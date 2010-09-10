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

#ifndef STATIONS_SIMPLE_PRIVATE_GELSENKIRCHEN_H
#define STATIONS_SIMPLE_PRIVATE_GELSENKIRCHEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50450, 0, "Musiktheater", "", 51.513096, 7.091866 },
	{ 50451, 0, "Zoom-Erlebniswelt", "", 51.541785, 7.110326 },
	{ 50452, 0, "Nordsternpark", "", 51.528207, 7.030205 },
	{ 50453, 0, "Schloss Horst", "", 51.536766, 7.024763 },
	{ 50454, 0, "Fachhochschule", "", 51.574990, 7.026258 },
	{ 50455, 0, "Zob Ge-Buer", "", 51.578295, 7.057883 },
	{ 50456, 0, "Goldbergplatz", "", 51.577376, 7.055236 },
	{ 50457, 0, "Freiheit", "", 51.581533, 7.050809 },
	{ 50447, 0, "Hbf - Bahnhofsvorplatz", "", 51.506275, 7.100644 },
	{ 50448, 0, "Hbf - Südausgang", "", 51.504463, 7.102850 },
	{ 50449, 0, "Heinrich-König-Platz", "", 51.510398, 7.094005 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateGelsenkirchen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateGelsenkirchen() {
    rect = QRectF(QPointF(50.540400, 6.070390), QPointF(52.540400, 8.070390));
    center = QPointF(51.540400, 7.070390);
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
      station->setRegion(QString("Gelsenkirchen %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_GELSENKIRCHEN_H */

