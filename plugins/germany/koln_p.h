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
	{ 22755, 0, "Zülpicherplatz", "", 50.9302917329, 6.93960428238 },
	{ 22756, 0, "Schokoladenmuseum", "", 50.9323574825, 6.96322113276 },
	{ 22758, 0, "Philharmonie / Treppe/ Hohenzollernbrücke", "", 50.9411164582, 6.96192026138 },
	{ 23256, 0, "Neumarkt / Apostelnstraße", "", 50.9364954674, 6.94620251656 },
	{ 26425, 0, "Dom Hbf Köln", "", 50.9419006627, 6.95761799812 },
	{ 29033, 0, "Friesenplatz*/Ecke Limburger Straße", "", 50.9405688593, 6.93846702576 },
	{ 31381, 0, "Deutz Bahnhof", "", 50.9401767475, 6.97414040565 },
	{ 31634, 0, "Heumarkt 43", "", 50.9360120454, 6.96061134338 },
	{ 32018, 0, "Tunisstr. / Wdr - Arkaden", "", 50.9390409566, 6.95304751396 },
	{ 32257, 0, "Chlodwigplatz / Merowingerstr.", "", 50.9208848197, 6.95933461189 },
	{ 33030, 0, "Heinzelmännchenbrunnen / Am Hof", "", 50.9400685781, 6.9577896595 },
	{ 33034, 0, "Ehrenstr. / St. Apern", "", 50.9385271374, 6.94527983665 },
	{ 35518, 0, "Holmes Place / Mediapark", "", 50.9502894712, 6.94438934326 },
	{ 42263, 0, "Mensa / Zülpicherstr.", "", 50.9276003733, 6.93340301514 },
	{ 42525, 0, "Rudolfplatz", "", 50.9365258924, 6.93898200989 },
	{ 43695, 0, "Uni/Albertus Magnus Platz", "", 50.92899, 6.9272 },
	{ 56392, 0, "Breitestr/ Ecke Auf Dem Behrlich", "", 50.9388786985, 6.94803714752 },
	{ 56401, 0, "Quartermarkt", "", 50.9363095365, 6.95824027061 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateKoln : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateKoln() {
    rect = QRectF(QPointF(50.742900, 6.756490), QPointF(51.142900, 7.156490));
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

