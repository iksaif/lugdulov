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

#include <QtCore/QCoreApplication>
#include <QtCore/QTimer>
#include <QtCore/QVariant>
#include <QtCore/QDebug>

#include <qjson/serializer.h>

#include <iostream>

#include "cli.h"
#include "stationspluginmanager.h"
#include "stationsplugin.h"
#include "station.h"

static const struct QCommandLineConfigEntry conf[] =
  {
    { QCommandLine::Switch, 'l', "list", "List available plugins (default)", QCommandLine::Optional },
    { QCommandLine::Switch, 'i', "infos", "Fetch informations", QCommandLine::Optional },
    { QCommandLine::Switch, 't', "test", "Test plugins", QCommandLine::Optional },
    { QCommandLine::Option, 'f', "fmt", "Output format (xml, json (default))", QCommandLine::Optional },
    { QCommandLine::Param, '\0', "plugin", "Fetch informations for that plugin", QCommandLine::OptionalMultiple },
    QCOMMANDLINE_CONFIG_ENTRY_END
  };

Cli::Cli(QObject *parent)
  : QObject(parent)
{
  manager = new StationsPluginManager(this);

  cmdline = new QCommandLine(this);
  cmdline->setConfig(conf);
  cmdline->enableVersion(true); // enable -v // --version
  cmdline->enableHelp(true); // enable -h / --help

  connect(cmdline, SIGNAL(switchFound(const QString &)),
	  this, SLOT(switchFound(const QString &)));
  connect(cmdline, SIGNAL(optionFound(const QString &, const QVariant &)),
	  this, SLOT(optionFound(const QString &, const QVariant &)));
  connect(cmdline, SIGNAL(paramFound(const QString &, const QVariant &)),
	  this, SLOT(paramFound(const QString &, const QVariant &)));
  connect(cmdline, SIGNAL(parseError(const QString &)),
	  this, SLOT(parseError(const QString &)));

  action = List;
  format = Json;

  cmdline->parse();

  QTimer::singleShot(0, this, SLOT(run()));
}

Cli::~Cli()
{
}

void
Cli::switchFound(const QString & name)
{
  if (name == "list")
    action = List;
  if (name == "infos")
    action = Infos;
  if (name == "test")
    action = Test;
}

void
Cli::optionFound(const QString & name, const QVariant & value)
{
  if (name == "fmt") {
    QString fmt = value.toString();

    if (value == "json")
      format = Json;
    else if (value == "xml")
      format = Xml;
    else
      parseError("Invalid format, must be json or xml");
  }
}

void
Cli::paramFound(const QString & name, const QVariant & value)
{
  if (name == "plugin")
    plugins << value.toString();
}

void
Cli::parseError(const QString & error)
{
  qWarning() << qPrintable(error);
  cmdline->showHelp(true, -1);
  QCoreApplication::quit();
}

void
Cli::serialize(const QVariant & out)
{
  if (format == Json) {
    QJson::Serializer serializer;
    QByteArray json;

    serializer.setIndentMode(QJson::IndentMinimum);
    json = serializer.serialize(out);

    std::cout << json.data() << std::endl;
  }
  if (format == Xml) {
    std::cout << "not implented yet" << std::endl;
  }
}

void
Cli::stationsCreated(const QList < Station *> & data)
{
  StationsPlugin *plugin = (StationsPlugin *)sender();

  if (stations[plugin].isEmpty())
    stations[plugin] = data;
  else {
    foreach (Station *station, data)
      if (!stations[plugin].contains(station))
	stations[plugin].append(station);
  }

  std::cerr << updated[plugin].size() << "/" << stations[plugin].size()
	    << " total: " << stations.size() - working.size() << "/"
	    << stations.size() << "                                \r";


  foreach (Station *station, data)
    plugin->updateCached(station);
}

void
Cli::stationsUpdated(const QList < Station *> & data)
{
  StationsPlugin *plugin = (StationsPlugin *)sender();

  foreach (Station *station, data) {
    if (station->bikes() != -1)
      updated[plugin][station] = true;
  }

  std::cerr << updated[plugin].size() << "/" << stations[plugin].size()
	    << " total: " << stations.size() - working.size() << "/"
	    << stations.size() << "                                \r";

  if (updated[plugin].size() == stations[plugin].size())
    working.remove(plugin);
  if (working.isEmpty()) {
    if (action == Infos)
      infosFinished();
    if (action == Test)
      testFinished();
  }
}

