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

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QRegExp>
#include <QtCore/QTimer>

#include <QtCore/QDebug>

#include "station.h"
#include "stationsplugincallabike.h"
#include "stationspluginsimple_p.h"

StationsPluginCallABike::StationsPluginCallABike(QObject *parent)
  : StationsPluginSingle(parent),
    gotCookies(false),
    fetch(false)
{
}

StationsPluginCallABike::~StationsPluginCallABike()
{
}

void
StationsPluginCallABike::init()
{
  request(infosUrl().scheme() + "://" + infosUrl().authority(), -1);
}

void
StationsPluginCallABike::fetchOnline()
{
  QString data;
  int uid = 0;

  /* We don't have cookies yet, delay request */
  if (!gotCookies) {
    fetch = true;
    return ;
  }

  if (id().contains("_"))
    uid = id().split("_").last().toInt();

  data = "xajax=showStadtOverview";
  data += QString("&xajaxargs[]=%1").arg(uid);
  data += "&xajaxargs[]=" + QUrl::toPercentEncoding("<xjxobj><e><k>kerngebiet</k><v>true</v></e></xjxobj>");

  request(infosUrl(), -1, data.toAscii());
}

void
StationsPluginCallABike::handleInfos(const QByteArray & data)
{
  QVariant markers;

  if (!gotCookies) { /* If we are loading the first page to get some cookies */
    gotCookies = true;
    fetchOnline();
    fetch = false;
    return ;
  }

  markers = parseHal2Marker(data);

  foreach (QVariant var, markers.toList()) {
    QVariantMap marker = var.toMap();
    int id;
    Station *station;
    bool ok;

    if (marker.count() == 0)
      continue;

    id = marker["id"].toInt(&ok);

    if (!ok)
      continue ;

    station = getOrCreateStation(id);
    //if (station->name().isEmpty()) // Always update the name because we can't trust the id
    station->setName(marker["name"].toString());
    //if (station->pos().isNull()) // Same for the position
    station->setPos(QPointF(marker["lat"].toReal(), marker["lng"].toReal()));
    station->setBikes(marker["bikes"].toInt());

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}

QString
StationsPluginCallABike::cleanElement(const QString & elem)
{
  QString str = elem;

  str = str.trimmed();
  if (str.startsWith("'"))
    str = str.mid(1);
  if (str.endsWith("'"))
    str = str.mid(0, str.size() - 1);

  return str;
}

QVariant
StationsPluginCallABike::parseHal2Marker(const QByteArray & data)
{
  QVariantList ret;
  QRegExp re = QRegExp("createHAL2Marker\\((.*),\\{(.*)\\);");
  int ofs = 0;
  int id = 0;

  re.setMinimal(true);

  while ((ofs = re.indexIn(data, ofs)) >= 0) {
    QStringList captured = re.capturedTexts();
    QStringList elems;
    QVariantMap map;
    QRegExp bikeRe;
    QRegExp nameRe;

    ofs += re.matchedLength();

    if (captured.size() != 3)
      continue;

    elems = captured.at(1).trimmed().split(",");
    if (elems.size() < 2)
      continue ;

    map["lat"] = cleanElement(elems[1]).toDouble();
    map["lng"] = cleanElement(elems[0]).toDouble();
    map["id"] = ++id; // Don't use the real id, it's too big and we don't need it
    //map["id"] = cleanElement(elems[3]).toLongLong();
    //map["name"] = cleanElement(elems[4]);

    nameRe = QRegExp("tooltip: '(.*)'");
    nameRe.setMinimal(true);
    nameRe.indexIn(captured.at(1));

    if (!nameRe.capturedTexts().isEmpty()) {
      map["name"] = nameRe.capturedTexts().at(1);
    } else {
      map["name"] = QString("Station %1").arg(map["id"].toInt());
    }

    bikeRe = QRegExp("bikes: \"([0-9,]*)\"");
    bikeRe.setMinimal(true);
    bikeRe.indexIn(captured.at(1));

    if (!bikeRe.capturedTexts().isEmpty()) {
      QString bikes = bikeRe.capturedTexts().at(1);

      if (bikes.contains(','))
	map["bikes"] = bikes.count(',') + 1;
      else
	map["bikes"] = 0;
    }

    ret << map;
  }

  return ret;
}
