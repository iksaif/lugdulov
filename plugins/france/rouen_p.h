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

#ifndef STATIONS_SIMPLE_PRIVATE_ROUEN_H
#define STATIONS_SIMPLE_PRIVATE_ROUEN_H

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
	{ 9, 0, "09 - Republique - Quai Corneille", "Rue De La Republique", "Rue De La Republique  ", 49.4374898661, 1.0962522912 },
	{ 16, 0, "16-Ile Lacroix", "Avenue Jacques Chastellain - Parking De La Patinoire", "Avenue Jacques Chastellain - Parking De La Patinoire  ", 49.4315027287, 1.10287126622 },
	{ 1, 0, "01 - Theatre Des Arts", "Devant N°7 Bis Rue Jeanne D'Arc", "Devant N°7 Bis Rue Jeanne D'Arc  ", 49.439343519, 1.08871291348 },
	{ 10, 0, "10- Place Carnot", "Cours Clemenceau", "Cours Clemenceau  ", 49.4340412478, 1.09027469614 },
	{ 4, 0, "04- Musee Des Beaux Arts", "Devant N° 39 Allee Eugene Delacroix", "Devant N° 39 Allee Eugene Delacroix  ", 49.4443038267, 1.09404813781 },
	{ 12, 0, "12- Place Des Cotonniers", "Place Des Cotonniers", "Place Des Cotonniers  ", 49.4312487974, 1.08349671266 },
	{ 6, 0, "06- Chu - Rue De Germont", "Devant N° 6 Rue Edouard Adam", "Devant N° 6 Rue Edouard Adam  ", 49.4412011883, 1.10598550254 },
	{ 5, 0, "05- Hotel De Ville", "Rue De L Hopital", "Rue De L Hopital  ", 49.4425055864, 1.09826633822 },
	{ 14, 0, "14- Balzac - Boulevard De L' Europe", "Boulevard De L' Europe", "Boulevard De L' Europe  ", 49.4258234514, 1.08791281091 },
	{ 15, 0, "15-Gare", "Rue Jeanne D'Arc Angle Rue De La Rochefoucauld", "Rue Jeanne D'Arc Angle Rue De La Rochefoucauld  ", 49.4482075163, 1.09363650864 },
	{ 11, 0, "11- Clemenceau Joffre", "Cours Clemenceau", "Cours Clemenceau  ", 49.4346461396, 1.08795949014 },
	{ 3, 0, "03- Vieux Marche", "Place Du Vieux Marche", "Place Du Vieux Marche  ", 49.4435353393, 1.08923078431 },
	{ 2, 0, "02- Pasteur - Fac De Droit", "Avenue Pasteur", "Avenue Pasteur  ", 49.4442198011, 1.07816417879 },
	{ 17, 0, "17- Saint Clement", "Rue Lecuyer Angle Rue Lethuillier Pinel", "Rue Lecuyer Angle Rue Lethuillier Pinel  ", 49.4258744781, 1.07642484437 },
	{ 13, 0, "13- Saint Sever", "Place Saint Sever", "Place Saint Sever  ", 49.4308805149, 1.08609530535 },
	{ 7, 0, "07- Chu - Boulevard Gambetta", "Rue D' Amiens", "Rue D' Amiens  ", 49.4382035623, 1.10539625602 },
	{ 8, 0, "08- Saint Marc", "Rue Armand Carrel", "Rue Armand Carrel  ", 49.4380474032, 1.10067475146 },
	{0, 0, NULL, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateRouen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateRouen() {
    rect = QRectF(QPointF(49.425375770135, 1.075833631204), QPointF(49.448655197633, 1.106576715704));
    center = QPointF(49.437015483884, 1.091205173454);
    statusUrl = "http://cyclic.rouen.fr/service/stationdetails/%1";
    infosUrl = "http://cyclic.rouen.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Rouen %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_ROUEN_H */

