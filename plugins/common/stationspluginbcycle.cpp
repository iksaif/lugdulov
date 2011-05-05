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

#include "station.h"
#include "tools.h"
#include "stationspluginbcycle.h"

StationsPluginBcycle::StationsPluginBcycle(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginBcycle::~StationsPluginBcycle()
{
}

void
StationsPluginBcycle::handleInfos(const QByteArray & data)
{
  QRegExp rgpos("point = new google\\.maps\\.LatLng\\((-?[0-9\\.]+), (-?[0-9\\.]+)\\);");
  QRegExp rgmark("marker = new createMarker\\(point, \"(.*)\", icon, back\\);");
  QRegExp rghtml("<div class=\'location\'><strong>(.*)</strong><br />(.*)</div><div class=\'avail\'>Bikes available: <strong>([0-9]+)</strong><br />Docks available: <strong>([0-9]+)</strong></div><br/>");

  QList < QPointF > positions;

  int ofs = 0;
  int id = 1;

  rgpos.setMinimal(true);
  rgmark.setMinimal(true);
  rghtml.setMinimal(true);

  while ((ofs = rgpos.indexIn(data, ofs)) >= 0) {
    QStringList capt = rgpos.capturedTexts();

    positions << QPointF(capt.at(1).toDouble(), capt.at(2).toDouble());
    ofs += rgpos.matchedLength();
  }

  ofs = 0;

  while ((ofs = rgmark.indexIn(data, ofs)) >= 0) {
    Station *station = getOrCreateStation(id++);
    QStringList capt = rgmark.capturedTexts();

    rghtml.indexIn(capt.at(1));
    capt = rghtml.capturedTexts();

    if (station->name().isEmpty())
      station->setName(capt.at(1));
    if (station->description().isEmpty())
      station->setDescription(QString(capt.at(2)).replace("<br />", ""));
    if (station->pos().isNull())
      station->setPos(positions.takeFirst());

    station->setBikes(capt.at(3).toDouble());
    station->setFreeSlots(capt.at(4).toDouble());
    station->setTotalSlots(station->bikes() + station->freeSlots());

    storeOrDropStation(station);

    if (positions.isEmpty())
      break ;

    ofs += rgmark.matchedLength();
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
