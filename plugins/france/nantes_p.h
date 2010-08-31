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
	{ 85, 0, "00085-Bel Air", "", 47.2258562443, -1.55948040936 },
	{ 87, 0, "00087-Anatole France", "", 47.2236269898, -1.57132257891 },
	{ 2, 0, "00002-Hôtel De Ville", "29 Rue De Strasbourg", 47.2188462472, -1.55343087729 },
	{ 3, 0, "00003-Strasbourg", "Place Tirant Lo Blanc", 47.2166206725, -1.55159023806 },
	{ 4, 0, "00004-Moulin", "18 Rue Du Moulin", 47.2165824543, -1.55432379587 },
	{ 5, 0, "00005-Brossard", "N° 12 Allee Duquesne", 47.2188337539, -1.5567348651 },
	{ 6, 0, "00006-Place Du Cirque", "7 Allee Duquesne", 47.2173976323, -1.55685507982 },
	{ 7, 0, "00007- Barillerie", "N° 2 Allee Penthievre", 47.2156818709, -1.55618824552 },
	{ 8, 0, "00008-Boucherie", "Face Au 4 Rue De La Boucherie", 47.2161277618, -1.55711957672 },
	{ 9, 0, "00009-Guepin", "N° 2 Rue Du Calvaire", 47.2158201151, -1.55902714089 },
	{ 11, 0, "00011-Calvaire", "Pl.Des Volontaires De La Defense Passive", 47.2155460798, -1.56073885173 },
	{ 12, 0, "00012-Place Delorme", "Place Delorme", 47.2151191954, -1.56403887464 },
	{ 13, 0, "00013-Bretagne Sud", "1 Rue Pierre Chéreau", 47.2169981234, -1.5596152476 },
	{ 14, 0, "00014-Bretagne Nord", "1 Rue Cassegrain", 47.2181047305, -1.55858540777 },
	{ 15, 0, "00015-Place Aristide Briand", "Place Aristide Briand", 47.217239758, -1.56312272572 },
	{ 16, 0, "00016-Place Edouard Normand", "Face Au 7 Place Edouard Normand", 47.2188758973, -1.56347994716 },
	{ 17, 0, "00017-Sainte Elisabeth", "3 Place Saint Elisabeth", 47.2193525396, -1.56163748769 },
	{ 18, 0, "00018-Place Viarme", "53 Place Viarme", 47.221484031, -1.5633263676 },
	{ 19, 0, "00019-Saint Similien", "1 Place Saint Similien", 47.2198603571, -1.55887187704 },
	{ 20, 0, "00020-Bellamy", "50 Rue Paul Bellamy", 47.2228234237, -1.55727643048 },
	{ 21, 0, "00021-Marche Talensac Sud", "Face Au 6 Rue Talensac", 47.2210982376, -1.55662204898 },
	{ 22, 0, "00022-Moquechien", "8 Rue Moquechien", 47.2202637021, -1.5554640594 },
	{ 23, 0, "00023-Buat", "Rue Du Général Buat", 47.2271267672, -1.54237165341 },
	{ 24, 0, "00024-Versailles", "25 Quai De Versailles", 47.2242262355, -1.55387500221 },
	{ 25, 0, "00025-Descartes", "Rue Descartes", 47.2162618544, -1.565404431 },
	{ 26, 0, "00026-Guist'Hau Sud", "16 Boulevard De Guist'Hau", 47.2168555991, -1.5670208197 },
	{ 27, 0, "00027-Guist'Hau Nord", "42 Boulevard Guist'Hau", 47.2179615323, -1.56920341388 },
	{ 28, 0, "00028- Place De L'Edit Nantes", "Place De L'Edit De Nantes", 47.2143863461, -1.56759411646 },
	{ 29, 0, "00029-Duguay Trouin", "10 Allee Duguay Trouin", 47.2134237551, -1.55504579796 },
	{ 30, 0, "00030-Commerce", "Place Du Commerce", 47.2132900426, -1.55713776991 },
	{ 31, 0, "00031-Bourse", "Square De La Bourse", 47.2121459376, -1.5590107663 },
	{ 32, 0, "00032-Rubens", "Face 17 Rue Rubens", 47.2142292952, -1.56025959472 },
	{ 33, 0, "00033-Racine", "4 Rue Racine", 47.2136693814, -1.56323260081 },
	{ 34, 0, "00034-Mediatheque", "37 Quai De La Fosse", 47.2111402682, -1.56131673654 },
	{ 35, 0, "00035-Jean V", "2 Place Jean V", 47.2120081474, -1.56521317453 },
	{ 36, 0, "00036-Alger", "5 Rue D'Alger", 47.2105435422, -1.56670570381 },
	{ 37, 0, "00037-Feydeau", "Ile Feydeau", 47.2114760455, -1.55697932352 },
	{ 38, 0, "00038-Place Ricordeau", "Place Alexis Ricordeau", 47.2119427549, -1.55382777574 },
	{ 39, 0, "00039-Quai Moncousu", "11 Quai Moncousu", 47.2094244256, -1.55532326309 },
	{ 40, 0, "00040-Madeleine", "2 Quai Moncousu", 47.2088592015, -1.55072224955 },
	{ 41, 0, "00041-Chantier Naval", "87 Quai De La Fosse", 47.2083896238, -1.56966781856 },
	{ 42, 0, "00042-Gare Maritime", "Place Jacksonville", 47.2072700314, -1.57160826557 },
	{ 43, 0, "00043 - Machine De L'Île", "", 47.2061523329, -1.56419144053 },
	{ 44, 0, "00044-Palais De Justice", "19 Quai Francois Mitterand", 47.2083344038, -1.56119163908 },
	{ 45, 0, "00045-Prairie Au Duc", "Face Au 40 Boulevard De La Prairie Au Duc", 47.2047086159, -1.55894511584 },
	{ 46, 0, "00046-Place Republique", "3 Place De La Republique", 47.2055224294, -1.5551187637 },
	{ 47, 0, "00047- Martyrs Nantais", "1 Boulevard Des Martyrs Nantais", 47.2070165243, -1.54820939239 },
	{ 48, 0, "00048-Verdun", "15 Rue De Verdun", 47.2174693167, -1.55179732711 },
	{ 49, 0, "00049-Duchesse Anne", "2 Rue Henry Iv", 47.2166479394, -1.54730926421 },
	{ 50, 0, "00050-Chateau", "2 Rue Des Etats", 47.2150924006, -1.55017052755 },
	{ 51, 0, "00051-Bouffay", "Face Au 4 Place Bouffay", 47.214415947, -1.55313519535 },
	{ 52, 0, "00052-Baco", "Face Au 8 Allee Baco", 47.2143992373, -1.5488247638 },
	{ 53, 0, "00053-Olivettes", "10 Rue Des Olivettes", 47.2115596615, -1.54996676918 },
	{ 54, 0, "00054- Cite Internationale Des Congres", "1 Bis Rue De Jemmapes", 47.2132473951, -1.54505325621 },
	{ 55, 0, "00055-Magellan", "11Rue De Belfort", 47.2106402013, -1.5441107184 },
	{ 56, 0, "00056-Vincent Gache", "9 Rue Francois Albert", 47.2067364453, -1.54181869829 },
	{ 57, 0, "00057-Gaetan Rondeau", "20 Rue Gaetan Rondeau", 47.2054112085, -1.5375727781 },
	{ 58, 0, "00058-Palais Des Sports", "21 Rue Viviani", 47.2083934143, -1.5362026757 },
	{ 59, 0, "00059-Stade Saupin", "35 Quai Malakoff", 47.2139518122, -1.53964521488 },
	{ 60, 0, "00060-Gare Sud", "12 Rue Lourmel", 47.2158897239, -1.54281271287 },
	{ 61, 0, "00061-Lu - Lieu Unique", "23 Quai Ferdinand Favre", 47.2155302433, -1.54599878599 },
	{ 62, 0, "00062-Gare Nord", "1 Place Charles Le Roux", 47.2181136037, -1.54229979172 },
	{ 63, 0, "00063-Jardin Des Plantes", "6 Rue Stanilas Baudry", 47.2197752758, -1.54457508928 },
	{ 64, 0, "00064-Saint Clement", "37 Rue Du Marechal Joffre", 47.2218183531, -1.54702364232 },
	{ 65, 0, "00065-Cours Sully", "9 Cours Sully", 47.2225589653, -1.55177067274 },
	{ 66, 0, "00066-Chanzy", "Face Au 23 Avenue De Chanzy", 47.2253512786, -1.54775610474 },
	{ 68, 0, "00068-Livet", "65 Rue Du Four", 47.2241243866, -1.54514183724 },
	{ 70, 0, "00070-Foch Cathedrale", "Rue De L'Eveche", 47.2188429902, -1.55032404372 },
	{ 71, 0, "00071-Marche Talensac Nord", "", 47.222133966, -1.55928863083 },
	{ 72, 0, "00072-Felibien", "19 Rue De Felibien", 47.2207122674, -1.56537210446 },
	{ 73, 0, "00073-Sarradin", "4 Place Sarradin", 47.2209140367, -1.5705823627 },
	{ 74, 0, "00074-Canclaux", "8 Place Canclaux", 47.2142540844, -1.57494721937 },
	{ 75, 0, "00075-Lamoriciere", "Rue De Lamoriciere", 47.2123520159, -1.57127892086 },
	{ 76, 0, "00076-Place René Bouhier", "8 Place Rene Bouhier", 47.2097285367, -1.57108731317 },
	{ 78, 0, "00078-De Gaulle", "Boulevard De Gaulle", 47.2086055973, -1.54060605107 },
	{ 79, 0, "00079-Malakoff", "", 47.2132564824, -1.53675295475 },
	{ 67, 0, "00067-Place Waldeck Rousseau", "Place Waldeck Rousseau", 47.2277349784, -1.5521205013 },
	{ 80, 0, "00080 - Victor Hugo", "Angle Victor Hugo Bd Gustave Roch", 47.2040554375, -1.55135126573 },
	{ 83, 0, "00083-Millerand", "", 47.2081384334, -1.53011772673 },
	{ 84, 0, "00084-Région", "", 47.2106486801, -1.52589775912 },
	{ 77, 0, "00077-Ecole D'Architecture", "Quai F.Mitterand", 47.2075419755, -1.55772397228 },
	{ 69, 0, "00069 - Manufacture", "11 Bd Stalingrad", 47.2192205087, -1.53616686134 },
	{ 88, 0, "00088-Mellinet", "", 47.2114507531, -1.57713472346 },
	{ 89, 0, "00089-Saint-Aignan", "", 47.2074375612, -1.57861226279 },
	{ 82, 0, "00082-Sebilleau", "", 47.2068182488, -1.53295637446 },
	{ 86, 0, "00086-Hauts Pavés", "", 47.2254442962, -1.56739639776 },
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

