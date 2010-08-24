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
        const char *fullAddress;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "00001 - Poids De L'Huile", "12 Rue Du Poids De L'Huile", "12 Rue Du Poids De L'Huile  ", 43.604134687, 1.44542078074 },
	{ 2, 0, "00002 - Lafayette", "21 Rue Lafayette", "21 Rue Lafayette  ", 43.6048526522, 1.44528587667 },
	{ 3, 0, "00003 - Pomme", "62 Rue De La Pomme", "62 Rue De La Pomme  ", 43.6033359383, 1.4455693116 },
	{ 6, 0, "00006 - Lois", "5 Rue Des Lois", "5 Rue Des Lois  ", 43.6052038614, 1.44210144577 },
	{ 7, 0, "00007 - Place Victor Hugo", "6 Rue Du Rempart Villeneuve", "6 Rue Du Rempart Villeneuve  ", 43.6058521622, 1.44659381222 },
	{ 8, 0, "00008 - Espace Saint Georges", "19 Rue Paul Vidal", "19 Rue Paul Vidal  ", 43.6030776948, 1.44804713795 },
	{ 10, 0, "00010 - Place Esquirol", "15 Pl Etienne Esquirol", "15 Pl Etienne Esquirol  ", 43.6003776909, 1.44544233356 },
	{ 11, 0, "00011 - Place De La Daurade", "2 Pl De La Daurade", "2 Pl De La Daurade  ", 43.6012365024, 1.43951674215 },
	{ 12, 0, "00012 - Pargaminieres", "66 Rue Pargaminieres", "66 Rue Pargaminieres  ", 43.6046591643, 1.44036590732 },
	{ 13, 0, "00013 - Lois Esquile", "1 Rue De L Esquile", "1 Rue De L Esquile  ", 43.6062131819, 1.44133107759 },
	{ 14, 0, "00014 - Perigord", "26 Rue De Perigord", "26 Rue De Perigord  ", 43.6073520536, 1.44426962055 },
	{ 16, 0, "00016 - Strasbourg Bayard", "32 Bd De Strasbourg", "32 Bd De Strasbourg  ", 43.6079376303, 1.44661077055 },
	{ 17, 0, "00017 - Strasbourg Sardane", "7 Bd De Strasbourg", "7 Bd De Strasbourg  ", 43.6061069289, 1.4480618253 },
	{ 18, 0, "00018 - Strasbourg Jean Jaures", "4 Bd De Strasbourg", "4 Bd De Strasbourg  ", 43.6062971877, 1.44824440833 },
	{ 19, 0, "00019 - Carnot Peri", "62 Bd Lazare Carnot", "62 Bd Lazare Carnot  ", 43.6055759201, 1.44907202262 },
	{ 20, 0, "00020 - Carnot Trois Journees", "69 Bd Lazare Carnot", "69 Bd Lazare Carnot  ", 43.6047176042, 1.44962961992 },
	{ 21, 0, "00021 - Carnot Labeda", "63 Bd Lazare Carnot", "63 Bd Lazare Carnot  ", 43.604111438, 1.45024513037 },
	{ 22, 0, "00022 - Carnot Roland", "24 Bd Lazare Carnot", "24 Bd Lazare Carnot  ", 43.6022199082, 1.4519566582 },
	{ 23, 0, "00023 - Combattants", "6 Bd Lazare Carnot", "6 Bd Lazare Carnot  ", 43.6012859373, 1.45205771368 },
	{ 24, 0, "00024 - Place Saint Etienne", "14 Pl Saint Etienne", "14 Pl Saint Etienne  ", 43.6003986674, 1.45017910039 },
	{ 25, 0, "00025 - Place Rouaix", "1 Rue Des Tourneurs", "1 Rue Des Tourneurs  ", 43.599435046, 1.44558073239 },
	{ 26, 0, "00026 - Dalbade - De Gorsse", "9 Rue Henry De Gorsse", "9 Rue Henry De Gorsse  ", 43.5980475392, 1.44300513399 },
	{ 27, 0, "00027 - Quai De Tounis", "Quai De Tounis", "Quai De Tounis  ", 43.5993837281, 1.44046110641 },
	{ 28, 0, "00028 - Place Saint Pierre", "6 Pl Saint Pierre", "6 Pl Saint Pierre  ", 43.6034370674, 1.43608066157 },
	{ 29, 0, "00029 - Valade", "31 Rue Valade", "31 Rue Valade  ", 43.6050719046, 1.43703205196 },
	{ 30, 0, "00030 - Place Anatole France", "40 Pl Anatole France", "40 Pl Anatole France  ", 43.6062952723, 1.43822499927 },
	{ 31, 0, "00031 - Salenques", "7 Rue Des Salenques", "7 Rue Des Salenques  ", 43.6074900233, 1.43922052826 },
	{ 32, 0, "00032 - Musee St Raymond", "8 Rue Des Trois Renards", "8 Rue Des Trois Renards  ", 43.6076503342, 1.44120957383 },
	{ 33, 0, "00033 - Beraldi", "11 Rue Henri Beraldi", "11 Rue Henri Beraldi  ", 43.6085687131, 1.44357023839 },
	{ 34, 0, "00034 - Saint Lazare", "2 Petite Rue Saint Lazare", "2 Petite Rue Saint Lazare  ", 43.6096500363, 1.44607687987 },
	{ 35, 0, "00035 - Place Jeanne D'Arc", "1 Rue Raymond Iv", "1 Rue Raymond Iv  ", 43.6085186497, 1.44621823519 },
	{ 39, 0, "00039 - Place Damloup", "9 Pl De Damloup", "9 Pl De Damloup  ", 43.6058323212, 1.45293970883 },
	{ 42, 0, "00042 - Dauriac Escande", "3 Bd Pr Leopold Escande", "3 Bd Pr Leopold Escande  ", 43.601588175, 1.45604810027 },
	{ 43, 0, "00043 - Dupuy", "14 Pl Dominique Martin Dupuy", "14 Pl Dominique Martin Dupuy  ", 43.599990271, 1.45409382429 },
	{ 44, 0, "00044 - Palais Niel", "1 All Forain Francois Verdier", "1 All Forain Francois Verdier  ", 43.5980026416, 1.45174992411 },
	{ 45, 0, "00045 - Ozenne", "10 Rue Theodore Ozenne", "10 Rue Theodore Ozenne  ", 43.5963278737, 1.44701439424 },
	{ 46, 0, "00046 - Place Des Carmes", "1 Pl Des Carmes", "1 Pl Des Carmes  ", 43.5974014755, 1.44531564933 },
	{ 47, 0, "00047 - Nazareth Languedoc", "12 Rue Du Languedoc", "12 Rue Du Languedoc  ", 43.5954617576, 1.44553144517 },
	{ 48, 0, "00048 - Place Du Salin", "18 Pl Du Salin", "18 Pl Du Salin  ", 43.5947491197, 1.44413271127 },
	{ 50, 0, "00050 - Garonnette", "1 Av Maurice Hauriou", "1 Av Maurice Hauriou  ", 43.5945697376, 1.44092005937 },
	{ 51, 0, "00051 - Duportal Brienne", "1 Bd Armand Duportal", "1 Bd Armand Duportal  ", 43.6050356887, 1.43484323579 },
	{ 52, 0, "00052 - Duportal Cite Admin.", "41 Bd Armand Duportal", "41 Bd Armand Duportal  ", 43.6086474542, 1.43465009606 },
	{ 53, 0, "00053 - Place Saint Julien", "Pl Saint Julien", "Pl Saint Julien  ", 43.6086363364, 1.43763148934 },
	{ 54, 0, "00054 - Chaine", "10 Rue De La Chaine", "10 Rue De La Chaine  ", 43.6084203375, 1.43976255677 },
	{ 55, 0, "00055 - St Sernin G. Arnoult", "2 Rue Gatien Arnoult", "2 Rue Gatien Arnoult  ", 43.6089519605, 1.44100359873 },
	{ 56, 0, "00056 - Saint Sernin  Merly", "1 Rue Merly", "1 Rue Merly  ", 43.6090298188, 1.44280843668 },
	{ 57, 0, "00057 - Merly Arcole", "15 Rue Merly", "15 Rue Merly  ", 43.6104884274, 1.44310722802 },
	{ 58, 0, "00058 - Concorde Arcole", "4 Rue De La Concorde", "4 Rue De La Concorde  ", 43.6106186453, 1.4436371257 },
	{ 59, 0, "00059 - Concorde", "61 Rue De La Concorde", "61 Rue De La Concorde  ", 43.6135903725, 1.44648549845 },
	{ 61, 0, "00061 - Bonrepos", "8T Bd De Bonrepos", "8T Bd De Bonrepos  ", 43.6107181009, 1.45245582657 },
	{ 65, 0, "00065 - Verdier - Grand Rond", "2 All Forain Francois Verdier", "2 All Forain Francois Verdier  ", 43.5970748468, 1.4526053074 },
	{ 66, 0, "00066 - Jardin Royal", "Huit Mai 1945", "Huit Mai 1945  ", 43.5964782221, 1.45109333987 },
	{ 69, 0, "00069 - Feuga", "11 All Paul Feuga", "11 All Paul Feuga  ", 43.5926074943, 1.44275638711 },
	{ 70, 0, "00070 - Fer A Cheval", "5 Place Du Fer A Cheval", "5 Place Du Fer A Cheval  ", 43.5925895803, 1.43411233132 },
	{ 72, 0, "00072 - Fitte Cugnaux", "23 All Charles De Fitte", "23 All Charles De Fitte  ", 43.5950494918, 1.43268830788 },
	{ 73, 0, "00073 - Fitte Teinturiers", "40 All Charles De Fitte", "40 All Charles De Fitte  ", 43.5962847639, 1.43207510607 },
	{ 75, 0, "00075 - Chateau D Eau", "12 Pl Laganne", "12 Pl Laganne  ", 43.5985426071, 1.43659075722 },
	{ 76, 0, "00076 - Republique Pl. Olivier", "34 Rue De La Republique", "34 Rue De La Republique  ", 43.5984949088, 1.4351815571 },
	{ 79, 0, "00079 - Place Lange", "1 Pl Lange", "1 Pl Lange  ", 43.6011288056, 1.43413810671 },
	{ 80, 0, "00080 - Fitte Varsi", "89B All Charles De Fitte", "89B All Charles De Fitte  ", 43.5997038677, 1.42927516851 },
	{ 81, 0, "00081 - Jardin Raymond Vi", "All Charles De Fitte", "All Charles De Fitte  ", 43.5998949876, 1.42955660182 },
	{ 82, 0, "00082 - Sejourne Catalans", "1 Av Paul Sejourne", "1 Av Paul Sejourne  ", 43.6055917313, 1.4282538519 },
	{ 83, 0, "00083 - Sejourne Amidonniers", "2 Av Paul Sejourne", "2 Av Paul Sejourne  ", 43.6055623784, 1.42796981948 },
	{ 85, 0, "00085 - Marechal Leclerc", "2 Bd Du Marechal Leclerc", "2 Bd Du Marechal Leclerc  ", 43.6067080086, 1.43059871626 },
	{ 86, 0, "00086 - Heracles - Bearnais", "23 Rue Du Bearnais", "23 Rue Du Bearnais  ", 43.6080202785, 1.42845023144 },
	{ 87, 0, "00087 - Lascrosses Leclerc", "47 Bd Lascrosses", "47 Bd Lascrosses  ", 43.6095000042, 1.43233572993 },
	{ 88, 0, "00088 - Duportal Lascrosses", "17T Bd Lascrosses", "17T Bd Lascrosses  ", 43.610250914, 1.43507009438 },
	{ 90, 0, "00090 - Lascrosses- A. Bernard", "3B Bd Lascrosses", "3B Bd Lascrosses  ", 43.6114697144, 1.43787138555 },
	{ 91, 0, "00091 - Arcole Balance", "48 Bd D Arcole", "48 Bd D Arcole  ", 43.6115840876, 1.43973757988 },
	{ 94, 0, "00094 - Semard Gare Routiere", "73 Bd Pierre Semard", "73 Bd Pierre Semard  ", 43.613829128, 1.45147977927 },
	{ 97, 0, "00097 - Raymond Iv", "Rue Raymond Iv", "Rue Raymond Iv  ", 43.6124358816, 1.45147664662 },
	{ 101, 0, "00101 - Capt Port St Sauveur", "5 Port Saint Sauveur", "5 Port Saint Sauveur  ", 43.5942648504, 1.45632183659 },
	{ 107, 0, "00107 - Sebastopol", "1 Rue De Sebastopol", "1 Rue De Sebastopol  ", 43.6097533618, 1.43038955524 },
	{ 111, 0, "00111 - Minimes Passerelle", "38B Bd Des Minimes", "38B Bd Des Minimes  ", 43.6152597992, 1.44292117585 },
	{ 119, 0, "00119 - Chapou", "129 All De Brienne", "129 All De Brienne  ", 43.6099673431, 1.41952485321 },
	{ 120, 0, "00120 - Ponts Jumeaux", "152 All De Barcelone", "152 All De Barcelone  ", 43.6103535152, 1.42054540744 },
	{ 123, 0, "00123 - Chaussas Embouchure", "1 Rue De Chaussas", "1 Rue De Chaussas  ", 43.6149246512, 1.43288072067 },
	{ 126, 0, "00126 - Ecole Bonnefoy", "18 Rue Bonnefoy", "18 Rue Bonnefoy  ", 43.6168906311, 1.4543397011 },
	{ 129, 0, "00129 - Croix De Pierre", "2 Bd Deodat De Severac", "2 Bd Deodat De Severac  ", 43.5855999772, 1.42807730277 },
	{ 134, 0, "00134 - Eglise Bonnefoy", "8 Allee De L Eglise Bonnefoy", "8 Allee De L Eglise Bonnefoy  ", 43.6189409438, 1.45665875491 },
	{ 104, 0, "00104 - Muret Barthere", "219 Av De Muret", "219 Av De Muret  ", 43.5897950624, 1.43206663283 },
	{ 105, 0, "00105 - Billiere -Champetre", "12  Av  Etienne  Billieres", "12  Av  Etienne  Billieres  ", 43.5976420488, 1.42886269924 },
	{ 117, 0, "00117 - Billieres -Poste", "39 Avenue Etienne Billieres", "39 Avenue Etienne Billieres  ", 43.5968529566, 1.42588227329 },
	{ 131, 0, "00131 - Bernies", "15 Rue Paul Bernies", "15 Rue Paul Bernies  ", 43.6117411156, 1.41459747127 },
	{ 106, 0, "00106 - Brienne Passerelle", "99 All De Brienne", "99 All De Brienne  ", 43.6084221116, 1.42386687478 },
	{ 4, 0, "00004 - Ste Ursule", "15 Rue Sainte Ursule", "15 Rue Sainte Ursule  ", 43.6023360928, 1.44204743784 },
	{ 115, 0, "00115 - Demoiselles Mistral", "8 All Des Demoiselles", "8 All Des Demoiselles  ", 43.590622011, 1.45380582508 },
	{ 74, 0, "00074 - Laganne Teinturiers", "37 Rue Laganne", "37 Rue Laganne  ", 43.5966605629, 1.43617519701 },
	{ 96, 0, "00096 - Mediatheque", "50 Rue Du General Compans", "50 Rue Du General Compans  ", 43.6097428274, 1.45520479539 },
	{ 36, 0, "00036 - Place Schuman", "5 Pl Robert Schuman", "5 Pl Robert Schuman  ", 43.6096231673, 1.44936782298 },
	{ 41, 0, "00041 - St Aubin Camichel", "1 Rue Charles Camichel", "1 Rue Charles Camichel  ", 43.6026536423, 1.4544360788 },
	{ 98, 0, "00098 - Pont Des Demoiselles", "80 All Des Demoiselles", "80 All Des Demoiselles  ", 43.5876779901, 1.45983630955 },
	{ 38, 0, "00038 - Jaures Bachelier", "56 All Jean Jaures", "56 All Jean Jaures  ", 43.6075475687, 1.45165141809 },
	{ 62, 0, "00062 - Jaures Stalingrad", "71 All Jean Jaures", "71 All Jean Jaures  ", 43.6090446441, 1.45336004008 },
	{ 63, 0, "00063 - Piscine Leo Lagrange", "54 Rue Des Sept Troubadours", "54 Rue Des Sept Troubadours  ", 43.6074334874, 1.45418901792 },
	{ 100, 0, "00100 - Port St Sauveur", "16 All Paul Sabatier", "16 All Paul Sabatier  ", 43.5969740671, 1.45567404278 },
	{ 103, 0, "00103 - St Michel St Catherine", "139 Grande Rue St Michel", "139 Grande Rue St Michel  ", 43.5906050823, 1.44517443094 },
	{ 109, 0, "00109 - Metro Canal Du Midi", "1 Bd De La Marquette", "1 Bd De La Marquette  ", 43.6151736118, 1.43470777742 },
	{ 116, 0, "00116 - St Michel Notre Dame", "50 Grande Rue St Michel", "50 Grande Rue St Michel  ", 43.5883597911, 1.44648316567 },
	{ 132, 0, "00132 - Minimes Bilard", "101 Avenues Des Minimes", "101 Avenues Des Minimes  ", 43.6229377954, 1.43447369219 },
	{ 60, 0, "00060 - Roquelaine", "32 Pl Roquelaine", "32 Pl Roquelaine  ", 43.6126365223, 1.44854159839 },
	{ 77, 0, "00077 - Place Int Saint Cyprien", "2 Pl Interieure St Cyprien", "2 Pl Interieure St Cyprien  ", 43.5978358301, 1.43160528463 },
	{ 78, 0, "00078 - Place Int St Cyp. Darre", "14 Pl Interieure St Cyprien", "14 Pl Interieure St Cyprien  ", 43.5981218686, 1.43141523075 },
	{ 89, 0, "00089 - Esp Compans Caffarelli", "1 Esp Compans Caffarelli", "1 Esp Compans Caffarelli  ", 43.6110369152, 1.43662875903 },
	{ 122, 0, "00122 - Passerelle Haedens", "57 Bd De L Embouchure", "57 Bd De L Embouchure  ", 43.6134723583, 1.43012018727 },
	{ 67, 0, "00067 - Museum", "35 All Jules Guesde", "35 All Jules Guesde  ", 43.5943852254, 1.44906050328 },
	{ 102, 0, "00102 -  Mistral - Fleurance", "18 Allee Frederic Mistral", "18 Allee Frederic Mistral  ", 43.5935999125, 1.45304249259 },
	{ 110, 0, "00110 - Cabanel - Serres", "16 Rue Alexandre Cabanel", "16 Rue Alexandre Cabanel  ", 43.6137551769, 1.43815704624 },
	{ 114, 0, "00114 - Bd Montplaisir - Canal", "8 Bd Monplaisir", "8 Bd Monplaisir  ", 43.5923910122, 1.45800786139 },
	{ 133, 0, "00133 - Marche Aux Cochons", "71 Av Des Minimes", "71 Av Des Minimes  ", 43.6207359688, 1.43559731147 },
	{ 71, 0, "00071 - Cours Dillon", "3 Rue Laganne", "3 Rue Laganne  ", 43.5931893428, 1.43489432835 },
	{ 113, 0, "00113 - Museum Lamarck", "Face 58 Rue Dumeril", "Face 58 Rue Dumeril  ", 43.5923551245, 1.44921573215 },
	{ 92, 0, "00092 - Chalets", "31 Rue Des Chalets", "31 Rue Des Chalets  ", 43.6132502718, 1.4412206793 },
	{ 99, 0, "00099 - Rempart St Etienne", "7 Rue Du Rempart St Etienne", "7 Rue Du Rempart St Etienne  ", 43.6008250248, 1.45065484986 },
	{ 125, 0, "00125 - Barrière De Paris", "Barrière De Paris", "Barrière De Paris  ", 43.6269176822, 1.43422515076 },
	{ 40, 0, "00040 - Colombette", "41 Rue De La Colombette", "41 Rue De La Colombette  ", 43.6046601361, 1.45358869175 },
	{ 49, 0, "00049 - Coutelier - Metz", "52 Rue Des Couteliers", "52 Rue Des Couteliers  ", 43.5995895444, 1.4414349653 },
	{ 112, 0, "00112 - Place Russel - Branly", "47 Allee Branly", "47 Allee Branly  ", 43.5852668402, 1.45293651493 },
	{ 127, 0, "00127 - Begue - Demoiselles", "1 Rue Begue", "1 Rue Begue  ", 43.5898035523, 1.45594544811 },
	{ 37, 0, "00037 - Ste Lucie", "53 Rue Ste Lucie", "53 Rue Ste Lucie  ", 43.593506929, 1.42988070604 },
	{ 64, 0, "00064 - Peri Mercadier", "0030 Rue Gabriel Peri", "0030 Rue Gabriel Peri  ", 43.6061726307, 1.45498779877 },
	{ 84, 0, "00084 - Brienne Manufacture", "19T All De Brienne", "19T All De Brienne  ", 43.605242396, 1.43268768272 },
	{ 121, 0, "00121 - Serres - A. Bernard", "33 Av Honre Serres", "33 Av Honre Serres  ", 43.6123275226, 1.43834034521 },
	{ 130, 0, "00130 - Billieres - Patte D Oie", "66 Ter Av Etienne Billieres", "66 Ter Av Etienne Billieres  ", 43.5967933132, 1.42413938579 },
	{ 108, 0, "00108 - Sebastopol - Ritay", "2 Bd Sebastopol", "2 Bd Sebastopol  ", 43.6122837013, 1.42879062905 },
	{ 128, 0, "00128 - Prison St Michel", "18 B Grande Rue St Michel", "18 B Grande Rue St Michel  ", 43.5858956421, 1.44741188162 },
	{ 93, 0, "00093 - Printemps", "57 Rue Du Printemps", "57 Rue Du Printemps  ", 43.6144655444, 1.44361404386 },
	{ 140, 0, "00140 - Emile Male", "Place Emile Male", "Place Emile Male  ", 43.5915702917, 1.4187444945 },
	{ 141, 0, "00141 - Fontaine Lestang", "237 Rue Henri Desbals", "237 Rue Henri Desbals  ", 43.5875831955, 1.41812848171 },
	{ 142, 0, "00142 - Severac", "Bd Deodat De Severac", "Bd Deodat De Severac  ", 43.5887470524, 1.42288300273 },
	{ 146, 0, "00146 - Sang De Serp - Dagnaux", "57 Ch Du Sang De Serp", "57 Ch Du Sang De Serp  ", 43.6154182104, 1.42849333093 },
	{ 147, 0, "00147 - Chaussas - Daudet", "96 Rue De Chaussas", "96 Rue De Chaussas  ", 43.6199074847, 1.42896628242 },
	{ 154, 0, "00154 - Gallois", "Rue Des Gallois", "Rue Des Gallois  ", 43.5899589086, 1.44203115503 },
	{ 137, 0, "00137 - Brunhes-Fontaines", "47 Bd Jean Brunhes", "47 Bd Jean Brunhes  ", 43.6009492479, 1.42027580241 },
	{ 139, 0, "00139 - Barriere De Lombez", "39 Bis Av De Lombez", "39 Bis Av De Lombez  ", 43.5955673906, 1.41842051039 },
	{ 5, 0, "00005 - Leduc", "5 Rue Leduc", "5 Rue Leduc  ", 43.6105482478, 1.45587273792 },
	{ 136, 0, "00136 - Fontaines", "Rue Des Fontaines", "Rue Des Fontaines  ", 43.6020509196, 1.41453135957 },
	{ 155, 0, "00155 - Recollets", "34 Bd Des Recollets", "34 Bd Des Recollets  ", 43.583869085, 1.44363507886 },
	{ 157, 0, "00157 - U.R.S.S  Peyrouset", "16 Av De L'U.R.S.S", "16 Av De L'U.R.S.S  ", 43.5828316868, 1.44863423433 },
	{ 158, 0, "00158 - Urss St Thomas D Aquin", "57 Av De L Urss", "57 Av De L Urss  ", 43.5807954613, 1.44913573858 },
	{ 159, 0, "00159 - U.R.S.S Devic", "96 Av Jules Julien", "96 Av Jules Julien  ", 43.5785038853, 1.45028408338 },
	{ 160, 0, "00160 - Theatre Jules Julien", "21 Av Des Ecoles Jules Julien", "21 Av Des Ecoles Jules Julien  ", 43.5739249402, 1.45199938638 },
	{ 179, 0, "00179 - Cassaing Plana", "5 Ch Cassaing", "5 Ch Cassaing  ", 43.6168026524, 1.47350516101 },
	{ 227, 0, "00227 - Metro Ups", "118  Rte De Narbonne", "118  Rte De Narbonne  ", 43.5616096955, 1.46286914558 },
	{ 124, 0, "00124 - Eglise Des Minimes", "27 Av Des Minimes", "27 Av Des Minimes  ", 43.6181489116, 1.43687538616 },
	{ 172, 0, "00172 - Netwiller / Laforgue", "Rue Henri Ebelot", "Rue Henri Ebelot  ", 43.6428335698, 1.46119167161 },
	{ 135, 0, "00135 - Bonnefoy   Lemaitre", "183 Rue Du Fb  Bonnefoy", "183 Rue Du Fb  Bonnefoy  ", 43.6231632602, 1.45858573996 },
	{ 161, 0, "00161 - Rangueil - Bedouce", "35 Av De Rangueil", "35 Av De Rangueil  ", 43.576447511, 1.45491511202 },
	{ 165, 0, "00165 - Place Des Avions", "33 Avenue Des Avions", "33 Avenue Des Avions  ", 43.5768679202, 1.46018774207 },
	{ 118, 0, "00118 - Place Du Busca", "2 Place Du Busca", "2 Place Du Busca  ", 43.5881792539, 1.45076452847 },
	{ 190, 0, "00190 - Espagne Les Oustalous", "39 Rte D'Espagne", "39 Rte D'Espagne  ", 43.5782753634, 1.42391602251 },
	{ 148, 0, "00148 - Collignon", "5 Av De Collignon", "5 Av De Collignon  ", 43.6169269653, 1.44452816745 },
	{ 191, 0, "00191 - Rue Du 14 Juillet", "395 Route De Saint Simon", "395 Route De Saint Simon  ", 43.5899849939, 1.41518378562 },
	{ 162, 0, "00162 - Place D'Italie", "Av D' Italie", "Av D' Italie  ", 43.5802765386, 1.45491780579 },
	{ 163, 0, "00163 - Bedouce / Midi", "115 Av Albert Bedouce", "115 Av Albert Bedouce  ", 43.5814592116, 1.46219446467 },
	{ 164, 0, "00164 - Bedouce Saouzelong", "Av Albert Bedouce", "Av Albert Bedouce  ", 43.5797254327, 1.46009442602 },
	{ 192, 0, "00192 - Rte De St Simon/Prado", "355 Route De Saint-Simon", "355 Route De Saint-Simon  ", 43.5876594131, 1.40916212555 },
	{ 177, 0, "00177 - Baillaud Brunaud", "64 Rue Baillaud", "64 Rue Baillaud  ", 43.6174386782, 1.46539185105 },
	{ 173, 0, "00173 - Maunoury / Segela", "25 Av Maurice Bourges Maunoury", "25 Av Maurice Bourges Maunoury  ", 43.6331828272, 1.45053596993 },
	{ 174, 0, "00174 - Maunoury / Mela", "41 Av Maurice Bourges Maunoury", "41 Av Maurice Bourges Maunoury  ", 43.6369217918, 1.45269325018 },
	{ 182, 0, "00182 - Chaubet", "Av Jean Chaubet", "Av Jean Chaubet  ", 43.6059308325, 1.48195716205 },
	{ 198, 0, "00198 - Lafilaire - Deltour", "Face 25 Chemin Lafilaire", "Face 25 Chemin Lafilaire  ", 43.5962277156, 1.47345760066 },
	{ 199, 0, "00199 - Deltour - Rieux", "4 Bd Deltour", "4 Bd Deltour  ", 43.59152831, 1.47027628396 },
	{ 145, 0, "00145 - Gounod - Garros", "29 Rue Roland Garros", "29 Rue Roland Garros  ", 43.6139591318, 1.4249412241 },
	{ 149, 0, "00149 - Raisin Minimes", "Ch Du Raisin", "Ch Du Raisin  ", 43.6153685849, 1.44848670955 },
	{ 168, 0, "00168 - Bila   /  Route D Albi", "Rue Cremon", "Rue Cremon  ", 43.6265098134, 1.45893020789 },
	{ 68, 0, "00068 - Metro - Palais De Justice", "1 Bis Allee Jules Guesde", "1 Bis Allee Jules Guesde  ", 43.5926696951, 1.44484538993 },
	{ 152, 0, "00152 - Mazades", "10 Av Des Mazades", "10 Av Des Mazades  ", 43.6241831343, 1.43830218091 },
	{ 171, 0, "00171 - Route D Albi / Cactus", "191 Rte D'Albi", "191 Rte D'Albi  ", 43.6408973504, 1.46630839181 },
	{ 202, 0, "00202 - St Ex. - Courrege", "165 Av Antoine De St Exupery", "165 Av Antoine De St Exupery  ", 43.5816689491, 1.4760021766 },
	{ 203, 0, "00203 - St Ex. - Petit Prince", "2 Av Antoine De St Exupery", "2 Av Antoine De St Exupery  ", 43.583419254, 1.47007784484 },
	{ 204, 0, "00204 - Pl. Roger Arnaud", "Pl Roger Arnaud", "Pl Roger Arnaud  ", 43.5867791429, 1.46316404579 },
	{ 212, 0, "00212 - Chaumiere/ Cretes", "Rue De La Chaumiere", "Rue De La Chaumiere  ", 43.6152273741, 1.46537612503 },
	{ 95, 0, "00095 - Theatre Garonne", "4 Avenue Du Château D'Eau", "4 Avenue Du Château D'Eau  ", 43.6025281055, 1.42522275295 },
	{ 175, 0, "00175 - Metro Maunoury", "Bourges Maunoury", "Bourges Maunoury  ", 43.6394555737, 1.45256734914 },
	{ 188, 0, "00188 - Muret/Lafage", "121 Avenue De Muret", "121 Avenue De Muret  ", 43.5842829653, 1.42751710742 },
	{ 193, 0, "00193 - Lombez / Petite Vitesse", "59 Av De Lombez", "59 Av De Lombez  ", 43.5948493825, 1.41537734905 },
	{ 153, 0, "00153 - Bourges Maunoury", "12 Av Bourges Maunoury", "12 Av Bourges Maunoury  ", 43.6284694205, 1.4479362869 },
	{ 218, 0, "00218 - Amouroux /Ste Augustine", "24 Bis Che Amouroux", "24 Bis Che Amouroux  ", 43.6276035874, 1.46190795364 },
	{ 178, 0, "00178 - Brunaud / Plana", "Avenue Yves Brunaud", "Avenue Yves Brunaud  ", 43.6192814029, 1.46875376692 },
	{ 215, 0, "00215 - Metro Argoulets", "Face 8 Rue De Gaillac", "Face 8 Rue De Gaillac  ", 43.6238144241, 1.47584902878 },
	{ 216, 0, "00216 - Argoulets Houdon", "3 Rue Jean Houdon", "3 Rue Jean Houdon  ", 43.6228293809, 1.47405740131 },
	{ 184, 0, "00184 - Michoun", "70 Chemin Michoun", "70 Chemin Michoun  ", 43.6272771228, 1.46936221746 },
	{ 185, 0, "00185 - Roubichou Arles", "30 Rue Roubichou", "30 Rue Roubichou  ", 43.6270484665, 1.46551733837 },
	{ 219, 0, "00219 - Puccini/ Blagnac", "35 Rue Puccini", "35 Rue Puccini  ", 43.6145897946, 1.41135959175 },
	{ 176, 0, "00176 - General Compans", "1 Rue Du General Compans", "1 Rue Du General Compans  ", 43.6067904685, 1.45800884644 },
	{ 144, 0, "00144 - Suisse - Lausane", "62 Bd De Suisse", "62 Bd De Suisse  ", 43.616062174, 1.4217156943 },
	{ 169, 0, "00169 - Albi  / Jaffary", "65 Rte D'Albi", "65 Rte D'Albi  ", 43.6312467293, 1.46224809752 },
	{ 205, 0, "00205 - Cottage/ Rieux", "58 Av Des Cottages", "58 Av Des Cottages  ", 43.5858861382, 1.47508540801 },
        { 239, 0, "00239 - Lespinet / Herbettes", "Av De Lespinet", "Av De Lespinet", 43.5771669176, 1.46939383682 },
	{ 166, 0, "00166 - Rangueil Guyou", "23 Rue Guyou", "23 Rue Guyou  ", 43.574366149, 1.46203109791 },
	{ 208, 0, "00208 - Limayrac/ Darasse", "All De Limayrac", "All De Limayrac  ", 43.5912200236, 1.48008748376 },
	{ 209, 0, "00209 - Baroux/ Darasse", "4 Av Lucien Baroux", "4 Av Lucien Baroux  ", 43.5894669821, 1.478914286 },
	{ 210, 0, "00210 - Terrasse/ Centre Co.", "Face 42 Che De La Terrasse", "Face 42 Che De La Terrasse  ", 43.5860749567, 1.48302104095 },
	{ 232, 0, "00232 - Narbonne/ Mirouse", "64 Rte De Narbonne", "64 Rte De Narbonne  ", 43.5694372511, 1.45608644597 },
	{ 233, 0, "00233 - Narbonne /Sahuque", "105 Rte De Narbonne", "105 Rte De Narbonne  ", 43.5664127635, 1.4588525005 },
	{ 211, 0, "00211 - Le Dormeur/ La Terrasse", "9 Rue Le Dormeur", "9 Rue Le Dormeur  ", 43.5835061592, 1.48781984362 },
	{ 138, 0, "00138 - Barriere De Bayonne", "3 Bd Jean Brunhes", "3 Bd Jean Brunhes  ", 43.5981962146, 1.41997369299 },
	{ 151, 0, "00151 - Curie - Negreneys", "27 Bd Pierre Et Marie Curie", "27 Bd Pierre Et Marie Curie  ", 43.6245910886, 1.44305961173 },
	{ 234, 0, "00234 - Loin / Raynal", "Rue Loin 100M Avt Raynal", "Rue Loin 100M Avt Raynal  ", 43.6282365928, 1.45133050456 },
	{ 143, 0, "00143 - Desbals Saintonge", "145 Rue Henri Desbals", "145 Rue Henri Desbals  ", 43.5813322052, 1.41343167605 },
	{ 187, 0, "00187 - Desbals Montdore", "187 Rue Henri Desbals", "187 Rue Henri Desbals  ", 43.5845231235, 1.41554396037 },
	{ 238, 0, "00238 - Herbettes / Butte", "Avenue Des Herbettes", "Avenue Des Herbettes  ", 43.5794258356, 1.47311812721 },
	{ 170, 0, "00170 - Route D Albi   / Cuvier", "Face 163 Chemin Nicole", "Face 163 Chemin Nicole  ", 43.6356665121, 1.46414813845 },
	{ 195, 0, "00195 - Larrousse -Rieux", "Face 15 Rue Pierre Larousse", "Face 15 Rue Pierre Larousse  ", 43.597235403, 1.45907112459 },
	{ 220, 0, "00220 - Tabar /Universite", "3 Rue De L'Universite", "3 Rue De L'Universite  ", 43.5746121327, 1.40230245215 },
	{ 221, 0, "00221 - Vauquelin", "Face 85 Rue Vauquelin", "Face 85 Rue Vauquelin  ", 43.5764189548, 1.40648876885 },
	{ 236, 0, "00236 - Toec / Lemire", "Rue De L'Abbe Jules Lemire", "Rue De L'Abbe Jules Lemire  ", 43.597294439, 1.40387294895 },
	{ 244, 0, "00244 - Renan / Virty", "93 Rue Ernest Renan Angle Rue Vitry", "93 Rue Ernest Renan Angle Rue Vitry  ", 43.6357067761, 1.4437518224 },
	{ 245, 0, "00245 - Grande Bretagne / Badiou", "103 Bis Avenue De Grande Bretagne Angle Rue Badiou", "103 Bis Avenue De Grande Bretagne Angle Rue Badiou  ", 43.5999082407, 1.41518438916 },
	{ 246, 0, "00246 - Wagner / Jean Brunhes", "29 Boulevard Richard Wagner Ang Bd Jean Brunhes", "29 Boulevard Richard Wagner Ang Bd Jean Brunhes  ", 43.6039053242, 1.42014176036 },
	{ 251, 0, "00251 - Blum / Jouhaux", "26 Avenue Leon Blum Angle Rue Leon Jouhaux", "26 Avenue Leon Blum Angle Rue Leon Jouhaux  ", 43.6142083877, 1.46163078989 },
	{ 214, 0, "00214 - Castres/ Achiary", "48 Av De Castres", "48 Av De Castres  ", 43.6007954403, 1.4736606319 },
	{ 197, 0, "00197 - Caserne Perignon", "6 Av Louis Bleriot", "6 Av Louis Bleriot  ", 43.6003860582, 1.46409371615 },
	{ 247, 0, "00247 - Launaguet / Audibert", "Route De Launaguet Angle Chemin Audibert", "Route De Launaguet Angle Chemin Audibert  ", 43.6367749588, 1.43923013551 },
	{ 229, 0, "00229 - Iut Rangueil", "129 Av De Rangueil", "129 Av De Rangueil  ", 43.5714330641, 1.46278065695 },
	{ 228, 0, "00228 - Metro Pharmacie", "Face 35 Chemin Des Maraichers", "Face 35 Chemin Des Maraichers  ", 43.5677165059, 1.46445685203 },
	{ 217, 0, "00217 - Amouroux/ St Tropez", "42 Che Amouroux", "42 Che Amouroux  ", 43.6296716006, 1.46644251341 },
	{ 240, 0, "00240 - Rte De Blagnac / Job", "Face 103 Bis Route De Blagnac", "Face 103 Bis Route De Blagnac  ", 43.6172496485, 1.40812446003 },
	{ 201, 0, "00201 - Potez -St Exupery", "256 Av Antoine De St Exupery", "256 Av Antoine De St Exupery  ", 43.5796553266, 1.48049587614 },
	{ 189, 0, "00189 - Muret Boutinon", "44 Avenue De Muret", "44 Avenue De Muret  ", 43.5813522826, 1.42532582828 },
	{ 15, 0, "00015 - Pont Montaudran", "Face Au 20 Port St Sauveur", "Face Au 20 Port St Sauveur  ", 43.5966504244, 1.45566666983 },
	{ 248, 0, "00248 - Bouquetins/E. Rostand", "Rue Des Bouquetins Angle Rue Edmond Rostand", "Rue Des Bouquetins Angle Rue Edmond Rostand  ", 43.6410895881, 1.44903927558 },
	{ 167, 0, "00167 - Compans", "Rue Lapujade Angle Rue Des Flandres", "Rue Lapujade Angle Rue Des Flandres  ", 43.6240934017, 1.45469851782 },
	{ 213, 0, "00213 - Pujol/ Chaubet", "129 Av De Castres", "129 Av De Castres  ", 43.6007551771, 1.46751413107 },
	{ 194, 0, "00194 - Lombez / Hippodrome", "138 Av De Lombez", "138 Av De Lombez  ", 43.5942067653, 1.41065111417 },
	{ 196, 0, "00196 - Goujon - Guilhemery", "6 Rue Jean Goujon", "6 Rue Jean Goujon  ", 43.6017932127, 1.45804866294 },
	{ 249, 0, "00249 - Croix Daurade", "147 Rte D'Albi", "147 Rte D'Albi  ", 43.6381289958, 1.4652119871 },
        { 242, 0, "00242 - Raimbaud / Colette", "Rue Raimbaud Angle Rue Colette", "Rue Raimbaud Angle Rue Colette  ", 43.6338661782, 1.4374937962 },
	{ 252, 0, "00252 - Negreneys /Caseneuve", "161/163 Av De Negreneys Sur Ilot Central", "161/163 Av De Negreneys Sur Ilot Central  ", 43.6273575776, 1.44608509562 },
        { 235, 0, "00235 - Paul Verlaine", "Rue Paul Verlaine", "Rue Paul Verlaine", 43.6333722271, 1.43538536091 },
        { 243, 0, "00243 - Etats-Unis / Ferry", "Av Des Etats-Unis", "Av Des Etats-Unis", 43.6326412375, 1.43180804154 },
        { 180, 0, "00180 - Place Soupetard", "Place Soupetard", "Place Soupetard", 43.6122515816, 1.47765639323 },
	{ 226, 0, "00226 - Fontaines /Casselardit", "292 Rue Des Fontaines", "292 Rue Des Fontaines  ", 43.6041904084, 1.40721128993 },
	{ 156, 0, "00156 - Metro Empalot", "38 Av Jean Moulin Face Debouche Rue De Cannes", "38 Av Jean Moulin Face Debouche Rue De Cannes  ", 43.5797371157, 1.44178328913 },
	{ 207, 0, "00207 - Christ Roi", "Face 25 Rue De L Aude", "Face 25 Rue De L Aude  ", 43.5830069838, 1.48150897257 },
        { 186, 0, "00186 - Desbals Boualam", "Rue Henri Desbals", "Rue Henri Desbals", 43.5792182219, 1.41112908179 },
	{ 150, 0, "00150 - Curie Campistron", "78 Bd Pierre Et Marie Curie", "78 Bd Pierre Et Marie Curie  ", 43.6259309595, 1.43987090057 },
	{ 224, 0, "00224 - Campus Supaero", "Avenue Edouard Belin Face Château Du Creps", "Avenue Edouard Belin Face Château Du Creps  ", 43.5665957614, 1.4748819617 },
	{ 223, 0, "00223 - Enac", "Avenue Edouard Belin Angle Av Roche", "Avenue Edouard Belin Angle Av Roche  ", 43.5651043006, 1.47834074103 },
	{ 225, 0, "00225 - Belin Onera", "Avenue Edouard Belin Devant Onera", "Avenue Edouard Belin Devant Onera  ", 43.5694770721, 1.47326855435 },
        { 222, 0, "00222 - Cambou / Roche", "Rond Point Prof Francis Cambou", "Rond Point Prof Francis Cambou", 43.5628140764, 1.47517386253 },
	{ 9, 0, "00009 - Maillart - Roquemaurel", "Rue Roquemaurel Angle Rue Ella Maillard", "Rue Roquemaurel Angle Rue Ella Maillard  ", 43.595982734, 1.41021417918 },
	{ 200, 0, "00200 - Place De L'Ormeau", "Face 345 Av Jean Rieux", "Face 345 Av Jean Rieux  ", 43.5790692297, 1.48366977505 },
	{ 253, 0, "00253 - Etats-Unis / Robert", "Av Des Etats-Unis Face Au 68 / 70", "Av Des Etats-Unis Face Au 68 / 70  ", 43.6319121123, 1.43168347755 },
	{ 241, 0, "00241 - Espagne Charpentier", "57 Route D'Espagne", "57 Route D'Espagne  ", 43.5745765451, 1.42443256467 },
        { 181, 0, "00181 - Plana Garnier", "Rue Louis Plana", "Rue Louis Plana", 43.6105494206, 1.47950048168 },
	{ 230, 0, "00230 - Rangueil Tripode B", "141 Av De Rangueil", "141 Av De Rangueil  ", 43.5672211537, 1.46767832356 },
	{ 231, 0, "00231 - Narbonne Marfaing", "Rangueil / Cl Roche", "Rangueil / Cl Roche  ", 43.5572436952, 1.46537065799 },
        { 183, 0, "00183 - Rue De Cugnaux", "Rue De Cugnaux", "Rue De Cugnaux", 43.593130181, 1.42463077629 },
	{ 206, 0, "00206 - Leygue/ Rieux", "20 Av Armand Leygue", "20 Av Armand Leygue  ", 43.5943415059, 1.46466841911 },
	{0, 0, NULL, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateToulouse : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateToulouse() {
    rect = QRectF(QPointF(43.555531897661, 1.400592104323), QPointF(43.644545367270, 1.489530191453));
    center = QPointF(43.600038632465, 1.445061147888);
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

