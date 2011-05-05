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

#include <QtCore/QStringList>

#include <qjson/parser.h>

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

QUrl
StationsPluginVelIn::infosUrl(void)
{
  if (forgedUrl.isEmpty())
    forgeUrl();

  return forgedUrl;
}

void
StationsPluginVelIn::forgeUrl(void)
{
  if (!baseUrl.isEmpty())
    return ;

  QUrl server(d->infosUrl);

  baseUrl.setScheme("http");
  baseUrl.setHost(server.encodedHost());

#if 0
  request(baseUrl, StationsPluginVelIn::HomePage);
#else
  request(d->infosUrl, StationsPluginVelIn::MapPage);
#endif
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
    bool ok;

    if (sta.count() == 0)
      continue;

    id = sta["id"].toInt(&ok);

    if (!ok)
      continue ;

    station = getOrCreateStation(id);
    if (station->name().isEmpty())
      station->setName(QUrl::fromPercentEncoding(sta["name"].toByteArray()));
    if (station->pos().isNull())
      station->setPos(QPointF(sta["lat"].toReal(), sta["lng"].toReal()));
    station->setBikes(sta["ab"].toInt());
    station->setFreeSlots(sta["ap"].toInt());
    station->setTotalSlots(sta["tc"].toInt());

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}

void
StationsPluginVelIn::handleStatus(const QByteArray & data, int type)
{
  QStringList captured;

  if (type == StationsPluginVelIn::HomePage) {
    QRegExp re("window\\.location = '(.*)';");

    re.setMinimal(true);
    re.indexIn(data);
    captured = re.capturedTexts();

    if (captured.size() == 2) {
      QUrl url = baseUrl;

      url = QUrl(url.toString() + captured.at(1));

      request(url, StationsPluginVelIn::FormPage);
    }
  } else if (type == StationsPluginVelIn::FormPage) {
    QString webdbname, path;
    QRegExp rereq("href=\"(customFrmMap\\?OpenForm\\&ParentUNID=.*\\?open\\&lang=fr)\"");
    QRegExp redb("var webdbname = '(.*)';");

    rereq.setMinimal(true);
    redb.setMinimal(true);

    rereq.indexIn(data);
    redb.indexIn(data);

    captured = rereq.capturedTexts();
    if (captured.size() == 2)
      path = captured.at(1);

    captured = redb.capturedTexts();
    if (captured.size() == 2)
      webdbname = captured.at(1);

    if (!path.isEmpty() && !webdbname.isEmpty()) {
      QUrl url = baseUrl;

      url = QUrl(url.toString() + "/" + webdbname + "/" + path);
      request(url, StationsPluginVelIn::MapPage);
    }
  } else if (type == StationsPluginVelIn::MapPage) {
    QString key, db;
    QRegExp rekey("var mapdbkey ?= ?'(.*)';");
    QRegExp redb("var mapdb ?= ?'(.*)';");

    rekey.setMinimal(true);
    redb.setMinimal(true);
    rekey.indexIn(data);
    redb.indexIn(data);

    captured = rekey.capturedTexts();
    if (captured.size() == 2)
      key = captured.at(1);

    captured = redb.capturedTexts();
    if (captured.size() == 2)
      db = captured.at(1);

    if (!db.isEmpty() && !key.isEmpty()) {
      forgedUrl = QUrl(baseUrl.toString() + "/" + db + "/getSite?openagent&site=" + id() + "&format=json&key=" + key);
      request(forgedUrl);
    }
  }
}
