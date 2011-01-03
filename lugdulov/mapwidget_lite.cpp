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

#include "mapwidget_lite.h"

MapWidget::MapWidget(QWidget * parent)
  : QLabel(parent)
{
#if defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  setText(tr("The Map functionality is not supported in the lite version,"
	     "you need to purchase the full version on OVI store."));
#else
  setText(tr("Map not supported."));
#endif
}

MapWidget::~MapWidget()
{
}

void
MapWidget::setPlugin(StationsPlugin *p)
{
  Q_UNUSED(p);
}

void
MapWidget::centerView(const QPointF & position, int zoom)
{
  Q_UNUSED(position);
  Q_UNUSED(zoom);
}

void
MapWidget::positionUpdated(const QGeoPositionInfo & info)
{
  Q_UNUSED(info);
}

