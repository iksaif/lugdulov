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
#include "tools.h"
#include "montreal.h"

StationsPluginMontreal::StationsPluginMontreal(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginMontreal::~StationsPluginMontreal()
{
}

void
StationsPluginMontreal::handleInfos(const QByteArray & data)
{
  QDomDocument doc;
  QDomNodeList list;

  doc.setContent(data);

  list = doc.elementsByTagName("station");
  for (int i = 0; i < list.size(); ++i) {
    int id;
    Station *station;
    QPointF pos;
    QDomNode node = list.at(i);

    id = node.firstChildElement("id").toElement().text().toInt();
    if (id <= 0)
      continue ;
    pos = QPointF(node.firstChildElement("lat").toElement().text().toDouble(),
		  node.firstChildElement("long").toElement().text().toDouble());
    if (!rect().contains(pos))
      continue ;

    if (stations.find(id) == stations.end())
      stations[id] = new Station(this);
    station = stations[id];

    station->setId(id);
    if (station->name().isEmpty())
      station->setName(Tools::ucFirst(node.firstChildElement("name").toElement().text()));
    station->setPos(pos);

    station->setFreeSlots(node.firstChildElement("nbEmptyDocks").toElement().text().toInt());
    station->setBikes(node.firstChildElement("nbBikes").toElement().text().toInt());
    station->setTotalSlots(station->bikes() + station->freeSlots());
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
