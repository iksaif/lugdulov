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

#include <QtCore/QRegExp>

#include <qjson/parser.h>

#include "station.h"
#include "tools.h"
#include "taipei.h"

StationsPluginTaipei::StationsPluginTaipei(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginTaipei::~StationsPluginTaipei()
{
}

void
StationsPluginTaipei::handleInfos(const QByteArray & data)
{
  QByteArray js = data;
  QJson::Parser parser;
  bool ok;
  QVariant result;
  QVariantMap map;

  js = js.replace("var giant =", "");
  js = js.replace("\n]};", "]}");
  js = js.replace("\xef\xbb\xbf", "");

  result = parser.parse(js, &ok);

  if (!ok)
    return ;

  map = result.toMap();

  foreach (QVariant var, map["station"].toList()) {
    QVariantMap sta = var.toMap();
    int id;
    Station *station;
    bool ok;

    if (sta.count() == 0)
      continue;

    id = sta["id"].toInt(&ok);

    if (!ok)
      continue ;

    station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(sta["name"].toString());
    if (station->pos().isNull())
      station->setPos(QPointF(sta["lat"].toReal(), sta["lng"].toReal()));

    station->setBikes(sta["availBike"].toInt());
    station->setTotalSlots(sta["capacity"].toInt());
    station->setFreeSlots(station->totalSlots() - station->bikes());

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
