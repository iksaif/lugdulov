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

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QTimer>
#include <QtXml/QDomDocument>
#include <QtCore/QDebug>

#include "config.h"
#include "tools.h"
#include "stationspluginfactorysimple.h"
#include "stationsplugincyclocity.h"
#include "stationspluginnextbike.h"
#include "stationsplugincitybike.h"
#include "stationsplugindupral.h"
#include "stationspluginvelin.h"
#include "stationspluginbixi.h"
#include "stationsplugintransdev.h"

StationsPluginFactorySimple::StationsPluginFactorySimple()
  : QObject(NULL), initialized(false)
{

}

StationsPluginFactorySimple::~StationsPluginFactorySimple()
{
}

void
StationsPluginFactorySimple::init(const QString & id)
{
  id_ = id;
#if !(defined(BUILD_STATIC_PLUGINS) && defined(Q_OS_SYMBIAN))
  /* On Symbian, it seems that we can't do much in static plugin
   * constructors ... */
  init();
#endif
}

void
StationsPluginFactorySimple::init()
{
  if (initialized)
    return ;
  loadInfos(QString(":/%1/%1.xml").arg(id_));
  loadCities(QString(":/%1/cities.xml").arg(id_));
  loadCities(Tools::pluginsPath().canonicalPath() + QString("/%1/cities.xml").arg(id_));
  initialized = true;
}

void
StationsPluginFactorySimple::loadInfos(const QString & xml)
{
  QFile file(xml);
  QDomDocument doc;
  QDomNode node;
  QDomNamedNodeMap attrs;

  if (!file.open(QIODevice::ReadOnly)) {
    qWarning() << "Can't open" << file.fileName() << ": " << file.error();
    return ;
  }

  doc.setContent(&file);
  node = doc.firstChildElement("country");
  attrs = node.attributes();

  id_ =  attrs.namedItem("id").nodeValue();
  name_ = node.firstChildElement("name").text();
  description_ = node.firstChildElement("description").text();
  icon_ = QIcon(node.firstChildElement("icon").text());
}

void
StationsPluginFactorySimple::loadCities(const QString & xml)
{
  QFile file(xml);
  QDomDocument doc;
  QDomNode city;

  if (!file.exists()) {
    qDebug() << "Skipping non-existent " << xml << "file";
    return ;
  }

  if (!file.open(QIODevice::ReadOnly)) {
    qWarning() << "Can't open" << file.fileName() << ": " << file.error();
    return ;
  }

  doc.setContent(&file);

  city = doc.firstChildElement("cities").firstChildElement("city");
  while (!city.isNull()) {
    loadCity(city);
    city = city.nextSiblingElement("city");
  }
}

void
StationsPluginFactorySimple::loadCity(const QDomNode & city)
{
  QDomNode node;
  QPointF min, max;
  QDomNamedNodeMap attrs;
  StationsPluginSimplePrivate data;

  attrs = city.attributes();

  data.id = attrs.namedItem("id").nodeValue();

  node = city.firstChildElement("latitude");
  attrs = node.attributes();

  data.center.setX(node.toElement().text().toDouble());
  min.setX(attrs.namedItem("min").nodeValue().toDouble());
  max.setX(attrs.namedItem("max").nodeValue().toDouble());

  node = city.firstChildElement("longitude");
  attrs = node.attributes();

  data.center.setY(node.toElement().text().toDouble());
  min.setY(attrs.namedItem("min").nodeValue().toDouble());
  max.setY(attrs.namedItem("max").nodeValue().toDouble());

  data.rect = QRectF(min, max);
  data.statusUrl = city.firstChildElement("status").text();
  data.infosUrl = city.firstChildElement("infos").text();
  data.name = city.firstChildElement("name").text();
  data.bikeName = city.firstChildElement("bikeName").text();
  data.type = city.firstChildElement("type").text();

  QString icon = city.firstChildElement("bikeIcon").text();

  if (icon.isEmpty())
    icon = ":/res/bike.png";

  data.bikeIcon = QIcon(icon);

  if (data.id.isEmpty() || !data.rect.isValid() || data.center.isNull() ||
      data.name.isEmpty() || data.bikeName.isEmpty() || data.type.isEmpty()) {
    qWarning() << "Error processing city " << data.id
	       << data.name << data.bikeName << data.type;
    return ;
  }

  cities[data.id] = data;
}

QList < StationsPlugin * >
StationsPluginFactorySimple::plugins()
{
  QList < StationsPlugin * > plugins;

  foreach (QString id, cities.keys())
    plugins << plugin(id);

  return plugins;
}

StationsPlugin *
StationsPluginFactorySimple::plugin(const QString & city)
{
  StationsPluginSimple *plugin = NULL;

  if (!cities.contains(city))
    return NULL;

  plugin = pluginForType(cities[city].type);

  if (plugin) {
    plugin->d = new StationsPluginSimplePrivate();
    *plugin->d = cities[city];
    plugin->loadOverride(QString(":/%1/%2.xml").arg(id()).arg(city));
    plugin->loadOverride(Tools::pluginsPath().canonicalPath() + QString("/%1/%2.xml").arg(id()).arg(city));
  }

  return plugin;
}

StationsPluginSimple *
StationsPluginFactorySimple::pluginForType(const QString & type)
{
  StationsPluginSimple *plugin = NULL;

  if (type == "CycloCity")
    plugin = new StationsPluginCycloCity();
  else if (type == "NextBike")
    plugin = new StationsPluginNextBike();
  else if (type == "CityBike")
    plugin = new StationsPluginCityBike();
  else if (type == "Dupral")
    plugin = new StationsPluginDupral();
  else if (type == "VelIn")
    plugin = new StationsPluginVelIn();
  else if (type == "Bixi")
    plugin = new StationsPluginBixi();
  else if (type == "Transdev")
    plugin = new StationsPluginTransdev();
  else {
    qCritical() << "Unknown plugin type" << type;
    Q_ASSERT(plugin);
  }

  return plugin;
}

StationsPlugin *
StationsPluginFactorySimple::plugin(const QPointF & pt)
{
  foreach (QString id, cities.keys())
    if (cities[id].rect.contains(pt))
      return plugin(id);

  return NULL;
}

QString
StationsPluginFactorySimple::id() const
{
  return id_;
}

QString
StationsPluginFactorySimple::name() const
{
  return name_;
}

QString
StationsPluginFactorySimple::description() const
{
  return description_;
}

QIcon
StationsPluginFactorySimple::icon() const
{
  return icon_;
}
