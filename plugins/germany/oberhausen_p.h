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

#ifndef STATIONS_SIMPLE_PRIVATE_OBERHAUSEN_H
#define STATIONS_SIMPLE_PRIVATE_OBERHAUSEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50486, 0, "Hauptbahnhof Oberhausen", "", 51.473131, 6.851485 },
	{ 50487, 0, "Neue Mitte/Centro.", "", 51.489674, 6.874081 },
	{ 50488, 0, "Bf. Sterkrade", "", 51.512569, 6.844456 },
	{ 50489, 0, "Westausgang Hbf/Lvr-Industriemuseum", "", 51.474807, 6.849602 },
	{ 50490, 0, "Schloss Oberhausen", "", 51.492673, 6.861165 },
	{ 50491, 0, "Rathaus Oberhausen", "", 51.473366, 6.859852 },
	{ 50492, 0, "Innenstadt Sterkrade", "", 51.515392, 6.849378 },
	{ 50493, 0, "Innenstadt Alt-Oberhausen", "", 51.468647, 6.855042 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateOberhausen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateOberhausen() {
    rect = QRectF(QPointF(50.493600, 5.851690), QPointF(52.493600, 7.851690));
    center = QPointF(51.493600, 6.851690);
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
      station->setRegion(QString("Oberhausen %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_OBERHAUSEN_H */

