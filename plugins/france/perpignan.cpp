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
#include "perpignan.h"
#include "perpignan_p.h"

StationsPluginPerpignan::StationsPluginPerpignan(QObject *parent)
  : StationsPluginCityBike(parent)
{
  d = new StationsPluginSimplePrivatePerpignan();
}

StationsPluginPerpignan::~StationsPluginPerpignan()
{
  delete d;
}

QString
StationsPluginPerpignan::id() const
{
  return QLatin1String("perpignan");
}

QString
StationsPluginPerpignan::name() const
{
  return QString::fromUtf8("Perpignan");
}

QString
StationsPluginPerpignan::bikeName() const
{
  return QString::fromUtf8("Bip!");
}

QIcon
StationsPluginPerpignan::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

