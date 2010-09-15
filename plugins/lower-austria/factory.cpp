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
#include "modling.h"
#include "baden.h"
#include "romerland.h"
#include "wachau.h"
#include "triestingtal.h"
#include "st_polten.h"
#include "wiener_neustadt.h"
#include "tulln.h"
#include "wieselburg.h"
#include "obb_bahnhofe.h"


QString
StationsPluginFactoryLowerAustria::id() const
{
  return QLatin1String("LowerAustria");
}

QString
StationsPluginFactoryLowerAustria::name() const
{
  return QString::fromUtf8("Lower Austria");
}

QIcon
StationsPluginFactoryLowerAustria::icon() const
{
  return QIcon(":/lower-austria/at.png");
}

QList < StationsPlugin * >
StationsPluginFactoryLowerAustria::stations(QObject *parent)
{
  QList < StationsPlugin * > ret;

  ret << new StationsPluginModling(parent);
  ret << new StationsPluginBaden(parent);
  ret << new StationsPluginRomerland(parent);
  ret << new StationsPluginWachau(parent);
  ret << new StationsPluginTriestingtal(parent);
  ret << new StationsPluginSt_Polten(parent);
  ret << new StationsPluginWiener_Neustadt(parent);
  ret << new StationsPluginTulln(parent);
  ret << new StationsPluginWieselburg(parent);
  ret << new StationsPluginObb_Bahnhofe(parent);

  return ret;
}

Q_EXPORT_PLUGIN2(stationsloweraustria, StationsPluginFactoryLowerAustria)
