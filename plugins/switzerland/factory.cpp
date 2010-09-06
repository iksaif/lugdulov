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

#include <QtCore/QtPlugin>

#include "factory.h"
#include "zug.h"
#include "schupfheim.h"
#include "schwyz.h"
#include "luzern.h"
#include "sempach_station.h"
#include "hochdorf.h"
#include "arth_goldau.h"
#include "stansstad.h"
#include "sarnen.h"
#include "kussnacht_am_rigi.h"
#include "sursee.h"
#include "bern.h"
#include "stans.h"
#include "langenthal.h"
#include "rotkreuz.h"
#include "brunnen.h"


QString
StationsPluginFactorySwitzerland::id() const
{
  return QLatin1String("Switzerland");
}

QString
StationsPluginFactorySwitzerland::name() const
{
  return QString::fromUtf8("Switzerland");
}

QIcon
StationsPluginFactorySwitzerland::icon() const
{
  return QIcon(":/res/bike.png");
}

QList < StationsPlugin * >
StationsPluginFactorySwitzerland::stations(QObject *parent)
{
  QList < StationsPlugin * > ret;

  ret << new StationsPluginZug(parent);
  ret << new StationsPluginSchupfheim(parent);
  ret << new StationsPluginSchwyz(parent);
  ret << new StationsPluginLuzern(parent);
  ret << new StationsPluginSempach_Station(parent);
  ret << new StationsPluginHochdorf(parent);
  ret << new StationsPluginArth_Goldau(parent);
  ret << new StationsPluginStansstad(parent);
  ret << new StationsPluginSarnen(parent);
  ret << new StationsPluginKussnacht_Am_Rigi(parent);
  ret << new StationsPluginSursee(parent);
  ret << new StationsPluginBern(parent);
  ret << new StationsPluginStans(parent);
  ret << new StationsPluginLangenthal(parent);
  ret << new StationsPluginRotkreuz(parent);
  ret << new StationsPluginBrunnen(parent);

  return ret;
}

Q_EXPORT_PLUGIN2(stationsswitzerland, StationsPluginFactorySwitzerland)
