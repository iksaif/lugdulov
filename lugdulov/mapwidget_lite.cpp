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

#include "mapwidget_lite.h"
#include "station.h"

MapWidget::MapWidget(QWidget * parent)
  : QLabel(parent)
{
#if defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  setWordWrap(true);
  setText(tr("Map functionality is not available in the lite version,"
	     " you need to purchase the full version on "
		 "<a href='http://store.ovi.com/content/65625'>OVI store</a>."));
  setOpenExternalLinks(true);
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
MapWidget::centerOnStation(Station *station)
{
  Q_UNUSED(station);
}

void
MapWidget::centerView(const QPointF & position, int zoom)
{
  Q_UNUSED(position);
  Q_UNUSED(zoom);
}

#ifdef HAVE_QT_LOCATION
void
MapWidget::positionUpdated(const QGeoPositionInfo & info)
{
  Q_UNUSED(info);
}
#endif
