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

#ifndef STATIONS_SIMPLE_PRIVATE_PAU_H
#define STATIONS_SIMPLE_PRIVATE_PAU_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 17, 0, "Allees", "Avenue Des Lilas Face Au N 26 Avenue Des Lilas", 43.305313, -0.351039 },
	{ 6, 0, "Barthou", "Angle De La Rue Leon Daran De La Rue Louis Barthou", 43.294804, -0.365615 },
//	{ 225, 0, "Borne Mobile", "Pau", 100.000000, 100.000000 },
	{ 1, 0, "Bosquet", "Angle De La Rue Jean Monnet De La Cours Bosquet Face A L'Entree Du Centre Commercial", 43.297707, -0.366069 },
	{ 8, 0, "Chateau", "Angle De La Rue Henri Iv De La Rue Gassion", 43.294740, -0.372936 },
	{ 18, 0, "Croix Du Prince", "Angle Avenue De Gelos Rue Du 14 Juillet Face Au N 14 Avenue De Gelos", 43.287224, -0.380451 },
	{ 7, 0, "Funiculaire", "Angle Du Boulevard Des Pyrenees De La Place Royale", 43.293396, -0.371321 },
	{ 14, 0, "Gare Sncf", "Angle De L'Avenue Jean Biray De L'Avenue Napoleon Bonaparte", 43.292450, -0.369824 },
	{ 4, 0, "Mediatheque", "Place Marguerit Laborde Au Bout Du Parking", 43.299995, -0.368211 },
	{ 11, 0, "Parc Des Expositions", "Rond Point Du Souvenir Francais Face A L'Entree Du Parc Des Expositions", 43.305510, -0.377247 },
	{ 20, 0, "Pierre Masse", "Angle De L'Avenue Pierre Masse La Rue Andre Mitton", 43.314774, -0.357013 },
	{ 2, 0, "Place Clemenceau", "Place Georges Clemenceau Face Au N 20 De La Place Georges Clemenceau", 43.296270, -0.368853 },
	{ 15, 0, "Place De La Monnaie", "Place De La Monnaie Face Au N 5 Place De La Monnaie", 43.294094, -0.375918 },
	{ 9, 0, "Place Gramont", "Angle De La Rue Borgenave D'Abere La Place Gramont", 43.296300, -0.374465 },
	{ 12, 0, "Place Lyautey", "Angle Du Boulevard D'Alsace-Lorraine Du Cours Lyautey", 43.304485, -0.366977 },
	{ 10, 0, "Place Verdun", "Angle De La Rue Borde Longue De La Rue De Liege Face Au N 32 De La Rue De Liege", 43.299010, -0.375135 },
	{ 5, 0, "Saint Cricq", "Face N 30 Avenue Charles De Gaulle", 43.301163, -0.359003 },
	{ 19, 0, "Saint John Perse", "Angle De La Rue Saint John Perse De La Rue Audrey Benghozi", 43.318893, -0.364150 },
	{ 13, 0, "Saragosse", "Angle De L'Avenue De Saragosse De La Rue Jules Vernes", 43.307964, -0.358153 },
	{ 3, 0, "Sept Canton", "Face N 2 Rue Saint Jacques", 43.298397, -0.370582 },
	{ 16, 0, "Universite Sud", "Avenue De L'Universite Face A L'Entree De L'Universite", 43.311650, -0.365027 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivatePau : StationsPluginSimplePrivate {
  StationsPluginSimplePrivatePau() {
    rect = QRectF(QPointF(43.094610, -0.570780), QPointF(43.494610, -0.170780));
    center = QPointF(43.294610, -0.370780);
    statusUrl = "";
    infosUrl = "http://www.idecycle.com/stations/plan";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Pau %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_PAU_H */

