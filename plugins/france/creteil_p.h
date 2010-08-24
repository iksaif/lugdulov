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
        const char *fullAddress;
        double x;
        double y;
} stations[] = {
//	{ 53001, 0, "53001 - Pon01 - Rue Sere-Depoin (Cb)", "Place Du Général De Gaulle Devant La Gare -", "Place Du Général De Gaulle Devant La Gare - 95300 Pontoise", 49.0476219606, 2.09554701549 },
//	{ 54902, 90, "54902 - Vau02 - Mairie Croix-Lieu(Cb)", "Rond Point De La Croix Lieu Côté Avenue Gandhi -", "Rond Point De La Croix Lieu Côté Avenue Gandhi - 95490 Vaureal", 49.0301063149, 2.02157338053 },
//	{ 50012, 0, "50012 - Cer12 - Place Du Haut-Gency", "Place Du Haut De Gency Angle Rue Des Vendanges Prochaines -", "Place Du Haut De Gency Angle Rue Des Vendanges Prochaines - 95000 Cergy", 49.0478230228, 2.04475984672 },
//	{ 50002, 0, "50002 - Cer02 - Avenue Du Hazay", "Avenue Du Hazay Angle Rue De La Destinée -", "Avenue Du Hazay Angle Rue De La Destinée - 95000 Cergy", 49.0420523784, 2.01949103979 },
//	{ 50005, 0, "50005 - Cer05 - Moulin A Vent", "Avenue Du Hazay Angle Rue De L'Aisselette -", "Avenue Du Hazay Angle Rue De L'Aisselette - 95000 Cergy", 49.0495219954, 2.01694329051 },
//	{ 50015, 0, "50015 - Cer15 - Place Des Linandes (Cb)", "Place Des Linandes -", "Place Des Linandes - 95000 Cergy", 49.0439278452, 2.06982453728 },
//	{ 56103, 0, "56103 - Era03 - Gare D'Eragny (Cb)", "Rue Des Belles Hâtes Angle Boulevard Des Aviateurs Alliés", "Rue Des Belles Hâtes Angle Boulevard Des Aviateurs Alliés 95600 - Eragny", 49.0180572988, 2.09102626847 },
//	{ 50013, 0, "50013 - Cer13 - Rond-Point Des Raies", "Allée Du Belvédère Angle Rond Point Des Raies -", "Allée Du Belvédère Angle Rond Point Des Raies - 95000 Cergy", 49.0449053132, 2.05336101556 },
//	{ 50016, 0, "50016 - Cer16 - Université Les Chênes (Cb)", "Rue Des Chênes D'Or Angle Boulevard Du Port -", "Rue Des Chênes D'Or Angle Boulevard Du Port - 95000 Cergy", 49.0377616122, 2.07306841113 },
//	{ 50014, 0, "50014 - Cer14 - Avenue Du Nord", "Avenue Du Nord Angle Allée Des Acacias -", "Avenue Du Nord Angle Allée Des Acacias - 95000 Cergy", 49.0432595138, 2.06045080063 },
//	{ 50022, 0, "50022 - Cer22 - Gare Cergy Grand Centre (Cb)", "Boulevard De L'Oise / Rue De La Gare -", "Boulevard De L'Oise / Rue De La Gare - 95000 Cergy", 49.0353620952, 2.08122638022 },
//	{ 56106, 10, "56106 - Era06 - Centre Technique Municipal", "Rue De L'Ambassadeur Angle Rue Des Anglais -", "Rue De L'Ambassadeur Angle Rue Des Anglais - 95610 Eragny", 49.0112158546, 2.09846305412 },
//	{ 54903, 90, "54903 - Vau03 - Le Boulingrin", "Avenue Simone Signoret Angle Rue De L'Enfance -", "Avenue Simone Signoret Angle Rue De L'Enfance - 95490 Vaureal", 49.026274876, 2.01695070866 },
//	{ 50019, 0, "50019 - Cer19 - Rue Des Lilas", "Rue Des Lilas Angle Boulevard Du Port -", "Rue Des Lilas Angle Boulevard Du Port - 95000 Cergy", 49.0349525288, 2.06663186197 },
//	{ 50008, 0, "50008 - Cer08 - Axe Majeur (Cb)", "Rue De L'Esplanade De Paris Angle Boulevard De L'Oise -", "Rue De L'Esplanade De Paris Angle Boulevard De L'Oise - 95000 Cergy", 49.0440652155, 2.03685274589 },
//	{ 50011, 0, "50011 - Cer11 - Place De L'Hotel De Ville (Cb)", "Rue Des Gémeaux -", "Rue Des Gémeaux - 95000 Cergy", 49.0512738799, 2.03759010503 },
//	{ 50006, 0, "50006 - Cer06 - Le Chat Perché", "Avenue De La Belle Heaumière Angle Square De L'Echiquier -", "Avenue De La Belle Heaumière Angle Square De L'Echiquier - 95000 Cergy", 49.0488292266, 2.02684530522 },
//	{ 53003, 0, "53003 - Pon03 - Université St Martin", "Avenue François Mitterand Côté Boulevard Du Port -", "Avenue François Mitterand Côté Boulevard Du Port - 95300 Pontoise", 49.0435830059, 2.08480805038 },
//	{ 50018, 0, "50018 - Cer18 - Port Cergy (Cb)", "Boulevard Du Port Angle Rue Jean Bart -", "Boulevard Du Port Angle Rue Jean Bart - 95000 Cergy", 49.0314815358, 2.06167551615 },
//	{ 56104, 10, "56104 - Era04 - La Challe (Cb)", "Place De La Challe Angle Rue De La Challe Orange", "Place De La Challe Angle Rue De La Challe Orange 95600 - Eragny", 49.0176968699, 2.09941682485 },
//	{ 50023, 0, "50023 - Cer23 - Les Touleuses", "Avenue Du Sud -", "Avenue Du Sud - 95000 Cergy", 49.0304396655, 2.08215272005 },
//	{ 50010, 0, "50010 - Cer10 - Gare Cergy Axe Maj Horloge (Cb)", "Rue Des Pas Perdus -", "Rue Des Pas Perdus - 95000 Cergy", 49.0493584167, 2.03345889822 },
//	{ 54901, 90, "54901 - Vau01 - Place Du Rdv (Cb)", "Place Du Rendez-Vous Côté Avenue Louis Lecoin -", "Place Du Rendez-Vous Côté Avenue Louis Lecoin - 95490 Vaureal", 49.0329336268, 2.02031244242 },
//	{ 54904, 90, "54904 - Vau04 - Mendes France", "Mail Mendes France Angle Boulevard De L'Oise -", "Mail Mendes France Angle Boulevard De L'Oise - 95490 Vaureal", 27.1409733745, -3.40456062425 },
//	{ 50004, 0, "50004 - Cer04 - Le Bon Temps", "Avenue Du Bon Temps Angle Avenue Du Hazay -", "Avenue Du Bon Temps Angle Avenue Du Hazay - 95000 Cergy", 49.0522974873, 2.02326979765 },
//	{ 53002, 0, "53002 - Pon02 - Place De La Libération", "Place De La Libération Côté Avenue De Verdun -", "Place De La Libération Côté Avenue De Verdun - 95300 Pontoise", 49.0446828562, 2.09081736443 },
//	{ 54905, 90, "54905 - Vau05 - Les Toupets", "Mail Mendes France Angle Avenue De La Revolution Francaise -", "Mail Mendes France Angle Avenue De La Revolution Francaise - 95490 Vaureal", 27.1409733745, -3.40456062425 },
//	{ 56102, 0, "56102 - Era02 - Charles De Gaulle", "Avenue Fernand Chatelain Angle Rue De Pierrelaye", "Avenue Fernand Chatelain Angle Rue De Pierrelaye 95600 - Eragny", 49.0230651499, 2.11045997988 },
//	{ 50021, 0, "50021 - Cer21 - Dalle Piétonne Grand Centre", "Boulevard De L'Oise / Rue De La Gare -", "Boulevard De L'Oise / Rue De La Gare - 95000 Cergy", 49.0360066253, 2.08007512081 },
//	{ 53102, 10, "53102 - Soa02 - Gare Soa Centre", "Av Du Général Leclerc / Rue Du 8 Mai 1945 -", "Av Du Général Leclerc / Rue Du 8 Mai 1945 - 95310 Saint Ouen L'Aumone", 49.0462492384, 2.10571036092 },
//	{ 56401, 0, "56401 - Cou01 - La Louviere (Cb)", "Boulevard Des Chasseurs Angle Boulevard Sainte Apolline -", "Boulevard Des Chasseurs Angle Boulevard Sainte Apolline - 95400 Courdimanche", 49.0452230558, 2.00250714774 },
//	{ 50017, 0, "50017 - Cer17 - Cergy Village Centre", "Rue Nationale Angle Rue Levèque -", "Rue Nationale Angle Rue Levèque - 95000 Cergy", 49.0365766826, 2.06167568 },
//	{ 53101, 10, "53101 - Soa01 - Place Carnot (Cb)", "Place Carnot Côté Quai De L'Ecluse Ou Halage -", "Place Carnot Côté Quai De L'Ecluse Ou Halage - 95310 Saint Ouen L'Aumone", 49.0477806445, 2.10303773922 },
//	{ 50001, 0, "50001 - Cer01 - Gare Les Hauts De Cergy", "Place Des 3 Gares -", "Place Des 3 Gares - 95000 Cergy", 49.0482141459, 2.01181120612 },
//	{ 56101, 10, "56101 - Era01 - La Danne", "Boulevard Charles De Gaulle Angle Boulevard Jacques Duclos", "Boulevard Charles De Gaulle Angle Boulevard Jacques Duclos 95600 - Eragny", 49.0242105063, 2.10326752164 },
//	{ 50007, 0, "50007 - Cer07 -  Parc St-Christophe", "Avenue De L'Entreprise Angle Rond Point Du Cèdre -", "Avenue De L'Entreprise Angle Rond Point Du Cèdre - 95000 Cergy", 49.0428878519, 2.0297105452 },
//	{ 50003, 0, "50003 - Cer03 - Les Essarts (Cb)", "Avenue Des Essarts Angle Boulevard De L'Oise -", "Avenue Des Essarts Angle Boulevard De L'Oise - 95000 Cergy", 49.0420523784, 2.01949103979 },
//	{ 50009, 0, "50009 - Cer09 - Rue Du Brûloir", "88, Rue Du Brûloir Angle Rue Des Touleuses Pourpres -", "88, Rue Du Brûloir Angle Rue Des Touleuses Pourpres - 95000 Cergy", 49.0286831905, 2.07198057754 },
	{ 1, 0, "01 - Lattre De Tassigny", "Avenue Du Marechal De Lattre De Tassigny", "Avenue Du Marechal De Lattre De Tassigny  ", 48.7988350968, 2.45387633773 },
	{ 2, 0, "02 - Hopital Intercommunal (Chic)", "Avenue De Verdun", "Avenue De Verdun  ", 48.7961736331, 2.46370624552 },
	{ 3, 0, "03 - Rue Du General Leclerc - Centre Ancien", "Allée De La Porte De Brie", "Allée De La Porte De Brie  ", 48.7907886168, 2.46489018474 },
	{ 4, 0, "04 - Universite - Mail Des Meches", "Avenue Du Général De Gaulle", "Avenue Du Général De Gaulle  ", 48.7881107808, 2.44624865216 },
	{ 5, 0, "05 - Rue Du General Leclerc - Rue Du Barrage", "144 Rue Du General Leclerc", "144 Rue Du General Leclerc  ", 48.7868389124, 2.46856657249 },
	{ 6, 0, "06 - Avenue De La Breche", "Avenue De La Breche", "Avenue De La Breche  ", 48.7835010267, 2.4545763584 },
	{ 7, 0, "07- Avenue Du Docteur Paul Casalis", "Avenue Du Docteur Paul Casalis", "Avenue Du Docteur Paul Casalis  ", 48.7802135295, 2.46969223099 },
	{ 8, 0, "08 - Rond Point Hotel De Ville", "Avenue De La France Libre", "Avenue De La France Libre  ", 48.7773524472, 2.45537843176 },
	{ 9, 0, "09 - Europarc", "Allee Fernand Pouillon", "Allee Fernand Pouillon  ", 48.7660375642, 2.47131485523 },
	{ 10, 0, "10 - Magellan", "Rue Magellan", "Rue Magellan  ", 48.7689563311, 2.45666466766 },
	{0, 0, NULL, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateCreteil : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateCreteil() {
    rect = QRectF(QPointF(48.765381613571, 2.445747328097), QPointF(48.799491047434, 2.471816179287));
    center = QPointF(48.782436330502, 2.458781753692);
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

