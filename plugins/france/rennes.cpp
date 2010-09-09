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
#include "rennes.h"
#include "rennes_p.h"

StationsPluginRennes::StationsPluginRennes(QObject *parent)
  : StationsPluginSingle(parent)
{
  d = new StationsPluginSimplePrivateRennes();
}

StationsPluginRennes::~StationsPluginRennes()
{
  delete d;
}

QString
StationsPluginRennes::id() const
{
  return QLatin1String("rennes");
}

QString
StationsPluginRennes::name() const
{
  return QString::fromUtf8("Rennes");
}

QString
StationsPluginRennes::bikeName() const
{
  return QString::fromUtf8("VeloStar");
}

QIcon
StationsPluginRennes::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

void
StationsPluginRennes::handleInfos(const QByteArray & data)
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
    pos = QPointF(node.firstChildElement("latitude").toElement().text().toDouble(),
		  node.firstChildElement("longitude").toElement().text().toDouble());
    if (!d->rect.contains(pos))
      continue ;

    if (stations.find(id) == stations.end())
      stations[id] = new Station(this);
    station = stations[id];

    station->setId(id);
    if (station->name().isEmpty())
      station->setName(Tools::ucFirst(node.firstChildElement("name").toElement().text()));
    station->setPos(pos);

    station->setFreeSlots(node.firstChildElement("slotsavailable").toElement().text().toInt());
    station->setBikes(node.firstChildElement("bikesavailable").toElement().text().toInt());
    station->setTotalSlots(station->bikes() + station->freeSlots());
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
