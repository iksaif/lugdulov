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
	{ 13650, 0, "Au Gemeindeamt", "", 47.3219876, 9.9804615 },
	{ 13661, 0, "Bezau Hauptschule, Platz 138", "", 47.3835399, 9.9020513 },
	{ 13648, 0, "Schoppernau Gemeindeamt", "", 47.312406, 10.015903 },
	{ 13649, 0, "Schoppernau Talstation Diedamskopf", "", 47.3163738302, 10.0091350079 },
	{ 13652, 0, "Rehmen Kirche", "", 47.3225851284, 9.99851346016 },
	{ 13654, 0, "Schnepfau Gemeindesaal", "", 47.3519952329, 9.94528770447 },
	{ 13658, 0, "Bizau Kirche", "", 47.3690666603, 9.92848098278 },
	{ 13659, 0, "Mellau Gemeindeamt", "", 47.3505144, 9.881764 },
	{ 13660, 0, "Bezau Bahnhof", "", 47.381236399, 9.89786624908 },
	{ 13662, 0, "Egg Cafe Ampuls", "", 47.4307729, 9.8972451 },
	{ 48856, 0, "Andelsbuch Gemeindeamt", "", 47.4122910076, 9.89490590332 },
	{ 48857, 0, "Andelsbuch Bergbahn", "", 47.4201897271, 9.90657806396 },
	{ 48858, 0, "Bersbuch Wälderbahn", "", 47.3960252071, 9.86640930176 },
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

