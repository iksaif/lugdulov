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

#ifndef STATIONS_SIMPLE_PRIVATE_KOLN_H
#define STATIONS_SIMPLE_PRIVATE_KOLN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 22755, 0, "Zülpicherplatz", "", 50.930292, 6.939604 },
	{ 22756, 0, "Schokoladenmuseum", "", 50.932357, 6.963221 },
	{ 22758, 0, "Philharmonie / Treppe/ Hohenzollernbrücke", "", 50.941116, 6.961920 },
	{ 23256, 0, "Neumarkt / Apostelnstraße", "", 50.936495, 6.946203 },
	{ 26425, 0, "Dom Hbf Köln", "", 50.941901, 6.957618 },
	{ 29033, 0, "Friesenplatz*/Ecke Limburger Straße", "", 50.940569, 6.938467 },
	{ 31381, 0, "Deutz Bahnhof", "", 50.940177, 6.974140 },
	{ 31634, 0, "Heumarkt 43", "", 50.936012, 6.960611 },
	{ 32018, 0, "Tunisstr. / Wdr - Arkaden", "", 50.939041, 6.953048 },
	{ 32257, 0, "Chlodwigplatz / Merowingerstr.", "", 50.920885, 6.959335 },
	{ 33030, 0, "Heinzelmännchenbrunnen / Am Hof", "", 50.940069, 6.957790 },
	{ 33034, 0, "Ehrenstr. / St. Apern", "", 50.938527, 6.945280 },
	{ 35518, 0, "Holmes Place / Mediapark", "", 50.950289, 6.944389 },
	{ 42263, 0, "Mensa / Zülpicherstr.", "", 50.927600, 6.933403 },
	{ 42525, 0, "Rudolfplatz", "", 50.936526, 6.938982 },
	{ 43695, 0, "Uni/Albertus Magnus Platz", "", 50.928990, 6.927200 },
	{ 56392, 0, "Breitestr/ Ecke Auf Dem Behrlich", "", 50.938879, 6.948037 },
	{ 56401, 0, "Quartermarkt", "", 50.936310, 6.958240 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateKoln : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateKoln() {
    rect = QRectF(QPointF(49.942900, 5.956490), QPointF(51.942900, 7.956490));
    center = QPointF(50.942900, 6.956490);
    statusUrl = "";
    infosUrl = "http://nextbike.net/maps/nextbike-official.xml";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Koln %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_KOLN_H */

