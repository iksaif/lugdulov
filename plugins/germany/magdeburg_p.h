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
	{ 33, 0, "Campus Tower Universität Magdeburg (Universitätsplatz 1)", "", 52.1395727343, 11.640304327 },
	{ 271, 0, "Hotel - Sleep And Go Md (Rogätzer Str. 5A)", "", 52.1441027888, 11.6532540321 },
	{ 1434, 0, "Ecke Wobau/ Kkh (Am Ulrichplatz)", "", 52.1302346277, 11.6343712807 },
	{ 1531, 0, "Jugendherberge Magdeburg (Leiterstraße 10)", "", 52.1282851004, 11.6318285465 },
	{ 1570, 0, "Ecke Ulrichhaus/ Frankonia Jagd (Breiter Weg 186)", "", 52.1299744761, 11.6354387999 },
	{ 3935, 0, "Eiscafe Palazzo (City-Carree)", "", 52.1310051944, 11.6321182251 },
	{ 7531, 0, "Mückenwirt Biergarten (An Der Elbe 14)", "", 52.1071114302, 11.6437804699 },
	{ 7532, 0, "Hauptbahnhof Magdeburg (Vorplatz)", "", 52.1303729355, 11.6284275055 },
	{ 7534, 0, "Opernhaus/ Theater (Breiter Weg 38)", "", 52.136596343, 11.6393709183 },
	{ 7535, 0, "Ecke Ulrichshaus/ C&A (Ernst-Reuter-Allee)", "", 52.1308668885, 11.6358733177 },
	{ 7536, 0, "Tourist-Information Magdeburg (Ernst-Reuter-Allee 12)", "", 52.1310282453, 11.6374129057 },
	{ 7537, 0, "Hasselbachplatz (Liebig-Lounge)", "", 52.120430144, 11.6280305386 },
	{ 11800, 0, "Am Ratswaagehotel (Ratswaageplatz 1-4)", "", 52.1329809455, 11.6377830505 },
	{ 12097, 0, "Am Hundertwasserhaus (Breiter Weg 128)", "", 52.1273695835, 11.6340601444 },
	{ 12105, 0, "Rotehornpark/ Café Le Frog", "", 52.1185888868, 11.6418814659 },
	{ 12205, 0, "Hotel - Inter City (Am Hbf)", "", 52.1295002719, 11.6280090809 },
	{ 12878, 0, "Domplatz (Breiter Weg)", "", 52.1253672363, 11.6318178177 },
	{ 15066, 0, "Cafe Alex - Spielbank Md (Ulrichsplatz 2)", "", 52.130669308, 11.6346287727 },
	{ 20229, 0, "Mvb Videowand/ Mcdonalds (Ernst-Reuter-Allee)", "", 52.1311632577, 11.6369462013 },
	{ 40831, 0, "Hier Anmelden! Bei Couch-Potato (Ulrichplatz 4)", "", 52.1300633889, 11.6345322132 },
	{ 45908, 0, "Eingang Schauspielhaus - Freie Kammerspiele", "", 52.12374685, 11.6284167767 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateMagdeburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateMagdeburg() {
    rect = QRectF(QPointF(51.926800, 11.434200), QPointF(52.326800, 11.834200));
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

