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

#ifndef STATIONS_SIMPLE_PRIVATE_AVIGNON_H
#define STATIONS_SIMPLE_PRIVATE_AVIGNON_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 28, 0, "19 Banasterie", "", 43.952406, 4.809761 },
	{ 26, 0, "18 Saint Michel", "", 43.942606, 4.808514 },
	{ 19, 0, "17 Dunant", "", 43.941944, 4.822222 },
	{ 18, 0, "16 Rotondes", "", 43.939167, 4.821389 },
	{ 17, 0, "15 Saint Jean", "", 43.947039, 4.828061 },
	{ 16, 0, "14 Maison Pour Tous", "", 43.939444, 4.805833 },
	{ 15, 0, "13 Saint Ruf", "", 43.937778, 4.810278 },
	{ 14, 0, "12 Porte Thiers", "", 43.946667, 4.817222 },
	{ 13, 0, "11 Porte Limbert", "", 43.943889, 4.814722 },
	{ 12, 0, "10 Porte Saint-Roch", "", 43.943611, 4.799444 },
	{ 11, 0, "09 Porte Saint-Lazare", "", 43.950911, 4.819661 },
	{ 10, 0, "08 Porte De L'Oulle", "", 43.950000, 4.802222 },
	{ 9, 0, "07 Vernet", "", 43.947500, 4.803333 },
	{ 7, 0, "05 Carmes", "", 43.950000, 4.813056 },
	{ 6, 0, "04 Republique", "", 43.946389, 4.805556 },
	{ 5, 0, "03 Hotel De Ville", "", 43.949018, 4.805381 },
	{ 4, 0, "02 Place Pie", "", 43.948458, 4.810347 },
	{ 3, 0, "01 Jaures", "", 43.943233, 4.805682 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateAvignon : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateAvignon() {
    rect = QRectF(QPointF(43.748613, 4.605967), QPointF(44.148613, 5.005967));
    center = QPointF(43.948613, 4.805967);
    statusUrl = "";
    infosUrl = "http://www.velopop.fr/stations.html";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Avignon %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_AVIGNON_H */

