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
#include "offenbach_am_main.h"
#include "offenbach_am_main_p.h"

StationsPluginOffenbach_Am_Main::StationsPluginOffenbach_Am_Main(QObject *parent)
  : StationsPluginNextBike(parent)
{
  d = new StationsPluginSimplePrivateOffenbach_Am_Main();
}

StationsPluginOffenbach_Am_Main::~StationsPluginOffenbach_Am_Main()
{
  delete d;
}

QString
StationsPluginOffenbach_Am_Main::id() const
{
  return QLatin1String("offenbach_am_main");
}

QString
StationsPluginOffenbach_Am_Main::name() const
{
  return QString::fromUtf8("Offenbach am Main");
}

QString
StationsPluginOffenbach_Am_Main::bikeName() const
{
  return QString::fromUtf8("nextbike");
}

QIcon
StationsPluginOffenbach_Am_Main::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

