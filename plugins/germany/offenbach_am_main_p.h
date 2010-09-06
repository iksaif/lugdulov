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

#ifndef STATIONS_SIMPLE_PRIVATE_OFFENBACH_AM_MAIN_H
#define STATIONS_SIMPLE_PRIVATE_OFFENBACH_AM_MAIN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 119, 0, "S-Bahn Kaiserlei / Berliner Str.", "", 50.105304168, 8.74001026154 },
	{ 123, 0, "Frankfurter Str. / Kaiserstr.", "", 50.1049050541, 8.75844240189 },
	{ 137, 0, "Hauptbahnhof / Kaiserstr.", "", 50.0995235726, 8.76065254211 },
	{ 241, 0, "S-Bahn Ost / Untere Grenzstr.", "", 50.1026341702, 8.78434181213 },
	{ 8372, 0, "S- Bahn Marktplatz / Rathaus", "", 50.1060955047, 8.76174151897 },
	{ 42784, 0, "S-Bahn Marktplatz / Berliner Str.", "", 50.1057445657, 8.76329183578 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateOffenbach_Am_Main : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateOffenbach_Am_Main() {
    rect = QRectF(QPointF(49.109300, 7.738250), QPointF(51.109300, 9.738250));
    center = QPointF(50.109300, 8.738250);
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
      station->setRegion(QString("Offenbach_Am_Main %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_OFFENBACH_AM_MAIN_H */

