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

#ifndef STATIONS_SIMPLE_PRIVATE_PLAINECOMMUNE_H
#define STATIONS_SIMPLE_PRIVATE_PLAINECOMMUNE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 32151, 10, "32151 - Proudhon (Cb)", "Av Du Pdt Wilson / Rue Proudhon -", 48.906263, 2.358945 },
	{ 33052, 0, "33052-Casanova Tillon (Cb)", "Casanova/Tillon-", 48.918682, 2.392932 },
	{ 32180, 10, "32180-Place De La Resistance Et De La Deportation", "Rue Gabriel Peri / Rue Franciade -", 48.937170, 2.356080 },
	{ 32160, 10, "32160-Stade De France", "Chemin Du Cornillon/Rue Francis De Pressence-", 48.919591, 2.362469 },
	{ 32162, 10, "32162-Place Du Cornillon", "Face Au 14 Rue Jesse Owens-", 48.924677, 2.364353 },
	{ 32166, 10, "32166-Porte De Paris/Saint Denis", "58 Rue De La Legion D'Honneur-", 48.930466, 2.356527 },
	{ 32158, 10, "32158 - Fruitiers", "Rue Des Fruitiers Cote Restaurant Zack / Avenue Francois Miterrand -", 48.917974, 2.354736 },
	{ 32179, 10, "32179-Bibliotheque", "Rue Du Cygne/Rue De La Boulangerie/Devant Bibliotheque-", 48.935435, 2.357225 },
	{ 32159, 10, "32159 - Gare Stade De France", "Rue Des Cheminots/Rue De Fellini-", 48.916950, 2.352677 },
	{ 32153, 10, "32153 - Place Du Marche (Cb)", "Avenue Du President Wilson / Rue De Bailly -", 48.910613, 2.358538 },
//	{ 34502, 10, "34502-Square Falker", "Face Au 14 Rue Arnold Geraux-", 27.140973, -3.404561 },
	{ 32157, 10, "32157-Francis De Pressence", "260 Avenue Du President Wilson-", 48.917704, 2.357873 },
	{ 32154, 10, "32154 - Commissariat De Police", "Avenue Du Stade De France / Rue Du Landy -", 48.918989, 2.361800 },
	{ 32176, 10, "32176-Place Du 8 Mai (Cb)", "Rue Gillot-", 48.940109, 2.353816 },
	{ 33063, 0, "33063-Espace Bel Air", "Chemin Du Haut De Saint Denis/Rue Francis Pressence-", 48.923103, 2.367748 },
	{ 31206, 0, "31206 - Carrefour Des 6 Routes", "Carrefour Des 6 Routes, Leclerc / Pasteur -", 48.929703, 2.385388 },
	{ 32161, 10, "32161-Communaute D'Agglomeration (Cb)", "Rue De L'Olympisme/21 Avenue Jules Rimet-", 48.924623, 2.362540 },
	{ 32173, 10, "32173-Maison De Retraite Des Petites Soeurs", "Rue Gaston Dourdin/Rue Pierre Brossolette-", 48.941422, 2.351047 },
	{ 32163, 10, "32163-Passerelle Des Franc Moisin", "Quai Du Canal/Cours Thierry-", 48.929729, 2.352490 },
	{ 32168, 10, "32168-Universite Paris Viii", "Face Au 3 Rue De La Liberte-", 48.945284, 2.363846 },
	{ 32167, 10, "32167-Porte De Paris (Cb)", "1 Avenue Gabriel Peri-", 48.930205, 2.356500 },
	{ 31204, 0, "31204 - Place De La Fraternite", "Avenue General Leclerc, Face Bibliotheque John Lennon -", 48.926102, 2.377842 },
	{ 33051, 0, "33051-Rue Bordier (Cb)", "Rue Bordier/Boulevard Faure -", 48.903874, 2.384873 },
	{ 32177, 10, "32177-Place Des Poulies", "Rue Vaillant-", 48.932181, 2.365135 },
	{ 32174, 10, "32174-Place Du General Leclerc", "Rue Berne/Rue Gabriel Peri-", 48.942391, 2.356409 },
