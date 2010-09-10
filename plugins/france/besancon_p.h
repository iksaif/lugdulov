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

#ifndef STATIONS_SIMPLE_PRIVATE_BESANCON_H
#define STATIONS_SIMPLE_PRIVATE_BESANCON_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "01 - Gare Viotte (Cb)", "", 47.246304, 6.022338 },
	{ 2, 0, "02 - Square Bouchot", "", 47.242645, 6.021028 },
	{ 3, 0, "03 - Madeleine", "", 47.240162, 6.020103 },
	{ 4, 0, "04 - Flore", "", 47.245319, 6.028088 },
	{ 5, 0, "05 - Isembart", "", 47.242766, 6.025135 },
	{ 6, 0, "06 - Office De Tourisme (Cb)", "", 47.242462, 6.030417 },
	{ 7, 0, "07 - Gare Mouillere", "", 47.240379, 6.033592 },
	{ 8, 0, "08 - Marulaz", "", 47.239742, 6.017165 },
	{ 9, 0, "09 - La City (Cb)", "", 47.235379, 6.015318 },
	{ 10, 0, "10 - 8 Septembre", "", 47.237722, 6.024298 },
	{ 11, 0, "11 - Jean Cornet", "", 47.236173, 6.029361 },
	{ 12, 0, "12 - Granvelle (Cb)", "", 47.235463, 6.025941 },
	{ 13, 0, "13 - Victor Hugo", "", 47.234905, 6.029314 },
	{ 14, 0, "14 - Jacobins", "", 47.234568, 6.033654 },
	{ 15, 0, "15 - Tarragnoz", "", 47.230795, 6.028580 },
	{ 16, 0, "16 - Gare D'Eau", "", 47.232306, 6.022722 },
	{ 17, 0, "17 - Prefecture", "", 47.232904, 6.020661 },
	{ 18, 0, "18 - Saint-Jacques (Cb)", "", 47.234705, 6.020930 },
	{ 19, 0, "19 - Beaux-Arts (Cb)", "", 47.241404, 6.022926 },
	{ 20, 0, "20 - Revolution", "", 47.239564, 6.023301 },
	{ 21, 0, "21 - Saint-Paul", "", 47.238182, 6.031893 },
	{ 22, 0, "22 - Liberte", "", 47.247319, 6.028623 },
	{ 23, 0, "23 - Rivotte", "", 47.232542, 6.035338 },
	{ 24, 0, "24 - Mediatheque", "", 47.239651, 6.027922 },
	{ 25, 0, "25 - Morand", "", 47.238151, 6.026391 },
	{ 26, 0, "26 - Bersot", "", 47.238741, 6.029340 },
	{ 27, 0, "27 - Mairie", "", 47.236611, 6.022992 },
	{ 28, 0, "28 - Leclerc", "", 47.242304, 6.014776 },
	{ 29, 0, "29 - Square Labbe", "", 47.238972, 6.013357 },
	{ 30, 0, "30 - Xavier Marmier", "", 47.241279, 6.006520 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBesancon : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBesancon() {
    rect = QRectF(QPointF(47.041225, 6.006520), QPointF(47.247319, 6.225566));
    center = QPointF(47.241225, 6.025566);
    statusUrl = "http://www.velocite.besancon.fr/service/stationdetails/%1";
    infosUrl = "http://www.velocite.besancon.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Besancon %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_BESANCON_H */

