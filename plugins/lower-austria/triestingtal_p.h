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

#ifndef STATIONS_SIMPLE_PRIVATE_TRIESTINGTAL_H
#define STATIONS_SIMPLE_PRIVATE_TRIESTINGTAL_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 43858, 0, "Leobersdorf / Rathausplatz", "", 47.928530, 16.216570 },
	{ 43853, 0, "Kaumberg / Marktplatz", "", 48.023880, 15.898240 },
	{ 43855, 0, "Weissenbach / Bahnhof", "", 47.983800, 16.045350 },
	{ 43856, 0, "Berndorf / Bahnhof - Ortszentrum", "", 47.944760, 16.108420 },
	{ 43857, 0, "Leobersdorf / Bahnhof", "", 47.937390, 16.230920 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateTriestingtal : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateTriestingtal() {
    rect = QRectF(QPointF(46.983500, 15.081200), QPointF(48.983500, 17.081200));
    center = QPointF(47.983500, 16.081200);
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
      station->setRegion(QString("Triestingtal %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_TRIESTINGTAL_H */

