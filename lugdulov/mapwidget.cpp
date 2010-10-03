/*
 * Copyright (C) 2010 Corentin Chary <corentin.chary@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <QtGui/QDesktopServices>

#include "lugdulov.h"
#include "mapwidget.h"
#include "stationsmodel.h"
#include "stationssortfilterproxymodel.h"
#include "settings.h"
#include "stationsplugin.h"
#include "station.h"
#include "stationdialog.h"
#include "imagemanager.h"

using namespace qmapcontrol;

MapWidget::MapWidget(QWidget *parent)
{
  model = NULL;
  proxy = NULL;
  plugin = NULL;

  setupMapControl();
  createInnerLayout();

  stationsTimer = new QTimer(this);
  stationsTimer->setInterval(1000);
  connect(stationsTimer, SIGNAL(timeout()), this, SLOT(refreshStations()));

  statusTimer = new QTimer(this);
  statusTimer->setInterval(60000);
  connect(statusTimer, SIGNAL(timeout()), this, SLOT(refreshStatus()));
  statusTimer->start();
}

MapWidget::~MapWidget()
{
}

void
MapWidget::createInnerLayout()
{
  QPushButton* zoomin;
  QPushButton* zoomout;

  zoomin = new QPushButton(this);
  zoomout = new QPushButton(this);
  follow = new QPushButton(this);

  zoomin->setIcon(QIcon::fromTheme("zoom-in", QPixmap(":/res/zoom-in.png")));
  zoomout->setIcon(QIcon::fromTheme("zoom-out", QPixmap(":/res/zoom-out.png")));
  follow->setIcon(QIcon::fromTheme("gps", QPixmap(":/res/gps.png")));

  zoomin->setFlat(true);
  zoomin->setIconSize(QSize(32, 32));

  zoomout->setFlat(true);
  zoomout->setIconSize(QSize(32, 32));

  follow->setFlat(true);
  follow->setIconSize(QSize(32, 32));
  follow->setCheckable(true);
  follow->setChecked(true);
  follow->hide();

  zoomin->setMaximumWidth(50);
  zoomout->setMaximumWidth(50);
  follow->setMaximumWidth(50);

  connect(zoomin, SIGNAL(clicked(bool)), mc, SLOT(zoomIn()));
  connect(zoomout, SIGNAL(clicked(bool)), mc, SLOT(zoomOut()));

  QVBoxLayout* innerlayout = new QVBoxLayout;
  innerlayout->addWidget(zoomin);
  innerlayout->addWidget(zoomout);
  innerlayout->addWidget(follow);
  mc->setLayout(innerlayout);
}

void
MapWidget::setupMapControl()
{
  mc = new MapControl(size());
  //mapadapter = new GoogleMapAdapter();
  mapadapter = new OSMMapAdapter();

  Layer* l = new Layer("Custom Layer", mapadapter, Layer::MapLayer);

#if defined(Q_WS_MAEMO_5) || defined(Q_WS_S60)
  mc->enablePersistentCache();
#else
  mc->enablePersistentCache(QDesktopServices::storageLocation(QDesktopServices::CacheLocation));
#endif

  mc->addLayer(l);
  mc->showScale(true);

  stationsLayer = new GeometryLayer("Stations", mapadapter);
  mc->addLayer(stationsLayer);

  connect(stationsLayer, SIGNAL(geometryClicked(Geometry*, QPoint)),
	  this, SLOT(geometryClicked(Geometry*, QPoint)));

  positionLayer = new GeometryLayer("Position", mapadapter);
  mc->addLayer(positionLayer);

  positionMarker = new Point(0, 0, new QPixmap(":/res/circle.png"), tr("You are here"));
  positionMarker->setBaselevel(15);
  positionMarker->setMinsize(QSize(24, 24));
  positionMarker->setMaxsize(QSize(48, 48));
  positionMarker->setVisible(false);
  positionLayer->addGeometry(positionMarker);

  QHBoxLayout* layout = new QHBoxLayout;
  layout->addWidget(mc);
  setLayout(layout);

  connect(mc, SIGNAL(viewChanged(const QPointF &, int)),
	  this, SLOT(viewChanged(const QPointF &, int)));
}

void
MapWidget::setPlugin(StationsPlugin *p)
{
  delete model;
  delete proxy;

  plugin = p;

  model = new StationsModel(plugin, this);
  proxy = new StationsSortFilterProxyModel(model);

  proxy->setSourceModel(model);
  proxy->setStationLimit(10);
  proxy->setBookmarks(Settings::bookmarks(plugin));
  proxy->setSortRole(StationsSortFilterProxyModel::StationDistanceRole);

  connect(model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)),
	  this, SLOT(dataChanged(const QModelIndex &, const QModelIndex &)));
  connect(model, SIGNAL(rowsInserted(const QModelIndex &, int, int)),
	  this, SLOT(refreshStations()));

  plugin->fetchAll(); // First fetch cached data
  QTimer::singleShot(200, plugin, SLOT(fetchOnline())); // Then load online data
}

#ifdef HAVE_QT_LOCATION
void
MapWidget::positionUpdated(const QGeoPositionInfo & info)
{
  follow->show();
  coord = QPointF(info.coordinate().latitude(), info.coordinate().longitude());
  positionMarker->setVisible(true);
  positionMarker->setCoordinate(QPointF(coord.y(), coord.x()));

  if (!follow->isChecked())
    return ;

  if (plugin && plugin->rect().contains(coord))
    centerView(coord);
}
#endif

void
MapWidget::viewChanged(const QPointF & coordinate, int zoom)
{
  if (!proxy)
    return ;

  if (coord.y() == coordinate.x() && coord.x() == coordinate.y())
    return ;

  coord = QPointF(coordinate.y(), coordinate.x());

  if (stationsTimer->isActive())
    stationsTimer->stop();
  stationsTimer->start();
}

void
MapWidget::geometryClicked(Geometry *geom, QPoint pt)
{
  if (stations.find((Point *)geom) == stations.end())
    return ;

  StationDialog *dlg = new StationDialog(stations[(Point *)geom], this);

  showAndDelete(dlg);
}

void
MapWidget::showStation(Station *station)
{
  if (geometries.find(station) == geometries.end()) {
    QPixmap *pix = new QPixmap(station->plugin()->bikeIcon().pixmap(QSize(48, 48)));
    Point *geom = new Point(station->pos().y(), station->pos().x(), pix, station->name());

    stationsLayer->addGeometry(geom);
    stations[geom] = station;
    geometries[station] = geom;
  }

  QPainter painter(geometries[station]->pixmap());
  QRectF rect1, rect2;

  rect1 = rect2 = QRectF(10, 0, 30, 3);

  painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
  painter.setPen(Qt::NoPen);
  if (station->bikes() > 0 && station->totalSlots() > 0) {
    rect1.setWidth(rect1.width() * (double)station->bikes() / (double)station->totalSlots());
    rect2.setWidth(rect2.width() * (double)station->freeSlots() / (double)station->totalSlots());
    rect2.moveTo(rect1.x() + rect1.width(), rect2.y());
  } else if (station->bikes() > 0) {
    rect2 = QRectF();
  } else if (station->freeSlots() > 0) {
    rect1 = QRectF();
  } else {
    return ;
  }

  if (!rect1.isNull()) {
    painter.setBrush(Qt::darkGreen);
    painter.drawRect(rect1);
  }
  if (!rect2.isNull()) {
    painter.setBrush(Qt::darkRed);
    painter.drawRect(rect2);
  }
}

void
MapWidget::refreshStations()
{
  if (coord.isNull())
    return ;

  stationsTimer->stop();

  proxy->setPosition(QPointF(coord.x(), coord.y()));
  proxy->sort(0);

  for (int i = 0; i < proxy->rowCount(); ++i) {
    Station *station = (Station *)proxy->index(i, 0).data(StationsModel::StationRole).value<void *>();

    showStation(station);
  }

  refreshStatus();
}

void
MapWidget::refreshStatus()
{
  foreach (Point *geometry, stations.keys()) {
    if (mc->getViewport().contains(geometry->coordinate()))
      stations[geometry]->plugin()->updateCached(stations[geometry]);
  }
}

void
MapWidget::dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
  for (int i = topLeft.row(); i <= bottomRight.row(); ++i) {
    Station *station = (Station *)model->index(i, 0).data(StationsModel::StationRole).value<void *>();

    if (geometries.find(station) != geometries.end())
      showStation(station);
  }
  mc->updateRequestNew();
}

void
MapWidget::centerView(const QPointF & pt, int zoom)
{
  coord = pt;

  mc->setView(QPointF(pt.y(), pt.x()));
  if (zoom != -1)
    mc->setZoom(zoom);

  stationsTimer->start();
}

void
MapWidget::resizeEvent(QResizeEvent * event)
{
  mc->resize(event->size());
  QWidget::resizeEvent(event);
}
