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

#ifndef STATIONS_SIMPLE_PRIVATE_CALAIS_H
#define STATIONS_SIMPLE_PRIVATE_CALAIS_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "1 : Lafayette", "", 50.946611, 1.858303 },
	{ 2, 0, "2 : Théatre", "", 50.947474, 1.853694 },
	{ 3, 0, "3 : Hôtel De Ville", "", 50.951856, 1.853733 },
	{ 4, 0, "4 : Gare Sncf", "", 50.952908, 1.851291 },
	{ 5, 0, "5 : Richelieu", "", 50.955303, 1.849849 },
	{ 6, 0, "6 : Place D'Armes", "", 50.959396, 1.849231 },
	{ 7, 0, "7 : Pluviose", "", 50.965155, 1.843369 },
	{ 8, 0, "8 : Milieu De Digue", "", 50.962613, 1.831764 },
	{ 9, 0, "9 : Eglise De Blériot", "", 50.958423, 1.825627 },
	{ 10, 0, "10 : Camping De Blériot", "", 50.956936, 1.812581 },
	{ 11, 0, "11 : Base De Voile", "", 50.954689, 1.797998 },
	{ 12, 0, "12 : Cc La Française", "", 50.943716, 1.807732 },
	{ 13, 0, "13 : Pôle Administratif", "", 50.952854, 1.858672 },
	{ 14, 0, "14 : Cité De La Dentelle", "", 50.950309, 1.859797 },
	{ 15, 0, "15 : Université", "", 50.952580, 1.880568 },
	{ 16, 0, "16 : Lycée Berthelot", "", 50.946254, 1.842716 },
	{ 17, 0, "17 : Mogador", "", 50.945176, 1.828760 },
	{ 18, 0, "18 : Piscine Patinoire Icéo", "", 50.957068, 1.896017 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateCalais : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateCalais() {
    rect = QRectF(QPointF(50.758029, 1.652413), QPointF(51.158029, 2.052413));
    center = QPointF(50.958029, 1.852413);
    statusUrl = "";
    infosUrl = "http://www.vel-in.fr/oybike/stands.nsf/getSite?openagent&site=calais&format=json&key=D";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Calais %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_CALAIS_H */

