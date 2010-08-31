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
	{ 27, 0, "27 - Cite Administrative", "Avenue De Colmar Devant Maison Des Associations", 47.7564505918, 7.33596269769 },
	{ 30, 0, "30 -  Hardt", "Rue De La Hardt Face Au 40", 47.7530211023, 7.35513626876 },
	{ 31, 0, "31 - Kinepolis", "Cinema Kinepolis Nouveau Bassin", 47.7604035343, 7.35154587448 },
	{ 23, 0, "23 - Hasenrein", "Avenue D'Altkirch Entrée Hopital", 47.7357451376, 7.33229807737 },
	{ 20, 0, "20 - Filature", "", 47.7535339152, 7.34846291227 },
	{ 15, 0, "15 - Grand Rex", "", 47.7524331345, 7.33738736357 },
	{ 28, 0, "28 - Schuman Lefeb", "Face 113 Avenue Robert Schuman Angle Rue Lefebvre", 47.7563938571, 7.34797191027 },
	{ 17, 0, "17 - Place De La Reunion", "", 47.7466946257, 7.33859576904 },
	{ 25, 0, "25 - Palais Des Sports", "Rue Du Château Zu-Rhein Angle Rue De Hirsingue", 47.7405762189, 7.32030212836 },
	{ 18, 0, "18 - Clemenceau", "14 Avenue Auguste Wicky", 47.7442195601, 7.33977824911 },
	{ 3, 0, "03 - Porte De Bale", "", 47.7468581729, 7.34359523047 },
	{ 11, 0, "11 - Place Du Printemps", "", 47.7496639092, 7.32946903672 },
	{ 22, 0, "22 - St Sauveur", "Rue De Zillisheim Angle Rue St Sauveur", 47.74272854, 7.33252938649 },
	{ 9, 0, "09 - Nessel", "Boulevard Charles Stoessel", 47.7449677203, 7.32781031945 },
	{ 16, 0, "16 - Place Franklin", "", 47.7510835523, 7.33355834455 },
	{ 12, 0, "12 - Stalingrad", "", 47.7492972821, 7.34639152434 },
	{ 26, 0, "26 - Goerich", "Rue Charles Goerich Angle Rue Koechlim-Dolfus", 47.7432593603, 7.32393495956 },
	{ 24, 0, "24 - Tivoli", "Rue De Tivoli Angle Bd Wallack", 47.7430550862, 7.34736417117 },
	{ 7, 0, "07 - Mairie", "", 47.7494111008, 7.33577902566 },
	{ 29, 0, "29 - Laurent", "72 Rue Laurent", 47.752205822, 7.35230611412 },
	{ 10, 0, "10 - Place De La Paix", "", 47.7441863794, 7.33572665536 },
	{ 35, 0, "35 - Europe", "Rue Du Capitaine Dreyfus Angle Bd De L'Europe", 47.7526919379, 7.34645885818 },
	{ 32, 0, "32- Campus", "Rue Alfred Verner Allée Brenard Thierry-Mieg", 47.7332104864, 7.31426569702 },
	{ 4, 0, "04 - Parc Salvator", "", 47.7483121921, 7.34310470688 },
	{ 19, 0, "19 - Les Trois Rois", "", 47.7440933233, 7.33348655061 },
	{ 14, 0, "14 - Schumann", "", 47.7522094578, 7.34259128373 },
	{ 8, 0, "08 - Porte Haute (2)", "", 47.7469931995, 7.33206326835 },
	{ 1, 0, "01 - Parvis De La Gare", "Avenue Du Général Leclerc", 47.7427803502, 7.34202050648 },
	{ 13, 0, "13 - Marche", "", 47.7512468903, 7.32975195387 },
	{ 6, 0, "06 - Porte Jeune", "", 47.7500690513, 7.33871413913 },
	{ 5, 0, "05 - Metz", "", 47.7494649866, 7.34123604963 },
	{ 33, 0, "33 - Auberge", "Rue De Brunstatt Angle Rue De L'Illberg", 47.7383211152, 7.31740462583 },
	{ 2, 0, "02 - Republique", "3 Place De La République", 47.7459607192, 7.34141256758 },
	{ 34, 0, "34 - Patinoire", "Boulevard Charles Stoessel Entrée Parc Des Sport Patinoire", 47.7359296084, 7.3189564417 },
	{ 21, 0, "21 - Fonderie", "Rue De La Locomotive Angle Rue Des Monteurs", 47.7391778467, 7.332528398 },
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

