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
        const char *fullAddress;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "01 - Gare Viotte (Cb)", "", "  ", 47.2463041383, 6.02233755193 },
	{ 2, 0, "02 - Square Bouchot", "", "  ", 47.24264475, 6.02102752529 },
	{ 3, 0, "03 - Madeleine", "", "  ", 47.2401617637, 6.02010280166 },
	{ 4, 0, "04 - Flore", "", "  ", 47.2453187653, 6.02808842836 },
	{ 5, 0, "05 - Isembart", "", "  ", 47.242765625, 6.02513523752 },
	{ 6, 0, "06 - Office De Tourisme (Cb)", "", "  ", 47.2424615277, 6.03041701042 },
	{ 7, 0, "07 - Gare Mouillere", "", "  ", 47.2403785904, 6.03359224259 },
	{ 8, 0, "08 - Marulaz", "", "  ", 47.2397422387, 6.01716484605 },
	{ 9, 0, "09 - La City (Cb)", "", "  ", 47.2353794968, 6.01531775872 },
	{ 10, 0, "10 - 8 Septembre", "", "  ", 47.2377223044, 6.02429829629 },
	{ 11, 0, "11 - Jean Cornet", "", "  ", 47.2361734638, 6.02936143298 },
	{ 12, 0, "12 - Granvelle (Cb)", "", "  ", 47.2354634327, 6.02594080104 },
	{ 13, 0, "13 - Victor Hugo", "", "  ", 47.2349052193, 6.0293135657 },
	{ 14, 0, "14 - Jacobins", "", "  ", 47.2345680603, 6.03365351314 },
	{ 15, 0, "15 - Tarragnoz", "", "  ", 47.2307951598, 6.02858040758 },
	{ 16, 0, "16 - Gare D'Eau", "", "  ", 47.2323063706, 6.02272189141 },
	{ 17, 0, "17 - Prefecture", "", "  ", 47.2329035506, 6.02066083259 },
	{ 18, 0, "18 - Saint-Jacques (Cb)", "", "  ", 47.2347050416, 6.02093031595 },
	{ 19, 0, "19 - Beaux-Arts (Cb)", "", "  ", 47.241404392, 6.0229256225 },
	{ 20, 0, "20 - Revolution", "", "  ", 47.2395642758, 6.02330130527 },
	{ 21, 0, "21 - Saint-Paul", "", "  ", 47.2381816509, 6.03189336389 },
	{ 22, 0, "22 - Liberte", "", "  ", 47.2473188776, 6.02862320903 },
	{ 23, 0, "23 - Rivotte", "", "  ", 47.2325418335, 6.0353380606 },
	{ 24, 0, "24 - Mediatheque", "", "  ", 47.2396506324, 6.02792211119 },
	{ 25, 0, "25 - Morand", "", "  ", 47.2381506922, 6.0263905668 },
	{ 26, 0, "26 - Bersot", "", "  ", 47.2387407098, 6.02934029153 },
	{ 27, 0, "27 - Mairie", "", "  ", 47.2366113604, 6.02299204761 },
	{ 28, 0, "28 - Leclerc", "", "  ", 47.2423039449, 6.01477570241 },
	{ 29, 0, "29 - Square Labbe", "", "  ", 47.2389721584, 6.01335658368 },
	{ 30, 0, "30 - Xavier Marmier", "", "  ", 47.2412791303, 6.00651997961 },
	{0, 0, NULL, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBesancon : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBesancon() {
    rect = QRectF(QPointF(47.230464685463, 6.005943617992), QPointF(47.247649351927, 6.035914422218));
    center = QPointF(47.239057018695, 6.020929020105);
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

