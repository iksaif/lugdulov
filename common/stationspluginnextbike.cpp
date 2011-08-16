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

#include <QtCore/QtPlugin>
#include <QtCore/QStringList>
#include <QtXml/QDomNode>

#include "tools.h"
#include "station.h"
#include "stationspluginnextbike.h"
#include "stationspluginsimple_p.h"

StationsPluginNextBike::StationsPluginNextBike(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginNextBike::~StationsPluginNextBike()
{
}

void
StationsPluginNextBike::handleInfos(const QByteArray & data)
{
  QDomDocument doc;
  QDomNode country, city, node;
  QString cityId = id();

  doc.setContent(data);

  country = doc.firstChildElement("markers").firstChildElement("country");

  while (!country.isNull()) {
    city = country.firstChildElement("city");

    while (!city.isNull()) {

      if (city.toElement().attribute("uid") == cityId)
	goto found;

      QString name = city.toElement().attribute("name");

      name = name.trimmed().toLower();
      name.replace(" ", "_");
      name = name.normalized(QString::NormalizationForm_KD);

      for (int i = 0; i < name.size(); ++i)
	if ((!name[i].isLetterOrNumber() && !name[i].isPunct()) ||
	    name[i].category() == QChar::Letter_Modifier)
	  name.remove(i, 1);
      for (int i = 0; i < name.size(); ++i) {
	if (name[i].toAscii() == '\0')
	  name.remove(i, 1);
	if (name[i].toAscii() == '-')
	  name[i] = '_';
      }

      if (name == cityId)
	goto found;

      city = city.nextSiblingElement("city");
    }
    country = country.nextSiblingElement("country");
  }

  return ;

 found:
  node = city.firstChildElement("place");
  while (!node.isNull()) {
    Station *station;
    bool ok;
    QDomNamedNodeMap attrs = node.attributes();
    int id;
    qreal lat, lng;

    id = attrs.namedItem("uid").nodeValue().toInt(&ok);

    if (!ok)
      continue ;

    station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(attrs.namedItem("name").nodeValue());

    lat = attrs.namedItem("lat").nodeValue().toDouble();
    lng = attrs.namedItem("lng").nodeValue().toDouble();

    if (station->pos().isNull())
      station->setPos(QPointF(lat, lng));

    station->setBikes(attrs.namedItem("bikes").nodeValue().replace("+", "").toInt());
    if (attrs.contains("bike_racks")) {
      station->setFreeSlots(attrs.namedItem("bike_racks").nodeValue().toInt());
      station->setTotalSlots(station->bikes() + station->freeSlots());
    } else {
      station->setFreeSlots(-1);
      station->setTotalSlots(-1);
    }
    node = node.nextSiblingElement("place");

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