//	{ 34501, 10, "34501-Hotel De Ville (Cb)", "Hotel De Ville-", 27.140973, -3.404561 },
	{ 31202, 0, "31202 - La Poste (Cb)", "58 Rue Gabriel Péri -", 48.926348, 2.391727 },
	{ 32175, 10, "32175-Centre Nautique De La Baleine", "Avenue Moulin/Rue Guuy Mocquet-", 48.940754, 2.363489 },
	{ 32170, 10, "32170-Sembat/Guesde", "64 Boulevard Marcel Sembat-", 48.933073, 2.351509 },
	{ 32171, 10, "32171-Gare Saint Denis (Cb)", "Quai Du Port Sur Parking-", 48.933909, 2.348672 },
	{ 33056, 0, "33056-Place Jules Verne", "Rue Du Commandant L'Herminier/Angle Rue Hemat-", 48.917031, 2.386753 },
	{ 31203, 0, "31203 - Place Du Chateau D'Eau (Cb)", "Vis A Vis Du 87 Boulevard Pasteur -", 48.927133, 2.385235 },
	{ 31201, 0, "31201 - Mairie De La Courneuve (Cb)", "Rue Gabriel Péri -", 48.927545, 2.387773 },
	{ 31205, 0, "31205 - Gare De La Courneuve (Cb)", "Rue De La Gare / Boulevard Pasteur, Gare D'Aubervilliers-La Courneuve -", 48.922989, 2.385763 },
	{ 32169, 10, "32169-Square De Geyter", "1 Place Du Square De Geyter-", 48.931724, 2.353213 },
	{ 33060, 0, "33060-Quai Francois Mitterand", "Face Au 174 Bd Felix Faure/Face A La Rue Hertault, Sur Trottoir-", 48.911220, 2.375090 },
	{ 33062, 0, "33062-Place Rol Tanguy", "Rue De La Commune De Paris/Rue Sadi Carnot-", 48.909457, 2.379329 },
	{ 33053, 0, "33053-Bibliotheque Saint John Perce (Cb)", "Rue Edouard Poisson-", 48.910706, 2.382221 },
	{ 33061, 0, "33061-Avenue Victor Hugo", "53 Rue Edouard Carnot-", 48.911354, 2.379713 },
	{ 33058, 0, "33058-Place Cottin", "Rue Rechossiere/Place Cottin-", 48.916993, 2.389590 },
	{ 33059, 0, "33059-Heurtault/Moutier", "49 Rue Hertault-", 48.915740, 2.377125 },
	{ 33055, 0, "33055-Mairie (Cb)", "Avenue De La Republique, Sur Parvis De La Mairie, Face Au Square Du Docteur Pesque-", 48.914525, 2.381651 },
	{ 33054, 0, "33054-Poste", "Avenue De La Republique Sur Trottoir/Rue De La Commune De Paris-", 48.909257, 2.386719 },
	{ 32178, 10, "32178-Mairie De Saint Denis (Cb)", "Place Du Caquet-", 48.937565, 2.359640 },
	{ 32172, 10, "32172 - St Denis De L'Estre / Place Tilleuls (Cb)", "Rue De La Republique/Boulevard Jules Guesde -", 48.937144, 2.350405 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivatePlainecommune : StationsPluginSimplePrivate {
  StationsPluginSimplePrivatePlainecommune() {
    rect = QRectF(QPointF(48.736080, 2.348672), QPointF(48.945284, 2.564884));
    center = QPointF(48.936080, 2.364884);
    statusUrl = "http://www.velcom.fr/service/stationdetails/%1";
    infosUrl = "http://www.velcom.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Plainecommune %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;

    ret << "10";
    ret << "0";
    ret << "20";

    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_PLAINECOMMUNE_H */

