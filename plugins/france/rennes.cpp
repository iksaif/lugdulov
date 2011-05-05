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

#include <QtXml/QDomNode>

#include "tools.h"
#include "station.h"
#include "rennes.h"

StationsPluginRennes::StationsPluginRennes(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginRennes::~StationsPluginRennes()
{
}

void
StationsPluginRennes::handleInfos(const QByteArray & data)
{
  QDomDocument doc;
  QDomNodeList list;

  doc.setContent(data);

  list = doc.elementsByTagName("station");
  for (int i = 0; i < list.size(); ++i) {
    bool ok;
    int id;
    Station *station;
    QPointF pos;
    QDomNode node = list.at(i);

    id = node.firstChildElement("id").toElement().text().toInt(&ok);

    if (id <= 0 || !ok)
      continue ;

    pos = QPointF(node.firstChildElement("latitude").toElement().text().toDouble(),
		  node.firstChildElement("longitude").toElement().text().toDouble());

    station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(Tools::ucFirst(node.firstChildElement("name").toElement().text()));
    if (station->pos().isNull())
      station->setPos(pos);

    station->setFreeSlots(node.firstChildElement("slotsavailable").toElement().text().toInt());
    station->setBikes(node.firstChildElement("bikesavailable").toElement().text().toInt());
    station->setTotalSlots(station->bikes() + station->freeSlots());

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
