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
#include <QtCore/QPluginLoader>
#include <QtCore/QCoreApplication>
#include <QtCore/QTranslator>
#include <QtCore/QLibraryInfo>

#include <QtCore/QDebug>

#include "config.h"
#include "stationspluginmanager.h"
#include "stationspluginfactory.h"
#include "stationspluginfactorysimple.h"
#include "stationsplugin.h"
#include "station.h"

StationsPluginManager::StationsPluginManager(QObject *parent)
  : QObject(parent)
{
  loadPlugins();
}

StationsPluginManager::~StationsPluginManager()
{
}

QMultiMap < StationsPluginFactory *, StationsPlugin * >
StationsPluginManager::stations()
{
  QMultiMap < StationsPluginFactory *, StationsPlugin * > map;

  foreach (StationsPluginFactory *factory, factories.values())
    foreach (StationsPlugin *plugin, factory->plugins())
      map.insert(factory, plugin);

  return map;
}

StationsPlugin *
StationsPluginManager::station(const QPointF & pt)
{
  StationsPlugin *plugin = NULL;

  foreach (StationsPluginFactory *factory, factories.values())
    if ((plugin = factory->plugin(pt)) != NULL)
      break ;

  return plugin;
}

StationsPlugin *
StationsPluginManager::station(const QString & id)
{
  StationsPlugin *plugin = NULL;

  foreach (StationsPluginFactory *factory, factories.values())
    if ((plugin = factory->plugin(id)) != NULL)
      break ;

  return plugin;
}

void
StationsPluginManager::loadPlugins()
{
  factories.clear();

  foreach (QObject *plugin, QPluginLoader::staticInstances()) {
    loadPlugin(plugin);
  }

#ifndef BUILD_STATIC_PLUGINS
  loadPlugins(QDir(PLUGINS_INSTALL_DIR));

  QDir dir = QCoreApplication::applicationDirPath();

  loadPlugins(dir);

#if defined(Q_OS_MAC)
  if (dir.dirName() == "MacOS") {
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
  }
#else
  dir.cdUp();
#endif
  dir.cd("lib");
  dir.cd("lugdulov");
  dir.cd("plugins");

  loadPlugins(dir);
#endif
}

void
StationsPluginManager::loadPlugins(QDir pluginsDir)
{
  if (!pluginsDir.exists())
    return ;

  foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
    if (!QLibrary::isLibrary(fileName))
      continue ;

    QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
    QObject *plugin = loader.instance();

    if (plugin) {
      qDebug() << "lugdulov: loading plugin" << pluginsDir.absoluteFilePath(fileName);
      loadPlugin(plugin);
    } else {
      qWarning() << "lugdulov: failed to load plugin " << loader.fileName() << ":"
	       << loader.errorString ();
    }
  }
}

void
StationsPluginManager::loadPlugin(QObject *plugin)
{
  StationsPluginFactory *factory = qobject_cast< StationsPluginFactory * >(plugin);

  if (!factory)
    return ;

  qDebug() << "lugdulov: stations plugin " << factory->id() << factory->name() << "loaded.";

  factories[factory->id()] = factory;

  QTranslator *translator = new QTranslator(plugin);

  translator->load("lugdulov_" + factory->id() + "_" + QLocale::system().name(),
		   ":/" + factory->id() + "/");
  QCoreApplication::instance()->installTranslator(translator);
}
