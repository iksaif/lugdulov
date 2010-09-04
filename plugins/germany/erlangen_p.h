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

#ifndef STATIONS_SIMPLE_PRIVATE_ERLANGEN_H
#define STATIONS_SIMPLE_PRIVATE_ERLANGEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 509, 0, "Cinestar", "", 49.5907952151, 11.0049962997 },
	{ 26806, 0, "Arcaden", "", 49.5938761317, 11.0051035881 },
	{ 26807, 0, "Hauptbahnhof", "", 49.596073687, 11.0024535656 },
	{ 42198, 0, "Tourist-Info", "", 49.590739576, 11.0068631172 },
	{ 43720, 0, "Martin-Luther-Platz", "", 49.6018383217, 11.003279686 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateErlangen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateErlangen() {
    rect = QRectF(QPointF(49.396000, 10.802200), QPointF(49.796000, 11.202200));
    center = QPointF(49.596000, 11.002200);
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
      station->setRegion(QString("Erlangen %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_ERLANGEN_H */

