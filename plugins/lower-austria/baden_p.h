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

#ifndef STATIONS_SIMPLE_PRIVATE_BADEN_H
#define STATIONS_SIMPLE_PRIVATE_BADEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 44621, 0, "Bad Vöslau / Bahnhof", "", 47.969220, 16.223210 },
	{ 44622, 0, "Bad Vöslau / Schlossplatz", "", 47.965560, 16.214410 },
	{ 44624, 0, "Guntramsdorf / Hst. Lokalbahn", "", 48.049150, 16.312210 },
	{ 44626, 0, "Gumpoldskirchen / Bahnhof", "", 48.040810, 16.284490 },
	{ 44629, 0, "Guntramsdorf / Hst. Neu Guntramsdorf", "", 48.064030, 16.313860 },
	{ 46197, 0, "Baden / Bahnhof", "", 48.004840, 16.242750 },
	{ 46209, 0, "Baden / Haltestelle Josefplatz", "", 48.006180, 16.233980 },
	{ 46216, 0, "Baden / Tourismusinfo Römertherme", "", 48.008040, 16.230940 },
	{ 46219, 0, "Baden / Strandbad", "", 48.006410, 16.219160 },
	{ 46248, 0, "Pfaffstätten / Bahnhof", "", 48.017700, 16.259230 },
	{ 63758, 0, "Bahnhof Mödling", "", 48.015619, 16.290441 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBaden : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBaden() {
    rect = QRectF(QPointF(47.063400, 15.313700), QPointF(49.063400, 17.313700));
    center = QPointF(48.063400, 16.313700);
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
      station->setRegion(QString("Baden %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_BADEN_H */

