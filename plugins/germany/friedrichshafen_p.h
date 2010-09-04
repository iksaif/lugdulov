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
	{ 59, 0, "Medienhaus K42", "", 47.6504141113, 9.48244571686 },
	{ 579, 0, "Stadtbahnhof", "", 47.6528858598, 9.4747209549 },
	{ 1369, 0, "Franziskusplatz", "", 47.6539482421, 9.47483897209 },
	{ 4129, 0, "Graf Zeppelin Haus", "", 47.6515415901, 9.4690990448 },
	{ 19486, 0, "Messe Flughafen", "", 47.6655318648, 9.50570583344 },
	{ 19488, 0, "Messeeingang West", "", 47.6775680155, 9.50639247894 },
	{ 20353, 0, "Schiffsanlegestelle, Autofähre-Info", "", 47.65057673, 9.48335766792 },
	{ 21145, 0, "Schanzstraße / Rathaus", "", 47.6505586613, 9.47936654091 },
	{ 21459, 0, "Antoniuseck", "", 47.6501864444, 9.47833120823 },
	{ 27664, 0, "Romanshorner Platz 2", "", 47.652001, 9.483005 },
	{ 31944, 0, "Flughafen", "", 47.6731, 9.5227736 },
	{ 34346, 0, "Medienhaus K42", "", 47.7691856916, 9.14448738098 },
	{ 47559, 0, "Telekom-Dammstraße", "", 47.6500852588, 9.48130309582 },
	{ 54085, 0, "Camping Park Messe", "", 47.6706327574, 9.49559926987 },
	{ 54086, 0, "Hymer-City Messe", "", 47.6764844422, 9.51313018799 },
	{ 54930, 0, "Messe Eingang Ost", "", 47.6791861098, 9.51124191284 },
	{ 62756, 0, "Messe Park Ride Parkplatz", "", 47.6673237366, 9.51115608215 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateFriedrichshafen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateFriedrichshafen() {
    rect = QRectF(QPointF(47.451900, 9.278370), QPointF(47.851900, 9.678370));
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

