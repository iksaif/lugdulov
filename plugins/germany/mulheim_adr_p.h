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

#ifndef STATIONS_SIMPLE_PRIVATE_MULHEIM_ADR_H
#define STATIONS_SIMPLE_PRIVATE_MULHEIM_ADR_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50474, 0, "Wasserbahnhof", "", 51.422467, 6.875907 },
	{ 50475, 0, "Mülheim Hbf Westausgang", "", 51.429872, 6.886254 },
	{ 50476, 0, "Kaiserplatz", "", 51.428188, 6.884338 },
	{ 50477, 0, "Leineweberstraße", "", 51.427025, 6.880045 },
	{ 50478, 0, "Wertgasse", "", 51.425003, 6.881156 },
	{ 50479, 0, "Wiesenstraße", "", 51.439295, 6.878685 },
	{ 50480, 0, "Hauskampstr.", "", 51.448726, 6.851721 },
	{ 50481, 0, "Schloss Broich", "", 51.427941, 6.869221 },
	{ 50482, 0, "Düsseldorfer Str.", "", 51.407424, 6.869967 },
	{ 50483, 0, "Klostermarkt", "", 51.402886, 6.879423 },
	{ 50484, 0, "Prinzeß-Luise-Str.", "", 51.424540, 6.862471 },
	{ 50485, 0, "Stadthalle", "", 51.427529, 6.873901 },
	{ 53466, 0, "Mülheim Hbf Nordausgang", "", 51.431565, 6.886110 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateMulheim_Adr : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateMulheim_Adr() {
    rect = QRectF(QPointF(50.430800, 5.874010), QPointF(52.430800, 7.874010));
    center = QPointF(51.430800, 6.874010);
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
      station->setRegion(QString("Mulheim_Adr %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_MULHEIM_ADR_H */

