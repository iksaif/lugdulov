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

#ifndef STATIONS_SIMPLE_PRIVATE_HAMBURG_H
#define STATIONS_SIMPLE_PRIVATE_HAMBURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1418, 0, "Europa Passage / Reesendamm / Jungfernstieg", "", 53.551998, 9.993970 },
	{ 1420, 0, "Neuer Jungfernstieg", "", 53.556499, 9.992530 },
	{ 1422, 0, "Bahnhof Dammtor/ Dag Hammarskjoeld Bruecke", "", 53.560692, 9.989297 },
	{ 1429, 0, "Mönckebergstr.", "", 53.551201, 10.001100 },
	{ 4291, 0, "A&O Hostel Amsinckstraße", "", 53.547703, 10.011131 },
	{ 4691, 0, "Glockengießerwall", "", 53.553699, 10.003600 },
	{ 4897, 0, "U- Bahn Hallerstraße", "", 53.572800, 9.988930 },
	{ 8246, 0, "Golden Tulip Finkenwerder", "", 53.540103, 9.862032 },
	{ 14294, 0, "St. Pauli Jugendherberge Stintfang", "", 53.546861, 9.971595 },
	{ 13713, 0, "Mittelweg Ecke Milchstraße", "", 53.570721, 9.994769 },
	{ 13715, 0, "Hafen City Marco Polo Terassen", "", 53.542284, 9.993246 },
	{ 13717, 0, "Jungfernstieg", "", 53.554790, 9.989748 },
	{ 18404, 0, "Eppendorf Marie-Jonas-Platz", "", 53.590537, 9.987023 },
	{ 18411, 0, "Haltestelle St. Michaelis Ludwig-Erhard-Straße", "", 53.549079, 9.978375 },
	{ 19314, 0, "Mittelweg Ecke Hallerstraße", "", 53.572887, 9.993610 },
	{ 19315, 0, "U-Bahn Station Hudtwalckerstraße/ Bebelallee", "", 53.594517, 9.995627 },
	{ 25147, 0, "Mühlenkamp/ Ecke Gertigstraße", "", 53.581347, 10.011892 },
	{ 27352, 0, "U-Bahn Station Mundsburg", "", 53.570173, 10.027363 },
	{ 28133, 0, "Dammtor /  Rothenbaumchausee", "", 53.561559, 9.990199 },
	{ 42495, 0, "Kennedybrücke", "", 53.557773, 9.997880 },
	{ 44524, 0, "Ballindamm Ecke Lombardsbrücke", "", 53.555504, 9.999940 },
	{ 48334, 0, "Preystraße / Mühlenkamp", "", 53.581856, 10.011420 },
	{ 55206, 0, "Alsterufer/ Ecke Alte Rabenstraße", "", 53.567446, 10.001067 },
	{ 55210, 0, "Alsterufer/Ecke Alsterterassen", "", 53.559201, 9.995799 },
	{ 55215, 0, "Alsterufer Gegenüber Cliff Restaurant", "", 53.573677, 10.002258 },
	{ 55217, 0, "Fernsicht/ Ecke Agnesstraße", "", 53.580506, 10.000391 },
	{ 55219, 0, "An Der Alster/ Schwanenwik Brücke", "", 53.563228, 10.015551 },
	{ 58577, 0, "Kampnagel Kulturfabrik Jarrestraße 20", "", 53.583793, 10.021141 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateHamburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateHamburg() {
    rect = QRectF(QPointF(52.550600, 8.990520), QPointF(54.550600, 10.990520));
    center = QPointF(53.550600, 9.990520);
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
      station->setRegion(QString("Hamburg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_HAMBURG_H */

