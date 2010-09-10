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

#ifndef STATIONS_SIMPLE_PRIVATE_NANTES_H
#define STATIONS_SIMPLE_PRIVATE_NANTES_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 85, 0, "00085-Bel Air", "", 47.225856, -1.559480 },
	{ 87, 0, "00087-Anatole France", "", 47.223627, -1.571323 },
	{ 1, 0, "00001-Prefecture", "5 Quai Ceineray", 47.220177, -1.554030 },
	{ 2, 0, "00002-Hôtel De Ville", "29 Rue De Strasbourg", 47.218846, -1.553431 },
	{ 3, 0, "00003-Strasbourg", "Place Tirant Lo Blanc", 47.216621, -1.551590 },
	{ 4, 0, "00004-Moulin", "18 Rue Du Moulin", 47.216582, -1.554324 },
	{ 5, 0, "00005-Brossard", "N° 12 Allee Duquesne", 47.218834, -1.556735 },
	{ 6, 0, "00006-Place Du Cirque", "7 Allee Duquesne", 47.217398, -1.556855 },
	{ 7, 0, "00007- Barillerie", "N° 2 Allee Penthievre", 47.215682, -1.556188 },
	{ 8, 0, "00008-Boucherie", "Face Au 4 Rue De La Boucherie", 47.216128, -1.557120 },
	{ 9, 0, "00009-Guepin", "N° 2 Rue Du Calvaire", 47.215820, -1.559027 },
	{ 11, 0, "00011-Calvaire", "Pl.Des Volontaires De La Defense Passive", 47.215546, -1.560739 },
	{ 12, 0, "00012-Place Delorme", "Place Delorme", 47.215119, -1.564039 },
	{ 13, 0, "00013-Bretagne Sud", "1 Rue Pierre Chéreau", 47.216998, -1.559615 },
	{ 14, 0, "00014-Bretagne Nord", "1 Rue Cassegrain", 47.218105, -1.558585 },
	{ 15, 0, "00015-Place Aristide Briand", "Place Aristide Briand", 47.217240, -1.563123 },
	{ 16, 0, "00016-Place Edouard Normand", "Face Au 7 Place Edouard Normand", 47.218876, -1.563480 },
	{ 17, 0, "00017-Sainte Elisabeth", "3 Place Saint Elisabeth", 47.219353, -1.561637 },
	{ 18, 0, "00018-Place Viarme", "53 Place Viarme", 47.221484, -1.563326 },
	{ 19, 0, "00019-Saint Similien", "1 Place Saint Similien", 47.219860, -1.558872 },
	{ 20, 0, "00020-Bellamy", "50 Rue Paul Bellamy", 47.222823, -1.557276 },
	{ 21, 0, "00021-Marche Talensac Sud", "Face Au 6 Rue Talensac", 47.221098, -1.556622 },
	{ 22, 0, "00022-Moquechien", "8 Rue Moquechien", 47.220264, -1.555464 },
	{ 23, 0, "00023-Buat", "Rue Du Général Buat", 47.227127, -1.542372 },
	{ 24, 0, "00024-Versailles", "25 Quai De Versailles", 47.224226, -1.553875 },
	{ 25, 0, "00025-Descartes", "Rue Descartes", 47.216262, -1.565404 },
	{ 26, 0, "00026-Guist'Hau Sud", "16 Boulevard De Guist'Hau", 47.216856, -1.567021 },
	{ 27, 0, "00027-Guist'Hau Nord", "42 Boulevard Guist'Hau", 47.217962, -1.569203 },
	{ 28, 0, "00028- Place De L'Edit Nantes", "Place De L'Edit De Nantes", 47.214386, -1.567594 },
	{ 29, 0, "00029-Duguay Trouin", "10 Allee Duguay Trouin", 47.213424, -1.555046 },
	{ 30, 0, "00030-Commerce", "Place Du Commerce", 47.213290, -1.557138 },
	{ 31, 0, "00031-Bourse", "Square De La Bourse", 47.212146, -1.559011 },
	{ 32, 0, "00032-Rubens", "Face 17 Rue Rubens", 47.214229, -1.560260 },
	{ 33, 0, "00033-Racine", "4 Rue Racine", 47.213669, -1.563233 },
	{ 34, 0, "00034-Mediatheque", "37 Quai De La Fosse", 47.211140, -1.561317 },
	{ 35, 0, "00035-Jean V", "2 Place Jean V", 47.212008, -1.565213 },
	{ 36, 0, "00036-Alger", "5 Rue D'Alger", 47.210544, -1.566706 },
	{ 37, 0, "00037-Feydeau", "Ile Feydeau", 47.211476, -1.556979 },
	{ 38, 0, "00038-Place Ricordeau", "Place Alexis Ricordeau", 47.211943, -1.553828 },
	{ 39, 0, "00039-Quai Moncousu", "11 Quai Moncousu", 47.209424, -1.555323 },
	{ 40, 0, "00040-Madeleine", "2 Quai Moncousu", 47.208859, -1.550722 },
	{ 41, 0, "00041-Chantier Naval", "87 Quai De La Fosse", 47.208390, -1.569668 },
	{ 42, 0, "00042-Gare Maritime", "Place Jacksonville", 47.207270, -1.571608 },
	{ 43, 0, "00043 - Machine De L'Île", "", 47.206152, -1.564191 },
	{ 44, 0, "00044-Palais De Justice", "19 Quai Francois Mitterand", 47.208334, -1.561192 },
	{ 45, 0, "00045-Prairie Au Duc", "Face Au 40 Boulevard De La Prairie Au Duc", 47.204709, -1.558945 },
	{ 46, 0, "00046-Place Republique", "3 Place De La Republique", 47.205522, -1.555119 },
	{ 47, 0, "00047- Martyrs Nantais", "1 Boulevard Des Martyrs Nantais", 47.207017, -1.548209 },
	{ 48, 0, "00048-Verdun", "15 Rue De Verdun", 47.217469, -1.551797 },
	{ 49, 0, "00049-Duchesse Anne", "2 Rue Henry Iv", 47.216648, -1.547309 },
	{ 50, 0, "00050-Chateau", "2 Rue Des Etats", 47.215092, -1.550171 },
	{ 51, 0, "00051-Bouffay", "Face Au 4 Place Bouffay", 47.214416, -1.553135 },
	{ 52, 0, "00052-Baco", "Face Au 8 Allee Baco", 47.214399, -1.548825 },
	{ 53, 0, "00053-Olivettes", "10 Rue Des Olivettes", 47.211560, -1.549967 },
	{ 54, 0, "00054- Cite Internationale Des Congres", "1 Bis Rue De Jemmapes", 47.213247, -1.545053 },
	{ 55, 0, "00055-Magellan", "11Rue De Belfort", 47.210640, -1.544111 },
	{ 56, 0, "00056-Vincent Gache", "9 Rue Francois Albert", 47.206736, -1.541819 },
	{ 57, 0, "00057-Gaetan Rondeau", "20 Rue Gaetan Rondeau", 47.205411, -1.537573 },
	{ 58, 0, "00058-Palais Des Sports", "21 Rue Viviani", 47.208393, -1.536203 },
	{ 59, 0, "00059-Stade Saupin", "35 Quai Malakoff", 47.213952, -1.539645 },
	{ 60, 0, "00060-Gare Sud", "12 Rue Lourmel", 47.215890, -1.542813 },
	{ 61, 0, "00061-Lu - Lieu Unique", "23 Quai Ferdinand Favre", 47.215530, -1.545999 },
	{ 62, 0, "00062-Gare Nord", "1 Place Charles Le Roux", 47.218114, -1.542300 },
	{ 63, 0, "00063-Jardin Des Plantes", "6 Rue Stanilas Baudry", 47.219775, -1.544575 },
	{ 64, 0, "00064-Saint Clement", "37 Rue Du Marechal Joffre", 47.221818, -1.547024 },
	{ 65, 0, "00065-Cours Sully", "9 Cours Sully", 47.222559, -1.551771 },
	{ 66, 0, "00066-Chanzy", "Face Au 23 Avenue De Chanzy", 47.225351, -1.547756 },
	{ 68, 0, "00068-Livet", "65 Rue Du Four", 47.224124, -1.545142 },
	{ 70, 0, "00070-Foch Cathedrale", "Rue De L'Eveche", 47.218843, -1.550324 },
	{ 71, 0, "00071-Marche Talensac Nord", "", 47.222134, -1.559289 },
	{ 72, 0, "00072-Felibien", "19 Rue De Felibien", 47.220712, -1.565372 },
	{ 73, 0, "00073-Sarradin", "4 Place Sarradin", 47.220914, -1.570582 },
	{ 74, 0, "00074-Canclaux", "8 Place Canclaux", 47.214254, -1.574947 },
	{ 75, 0, "00075-Lamoriciere", "Rue De Lamoriciere", 47.212352, -1.571279 },
	{ 76, 0, "00076-Place René Bouhier", "8 Place Rene Bouhier", 47.209729, -1.571087 },
	{ 78, 0, "00078-De Gaulle", "Boulevard De Gaulle", 47.208606, -1.540606 },
	{ 79, 0, "00079-Malakoff", "", 47.213256, -1.536753 },
	{ 67, 0, "00067-Place Waldeck Rousseau", "Place Waldeck Rousseau", 47.227735, -1.552121 },
	{ 80, 0, "00080 - Victor Hugo", "Angle Victor Hugo Bd Gustave Roch", 47.204055, -1.551351 },
	{ 83, 0, "00083-Millerand", "", 47.208138, -1.530118 },
	{ 84, 0, "00084-Région", "", 47.210649, -1.525898 },
	{ 77, 0, "00077-Ecole D'Architecture", "Quai F.Mitterand", 47.207542, -1.557724 },
	{ 69, 0, "00069 - Manufacture", "11 Bd Stalingrad", 47.219221, -1.536167 },
	{ 88, 0, "00088-Mellinet", "", 47.211451, -1.577135 },
	{ 89, 0, "00089-Saint-Aignan", "", 47.207438, -1.578612 },
	{ 81, 0, "00081 - Mangin", "", 47.200869, -1.545411 },
	{ 82, 0, "00082-Sebilleau", "", 47.206818, -1.532956 },
	{ 86, 0, "00086-Hauts Pavés", "", 47.225444, -1.567396 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateNantes : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateNantes() {
    rect = QRectF(QPointF(47.016842, -1.578612), QPointF(47.227735, -1.356745));
    center = QPointF(47.216842, -1.556744);
    statusUrl = "http://www.bicloo.nantesmetropole.fr/service/stationdetails/%1";
    infosUrl = "http://www.bicloo.nantesmetropole.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Nantes %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_NANTES_H */

