/*
 * Copyright (C) 2010-2011 Corentin Chary <corentin.chary@gmail.com>
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

#include <qglobal.h>
#include <QtCore/QDebug>
#include "config.h"

#if defined(Q_WS_MAEMO_5)
#include <QtGui/QX11Info>
#endif

#include <QtGui/QDesktopServices>

#include "lugdulov.h"
#include "mapwidget_qmapcontrol.h"
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

  grabZoomKeys(true);
}

MapWidget::~MapWidget()
{
  grabZoomKeys(false);
  delete mc;
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
  Settings conf;
  QString provider = conf.value("MapProvider").toString();

  mc = new MapControl(size());

  if (provider == "google")
    mapadapter = new GoogleMapAdapter();
  else if (provider == "openstreetmap")
    mapadapter = new OSMMapAdapter();
  else
    mapadapter = new OCMMapAdapter();

  Layer* l = new Layer("Custom Layer", mapadapter, Layer::MapLayer);

#if defined(Q_WS_MAEMO_5) || defined(Q_WS_S60)
  mc->enablePersistentCache(QDesktopServices::storageLocation(QDesktopServices::CacheLocation));
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
  delete proxy;
  delete model;

  plugin = p;

  foreach (Geometry *geometry, geometries)
    stationsLayer->removeGeometry(geometry);
  qDeleteAll(geometries);
  stations.clear();
  geometries.clear();

  if (!plugin) {
    proxy = NULL;
    model = NULL;
    return ;
  }

  model = new StationsModel(plugin, this);
  proxy = new StationsSortFilterProxyModel(model);

  proxy->setSourceModel(model);
  proxy->setStationLimit(10);
  proxy->setSortRole(StationsSortFilterProxyModel::StationDistanceRole);

  connect(model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)),
	  this, SLOT(dataChanged(const QModelIndex &, const QModelIndex &)));
  connect(model, SIGNAL(rowsInserted(const QModelIndex &, int, int)),
	  this, SLOT(refreshStations()));

  plugin->fetchAll(); // First fetch cached data
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
    centerView(coord, 17);
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
  if (!station)
    return ;

  if (geometries.find(station) == geometries.end()) {
    QPixmap *pix = new QPixmap(48, 48);
    Point *geom = new Point(station->pos().y(), station->pos().x(), pix, station->name());

    stationsLayer->addGeometry(geom);
    stations[geom] = station;
    geometries[station] = geom;
  }

  QPixmap *pix = geometries[station]->pixmap();

  *pix = QPixmap(48, 48);
  pix->fill(QColor(255, 255, 255, 0));

  QPainter painter(pix);
  QColor color, color2;
  int angleBikes = -1, angleSlots = -1;
  QPen pen;
  QBrush brush;
  QRect rect(3, 3, 44, 44);

  painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);

  if (station->bikes() >= 0 && station->totalSlots() > 0) {
    double ratio;

    if (station->bikes())
      ratio = (double) station->bikes() / (double) station->totalSlots();
    else
      ratio = 0;

    if (ratio == 0)
      color = Qt::red;
    else if (ratio < 0.3)
      color = QColor(238, 113, 17);
    else if (ratio < 0.6)
      color = Qt::yellow;
    else
      color = Qt::darkGreen;
    angleBikes = 16 * 360 * ratio;
    angleSlots = 16 * 360 * (1 - ratio);
  } else if (station->bikes() >= 0) {
    int bikes = station->bikes();

    if (bikes == 0)
      color = Qt::red;
    else if (bikes < 3)
      color = QColor(238, 113, 17);
    else if (bikes < 5)
      color = Qt::yellow;
    else
      color = Qt::darkGreen;
  } else if (station->freeSlots() >= 0) {
    if (station->freeSlots() == 0)
      color = Qt::darkGreen;
    else
      goto end;
  } else {
    goto end;
  }

  pen.setWidth(2);
  pen.setColor(color);
  color.setAlpha(100);

  painter.setBrush(color);
  painter.setPen(pen);

  color2 = Qt::gray;
  color2.setAlpha(100);

  if (angleBikes > 0 && angleSlots > 0) {
    painter.drawPie(rect, 90 * 16, -angleBikes);
    painter.setBrush(color2);
    painter.drawPie(rect, 90 * 16, angleSlots);
  } else if (angleBikes > 0) {
    painter.drawPie(rect, 90 * 16, -angleBikes);
  } else if (angleSlots > 0) {
    painter.setBrush(color2);
    painter.drawPie(rect, 90 * 16, angleSlots);
  } else {
    painter.drawEllipse(rect);
  }
 end:
  painter.drawPixmap(0, 0, station->plugin()->bikeIcon().pixmap(QSize(48, 48)));
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
    Station *station;

    station = (Station *)proxy->index(i, 0).data(StationsModel::StationRole).value<void *>();
    showStation(station);
  }

  refreshStatus();

  QTimer::singleShot(2000, this, SLOT(centerChanged()));
}

void
MapWidget::centerChanged()
{
  emit centerChanged(QPointF(coord.x(), coord.y()));
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

  QTimer::singleShot(0, this, SLOT(refreshStations()));
}

void
MapWidget::centerOnStation(Station *station)
{
  centerView(station->pos(), 17);
}

void
MapWidget::resizeEvent(QResizeEvent * event)
{
  mc->resize(event->size());
  QWidget::resizeEvent(event);
}

void
MapWidget::keyPressEvent(QKeyEvent* event)
{
  switch (event->key()) {
#if defined(Q_WS_MAEMO_5)
  case Qt::Key_F7:
    mc->zoomIn();
    break;

  case Qt::Key_F8:
    mc->zoomOut();
    break;
#endif
 case Qt::Key_Plus:
    mc->zoomIn();
    break;
 case Qt::Key_Minus:
    mc->zoomOut();
    break;
 case Qt::Key_Left:
   mc->scrollLeft(5);
   break;
 case Qt::Key_Right:
   mc->scrollRight(5);
   break;
 case Qt::Key_Up:
   mc->scrollUp(5);
   break;
 case Qt::Key_Down:
   mc->scrollDown(5);
   break;
 default:
   QWidget::keyPressEvent(event);
   return;
   break;
  }
  event->accept();
}

#if defined(Q_WS_MAEMO_5)
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#endif

void
MapWidget::grabZoomKeys(bool grab)
{
#if defined(Q_WS_MAEMO_5)
  if (!winId()) {
    qWarning("Can't grab keys unless we have a window id");
    return;
  }

  unsigned long val = (grab) ? 1 : 0;
  Atom atom = XInternAtom(QX11Info::display(), "_HILDON_ZOOM_KEY_ATOM", False);

  if (!atom) {
    qWarning("Unable to obtain _HILDON_ZOOM_KEY_ATOM. This example will only work "
	     "on a Maemo 5 device!");
    return;
  }

  XChangeProperty (QX11Info::display(), winId(), atom, XA_INTEGER,
		   32, PropModeReplace, reinterpret_cast<unsigned char *>(&val),
		   1);
#endif
}


