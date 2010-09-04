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
	{ 50450, 0, "Musiktheater", "", 51.5130961644, 7.09186587644 },
	{ 50451, 0, "Zoom-Erlebniswelt", "", 51.5417849043, 7.11032612019 },
	{ 50452, 0, "Nordsternpark", "", 51.5282066369, 7.03020540281 },
	{ 50453, 0, "Schloss Horst", "", 51.5367664029, 7.02476329529 },
	{ 50454, 0, "Fachhochschule", "", 51.5749900821, 7.02625799504 },
	{ 50455, 0, "Zob Ge-Buer", "", 51.5782954624, 7.05788253125 },
	{ 50456, 0, "Goldbergplatz", "", 51.5773755242, 7.05523564465 },
	{ 50457, 0, "Freiheit", "", 51.5815332476, 7.05080866814 },
	{ 50447, 0, "Hbf - Bahnhofsvorplatz", "", 51.5062750276, 7.10064411163 },
	{ 50448, 0, "Hbf - Südausgang", "", 51.5044632059, 7.10285043638 },
	{ 50449, 0, "Heinrich-König-Platz", "", 51.5103976348, 7.0940052485 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateGelsenkirchen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateGelsenkirchen() {
    rect = QRectF(QPointF(51.340400, 6.870390), QPointF(51.740400, 7.270390));
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

