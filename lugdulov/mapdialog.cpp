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

#include "config.h"

#include "lugdulov.h"
#include "mapdialog.h"

MapDialog::MapDialog(StationsPlugin *plugin, QWidget *parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  plugin(plugin)
{
  setupUi(this);
  setupDialog(this);
#if defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
  mapWidget->setPlugin(plugin);
}

MapDialog::~MapDialog()
{
}

#ifdef HAVE_QT_LOCATION
void
MapDialog::positionUpdated(const QGeoPositionInfo & info)
{
  mapWidget->positionUpdated(info);
}
#endif

void
MapDialog::centerView(const QPointF & pt, int z)
{
  mapWidget->centerView(pt, z);
}
