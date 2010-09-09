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

#ifndef STATIONS_SIMPLE_PRIVATE_ORLEANS_H
#define STATIONS_SIMPLE_PRIVATE_ORLEANS_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "Gare Des Aubrais", "", 47.927011, 1.907435 },
	{ 2, 0, "Coligny", "", 47.915510, 1.899200 },
	{ 3, 0, "Bannier A Coulmiers", "", 47.912537, 1.900009 },
	{ 4, 0, "Antigna", "", 47.911573, 1.903608 },
	{ 5, 0, "Place Dunois", "", 47.907698, 1.893349 },
	{ 6, 0, "Mediatheque", "", 47.907500, 1.900833 },
	{ 7, 0, "Gare D'Orleans - Parvis", "", 47.907725, 1.904136 },
	{ 8, 0, "Gare D'Orleans - Tram", "", 47.906775, 1.904455 },
	{ 9, 0, "Place D'Arc", "", 47.906137, 1.906347 },
	{ 10, 0, "Halmagrand", "", 47.904501, 1.909351 },
	{ 11, 0, "Centre De Conferences", "", 47.904059, 1.918249 },
	{ 12, 0, "Republique", "", 47.903878, 1.904326 },
	{ 13, 0, "Place Du Martroi", "", 47.902607, 1.904560 },
	{ 14, 0, "La Cathedrale", "", 47.902330, 1.908889 },
	{ 15, 0, "Patinoire", "", 47.903205, 1.893328 },
	{ 16, 0, "Place Croix Morin", "", 47.901801, 1.897007 },
	{ 17, 0, "Place De Gaulle", "", 47.901289, 1.903094 },
	{ 18, 0, "Place Louis Xi", "", 47.900601, 1.905979 },
	{ 19, 0, "Bourgogne", "", 47.900487, 1.913899 },
	{ 20, 0, "Place Du Vieux Marche", "", 47.898969, 1.902809 },
	{ 21, 0, "Place Du Chatelet", "", 47.898636, 1.904959 },
	{ 22, 0, "Place De La Loire", "", 47.898531, 1.907769 },
	{ 23, 0, "Tourelles - Dauphine", "", 47.894686, 1.904185 },
	{ 24, 0, "Jardin Des Plantes", "", 47.892997, 1.899376 },
	{ 25, 0, "Place Saint Charles", "", 47.893965, 1.913107 },
	{ 26, 0, "Mairie St Jean Le Blanc", "", 47.892981, 1.916483 },
	{ 27, 0, "Parc Leon Chenault", "", 47.889381, 1.908466 },
	{ 28, 0, "Croix Saint Marceau", "", 47.888613, 1.905020 },
	{ 29, 0, "Capitainerie", "", 47.898788, 1.920474 },
	{ 30, 0, "Jean Zay", "", 47.906064, 1.922008 },
	{ 31, 0, "Palais Des Sports", "", 47.910288, 1.911461 },
	{ 32, 0, "Madeleine-Vauquois", "", 47.901078, 1.888186 },
	{ 33, 0, "Candolle", "", 47.889078, 1.896031 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateOrleans : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateOrleans() {
    rect = QRectF(QPointF(47.701387, 1.703976), QPointF(48.101387, 2.103976));
    center = QPointF(47.901387, 1.903976);
    statusUrl = "https://www.agglo-veloplus.fr/getStatusBorne?idBorne=%1";
    infosUrl = "https://www.agglo-veloplus.fr/component/data_1.xml";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Orleans %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_ORLEANS_H */

