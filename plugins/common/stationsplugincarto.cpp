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

#include "station.h"
#include "stationsplugincarto.h"
#include "stationsplugincarto_p.h"

StationsPluginCarto::StationsPluginCarto(QObject *parent)
  : StationsPlugin(parent)
{
  nm = new QNetworkAccessManager(this);
  count = 0;
  step = 0;
  d = NULL;
}

StationsPluginCarto::~StationsPluginCarto()
{
  qDeleteAll(stations);
}

QRectF
StationsPluginCarto::rect() const
{
  return d->rect;
}


QPointF
StationsPluginCarto::center() const
{
  return d->center;
}

void
StationsPluginCarto::fetchPos(const QPointF &, int)
{
}

void
StationsPluginCarto::fetchFromFile(const QString &)
{
}

void
StationsPluginCarto::fetchAll()
{
  QList < Station * > list = d->fetchAll(this);

  if (stations.count())
    list = stations.values();
  else {
    foreach (Station *station, list)
      stations[station->id()] = station;
  }
  emit stationsCreated(list);
}

void
StationsPluginCarto::fetchFromUrl(const QUrl &)
{
  /* FIXME download carto XML file from official website */
}

void
StationsPluginCarto::fetchOnline()
{
  /* FIXME download carto XML file from official website */
}

void
StationsPluginCarto::update(Station *station)
{
  request(stationStatusUrl(station->id()), station->id());
}

void
StationsPluginCarto::update(const QList < Station * > & stations)
{
  foreach (Station *station, stations)
    update(station);
}

void
StationsPluginCarto::error(QNetworkReply::NetworkError code)
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
StationsPluginCarto::finished()
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());
  int id = replies[rep];

  if (rep)
    rep->deleteLater();

  if (!rep) {
    step++;
    replies.remove(rep);
    return ;
  }

  if (id)
    handleStatus(rep->readAll(), id);

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
StationsPluginCarto::handleStatus(const QByteArray & data, int id)
{
  Station *station;
  QList < Station * > updated;

  if (!stations[id])
    return ;

  station = stations[id];

  QDomDocument doc;
  QDomNode node;

  doc.setContent(data);
  node = doc.firstChildElement("station");

  station->setFreeSlots(node.firstChildElement("free").text().toInt());
  station->setTotalSlots(node.firstChildElement("total").text().toInt());
  station->setBikes(node.firstChildElement("available").text().toInt());
  station->setTicket(node.firstChildElement("ticket").text().toInt());

  updated << station;
  emit stationsUpdated(updated);
}

void
StationsPluginCarto::request(const QUrl & url, int id)
{
  QNetworkReply *rep;

  rep = nm->get(QNetworkRequest(url));
  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)),
	  this, SLOT(error(QNetworkReply::NetworkError)));
  connect(rep, SIGNAL(finished()), this, SLOT(finished()));

  if (count == 0) {
    emit started();
    step = 0;
  }
  replies[rep] = id;
  count++;
}

QUrl
StationsPluginCarto::stationStatusUrl(int id)
{
  return d->statusUrl.arg(id);
}

QUrl
StationsPluginCarto::stationCartoUrl()
{
  return d->cartoUrl;
}

QUrl
StationsPluginCarto::stationImageUrl(int id)
{
  return QUrl();
}

QStringList
StationsPluginCarto::regions()
{
  return d->regions();
}

QList < QAction * >
StationsPluginCarto::actions()
{
  QList < QAction * > ret;

  return ret;
}

void
StationsPluginCarto::actionTriggered(QAction *action, Station *station, QWidget *parent)
{
}

