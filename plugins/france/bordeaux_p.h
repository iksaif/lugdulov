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
	{ 67, 0, "Allee De Serr  Abadie", "Allée Serr Face À L'Église Ste Marie", 44.84386, -0.55736 },
	{ 60, 0, "Allees De Chartres", "1 Allées De Chartres", 44.84717, -0.57127 },
	{ 112, 0, "Arts Et Metiers", "", 44.80591, -0.60232 },
	{ 138, 0, "Barbey", "9 Et 10 Place Dormoy", 44.82655, -0.56456 },
	{ 129, 0, "Barriere De Begles", "", 44.81319, -0.56436 },
	{ 48, 0, "Barriere De Pessac", "64 Et 66 Boulevard George V", 44.82598, -0.59008 },
	{ 130, 0, "Barriere De Toulouse", "2 Et 4 Boulevard Albert Ier Le Long D", 44.81459, -0.57248 },
	{ 33, 0, "Barriere Du Medoc", "195 Rue David Johston Et Face Au 157 R", 44.85348, -0.59271 },
	{ 109, 0, "Barriere St Genes", "274-276 Et 268-272 Cours De L'Argonne", 44.822, -0.58188 },
	{ 13, 0, "Barriere St Medard", "17 Avenue Charles De Gaulle", 44.84845, -0.59822 },
	{ 98, 0, "Bassins A Flot", "83 Quai De Bacalan", 44.86013, -0.5543 },
	{ 108, 0, "Bergonie", "Rue Grateloup Face À La Boulangerie", 44.82475, -0.57831 },
	{ 27, 0, "Bordeaux Ii", "A L'Entrée De L'Université Bordeaux 2", 44.82663, -0.60171 },
	{ 78, 0, "Bougnard", "", 44.79394, -0.6339 },
	{ 95, 0, "Bruges Hotel De Ville", "Avenue Du Général De Gaulle", 44.88171, -0.61286 },
	{ 70, 0, "Buttiniere", "", 44.86428, -0.52409 },
	{ 55, 0, "Camille Godard", "35-37 Rue Evrard De Fayolle", 44.85492, -0.57424 },
	{ 42, 0, "Camille Jullian", "31 Et 33 Rue Du Pas St Georges", 44.83918, -0.57205 },
	{ 59, 0, "Capc", "17 Quai Des Chartrons", 44.84974, -0.57026 },
	{ 133, 0, "Capucins", "30 Place Des Capucins", 44.82997, -0.56811 },
	{ 31, 0, "Cauderan", "9-11 Rue De L'Eglise", 44.85165, -0.61441 },
	{ 62, 0, "Cenon Gare", "", 44.85621, -0.53383 },
	{ 58, 0, "Chartrons", "73-74 Quai De Chartrons", 44.85316, -0.56731 },
	{ 11, 0, "Cite Administrative", "", 44.84158, -0.59969 },
	{ 97, 0, "Claveau", "101 Et 103 Rue Joseph Brunet", 44.87755, -0.54422 },
	{ 114, 0, "Compostelle", "", 44.79313, -0.60561 },
	{ 125, 0, "Conservatoire", "Face Au Conservatoire 22 Quai Ste Cro", 44.83181, -0.5597 },
	{ 132, 0, "Cours De La Somme", "118-120 Cours De La Somme", 44.8263, -0.57242 },
	{ 100, 0, "Cours Du Medoc", "119-121 Quai Des Chartrons", 44.85559, -0.56322 },
	{ 69, 0, "Cours Le Rouzic", "5 Place Calixte Camelle", 44.84299, -0.55036 },
	{ 122, 0, "Cours St Louis Medoc", "75 Et 77 Cours St Louis", 44.85863, -0.56969 },
	{ 115, 0, "Creps", "", 44.8009, -0.59653 },
	{ 117, 0, "Doyen Brus", "", 44.80058, -0.60949 },
	{ 14, 0, "Dubreuil / Turenne", "Rue De Lyon", 44.84843, -0.59208 },
	{ 113, 0, "Ecole De Management", "", 44.7968, -0.60195 },
	{ 57, 0, "Eglise St Louis", "9 Rue Sicard", 44.85158, -0.57162 },
	{ 136, 0, "Eglise Ste Croix", "", 44.83133, -0.56131 },
	{ 93, 0, "Eysines Centre", "", 44.88395, -0.6499 },
	{ 75, 0, "Ferdinand Buisson", "109 Bis - 111 Rue Durcy", 44.80365, -0.55839 },
	{ 90, 0, "Fontaine D'Arlac", "", 44.82662, -0.62606 },
	{ 110, 0, "Forum", "Angle Allée Du 7Ème Art Et Du Cours De", 44.81252, -0.59093 },
	{ 63, 0, "Francois Mitterrand", "", 44.83035, -0.5269 },
	{ 16, 0, "Galin", "Face À La Cloture Du Parc Relais Angl", 44.8496, -0.54483 },
	{ 80, 0, "Gare Alouette", "", 44.7922, -0.65908 },
	{ 66, 0, "Gare D'Orleans", "Quai De Queyries Face À La Gare D'Orl", 44.84131, -0.56245 },
	{ 94, 0, "Gare De Blanquefort", "", 44.91741, -0.62384 },
	{ 127, 0, "Gare St Jean", "Sortie Nord De La Gare Au Droit De La", 44.8263, -0.55705 },
	{ 9, 0, "Gavinies", "202 Et 206 Rue D'Ornano", 44.83301, -0.59285 },
	{ 12, 0, "Grand Lebrun", "", 44.85111, -0.60852 },
	{ 40, 0, "Grand Theatre", "37 Rue Esprit Des Lois", 44.84291, -0.57398 },
	{ 20, 0, "Grands Hommes", "1 Place Des Grands Hommes", 44.84319, -0.57728 },
	{ 104, 0, "Grosse Cloche", "12 Place De La Ferme Richemont En Face", 44.83505, -0.57206 },
	{ 22, 0, "Hotel De Ville", "12Bis Er 13 Place Pey Berland", 44.83825, -0.5765 },
	{ 18, 0, "Huguerie", "", 44.84425, -0.58162 },
	{ 37, 0, "Jardin Public", "60 Cours De Verdun", 44.84858, -0.5757 },
	{ 72, 0, "Jean Zay", "", 44.85424, -0.51339 },
	{ 87, 0, "Kennedy Parc Hotelier", "Rue Rudolf Diesel", 44.83622, -0.68707 },
	{ 81, 0, "L. Morin Cazalet", "", 44.79607, -0.667 },
	{ 64, 0, "La Benauge", "", 44.83962, -0.55623 },
	{ 82, 0, "La Chataigneraie", "", 44.7934, -0.6474 },
	{ 71, 0, "La Gardette", "", 44.88743, -0.51764 },
	{ 30, 0, "La Glaciere Mondesir", "313 Avenue D'Arès", 44.83833, -0.61597 },
	{ 49, 0, "Le Bouscat Mairie", "", 44.86497, -0.59999 },
	{ 118, 0, "Le Bouscat Ravezies", "", 44.86692, -0.57602 },
	{ 84, 0, "Le Burck", "110 Avenue Pierre Mendès France", 44.81546, -0.63439 },
	{ 96, 0, "Les Aubiers", "Entre La Station Tram Et Les Terminus", 44.87389, -0.57383 },
	{ 99, 0, "Les Hangars", "36-37 Quai De Bacalan", 44.85789, -0.55816 },
	{ 139, 0, "Lycee Bremontier", "", 44.82402, -0.57015 },
	{ 47, 0, "Magendie", "214-216 Rue Fernand Audeguil", 44.82789, -0.58603 },
	{ 91, 0, "Mairie Du Haillan", "", 44.87342, -0.67811 },
	{ 50, 0, "Mandron Godard", "40 Boulevard Godard", 44.8597, -0.58898 },
	{ 1, 0, "Meriadeck", "Rue Claude Bonnier Face À La Station", 44.83805, -0.58417 },
	{ 88, 0, "Merignac Capeyron", "26 Place Jean Jaurès", 44.8513, -0.64498 },
	{ 89, 0, "Merignac Centre", "", 44.84164, -0.64662 },
	{ 85, 0, "Merignac Quatre Chemins", "258 Avenue De La Marne", 44.83246, -0.64581 },
	{ 86, 0, "Merignac Soleil", "", 44.83268, -0.65632 },
	{ 116, 0, "Montaigne Montesquieu", "Le Long Du Muret De La Maison Des Étud", 44.79676, -0.6171 },
	{ 44, 0, "Musee D'Aquitaine", "16 Et 18 Cours Pasteur", 44.83598, -0.57542 },
	{ 131, 0, "Nansouty", "236-238 Cours De L'Yser", 44.82026, -0.5718 },
	{ 7, 0, "Palais De Justice", "16 Bis Cours Maréchal Juin", 44.83593, -0.58218 },
	{ 17, 0, "Palais Gallien", "", 44.84685, -0.58203 },
	{ 61, 0, "Parc Aux Angeliques", "Quai De Queyries Face À L'Allée Jean", 44.8463, -0.56496 },
	{ 32, 0, "Parc Bordelais", "67 Avenue Carnot", 44.85255, -0.59919 },
	{ 124, 0, "Parc Des Sports", "9 Et 10 Quai De La Monnaie", 44.83468, -0.56306 },
	{ 53, 0, "Parc Riviere", "236 Rue Camille Godard", 44.85428, -0.58576 },
	{ 8, 0, "Patinoire", "112 Cours Maréchal Juin", 44.83467, -0.58812 },
	{ 111, 0, "Peixotto", "Carrefour Avenue Roul - Cours De La Li", 44.80689, -0.59231 },
	{ 28, 0, "Pellegrin", "Place Amélie Rabba Léon Face Au 6 Rue", 44.83015, -0.60367 },
	{ 79, 0, "Pessac Bersol", "", 44.78622, -0.63859 },
	{ 83, 0, "Pessac Centre", "", 44.80457, -0.63208 },
	{ 46, 0, "Pl. Amedee Larrieu", "22 Et 23 Place Amédée Larrieu", 44.82993, -0.58142 },
	{ 137, 0, "Pl. Andre Meunier", "Place André Meunier Face À L'École De", 44.82881, -0.5628 },
	{ 77, 0, "Pl. Bernard Roumegoux", "", 44.77356, -0.61439 },
	{ 38, 0, "Pl. Charles Gruet", "9 Place Du Champ De Mars", 44.84653, -0.58019 },
	{ 36, 0, "Pl. De Longchamps", "2 Place De Longchamps", 44.85005, -0.58198 },
	{ 134, 0, "Pl. Du Maucaillou", "20 Place Du Maucaillou Et Face Au 61 R", 44.83264, -0.56715 },
	{ 43, 0, "Pl. Fernand Lafargue", "3 - 7 Rue Des Ayres", 44.83696, -0.57211 },
	{ 101, 0, "Pl. Jean Jaures", "2-5 Place Jean Jaurès", 44.84305, -0.57038 },
	{ 35, 0, "Pl. Marie Brizard", "209 - 213 Rue Fondaudège", 44.8501, -0.58576 },
	{ 56, 0, "Pl. Paul Doumer", "2 Et 3 Place Paul Doumer", 44.852, -0.574 },
	{ 45, 0, "Pl. Ste Eulalie", "2 Place Ste Eulalie", 44.83315, -0.57701 },
	{ 51, 0, "Place Ampere", "171 Boulevard Godard", 44.86286, -0.58327 },
	{ 52, 0, "Place De L'Europe", "Place De L'Europe Face À La Mairie An", 44.85891, -0.58107 },
	{ 102, 0, "Place De La Bourse", "1 Quai De La Douane Au Niveau De La C", 44.84024, -0.56914 },
	{ 106, 0, "Place De La Victoire", "23 Place De La Victoire", 44.83078, -0.57326 },
	{ 74, 0, "Place Du 14 Juillet", "Rue Calixte Camelle - Rue Du Mal De La", 44.8076, -0.54864 },
	{ 103, 0, "Place Du Palais", "40-46 Cours Alsace Et Lorraine", 44.83779, -0.57014 },
	{ 5, 0, "Place Gambetta", "Place Gambetta Face Au N 40", 44.84147, -0.58085 },
	{ 24, 0, "Place Rodesse", "Rue Belleville Au Niveau De L'Espace R", 44.83381, -0.58499 },
	{ 121, 0, "Place St Martial", "118 Cours E Vaillant", 44.8591, -0.5658 },
	{ 135, 0, "Place St Michel", "28-29-30 Et 31 Place Meynard", 44.83472, -0.56648 },
	{ 41, 0, "Place St Projet", "9 Rue Des Trois Conils", 44.83888, -0.57459 },
	{ 3, 0, "Place Tartas", "167 Rue Judaique", 44.8409, -0.59099 },
	{ 19, 0, "Place Tourny", "58-60 Allées De Tourny", 44.84462, -0.57747 },
	{ 76, 0, "Pont De La Maye", "", 44.78206, -0.5661 },
	{ 123, 0, "Porte De Bourgogne", "40-43 Quai Richelieu", 44.83781, -0.56717 },
	{ 126, 0, "Quai De Paludate", "82 Et 83 Quai De Paludate", 44.82669, -0.54981 },
	{ 39, 0, "Quinconces", "9 - 13 Cours Du 30 Juillet", 44.84423, -0.57421 },
	{ 23, 0, "Republique", "Face Aux Monuments Aux Morts Entre Le", 44.83483, -0.58023 },
	{ 15, 0, "Rue De La Croix Blanche", "", 44.84521, -0.592 },
	{ 105, 0, "Rue Du Mirail", "57 Et 59 Rue Du Mirail", 44.83269, -0.571 },
	{ 25, 0, "Rue F. De Sourdis", "Rue François De Sourdis", 44.83103, -0.58737 },
	{ 54, 0, "Rue St Vincent De Paul", "", 44.82677, -0.55758 },
	{ 128, 0, "Sacre Coeur", "Place Cardinal Donnet Face Au 110-114", 44.82217, -0.5631 },
	{ 120, 0, "Saint Louis Haussmann", "196 Cours St Louis", 44.86258, -0.5672 },
	{ 6, 0, "Square A. Lhote", "Square André Lhote", 44.83811, -0.5817 },
	{ 29, 0, "St Augustin", "Place De L'Eglise St Augustin Façade", 44.83248, -0.61049 },
	{ 2, 0, "St Bruno", "Rue Henri Labit", 44.83785, -0.59026 },
	{ 21, 0, "St Christoly", "5-9 Rue Beaubadat", 44.83923, -0.57754 },
	{ 92, 0, "St Medard Republique", "", 44.89511, -0.71403 },
	{ 107, 0, "St Nicolas", "20 Et 22 Rue Brian", 44.82752, -0.57593 },
	{ 4, 0, "St Seurin", "", 44.84224, -0.58504 },
	{ 10, 0, "Stade Chaban Delmas", "113-115 Boulevard Antoine Gautier", 44.83152, -0.59864 },
	{ 65, 0, "Stalingrad", "7 Et 9 Place De Stalingrad", 44.84035, -0.55953 },
	{ 73, 0, "Terres Neuves", "297-299 Boulevard Jj Bosc", 44.81567, -0.55095 },
	{ 68, 0, "Thiers Jardin Botanique", "73 Avenue Thiers Devant Le Crédit Mut", 44.84293, -0.55573 },
	{ 34, 0, "Tivoli", "9 Au 13 Rue De Tivoli", 44.85362, -0.58852 },
	{ 119, 0, "Tram Station Grd Parc", "Rue Julien Manes", 44.86271, -0.57557 },
	{ 26, 0, "Xaintrailles", "", 44.82798, -0.59353 },
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

