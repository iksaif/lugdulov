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

#ifndef STATIONS_SIMPLE_PRIVATE_CAEN_H
#define STATIONS_SIMPLE_PRIVATE_CAEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "Saint-Pierre", "Face À L'Entrée De L'Église, En Remontant Vers Le Vaugueux,", 49.184333, -0.360864 },
	{ 2, 0, "Place Bouchard", "Rue Gémare Devant La Papeterie Plein Ciel,", 49.183788, -0.364292 },
	{ 3, 0, "Place De La Republique", "Dans Le Square Gambetta, Près De La Sortie Du Parking « République »,", 49.181419, -0.363262 },
	{ 4, 0, "Saint-Jean", "Devant La Poissonnerie Moderne.,", 49.180993, -0.358319 },
	{ 5, 0, "Bassin St Pierre", "Quai De La Londe Devant L'Hotel Mercure,", 49.184063, -0.355728 },
	{ 6, 0, "Vaugueux", "Angle Av De La Libération / Rue Du Vaugueux,", 49.186107, -0.360332 },
	{ 7, 0, "Place St-Sauveur", "Côté Rue Pasteur Devant L'Église,", 49.183157, -0.368254 },
	{ 8, 0, "Hotel De Ville", "Devant Le Bâtiment Etat Civil,", 49.181535, -0.370971 },
	{ 9, 0, "Gambetta", "A L'Angle Du Nouveau Palais De Justice, Près Du Rond Point,", 49.179336, -0.365395 },
	{ 10, 0, "Place Foch", "Cours Du Gal De Gaulle, Près De La Colonne (Aux Abords De L'Hippodrome) Devant L'Opac ,", 49.178311, -0.359690 },
	{ 11, 0, "Place De La Resistance", "Angle Av Du 6 Juin / Rue Des Carmes / Près De La Statue Jeanne D'Arc,", 49.180487, -0.355505 },
	{ 12, 0, "Saint-Gilles", "Au Bout De L'Av Clémenceau En Haut De La Rue Des Cordes, Devant Le Théâtre Des Cordes,", 49.187655, -0.355578 },
	{ 13, 0, "Delivrande", "A L'Angle De La Rue De La Délivrande Et De La Rue D'Hérouville,", 49.189505, -0.359220 },
	{ 14, 0, "Universite", "Esplanade De La Paix / En Haut Du Gaillon,", 49.188506, -0.364255 },
	{ 15, 0, "Place De La Mare", "Côté Rue De Geole / A Côté De L'Arrêt Place De La Mare (Bus Et Tram).,", 49.186598, -0.366465 },
	{ 16, 0, "Place Du Canada", "Angle Rue Du Dr Rayer / Au Dessus Des Fossés St Julien,", 49.185522, -0.371542 },
	{ 17, 0, "Place De L'Ancienne Boucherie", "A L'Angle De La Rue De Bayeux Et De La Rue Caponière,", 49.182501, -0.375080 },
	{ 18, 0, "Lycee Malherbe", "Av Albert Sorel / Entre Le Lycée Malherbe Et Le Stade Hélitas, Sous Les Arbres,", 49.177159, -0.371255 },
	{ 19, 0, "Saint-Michel", "Angle Rue St Michel / Entre Les Quais Et L'Hippodrome,", 49.175675, -0.356686 },
	{ 20, 0, "Place Du 36 Eme R.I.", "Angle St Jean / 11 Novembre,", 49.177669, -0.355902 },
	{ 21, 0, "Rives De L'Orne", "Sur Le Parking Parcotrain, À L'Entrée De La Gare, Accès Côté Cours Montalivet,", 49.177201, -0.350425 },
	{ 22, 0, "Rond-Point De L'Orne", "Quai Vendeuvre / Au Bout Du Port, Vers La Salle De Concert Le Cargo,", 49.180406, -0.350138 },
	{ 23, 0, "Hippodrome", "Devant L'Entrée De L'Hippodrome, Sur L'Esplanade De La Patinoire,", 49.178483, -0.367546 },
	{ 24, 0, "Clemenceau", "Clos Beaumois", 49.187955, -0.352126 },
	{ 25, 0, "Clemenceau-Chr", "Angle Clémenceau / Rue De La Masse,", 49.189175, -0.346211 },
	{ 26, 0, "Lemonnier", "Rue D'Hérouville / Près De L'Institut,", 49.192795, -0.353327 },
	{ 27, 0, "Jardin Des Plantes", "Place Blot, À Gauche De L'Entrée Principale Du Jardin,", 49.189133, -0.370872 },
	{ 28, 0, "Hastings", "Angle Rue Lanfranc,", 49.184467, -0.378567 },
	{ 29, 0, "Place Villers-Chs", "Côté Rue Caponière / Au Parking À Côté Du Chs, Face Au Salon De Coiffure,", 49.178509, -0.379146 },
	{ 30, 0, "Vaucelles", "Angle Rue De Falaise / Sous Le Pont De Vaucelles,", 49.174790, -0.353928 },
	{ 31, 0, "Gare Sncf", "A Gauche De L'Entrée De La Gare / Devant La Billeterie Temporaire,", 49.176079, -0.348360 },
	{ 32, 0, "Victor Lepine", "Angle Bd Leroy / Au Croisement Avec La Ligne De Tram. Devant La Crèche,", 49.173123, -0.344076 },
	{ 33, 0, "Marechal Joffre", "Angle Bd Leroy / Près De La Place Du Marché,", 49.171903, -0.348560 },
	{ 34, 0, "Falaise Cygne De Croix", "Au Croisement Du Bd Leroy Et De La Rue De Falaise. A Côté De La Pharmacie,", 49.170602, -0.353050 },
	{ 35, 0, "Bvd Lyautey", "Angle Rue Lechesne,", 49.168286, -0.361511 },
	{ 36, 0, "Demi-Lune", "Devant La Clinique De La Planche,", 49.174367, -0.338328 },
	{ 37, 0, "Saint-Ouen", "Devant Le Centre Commercial St Ouen, Près Du Zénith,", 49.174776, -0.377567 },
	{ 38, 0, "Caponiere", "Angle Bd Detolle,", 49.174725, -0.388990 },
	{ 39, 0, "La Haie Vigne", "Devant Le Centre Sportif, Au Croisement De La Rue De Bayeux Et De La Rue Damozanne,", 49.182906, -0.384299 },
	{ 40, 0, "Guynemer", "Angle Avenue Du 43E Régiment D'Artillerie / A Côté De La Polyclinique Du Parc,", 49.167865, -0.346895 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateCaen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateCaen() {
    rect = QRectF(QPointF(48.984667, -0.560270), QPointF(49.384667, -0.160270));
    center = QPointF(49.184667, -0.360270);
    statusUrl = "";
    infosUrl = "http://www.veol.caen.fr/localizaciones/localizaciones.php";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Caen %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_CAEN_H */

