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

#ifndef STATIONS_SIMPLE_PRIVATE_BREGENZERWALD_H
#define STATIONS_SIMPLE_PRIVATE_BREGENZERWALD_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 13650, 0, "Au Gemeindeamt", "", 47.321988, 9.980462 },
	{ 13661, 0, "Bezau Hauptschule, Platz 138", "", 47.383540, 9.902051 },
	{ 13648, 0, "Schoppernau Gemeindeamt", "", 47.312406, 10.015903 },
	{ 13649, 0, "Schoppernau Talstation Diedamskopf", "", 47.316374, 10.009135 },
	{ 13652, 0, "Rehmen Kirche", "", 47.322585, 9.998513 },
	{ 13654, 0, "Schnepfau Gemeindesaal", "", 47.351995, 9.945288 },
	{ 13658, 0, "Bizau Kirche", "", 47.369067, 9.928481 },
	{ 13659, 0, "Mellau Gemeindeamt", "", 47.350514, 9.881764 },
	{ 13660, 0, "Bezau Bahnhof", "", 47.381236, 9.897866 },
	{ 13662, 0, "Egg Cafe Ampuls", "", 47.430773, 9.897245 },
	{ 48856, 0, "Andelsbuch Gemeindeamt", "", 47.412291, 9.894906 },
	{ 48857, 0, "Andelsbuch Bergbahn", "", 47.420190, 9.906578 },
	{ 48858, 0, "Bersbuch Wälderbahn", "", 47.396025, 9.866409 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBregenzerwald : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBregenzerwald() {
    rect = QRectF(QPointF(46.375100, 8.933010), QPointF(48.375100, 10.933010));
    center = QPointF(47.375100, 9.933010);
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
      station->setRegion(QString("Bregenzerwald %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_BREGENZERWALD_H */

