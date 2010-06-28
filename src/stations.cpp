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
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QtXml/QDomNode>
#include <QtCore/QFile>

#include <QDebug>

#include <qjson/parser.h>

#include "station.h"
#include "stations.h"
#include "stationsbuiltin.h"

Stations::Stations(QObject *parent)
  : QObject(parent)
{
  nm = new QNetworkAccessManager(this);
  count = 0;
  step = 0;
}

Stations::~Stations()
{
  qDeleteAll(stations);
}

void
Stations::fetchFromFile(const QString & file)
{
  Stations::Request req = { Request::Properties, -1, QString() };
  QFile fp(file);

  fp.open(QIODevice::ReadOnly);
  handleProperties(fp.readAll(), req);
  fp.close();
}

void
Stations::fetchBuiltIn()
{
  QList < Station * > list = builtinStations();

  foreach (Station *station, list)
    stations[station->id()] = station;
  emit stationsUpdated(list);
}

void
Stations::fetchFromUrl(const QUrl & url)
{
  request(url, Request::Properties);
}

void
Stations::fetchAll()
{
  foreach (QString region, Station::regions())
    fetch(region);
}

void
Stations::update(Station *station)
{
  fetchStatus(station->id());
}

void
Stations::error(QNetworkReply::NetworkError code)
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());

  Q_UNUSED(code);

  if (rep) {
    emit error(tr("Network Error"), rep->errorString());
    step++;
    replies.remove(rep);
    rep->deleteLater();
  }
}

void
Stations::finished()
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());
  Stations::Request req = replies[rep];

  rep->deleteLater();

  if (!rep || req.type == Request::Null) {
    step++;
    replies.remove(rep);
    return ;
  }

  if (req.type == Request::Properties) {
    handleProperties(rep->readAll(), req);
  }
  if (req.type == Request::Status) {
    handleStatus(rep->readAll(), req);
  }

  step++;
  emit progress(step, count);

  replies.remove(rep);

  if (step == count) {
    step = 0;
    count = 0;
    emit done();
  }
}

void
Stations::handleProperties(const QByteArray & data, Request req)
{
  QJson::Parser parser;
  bool ok;

  QVariant result = parser.parse(data, &ok);

  if (!ok)
    return ;

  QVariantMap map = result.toMap();

  if (map.find(QLatin1String("markers")) == map.end())
    return;

  foreach (QVariant var, map["markers"].toList()) {
    QVariantMap sta = var.toMap();
    int id;
    Station *station;

    if (sta.count() == 0)
      continue;

    id = sta["numStation"].toInt();
    if (!stations[id])
      stations[id] = new Station();
    station = stations[id];
    station->setId(sta["numStation"].toInt());
    station->setName(sta["nomStation"].toString());
    station->setDescription(sta["infoStation"].toString());
    station->setPos(QPointF(sta["x"].toReal(), sta["y"].toReal()));
    if (req.region.isEmpty())
      station->setRegion(sta["codePostal"].toString()); /* Ext */
    else
      station->setRegion(req.region);

    /* Extended properties */
    sta = sta["status"].toMap();
    if (sta.count() != 0) {
      station->setFreeSlots(sta["free"].toInt());
      station->setTotalSlots(sta["total"].toInt());
      station->setBikes(sta["available"].toInt());
      station->setTicket(sta["ticket"].toInt());
    }

    emit stationUpdated(station);

    if (sta.count() != 0)
      emit statusUpdated(station);
  }
}

void
Stations::handleStatus(const QByteArray & data, Request req)
{
  int id = req.id;
  Station *station;

  if (!stations[id]) {
    fetch(id);
    stations[id] = new Station();
  }
  station = stations[id];

  QDomDocument doc;
  QDomNode node;

  doc.setContent(data);
  node = doc.firstChildElement("station");

  station->setFreeSlots(node.firstChildElement("free").text().toInt());
  station->setTotalSlots(node.firstChildElement("total").text().toInt());
  station->setBikes(node.firstChildElement("available").text().toInt());
  station->setTicket(node.firstChildElement("ticket").text().toInt());

  emit statusUpdated(station);
}

void
Stations::request(const QUrl & url, Request::Type type, int id, const QString & region)
{
  QNetworkReply *rep;
  Request req = {type, id, region};

  rep = nm->get(QNetworkRequest(url));
  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
  connect(rep, SIGNAL(finished()), this, SLOT(finished()));

  if (count == 0) {
    emit started();
    step = 0;
  }
  replies[rep] = req;
  count++;
}

void
Stations::fetch(int id)
{
  request(Station::stationJsonUrl(id), Request::Properties, id);
}

void
Stations::fetchStatus(int id)
{
  request(Station::stationStatusUrl(id), Request::Status, id);
}

void
Stations::fetch(const QString & region)
{
  request(Station::stationsJsonUrl(region), Request::Properties, -1, region);
}


