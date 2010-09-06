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
	{ 46618, 0, "Petronell-Carnuntum Bahnhof", "", 48.10604, 16.86747 },
	{ 46608, 0, "Bruck An Der Leitha Bahnhof", "", 48.01941, 16.77879 },
	{ 46609, 0, "Bruck An Der Leitha Hauptplatz", "", 48.02532, 16.77919 },
	{ 46610, 0, "Bruck An Der Leitha Parkbad", "", 48.02874, 16.79195 },
	{ 46611, 0, "Bruck An Der Leitha Bh", "", 48.02878, 16.7785 },
	{ 46612, 0, "Hainburg Frachtenbahnhof", "", 48.14479, 16.93267 },
	{ 46613, 0, "Hainburg Bahnhof Ungartor", "", 4814858.0, 16.94776 },
	{ 46614, 0, "Hainburg Hauptplatz", "", 48.14738, 16.94136 },
	{ 46615, 0, "Hainburg Kulturfabrik", "", 48.14723, 16.93752 },
	{ 46616, 0, "Bad Deutschaltenburg Bahnhof", "", 48.13279, 16.91042 },
	{ 46617, 0, "Bad Deutschaltenburg Museum Carnuntinum", "", 48.13983, 16.90313 },
	{ 46619, 0, "Petronell-Carnuntum Archäologischer Park Carnuntum", "", 48.11236, 16.85753 },
	{ 46620, 0, "Höflein Dorfplatz", "", 48.06731, 16.78763 },
	{ 46621, 0, "Rohrau Gemeindeamt", "", 48.06575, 16.85922 },
	{ 46622, 0, "Prellenkirchen Ortsmitte", "", 48.07449, 16.95162 },
	{ 46623, 0, "Göttlesbrunn Dorfplatz", "", 48.06007, 16.73811 },
	{ 46624, 0, "Berg / Gemeindeamt", "", 48.103555302, 17.0394033194 },
	{ 46625, 0, "Wolfsthal Bahnhof", "", 48.13587, 17.00647 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateRomerland : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateRomerland() {
    rect = QRectF(QPointF(47.905400, 16.666400), QPointF(48.305400, 17.066400));
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

