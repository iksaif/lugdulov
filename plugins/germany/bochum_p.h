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

#ifndef STATIONS_SIMPLE_PRIVATE_BOCHUM_H
#define STATIONS_SIMPLE_PRIVATE_BOCHUM_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50341, 0, "Bergbaumuseum", "", 51.4891356916, 7.21573603237 },
	{ 50342, 0, "Bf. Dahlhausen", "", 51.4267485718, 7.1421571657 },
	{ 50343, 0, "Eisenbahnmuseum", "", 51.4327900832, 7.12625941611 },
	{ 50344, 0, "Bo-Hauptbahnhof", "", 51.4795259235, 7.22187179585 },
	{ 50345, 0, "Rathaus / Gustav-Heinemann-Platz", "", 51.4830644689, 7.21524336001 },
	{ 50346, 0, "Rathaus / Willy-Brandt-Platz", "", 51.4818633045, 7.21492349382 },
	{ 50347, 0, "Schauspielhaus", "", 51.4728205674, 7.21666934921 },
	{ 50348, 0, "Bermuda 3Eck / Viktoriastr.", "", 51.4769357395, 7.21509476819 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBochum : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBochum() {
    rect = QRectF(QPointF(50.481300, 6.213300), QPointF(52.481300, 8.213300));
    center = QPointF(51.481300, 7.213300);
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
      station->setRegion(QString("Bochum %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_BOCHUM_H */

