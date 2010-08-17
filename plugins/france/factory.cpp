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
#include "aixenprovence.h"
#include "amiens.h"
#include "besancon.h"
#include "cergypontoise.h"
#include "creteil.h"
#include "lyon.h"
#include "marseille.h"
#include "mulhouse.h"
#include "nancy.h"
#include "nantes.h"
#include "paris.h"
#include "plainecommune.h"
#include "rouen.h"
#include "toulouse.h"

QString
StationsPluginFactoryFrance::id() const
{
  return QLatin1String("France");
}

QString
StationsPluginFactoryFrance::name() const
{
  return QString::fromUtf8("Réseaux Français - Authors:"
			   "Patrick Installé <PatrickInstalle@P-Installe.be>,"
			   "Corentin Chary <corentin.chary@gmail.com>");
}

QIcon
StationsPluginFactoryFrance::icon() const
{
  return QIcon(":/france/bike.png");
}

QList < StationsPlugin * >
StationsPluginFactoryFrance::stations(QObject *parent)
{
  QList < StationsPlugin * > ret;

  ret << new StationsPluginLyon(parent);
  ret << new StationsPluginAixenprovence(parent);
  ret << new StationsPluginAmiens(parent);
  ret << new StationsPluginBesancon(parent);
  ret << new StationsPluginCergyPontoise(parent);
  ret << new StationsPluginCreteil(parent);
  ret << new StationsPluginMarseille(parent);
  ret << new StationsPluginMulhouse(parent);
  ret << new StationsPluginNancy(parent);
  ret << new StationsPluginNantes(parent);
  ret << new StationsPluginParis(parent);
  ret << new StationsPluginPlainecommune(parent);
  ret << new StationsPluginRouen(parent);
  ret << new StationsPluginToulouse(parent);
  return ret;
}

Q_EXPORT_PLUGIN2(stationsfrance, StationsPluginFactoryFrance)
