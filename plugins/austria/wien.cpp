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

#include <QtXml/QDomNode>

#include "station.h"
#include "wien.h"

StationsPluginWien::StationsPluginWien(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginWien::~StationsPluginWien()
{
}

QUrl
StationsPluginWien::imageUrl(int id)
{
  if (!stations.contains(id))
    return QUrl();
  id = stations[id]->data().toInt();
  return QString("http://dynamisch.citybikewien.at/include/"
		 "r4_get_data.php?url=terminal%2Fcont%2Fimg%2Fstation_%1.jpg").arg(id);
}

void
StationsPluginWien::handleInfos(const QByteArray & data)
{
  QDomDocument doc;
  QDomNode node;

  doc.setContent(data);
  node = doc.firstChildElement("stations").firstChildElement("station");

  while (!node.isNull()) {
    Station *station;
    QDomNamedNodeMap attrs = node.attributes();
    int id;
    qreal lat, lng;

    id = node.firstChildElement("id").text().toInt();

    if (stations.find(id) == stations.end())
      stations[id] = new Station(this);
    station = stations[id];

    station->setId(id);
    station->setData(node.firstChildElement("internal_id").text().toInt());

    if (station->name().isEmpty())
      station->setName(node.firstChildElement("name").text());
    if (station->description().isEmpty())
      station->setDescription(node.firstChildElement("description").text());

    lng = node.firstChildElement("longitude").text().toDouble();
    lat = node.firstChildElement("latitude").text().toDouble();
    station->setPos(QPointF(lat, lng));

    station->setBikes(node.firstChildElement("free_bikes").text().toInt());
    station->setFreeSlots(node.firstChildElement("free_boxes").text().toInt());
    station->setTotalSlots(node.firstChildElement("boxes").text().toInt());
    node = node.nextSiblingElement("station");
  }


  foreach (int id, stations.keys()) {
    if (rect().contains(stations[id]->pos()))
      continue ;
    delete stations[id];
    stations.remove(id);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
