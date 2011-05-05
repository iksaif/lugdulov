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
#include "melbourne.h"

StationsPluginMelbourne::StationsPluginMelbourne(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginMelbourne::~StationsPluginMelbourne()
{
}
#include <QDebug>
void
StationsPluginMelbourne::handleInfos(const QByteArray & data)
{
  QJson::Parser parser;
  bool ok;
  QVariant result = parser.parse(data, &ok);

  if (!ok)
    return ;

  foreach (QVariant var, result.toList()) {
    QVariantMap sta = var.toMap();
    int id;
    Station *station;

    if (sta.count() == 0)
      continue;

    id = sta["id"].toInt(&ok);

    if (!ok)
      continue ;

    station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(sta["name"].toString());
    if (station->pos().isNull())
      station->setPos(QPointF(sta["lat"].toReal(), sta["long"].toReal()));

    station->setFreeSlots(sta["nbEmptyDocks"].toInt());
    station->setBikes(sta["nbBikes"].toInt());
    station->setTotalSlots(station->bikes() + station->freeSlots());

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
