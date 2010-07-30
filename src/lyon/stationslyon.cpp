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
#include <QtCore/QFile>
#include <QtCore/QtPlugin>
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include <qjson/parser.h>

#include "station.h"
#include "stationslyon.h"
#include "stationslyonbuiltin.h"

QString
StationsFactoryLyon::id() const
{
  return QLatin1String("lyon");
}

QString
StationsFactoryLyon::name() const
{
  return QLatin1String("Velo'v Stations - Author: Corentin Chary <corentin.chary@gmail.com>");
}

QIcon
StationsFactoryLyon::icon() const
{
  return QIcon(":/lyon/bike.png");
}

QList < Stations * >
StationsFactoryLyon::stations(QObject *parent)
{
  QList < Stations * > ret;

  ret << new StationsLyon(parent);
  return ret;
}

StationsLyon::StationsLyon(QObject *parent)
  : Stations(parent)
{
  nm = new QNetworkAccessManager(this);
  count = 0;
  step = 0;
}

StationsLyon::~StationsLyon()
{
  qDeleteAll(stations);
}

QString
StationsLyon::name() const
{
  return QLatin1String("Lyon");
}

QString
StationsLyon::bikeName() const
{
  return QLatin1String("Velo'V");
}

QIcon
StationsLyon::bikeIcon() const
{
  return QIcon(":/lyon/bike.png");
}

bool
StationsLyon::intersect(const QPointF & pos)
{
  if (pos.x() > 45.815042 && pos.x() < 45.61764 &&
      pos.y() > 4.799995  && pos.y() < 5.090103)
    return true;
  return false;
}

void
StationsLyon::fetchPos(const QPointF & pos, int num)
{
  request(stationsJsonUrl(pos, num), Request::PropertiesNear);
}

void
StationsLyon::fetchFromFile(const QString & file)
{
  StationsLyon::Request req = { Request::Properties, -1, QString() };
  QFile fp(file);

  fp.open(QIODevice::ReadOnly);
  handleProperties(fp.readAll(), req);
  fp.close();
}

void
StationsLyon::fetchAll()
{
  QList < Station * > list = builtinStationsLyon(this);

  foreach (Station *station, list)
    stations[station->id()] = station;
  emit stationsUpdated(list, false);
}

void
StationsLyon::fetchFromUrl(const QUrl & url)
{
  request(url, Request::Properties);
}

void
StationsLyon::fetchOnline()
{
  foreach (QString region, regions())
    fetch(region);
}

void
StationsLyon::update(Station *station)
{
  fetchStatus(station->id());
}

void
StationsLyon::update(QList < Station * > stations)
{
  foreach (Station *station, stations)
    update(station);
}

void
StationsLyon::error(QNetworkReply::NetworkError code)
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
StationsLyon::finished()
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());
  StationsLyon::Request req = replies[rep];

  if (rep)
    rep->deleteLater();

  if (!rep || req.type == Request::Null) {
    step++;
    replies.remove(rep);
    return ;
  }

  if (req.type == Request::Properties ||
      req.type == Request::PropertiesNear) {
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
StationsLyon::handleProperties(const QByteArray & data, Request req)
{
  QJson::Parser parser;
  bool ok;
  QList < Station * > list;
  QMap < Station * , bool > status;
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
      stations[id] = new Station(this);

    station = stations[id];
    station->setId(sta["numStation"].toInt());
    station->setName(sta["nomStation"].toString());
    station->setDescription(sta["infoStation"].toString());
    station->setPos(QPointF(sta["x"].toReal(), sta["y"].toReal()));
    station->setDistance(sta["distance"].toReal());
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
      status[station] = true;
    }

    list << station;
  }

  emit stationsUpdated(list, req.type == Request::PropertiesNear);

  foreach (Station *station, list) {
    if (status[station])
      emit statusUpdated(station);
  }
}

void
StationsLyon::handleStatus(const QByteArray & data, Request req)
{
  int id = req.id;
  Station *station;

  if (!stations[id]) {
    fetch(id);
    stations[id] = new Station(this);
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
StationsLyon::request(const QUrl & url, Request::Type type, int id, const QString & region)
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
StationsLyon::fetch(int id)
{
  request(StationsLyon::stationJsonUrl(id), Request::Properties, id);
}

void
StationsLyon::fetchStatus(int id)
{
  request(StationsLyon::stationStatusUrl(id), Request::Status, id);
}

void
StationsLyon::fetch(const QString & region)
{
  request(StationsLyon::stationsJsonUrl(region), Request::Properties, -1, region);
}


QUrl
StationsLyon::stationJsonUrl(int id)
{
  return QString("http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParId.php?gid=%1").arg(id);
}

QUrl
StationsLyon::stationsJsonUrl(const QString &region)
{
  return QString("http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParArrondissement.php?arrondissement=%1").arg(region);
}

QUrl
StationsLyon::stationStatusUrl(int id)
{
  return QString("http://www.velov.grandlyon.com/velovmap/zhp/inc/DispoStationsParId.php?id=%1").arg(id);
}

QUrl
StationsLyon::stationImageUrl(int id)
{
  return QString("http://www.velov.grandlyon.com/uploads/tx_gsstationsvelov/%1.jpg").arg(id);
}

QUrl
StationsLyon::stationsJsonUrl(const QPointF &pos, int num)
{
  return QString("http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParCoord.php?lat=%1&long=%2&nombreStation=%3").arg(pos.x()).arg(pos.y()).arg(num);
}

QStringList
StationsLyon::regions()
{
  QStringList reg;

  reg << "69381";
  reg << "69382";
  reg << "69383";
  reg << "69384";
  reg << "69385";
  reg << "69386";
  reg << "69387";
  reg << "69388";
  reg << "69389";
  reg << "69266";
  reg << "69034";
  reg << "69256";
  return reg;
}

Q_EXPORT_PLUGIN2(stationslyon, StationsFactoryLyon)
