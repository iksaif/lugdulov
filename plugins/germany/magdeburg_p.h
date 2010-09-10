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

#ifndef STATIONS_SIMPLE_PRIVATE_MAGDEBURG_H
#define STATIONS_SIMPLE_PRIVATE_MAGDEBURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 33, 0, "Campus Tower Universität Magdeburg (Universitätsplatz 1)", "", 52.139573, 11.640304 },
	{ 271, 0, "Hotel - Sleep And Go Md (Rogätzer Str. 5A)", "", 52.144103, 11.653254 },
	{ 1434, 0, "Ecke Wobau/ Kkh (Am Ulrichplatz)", "", 52.130235, 11.634371 },
	{ 1531, 0, "Jugendherberge Magdeburg (Leiterstraße 10)", "", 52.128285, 11.631829 },
	{ 1570, 0, "Ecke Ulrichhaus/ Frankonia Jagd (Breiter Weg 186)", "", 52.129974, 11.635439 },
	{ 3935, 0, "Eiscafe Palazzo (City-Carree)", "", 52.131005, 11.632118 },
	{ 7531, 0, "Mückenwirt Biergarten (An Der Elbe 14)", "", 52.107111, 11.643780 },
	{ 7532, 0, "Hauptbahnhof Magdeburg (Vorplatz)", "", 52.130373, 11.628428 },
	{ 7534, 0, "Opernhaus/ Theater (Breiter Weg 38)", "", 52.136596, 11.639371 },
	{ 7535, 0, "Ecke Ulrichshaus/ C&A (Ernst-Reuter-Allee)", "", 52.130867, 11.635873 },
	{ 7536, 0, "Tourist-Information Magdeburg (Ernst-Reuter-Allee 12)", "", 52.131028, 11.637413 },
	{ 7537, 0, "Hasselbachplatz (Liebig-Lounge)", "", 52.120430, 11.628031 },
	{ 11800, 0, "Am Ratswaagehotel (Ratswaageplatz 1-4)", "", 52.132981, 11.637783 },
	{ 12097, 0, "Am Hundertwasserhaus (Breiter Weg 128)", "", 52.127370, 11.634060 },
	{ 12105, 0, "Rotehornpark/ Café Le Frog", "", 52.118589, 11.641881 },
	{ 12205, 0, "Hotel - Inter City (Am Hbf)", "", 52.129500, 11.628009 },
	{ 12878, 0, "Domplatz (Breiter Weg)", "", 52.125367, 11.631818 },
	{ 15066, 0, "Cafe Alex - Spielbank Md (Ulrichsplatz 2)", "", 52.130669, 11.634629 },
	{ 20229, 0, "Mvb Videowand/ Mcdonalds (Ernst-Reuter-Allee)", "", 52.131163, 11.636946 },
	{ 40831, 0, "Hier Anmelden! Bei Couch-Potato (Ulrichplatz 4)", "", 52.130063, 11.634532 },
	{ 45908, 0, "Eingang Schauspielhaus - Freie Kammerspiele", "", 52.123747, 11.628417 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateMagdeburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateMagdeburg() {
    rect = QRectF(QPointF(51.126800, 10.634200), QPointF(53.126800, 12.634200));
    center = QPointF(52.126800, 11.634200);
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
      station->setRegion(QString("Magdeburg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_MAGDEBURG_H */

