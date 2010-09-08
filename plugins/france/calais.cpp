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
#include "calais.h"
#include "calais_p.h"

StationsPluginCalais::StationsPluginCalais(QObject *parent)
  : StationsPluginVelIn(parent)
{
  d = new StationsPluginSimplePrivateCalais();
}

StationsPluginCalais::~StationsPluginCalais()
{
  delete d;
}

QString
StationsPluginCalais::id() const
{
  return QLatin1String("calais");
}

QString
StationsPluginCalais::name() const
{
  return QString::fromUtf8("Calais");
}

QString
StationsPluginCalais::bikeName() const
{
  return QString::fromUtf8("Velin");
}

QIcon
StationsPluginCalais::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

