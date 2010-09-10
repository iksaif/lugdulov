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

#ifndef STATIONS_SIMPLE_PRIVATE_FRIEDRICHSHAFEN_H
#define STATIONS_SIMPLE_PRIVATE_FRIEDRICHSHAFEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 59, 0, "Medienhaus K42", "", 47.650414, 9.482446 },
	{ 579, 0, "Stadtbahnhof", "", 47.652886, 9.474721 },
	{ 1369, 0, "Franziskusplatz", "", 47.653948, 9.474839 },
	{ 4129, 0, "Graf Zeppelin Haus", "", 47.651542, 9.469099 },
	{ 19486, 0, "Messe Flughafen", "", 47.665532, 9.505706 },
	{ 19488, 0, "Messeeingang West", "", 47.677568, 9.506392 },
	{ 20353, 0, "Schiffsanlegestelle, Autofähre-Info", "", 47.650577, 9.483358 },
	{ 21145, 0, "Schanzstraße / Rathaus", "", 47.650559, 9.479367 },
	{ 21459, 0, "Antoniuseck", "", 47.650186, 9.478331 },
	{ 27664, 0, "Romanshorner Platz 2", "", 47.652001, 9.483005 },
	{ 31944, 0, "Flughafen", "", 47.673100, 9.522774 },
	{ 34346, 0, "Medienhaus K42", "", 47.769186, 9.144487 },
	{ 47559, 0, "Telekom-Dammstraße", "", 47.650085, 9.481303 },
	{ 54085, 0, "Camping Park Messe", "", 47.670633, 9.495599 },
	{ 54086, 0, "Hymer-City Messe", "", 47.676484, 9.513130 },
	{ 54930, 0, "Messe Eingang Ost", "", 47.679186, 9.511242 },
	{ 62756, 0, "Messe Park Ride Parkplatz", "", 47.667324, 9.511156 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateFriedrichshafen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateFriedrichshafen() {
    rect = QRectF(QPointF(46.651900, 8.478370), QPointF(48.651900, 10.478370));
    center = QPointF(47.651900, 9.478370);
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
      station->setRegion(QString("Friedrichshafen %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_FRIEDRICHSHAFEN_H */

