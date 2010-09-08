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
#include "vannes.h"
#include "vannes_p.h"

StationsPluginVannes::StationsPluginVannes(QObject *parent)
  : StationsPluginSingle(parent)
{
  d = new StationsPluginSimplePrivateVannes();
}

StationsPluginVannes::~StationsPluginVannes()
{
  delete d;
}

QString
StationsPluginVannes::id() const
{
  return QLatin1String("vannes");
}

QString
StationsPluginVannes::name() const
{
  return QString::fromUtf8("Vannes");
}

QString
StationsPluginVannes::bikeName() const
{
  return QString::fromUtf8("Velocea");
}

QIcon
StationsPluginVannes::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

QUrl
StationsPluginVannes::infosUrl()
{
  QString url;

  url = "http://www.velocea.fr/vannes/vannescms.nsf/vStands?readviewentries&ms=%1";
  url = url.arg(QDateTime::currentDateTime().toTime_t());

  return QUrl(url);
}

void
StationsPluginVannes::handleInfos(const QByteArray & data)
{
  QDomDocument doc;
  QDomNodeList list;

  doc.setContent(data);

  list = doc.elementsByTagName("viewentry");
  for (int i = 0; i < list.size(); ++i) {
    int id;
    Station *station;
    QMap < QString, QString > values;
    QDomNode node = list.at(i).firstChildElement("entrydata");

    while (!node.isNull()) {
      values.insert(node.attributes().namedItem("name").nodeValue(),
		    node.firstChild().toElement().text());
      node = node.nextSiblingElement("entrydata");
    }

    id = values["standId"].toInt();
    if (id <= 0)
      continue ;
    if (stations.find(id) == stations.end())
      stations[id] = new Station(this);
    station = stations[id];

    station->setId(id);
    if (station->name().isEmpty())
      station->setName(values["standName"]);
    if (station->description().isEmpty())
      station->setDescription(values["standComments"]);
    station->setTotalSlots(values["Capacity"].toInt());
    station->setFreeSlots(values["portsFree"].toInt());
    station->setBikes(values["bikesAvaile"].toInt());
    if (values.contains("$1")) {
      QStringList coord = values["$1"].split(",");

      station->setPos(QPointF(coord.at(0).toDouble(), coord.at(1).toDouble()));
    }
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
