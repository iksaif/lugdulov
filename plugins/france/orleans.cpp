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

#include <qjson/parser.h>

#include "station.h"
#include "tools.h"
#include "orleans.h"

StationsPluginOrleans::StationsPluginOrleans(QObject *parent)
  : StationsPluginSimple(parent)
{
}

StationsPluginOrleans::~StationsPluginOrleans()
{
}

void
StationsPluginOrleans::handleInfos(const QByteArray & data)
{
  QDomDocument doc;
  QDomNodeList list;

  doc.setContent(data);

  list = doc.elementsByTagName("marker");

  for (int i = 0; i < list.size(); ++i) {
    int id;
    Station *station;
    QDomNamedNodeMap attrs = list.at(i).attributes();

    id = attrs.namedItem("id").nodeValue().toInt();
    if (id <= 0)
      continue ;
    if (stations.find(id) == stations.end())
      stations[id] = new Station(this);
    station = stations[id];

    station->setId(id);
    if (station->name().isEmpty())
      station->setName(Tools::ucFirst(attrs.namedItem("name").nodeValue()));
    station->setPos(QPointF(attrs.namedItem("lat").nodeValue().toDouble(),
			    attrs.namedItem("lng").nodeValue().toDouble()));
  }

  foreach (int id, stations.keys()) {
    if (rect().contains(stations[id]->pos()))
      continue ;
    delete stations[id];
    stations.remove(id);
  }

  emit stationsCreated(stations.values());
}

void
StationsPluginOrleans::handleStatus(const QByteArray & data, int id)
{
  Station *station;
  QList < Station * > updated;

  if (!stations[id])
    return ;

  station = stations[id];

  QDomDocument doc;
  QDomNode node;

  doc.setContent(data);
  node = doc.firstChildElement("station");

  station->setFreeSlots(node.firstChildElement("attachs").text().toInt());
  station->setBikes(node.firstChildElement("bikes").text().toInt());
  station->setTotalSlots(station->bikes() + station->freeSlots());
  station->setTicket(node.firstChildElement("ticket").text().toInt());

  updated << station;
  emit stationsUpdated(updated);
}
