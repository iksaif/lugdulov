/*
 * Copyright (C) 2010-2011 Corentin Chary <corentin.chary@gmail.com>
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

#ifndef STATIONSMANAGER_H
# define STATIONSMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QPointF>
#include <QtCore/QMap>
#include <QtCore/QDir>

class StationsPluginFactory;
class StationsPlugin;

class StationsPluginManager : public QObject
{
  Q_OBJECT
public:
  StationsPluginManager(QObject *parent);
  ~StationsPluginManager();

  QMultiMap < StationsPluginFactory *, StationsPlugin * >  stations();
  StationsPlugin *station(const QPointF & pt);
  StationsPlugin *station(const QString & id);

private:
  void loadPlugins();
  void loadPlugins(QDir pluginDir);
  void loadPlugin(QObject *plugin);

  QMap < QString, StationsPluginFactory * > factories;
};

#endif
