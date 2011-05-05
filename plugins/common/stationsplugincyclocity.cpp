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
#include <QtGui/QDesktopServices>
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QtCore/QFile>
#include <QtCore/QtPlugin>
#include <QtCore/QStringList>
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include "tools.h"
#include "station.h"
#include "stationsplugincyclocity.h"
#include "tools.h"

StationsPluginCycloCity::StationsPluginCycloCity(QObject *parent)
  : StationsPluginSimple(parent)
{
}

StationsPluginCycloCity::~StationsPluginCycloCity()
{
}

void
StationsPluginCycloCity::handleInfos(const QByteArray & data)
{
  QDomDocument doc;
  QDomNode node;

  doc.setContent(data);
  node = doc.firstChild().nextSibling().firstChild().firstChildElement("marker");

  while (!node.isNull()) {
    QDomNamedNodeMap attr = node.attributes();
    Station *station;
    bool ok;
    int id = attr.namedItem("number").nodeValue().toUInt(&ok);
    QString name = Tools::ucFirst(attr.namedItem("name").nodeValue());
    QString address = Tools::ucFirst(attr.namedItem("address").nodeValue());
    double lat = attr.namedItem("lat").nodeValue().toDouble();
    double lng = attr.namedItem("lng").nodeValue().toDouble();

    node = node.nextSiblingElement("marker");

    if (id < 0 || !ok)
      continue ;

    station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(Tools::ucFirst(name));
    if (station->description().isEmpty())
      station->setDescription(Tools::ucFirst(address));
    if (station->pos().isNull())
      station->setPos(QPointF(lat, lng));

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
}

void
StationsPluginCycloCity::handleStatus(const QByteArray & data, int id)
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

  station->setFreeSlots(node.firstChildElement("free").text().toInt());
  station->setTotalSlots(node.firstChildElement("total").text().toInt());
  station->setBikes(node.firstChildElement("available").text().toInt());
  station->setTicket(node.firstChildElement("ticket").text().toInt());

  updated << station;
  emit stationsUpdated(updated);
}
