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

#ifndef STATIONS_SIMPLE_PRIVATE_DRESDEN_H
#define STATIONS_SIMPLE_PRIVATE_DRESDEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 40, 0, "Frauenkirche", "", 51.052361, 13.741933 },
	{ 73, 0, "Bahnhof Neustadt / Schlesischer Platz", "", 51.065025, 13.741279 },
	{ 120, 0, "Hauptbahnhof / Wiener Platz", "", 51.040490, 13.733693 },
	{ 2985, 0, "Albertplatz", "", 51.063731, 13.747587 },
	{ 6768, 0, "Fetscherplatz", "", 51.046452, 13.771404 },
	{ 10924, 0, "Postplatz", "", 51.051822, 13.732315 },
	{ 12936, 0, "Großer Garten / Lennéstraße", "", 51.042672, 13.751208 },
	{ 12937, 0, "Schillerplatz", "", 51.052294, 13.807411 },
	{ 12938, 0, "Körnerplatz / Friedrich-Wieck-Straße", "", 51.053899, 13.814975 },
	{ 13640, 0, "Jorge-Gomondai-Platz / Hauptstraße", "", 51.062075, 13.745388 },
	{ 14224, 0, "Dr.-Külz-Ring / Waisenhausstr. / Buchhandel Thalia", "", 51.046993, 13.736579 },
	{ 14262, 0, "Altmarkt / Seestrasse", "", 51.049495, 13.736976 },
	{ 14266, 0, "Theaterplatz / Italienisches Dörfchen / Semperoper", "", 51.054229, 13.737491 },
	{ 15334, 0, "Ibis Hotel Bastei / Prager Straße", "", 51.043148, 13.734874 },
	{ 15463, 0, "Kreuzkirche", "", 51.048734, 13.739049 },
	{ 19088, 0, "Schloßplatz / Brühlsche Terrasse / Hofkirche", "", 51.053407, 13.738768 },
	{ 19892, 0, "Mc Donalds / Prager Strasse / Hotel Pullmann", "", 51.042812, 13.735236 },
	{ 40610, 0, "Rathausplatz / Kreuzstraße", "", 51.048070, 13.741769 },
	{ 40611, 0, "Ostra-Ufer / Kongresszentrum", "", 51.057096, 13.731430 },
	{ 41380, 0, "Ibis Hotel Königstein / Prager Straße", "", 51.044015, 13.735034 },
	{ 41734, 0, "Ibis Hotel Lilienstein / Prager Straße", "", 51.044817, 13.735482 },
	{ 42849, 0, "Maxstraße / Ostra-Allee", "", 51.056742, 13.728243 },
	{ 48358, 0, "O2 Kesselsdorfer Str.30", "", 51.043418, 13.698320 },
	{ 43806, 0, "Kleinzschachwitz/ Fähre", "", 51.009030, 13.860927 },
	{ 44199, 0, "Hotel Westin Bellevue / Große Meißner Straße 15", "", 51.058796, 13.739183 },
	{ 44668, 0, "Wilsdruffer Str / Mcdonalds", "", 51.049718, 13.740463 },
	{ 45444, 0, "Hygienemuseum", "", 51.043576, 13.747130 },
	{ 48354, 0, "O2 Prager Str.2", "", 51.041853, 13.734691 },
	{ 48355, 0, "O2 Prager Str.11", "", 51.044861, 13.735914 },
	{ 48359, 0, "O2 Leipziger Str-115", "", 51.077511, 13.716087 },
	{ 50533, 0, "Finanzministerium", "", 51.057075, 13.745903 },
	{ 51670, 0, "Campingplatz Wostra", "", 50.999767, 13.867922 },
	{ 63903, 0, "Gruppenbuchung", "", 51.060359, 13.851914 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateDresden : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateDresden() {
    rect = QRectF(QPointF(50.052500, 12.744400), QPointF(52.052500, 14.744400));
    center = QPointF(51.052500, 13.744400);
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
      station->setRegion(QString("Dresden %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_DRESDEN_H */

