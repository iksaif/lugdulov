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
#include "st_polten.h"
#include "st_polten_p.h"

StationsPluginSt_Polten::StationsPluginSt_Polten(QObject *parent)
  : StationsPluginNextBike(parent)
{
  d = new StationsPluginSimplePrivateSt_Polten();
}

StationsPluginSt_Polten::~StationsPluginSt_Polten()
{
  delete d;
}

QString
StationsPluginSt_Polten::id() const
{
  return QLatin1String("st_polten");
}

QString
StationsPluginSt_Polten::name() const
{
  return QString::fromUtf8("St. Pölten");
}

QString
StationsPluginSt_Polten::bikeName() const
{
  return QString::fromUtf8("nextbike");
}

QIcon
StationsPluginSt_Polten::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

