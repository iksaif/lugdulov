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

#ifndef STATIONS_SIMPLE_PRIVATE_ROMERLAND_H
#define STATIONS_SIMPLE_PRIVATE_ROMERLAND_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 46618, 0, "Petronell-Carnuntum Bahnhof", "", 48.106040, 16.867470 },
	{ 46608, 0, "Bruck An Der Leitha Bahnhof", "", 48.019410, 16.778790 },
	{ 46609, 0, "Bruck An Der Leitha Hauptplatz", "", 48.025320, 16.779190 },
	{ 46610, 0, "Bruck An Der Leitha Parkbad", "", 48.028740, 16.791950 },
	{ 46611, 0, "Bruck An Der Leitha Bh", "", 48.028780, 16.778500 },
	{ 46612, 0, "Hainburg Frachtenbahnhof", "", 48.144790, 16.932670 },
	{ 46613, 0, "Hainburg Bahnhof Ungartor", "", 48.14858, 16.94776 },
	{ 46614, 0, "Hainburg Hauptplatz", "", 48.147380, 16.941360 },
	{ 46615, 0, "Hainburg Kulturfabrik", "", 48.147230, 16.937520 },
	{ 46616, 0, "Bad Deutschaltenburg Bahnhof", "", 48.132790, 16.910420 },
	{ 46617, 0, "Bad Deutschaltenburg Museum Carnuntinum", "", 48.139830, 16.903130 },
	{ 46619, 0, "Petronell-Carnuntum Archäologischer Park Carnuntum", "", 48.112360, 16.857530 },
	{ 46620, 0, "Höflein Dorfplatz", "", 48.067310, 16.787630 },
	{ 46621, 0, "Rohrau Gemeindeamt", "", 48.065750, 16.859220 },
	{ 46622, 0, "Prellenkirchen Ortsmitte", "", 48.074490, 16.951620 },
	{ 46623, 0, "Göttlesbrunn Dorfplatz", "", 48.060070, 16.738110 },
	{ 46624, 0, "Berg / Gemeindeamt", "", 48.103555, 17.039403 },
	{ 46625, 0, "Wolfsthal Bahnhof", "", 48.135870, 17.006470 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateRomerland : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateRomerland() {
    rect = QRectF(QPointF(47.105400, 15.866400), QPointF(49.105400, 17.866400));
    center = QPointF(48.105400, 16.866400);
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
      station->setRegion(QString("Romerland %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_ROMERLAND_H */

