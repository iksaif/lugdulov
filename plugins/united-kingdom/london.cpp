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

#include <QtXml/QDomNode>

#include "station.h"
#include "london.h"

StationsPluginLondon::StationsPluginLondon(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginLondon::~StationsPluginLondon()
{
}

void
StationsPluginLondon::handleInfos(const QByteArray & data)
{
  QRegExp re("id:\"(\\d+)\",name:\"(.*)\",lat:\"(.*)\",long:\"(.*)\",nbBikes:\"(\\d+)\",nbEmptyDocks:\"(\\d+)\"");
  int ofs = 0;

  re.setMinimal(true);

  while ((ofs = re.indexIn(data, ofs)) >= 0) {
    bool ok;
    int id;
    QPointF pos;
    Station *station;
    QStringList capt = re.capturedTexts();

    ofs++;

    if (capt.size() != 7)
      continue ;

    id = capt.at(1).toInt(&ok);
    pos = QPointF(capt.at(3).toDouble(),
		  capt.at(4).toDouble());

    if (!ok)
      continue ;

    station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(capt.at(2));
    if (station->pos().isNull())
      station->setPos(pos);
    station->setBikes(capt.at(5).toInt());
    station->setFreeSlots(capt.at(6).toInt());
    station->setTotalSlots(station->bikes() + station->freeSlots());

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
