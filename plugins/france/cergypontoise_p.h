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

#ifndef STATIONS_SIMPLE_PRIVATE_CERGYPONTOISE_H
#define STATIONS_SIMPLE_PRIVATE_CERGYPONTOISE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
//	{ 53004, 0, "53004 - Pon04 - La Palette", "Bd De L'Oise Angle Rue De La Palette", 27.1409734276, -3.40456063168 },
//	{ 50101, 0, "50101 - Pôle Gare (Cb)", "Chemin De Cergy Devant La Gare -", 27.1409734276, -3.40456063168 },
	{ 53001, 0, "53001 - Pon01 - Rue Sere-Depoin (Cb)", "Place Du Général De Gaulle Devant La Gare -", 49.0476219606, 2.09554701549 },
	{ 54902, 0, "54902 - Vau02 - Mairie Croix-Lieu(Cb)", "Rond Point De La Croix Lieu Côté Avenue Gandhi -", 49.0301063149, 2.02157338053 },
	{ 50012, 0, "50012 - Cer12 - Place Du Haut-Gency", "Place Du Haut De Gency Angle Rue Des Vendanges Prochaines -", 49.0478230228, 2.04475984672 },
	{ 50002, 0, "50002 - Cer02 - Avenue Du Hazay", "Avenue Du Hazay Angle Rue De La Destinée -", 49.0420523784, 2.01949103979 },
	{ 50005, 0, "50005 - Cer05 - Moulin A Vent", "Avenue Du Hazay Angle Rue De L'Aisselette -", 49.0495219954, 2.01694329051 },
	{ 50015, 0, "50015 - Cer15 - Place Des Linandes (Cb)", "Place Des Linandes -", 49.0439278452, 2.06982453728 },
	{ 56103, 0, "56103 - Era03 - Gare D'Eragny (Cb)", "Rue Des Belles Hâtes Angle Boulevard Des Aviateurs Alliés", 49.0180572988, 2.09102626847 },
	{ 50013, 0, "50013 - Cer13 - Rond-Point Des Raies", "Allée Du Belvédère Angle Rond Point Des Raies -", 49.0449053132, 2.05336101556 },
	{ 50016, 0, "50016 - Cer16 - Université Les Chênes (Cb)", "Rue Des Chênes D'Or Angle Boulevard Du Port -", 49.0377616122, 2.07306841113 },
	{ 50014, 0, "50014 - Cer14 - Avenue Du Nord", "Avenue Du Nord Angle Allée Des Acacias -", 49.0432595138, 2.06045080063 },
	{ 50022, 0, "50022 - Cer22 - Gare Cergy Grand Centre (Cb)", "Boulevard De L'Oise / Rue De La Gare -", 49.0353620952, 2.08122638022 },
	{ 56106, 0, "56106 - Era06 - Centre Technique Municipal", "Rue De L'Ambassadeur Angle Rue Des Anglais -", 49.0112158546, 2.09846305412 },
	{ 54903, 0, "54903 - Vau03 - Le Boulingrin", "Avenue Simone Signoret Angle Rue De L'Enfance -", 49.026274876, 2.01695070866 },
	{ 50019, 0, "50019 - Cer19 - Rue Des Lilas", "Rue Des Lilas Angle Boulevard Du Port -", 49.0349525288, 2.06663186197 },
	{ 50008, 0, "50008 - Cer08 - Axe Majeur (Cb)", "Rue De L'Esplanade De Paris Angle Boulevard De L'Oise -", 49.0440652155, 2.03685274589 },
	{ 50011, 0, "50011 - Cer11 - Place De L'Hotel De Ville (Cb)", "Rue Des Gémeaux -", 49.0512738799, 2.03759010503 },
	{ 50006, 0, "50006 - Cer06 - Le Chat Perché", "Avenue De La Belle Heaumière Angle Square De L'Echiquier -", 49.0488292266, 2.02684530522 },
	{ 53003, 0, "53003 - Pon03 - Université St Martin", "Avenue François Mitterand Côté Boulevard Du Port -", 49.0435830059, 2.08480805038 },
	{ 50018, 0, "50018 - Cer18 - Port Cergy (Cb)", "Boulevard Du Port Angle Rue Jean Bart -", 49.0314815358, 2.06167551615 },
	{ 56104, 0, "56104 - Era04 - La Challe (Cb)", "Place De La Challe Angle Rue De La Challe Orange", 49.0176968699, 2.09941682485 },
	{ 50023, 0, "50023 - Cer23 - Les Touleuses", "Avenue Du Sud -", 49.0304396655, 2.08215272005 },
	{ 50010, 0, "50010 - Cer10 - Gare Cergy Axe Maj Horloge (Cb)", "Rue Des Pas Perdus -", 49.0493584167, 2.03345889822 },
	{ 54901, 0, "54901 - Vau01 - Place Du Rdv (Cb)", "Place Du Rendez-Vous Côté Avenue Louis Lecoin -", 49.0329336268, 2.02031244242 },
