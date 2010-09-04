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
	{ 40, 0, "Frauenkirche", "", 51.0523613514, 13.7419331074 },
	{ 73, 0, "Bahnhof Neustadt / Schlesischer Platz", "", 51.065025326, 13.7412786484 },
	{ 120, 0, "Hauptbahnhof / Wiener Platz", "", 51.0404899454, 13.7336933613 },
	{ 2985, 0, "Albertplatz", "", 51.0637307655, 13.747587204 },
	{ 6768, 0, "Fetscherplatz", "", 51.0464515686, 13.7714042664 },
	{ 10924, 0, "Postplatz", "", 51.051821808, 13.7323147058 },
	{ 12936, 0, "Großer Garten / Lennéstraße", "", 51.042672219, 13.7512081861 },
	{ 12937, 0, "Schillerplatz", "", 51.0522939088, 13.8074111938 },
	{ 12938, 0, "Körnerplatz / Friedrich-Wieck-Straße", "", 51.0538990155, 13.8149750233 },
	{ 13640, 0, "Jorge-Gomondai-Platz / Hauptstraße", "", 51.0620754284, 13.7453877926 },
	{ 14224, 0, "Dr.-Külz-Ring / Waisenhausstr. / Buchhandel Thalia", "", 51.0469926151, 13.7365794182 },
	{ 14262, 0, "Altmarkt / Seestrasse", "", 51.0494949553, 13.7369763851 },
	{ 14266, 0, "Theaterplatz / Italienisches Dörfchen / Semperoper", "", 51.0542294717, 13.7374913692 },
	{ 15334, 0, "Ibis Hotel Bastei / Prager Straße", "", 51.0431477859, 13.7348735332 },
	{ 15463, 0, "Kreuzkirche", "", 51.0487341, 13.7390492 },
	{ 19088, 0, "Schloßplatz / Brühlsche Terrasse / Hofkirche", "", 51.0534066988, 13.7387681007 },
	{ 19892, 0, "Mc Donalds / Prager Strasse / Hotel Pullmann", "", 51.0428121913, 13.7352356315 },
	{ 40610, 0, "Rathausplatz / Kreuzstraße", "", 51.0480701218, 13.7417694926 },
	{ 40611, 0, "Ostra-Ufer / Kongresszentrum", "", 51.0570955748, 13.7314295769 },
	{ 41380, 0, "Ibis Hotel Königstein / Prager Straße", "", 51.0440145866, 13.7350344658 },
	{ 41734, 0, "Ibis Hotel Lilienstein / Prager Straße", "", 51.0448172904, 13.7354823947 },
	{ 42849, 0, "Maxstraße / Ostra-Allee", "", 51.0567415364, 13.7282431126 },
	{ 48358, 0, "O2 Kesselsdorfer Str.30", "", 51.0434176089, 13.6983203888 },
	{ 43806, 0, "Kleinzschachwitz/ Fähre", "", 51.009029505, 13.8609266281 },
	{ 44199, 0, "Hotel Westin Bellevue / Große Meißner Straße 15", "", 51.0587958, 13.7391827 },
	{ 44668, 0, "Wilsdruffer Str / Mcdonalds", "", 51.0497175289, 13.7404632568 },
	{ 45444, 0, "Hygienemuseum", "", 51.043576, 13.74713 },
	{ 48354, 0, "O2 Prager Str.2", "", 51.0418526136, 13.734691143 },
	{ 48355, 0, "O2 Prager Str.11", "", 51.0448611352, 13.7359142303 },
	{ 48359, 0, "O2 Leipziger Str-115", "", 51.0775105819, 13.7160873413 },
	{ 50533, 0, "Finanzministerium", "", 51.0570753441, 13.7459027767 },
	{ 51670, 0, "Campingplatz Wostra", "", 50.9997668103, 13.8679218292 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateDresden : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateDresden() {
    rect = QRectF(QPointF(50.852500, 13.544400), QPointF(51.252500, 13.944400));
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

