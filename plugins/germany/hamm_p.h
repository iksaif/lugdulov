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

#ifndef STATIONS_SIMPLE_PRIVATE_HAMM_H
#define STATIONS_SIMPLE_PRIVATE_HAMM_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50458, 0, "Bahnhof", "", 51.67878576, 7.80912280083 },
	{ 50459, 0, "Heinrich-Von-Kleist-Forum", "", 51.6783093231, 7.81105482906 },
	{ 50460, 0, "Allee-Center", "", 51.681189715, 7.81196511727 },
	{ 50461, 0, "Martin-Luther-Platz", "", 51.6798753688, 7.81616372644 },
	{ 50462, 0, "Weststraße", "", 51.6809774909, 7.81755262022 },
	{ 50463, 0, "Widumstraße", "", 51.6807148645, 7.82057866022 },
	{ 50464, 0, "Rathaus", "", 51.6772601292, 7.82192927728 },
	{ 50465, 0, "Oberlandesgericht", "", 51.6785135, 7.8268418 },
	{ 50466, 0, "Maximilianpark", "", 51.6836452415, 7.88385987282 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateHamm : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateHamm() {
    rect = QRectF(QPointF(51.477500, 7.648360), QPointF(51.877500, 8.048360));
    center = QPointF(51.677500, 7.848360);
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
      station->setRegion(QString("Hamm %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_HAMM_H */

