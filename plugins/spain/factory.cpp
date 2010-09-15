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
#include "seville.h"
#include "santander.h"
#include "barcelone.h"

QString
StationsPluginFactorySpain::id() const
{
  return QLatin1String("Spain");
}

QString
StationsPluginFactorySpain::name() const
{
  return QString::fromUtf8("Spain");
}

QIcon
StationsPluginFactorySpain::icon() const
{
  return QIcon(":/spain/es.png");
}

QList < StationsPlugin * >
StationsPluginFactorySpain::stations(QObject *parent)
{
  QList < StationsPlugin * > ret;

  ret << new StationsPluginSeville(parent);
  ret << new StationsPluginSantander(parent);
  ret << new StationsPluginBarcelone(parent);
  return ret;
}

Q_EXPORT_PLUGIN2(stationsspain, StationsPluginFactorySpain)
