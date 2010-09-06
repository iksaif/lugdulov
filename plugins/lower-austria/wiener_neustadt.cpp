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
#include "wiener_neustadt.h"
#include "wiener_neustadt_p.h"

StationsPluginWiener_Neustadt::StationsPluginWiener_Neustadt(QObject *parent)
  : StationsPluginNextBike(parent)
{
  d = new StationsPluginSimplePrivateWiener_Neustadt();
}

StationsPluginWiener_Neustadt::~StationsPluginWiener_Neustadt()
{
  delete d;
}

QString
StationsPluginWiener_Neustadt::id() const
{
  return QLatin1String("wiener_neustadt");
}

QString
StationsPluginWiener_Neustadt::name() const
{
  return QString::fromUtf8("Wiener Neustadt");
}

QString
StationsPluginWiener_Neustadt::bikeName() const
{
  return QString::fromUtf8("nextbike");
}

QIcon
StationsPluginWiener_Neustadt::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

