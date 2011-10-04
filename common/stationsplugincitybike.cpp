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

#include <QtNetwork/QNetworkReply>
#include <QtCore/QStringList>
#include <QtCore/QRegExp>
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include "tools.h"
#include "station.h"
#include "stationsplugincitybike.h"
#include "stationspluginsimple_p.h"

StationsPluginCityBike::StationsPluginCityBike(QObject *parent)
  : StationsPluginSimple(parent)
{
  mode = "unknown";
  dataUrl = "";
}

StationsPluginCityBike::~StationsPluginCityBike()
{
}

void
StationsPluginCityBike::update(Station *station)
{
  if (mode == "unknown") { /* We need to download the main page first */
    mode = "processing"; /* Avoid recursion */
    request(infosUrl());
  }

  if (mode == "kml")
    fetchOnline();
  else {
    QByteArray data = QString("idStation=%1").arg(station->id()).toAscii();

    request(statusUrl(station->id()), station->id(), data);
  }
}

void
StationsPluginCityBike::update(const QList < Station * > & stations)
{
  if (mode == "kml")
    fetchOnline();
  else
    StationsPluginSimple::update(stations);
}

QUrl
StationsPluginCityBike::statusUrl(int id)
{
  if (dataUrl.isEmpty())
    return StationsPluginSimple::statusUrl(id);
  else
    return dataUrl.arg(id);
}

void
StationsPluginCityBike::handleInfosKml(const QByteArray & data)
{
  QRegExp re("(<kml .*kml>)");
  QStringList captured;
  QDomDocument doc;
  QDomNode node;
  int id = 1;

  re.indexIn(data);

  captured = re.capturedTexts();
  if (!captured.size())
    return ;

  doc.setContent(captured[0]);
  node = doc.firstChild().firstChild().firstChildElement("Placemark");

  while (!node.isNull()) {
    QDomDocument subDoc;
    QDomNodeList list;
    Station *station;
    QString str;
    QStringList strl;

    station = getOrCreateStation(id);

    subDoc.setContent(node.firstChild().firstChild().nodeValue());

    if (station->name().isEmpty() || station->description().isEmpty()) {
      str = subDoc.firstChild().firstChild().firstChild().nodeValue();
      strl = parseName(str);
      if (strl.size() >= 2) {
	if (station->name().isEmpty())
	  station->setName(strl[0].trimmed());
	if (station->description().isEmpty())
	  station->setDescription(strl[1].trimmed());
      }
    }

    str = node.firstChild().nextSibling().nextSibling().firstChild().firstChild().nodeValue();
    strl = str.split(",");

    if (strl.size() > 2) {
      if (station->pos().isNull())
	station->setPos(QPointF(strl[1].toDouble(), strl[0].toDouble()));
    }

    list = subDoc.firstChild().childNodes();
    if (list.size() >= 3) {
      list = list.at(2).childNodes();
      if (list.size() >= 3) {
	station->setBikes(list.at(0).nodeValue().toInt());
	station->setFreeSlots(list.at(2).nodeValue().toInt());
	station->setTotalSlots(station->bikes() + station->freeSlots());
      }
      node = node.nextSiblingElement("Placemark");
    }

    storeOrDropStation(station);

    ++id;
  }
}

QList < QStringList >
StationsPluginCityBike::findAll(const QRegExp & re, const QByteArray & data)
{
  QList < QStringList > ret;
  int ofs = 0;

  while ((ofs = re.indexIn(data, ofs)) >= 0) {
    QStringList captured = re.capturedTexts();

    ofs += re.matchedLength();

    if (!captured.isEmpty())
      ret << captured;
  }

  return ret;
}

