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

#ifndef STATIONS_SIMPLE_PRIVATE_TOULOUSE_H
#define STATIONS_SIMPLE_PRIVATE_TOULOUSE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "00001 - Poids De L'Huile", "12 Rue Du Poids De L'Huile", 43.604135, 1.445421 },
	{ 2, 0, "00002 - Lafayette", "21 Rue Lafayette", 43.604853, 1.445286 },
	{ 3, 0, "00003 - Pomme", "62 Rue De La Pomme", 43.603336, 1.445569 },
	{ 6, 0, "00006 - Lois", "5 Rue Des Lois", 43.605204, 1.442101 },
	{ 7, 0, "00007 - Place Victor Hugo", "6 Rue Du Rempart Villeneuve", 43.605852, 1.446594 },
	{ 8, 0, "00008 - Espace Saint Georges", "19 Rue Paul Vidal", 43.603078, 1.448047 },
	{ 10, 0, "00010 - Place Esquirol", "15 Pl Etienne Esquirol", 43.600378, 1.445442 },
	{ 11, 0, "00011 - Place De La Daurade", "2 Pl De La Daurade", 43.601237, 1.439517 },
	{ 12, 0, "00012 - Pargaminieres", "66 Rue Pargaminieres", 43.604659, 1.440366 },
	{ 13, 0, "00013 - Lois Esquile", "1 Rue De L Esquile", 43.606213, 1.441331 },
	{ 14, 0, "00014 - Perigord", "26 Rue De Perigord", 43.607352, 1.444270 },
	{ 16, 0, "00016 - Strasbourg Bayard", "32 Bd De Strasbourg", 43.607938, 1.446611 },
	{ 17, 0, "00017 - Strasbourg Sardane", "7 Bd De Strasbourg", 43.606107, 1.448062 },
	{ 18, 0, "00018 - Strasbourg Jean Jaures", "4 Bd De Strasbourg", 43.606297, 1.448244 },
	{ 19, 0, "00019 - Carnot Peri", "62 Bd Lazare Carnot", 43.605576, 1.449072 },
	{ 20, 0, "00020 - Carnot Trois Journees", "69 Bd Lazare Carnot", 43.604718, 1.449630 },
	{ 21, 0, "00021 - Carnot Labeda", "63 Bd Lazare Carnot", 43.604111, 1.450245 },
	{ 22, 0, "00022 - Carnot Roland", "24 Bd Lazare Carnot", 43.602220, 1.451957 },
	{ 23, 0, "00023 - Combattants", "6 Bd Lazare Carnot", 43.601286, 1.452058 },
	{ 24, 0, "00024 - Place Saint Etienne", "14 Pl Saint Etienne", 43.600399, 1.450179 },
	{ 25, 0, "00025 - Place Rouaix", "1 Rue Des Tourneurs", 43.599435, 1.445581 },
	{ 26, 0, "00026 - Dalbade - De Gorsse", "9 Rue Henry De Gorsse", 43.598048, 1.443005 },
	{ 27, 0, "00027 - Quai De Tounis", "Quai De Tounis", 43.599384, 1.440461 },
	{ 28, 0, "00028 - Place Saint Pierre", "6 Pl Saint Pierre", 43.603437, 1.436081 },
	{ 29, 0, "00029 - Valade", "31 Rue Valade", 43.605072, 1.437032 },
	{ 30, 0, "00030 - Place Anatole France", "40 Pl Anatole France", 43.606295, 1.438225 },
	{ 31, 0, "00031 - Salenques", "7 Rue Des Salenques", 43.607490, 1.439221 },
	{ 32, 0, "00032 - Musee St Raymond", "8 Rue Des Trois Renards", 43.607650, 1.441210 },
	{ 33, 0, "00033 - Beraldi", "11 Rue Henri Beraldi", 43.608569, 1.443570 },
	{ 34, 0, "00034 - Saint Lazare", "2 Petite Rue Saint Lazare", 43.609650, 1.446077 },
	{ 35, 0, "00035 - Place Jeanne D'Arc", "1 Rue Raymond Iv", 43.608519, 1.446218 },
	{ 39, 0, "00039 - Place Damloup", "9 Pl De Damloup", 43.605832, 1.452940 },
	{ 42, 0, "00042 - Dauriac Escande", "3 Bd Pr Leopold Escande", 43.601588, 1.456048 },
	{ 43, 0, "00043 - Dupuy", "14 Pl Dominique Martin Dupuy", 43.599990, 1.454094 },
	{ 44, 0, "00044 - Palais Niel", "1 All Forain Francois Verdier", 43.598003, 1.451750 },
	{ 45, 0, "00045 - Ozenne", "10 Rue Theodore Ozenne", 43.596328, 1.447014 },
	{ 46, 0, "00046 - Place Des Carmes", "1 Pl Des Carmes", 43.597401, 1.445316 },
	{ 47, 0, "00047 - Nazareth Languedoc", "12 Rue Du Languedoc", 43.595462, 1.445531 },
	{ 48, 0, "00048 - Place Du Salin", "18 Pl Du Salin", 43.594749, 1.444133 },
	{ 50, 0, "00050 - Garonnette", "1 Av Maurice Hauriou", 43.594570, 1.440920 },
	{ 51, 0, "00051 - Duportal Brienne", "1 Bd Armand Duportal", 43.605036, 1.434843 },
	{ 52, 0, "00052 - Duportal Cite Admin.", "41 Bd Armand Duportal", 43.608647, 1.434650 },
	{ 53, 0, "00053 - Place Saint Julien", "Pl Saint Julien", 43.608636, 1.437631 },
	{ 54, 0, "00054 - Chaine", "10 Rue De La Chaine", 43.608420, 1.439763 },
	{ 55, 0, "00055 - St Sernin G. Arnoult", "2 Rue Gatien Arnoult", 43.608952, 1.441004 },
	{ 56, 0, "00056 - Saint Sernin  Merly", "1 Rue Merly", 43.609030, 1.442808 },
	{ 57, 0, "00057 - Merly Arcole", "15 Rue Merly", 43.610488, 1.443107 },
	{ 58, 0, "00058 - Concorde Arcole", "4 Rue De La Concorde", 43.610619, 1.443637 },
	{ 59, 0, "00059 - Concorde", "61 Rue De La Concorde", 43.613590, 1.446485 },
	{ 61, 0, "00061 - Bonrepos", "8T Bd De Bonrepos", 43.610718, 1.452456 },
	{ 65, 0, "00065 - Verdier - Grand Rond", "2 All Forain Francois Verdier", 43.597075, 1.452605 },
	{ 66, 0, "00066 - Jardin Royal", "Huit Mai 1945", 43.596478, 1.451093 },
	{ 69, 0, "00069 - Feuga", "11 All Paul Feuga", 43.592607, 1.442756 },
	{ 70, 0, "00070 - Fer A Cheval", "5 Place Du Fer A Cheval", 43.592590, 1.434112 },
	{ 72, 0, "00072 - Fitte Cugnaux", "23 All Charles De Fitte", 43.595049, 1.432688 },
	{ 73, 0, "00073 - Fitte Teinturiers", "40 All Charles De Fitte", 43.596285, 1.432075 },
	{ 75, 0, "00075 - Chateau D Eau", "12 Pl Laganne", 43.598543, 1.436591 },
	{ 76, 0, "00076 - Republique Pl. Olivier", "34 Rue De La Republique", 43.598495, 1.435182 },
	{ 79, 0, "00079 - Place Lange", "1 Pl Lange", 43.601129, 1.434138 },
	{ 80, 0, "00080 - Fitte Varsi", "89B All Charles De Fitte", 43.599704, 1.429275 },
	{ 81, 0, "00081 - Jardin Raymond Vi", "All Charles De Fitte", 43.599895, 1.429557 },
	{ 82, 0, "00082 - Sejourne Catalans", "1 Av Paul Sejourne", 43.605592, 1.428254 },
	{ 83, 0, "00083 - Sejourne Amidonniers", "2 Av Paul Sejourne", 43.605562, 1.427970 },
	{ 85, 0, "00085 - Marechal Leclerc", "2 Bd Du Marechal Leclerc", 43.606708, 1.430599 },
	{ 86, 0, "00086 - Heracles - Bearnais", "23 Rue Du Bearnais", 43.608020, 1.428450 },
	{ 87, 0, "00087 - Lascrosses Leclerc", "47 Bd Lascrosses", 43.609500, 1.432336 },
	{ 88, 0, "00088 - Duportal Lascrosses", "17T Bd Lascrosses", 43.610251, 1.435070 },
	{ 90, 0, "00090 - Lascrosses- A. Bernard", "3B Bd Lascrosses", 43.611470, 1.437871 },
	{ 91, 0, "00091 - Arcole Balance", "48 Bd D Arcole", 43.611584, 1.439738 },
	{ 94, 0, "00094 - Semard Gare Routiere", "73 Bd Pierre Semard", 43.613829, 1.451480 },
	{ 97, 0, "00097 - Raymond Iv", "Rue Raymond Iv", 43.612436, 1.451477 },
	{ 101, 0, "00101 - Capt Port St Sauveur", "5 Port Saint Sauveur", 43.594265, 1.456322 },
	{ 107, 0, "00107 - Sebastopol", "1 Rue De Sebastopol", 43.609753, 1.430390 },
	{ 111, 0, "00111 - Minimes Passerelle", "38B Bd Des Minimes", 43.615260, 1.442921 },
	{ 119, 0, "00119 - Chapou", "129 All De Brienne", 43.609967, 1.419525 },
	{ 120, 0, "00120 - Ponts Jumeaux", "152 All De Barcelone", 43.610354, 1.420545 },
	{ 123, 0, "00123 - Chaussas Embouchure", "1 Rue De Chaussas", 43.614925, 1.432881 },
	{ 126, 0, "00126 - Ecole Bonnefoy", "18 Rue Bonnefoy", 43.616891, 1.454340 },
	{ 129, 0, "00129 - Croix De Pierre", "2 Bd Deodat De Severac", 43.585600, 1.428077 },
	{ 134, 0, "00134 - Eglise Bonnefoy", "8 Allee De L Eglise Bonnefoy", 43.618941, 1.456659 },
	{ 104, 0, "00104 - Muret Barthere", "219 Av De Muret", 43.589795, 1.432067 },
	{ 105, 0, "00105 - Billiere -Champetre", "12  Av  Etienne  Billieres", 43.597642, 1.428863 },
	{ 117, 0, "00117 - Billieres -Poste", "39 Avenue Etienne Billieres", 43.596853, 1.425882 },
	{ 131, 0, "00131 - Bernies", "15 Rue Paul Bernies", 43.611741, 1.414597 },
	{ 106, 0, "00106 - Brienne Passerelle", "99 All De Brienne", 43.608422, 1.423867 },
	{ 4, 0, "00004 - Ste Ursule", "15 Rue Sainte Ursule", 43.602336, 1.442047 },
	{ 115, 0, "00115 - Demoiselles Mistral", "8 All Des Demoiselles", 43.590622, 1.453806 },
	{ 74, 0, "00074 - Laganne Teinturiers", "37 Rue Laganne", 43.596661, 1.436175 },
	{ 96, 0, "00096 - Mediatheque", "50 Rue Du General Compans", 43.609743, 1.455205 },
	{ 36, 0, "00036 - Place Schuman", "5 Pl Robert Schuman", 43.609623, 1.449368 },
	{ 41, 0, "00041 - St Aubin Camichel", "1 Rue Charles Camichel", 43.602654, 1.454436 },
	{ 98, 0, "00098 - Pont Des Demoiselles", "80 All Des Demoiselles", 43.587678, 1.459836 },
	{ 38, 0, "00038 - Jaures Bachelier", "56 All Jean Jaures", 43.607548, 1.451651 },
	{ 62, 0, "00062 - Jaures Stalingrad", "71 All Jean Jaures", 43.609045, 1.453360 },
	{ 63, 0, "00063 - Piscine Leo Lagrange", "54 Rue Des Sept Troubadours", 43.607433, 1.454189 },
	{ 100, 0, "00100 - Port St Sauveur", "16 All Paul Sabatier", 43.596974, 1.455674 },
	{ 103, 0, "00103 - St Michel St Catherine", "139 Grande Rue St Michel", 43.590605, 1.445174 },
	{ 109, 0, "00109 - Metro Canal Du Midi", "1 Bd De La Marquette", 43.615174, 1.434708 },
	{ 116, 0, "00116 - St Michel Notre Dame", "50 Grande Rue St Michel", 43.588360, 1.446483 },
	{ 132, 0, "00132 - Minimes Bilard", "101 Avenues Des Minimes", 43.622938, 1.434474 },
	{ 60, 0, "00060 - Roquelaine", "32 Pl Roquelaine", 43.612637, 1.448542 },
	{ 77, 0, "00077 - Place Int Saint Cyprien", "2 Pl Interieure St Cyprien", 43.597836, 1.431605 },
	{ 78, 0, "00078 - Place Int St Cyp. Darre", "14 Pl Interieure St Cyprien", 43.598122, 1.431415 },
	{ 89, 0, "00089 - Esp Compans Caffarelli", "1 Esp Compans Caffarelli", 43.611037, 1.436629 },
	{ 122, 0, "00122 - Passerelle Haedens", "57 Bd De L Embouchure", 43.613472, 1.430120 },
	{ 67, 0, "00067 - Museum", "35 All Jules Guesde", 43.594385, 1.449061 },
	{ 102, 0, "00102 -  Mistral - Fleurance", "18 Allee Frederic Mistral", 43.593600, 1.453042 },
	{ 110, 0, "00110 - Cabanel - Serres", "16 Rue Alexandre Cabanel", 43.613755, 1.438157 },
	{ 114, 0, "00114 - Bd Montplaisir - Canal", "8 Bd Monplaisir", 43.592391, 1.458008 },
	{ 133, 0, "00133 - Marche Aux Cochons", "71 Av Des Minimes", 43.620736, 1.435597 },
	{ 71, 0, "00071 - Cours Dillon", "3 Rue Laganne", 43.593189, 1.434894 },
	{ 113, 0, "00113 - Museum Lamarck", "Face 58 Rue Dumeril", 43.592355, 1.449216 },
	{ 92, 0, "00092 - Chalets", "31 Rue Des Chalets", 43.613250, 1.441221 },
	{ 99, 0, "00099 - Rempart St Etienne", "7 Rue Du Rempart St Etienne", 43.600825, 1.450655 },
	{ 125, 0, "00125 - Barrière De Paris", "Barrière De Paris", 43.626918, 1.434225 },
	{ 40, 0, "00040 - Colombette", "41 Rue De La Colombette", 43.604660, 1.453589 },
	{ 49, 0, "00049 - Coutelier - Metz", "52 Rue Des Couteliers", 43.599590, 1.441435 },
	{ 112, 0, "00112 - Place Russel - Branly", "47 Allee Branly", 43.585267, 1.452937 },
	{ 127, 0, "00127 - Begue - Demoiselles", "1 Rue Begue", 43.589804, 1.455945 },
	{ 37, 0, "00037 - Ste Lucie", "53 Rue Ste Lucie", 43.593507, 1.429881 },
	{ 64, 0, "00064 - Peri Mercadier", "0030 Rue Gabriel Peri", 43.606173, 1.454988 },
	{ 84, 0, "00084 - Brienne Manufacture", "19T All De Brienne", 43.605242, 1.432688 },
	{ 121, 0, "00121 - Serres - A. Bernard", "33 Av Honre Serres", 43.612328, 1.438340 },
	{ 130, 0, "00130 - Billieres - Patte D Oie", "66 Ter Av Etienne Billieres", 43.596793, 1.424139 },
	{ 108, 0, "00108 - Sebastopol - Ritay", "2 Bd Sebastopol", 43.612284, 1.428791 },
	{ 128, 0, "00128 - Prison St Michel", "18 B Grande Rue St Michel", 43.585896, 1.447412 },
	{ 93, 0, "00093 - Printemps", "57 Rue Du Printemps", 43.614466, 1.443614 },
	{ 140, 0, "00140 - Emile Male", "Place Emile Male", 43.591570, 1.418744 },
	{ 141, 0, "00141 - Fontaine Lestang", "237 Rue Henri Desbals", 43.587583, 1.418128 },
	{ 142, 0, "00142 - Severac", "Bd Deodat De Severac", 43.588747, 1.422883 },
	{ 146, 0, "00146 - Sang De Serp - Dagnaux", "57 Ch Du Sang De Serp", 43.615418, 1.428493 },
	{ 147, 0, "00147 - Chaussas - Daudet", "96 Rue De Chaussas", 43.619907, 1.428966 },
	{ 154, 0, "00154 - Gallois", "Rue Des Gallois", 43.589959, 1.442031 },
	{ 137, 0, "00137 - Brunhes-Fontaines", "47 Bd Jean Brunhes", 43.600949, 1.420276 },
	{ 139, 0, "00139 - Barriere De Lombez", "39 Bis Av De Lombez", 43.595567, 1.418421 },
	{ 5, 0, "00005 - Leduc", "5 Rue Leduc", 43.610548, 1.455873 },
	{ 136, 0, "00136 - Fontaines", "Rue Des Fontaines", 43.602051, 1.414531 },
	{ 155, 0, "00155 - Recollets", "34 Bd Des Recollets", 43.583869, 1.443635 },
	{ 157, 0, "00157 - U.R.S.S  Peyrouset", "16 Av De L'U.R.S.S", 43.582832, 1.448634 },
	{ 158, 0, "00158 - Urss St Thomas D Aquin", "57 Av De L Urss", 43.580795, 1.449136 },
	{ 159, 0, "00159 - U.R.S.S Devic", "96 Av Jules Julien", 43.578504, 1.450284 },
	{ 160, 0, "00160 - Theatre Jules Julien", "21 Av Des Ecoles Jules Julien", 43.573925, 1.451999 },
	{ 179, 0, "00179 - Cassaing Plana", "5 Ch Cassaing", 43.616803, 1.473505 },
	{ 227, 0, "00227 - Metro Ups", "118  Rte De Narbonne", 43.561610, 1.462869 },
	{ 124, 0, "00124 - Eglise Des Minimes", "27 Av Des Minimes", 43.618149, 1.436875 },
	{ 172, 0, "00172 - Netwiller / Laforgue", "Rue Henri Ebelot", 43.642834, 1.461192 },
	{ 135, 0, "00135 - Bonnefoy   Lemaitre", "183 Rue Du Fb  Bonnefoy", 43.623163, 1.458586 },
	{ 161, 0, "00161 - Rangueil - Bedouce", "35 Av De Rangueil", 43.576448, 1.454915 },
	{ 165, 0, "00165 - Place Des Avions", "33 Avenue Des Avions", 43.576868, 1.460188 },
	{ 118, 0, "00118 - Place Du Busca", "2 Place Du Busca", 43.588179, 1.450765 },
	{ 190, 0, "00190 - Espagne Les Oustalous", "39 Rte D'Espagne", 43.578275, 1.423916 },
	{ 148, 0, "00148 - Collignon", "5 Av De Collignon", 43.616927, 1.444528 },
	{ 191, 0, "00191 - Rue Du 14 Juillet", "395 Route De Saint Simon", 43.589985, 1.415184 },
	{ 162, 0, "00162 - Place D'Italie", "Av D' Italie", 43.580277, 1.454918 },
	{ 163, 0, "00163 - Bedouce / Midi", "115 Av Albert Bedouce", 43.581459, 1.462194 },
	{ 164, 0, "00164 - Bedouce Saouzelong", "Av Albert Bedouce", 43.579725, 1.460094 },
	{ 192, 0, "00192 - Rte De St Simon/Prado", "355 Route De Saint-Simon", 43.587659, 1.409162 },
	{ 177, 0, "00177 - Baillaud Brunaud", "64 Rue Baillaud", 43.617439, 1.465392 },
	{ 173, 0, "00173 - Maunoury / Segela", "25 Av Maurice Bourges Maunoury", 43.633183, 1.450536 },
	{ 174, 0, "00174 - Maunoury / Mela", "41 Av Maurice Bourges Maunoury", 43.636922, 1.452693 },
	{ 182, 0, "00182 - Chaubet", "Av Jean Chaubet", 43.605931, 1.481957 },
	{ 198, 0, "00198 - Lafilaire - Deltour", "Face 25 Chemin Lafilaire", 43.596228, 1.473458 },
	{ 199, 0, "00199 - Deltour - Rieux", "4 Bd Deltour", 43.591528, 1.470276 },
	{ 145, 0, "00145 - Gounod - Garros", "29 Rue Roland Garros", 43.613959, 1.424941 },
	{ 149, 0, "00149 - Raisin Minimes", "Ch Du Raisin", 43.615369, 1.448487 },
	{ 168, 0, "00168 - Bila   /  Route D Albi", "Rue Cremon", 43.626510, 1.458930 },
	{ 68, 0, "00068 - Metro - Palais De Justice", "1 Bis Allee Jules Guesde", 43.592670, 1.444845 },
	{ 152, 0, "00152 - Mazades", "10 Av Des Mazades", 43.624183, 1.438302 },
	{ 171, 0, "00171 - Route D Albi / Cactus", "191 Rte D'Albi", 43.640897, 1.466308 },
	{ 202, 0, "00202 - St Ex. - Courrege", "165 Av Antoine De St Exupery", 43.581669, 1.476002 },
	{ 203, 0, "00203 - St Ex. - Petit Prince", "2 Av Antoine De St Exupery", 43.583419, 1.470078 },
	{ 204, 0, "00204 - Pl. Roger Arnaud", "Pl Roger Arnaud", 43.586779, 1.463164 },
	{ 212, 0, "00212 - Chaumiere/ Cretes", "Rue De La Chaumiere", 43.615227, 1.465376 },
	{ 95, 0, "00095 - Theatre Garonne", "4 Avenue Du Château D'Eau", 43.602528, 1.425223 },
	{ 175, 0, "00175 - Metro Maunoury", "Bourges Maunoury", 43.639456, 1.452567 },
	{ 188, 0, "00188 - Muret/Lafage", "121 Avenue De Muret", 43.584283, 1.427517 },
	{ 193, 0, "00193 - Lombez / Petite Vitesse", "59 Av De Lombez", 43.594849, 1.415377 },
	{ 153, 0, "00153 - Bourges Maunoury", "12 Av Bourges Maunoury", 43.628469, 1.447936 },
	{ 218, 0, "00218 - Amouroux /Ste Augustine", "24 Bis Che Amouroux", 43.627604, 1.461908 },
	{ 178, 0, "00178 - Brunaud / Plana", "Avenue Yves Brunaud", 43.619281, 1.468754 },
	{ 215, 0, "00215 - Metro Argoulets", "Face 8 Rue De Gaillac", 43.623814, 1.475849 },
	{ 216, 0, "00216 - Argoulets Houdon", "3 Rue Jean Houdon", 43.622829, 1.474057 },
	{ 184, 0, "00184 - Michoun", "70 Chemin Michoun", 43.627277, 1.469362 },
	{ 185, 0, "00185 - Roubichou Arles", "30 Rue Roubichou", 43.627048, 1.465517 },
	{ 219, 0, "00219 - Puccini/ Blagnac", "35 Rue Puccini", 43.614590, 1.411360 },
	{ 176, 0, "00176 - General Compans", "1 Rue Du General Compans", 43.606790, 1.458009 },
	{ 144, 0, "00144 - Suisse - Lausane", "62 Bd De Suisse", 43.616062, 1.421716 },
	{ 169, 0, "00169 - Albi  / Jaffary", "65 Rte D'Albi", 43.631247, 1.462248 },
	{ 205, 0, "00205 - Cottage/ Rieux", "58 Av Des Cottages", 43.585886, 1.475085 },
	{ 239, 0, "00239 - Lespinet / Herbettes", "", 43.577167, 1.469394 },
	{ 166, 0, "00166 - Rangueil Guyou", "23 Rue Guyou", 43.574366, 1.462031 },
	{ 208, 0, "00208 - Limayrac/ Darasse", "All De Limayrac", 43.591220, 1.480087 },
	{ 209, 0, "00209 - Baroux/ Darasse", "4 Av Lucien Baroux", 43.589467, 1.478914 },
	{ 210, 0, "00210 - Terrasse/ Centre Co.", "Face 42 Che De La Terrasse", 43.586075, 1.483021 },
	{ 232, 0, "00232 - Narbonne/ Mirouse", "64 Rte De Narbonne", 43.569437, 1.456086 },
	{ 233, 0, "00233 - Narbonne /Sahuque", "105 Rte De Narbonne", 43.566413, 1.458853 },
	{ 211, 0, "00211 - Le Dormeur/ La Terrasse", "9 Rue Le Dormeur", 43.583506, 1.487820 },
	{ 138, 0, "00138 - Barriere De Bayonne", "3 Bd Jean Brunhes", 43.598196, 1.419974 },
	{ 151, 0, "00151 - Curie - Negreneys", "27 Bd Pierre Et Marie Curie", 43.624591, 1.443060 },
	{ 234, 0, "00234 - Loin / Raynal", "Rue Loin 100M Avt Raynal", 43.628237, 1.451331 },
	{ 143, 0, "00143 - Desbals Saintonge", "145 Rue Henri Desbals", 43.581332, 1.413432 },
	{ 187, 0, "00187 - Desbals Montdore", "187 Rue Henri Desbals", 43.584523, 1.415544 },
	{ 238, 0, "00238 - Herbettes / Butte", "Avenue Des Herbettes", 43.579426, 1.473118 },
	{ 170, 0, "00170 - Route D Albi   / Cuvier", "Face 163 Chemin Nicole", 43.635667, 1.464148 },
	{ 195, 0, "00195 - Larrousse -Rieux", "Face 15 Rue Pierre Larousse", 43.597235, 1.459071 },
	{ 220, 0, "00220 - Tabar /Universite", "3 Rue De L'Universite", 43.574612, 1.402302 },
	{ 221, 0, "00221 - Vauquelin", "Face 85 Rue Vauquelin", 43.576419, 1.406489 },
	{ 236, 0, "00236 - Toec / Lemire", "Rue De L'Abbe Jules Lemire", 43.597294, 1.403873 },
	{ 244, 0, "00244 - Renan / Virty", "93 Rue Ernest Renan Angle Rue Vitry", 43.635707, 1.443752 },
	{ 245, 0, "00245 - Grande Bretagne / Badiou", "103 Bis Avenue De Grande Bretagne Angle Rue Badiou", 43.599908, 1.415184 },
	{ 246, 0, "00246 - Wagner / Jean Brunhes", "29 Boulevard Richard Wagner Ang Bd Jean Brunhes", 43.603905, 1.420142 },
	{ 251, 0, "00251 - Blum / Jouhaux", "26 Avenue Leon Blum Angle Rue Leon Jouhaux", 43.614208, 1.461631 },
	{ 214, 0, "00214 - Castres/ Achiary", "48 Av De Castres", 43.600795, 1.473661 },
	{ 197, 0, "00197 - Caserne Perignon", "6 Av Louis Bleriot", 43.600386, 1.464094 },
	{ 247, 0, "00247 - Launaguet / Audibert", "Route De Launaguet Angle Chemin Audibert", 43.636775, 1.439230 },
	{ 229, 0, "00229 - Iut Rangueil", "129 Av De Rangueil", 43.571433, 1.462781 },
	{ 228, 0, "00228 - Metro Pharmacie", "Face 35 Chemin Des Maraichers", 43.567717, 1.464457 },
	{ 217, 0, "00217 - Amouroux/ St Tropez", "42 Che Amouroux", 43.629672, 1.466443 },
	{ 240, 0, "00240 - Rte De Blagnac / Job", "Face 103 Bis Route De Blagnac", 43.617250, 1.408124 },
	{ 201, 0, "00201 - Potez -St Exupery", "256 Av Antoine De St Exupery", 43.579655, 1.480496 },
	{ 189, 0, "00189 - Muret Boutinon", "44 Avenue De Muret", 43.581352, 1.425326 },
	{ 15, 0, "00015 - Pont Montaudran", "Face Au 20 Port St Sauveur", 43.596650, 1.455667 },
	{ 248, 0, "00248 - Bouquetins/E. Rostand", "Rue Des Bouquetins Angle Rue Edmond Rostand", 43.641090, 1.449039 },
	{ 167, 0, "00167 - Compans", "Rue Lapujade Angle Rue Des Flandres", 43.624093, 1.454699 },
	{ 213, 0, "00213 - Pujol/ Chaubet", "129 Av De Castres", 43.600755, 1.467514 },
	{ 194, 0, "00194 - Lombez / Hippodrome", "138 Av De Lombez", 43.594207, 1.410651 },
	{ 196, 0, "00196 - Goujon - Guilhemery", "6 Rue Jean Goujon", 43.601793, 1.458049 },
	{ 249, 0, "00249 - Croix Daurade", "147 Rte D'Albi", 43.638129, 1.465212 },
	{ 242, 0, "00242 -  Raimbaud / Colette", "Rue Raimbaud Angle Rue Colette", 43.633866, 1.437494 },
	{ 252, 0, "00252 - Negreneys /Caseneuve", "161/163 Av De Negreneys Sur Ilot Central", 43.627358, 1.446085 },
	{ 235, 0, "00235 - Paul Verlaine", "", 43.633372, 1.435385 },
	{ 243, 0, "00243 - Etats-Unis / Ferry", "", 43.632641, 1.431808 },
	{ 180, 0, "00180 - Place Soupetard", "", 43.612252, 1.477656 },
	{ 226, 0, "00226 - Fontaines /Casselardit", "292 Rue Des Fontaines", 43.604190, 1.407211 },
	{ 156, 0, "00156 - Metro Empalot", "38 Av Jean Moulin Face Debouche Rue De Cannes", 43.579737, 1.441783 },
	{ 207, 0, "00207 - Christ Roi", "Face 25 Rue De L Aude", 43.583007, 1.481509 },
	{ 186, 0, "00186 - Desbals Boualam", "", 43.579218, 1.411129 },
	{ 150, 0, "00150 - Curie Campistron", "78 Bd Pierre Et Marie Curie", 43.625931, 1.439871 },
	{ 224, 0, "00224 - Campus Supaero", "Avenue Edouard Belin Face Château Du Creps", 43.566596, 1.474882 },
	{ 223, 0, "00223 - Enac", "Avenue Edouard Belin Angle Av Roche", 43.565104, 1.478341 },
	{ 225, 0, "00225 - Belin Onera", "Avenue Edouard Belin Devant Onera", 43.569477, 1.473269 },
	{ 222, 0, "00222 - Cambou / Roche", "", 43.562814, 1.475174 },
	{ 9, 0, "00009 - Maillart - Roquemaurel", "Rue Roquemaurel Angle Rue Ella Maillard", 43.595983, 1.410214 },
	{ 200, 0, "00200 - Place De L'Ormeau", "Face 345 Av Jean Rieux", 43.579069, 1.483670 },
	{ 253, 0, "00253 - Etats-Unis / Robert", "Av Des Etats-Unis Face Au 68 / 70", 43.631912, 1.431683 },
	{ 241, 0, "00241 - Espagne Charpentier", "57 Route D'Espagne", 43.574577, 1.424433 },
	{ 181, 0, "00181 - Plana Garnier", "", 43.610549, 1.479500 },
	{ 230, 0, "00230 - Rangueil Tripode B", "141 Av De Rangueil", 43.567221, 1.467678 },
	{ 231, 0, "00231 - Narbonne Marfaing", "Rangueil / Cl Roche", 43.557244, 1.465371 },
	{ 183, 0, "00183 - Rue De Cugnaux", "", 43.593130, 1.424631 },
	{ 206, 0, "00206 - Leygue/ Rieux", "20 Av Armand Leygue", 43.594342, 1.464668 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateToulouse : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateToulouse() {
    rect = QRectF(QPointF(43.404363, 1.402302), QPointF(43.642834, 1.642951));
    center = QPointF(43.604363, 1.442951);
    statusUrl = "http://www.velo.toulouse.fr/service/stationdetails/%1";
    infosUrl = "http://www.velo.toulouse.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Toulouse %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_TOULOUSE_H */

