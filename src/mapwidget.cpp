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
  mc = new MapControl(QSize(800,600));
  TileMapAdapter* mapadapter = new TileMapAdapter("tile.openstreetmap.org", "/%1/%2/%3.png", 256, 0, 17);
  Layer* l = new Layer("Custom Layer", mapadapter, Layer::MapLayer);


  mc->addLayer(l);

  QHBoxLayout* layout = new QHBoxLayout;
  layout->addWidget(mc);
  setLayout(layout);

  QPushButton* zoomin = new QPushButton("+");
  QPushButton* zoomout = new QPushButton("-");

  followGpsButton = new QPushButton("F");
  followGpsButton->setCheckable(true);
  followGpsButton->setChecked(true);

  zoomin->setMaximumWidth(50);
  zoomout->setMaximumWidth(50);
  followGpsButton->setMaximumWidth(50);

  connect(zoomin, SIGNAL(clicked(bool)), mc, SLOT(zoomIn()));
  connect(zoomout, SIGNAL(clicked(bool)), mc, SLOT(zoomOut()));

  QVBoxLayout* innerlayout = new QVBoxLayout;
  innerlayout->addWidget(zoomin);
  innerlayout->addWidget(zoomout);
  innerlayout->addWidget(followGpsButton);
  mc->setLayout(innerlayout);
}

MapWidget::~MapWidget()
{
}

#ifdef HAVE_QT_LOCATION
void
MapWidget::positionUpdated(const QGeoPositionInfo & info)
{
  if (followGpsButton->isChecked())
    centerView(QPointF(info.coordinate().longitude(), info.coordinate().latitude()));
}
#endif

void
MapWidget::centerView(const QPointF & pt)
{
  mc->setView(pt);
}

