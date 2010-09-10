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

#ifndef STATIONS_SIMPLE_PRIVATE_LUBECK_H
#define STATIONS_SIMPLE_PRIVATE_LUBECK_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 8242, 0, "Travemuende Vorderreihe Volksbank", "", 53.956237, 10.866337 },
	{ 14952, 0, "Travemünde Vorderreihe", "", 53.957651, 10.870500 },
	{ 19189, 0, "Travemünde Kaiserallee Dlrg Station", "", 53.967371, 10.880456 },
	{ 19191, 0, "Travemünde Kaiserallee Liegewiese", "", 53.970174, 10.881658 },
	{ 19192, 0, "Travemünde Promenade Vorderreihe", "", 53.959116, 10.874534 },
	{ 19194, 0, "Jugendherberge Am Gertrudenkirchhof 4", "", 53.878137, 10.693946 },
	{ 19195, 0, "An Der Untertrave Fußgängerbrücke Zur Muk", "", 53.869560, 10.679827 },
	{ 19198, 0, "Touristen Information Am Holstentor", "", 53.865840, 10.677638 },
	{ 25847, 0, "Casino Travemünde", "", 53.964771, 10.879126 },
	{ 29569, 0, "Lindenplatz", "", 53.866667, 10.674367 },
	{ 45695, 0, "Holstentorplatz Vor Dem Kiosk", "", 53.865903, 10.679210 },
	{ 55458, 0, "Travemünde Hafen", "", 53.955555, 10.865264 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateLubeck : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateLubeck() {
    rect = QRectF(QPointF(52.869600, 9.687600), QPointF(54.869600, 11.687600));
    center = QPointF(53.869600, 10.687600);
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
      station->setRegion(QString("Lubeck %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_LUBECK_H */

