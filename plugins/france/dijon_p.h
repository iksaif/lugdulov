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
	{ 1, 0, "Place St Fiacre", "Angle Rue Vauban,", 47.3204978064, 5.04096239805 },
	{ 2, 0, "Dauphine", "Face Au Café Le Dauphine,", 47.3212223783, 5.03898561001 },
	{ 3, 0, "Place Notre Dame", "Rue Des Forges,Face À L'Office De Tourisme,", 47.3221633069, 5.04093021154 },
	{ 4, 0, "Place Du Théatre", "Angle Rue Vaillant,Face Au Bar La Comédie,", 47.321037827, 5.04350781441 },
	{ 5, 0, "Rue Chabot Charny", "Angle Rue De L'Ecole De Droit,", 47.3192113713, 5.04315376282 },
	{ 6, 0, "Place Des Cordeliers", "Angle Rue Charrue, Face Aux Asurances Gaudin,", 47.3190313588, 5.04026100039 },
	{ 7, 0, "Place Bossuet", "Face Rue Piron, Face À La Poste,", 47.3210087351, 5.03689885139 },
	{ 8, 0, "Place Grangier", "Face À Groupama,", 47.323138764, 5.03786042333 },
	{ 9, 0, "Rue Auguste Comte", "Angle Rue Jj Rousseau,", 47.3237833012, 5.04441440105 },
	{ 10, 0, "Rue Jeannin", "Face Au 69 À 75,Face Au Bar Le Jeannin,", 47.3215323865, 5.04754453897 },
	{ 11, 0, "Place Wilson", "Au Centre De La Place Côté Rue Chabot Charny,", 47.3165920381, 5.0431483984 },
	{ 12, 0, "Place Emile Zola", "Angle Rue Monge,Face Au Restaurant Les Moules Zola,", 47.3192413733, 5.03524392843 },
	{ 13, 0, "Place Ste Benigne", "Angle Rue De La Prévoté,Face À L'Église St Bégnigne,", 47.3215178407, 5.03354340792 },
	{ 14, 0, "Rue De La Préfecture", "Angle Rue Mère Javouhey,À Coté Du Bar Le Refuge 73,", 47.3256705047, 5.04267096519 },
	{ 15, 0, "Place Du 30 Octobre Et De La Légion D'Honneur", "Angle Cabet / Carnot,À Coté Du Lycée Simone Weil,", 47.3215378412, 5.05147397518 },
	{ 16, 0, "Montée De Guise", "Montée De Guise,Sortie Parking Tivoli,", 47.3171757397, 5.03348439932 },
	{ 17, 0, "Place Darcy", "Angle Rue Dr Chaussier,Face À La Porte Guillaume,", 47.3232742174, 5.0339859724 },
	{ 18, 0, "Cellier De Clairvaux", "Angle Bd De La Trémouille / Rue Du Suzon", 47.325590509, 5.04027038813 },
	{ 19, 0, "Place De La République", "Devant Restaurant Le Pallazio  Et La Rhumerie Jamaique,", 47.3260995705, 5.04523515701 },
	{ 20, 0, "Cours Du Général De Gaulle", "Clinique", 47.3131878929, 5.04436612129 },
	{ 21, 0, "Rue Des Corroyeurs", "Devant L'Entrée De L'Anpe,", 47.315933775, 5.03148078918 },
	{ 22, 0, "Rue Du Faubourg Raines", "Hôpital", 47.3182994835, 5.0297293067 },
	{ 23, 0, "Avenue Foch", "Office Du Tourisme", 47.3237305749, 5.03163099289 },
	{ 24, 0, "Rue Sambin", "Ecole De Commerce", 47.3277576223, 5.04159808159 },
	{ 25, 0, "Place Jardillier", "Sur La Rue Marceau,Rue Claus Sluter,", 47.3277521683, 5.04519760609 },
	{ 26, 0, "Boulevard Clémenceau", "Conservatoire", 47.327917607, 5.04940330982 },
	{ 27, 0, "Cours Du Parc", "Piscine", 47.3072155613, 5.04690885544 },
	{ 28, 0, "Quai Navier", "Près Du Pont Av Jean Jaurès,Devant Boulangerie Tresse,", 47.3123768302, 5.0270819664 },
	{ 29, 0, "Planétarium", "Devant L'Entrée Du Parc,Rue Jehan De Marville,", 47.3203014338, 5.0262773037 },
	{ 30, 0, "Gare Dijon Ville", "Cours De La Gare,Devant La Bagagerie Sncf,", 47.3233378532, 5.02791881561 },
	{ 31, 0, "Avenue Victor Hugo", "Sciences Po", 47.3263359187, 5.03014236689 },
	{ 32, 0, "Place Barbe", "Côté Rue De Jouvence,", 47.3289356802, 5.03878712654 },
	{ 33, 0, "Place J. Bouhey", "Auditorium", 47.3288993208, 5.0518655777 },
	{ 34, 0, "Boulevard De Strasbourg", "Au Dessus Du Rond Point,Bd Paul Doumer,", 47.3222142165, 5.06152153015 },
	{ 35, 0, "Hôpital Bocage", "Sur Le Domaine Du Chu / Derrière L'Entrée Principal,", 47.3220687602, 5.06692886353 },
	{ 36, 0, "Hôpital Bocage", "Maternité", 47.3216905719, 5.07074832916 },
	{ 37, 0, "Auxonne", "Eldorado", 47.3141262368, 5.04896879196 },
	{ 38, 0, "Drapeau", "Heudelet,", 47.3326569342, 5.04409790039 },
	{ 39, 0, "Drapeau", "Junot ,", 47.3375721506, 5.04474163055 },
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

