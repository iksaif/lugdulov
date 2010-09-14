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

#ifndef STATIONS_SIMPLE_PRIVATE_BORDEAUX_H
#define STATIONS_SIMPLE_PRIVATE_BORDEAUX_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 67, 0, "Allee De Serr  Abadie", "Allée Serr Face À L'Église Ste Marie", 44.843860, -0.557360 },
	{ 60, 0, "Allees De Chartres", "1 Allées De Chartres", 44.847170, -0.571270 },
	{ 112, 0, "Arts Et Metiers", "", 44.805910, -0.602320 },
	{ 138, 0, "Barbey", "9 Et 10 Place Dormoy", 44.826550, -0.564560 },
	{ 129, 0, "Barriere De Begles", "", 44.813190, -0.564360 },
	{ 48, 0, "Barriere De Pessac", "64 Et 66 Boulevard George V", 44.825980, -0.590080 },
	{ 130, 0, "Barriere De Toulouse", "2 Et 4 Boulevard Albert Ier Le Long D", 44.814590, -0.572480 },
	{ 33, 0, "Barriere Du Medoc", "195 Rue David Johston Et Face Au 157 R", 44.853480, -0.592710 },
	{ 109, 0, "Barriere St Genes", "274-276 Et 268-272 Cours De L'Argonne", 44.822000, -0.581880 },
	{ 13, 0, "Barriere St Medard", "17 Avenue Charles De Gaulle", 44.848450, -0.598220 },
	{ 98, 0, "Bassins A Flot", "83 Quai De Bacalan", 44.860130, -0.554300 },
	{ 108, 0, "Bergonie", "Rue Grateloup Face À La Boulangerie", 44.824750, -0.578310 },
	{ 27, 0, "Bordeaux Ii", "A L'Entrée De L'Université Bordeaux 2", 44.826630, -0.601710 },
	{ 78, 0, "Bougnard", "", 44.793940, -0.633900 },
	{ 95, 0, "Bruges Hotel De Ville", "Avenue Du Général De Gaulle", 44.881710, -0.612860 },
	{ 70, 0, "Buttiniere", "", 44.864280, -0.524090 },
	{ 55, 0, "Camille Godard", "35-37 Rue Evrard De Fayolle", 44.854920, -0.574240 },
	{ 42, 0, "Camille Jullian", "31 Et 33 Rue Du Pas St Georges", 44.839180, -0.572050 },
	{ 59, 0, "Capc", "17 Quai Des Chartrons", 44.849740, -0.570260 },
	{ 133, 0, "Capucins", "30 Place Des Capucins", 44.829970, -0.568110 },
	{ 31, 0, "Cauderan", "9-11 Rue De L'Eglise", 44.851650, -0.614410 },
	{ 62, 0, "Cenon Gare", "", 44.856210, -0.533830 },
	{ 58, 0, "Chartrons", "73-74 Quai De Chartrons", 44.853160, -0.567310 },
	{ 11, 0, "Cite Administrative", "", 44.841580, -0.599690 },
	{ 97, 0, "Claveau", "101 Et 103 Rue Joseph Brunet", 44.877550, -0.544220 },
	{ 114, 0, "Compostelle", "", 44.793130, -0.605610 },
	{ 125, 0, "Conservatoire", "Face Au Conservatoire 22 Quai Ste Cro", 44.831810, -0.559700 },
	{ 132, 0, "Cours De La Somme", "118-120 Cours De La Somme", 44.826300, -0.572420 },
	{ 100, 0, "Cours Du Medoc", "119-121 Quai Des Chartrons", 44.855590, -0.563220 },
	{ 69, 0, "Cours Le Rouzic", "5 Place Calixte Camelle", 44.842990, -0.550360 },
	{ 122, 0, "Cours St Louis Medoc", "75 Et 77 Cours St Louis", 44.858630, -0.569690 },
	{ 115, 0, "Creps", "", 44.800900, -0.596530 },
	{ 117, 0, "Doyen Brus", "", 44.800580, -0.609490 },
	{ 14, 0, "Dubreuil / Turenne", "Rue De Lyon", 44.848430, -0.592080 },
	{ 113, 0, "Ecole De Management", "", 44.796800, -0.601950 },
	{ 57, 0, "Eglise St Louis", "9 Rue Sicard", 44.851580, -0.571620 },
	{ 136, 0, "Eglise Ste Croix", "", 44.831330, -0.561310 },
	{ 93, 0, "Eysines Centre", "", 44.883950, -0.649900 },
	{ 75, 0, "Ferdinand Buisson", "109 Bis - 111 Rue Durcy", 44.803650, -0.558390 },
	{ 90, 0, "Fontaine D'Arlac", "", 44.826620, -0.626060 },
	{ 110, 0, "Forum", "Angle Allée Du 7Ème Art Et Du Cours De", 44.812520, -0.590930 },
	{ 63, 0, "Francois Mitterrand", "", 44.830350, -0.526900 },
	{ 16, 0, "Galin", "Face À La Cloture Du Parc Relais Angl", 44.849600, -0.544830 },
	{ 80, 0, "Gare Alouette", "", 44.792200, -0.659080 },
	{ 66, 0, "Gare D'Orleans", "Quai De Queyries Face À La Gare D'Orl", 44.841310, -0.562450 },
	{ 94, 0, "Gare De Blanquefort", "", 44.917410, -0.623840 },
	{ 127, 0, "Gare St Jean", "Sortie Nord De La Gare Au Droit De La", 44.826300, -0.557050 },
	{ 9, 0, "Gavinies", "202 Et 206 Rue D'Ornano", 44.833010, -0.592850 },
	{ 12, 0, "Grand Lebrun", "", 44.851110, -0.608520 },
	{ 40, 0, "Grand Theatre", "37 Rue Esprit Des Lois", 44.842910, -0.573980 },
	{ 20, 0, "Grands Hommes", "1 Place Des Grands Hommes", 44.843190, -0.577280 },
	{ 104, 0, "Grosse Cloche", "12 Place De La Ferme Richemont En Face", 44.835050, -0.572060 },
	{ 22, 0, "Hotel De Ville", "12Bis Er 13 Place Pey Berland", 44.838250, -0.576500 },
	{ 18, 0, "Huguerie", "", 44.844250, -0.581620 },
	{ 37, 0, "Jardin Public", "60 Cours De Verdun", 44.848580, -0.575700 },
	{ 72, 0, "Jean Zay", "", 44.854240, -0.513390 },
	{ 87, 0, "Kennedy Parc Hotelier", "Rue Rudolf Diesel", 44.836220, -0.687070 },
	{ 81, 0, "L. Morin Cazalet", "", 44.796070, -0.667000 },
	{ 64, 0, "La Benauge", "", 44.839620, -0.556230 },
	{ 82, 0, "La Chataigneraie", "", 44.793400, -0.647400 },
	{ 71, 0, "La Gardette", "", 44.887430, -0.517640 },
	{ 30, 0, "La Glaciere Mondesir", "313 Avenue D'Arès", 44.838330, -0.615970 },
	{ 49, 0, "Le Bouscat Mairie", "", 44.864970, -0.599990 },
	{ 118, 0, "Le Bouscat Ravezies", "", 44.866920, -0.576020 },
	{ 84, 0, "Le Burck", "110 Avenue Pierre Mendès France", 44.815460, -0.634390 },
	{ 96, 0, "Les Aubiers", "Entre La Station Tram Et Les Terminus", 44.873890, -0.573830 },
	{ 99, 0, "Les Hangars", "36-37 Quai De Bacalan", 44.857890, -0.558160 },
	{ 139, 0, "Lycee Bremontier", "", 44.824020, -0.570150 },
	{ 47, 0, "Magendie", "214-216 Rue Fernand Audeguil", 44.827890, -0.586030 },
	{ 91, 0, "Mairie Du Haillan", "", 44.873420, -0.678110 },
	{ 50, 0, "Mandron Godard", "40 Boulevard Godard", 44.859700, -0.588980 },
	{ 1, 0, "Meriadeck", "Rue Claude Bonnier Face À La Station", 44.838050, -0.584170 },
	{ 88, 0, "Merignac Capeyron", "26 Place Jean Jaurès", 44.851300, -0.644980 },
	{ 89, 0, "Merignac Centre", "", 44.841640, -0.646620 },
	{ 85, 0, "Merignac Quatre Chemins", "258 Avenue De La Marne", 44.832460, -0.645810 },
	{ 86, 0, "Merignac Soleil", "", 44.832680, -0.656320 },
	{ 116, 0, "Montaigne Montesquieu", "Le Long Du Muret De La Maison Des Étud", 44.796760, -0.617100 },
	{ 44, 0, "Musee D'Aquitaine", "16 Et 18 Cours Pasteur", 44.835980, -0.575420 },
	{ 131, 0, "Nansouty", "236-238 Cours De L'Yser", 44.820260, -0.571800 },
	{ 7, 0, "Palais De Justice", "16 Bis Cours Maréchal Juin", 44.835930, -0.582180 },
	{ 17, 0, "Palais Gallien", "", 44.846850, -0.582030 },
	{ 61, 0, "Parc Aux Angeliques", "Quai De Queyries Face À L'Allée Jean", 44.846300, -0.564960 },
	{ 32, 0, "Parc Bordelais", "67 Avenue Carnot", 44.852550, -0.599190 },
	{ 124, 0, "Parc Des Sports", "9 Et 10 Quai De La Monnaie", 44.834680, -0.563060 },
	{ 53, 0, "Parc Riviere", "236 Rue Camille Godard", 44.854280, -0.585760 },
	{ 8, 0, "Patinoire", "112 Cours Maréchal Juin", 44.834670, -0.588120 },
	{ 111, 0, "Peixotto", "Carrefour Avenue Roul - Cours De La Li", 44.806890, -0.592310 },
	{ 28, 0, "Pellegrin", "Place Amélie Rabba Léon Face Au 6 Rue", 44.830150, -0.603670 },
	{ 79, 0, "Pessac Bersol", "", 44.786220, -0.638590 },
	{ 83, 0, "Pessac Centre", "", 44.804570, -0.632080 },
	{ 46, 0, "Pl. Amedee Larrieu", "22 Et 23 Place Amédée Larrieu", 44.829930, -0.581420 },
	{ 137, 0, "Pl. Andre Meunier", "Place André Meunier Face À L'École De", 44.828810, -0.562800 },
	{ 77, 0, "Pl. Bernard Roumegoux", "", 44.773560, -0.614390 },
	{ 38, 0, "Pl. Charles Gruet", "9 Place Du Champ De Mars", 44.846530, -0.580190 },
	{ 36, 0, "Pl. De Longchamps", "2 Place De Longchamps", 44.850050, -0.581980 },
	{ 134, 0, "Pl. Du Maucaillou", "20 Place Du Maucaillou Et Face Au 61 R", 44.832640, -0.567150 },
	{ 43, 0, "Pl. Fernand Lafargue", "3 - 7 Rue Des Ayres", 44.836960, -0.572110 },
	{ 101, 0, "Pl. Jean Jaures", "2-5 Place Jean Jaurès", 44.843050, -0.570380 },
	{ 35, 0, "Pl. Marie Brizard", "209 - 213 Rue Fondaudège", 44.850100, -0.585760 },
	{ 56, 0, "Pl. Paul Doumer", "2 Et 3 Place Paul Doumer", 44.852000, -0.574000 },
	{ 45, 0, "Pl. Ste Eulalie", "2 Place Ste Eulalie", 44.833150, -0.577010 },
	{ 51, 0, "Place Ampere", "171 Boulevard Godard", 44.862860, -0.583270 },
	{ 52, 0, "Place De L'Europe", "Place De L'Europe Face À La Mairie An", 44.858910, -0.581070 },
	{ 102, 0, "Place De La Bourse", "1 Quai De La Douane Au Niveau De La C", 44.840240, -0.569140 },
	{ 106, 0, "Place De La Victoire", "23 Place De La Victoire", 44.830780, -0.573260 },
	{ 74, 0, "Place Du 14 Juillet", "Rue Calixte Camelle - Rue Du Mal De La", 44.807600, -0.548640 },
	{ 103, 0, "Place Du Palais", "40-46 Cours Alsace Et Lorraine", 44.837790, -0.570140 },
	{ 5, 0, "Place Gambetta", "Place Gambetta Face Au N 40", 44.841470, -0.580850 },
	{ 24, 0, "Place Rodesse", "Rue Belleville Au Niveau De L'Espace R", 44.833810, -0.584990 },
	{ 121, 0, "Place St Martial", "118 Cours E Vaillant", 44.859100, -0.565800 },
	{ 135, 0, "Place St Michel", "28-29-30 Et 31 Place Meynard", 44.834720, -0.566480 },
	{ 41, 0, "Place St Projet", "9 Rue Des Trois Conils", 44.838880, -0.574590 },
	{ 3, 0, "Place Tartas", "167 Rue Judaique", 44.840900, -0.590990 },
	{ 19, 0, "Place Tourny", "58-60 Allées De Tourny", 44.844620, -0.577470 },
	{ 76, 0, "Pont De La Maye", "", 44.782060, -0.566100 },
	{ 123, 0, "Porte De Bourgogne", "40-43 Quai Richelieu", 44.837810, -0.567170 },
	{ 126, 0, "Quai De Paludate", "82 Et 83 Quai De Paludate", 44.826690, -0.549810 },
	{ 39, 0, "Quinconces", "9 - 13 Cours Du 30 Juillet", 44.844230, -0.574210 },
	{ 23, 0, "Republique", "Face Aux Monuments Aux Morts Entre Le", 44.834830, -0.580230 },
	{ 15, 0, "Rue De La Croix Blanche", "", 44.845210, -0.592000 },
	{ 105, 0, "Rue Du Mirail", "57 Et 59 Rue Du Mirail", 44.832690, -0.571000 },
	{ 25, 0, "Rue F. De Sourdis", "Rue François De Sourdis", 44.831030, -0.587370 },
	{ 54, 0, "Rue St Vincent De Paul", "", 44.826770, -0.557580 },
	{ 128, 0, "Sacre Coeur", "Place Cardinal Donnet Face Au 110-114", 44.822170, -0.563100 },
	{ 120, 0, "Saint Louis Haussmann", "196 Cours St Louis", 44.862580, -0.567200 },
	{ 6, 0, "Square A. Lhote", "Square André Lhote", 44.838110, -0.581700 },
	{ 29, 0, "St Augustin", "Place De L'Eglise St Augustin Façade", 44.832480, -0.610490 },
	{ 2, 0, "St Bruno", "Rue Henri Labit", 44.837850, -0.590260 },
	{ 21, 0, "St Christoly", "5-9 Rue Beaubadat", 44.839230, -0.577540 },
	{ 92, 0, "St Medard Republique", "", 44.895110, -0.714030 },
	{ 107, 0, "St Nicolas", "20 Et 22 Rue Brian", 44.827520, -0.575930 },
	{ 4, 0, "St Seurin", "", 44.842240, -0.585040 },
	{ 10, 0, "Stade Chaban Delmas", "113-115 Boulevard Antoine Gautier", 44.831520, -0.598640 },
	{ 65, 0, "Stalingrad", "7 Et 9 Place De Stalingrad", 44.840350, -0.559530 },
	{ 73, 0, "Terres Neuves", "297-299 Boulevard Jj Bosc", 44.815670, -0.550950 },
	{ 68, 0, "Thiers Jardin Botanique", "73 Avenue Thiers Devant Le Crédit Mut", 44.842930, -0.555730 },
	{ 34, 0, "Tivoli", "9 Au 13 Rue De Tivoli", 44.853620, -0.588520 },
	{ 119, 0, "Tram Station Grd Parc", "Rue Julien Manes", 44.862710, -0.575570 },
	{ 26, 0, "Xaintrailles", "", 44.827980, -0.593530 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBordeaux : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBordeaux() {
    rect = QRectF(QPointF(44.637368, -0.776144), QPointF(45.037368, -0.376144));
    center = QPointF(44.837368, -0.576144);
    statusUrl = "";
    infosUrl = "http://www.vcub.fr/stations/plan";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Bordeaux %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_BORDEAUX_H */

