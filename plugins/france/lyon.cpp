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
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include <qjson/parser.h>

#include "station.h"
#include "lyon.h"

StationsPluginLyon::StationsPluginLyon(QObject *parent)
  : StationsPluginSimple(parent)
{
}

StationsPluginLyon::~StationsPluginLyon()
{
}

QStringList StationsPluginLyon::regions() {
  QStringList ret;

  ret << "69381";
  ret << "69382";
  ret << "69383";
  ret << "69384";
  ret << "69385";
  ret << "69386";
  ret << "69387";
  ret << "69388";
  ret << "69389";
  ret << "69266";
  ret << "69034";
  ret << "69256";

  return ret;
}

void
StationsPluginLyon::fetchOnline()
{
  //foreach (QString region, regions())
  //  fetchFromUrl(stationsJsonUrl(region));
}

void
StationsPluginLyon::handleInfos(const QByteArray & data)
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

    id = sta["numStation"].toInt(&ok);

    if (!ok)
      continue ;

    station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(sta["nomStation"].toString());
    if (station->description().isEmpty())
      station->setDescription(sta["infoStation"].toString());
    if (station->pos().isNull())
      station->setPos(QPointF(sta["x"].toReal(), sta["y"].toReal()));
  }

  emit stationsCreated(stations.values());
}

void
StationsPluginLyon::handleStatus(const QByteArray & data, int id)
{
  Station *station;
  QList < Station * > updated;
  QDomDocument doc;
  QDomNode node;

  if (!stations[id] || data.isEmpty())
    return ;

  station = stations[id];

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
