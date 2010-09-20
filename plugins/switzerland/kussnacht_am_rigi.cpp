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
#include "kussnacht_am_rigi.h"
#include "kussnacht_am_rigi_p.h"

StationsPluginKussnacht_Am_Rigi::StationsPluginKussnacht_Am_Rigi(QObject *parent)
  : StationsPluginNextBike(parent)
{
  d = new StationsPluginSimplePrivateKussnacht_Am_Rigi();
}

StationsPluginKussnacht_Am_Rigi::~StationsPluginKussnacht_Am_Rigi()
{
  delete d;
}

QString
StationsPluginKussnacht_Am_Rigi::id() const
{
  return QLatin1String("kussnacht_am_rigi");
}

QString
StationsPluginKussnacht_Am_Rigi::name() const
{
  return QString::fromUtf8("Küssnacht am Rigi (LV)");
}

QString
StationsPluginKussnacht_Am_Rigi::bikeName() const
{
  return QString::fromUtf8("nextbike");
}

QIcon
StationsPluginKussnacht_Am_Rigi::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

