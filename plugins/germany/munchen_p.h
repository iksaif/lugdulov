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

#ifndef STATIONS_SIMPLE_PRIVATE_MUNCHEN_H
#define STATIONS_SIMPLE_PRIVATE_MUNCHEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 44853, 0, "Geschwister-Scholl-Platz", "", 48.150655, 11.581231 },
	{ 46331, 0, "Bahnhofsplatz 2", "", 48.140619, 11.560804 },
	{ 50517, 0, "Pognerstraße 16", "", 48.103720, 11.545610 },
	{ 62762, 0, "Odeonsplatz Ecke Hofgartenstraße", "", 48.142566, 11.577820 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateMunchen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateMunchen() {
    rect = QRectF(QPointF(47.148300, 10.581400), QPointF(49.148300, 12.581400));
    center = QPointF(48.148300, 11.581400);
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
      station->setRegion(QString("Munchen %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_MUNCHEN_H */

