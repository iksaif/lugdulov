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

#ifndef STATIONS_SIMPLE_PRIVATE_HANNOVER_H
#define STATIONS_SIMPLE_PRIVATE_HANNOVER_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 22590, 0, "Markthalle / Köbelinger Markt", "", 52.370850, 9.736494 },
	{ 22543, 0, "Zoo", "", 52.381677, 9.766803 },
	{ 22582, 0, "Neues Rathaus", "", 52.367686, 9.737481 },
	{ 22585, 0, "Opernplatz", "", 52.373597, 9.739420 },
	{ 22587, 0, "Raschplatz / Kaufland", "", 52.379837, 9.740925 },
	{ 22588, 0, "Maschsee / Sprengelmuseum", "", 52.363412, 9.739015 },
	{ 22589, 0, "Platz Der Weltausstellung", "", 52.372520, 9.737841 },
	{ 22591, 0, "Aegidientorplatz", "", 52.368649, 9.743704 },
	{ 22593, 0, "Welfengarten / Uni", "", 52.381153, 9.718609 },
	{ 22595, 0, "Steintorplatz", "", 52.375874, 9.732599 },
	{ 22598, 0, "Hcc Congresszentrum / Stadthalle", "", 52.376438, 9.769056 },
	{ 22599, 0, "Emmichplatz / Musikhochschule", "", 52.377433, 9.752898 },
	{ 36913, 0, "Hotel Schlafgut, Kniestr. 33", "", 52.388697, 9.719596 },
	{ 39212, 0, "Kröpcke", "", 52.374610, 9.738125 },
	{ 41083, 0, "Hauptbahnhof / Ernst-August-Platz", "", 52.375979, 9.741202 },
	{ 41739, 0, "Königsworther Platz / Uni", "", 52.377800, 9.724231 },
	{ 41738, 0, "Klagesmarkt", "", 52.378730, 9.730486 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateHannover : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateHannover() {
    rect = QRectF(QPointF(51.372100, 8.735690), QPointF(53.372100, 10.735690));
    center = QPointF(52.372100, 9.735690);
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
      station->setRegion(QString("Hannover %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_HANNOVER_H */

