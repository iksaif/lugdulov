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
#include "stationsplugincitybike.h"
#include "stationspluginsimple_p.h"

StationsPluginCityBike::StationsPluginCityBike(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginCityBike::~StationsPluginCityBike()
{
}

void
StationsPluginCityBike::handleInfos(const QByteArray & data)
{
  QRegExp re("(<kml .*kml>)");
  QStringList captured;
  QDomDocument doc;
  QDomNode node;
  int id = 1;

  re.indexIn(data);

  captured = re.capturedTexts();
  if (!captured.size())
    return ;

  doc.setContent(captured[0]);
  node = doc.firstChild().firstChild().firstChildElement("Placemark");

  while (!node.isNull()) {
    QDomDocument subDoc;
    QDomNodeList list;
    Station *station;
    QString str;
    QStringList strl;

    station = getOrCreateStation(id);

    subDoc.setContent(node.firstChild().firstChild().nodeValue());

    if (station->name().isEmpty() || station->description().isEmpty()) {
      str = subDoc.firstChild().firstChild().firstChild().nodeValue();
      str = str.replace("\x92", "'");
      str = Tools::ucFirst(str.toLower());
      if (str.contains(" - "))
	strl = str.split(" - ");
      else if (str.contains(','))
	strl = str.split(",");
      else {
	strl << str;
	strl << str;
      }
      if (strl.size() >= 2) {
	if (station->name().isEmpty())
	  station->setName(strl[0].trimmed());
	if (station->description().isEmpty())
	  station->setDescription(strl[1].trimmed());
      }
    }

    str = node.firstChild().nextSibling().nextSibling().firstChild().firstChild().nodeValue();
    strl = str.split(",");

    if (strl.size() > 2) {
      if (station->pos().isNull())
	station->setPos(QPointF(strl[1].toDouble(), strl[0].toDouble()));
    }

    list = subDoc.firstChild().childNodes();
    if (list.size() >= 3) {
      list = list.at(2).childNodes();
      if (list.size() >= 3) {
	station->setBikes(list.at(0).nodeValue().toInt());
	station->setFreeSlots(list.at(2).nodeValue().toInt());
	station->setTotalSlots(station->bikes() + station->freeSlots());
      }
      node = node.nextSiblingElement("Placemark");
    }

    storeOrDropStation(station);

    ++id;
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
