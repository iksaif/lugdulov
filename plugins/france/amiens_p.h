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

#ifndef STATIONS_SIMPLE_PRIVATE_AMIENS_H
#define STATIONS_SIMPLE_PRIVATE_AMIENS_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 5, 0, "05- St Leu", "Rue St Leu", 49.897920, 2.300574 },
	{ 24, 0, "24- Coliseum", "Boulevard Faidherbe", 49.894135, 2.287054 },
	{ 17, 0, "17- Cirque", "Mail Albert 1Er", 49.888851, 2.297399 },
	{ 1, 0, "01- Hotel De Ville", "Rue Albert Catoire", 49.894515, 2.296143 },
	{ 7, 0, "07- Baraban", "Boulevard Baraban", 49.898603, 2.305425 },
	{ 22, 0, "22- Quatre Chenes", "Avenue Du Général Foy", 49.890874, 2.282666 },
	{ 15, 0, "15- Jacobins", "Rue Des Jacobins", 49.890944, 2.300843 },
	{ 4, 0, "04- Place Au Feurre", "Place Au Feurre", 49.897290, 2.297864 },
	{ 2, 0, "02- Les Halles", "Rue J Natiere", 49.896032, 2.295044 },
	{ 10, 0, "10- Palais De Justice", "Place D' Aguesseau", 49.893359, 2.301314 },
	{ 23, 0, "23- St Roch", "Foch", 49.893443, 2.284525 },
	{ 9, 0, "09- Cathedrale", "Rue Flatters", 49.895082, 2.299395 },
	{ 6, 0, "06- Citadelle", "Bd Des Célestins", 49.901942, 2.300613 },
	{ 18, 0, "18- Prefecture", "Rue De La République", 49.890376, 2.295757 },
	{ 25, 0, "25- La Hotoie", "Bd Des Fédérés", 49.896863, 2.282868 },
	{ 26, 0, "26- Marche Aux Chevaux", "Rue Du Marché Aux Chevaux", 49.897251, 2.289247 },
	{ 20, 0, "20- Branly", "Bd Maignan Larivière", 49.890016, 2.291227 },
	{ 13, 0, "13- Gare Jules Barni", "Rue Jules Barni", 49.889904, 2.308779 },
	{ 8, 0, "08- Vanmarcke", "Rue Edouard David", 49.896852, 2.301576 },
	{ 3, 0, "03- Vogel", "Bd Du Jardin Des Plantes", 49.898124, 2.295195 },
	{ 19, 0, "19- Republique", "République Gambetta", 49.892720, 2.297076 },
	{ 21, 0, "21- Maison De La Culture", "Place Léon Gontier", 49.893922, 2.292725 },
	{ 11, 0, "11- Port D' Amont", "Bd Du Port D' Amont", 49.895578, 2.306191 },
	{ 16, 0, "16- Joffre", "Place Du Maréchal Joffre", 49.887793, 2.303611 },
	{ 14, 0, "14- Gare Cinema", "Passage Alphonse Fiquet", 49.890281, 2.307376 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateAmiens : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateAmiens() {
    rect = QRectF(QPointF(49.693918, 2.282666), QPointF(49.901942, 2.494244));
    center = QPointF(49.893918, 2.294244);
    statusUrl = "http://www.velam.amiens.fr/service/stationdetails/%1";
    infosUrl = "http://www.velam.amiens.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Amiens %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_AMIENS_H */

