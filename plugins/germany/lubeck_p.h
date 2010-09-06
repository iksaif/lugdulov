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
	{ 8242, 0, "Travemuende Vorderreihe Volksbank", "", 53.9562370404, 10.8663368225 },
	{ 14952, 0, "Travemünde Vorderreihe", "", 53.9576511014, 10.8704996109 },
	{ 19189, 0, "Travemünde Kaiserallee Dlrg Station", "", 53.9673714727, 10.8804559708 },
	{ 19191, 0, "Travemünde Kaiserallee Liegewiese", "", 53.9701735485, 10.8816576004 },
	{ 19192, 0, "Travemünde Promenade Vorderreihe", "", 53.959115614, 10.8745336533 },
	{ 19194, 0, "Jugendherberge Am Gertrudenkirchhof 4", "", 53.8781368189, 10.6939458847 },
	{ 19195, 0, "An Der Untertrave Fußgängerbrücke Zur Muk", "", 53.8695596481, 10.6798267365 },
	{ 19198, 0, "Touristen Information Am Holstentor", "", 53.8658397972, 10.6776380539 },
	{ 25847, 0, "Casino Travemünde", "", 53.9647711799, 10.8791255951 },
	{ 29569, 0, "Lindenplatz", "", 53.8666672, 10.6743674 },
	{ 45695, 0, "Holstentorplatz Vor Dem Kiosk", "", 53.8659030627, 10.6792098284 },
	{ 55458, 0, "Travemünde Hafen", "", 53.9555552438, 10.8652639389 },
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

