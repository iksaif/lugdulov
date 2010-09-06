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

#ifndef STATIONS_SIMPLE_PRIVATE_OBB_BAHNHOFE_H
#define STATIONS_SIMPLE_PRIVATE_OBB_BAHNHOFE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 47461, 0, "Klosterneuburg-Kierling Bhf", "", 48.309896, 16.326249 },
//	{ 47455, 0, "Amstetten Bhf", "", 48.121753, 14.877403 },
	{ 47456, 0, "Fels Am Wagram Bhf", "", 48.42917, 15.82306 },
	{ 47457, 0, "Felixdorf Bhf", "", 47.887419, 16.247936 },
	{ 47458, 0, "Gänserndorf Bhf", "", 48.33972, 16.73167 },
	{ 47459, 0, "Hadersdorf Am Kamp Bhf", "", 48.44639, 15.71389 },
	{ 47460, 0, "Kirchberg Am Wagram Bhf", "", 48.42778, 15.89389 },
	{ 47462, 0, "Klosterneuburg-Weidling Bhf", "", 48.297663, 16.334378 },
	{ 47463, 0, "Korneuburg Bhf", "", 48.343274, 16.329096 },
	{ 47465, 0, "Leobendorf Bhf", "", 48.36472, 16.30167 },
	{ 47467, 0, "Neunkirchen Bhf", "", 47.731549, 16.085742 },
	{ 47469, 0, "Schwechat Bhf", "", 48.14278, 16.48194 },
//	{ 47471, 0, "St. Valentin Bhf", "", 48.17833, 14.52056 },
	{ 47472, 0, "Stockerau Bhf", "", 48.382786, 16.212659 },
	{ 47473, 0, "Ternitz Bhf", "", 47.71382, 16.033343 },
//	{ 47475, 0, "Ulmerfeld-Hausmening Bhf", "", 48.07491, 14.816011 },
	{ 47477, 0, "Wolkersdorf Bhf", "", 48.379356, 16.512603 },
//	{ 47478, 0, "Ybbs A. D. Donau Bhf", "", 48.1574833654, 15.0983476639 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateObb_Bahnhofe : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateObb_Bahnhofe() {
    rect = QRectF(QPointF(47.019300, 15.309200), QPointF(49.019300, 17.309200));
    center = QPointF(48.019300, 16.309200);
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
      station->setRegion(QString("Obb_Bahnhofe %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_OBB_BAHNHOFE_H */

