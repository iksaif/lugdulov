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

#ifndef STATIONS_SIMPLE_PRIVATE_DIJON_H
#define STATIONS_SIMPLE_PRIVATE_DIJON_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "Place St Fiacre", "Angle Rue Vauban,", 47.320498, 5.040962 },
	{ 2, 0, "Dauphine", "Face Au Café Le Dauphine,", 47.321222, 5.038986 },
	{ 3, 0, "Place Notre Dame", "Rue Des Forges,Face À L'Office De Tourisme,", 47.322163, 5.040930 },
	{ 4, 0, "Place Du Théatre", "Angle Rue Vaillant,Face Au Bar La Comédie,", 47.321038, 5.043508 },
	{ 5, 0, "Rue Chabot Charny", "Angle Rue De L'Ecole De Droit,", 47.319211, 5.043154 },
	{ 6, 0, "Place Des Cordeliers", "Angle Rue Charrue, Face Aux Asurances Gaudin,", 47.319031, 5.040261 },
	{ 7, 0, "Place Bossuet", "Face Rue Piron, Face À La Poste,", 47.321009, 5.036899 },
	{ 8, 0, "Place Grangier", "Face À Groupama,", 47.323139, 5.037860 },
	{ 9, 0, "Rue Auguste Comte", "Angle Rue Jj Rousseau,", 47.323783, 5.044414 },
	{ 10, 0, "Rue Jeannin", "Face Au 69 À 75,Face Au Bar Le Jeannin,", 47.321532, 5.047545 },
	{ 11, 0, "Place Wilson", "Au Centre De La Place Côté Rue Chabot Charny,", 47.316592, 5.043148 },
	{ 12, 0, "Place Emile Zola", "Angle Rue Monge,Face Au Restaurant Les Moules Zola,", 47.319241, 5.035244 },
	{ 13, 0, "Place Ste Benigne", "Angle Rue De La Prévoté,Face À L'Église St Bégnigne,", 47.321518, 5.033543 },
	{ 14, 0, "Rue De La Préfecture", "Angle Rue Mère Javouhey,À Coté Du Bar Le Refuge 73,", 47.325671, 5.042671 },
	{ 15, 0, "Place Du 30 Octobre Et De La Légion D'Honneur", "Angle Cabet / Carnot,À Coté Du Lycée Simone Weil,", 47.321538, 5.051474 },
	{ 16, 0, "Montée De Guise", "Montée De Guise,Sortie Parking Tivoli,", 47.317176, 5.033484 },
	{ 17, 0, "Place Darcy", "Angle Rue Dr Chaussier,Face À La Porte Guillaume,", 47.323274, 5.033986 },
	{ 18, 0, "Cellier De Clairvaux", "Angle Bd De La Trémouille / Rue Du Suzon", 47.325591, 5.040270 },
	{ 19, 0, "Place De La République", "Devant Restaurant Le Pallazio  Et La Rhumerie Jamaique,", 47.326100, 5.045235 },
	{ 20, 0, "Cours Du Général De Gaulle", "Clinique", 47.313188, 5.044366 },
	{ 21, 0, "Rue Des Corroyeurs", "Devant L'Entrée De L'Anpe,", 47.315934, 5.031481 },
	{ 22, 0, "Rue Du Faubourg Raines", "Hôpital", 47.318299, 5.029729 },
	{ 23, 0, "Avenue Foch", "Office Du Tourisme", 47.323731, 5.031631 },
	{ 24, 0, "Rue Sambin", "Ecole De Commerce", 47.327758, 5.041598 },
	{ 25, 0, "Place Jardillier", "Sur La Rue Marceau,Rue Claus Sluter,", 47.327752, 5.045198 },
	{ 26, 0, "Boulevard Clémenceau", "Conservatoire", 47.327918, 5.049403 },
	{ 27, 0, "Cours Du Parc", "Piscine", 47.307216, 5.046909 },
	{ 28, 0, "Quai Navier", "Près Du Pont Av Jean Jaurès,Devant Boulangerie Tresse,", 47.312377, 5.027082 },
	{ 29, 0, "Planétarium", "Devant L'Entrée Du Parc,Rue Jehan De Marville,", 47.320301, 5.026277 },
	{ 30, 0, "Gare Dijon Ville", "Cours De La Gare,Devant La Bagagerie Sncf,", 47.323338, 5.027919 },
	{ 31, 0, "Avenue Victor Hugo", "Sciences Po", 47.326336, 5.030142 },
	{ 32, 0, "Place Barbe", "Côté Rue De Jouvence,", 47.328936, 5.038787 },
	{ 33, 0, "Place J. Bouhey", "Auditorium", 47.328899, 5.051866 },
	{ 34, 0, "Boulevard De Strasbourg", "Au Dessus Du Rond Point,Bd Paul Doumer,", 47.322214, 5.061522 },
	{ 35, 0, "Hôpital Bocage", "Sur Le Domaine Du Chu / Derrière L'Entrée Principal,", 47.322069, 5.066929 },
	{ 36, 0, "Hôpital Bocage", "Maternité", 47.321691, 5.070748 },
	{ 37, 0, "Auxonne", "Eldorado", 47.314126, 5.048969 },
	{ 38, 0, "Drapeau", "Heudelet,", 47.332657, 5.044098 },
	{ 39, 0, "Drapeau", "Junot ,", 47.337572, 5.044742 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateDijon : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateDijon() {
    rect = QRectF(QPointF(47.127213, 4.843987), QPointF(47.527213, 5.243988));
    center = QPointF(47.327213, 5.043988);
    statusUrl = "";
    infosUrl = "http://www.velodi.net/localizaciones/localizaciones.php";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Dijon %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_DIJON_H */

