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

#ifndef STATIONS_SIMPLE_PRIVATE_AIXENPROVENCE_H
#define STATIONS_SIMPLE_PRIVATE_AIXENPROVENCE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 3, 0, "3- Brossolette/Churchill", "", 43.5185189747, 5.4433065422 },
	{ 8, 0, "8- Cite Du Livre", "", 43.5247413812, 5.43992403319 },
	{ 6, 0, "6- Gare Sncf", "", 43.5232148458, 5.44546523167 },
	{ 5, 0, "5- Pkg Bellegarde", "", 43.5322417708, 5.45057973986 },
	{ 1, 0, "1- Office Du Tourisme", "", 43.5258125443, 5.44521093141 },
	{ 4, 0, "4- Briand/Pasteur", "", 43.5327677856, 5.4460589339 },
	{ 13, 0, "13- Europe/Villeneuve", "Av De L Europe", 43.5242715956, 5.43122128977 },
	{ 14, 0, "14- Route Cezanne", "", 43.5265062249, 5.45982266324 },
	{ 10, 0, "10- Lacepede/Opera", "", 43.5275833255, 5.45242746677 },
	{ 15, 0, "15- Allees Provencales", "", 43.5266644033, 5.44248831556 },
	{ 12, 0, "12- Palais De Justice", "", 43.5285546023, 5.44962483462 },
	{ 2, 0, "2- Pkg Mignet", "", 43.5246738682, 5.44758411683 },
	{ 9, 0, "9- Shumann", "", 43.5189701384, 5.44669288281 },
	{ 7, 0, "7- Italie/Carnot", "", 43.524830747, 5.45399563147 },
	{ 11, 0, "11- Sextius/Cordeliers", "", 43.5292828167, 5.44401510025 },
	{ 16, 0, "16- Gare Routiere Europe", "", 43.5236136087, 5.44129665327 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateAixenprovence : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateAixenprovence() {
    rect = QRectF(QPointF(43.324909, 5.431221), QPointF(43.532768, 5.654144));
    center = QPointF(43.524909, 5.454144);
    statusUrl = "http://www.vhello.fr/service/stationdetails/%1";
    infosUrl = "http://www.vhello.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Aixenprovence %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;

    ret << "0";

    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_AIXENPROVENCE_H */

