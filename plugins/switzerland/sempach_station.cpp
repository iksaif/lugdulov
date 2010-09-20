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

#include <QtCore/QDebug>

#include "station.h"
#include "sempach_station.h"
#include "sempach_station_p.h"

StationsPluginSempach_Station::StationsPluginSempach_Station(QObject *parent)
  : StationsPluginNextBike(parent)
{
  d = new StationsPluginSimplePrivateSempach_Station();
}

StationsPluginSempach_Station::~StationsPluginSempach_Station()
{
  delete d;
}

QString
StationsPluginSempach_Station::id() const
{
  return QLatin1String("sempach_station");
}

QString
StationsPluginSempach_Station::name() const
{
  return QString::fromUtf8("Sempach Station (LV)");
}

QString
StationsPluginSempach_Station::bikeName() const
{
  return QString::fromUtf8("nextbike");
}

QIcon
StationsPluginSempach_Station::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

