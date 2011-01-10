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

#ifndef STATIONS_PLUGIN_FACTORY_SIMPLE_H
#define STATIONS_PLUGIN_FACTORY_SIMPLE_H

#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QRect>
#include <QtXml/QDomNode>

#include "stationspluginsimple_p.h"
#include "stationspluginfactory.h"

class StationsPlugin;
class StationsPluginSimple;

class StationsPluginFactorySimple : public StationsPluginFactory
{
 public:
  StationsPluginFactorySimple();
  virtual ~StationsPluginFactorySimple();

  virtual QList < StationsPlugin * > plugins(void);
  virtual StationsPlugin *plugin(const QString & id);
  virtual StationsPlugin *plugin(const QPointF & pt);

  virtual QString id() const;
  virtual QString name() const;
  virtual QString description() const;
  virtual QIcon icon() const;

 protected:
  void init(const QString & id);
  void loadCities(const QString & xml);
  void loadInfos(const QString & xml);

  virtual StationsPluginSimple *pluginForType(const QString & type);

 private:
  void loadCity(const QDomNode & node);

  QMap < QString , StationsPluginSimplePrivate > cities;

  QString id_;
  QString name_;
  QString description_;
  QIcon icon_;
};

#endif /* STATIONS_PLUGIN_FACTORY_SIMPLE_H */
