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

#ifndef STATIONS_SIMPLE_PRIVATE_FURTH_H
#define STATIONS_SIMPLE_PRIVATE_FURTH_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 5575, 0, "Stadttheater", "", 49.4751014709, 10.9916000366 },
	{ 5576, 0, "Hauptbahnhof", "", 49.4710998535, 10.9906997681 },
	{ 5577, 0, "Rathaus", "", 49.4780006409, 10.9884996414 },
	{ 41637, 0, "Tourist-Info", "", 49.4710105391, 10.9899947047 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateFurth : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateFurth() {
    rect = QRectF(QPointF(48.477400, 9.990100), QPointF(50.477400, 11.990100));
    center = QPointF(49.477400, 10.990100);
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
      station->setRegion(QString("Furth %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_FURTH_H */

