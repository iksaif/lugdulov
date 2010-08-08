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

using namespace qmapcontrol;

MapWidget::MapWidget(QWidget *parent)
{
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
}

MapWidget::~MapWidget()
{
}

#ifdef HAVE_QT_LOCATION
void
MapWidget::positionUpdated(const QGeoPositionInfo & info)
{
  if (follow->isChecked())
    centerView(QPointF(info.coordinate().longitude(), info.coordinate().latitude()));
}
#endif

void
MapWidget::centerView(const QPointF & pt, int zoom)
{
  mc->setView(QPointF(pt.y(), pt.x()));
  if (zoom != -1)
    mc->setZoom(zoom);
}

void
MapWidget::resizeEvent(QResizeEvent * event)
{
  mc->resize(event->size());
}
