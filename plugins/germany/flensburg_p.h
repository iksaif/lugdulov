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

#ifndef STATIONS_SIMPLE_PRIVATE_FLENSBURG_H
#define STATIONS_SIMPLE_PRIVATE_FLENSBURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 48471, 0, "Fischereihafen Ostseite", "", 54.7908010789, 9.43787813187 },
	{ 45757, 0, "Zob / Touristinformation", "", 54.7867429542, 9.43727731705 },
	{ 45760, 0, "Willy-Brandt-Platz", "", 54.7895144005, 9.43375825882 },
	{ 45765, 0, "Twedter Plack", "", 54.8155091102, 9.47238743305 },
	{ 47493, 0, "Hauptbahnhof", "", 54.7749683762, 9.43737387657 },
	{ 48470, 0, "Nordertorplatz/Phänomenta", "", 54.7957123497, 9.43088293076 },
	{ 48465, 0, "Campus Unigelände", "", 54.7761874485, 9.45538759232 },
	{ 48468, 0, "Exe/Friesische Str. Bushaltestelle", "", 54.7779695794, 9.42433834076 },
	{ 48469, 0, "Dr.-Todsen-Str./ Ecke Angelburger Str.", "", 54.7825049959, 9.43685889244 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateFlensburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateFlensburg() {
    rect = QRectF(QPointF(53.780400, 8.435710), QPointF(55.780400, 10.435710));
    center = QPointF(54.780400, 9.435710);
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
      station->setRegion(QString("Flensburg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_FLENSBURG_H */