void
Cli::stationsError()
{
  StationsPlugin *plugin = (StationsPlugin *)sender();

  working.remove(plugin);
  if (working.isEmpty()) {
    if (action == Infos)
      QTimer::singleShot(5, this, SLOT(infosFinished()));
    if (action == Test)
      QTimer::singleShot(5, this, SLOT(testFinished()));
  }
}

void
Cli::testFinished()
{
  QVariantMap map;
  QVariantList cities;

  foreach(StationsPlugin *plugin, stations.keys()) {
    QVariantMap city;
    QVariantList infos;
    int bikes = 0, freeSlots = 0, totalSlots = 0;

    city["name"] = plugin->name();
    city["id"] = plugin->id();
    city["bikeName"] = plugin->bikeName();

    foreach(Station *station, stations[plugin]) {
      if (station->freeSlots() >= 0)
	freeSlots += station->freeSlots();
      if (station->totalSlots() >= 0)
	totalSlots += station->totalSlots();
      if (station->bikes() >= 0)
	bikes += station->bikes();
    }

    city["bikes"] = bikes;
    city["freeSlots"] = freeSlots;
    city["totalSlots"] = totalSlots;
    city["stations"] = stations[plugin].count();

    cities.append(city);
  }

  map["cities"] = cities;
  serialize(map);
  exit(1);
}

void
Cli::infosFinished()
{
  QVariantMap map;
  QVariantList cities;

  foreach(StationsPlugin *plugin, stations.keys()) {
    QVariantMap city;
    QVariantMap pos;
    QVariantList infos;

    city["name"] = plugin->name();
    city["id"] = plugin->id();
    city["bikeName"] = plugin->bikeName();

    pos["latitude"] = plugin->center().x();
    pos["longitude"] = plugin->center().y();
    pos["latitude_min"] = plugin->rect().x();
    pos["latitude_max"] = plugin->rect().x() + plugin->rect().width();
    pos["longitude_min"] = plugin->rect().y();
    pos["longitude_max"] = plugin->rect().y() + plugin->rect().height();

    city["pos"] = pos;

    foreach(Station *station, stations[plugin]) {
      QVariantMap sta;
      QVariantMap pos;

      sta["id"] = station->id();
      sta["name"] = station->name();
      sta["description"] = station->description();
      sta["region"] = station->region();
      sta["freeSlots"] = station->freeSlots();
      sta["totalSlots"] = station->totalSlots();
      sta["bikes"] = station->bikes();

      pos["latitude"] = station->pos().x();
      pos["longitude"] = station->pos().y();
      sta["pos"] = pos;

      infos.append(sta);
    }

    city["stations"] = infos;

    cities.append(city);
  }

  map["cities"] = cities;
  serialize(map);
  exit(1);
}

void
Cli::list()
{
  QVariantMap map;
  QVariantList cities;

  foreach(StationsPlugin *plugin, manager->stations().values()) {
    QVariantMap city;
    QVariantMap pos;

    city["name"] = plugin->name();
    city["id"] = plugin->id();
    city["bikeName"] = plugin->bikeName();

    pos["latitude"] = plugin->center().x();
    pos["longitude"] = plugin->center().y();
    pos["latitude_min"] = plugin->rect().x();
    pos["latitude_max"] = plugin->rect().x() + plugin->rect().width();
    pos["longitude_min"] = plugin->rect().y();
    pos["longitude_max"] = plugin->rect().y() + plugin->rect().height();

    city["pos"] = pos;

    cities.append(city);
  }

  map["cities"] = cities;
  serialize(map);
}


void
Cli::infos()
{
  fetchAll();
}

void
Cli::test()
{
  fetchAll();
}

void
Cli::fetchAll()
{
  foreach(StationsPlugin *plugin, manager->stations().values()) {
    if (!plugins.size() || plugins.contains(plugin->id()) || plugins.contains(plugin->name())) {
      working[plugin] = true;

      connect(plugin, SIGNAL(error(const QString &, const QString &)),
	      this, SLOT(stationsError()));
      connect(plugin, SIGNAL(stationsCreated(const QList < Station *> &)),
	      this, SLOT(stationsCreated(const QList < Station *> &)));
      connect(plugin, SIGNAL(stationsUpdated(const QList < Station *> &)),
	      this, SLOT(stationsUpdated(const QList < Station *> &)));

      plugin->fetchAll();
      plugin->fetchOnline();
    }
  }
}

void
Cli::run()
{
  if (action == List) {
    list();
    QCoreApplication::instance()->quit();
  } else if (action == Infos) {
    infos();
  } else if(action == Test) {
    test();
  } else {
    QCoreApplication::instance()->quit();
  }
}
