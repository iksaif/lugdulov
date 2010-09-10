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

#ifndef STATIONS_SIMPLE_PRIVATE_MULHOUSE_H
#define STATIONS_SIMPLE_PRIVATE_MULHOUSE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 27, 0, "27 - Cite Administrative", "Avenue De Colmar Devant Maison Des Associations", 47.756451, 7.335963 },
	{ 30, 0, "30 -  Hardt", "Rue De La Hardt Face Au 40", 47.753021, 7.355136 },
	{ 31, 0, "31 - Kinepolis", "Cinema Kinepolis Nouveau Bassin", 47.760404, 7.351546 },
	{ 23, 0, "23 - Hasenrein", "Avenue D'Altkirch Entrée Hopital", 47.735745, 7.332298 },
	{ 20, 0, "20 - Filature", "", 47.753534, 7.348463 },
	{ 15, 0, "15 - Grand Rex", "", 47.752433, 7.337387 },
	{ 28, 0, "28 - Schuman Lefeb", "Face 113 Avenue Robert Schuman Angle Rue Lefebvre", 47.756394, 7.347972 },
	{ 17, 0, "17 - Place De La Reunion", "", 47.746695, 7.338596 },
	{ 25, 0, "25 - Palais Des Sports", "Rue Du Château Zu-Rhein Angle Rue De Hirsingue", 47.740576, 7.320302 },
	{ 18, 0, "18 - Clemenceau", "14 Avenue Auguste Wicky", 47.744220, 7.339778 },
	{ 3, 0, "03 - Porte De Bale", "", 47.746858, 7.343595 },
	{ 11, 0, "11 - Place Du Printemps", "", 47.749664, 7.329469 },
	{ 22, 0, "22 - St Sauveur", "Rue De Zillisheim Angle Rue St Sauveur", 47.742729, 7.332529 },
	{ 9, 0, "09 - Nessel", "Boulevard Charles Stoessel", 47.744968, 7.327810 },
	{ 16, 0, "16 - Place Franklin", "", 47.751084, 7.333558 },
	{ 12, 0, "12 - Stalingrad", "", 47.749297, 7.346392 },
	{ 26, 0, "26 - Goerich", "Rue Charles Goerich Angle Rue Koechlim-Dolfus", 47.743259, 7.323935 },
	{ 24, 0, "24 - Tivoli", "Rue De Tivoli Angle Bd Wallack", 47.743055, 7.347364 },
	{ 7, 0, "07 - Mairie", "", 47.749411, 7.335779 },
	{ 29, 0, "29 - Laurent", "72 Rue Laurent", 47.752206, 7.352306 },
	{ 10, 0, "10 - Place De La Paix", "", 47.744186, 7.335727 },
	{ 35, 0, "35 - Europe", "Rue Du Capitaine Dreyfus Angle Bd De L'Europe", 47.752692, 7.346459 },
	{ 32, 0, "32- Campus", "Rue Alfred Verner Allée Brenard Thierry-Mieg", 47.733210, 7.314266 },
	{ 4, 0, "04 - Parc Salvator", "", 47.748312, 7.343105 },
	{ 19, 0, "19 - Les Trois Rois", "", 47.744093, 7.333487 },
	{ 14, 0, "14 - Schumann", "", 47.752209, 7.342591 },
	{ 8, 0, "08 - Porte Haute (2)", "", 47.746993, 7.332063 },
	{ 1, 0, "01 - Parvis De La Gare", "Avenue Du Général Leclerc", 47.742780, 7.342021 },
	{ 13, 0, "13 - Marche", "", 47.751247, 7.329752 },
	{ 6, 0, "06 - Porte Jeune", "", 47.750069, 7.338714 },
	{ 5, 0, "05 - Metz", "", 47.749465, 7.341236 },
	{ 33, 0, "33 - Auberge", "Rue De Brunstatt Angle Rue De L'Illberg", 47.738321, 7.317405 },
	{ 2, 0, "02 - Republique", "3 Place De La République", 47.745961, 7.341413 },
	{ 34, 0, "34 - Patinoire", "Boulevard Charles Stoessel Entrée Parc Des Sport Patinoire", 47.735930, 7.318956 },
	{ 21, 0, "21 - Fonderie", "Rue De La Locomotive Angle Rue Des Monteurs", 47.739178, 7.332528 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateMulhouse : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateMulhouse() {
    rect = QRectF(QPointF(47.549492, 7.314266), QPointF(47.760404, 7.539781));
    center = QPointF(47.749492, 7.339781);
    statusUrl = "http://www.velocite.mulhouse.fr/service/stationdetails/%1";
    infosUrl = "http://www.velocite.mulhouse.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Mulhouse %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_MULHOUSE_H */

