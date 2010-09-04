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
#include "dusseldorf.h"
#include "dusseldorf_p.h"

StationsPluginDusseldorf::StationsPluginDusseldorf(QObject *parent)
  : StationsPluginNextBike(parent)
{
  d = new StationsPluginSimplePrivateDusseldorf();
}

StationsPluginDusseldorf::~StationsPluginDusseldorf()
{
  delete d;
}

QString
StationsPluginDusseldorf::id() const
{
  return QLatin1String("dusseldorf");
}

QString
StationsPluginDusseldorf::name() const
{
  return QString::fromUtf8("Düsseldorf");
}

QString
StationsPluginDusseldorf::bikeName() const
{
  return QString::fromUtf8("nextbike");
}

QIcon
StationsPluginDusseldorf::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

