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

#ifndef STATIONS_SIMPLE_PRIVATE_TOYAMA_H
#define STATIONS_SIMPLE_PRIVATE_TOYAMA_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "", "奥田新町８番 8 Okudashin-Machi", 36.705842, 137.215829 },
	{ 2, 0, "富山駅北 Toyama Station North", "牛島町１７番 17 Ushijima-Cho", 36.703055, 137.214531 },
	{ 11, 0, "大手町 Ote-Machi", "大手町", 36.691732, 137.211425 },
	{ 3, 0, "富山駅南① Toyama Station South 1", "明輪町１番 1 Meirin-Cho", 36.700744, 137.212211 },
	{ 4, 0, "富山駅南② Toyama Station South 2", "新富町１丁目", 36.699916, 137.212889 },
	{ 5, 0, "", "", 36.697144, 137.216360 },
	{ 6, 0, "市役所 City Hall", "新", 36.696277, 137.213238 },
	{ 7, 0, "北新町１丁目 Kitashin-Machi 1", "北新町１丁目３番 1-3 Kitashin-Machi", 36.693935, 137.220853 },
	{ 8, 0, "", "", 36.694109, 137.216014 },
	{ 9, 0, "城址公", "", 36.693453, 137.212635 },
	{ 10, 0, "丸の内 Marunouchi", "丸の内３丁目１番 3-1 Marunouchi", 36.692294, 137.209547 },
	{ 12, 0, "", "", 36.691711, 137.215395 },
	{ 13, 0, "旅籠町 Hatago-Machi", "旅籠町", 36.689300, 137.208727 },
	{ 14, 0, "西町 Nishi-Cho", "西町３番 3 Nishi-Cho", 36.688971, 137.214437 },
	{ 15, 0, "堤町通り Tsutsumicho Street", "堤町通り１丁目", 36.688891, 137.217613 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateToyama : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateToyama() {
    rect = QRectF(QPointF(36.495952, 36.895952), QPointF(137.013677, 137.413677));
    center = QPointF(36.695952, 137.213677);
    statusUrl = "http://www.cyclocity.jp/service/stationdetails/%1";
    infosUrl = "http://www.cyclocity.jp/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Toyama %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;

    ret << "0";

    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_TOYAMA_H */

