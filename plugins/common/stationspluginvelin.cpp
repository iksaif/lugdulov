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

#include <qjson/parser.h>

#include "tools.h"
#include "station.h"
#include "stationspluginvelin.h"
#include "stationspluginsimple_p.h"

StationsPluginVelIn::StationsPluginVelIn(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginVelIn::~StationsPluginVelIn()
{
}

void
StationsPluginVelIn::handleInfos(const QByteArray & data)
{
  QJson::Parser parser;
  bool ok;
  QVariant result = parser.parse(data, &ok);
  QVariantMap map;

  if (!ok)
    return ;

  map = result.toMap();
  map = map["site"].toMap();

  foreach (QVariant var, map["stands"].toList()) {
    QVariantMap sta = var.toMap();
    int id;
    Station *station;

    if (sta.count() == 0)
      continue;

    id = sta["id"].toInt();
    if (!stations[id])
      stations[id] = new Station(this);

    station = stations[id];
    station->setId(id);
    if (station->name().isEmpty())
      station->setName(sta["name"].toString());
    station->setPos(QPointF(sta["lat"].toReal(), sta["lng"].toReal()));
    station->setBikes(sta["ab"].toInt());
    station->setFreeSlots(sta["ap"].toInt());
    station->setTotalSlots(sta["tc"].toInt());
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
