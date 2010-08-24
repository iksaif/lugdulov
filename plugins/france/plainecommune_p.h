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
        const char *fullAddress;
        double x;
        double y;
} stations[] = {
	{ 32151, 10, "32151 - Proudhon (Cb)", "Av Du Pdt Wilson / Rue Proudhon -", "Av Du Pdt Wilson / Rue Proudhon - 93210 Saint Denis", 48.906263479, 2.35894503321 },
	{ 33052, 0, "33052-Casanova Tillon (Cb)", "Casanova/Tillon-", "Casanova/Tillon- 93300 Aubervilliers", 48.918681505, 2.39293220569 },
	{ 32180, 10, "32180-Place De La Resistance Et De La Deportation", "Rue Gabriel Peri / Rue Franciade -", "Rue Gabriel Peri / Rue Franciade - 93200 Saint Denis", 48.9371700941, 2.35607966721 },
	{ 32160, 10, "32160-Stade De France", "Chemin Du Cornillon/Rue Francis De Pressence-", "Chemin Du Cornillon/Rue Francis De Pressence- 93210 Saint Denis", 48.9195905336, 2.36246887326 },
	{ 32162, 10, "32162-Place Du Cornillon", "Face Au 14 Rue Jesse Owens-", "Face Au 14 Rue Jesse Owens- 93210 Saint Denis", 48.9246767336, 2.36435339383 },
	{ 32166, 10, "32166-Porte De Paris/Saint Denis", "58 Rue De La Legion D'Honneur-", "58 Rue De La Legion D'Honneur- 93210 Saint Denis", 48.930465824, 2.35652733447 },
	{ 32158, 10, "32158 - Fruitiers", "Rue Des Fruitiers Cote Restaurant Zack / Avenue Francois Miterrand -", "Rue Des Fruitiers Cote Restaurant Zack / Avenue Francois Miterrand - 93210 Saint Denis", 48.9179742624, 2.35473633952 },
	{ 32179, 10, "32179-Bibliotheque", "Rue Du Cygne/Rue De La Boulangerie/Devant Bibliotheque-", "Rue Du Cygne/Rue De La Boulangerie/Devant Bibliotheque- 93210 Saint Denis", 48.9354354473, 2.35722486681 },
	{ 32159, 10, "32159 - Gare Stade De France", "Rue Des Cheminots/Rue De Fellini-", "Rue Des Cheminots/Rue De Fellini- 93210 Saint Denis", 48.9169500303, 2.35267696264 },
	{ 32153, 10, "32153 - Place Du Marche (Cb)", "Avenue Du President Wilson / Rue De Bailly -", "Avenue Du President Wilson / Rue De Bailly - 93210 Saint Denis", 48.9106132852, 2.3585378254 },
//	{ 34502, 10, "34502-Square Falker", "Face Au 14 Rue Arnold Geraux-", "Face Au 14 Rue Arnold Geraux- 93210 Ile De Saint Denis", 27.1409734276, -3.40456063168 },
	{ 32157, 10, "32157-Francis De Pressence", "260 Avenue Du President Wilson-", "260 Avenue Du President Wilson- 93210 Saint Denis", 48.917704152, 2.35787256673 },
	{ 32154, 10, "32154 - Commissariat De Police", "Avenue Du Stade De France / Rue Du Landy -", "Avenue Du Stade De France / Rue Du Landy - 93210 Saint Denis", 48.918988546, 2.36180039147 },
	{ 32176, 10, "32176-Place Du 8 Mai (Cb)", "Rue Gillot-", "Rue Gillot- 93210 Saint Denis", 48.9401091217, 2.35381615262 },
	{ 33063, 0, "33063-Espace Bel Air", "Chemin Du Haut De Saint Denis/Rue Francis Pressence-", "Chemin Du Haut De Saint Denis/Rue Francis Pressence- 93300 Aubervilliers", 48.9231032001, 2.36774833015 },
	{ 31206, 20, "31206 - Carrefour Des 6 Routes", "Carrefour Des 6 Routes, Leclerc / Pasteur -", "Carrefour Des 6 Routes, Leclerc / Pasteur - 93120 La Courneuve", 48.929702771, 2.38538786666 },
	{ 32161, 10, "32161-Communaute D'Agglomeration (Cb)", "Rue De L'Olympisme/21 Avenue Jules Rimet-", "Rue De L'Olympisme/21 Avenue Jules Rimet- 93210 Saint Denis", 48.9246232104, 2.3625395133 },
	{ 32173, 10, "32173-Maison De Retraite Des Petites Soeurs", "Rue Gaston Dourdin/Rue Pierre Brossolette-", "Rue Gaston Dourdin/Rue Pierre Brossolette- 93210 Saint Denis", 48.941421548, 2.35104716259 },
	{ 32163, 10, "32163-Passerelle Des Franc Moisin", "Quai Du Canal/Cours Thierry-", "Quai Du Canal/Cours Thierry- 93210 Saint Denis", 48.929729483, 2.35248981783 },
	{ 32168, 10, "32168-Universite Paris Viii", "Face Au 3 Rue De La Liberte-", "Face Au 3 Rue De La Liberte- 93210 Saint Denis", 48.9452837018, 2.36384572983 },
	{ 32167, 10, "32167-Porte De Paris (Cb)", "1 Avenue Gabriel Peri-", "1 Avenue Gabriel Peri- 93210 Saint Denis", 48.9302052086, 2.35649995856 },
	{ 31204, 20, "31204 - Place De La Fraternite", "Avenue General Leclerc, Face Bibliotheque John Lennon -", "Avenue General Leclerc, Face Bibliotheque John Lennon - 93120 La Courneuve", 48.9261018273, 2.37784249608 },
	{ 33051, 0, "33051-Rue Bordier (Cb)", "Rue Bordier/Boulevard Faure -", "Rue Bordier/Boulevard Faure - 93300 Aubervilliers", 48.9038743672, 2.3848731018 },
	{ 32177, 10, "32177-Place Des Poulies", "Rue Vaillant-", "Rue Vaillant- 93210 Saint Denis", 48.9321806169, 2.36513479943 },
	{ 32174, 10, "32174-Place Du General Leclerc", "Rue Berne/Rue Gabriel Peri-", "Rue Berne/Rue Gabriel Peri- 93210 Saint Denis", 48.9423913822, 2.35640898974 },
//	{ 34501, 10, "34501-Hotel De Ville (Cb)", "Hotel De Ville-", "Hotel De Ville- 93210 Ile De Saint Denis", 27.1409734276, -3.40456063168 },
	{ 31202, 20, "31202 - La Poste (Cb)", "58 Rue Gabriel Péri -", "58 Rue Gabriel Péri - 93120 La Courneuve", 48.9263479285, 2.39172662576 },
	{ 32175, 10, "32175-Centre Nautique De La Baleine", "Avenue Moulin/Rue Guuy Mocquet-", "Avenue Moulin/Rue Guuy Mocquet- 93210 Saint Denis", 48.9407544374, 2.36348870548 },
	{ 32170, 10, "32170-Sembat/Guesde", "64 Boulevard Marcel Sembat-", "64 Boulevard Marcel Sembat- 93210 Saint Denis", 48.9330727235, 2.35150870608 },
	{ 32171, 10, "32171-Gare Saint Denis (Cb)", "Quai Du Port Sur Parking-", "Quai Du Port Sur Parking- 93210 Saint Denis", 48.9339088071, 2.34867172601 },
	{ 33056, 0, "33056-Place Jules Verne", "Rue Du Commandant L'Herminier/Angle Rue Hemat-", "Rue Du Commandant L'Herminier/Angle Rue Hemat- 93300 Aubervilliers", 48.9170306248, 2.38675332676 },
	{ 31203, 20, "31203 - Place Du Chateau D'Eau (Cb)", "Vis A Vis Du 87 Boulevard Pasteur -", "Vis A Vis Du 87 Boulevard Pasteur - 93120 La Courneuve", 48.927132578, 2.38523545277 },
	{ 31201, 20, "31201 - Mairie De La Courneuve (Cb)", "Rue Gabriel Péri -", "Rue Gabriel Péri - 93120 La Courneuve", 48.9275449283, 2.3877726442 },
	{ 31205, 20, "31205 - Gare De La Courneuve (Cb)", "Rue De La Gare / Boulevard Pasteur, Gare D'Aubervilliers-La Courneuve -", "Rue De La Gare / Boulevard Pasteur, Gare D'Aubervilliers-La Courneuve - 93120 La Courneuve", 48.9229893903, 2.38576347949 },
	{ 32169, 10, "32169-Square De Geyter", "1 Place Du Square De Geyter-", "1 Place Du Square De Geyter- 93210 Saint Denis", 48.9317244768, 2.35321331727 },
	{ 33060, 0, "33060-Quai Francois Mitterand", "Face Au 174 Bd Felix Faure/Face A La Rue Hertault, Sur Trottoir-", "Face Au 174 Bd Felix Faure/Face A La Rue Hertault, Sur Trottoir- 93300 Aubervilliers", 48.9112203001, 2.37509031024 },
	{ 33062, 0, "33062-Place Rol Tanguy", "Rue De La Commune De Paris/Rue Sadi Carnot-", "Rue De La Commune De Paris/Rue Sadi Carnot- 93300 Aubervilliers", 48.9094574203, 2.37932919609 },
	{ 33053, 0, "33053-Bibliotheque Saint John Perce (Cb)", "Rue Edouard Poisson-", "Rue Edouard Poisson- 93300 Aubervilliers", 48.9107055635, 2.38222068698 },
	{ 33061, 0, "33061-Avenue Victor Hugo", "53 Rue Edouard Carnot-", "53 Rue Edouard Carnot- 93300 Aubervilliers", 48.9113535493, 2.37971250195 },
	{ 33058, 0, "33058-Place Cottin", "Rue Rechossiere/Place Cottin-", "Rue Rechossiere/Place Cottin- 93300 Aubervilliers", 48.9169934659, 2.38958957557 },
	{ 33059, 0, "33059-Heurtault/Moutier", "49 Rue Hertault-", "49 Rue Hertault- 93300 Aubervilliers", 48.9157401054, 2.37712532352 },
	{ 33055, 0, "33055-Mairie (Cb)", "Avenue De La Republique, Sur Parvis De La Mairie, Face Au Square Du Docteur Pesque-", "Avenue De La Republique, Sur Parvis De La Mairie, Face Au Square Du Docteur Pesque- 93300 Aubervilliers", 48.9145252609, 2.38165131861 },
	{ 33054, 0, "33054-Poste", "Avenue De La Republique Sur Trottoir/Rue De La Commune De Paris-", "Avenue De La Republique Sur Trottoir/Rue De La Commune De Paris- 93300 Aubervilliers", 48.9092568688, 2.38671863167 },
	{ 32178, 10, "32178-Mairie De Saint Denis (Cb)", "Place Du Caquet-", "Place Du Caquet- 93210 Saint Denis", 48.9375648999, 2.35964021542 },
	{ 32172, 10, "32172 - St Denis De L'Estre / Place Tilleuls (Cb)", "Rue De La Republique/Boulevard Jules Guesde -", "Rue De La Republique/Boulevard Jules Guesde - 93210 Saint Denis", 48.9371438941, 2.35040488268 },
	{0, 0, NULL, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivatePlainecommune : StationsPluginSimplePrivate {
  StationsPluginSimplePrivatePlainecommune() {
    rect = QRectF(QPointF(48.903046180517, 2.347786516421), QPointF(48.946111888468, 2.393817415288));
    center = QPointF(48.924579034493, 2.370801965854);
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

    ret << "0";
    ret << "10";
    ret << "20";

    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_PLAINECOMMUNE_H */

