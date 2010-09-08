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

#ifndef STATIONS_SIMPLE_PRIVATE_VANNES_H
#define STATIONS_SIMPLE_PRIVATE_VANNES_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "Hôtel De Ville", "", 47.658184, -2.760283 },
	{ 2, 0, "Les Lices", "", 47.656480, -2.756823 },
	{ 3, 0, "République", "", 47.655920, -2.759968 },
	{ 4, 0, "Libération", "", 47.658904, -2.764077 },
	{ 5, 0, "La Paix", "", 47.661125, -2.759406 },
	{ 6, 0, "Préfecture", "", 47.658040, -2.755221 },
	{ 7, 0, "Porte Poterne", "", 47.655068, -2.755684 },
	{ 8, 0, "Le Port", "", 47.653269, -2.758978 },
	{ 9, 0, "Madeleine", "", 47.658972, -2.771498 },
	{ 10, 0, "Gares", "", 47.664791, -2.752016 },
	{ 11, 0, "Bir Hakeim", "", 47.658138, -2.749892 },
	{ 12, 0, "Capitainerie", "", 47.651382, -2.757264 },
	{ 13, 0, "Ménimur", "", 47.672408, -2.766606 },
	{ 14, 0, "Tohannic", "", 47.646805, -2.743365 },
	{ 15, 0, "La Rabine", "", 47.646430, -2.759031 },
	{ 16, 0, "Cuxhaven", "", 47.648731, -2.771681 },
	{ 17, 0, "Kercado - Piscine", "", 47.645179, -2.770856 },
	{ 18, 0, "Iut", "", 47.645072, -2.776799 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateVannes : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateVannes() {
    rect = QRectF(QPointF(47.454903, -2.959521), QPointF(47.854903, -2.559521));
    center = QPointF(47.654903, -2.759521);
    statusUrl = "";
    infosUrl = "http://www.velocea.fr/vannes/vannescms.nsf/vStands?readviewentries&ms=1283935637";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Vannes %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_VANNES_H */

