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

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsView>
#include <QtGui/QMessageBox>
#include <QtGui/QPushButton>
#include <QtGui/QDesktopServices>

#include "config.h"

#include "lugdulov.h"
#include "mapdialog.h"
#include "stationsplugin.h"
#include "mapwidget.h"
#include "mapgraphicswidget_qtm.h"
#include "stationsmodel.h"
#include "stationssortfilterproxymodel.h"
#include "settings.h"
#include "stationsplugin.h"
#include "station.h"
#include "stationdialog.h"

MapWidget::MapWidget(QWidget *parent)
  :
  QGraphicsView(parent),
  serviceProvider(0),
  mapManager(0),
  mapWidget(0),
  plugin(0),
  positionMarker(0),
  model(0),
  proxy(0),
  stationsTimer(0),
  statusTimer(0)
{
  Settings conf;
  QString provider = conf.value("MapProvider", "opencyclemap").toString();

  QGraphicsScene* scene = new QGraphicsScene(this);
  setScene(scene);

  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setProvider(provider);

  mapWidget = new MapGraphicsWidget(mapManager);
  mapWidget->setZoomLevel(mapWidget->maximumZoomLevel());
  mapWidget->setMapType(QGraphicsGeoMap::StreetMap);
  scene->addItem(mapWidget);

  connect(mapWidget, SIGNAL(centerChanged (const QGeoCoordinate &)),
	  this, SLOT(viewChanged(const QGeoCoordinate &)));
  //connect(mapWidget, SIGNAL(objectsClicked (QList < QGeoMapObject * >)),
  //this, SLOT(objectsClicked (QList < QGeoMapObject * >)));
  connect(mapWidget, SIGNAL(clicked(const QPointF &)),
	  this, SLOT(mapClicked(const QPointF &)));

  stationsTimer = new QTimer(this);
  stationsTimer->setInterval(1000);
  connect(stationsTimer, SIGNAL(timeout()), this, SLOT(refreshStations()));

  statusTimer = new QTimer(this);
  statusTimer->setInterval(60000);
  connect(statusTimer, SIGNAL(timeout()), this, SLOT(refreshStatus()));
  statusTimer->start();

  createInnerLayout();

  positionMarker = new QGeoMapPixmapObject();
  positionMarker->setPixmap(QPixmap(":/res/circle.png"));

  mapWidget->addMapObject(positionMarker);

  resizeEvent(0);
}

MapWidget::~MapWidget()
{
  delete serviceProvider;
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

  connect(zoomin, SIGNAL(clicked(bool)), this, SLOT(zoomIn()));
  connect(zoomout, SIGNAL(clicked(bool)), this, SLOT(zoomOut()));

  QVBoxLayout* innerlayout = new QVBoxLayout;
  innerlayout->addWidget(zoomin);
  innerlayout->addWidget(zoomout);
  innerlayout->addWidget(follow);
  setLayout(innerlayout);
}

void
MapWidget::setPlugin(StationsPlugin *p)
{
  delete proxy;
  delete model;

  plugin = p;

  // Hum ?
  //qDeleteAll(objects.values());
  stations.clear();
  objects.clear();

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

  mapWidget->setCenter(QGeoCoordinate(plugin->center().x(), plugin->center().y()));
}

void
MapWidget::setProvider(QString providerId)
{
  QStringList providers = QGeoServiceProvider::availableServiceProviders();
  QMap<QString, QVariant> parameters;

  if (providerId != "google" && providerId != "nokia" && providerId != "openstreetmap" && providerId != "cloudmade")
    providerId = "opencyclemap";

  if (providerId == "opencyclemap") {
    providerId = "openstreetmap";
    parameters["mapping.servers"] = QStringList("http://tile.opencyclemap.org/cycle/");
  }

  if (!providers.contains(providerId)) {
    parameters.clear();

    if (providers.contains("nokia"))
      providerId = "nokia";
    else if (!providers.isEmpty())
      providerId = providers.at(0);
    else
      providerId = QString();
  }

  parameters["mapping.cache.directory"] = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);

  if (serviceProvider)
    delete serviceProvider;

  serviceProvider = new QGeoServiceProvider(providerId, parameters);
  if (serviceProvider->error() != QGeoServiceProvider::NoError) {
    QMessageBox::information(this, tr("Error"), tr("Unable to find the '%1' geoservices plugin.").arg(providerId));
    qApp->quit();
    return;
  }

  mapManager = serviceProvider->mappingManager();
}

