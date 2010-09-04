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
#include "friedrichshafen.h"
#include "friedrichshafen_p.h"

StationsPluginFriedrichshafen::StationsPluginFriedrichshafen(QObject *parent)
  : StationsPluginNextBike(parent)
{
  d = new StationsPluginSimplePrivateFriedrichshafen();
}

StationsPluginFriedrichshafen::~StationsPluginFriedrichshafen()
{
  delete d;
}

QString
StationsPluginFriedrichshafen::id() const
{
  return QLatin1String("friedrichshafen");
}

QString
StationsPluginFriedrichshafen::name() const
{
  return QString::fromUtf8("Friedrichshafen");
}

QString
StationsPluginFriedrichshafen::bikeName() const
{
  return QString::fromUtf8("nextbike");
}

QIcon
StationsPluginFriedrichshafen::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

