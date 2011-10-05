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

#include <qjson/parser.h>

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
  QJson::Parser parser;
  bool ok;
  QVariant result;
  QVariantMap map;

  result = parser.parse(data, &ok);

  if (!ok)
    return ;

  map = result.toMap();
  map = map["d"].toMap();

  foreach (QVariant var, map["list"].toList()) {
    QVariantMap marker = var.toMap();
    QPointF position;
    int id;
    Station *station;
    bool ok;

    if (marker.count() == 0)
      continue;

    id = marker["Id"].toInt(&ok);

    if (!ok)
      continue ;

    if (marker["Status"].toString() == "ComingSoon" && marker["TotalDocks"].toInt() <= 1)
      continue ;

    QVariantMap location = marker["Location"].toMap();

    position = QPointF(location["Latitude"].toReal(), location["Longitude"].toReal());

    if (!rect().contains(position))
      continue ;

    station = getOrCreateStation(id);

    station->setName(marker["Name"].toString());
    station->setDescription(marker["Address"].toMap()["Street"].toString());

    station->setBikes(marker["BikesAvailable"].toInt());
    station->setTotalSlots(marker["TotalDocks"].toInt());
    station->setFreeSlots(station->totalSlots() - station->bikes());

    station->setPos(position);

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
