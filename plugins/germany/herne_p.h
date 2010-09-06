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

#ifndef STATIONS_SIMPLE_PRIVATE_HERNE_H
#define STATIONS_SIMPLE_PRIVATE_HERNE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50467, 0, "Künstlerzeche U.Fr.", "", 51.5463018494, 7.13703390866 },
	{ 50468, 0, "Hbf. Wanne-Eickel", "", 51.5325680781, 7.16534217955 },
	{ 50469, 0, "Bf. Herne", "", 51.5443108183, 7.21804297531 },
	{ 50470, 0, "Archäologie-Museum", "", 51.5364055191, 7.22622024153 },
	{ 50471, 0, "Akademie Mont-Cenis", "", 51.5392889769, 7.25695647982 },
	{ 50472, 0, "Schloß Strünkede", "", 51.5517514993, 7.21388759717 },
	{ 50473, 0, "Mondpalast", "", 51.5323311892, 7.15384995402 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateHerne : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateHerne() {
    rect = QRectF(QPointF(50.523300, 6.146610), QPointF(52.523300, 8.146610));
    center = QPointF(51.523300, 7.146610);
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
      station->setRegion(QString("Herne %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_HERNE_H */

