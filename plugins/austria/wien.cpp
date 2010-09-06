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
#include "wien.h"
#include "wien_p.h"

StationsPluginWien::StationsPluginWien(QObject *parent)
  : StationsPluginSingle(parent)
{
  d = new StationsPluginSimplePrivateWien();
}

StationsPluginWien::~StationsPluginWien()
{
  delete d;
}

QString
StationsPluginWien::id() const
{
  return QLatin1String("wien");
}

QString
StationsPluginWien::name() const
{
  return QString::fromUtf8("Wien");
}

QString
StationsPluginWien::bikeName() const
{
  return QString::fromUtf8("CityBike");
}

QIcon
StationsPluginWien::bikeIcon() const
{
  return QIcon(":/res/bike.png");
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
    if (d->rect.contains(stations[id]->pos()))
      continue ;
    delete stations[id];
    stations.remove(id);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
