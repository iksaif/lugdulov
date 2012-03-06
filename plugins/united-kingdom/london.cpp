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
  QRegExp re_stations("station\\=\\{(.*)\\}\\;");
  QRegExp re_items("\\s*(\\w+)\\s*:(.*),");
  int ofs = 0;

  re_stations.setMinimal(true);
  re_items.setMinimal(true);

  while ((ofs = re_stations.indexIn(data, ofs)) >= 0) {
    bool ok;
    int id;
    QPointF pos;
    Station *station;
    QMap<QString, QString> values;

    ofs += re_stations.matchedLength();

    int station_ofs = 0;
    QString station_data = re_stations.capturedTexts().at(1);

    while ((station_ofs = re_items.indexIn(station_data, station_ofs)) >= 0) {
      QStringList capt = re_items.capturedTexts();

      if (capt.size() < 3)
	continue ;

      station_ofs += re_items.matchedLength();
      values[capt.at(1)] = capt.at(2);
      values[capt.at(1)].replace("\"", "");
    }

    id = values["id"].toInt(&ok);
    pos = QPointF(values["lat"].toDouble(),
		  values["long"].toDouble());

    if (!ok)
      continue ;

    station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(values["name"]);
    if (station->pos().isNull())
      station->setPos(pos);
    station->setBikes(values["nbBikes"].toInt());
    station->setFreeSlots(values["nbEmptyDocks"].toInt());
    station->setTotalSlots(station->bikes() + station->freeSlots());

    storeOrDropStation(station);
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
