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

#include "config.h"
#include "factory.h"
#include "montreal.h"

StationsPluginFactoryCanada::StationsPluginFactoryCanada()
{
  loadInfos(":/canada/canada.xml");
  loadCities(":/canada/cities.xml");
  loadCities(PLUGINS_EXTEND_DIR "/canada/cities.xml");
}

StationsPluginSimple *
StationsPluginFactoryCanada::pluginForType(const QString & type)
{
  if (type == "Montreal" || type == "Bixi")
    return new StationsPluginMontreal();
  else
    return StationsPluginFactorySimple::pluginForType(type);
}

Q_EXPORT_PLUGIN2(stationscanada, StationsPluginFactoryCanada)
