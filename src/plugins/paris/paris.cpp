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
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include "station.h"
#include "paris.h"
#include "builtin.h"

QString
StationsPluginFactoryParis::id() const
{
  return QLatin1String("paris");
}

QString
StationsPluginFactoryParis::name() const
{
  return QLatin1String("Velib StationsPlugin - Author: Corentin Chary <corentin.chary@gmail.com>");
}

QIcon
StationsPluginFactoryParis::icon() const
{
  return QIcon(":/paris/bike.png");
}

QList < StationsPlugin * >
StationsPluginFactoryParis::stations(QObject *parent)
{
  QList < StationsPlugin * > ret;

  ret << new StationsPluginParis(parent);
  return ret;
}

StationsPluginParis::StationsPluginParis(QObject *parent)
  : StationsPlugin(parent)
{
  nm = new QNetworkAccessManager(this);
  count = 0;
  step = 0;
}

StationsPluginParis::~StationsPluginParis()
{
  qDeleteAll(stations);
}

QString
StationsPluginParis::id() const
{
  return QLatin1String("paris");
}

QString
StationsPluginParis::name() const
{
  return QLatin1String("Paris");
}

QString
StationsPluginParis::bikeName() const
{
  return QLatin1String("Velib");
}

QIcon
StationsPluginParis::bikeIcon() const
{
  return QIcon(":/paris/bike.png");
}

bool
StationsPluginParis::intersect(const QPointF & pos)
{
  if (pos.x() > 49.038318 && pos.x() < 48.580014 &&
      pos.y() > 2.095642  && pos.y() < 2.977467)
    return true;
  return false;
}

void
StationsPluginParis::fetchPos(const QPointF &, int)
{
}

void
StationsPluginParis::fetchFromFile(const QString &)
{
}

void
StationsPluginParis::fetchAll()
{
  QList < Station * > list = builtinStationsPluginParis(this);

  foreach (Station *station, list)
    stations[station->id()] = station;
  emit stationsCreated(list);
}

void
StationsPluginParis::fetchFromUrl(const QUrl &)
{
}

void
StationsPluginParis::fetchOnline()
{
  /* FIXME download carto XML file from official website */
}

void
StationsPluginParis::update(Station *station)
{
  request(stationStatusUrl(station->id()), station->id());
}

void
StationsPluginParis::update(QList < Station * > stations)
{
  foreach (Station *station, stations)
    update(station);
}

void
StationsPluginParis::error(QNetworkReply::NetworkError code)
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
StationsPluginParis::finished()
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
StationsPluginParis::handleStatus(const QByteArray & data, int id)
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
StationsPluginParis::request(const QUrl & url, int id)
{
  QNetworkReply *rep;

  rep = nm->get(QNetworkRequest(url));
  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
  connect(rep, SIGNAL(finished()), this, SLOT(finished()));

  if (count == 0) {
    emit started();
    step = 0;
  }
  replies[rep] = id;
  count++;
}

QUrl
StationsPluginParis::stationStatusUrl(int id)
{
  return QString("http://www.velib.paris.fr/service/stationdetails/%1").arg(id);
}

QUrl
StationsPluginParis::stationCartoUrl()
{
  return QString("http://www.velib.paris.fr/service/carto");
}

QUrl
StationsPluginParis::stationImageUrl(int id)
{
  return QUrl();
}

QStringList
StationsPluginParis::regions()
{
  QStringList reg;

  /* FIXME */
  return reg;
}

QList < QAction * >
StationsPluginParis::actions()
{
  QList < QAction * > ret;

  /* Fill me */
  return ret;
}

void
StationsPluginParis::actionTriggered(QAction *action, Station *station, QWidget *parent)
{
}

Q_EXPORT_PLUGIN2(stationsparis, StationsPluginFactoryParis)
