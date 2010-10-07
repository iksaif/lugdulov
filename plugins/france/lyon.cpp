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

#include <QtGui/QDesktopServices>
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QtCore/QFile>
#include <QtCore/QtPlugin>
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include <qjson/parser.h>

#include "station.h"
#include "lyon.h"
#include "lyon_p.h"

StationsPluginLyon::StationsPluginLyon(QObject *parent)
  : StationsPluginSimple(parent)
{
  d = new StationsPluginSimplePrivateLyon();
}

StationsPluginLyon::~StationsPluginLyon()
{
  delete d;
}

QString
StationsPluginLyon::id() const
{
  return QLatin1String("lyon");
}

QString
StationsPluginLyon::name() const
{
  return QLatin1String("Lyon");
}

QString
StationsPluginLyon::bikeName() const
{
  return QLatin1String("Velo'V");
}

QIcon
StationsPluginLyon::bikeIcon() const
{
  return QIcon(":/france/velov.png");
}

void
StationsPluginLyon::fetchOnline()
{
  foreach (QString region, regions())
    fetchFromUrl(stationsJsonUrl(region.replace("Lyon ", "")));
}

void
StationsPluginLyon::handleInfos(const QByteArray & data)
{
  QJson::Parser parser;
  bool ok;
  QList < Station * > created;
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
    if (!stations[id]) {
      stations[id] = new Station(this);
      created << stations[id];
    }

    station = stations[id];
    station->setId(sta["numStation"].toInt());
    station->setName(sta["nomStation"].toString());
    station->setDescription(sta["infoStation"].toString());
    station->setPos(QPointF(sta["x"].toReal(), sta["y"].toReal()));
  }

  if (created.size())
    emit stationsCreated(created);
}

void
StationsPluginLyon::handleStatus(const QByteArray & data, int id)
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

const QString StationsPluginLyon::baseUrl = QLatin1String("http://www.velov.grandlyon.com/velovmap/zhp/inc/");

QUrl
StationsPluginLyon::stationsJsonUrl(const QString &region)
{
  return baseUrl + QString("StationsParArrondissement.php?arrondissement=%1").arg(region);
}

QUrl
StationsPluginLyon::statusUrl(int id)
{
  return baseUrl + QString("DispoStationsParId.php?id=%1").arg(id);
}

QUrl
StationsPluginLyon::imageUrl(int id)
{
  return QString("http://www.velov.grandlyon.com/uploads/tx_gsstationsvelov/%1.jpg").arg(id);
}

QList < QAction * >
StationsPluginLyon::actions()
{
  QList < QAction * > ret;
  QAction *action;

  action = new QAction(QIcon(":/france/velov-icon.png"), tr("Velo'V map"), this);
  action->setToolTip(tr("Show this station in the official Velo'V map"));
  action->setData(ActionVelovMap);
  ret << action;
  return ret;
}

void
StationsPluginLyon::actionTriggered(QAction *action, Station *station, QWidget *parent)
{
  int data = action->data().toInt();

  if (data == ActionVelovMap) {
    QString str("http://www.velov.grandlyon.com/Plan-interactif.61.0.html?&gid=%1");

    str = str.arg(station->id());
    QDesktopServices::openUrl(str);
  }
}
