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

#ifndef STATIONS_SIMPLE_PRIVATE_ST_POLTEN_H
#define STATIONS_SIMPLE_PRIVATE_ST_POLTEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 48289, 0, "St. Pölten / Hbf Ostportal", "", 48.20839, 15.63134 },
	{ 48290, 0, "St. Pölten / Seenerlebnis Viehofen", "", 48.22093, 15.64257 },
	{ 48291, 0, "St. Pölten / Rathausplatz", "", 48.2054382231, 15.6227463484 },
	{ 48292, 0, "St. Pölten / Wirtschaftszentrum Nö", "", 48.19853, 15.63306 },
	{ 48294, 0, "St. Pölten / Landesmuseum/Festspielhaus", "", 48.20037, 15.63143 },
	{ 48295, 0, "St. Pölten / Landhaus - Haus 1A", "", 48.20131, 15.6318 },
	{ 48296, 0, "St. Pölten / Tor Zum Landhaus", "", 48.20388, 15.63327 },
	{ 48297, 0, "St. Pölten / Klostergasse", "", 48.20678, 15.62516 },
	{ 48298, 0, "St. Pölten / Gästehaus Aquilin", "", 48.17263, 15.62465 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateSt_Polten : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateSt_Polten() {
    rect = QRectF(QPointF(48.005800, 15.423200), QPointF(48.405800, 15.823200));
    center = QPointF(48.205800, 15.623200);
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
      station->setRegion(QString("St_Polten %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_ST_POLTEN_H */

