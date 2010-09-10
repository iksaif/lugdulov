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

#ifndef STATIONS_SIMPLE_PRIVATE_NURNBERG_H
#define STATIONS_SIMPLE_PRIVATE_NURNBERG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 55, 0, "Cinecitta", "", 49.452000, 11.083100 },
	{ 71, 0, "Aufseßplatz", "", 49.441101, 11.080100 },
	{ 121, 0, "Rathenauplatz", "", 49.457001, 11.089000 },
	{ 1455, 0, "Doku-Zentrum", "", 49.433899, 11.111400 },
	{ 2918, 0, "Hauptbahnhof", "", 49.447865, 11.081439 },
	{ 11670, 0, "Wöhrder Wiese", "", 49.451332, 11.090548 },
	{ 26619, 0, "Dianaplatz", "", 49.428659, 11.064970 },
	{ 40527, 0, "Wöhrdersee Hotel Mercure, Dürrenhofstr. 8", "", 49.449295, 11.097189 },
	{ 40568, 0, "Congress Hotel Mercure Nürnberg, Münchener Str. 283", "", 49.424021, 11.106711 },
	{ 42212, 0, "Lange Gasse 10", "", 49.458641, 11.083360 },
	{ 42213, 0, "Findelgasse 9", "", 49.452155, 11.079454 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateNurnberg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateNurnberg() {
    rect = QRectF(QPointF(48.447900, 10.081400), QPointF(50.447900, 12.081400));
    center = QPointF(49.447900, 11.081400);
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
      station->setRegion(QString("Nurnberg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_NURNBERG_H */

