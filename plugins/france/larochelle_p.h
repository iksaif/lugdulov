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

#ifndef STATIONS_SIMPLE_PRIVATE_LAROCHELLE_H
#define STATIONS_SIMPLE_PRIVATE_LAROCHELLE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "Hôtel De Ville", "", 46.15971375, -1.1518102 },
	{ 2, 0, "Square Valin", "", 46.15738769, -1.1506086 },
	{ 3, 0, "Arsenal", "", 46.15992554, -1.1486184 },
	{ 4, 0, "Marché", "", 46.16140435, -1.1489564 },
	{ 5, 0, "Hôtel De Police", "", 46.16271964, -1.1525398 },
	{ 6, 0, "Gare Routière", "", 46.16235552, -1.1535269 },
	{ 7, 0, "Préfecture", "", 46.15697152, -1.1568474 },
	{ 8, 0, "Vieux Port", "", 46.15693807, -1.1537361 },
	{ 9, 0, "Motte Rouge", "", 46.15590877, -1.1488974 },
	{ 10, 0, "Hôpital", "", 46.15831292, -1.145094 },
	{ 11, 0, "Porte Dauphine", "", 46.16784302, -1.1504477 },
	{ 12, 0, "Piscine", "", 46.1698603, -1.1523467 },
	{ 13, 0, "Médiathèque", "", 46.15341533, -1.1532318 },
	{ 14, 0, "Bibliothèque Universitaire", "", 46.15235252, -1.1535966 },
	{ 15, 0, "Office De Tourisme", "", 46.15503552, -1.1499166 },
	{ 16, 0, "Gare 1", "", 46.15279846, -1.1458128 },
	{ 17, 0, "Gare 2", "", 46.1529248, -1.1455875 },
	{ 18, 0, "Parking Jean Moulin 1", "", 46.15280589, -1.140604 },
	{ 19, 0, "Parking Jean Moulin 2", "", 46.15297683, -1.1413013 },
	{ 20, 0, "Faculté De Sciences", "", 46.14665906, -1.1571693 },
	{ 21, 0, "Cinéma", "", 46.14825715, -1.1535644 },
	{ 22, 0, "Place Des Cordeliers", "", 46.16297972, -1.1458665 },
	{ 23, 0, "Place Cacaud", "", 46.16375253, -1.1472129 },
	{ 24, 0, "Eigsi", "", 46.14029596, -1.1538219 },
	{ 25, 0, "Iut", "", 46.14205778, -1.1525452 },
	{ 26, 0, "Maison Du Département", "", 46.13819583, -1.1517244 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateLarochelle : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateLarochelle() {
    rect = QRectF(QPointF(45.958022, -1.353595), QPointF(46.358022, -0.953595));
    center = QPointF(46.158022, -1.153595);
    statusUrl = "";
    infosUrl = "http://www.rtcr.fr/ct_93_297__Carte_du_libre_service_velos.html";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Larochelle %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_LAROCHELLE_H */