//	{ 54904, 90, "54904 - Vau04 - Mendes France", "Mail Mendes France Angle Boulevard De L'Oise -", 27.1409733745, -3.40456062425 },
	{ 50004, 0, "50004 - Cer04 - Le Bon Temps", "Avenue Du Bon Temps Angle Avenue Du Hazay -", 49.0522974873, 2.02326979765 },
	{ 53002, 0, "53002 - Pon02 - Place De La Libération", "Place De La Libération Côté Avenue De Verdun -", 49.0446828562, 2.09081736443 },
//	{ 54905, 90, "54905 - Vau05 - Les Toupets", "Mail Mendes France Angle Avenue De La Revolution Francaise -", 27.1409733745, -3.40456062425 },
	{ 56102, 0, "56102 - Era02 - Charles De Gaulle", "Avenue Fernand Chatelain Angle Rue De Pierrelaye", 49.0230651499, 2.11045997988 },
	{ 50021, 0, "50021 - Cer21 - Dalle Piétonne Grand Centre", "Boulevard De L'Oise / Rue De La Gare -", 49.0360066253, 2.08007512081 },
	{ 53102, 0, "53102 - Soa02 - Gare Soa Centre", "Av Du Général Leclerc / Rue Du 8 Mai 1945 -", 49.0462492384, 2.10571036092 },
	{ 56401, 0, "56401 - Cou01 - La Louviere (Cb)", "Boulevard Des Chasseurs Angle Boulevard Sainte Apolline -", 49.0452230558, 2.00250714774 },
	{ 50017, 0, "50017 - Cer17 - Cergy Village Centre", "Rue Nationale Angle Rue Levèque -", 49.0365766826, 2.06167568 },
	{ 53101, 0, "53101 - Soa01 - Place Carnot (Cb)", "Place Carnot Côté Quai De L'Ecluse Ou Halage -", 49.0477806445, 2.10303773922 },
	{ 50001, 0, "50001 - Cer01 - Gare Les Hauts De Cergy", "Place Des 3 Gares -", 49.0482141459, 2.01181120612 },
	{ 56101, 0, "56101 - Era01 - La Danne", "Boulevard Charles De Gaulle Angle Boulevard Jacques Duclos", 49.0242105063, 2.10326752164 },
	{ 50007, 0, "50007 - Cer07 -  Parc St-Christophe", "Avenue De L'Entreprise Angle Rond Point Du Cèdre -", 49.0428878519, 2.0297105452 },
	{ 50003, 0, "50003 - Cer03 - Les Essarts (Cb)", "Avenue Des Essarts Angle Boulevard De L'Oise -", 49.0420523784, 2.01949103979 },
	{ 50009, 0, "50009 - Cer09 - Rue Du Brûloir", "88, Rue Du Brûloir Angle Rue Des Touleuses Pourpres -", 49.0286831905, 2.07198057754 },
	{ 54903, 0, "54903 - Vau03 - Le Boulingrin", "Avenue Simone Signoret Angle Rue De L'Enfance -", 49.0262748408, 2.01695069553 },
	{ 50009, 0, "50009 - Cer09 - Rue Du Brûloir", "88, Rue Du Brûloir Angle Rue Des Touleuses Pourpres -", 49.0286831553, 2.07198056447 },
	{ 54905, 0, "54905 - Vau05 - Les Toupets", "Mail Mendes France Angle Avenue De La Revolution Francaise -", 49.0231625956, 2.02948629121 },
	{ 53003, 0, "53003 - Pon03 - Université St Martin", "Avenue François Mitterand Côté Boulevard Du Port -", 49.0435829707, 2.08480803732 },
	{ 53101, 0, "53101 - Soa01 - Place Carnot (Cb)", "Place Carnot Côté Quai De L'Ecluse Ou Halage -", 49.0477806094, 2.10303772617 },
	{ 50005, 0, "50005 - Cer05 - Moulin A Vent", "Avenue Du Hazay Angle Rue De L'Aisselette -", 49.0495219603, 2.01694327738 },
	{ 50011, 0, "50011 - Cer11 - Place De L'Hotel De Ville (Cb)", "Rue Des Gémeaux -", 49.0512738448, 2.03759009192 },
	{ 56103, 0, "56103 - Era03 - Gare D'Eragny (Cb)", "Rue Des Belles Hâtes Angle Boulevard Des Aviateurs Alliés", 49.0180572637, 2.09102625542 },
	{ 56101, 0, "56101 - Era01 - La Danne", "Boulevard Charles De Gaulle Angle Boulevard Jacques Duclos", 49.0242104711, 2.1032675086 },
	{ 53002, 0, "53002 - Pon02 - Place De La Libération", "Place De La Libération Côté Avenue De Verdun -", 49.0446828211, 2.09081735137 },
	{ 50023, 0, "50023 - Cer23 - Les Touleuses", "Avenue Du Sud -", 49.0304396304, 2.08215270699 },
	{ 50008, 0, "50008 - Cer08 - Axe Majeur (Cb)", "Rue De L'Esplanade De Paris Angle Boulevard De L'Oise -", 49.0440651804, 2.03685273278 },
	{ 53102, 0, "53102 - Soa02 - Gare Soa Centre", "Av Du Général Leclerc / Rue Du 8 Mai 1945 -", 49.0462492033, 2.10571034787 },
	{ 50017, 0, "50017 - Cer17 - Cergy Village Centre", "Rue Nationale Angle Rue Levèque -", 49.0365766475, 2.06167566691 },
	{ 56102, 0, "56102 - Era02 - Charles De Gaulle", "Avenue Fernand Chatelain Angle Rue De Pierrelaye", 49.0230651148, 2.11045996685 },
	{ 50003, 0, "50003 - Cer03 - Les Essarts (Cb)", "Avenue Des Essarts Angle Boulevard De L'Oise -", 49.0420523432, 2.01949102666 },
	{ 56106, 0, "56106 - Era06 - Centre Technique Municipal", "Rue De L'Ambassadeur Angle Rue Des Anglais -", 49.0112158195, 2.09846304107 },
	{ 56104, 0, "56104 - Era04 - La Challe (Cb)", "Place De La Challe Angle Rue De La Challe Orange", 49.0176968348, 2.09941681181 },
	{ 50019, 0, "50019 - Cer19 - Rue Des Lilas", "Rue Des Lilas Angle Boulevard Du Port -", 49.0349524936, 2.06663184889 },
	{ 50021, 0, "50021 - Cer21 - Dalle Piétonne Grand Centre", "Boulevard De L'Oise / Rue De La Gare -", 49.0360065902, 2.08007510774 },
	{ 50013, 0, "50013 - Cer13 - Rond-Point Des Raies", "Allée Du Belvédère Angle Rond Point Des Raies -", 49.0449052781, 2.05336100247 },
	{ 50004, 0, "50004 - Cer04 - Le Bon Temps", "Avenue Du Bon Temps Angle Avenue Du Hazay -", 49.0522974522, 2.02326978453 },
	{ 50002, 0, "50002 - Cer02 - Avenue Du Hazay", "Avenue Du Hazay Angle Rue De La Destinée -", 49.0420523432, 2.01949102666 },
	{ 50010, 0, "50010 - Cer10 - Gare Cergy Axe Maj Horloge (Cb)", "Rue Des Pas Perdus -", 49.0493583816, 2.0334588851 },
	{ 53001, 0, "53001 - Pon01 - Rue Sere-Depoin (Cb)", "Place Du Général De Gaulle Devant La Gare -", 49.0476219255, 2.09554700243 },
	{ 50001, 0, "50001 - Cer01 - Gare Les Hauts De Cergy(Cb)", "Place Des 3 Gares -", 49.0482141108, 2.01181119299 },
	{ 54902, 0, "54902 - Vau02 - Mairie Croix-Lieu(Cb)", "Rond Point De La Croix Lieu Côté Avenue Gandhi -", 49.0301062798, 2.02157336741 },
	{ 56401, 0, "56401 - Cou01 - La Louviere (Cb)", "Boulevard Des Chasseurs Angle Boulevard Sainte Apolline -", 49.0452230206, 2.00250713459 },
	{ 50016, 0, "50016 - Cer16 - Université Les Chênes (Cb)", "Rue Des Chênes D'Or Angle Boulevard Du Port -", 49.0377615771, 2.07306839805 },
	{ 50018, 0, "50018 - Cer18 - Port Cergy (Cb)", "Boulevard Du Port Angle Rue Jean Bart -", 49.0314815006, 2.06167550306 },
	{ 50022, 0, "50022 - Cer22 - Gare Cergy Grand Centre (Cb)", "Boulevard De L'Oise / Rue De La Gare -", 49.0353620601, 2.08122636715 },
	{ 54901, 0, "54901 - Vau01 - Place Du Rdv (Cb)", "Place Du Rendez-Vous Côté Avenue Louis Lecoin -", 49.0329335917, 2.0203124293 },
	{ 50006, 0, "50006 - Cer06 - Le Chat Perché", "Avenue De La Belle Heaumière Angle Square De L'Echiquier -", 49.0488291915, 2.0268452921 },
//	{ 54904, 0, "54904 - Vau04 - Mendes France", "Mail Mendes France Angle Boulevard De L'Oise -", 27.1409734276, -3.40456063168 },
	{ 50012, 0, "50012 - Cer12 - Place Du Haut-Gency", "Place Du Haut De Gency Angle Rue Des Vendanges Prochaines -", 49.0478229877, 2.04475983361 },
	{ 50015, 0, "50015 - Cer15 - Place Des Linandes (Cb)", "Place Des Linandes -", 49.0439278101, 2.0698245242 },
	{ 50007, 0, "50007 - Cer07 -  Parc St-Christophe", "Avenue De L'Entreprise Angle Rond Point Du Cèdre -", 49.0428878168, 2.02971053209 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateCergypontoise : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateCergypontoise() {
    rect = QRectF(QPointF(48.848522, 2.002507), QPointF(49.052297, 2.234237));
    center = QPointF(49.048522, 2.034237);
    statusUrl = "http://www.velo2.cergypontoise.fr/service/stationdetails/%1";
    infosUrl = "http://www.velo2.cergypontoise.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Cergypontoise %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;

    ret << "0";
    ret << "10";
    ret << "90";

    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_CERGYPONTOISE_H */