void
StationsPluginCityBike::handleInfosJs(const QByteArray & data)
{
  QList < QPointF > points;
  QList < int > ids;
  QList < QString > names;
  QRegExp re;
  int i = 0;

  re = QRegExp("point = new GLatLng\\((.+),(.+)\\);");
  re.setMinimal(true);

  foreach (QStringList matches, findAll(re, data))
    points << QPointF(matches.at(1).toDouble(), matches.at(2).toDouble());

  re = QRegExp("data:.*idStation=.*([\\d]+)[\"\\+\\W]");
  re.setMinimal(true);

  foreach (QStringList matches, findAll(re, data))
    ids << matches.at(1).toInt();

  re = QRegExp("<a href=\"javascript:.*ada\\('([0-9]+)'\\)\">(.+)</a>");
  re.setMinimal(true);

  foreach (QStringList matches, findAll(re, data))
    if (matches.at(1) != "0" && matches.at(1) != "-1")
      names << matches.at(2);

  re = QRegExp("url:.*\"([^,]+).*\"");
  re.setMinimal(true);
  re.indexIn(data);

  if (re.matchedLength()) {
    dataUrl = infosUrl().scheme() + "://" + infosUrl().authority() + "/";
    dataUrl += re.capturedTexts().at(1);
  } else
    return ;

  foreach (int id, ids) {
    Station *station;
    QStringList namedescr;

    station = getOrCreateStation(id);

    if (station->name().isEmpty() || station->description().isEmpty()) {
      if (names.size() == points.size()) {
	namedescr = parseName(names[i]);
	if (namedescr.size() >= 2) {
	  if (station->name().isEmpty())
	    station->setName(namedescr[0].trimmed());
	  if (station->description().isEmpty())
	    station->setDescription(namedescr[1].trimmed());
	}
      } else {
	station->setName(QString("Station %1").arg(id));
      }
    }

    station->setPos(points[i]);

    storeOrDropStation(station);
    i++;
  }

}

void
StationsPluginCityBike::handleInfos(const QByteArray & data)
{
  if (data.contains("<kml xmlns=\"http://earth.google.com/kml/2.0\">")) {
    handleInfosKml(data);
    mode = "kml";
  } else {
    handleInfosJs(data);
    mode = "js";
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}

void
StationsPluginCityBike::handleStatus(const QByteArray & data, int id)
{
  if (mode == "js")
    handleStatusJs(data, id);
}

void
StationsPluginCityBike::handleStatusJs(const QByteArray & data, int id)
{
  Station *station;
  QList < Station * > updated;
  QRegExp re = QRegExp("\\n\\s*\\:\\s*(\\d+)");
  QList < QStringList > captured;

  if (!stations[id])
    return ;

  station = stations[id];

  re.setMinimal(true);

  captured = findAll(re, data);

  if (captured.size() == 2) {
    station->setBikes(captured.at(0).at(1).toInt());
    station->setFreeSlots(captured.at(1).at(1).toInt());
    station->setTotalSlots(station->bikes() + station->freeSlots());
  }

  updated << station;
  emit stationsUpdated(updated);
}

QStringList
StationsPluginCityBike::parseName(const QString & name)
{
  QStringList ret;
  QString str = name;

  str = str.replace("\x92", "'");
  str = Tools::ucFirst(str.toLower());
  if (str.contains(" - ") && mode == "kml")
    ret = str.split(" - ");
  else if (str.contains(','))
    ret = str.split(",");
  else {
    ret << str;
    ret << "";
  }

  return ret;
}

void
StationsPluginCityBike::loadData(QDomDocument & doc)
{
  QDomElement node = doc.firstChildElement("cache");

  node = node.firstChildElement("citybike");
  node = node.firstChildElement("dataUrl");

  if (node.isNull())
    return ;

  dataUrl = node.text();
}

void
StationsPluginCityBike::saveData(QDomDocument & doc)
{
  QDomElement citybike = doc.createElement("citybike");
  QDomElement url = doc.createElement("dataUrl");

  url.appendChild(doc.createTextNode(dataUrl));
  citybike.appendChild(url);

  doc.firstChildElement("cache").appendChild(citybike);
}
