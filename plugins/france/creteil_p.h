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

#ifndef STATIONS_SIMPLE_PRIVATE_CRETEIL_H
#define STATIONS_SIMPLE_PRIVATE_CRETEIL_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
//	{ 53001, 0, "53001 - Pon01 - Rue Sere-Depoin (Cb)", "Place Du Général De Gaulle Devant La Gare -", 49.047622, 2.095547 },
//	{ 54902, 0, "54902 - Vau02 - Mairie Croix-Lieu(Cb)", "Rond Point De La Croix Lieu Côté Avenue Gandhi -", 49.030106, 2.021573 },
//	{ 50012, 0, "50012 - Cer12 - Place Du Haut-Gency", "Place Du Haut De Gency Angle Rue Des Vendanges Prochaines -", 49.047823, 2.044760 },
//	{ 50002, 0, "50002 - Cer02 - Avenue Du Hazay", "Avenue Du Hazay Angle Rue De La Destinée -", 49.042052, 2.019491 },
//	{ 50005, 0, "50005 - Cer05 - Moulin A Vent", "Avenue Du Hazay Angle Rue De L'Aisselette -", 49.049522, 2.016943 },
//	{ 50015, 0, "50015 - Cer15 - Place Des Linandes (Cb)", "Place Des Linandes -", 49.043928, 2.069825 },
//	{ 56103, 0, "56103 - Era03 - Gare D'Eragny (Cb)", "Rue Des Belles Hâtes Angle Boulevard Des Aviateurs Alliés", 49.018057, 2.091026 },
//	{ 50013, 0, "50013 - Cer13 - Rond-Point Des Raies", "Allée Du Belvédère Angle Rond Point Des Raies -", 49.044905, 2.053361 },
//	{ 50016, 0, "50016 - Cer16 - Université Les Chênes (Cb)", "Rue Des Chênes D'Or Angle Boulevard Du Port -", 49.037762, 2.073068 },
//	{ 50014, 0, "50014 - Cer14 - Avenue Du Nord", "Avenue Du Nord Angle Allée Des Acacias -", 49.043260, 2.060451 },
//	{ 50022, 0, "50022 - Cer22 - Gare Cergy Grand Centre (Cb)", "Boulevard De L'Oise / Rue De La Gare -", 49.035362, 2.081226 },
//	{ 56106, 0, "56106 - Era06 - Centre Technique Municipal", "Rue De L'Ambassadeur Angle Rue Des Anglais -", 49.011216, 2.098463 },
//	{ 54903, 0, "54903 - Vau03 - Le Boulingrin", "Avenue Simone Signoret Angle Rue De L'Enfance -", 49.026275, 2.016951 },
//	{ 50019, 0, "50019 - Cer19 - Rue Des Lilas", "Rue Des Lilas Angle Boulevard Du Port -", 49.034953, 2.066632 },
//	{ 50008, 0, "50008 - Cer08 - Axe Majeur (Cb)", "Rue De L'Esplanade De Paris Angle Boulevard De L'Oise -", 49.044065, 2.036853 },
//	{ 50011, 0, "50011 - Cer11 - Place De L'Hotel De Ville (Cb)", "Rue Des Gémeaux -", 49.051274, 2.037590 },
//	{ 50006, 0, "50006 - Cer06 - Le Chat Perché", "Avenue De La Belle Heaumière Angle Square De L'Echiquier -", 49.048829, 2.026845 },
//	{ 53003, 0, "53003 - Pon03 - Université St Martin", "Avenue François Mitterand Côté Boulevard Du Port -", 49.043583, 2.084808 },
//	{ 50018, 0, "50018 - Cer18 - Port Cergy (Cb)", "Boulevard Du Port Angle Rue Jean Bart -", 49.031482, 2.061676 },
//	{ 56104, 0, "56104 - Era04 - La Challe (Cb)", "Place De La Challe Angle Rue De La Challe Orange", 49.017697, 2.099417 },
//	{ 50023, 0, "50023 - Cer23 - Les Touleuses", "Avenue Du Sud -", 49.030440, 2.082153 },
//	{ 50010, 0, "50010 - Cer10 - Gare Cergy Axe Maj Horloge (Cb)", "Rue Des Pas Perdus -", 49.049358, 2.033459 },
//	{ 54901, 0, "54901 - Vau01 - Place Du Rdv (Cb)", "Place Du Rendez-Vous Côté Avenue Louis Lecoin -", 49.032934, 2.020312 },
//	{ 54904, 90, "54904 - Vau04 - Mendes France", "Mail Mendes France Angle Boulevard De L'Oise -", 27.140973, -3.404561 },
//	{ 50004, 0, "50004 - Cer04 - Le Bon Temps", "Avenue Du Bon Temps Angle Avenue Du Hazay -", 49.052297, 2.023270 },
//	{ 53002, 0, "53002 - Pon02 - Place De La Libération", "Place De La Libération Côté Avenue De Verdun -", 49.044683, 2.090817 },
//	{ 54905, 90, "54905 - Vau05 - Les Toupets", "Mail Mendes France Angle Avenue De La Revolution Francaise -", 27.140973, -3.404561 },
//	{ 56102, 0, "56102 - Era02 - Charles De Gaulle", "Avenue Fernand Chatelain Angle Rue De Pierrelaye", 49.023065, 2.110460 },
//	{ 50021, 0, "50021 - Cer21 - Dalle Piétonne Grand Centre", "Boulevard De L'Oise / Rue De La Gare -", 49.036007, 2.080075 },
//	{ 53102, 0, "53102 - Soa02 - Gare Soa Centre", "Av Du Général Leclerc / Rue Du 8 Mai 1945 -", 49.046249, 2.105710 },
//	{ 56401, 0, "56401 - Cou01 - La Louviere (Cb)", "Boulevard Des Chasseurs Angle Boulevard Sainte Apolline -", 49.045223, 2.002507 },
//	{ 50017, 0, "50017 - Cer17 - Cergy Village Centre", "Rue Nationale Angle Rue Levèque -", 49.036577, 2.061676 },
//	{ 53101, 0, "53101 - Soa01 - Place Carnot (Cb)", "Place Carnot Côté Quai De L'Ecluse Ou Halage -", 49.047781, 2.103038 },
//	{ 50001, 0, "50001 - Cer01 - Gare Les Hauts De Cergy", "Place Des 3 Gares -", 49.048214, 2.011811 },
//	{ 56101, 0, "56101 - Era01 - La Danne", "Boulevard Charles De Gaulle Angle Boulevard Jacques Duclos", 49.024211, 2.103268 },
//	{ 50007, 0, "50007 - Cer07 -  Parc St-Christophe", "Avenue De L'Entreprise Angle Rond Point Du Cèdre -", 49.042888, 2.029711 },
//	{ 50003, 0, "50003 - Cer03 - Les Essarts (Cb)", "Avenue Des Essarts Angle Boulevard De L'Oise -", 49.042052, 2.019491 },
//	{ 50009, 0, "50009 - Cer09 - Rue Du Brûloir", "88, Rue Du Brûloir Angle Rue Des Touleuses Pourpres -", 49.028683, 2.071981 },
	{ 1, 0, "01 - Lattre De Tassigny", "Avenue Du Marechal De Lattre De Tassigny", 48.798835, 2.453876 },
	{ 2, 0, "02 - Hopital Intercommunal (Chic)", "Avenue De Verdun", 48.796174, 2.463706 },
	{ 3, 0, "03 - Rue Du General Leclerc - Centre Ancien", "Allée De La Porte De Brie", 48.790789, 2.464890 },
	{ 4, 0, "04 - Universite - Mail Des Meches", "Avenue Du Général De Gaulle", 48.788111, 2.446249 },
	{ 5, 0, "05 - Rue Du General Leclerc - Rue Du Barrage", "144 Rue Du General Leclerc", 48.786839, 2.468567 },
	{ 6, 0, "06 - Avenue De La Breche", "Avenue De La Breche", 48.783501, 2.454576 },
	{ 7, 0, "07- Avenue Du Docteur Paul Casalis", "Avenue Du Docteur Paul Casalis", 48.780214, 2.469692 },
	{ 8, 0, "08 - Rond Point Hotel De Ville", "Avenue De La France Libre", 48.777352, 2.455378 },
	{ 9, 0, "09 - Europarc", "Allee Fernand Pouillon", 48.766038, 2.471315 },
	{ 10, 0, "10 - Magellan", "Rue Magellan", 48.768956, 2.456665 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateCreteil : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateCreteil() {
    rect = QRectF(QPointF(48.589613, 2.446249), QPointF(48.798835, 2.652628));
    center = QPointF(48.789613, 2.452628);
    statusUrl = "http://www.cristolib.fr/service/stationdetails/%1";
    infosUrl = "http://www.cristolib.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Creteil %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;

    ret << "0";
    ret << "90";
    ret << "10";

    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_CRETEIL_H */