void
MapWidget::positionUpdated(const QGeoPositionInfo & info)
{
  follow->show();

  positionMarker->setCoordinate(info.coordinate());

  if (!follow->isChecked())
    return ;

  mapWidget->setCenter(info.coordinate());
  mapWidget->setZoomLevel(mapWidget->maximumZoomLevel() - 1);
}

void
MapWidget::centerView(const QPointF & pt, int z)
{
  mapWidget->setCenter(QGeoCoordinate(pt.x(), pt.y()));

  if (z != -1)
    mapWidget->setZoomLevel(qMin(z, 17));

  QTimer::singleShot(0, this, SLOT(refreshStations()));
}

void
MapWidget::centerOnStation(Station *station)
{
  centerView(station->pos(), 17);
}

void
MapWidget::resizeEvent(QResizeEvent* event)
{
  setSceneRect(QRectF(QPointF(0.0, 0.0), size()));
  if (mapWidget)
    mapWidget->resize(size());
}

void
MapWidget::showEvent(QShowEvent* event)
{
  resizeEvent(0);
}

void
MapWidget::viewChanged(const QGeoCoordinate & coordinate)
{
  if (!proxy)
    return ;

  stationsTimer->start();
}

void
MapWidget::refreshStations()
{
  stationsTimer->stop();

  proxy->setPosition(QPointF(mapWidget->center().latitude(), mapWidget->center().longitude()));
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
  emit centerChanged(QPointF(mapWidget->center().latitude(), mapWidget->center().longitude()));
}

void
MapWidget::refreshStatus()
{
  foreach (QGeoMapObject *object, mapWidget->mapObjectsInViewport()) {
    if (!stations.contains(object))
      continue ;

    Station *station  = stations.value(object);

    station->plugin()->updateCached(station);
  }
}

void
MapWidget::dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
  for (int i = topLeft.row(); i <= bottomRight.row(); ++i) {
    Station *station = (Station *)model->index(i, 0).data(StationsModel::StationRole).value<void *>();

    if (objects.find(station) != objects.end())
      showStation(station);
  }
}

/* Workaround for mapObjectsAtScreenPosition */
void
MapWidget::mapClicked(const QPointF & pos)
{
  QList < QGeoMapObject * > list;

#if /*__arm__*/ 1
  /* http://bugreports.qt.nokia.com/browse/QTBUG-18176 */
  /* Also seems to only take the first setPixmap() into account */
  foreach (QGeoMapObject *object, objects.values()) {
    QPointF a = mapWidget->coordinateToScreenPosition(object->boundingBox().center());
    QRectF rect(a.x() - 24, a.y() - 24, 48, 48);

    if (rect.contains(pos) && !a.isNull())
      list << object;
  }
#else
  list = mapWidget->mapObjectsAtScreenPosition(pos);
#endif

  objectsClicked(list);
}

void
MapWidget::objectsClicked(QList < QGeoMapObject * > objects)
{
  if (objects.isEmpty() || !stations.contains(objects.at(0)))
    return ;

  StationDialog *dlg = new StationDialog(stations[objects.at(0)], this);

  showAndDelete(dlg);
}

void
MapWidget::zoomIn()
{
  mapWidget->setZoomLevel(qMax((int)mapWidget->zoomLevel() + 1, 17));
}

void
MapWidget::zoomOut()
{
  mapWidget->setZoomLevel(mapWidget->zoomLevel() - 1);
}

void
MapWidget::showStation(Station *station)
{
  if (!station)
    return ;

  if (objects.find(station) == objects.end()) {
    QPixmap pix = QPixmap(48, 48);
    QGeoMapPixmapObject *object = new QGeoMapPixmapObject();

    object->setPixmap(QPixmap(48, 48));
    object->setCoordinate(QGeoCoordinate(station->pos().x(), station->pos().y()));

    mapWidget->addMapObject(object);
    stations[object] = station;
    objects[station] = object;
  }

  QPixmap pix = ((QGeoMapPixmapObject *)objects[station])->pixmap();

  pix.fill(QColor(255, 255, 255, 0));

  QPainter painter(&pix);
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

  ((QGeoMapPixmapObject *)objects[station])->setPixmap(pix);
}
