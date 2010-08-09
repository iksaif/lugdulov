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

#include "mapwidget.h"
#include "stationsmodel.h"
#include "stationssortfilterproxymodel.h"
#include "settings.h"
#include "stationsplugin.h"
#include "station.h"

using namespace qmapcontrol;

MapWidget::MapWidget(QWidget *parent)
{
  model = NULL;
  proxy = NULL;
  plugin = NULL;

  mc = new MapControl(size());
  mapadapter = new OSMMapAdapter();

  Layer* l = new Layer("Custom Layer", mapadapter, Layer::MapLayer);

  mc->addLayer(l);
  mc->showScale(true);
  mc->enablePersistentCache();

  QHBoxLayout* layout = new QHBoxLayout;
  layout->addWidget(mc);
  setLayout(layout);

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
  //mc->setZoom(20);

  connect(mc, SIGNAL(viewChanged(const QPointF &, int)),
	  this, SLOT(viewChanged(const QPointF &, int)));
}

MapWidget::~MapWidget()
{
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
  proxy->setStationLimit(5);
  proxy->setBookmarks(Settings::bookmarks(plugin));
  proxy->setSortRole(StationsSortFilterProxyModel::StationDistanceRole);

  plugin->fetchAll();
}

#ifdef HAVE_QT_LOCATION
void
MapWidget::positionUpdated(const QGeoPositionInfo & info)
{
  if (!follow->isChecked())
    return ;

  coord = QPointF(info.coordinate().latitude(), info.coordinate().longitude());
  centerView(coord);
}
#endif

void
MapWidget::viewChanged(const QPointF & coordinate, int zoom)
{
  if (coord == coordinate || !proxy)
    return ;

  coord = QPointF(coordinate.y(), coordinate.x());
  refreshStations();
}

void
MapWidget::refreshStations()
{
  if (coord.isNull())
    return ;

  /* refresh avec timer + garder stations + afficher les trucs */

  proxy->setPosition(QPointF(coord.x(), coord.y()));
  proxy->sort(0);
  qDebug() << proxy->rowCount() << model->rowCount();
  for (int i = 0; i < proxy->rowCount(); ++i) {
    Station *station = (Station *)proxy->index(i, 0).data(StationsModel::StationRole).value<void *>();
    qDebug() << i << station->name() << station->distanceTo(coord);
  }
}

void
MapWidget::centerView(const QPointF & pt, int zoom)
{
  coord = pt;

  mc->setView(QPointF(pt.y(), pt.x()));
  if (zoom != -1)
    mc->setZoom(zoom);

  refreshStations();
}

void
MapWidget::resizeEvent(QResizeEvent * event)
{
  mc->resize(event->size());
}
