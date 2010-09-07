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
#include "bordeaux.h"
#include "bordeaux_p.h"

StationsPluginBordeaux::StationsPluginBordeaux(QObject *parent)
  : StationsPluginSingle(parent)
{
  d = new StationsPluginSimplePrivateBordeaux();
}

StationsPluginBordeaux::~StationsPluginBordeaux()
{
  delete d;
}

QString
StationsPluginBordeaux::id() const
{
  return QLatin1String("bordeaux");
}

QString
StationsPluginBordeaux::name() const
{
  return QString::fromUtf8("Bordeaux");
}

QString
StationsPluginBordeaux::bikeName() const
{
  return QString::fromUtf8("vCub");
}

QIcon
StationsPluginBordeaux::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

void
StationsPluginBordeaux::handleInfos(const QByteArray & data)
{
  QRegExp re("\"gmap\": \\{ \"stations-map\": (.*)\\}\\);");
  QStringList captured;
  QString nodes;

  re.indexIn(data);
  captured = re.capturedTexts();
  if (captured.size() < 2)
    return ;
  nodes = captured.at(1);

  re = QRegExp("\"markers\": \\[(.*)\\]");
  re.indexIn(nodes);
  if (captured.size() < 2)
    return ;
  nodes = re.capturedTexts()[1];
  foreach (QString node, nodes.split("}, {")) {
    QMap < QString , QString > values;
    double lat, lng;
    Station *station = NULL;
    int id;

    node = node.mid(2); /* skip '" ' */

    foreach (QString data, node.split(", ")) {
      QStringList t = data.split(": ");
      QString key = t.at(0);
      QString value = t.at(1);

      key = key.trimmed().replace("\"", "");
      value = value.mid(1, value.size() - 2);

      values[key] = value;
    }

    if (values.find("text") != values.end()) {
      QDomDocument doc;
      QDomNodeList list;

      values["text"] = values["text"].replace("\\x", "%");
      values["text"] = QByteArray::fromPercentEncoding(values["text"].toUtf8());
      values["text"] = values["text"].replace("\\\"", "\"");
      doc.setContent(values["text"]);

      list = doc.elementsByTagName("div");

      for (int i = 0; i < list.size(); ++i) {
	QDomNode node = list.at(i);
	QDomNamedNodeMap attrs = node.attributes();
	QString c;

	if (!attrs.contains("class"))
	  continue ;
	c = attrs.namedItem("class").nodeValue();

	if (c == "gmap-titre") {
	  QStringList name = node.toElement().text().split(" - ");
	  QString tmp = name.at(0);

	  if (name.size() != 2)
	    continue ;

	  id = tmp.replace("#", "").toInt();

	  if (stations.find(id) == stations.end())
	    stations[id] = new Station(this);
	  station = stations[id];

	  station->setId(id);
	  if (station->name().isEmpty())
	    station->setName(name.at(1));
	}
	if (c == "gmap-adress") {
	  if (station->description().isEmpty())
	    station->setDescription(node.toElement().text());
	}
      }
      list = doc.elementsByTagName("strong");

      if (station && list.size() >= 2) {
	station->setBikes(list.at(0).toElement().text().toInt());
	station->setFreeSlots(list.at(1).toElement().text().toInt());
	station->setTotalSlots(station->freeSlots() + station->bikes());
      }
    }

    if (!station)
      continue ;
    lng = values["longitude"].toDouble();
    lat = values["latitude"].toDouble();
    station->setPos(QPointF(lat, lng));
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
