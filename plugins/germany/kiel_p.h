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

#ifndef STATIONS_SIMPLE_PRIVATE_KIEL_H
#define STATIONS_SIMPLE_PRIVATE_KIEL_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 52231, 0, "Andreas-Gayk-Straße/ Ecke Fabrikstraße", "", 54.3195270691, 10.1345872879 },
	{ 52239, 0, "Ostseehalle Exerzierplatz", "", 54.3217547671, 10.1273989677 },
	{ 52236, 0, "Schloßgarten", "", 54.3258093686, 10.1430416107 },
	{ 52229, 0, "Jugendherberge Johannesstraße", "", 54.3138571585, 10.1427304745 },
	{ 52232, 0, "Kunsthalle Düsternbrooker Weg", "", 54.3282838556, 10.1463729143 },
	{ 52826, 0, "Norwegenkai", "", 54.3151284192, 10.1369556785 },
	{ 60142, 0, "Holtenauer Str. / Ecke  Waitzstraße", "", 54.3354186794, 10.1336216927 },
	{ 61082, 0, "Atlantic Hotel Raiffeisenstraße", "", 54.316002, 10.132522 },
	{ 61800, 0, "Holtenauer Str./Ecke Düppelstraße", "", 54.3375767119, 10.1336324215 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateKiel : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateKiel() {
    rect = QRectF(QPointF(54.122700, 9.935900), QPointF(54.522700, 10.335900));
    center = QPointF(54.322700, 10.135900);
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
      station->setRegion(QString("Kiel %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_KIEL_H */

