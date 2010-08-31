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
	{ 5, 0, "05- St Leu", "Rue St Leu", 49.8979196254, 2.30057432814 },
	{ 24, 0, "24- Coliseum", "Boulevard Faidherbe", 49.8941349276, 2.28705404866 },
	{ 17, 0, "17- Cirque", "Mail Albert 1Er", 49.8888505037, 2.29739850907 },
	{ 1, 0, "01- Hotel De Ville", "Rue Albert Catoire", 49.894515429, 2.29614320766 },
	{ 7, 0, "07- Baraban", "Boulevard Baraban", 49.8986033413, 2.30542475605 },
	{ 22, 0, "22- Quatre Chenes", "Avenue Du Général Foy", 49.8908738967, 2.28266570248 },
	{ 15, 0, "15- Jacobins", "Rue Des Jacobins", 49.8909435452, 2.3008434194 },
	{ 4, 0, "04- Place Au Feurre", "Place Au Feurre", 49.8972902974, 2.29786445241 },
	{ 2, 0, "02- Les Halles", "Rue J Natiere", 49.8960323886, 2.29504397487 },
	{ 10, 0, "10- Palais De Justice", "Place D' Aguesseau", 49.8933588618, 2.30131422072 },
	{ 23, 0, "23- St Roch", "Foch", 49.8934425259, 2.284525283 },
	{ 9, 0, "09- Cathedrale", "Rue Flatters", 49.8950821191, 2.2993950039 },
	{ 6, 0, "06- Citadelle", "Bd Des Célestins", 49.9019419029, 2.30061312227 },
	{ 18, 0, "18- Prefecture", "Rue De La République", 49.8903762791, 2.29575743701 },
	{ 25, 0, "25- La Hotoie", "Bd Des Fédérés", 49.8968625368, 2.28286774758 },
	{ 26, 0, "26- Marche Aux Chevaux", "Rue Du Marché Aux Chevaux", 49.8972512886, 2.28924702784 },
	{ 20, 0, "20- Branly", "Bd Maignan Larivière", 49.8900155143, 2.29122726422 },
	{ 13, 0, "13- Gare Jules Barni", "Rue Jules Barni", 49.8899041714, 2.308779414 },
	{ 8, 0, "08- Vanmarcke", "Rue Edouard David", 49.8968515059, 2.3015758288 },
	{ 3, 0, "03- Vogel", "Bd Du Jardin Des Plantes", 49.8981243852, 2.29519512809 },
	{ 19, 0, "19- Republique", "République Gambetta", 49.8927200733, 2.29707581964 },
	{ 21, 0, "21- Maison De La Culture", "Place Léon Gontier", 49.8939216557, 2.2927247291 },
	{ 11, 0, "11- Port D' Amont", "Bd Du Port D' Amont", 49.8955778521, 2.30619107978 },
	{ 16, 0, "16- Joffre", "Place Du Maréchal Joffre", 49.8877929309, 2.30361108883 },
	{ 14, 0, "14- Gare Cinema", "Passage Alphonse Fiquet", 49.8902809262, 2.30737558427 },
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

