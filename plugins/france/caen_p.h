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
	{ 1, 0, "Saint-Pierre", "Face À LEntrée De LÉglise, En Remontant Vers Le Vaugueux,", 49.1843332062, -0.360864400864 },
	{ 2, 0, "Place Bouchard", "Rue Gémare Devant La Papeterie Plein Ciel,", 49.1837879687, -0.364292263985 },
	{ 3, 0, "Place De La Republique", "Dans Le Square Gambetta, Près De La Sortie Du Parking « République »,", 49.1814193589, -0.363262295723 },
	{ 4, 0, "Saint-Jean", "Devant La Poissonnerie Moderne.,", 49.1809933127, -0.358318984509 },
	{ 5, 0, "Bassin St Pierre", "Quai De La Londe Devant L'Hotel Mercure,", 49.184063218, -0.3557279706 },
	{ 6, 0, "Vaugueux", "Angle Av De La Libération / Rue Du Vaugueux,", 49.1861073782, -0.360331982374 },
	{ 7, 0, "Place St-Sauveur", "Côté Rue Pasteur Devant L'Église,", 49.183156818, -0.3682538867 },
	{ 8, 0, "Hotel De Ville", "Devant Le Bâtiment Etat Civil,", 49.1815350746, -0.370970964432 },
	{ 9, 0, "Gambetta", "A LAngle Du Nouveau Palais De Justice, Près Du Rond Point,", 49.1793364315, -0.36539465189 },
	{ 10, 0, "Place Foch", "Cours Du Gal De Gaulle, Près De La Colonne (Aux Abords De LHippodrome) Devant L'Opac ,", 49.1783107154, -0.359689593315 },
	{ 11, 0, "Place De La Resistance", "Angle Av Du 6 Juin / Rue Des Carmes / Près De La Statue Jeanne DArc,", 49.1804866111, -0.355505347252 },
	{ 12, 0, "Saint-Gilles", "Au Bout De L'Av Clémenceau En Haut De La Rue Des Cordes, Devant Le Théâtre Des Cordes,", 49.1876553438, -0.355577766895 },
	{ 13, 0, "Delivrande", "A LAngle De La Rue De La Délivrande Et De La Rue DHérouville,", 49.189504775, -0.359220206738 },
	{ 14, 0, "Universite", "Esplanade De La Paix / En Haut Du Gaillon,", 49.1885055648, -0.364254713058 },
	{ 15, 0, "Place De La Mare", "Côté Rue De Geole / A Côté De LArrêt Place De La Mare (Bus Et Tram).,", 49.1865982445, -0.366464853287 },
	{ 16, 0, "Place Du Canada", "Angle Rue Du Dr Rayer / Au Dessus Des Fossés St Julien,", 49.1855218383, -0.371542274952 },
	{ 17, 0, "Place De L'Ancienne Boucherie", "A LAngle De La Rue De Bayeux Et De La Rue Caponière,", 49.1825011141, -0.375080108643 },
	{ 18, 0, "Lycee Malherbe", "Av Albert Sorel / Entre Le Lycée Malherbe Et Le Stade Hélitas, Sous Les Arbres,", 49.1771587319, -0.371255278587 },
	{ 19, 0, "Saint-Michel", "Angle Rue St Michel / Entre Les Quais Et LHippodrome,", 49.1756753164, -0.356685519218 },
	{ 20, 0, "Place Du 36 Eme R.I.", "Angle St Jean / 11 Novembre,", 49.1776689745, -0.355902314186 },
	{ 21, 0, "Rives De L'Orne", "Sur Le Parking Parcotrain, À L'Entrée De La Gare, Accès Côté Cours Montalivet,", 49.177200814, -0.350425243378 },
	{ 22, 0, "Rond-Point De L'Orne", "Quai Vendeuvre / Au Bout Du Port, Vers La Salle De Concert Le Cargo,", 49.1804059591, -0.350138247013 },
	{ 23, 0, "Hippodrome", "Devant LEntrée De LHippodrome, Sur LEsplanade De La Patinoire,", 49.1784834229, -0.36754578352 },
	{ 24, 0, "Clemenceau", "Clos Beaumois", 49.1879551141, -0.352125763893 },
	{ 25, 0, "Clemenceau-Chr", "Angle Clémenceau / Rue De La Masse,", 49.1891752131, -0.346211493015 },
	{ 26, 0, "Lemonnier", "Rue D'Hérouville / Près De L'Institut,", 49.1927950137, -0.353327393532 },
	{ 27, 0, "Jardin Des Plantes", "Place Blot, À Gauche De L'Entrée Principale Du Jardin,", 49.1891331413, -0.370871722698 },
	{ 28, 0, "Hastings", "Angle Rue Lanfranc,", 49.1844673232, -0.378566980362 },
	{ 29, 0, "Place Villers-Chs", "Côté Rue Caponière / Au Parking À Côté Du Chs, Face Au Salon De Coiffure,", 49.1785088468, -0.379146337509 },
	{ 30, 0, "Vaucelles", "Angle Rue De Falaise / Sous Le Pont De Vaucelles,", 49.1747898049, -0.353928208351 },
	{ 31, 0, "Gare Sncf", "A Gauche De L'Entrée De La Gare / Devant La Billeterie Temporaire,", 49.1760786134, -0.348359942436 },
	{ 32, 0, "Victor Lepine", "Angle Bd Leroy / Au Croisement Avec La Ligne De Tram. Devant La Crèche,", 49.1731230714, -0.344076454639 },
	{ 33, 0, "Marechal Joffre", "Angle Bd Leroy / Près De La Place Du Marché,", 49.1719025766, -0.348559767008 },
	{ 34, 0, "Falaise Cygne De Croix", "Au Croisement Du Bd Leroy Et De La Rue De Falaise. A Côté De La Pharmacie,", 49.1706022606, -0.353049784899 },
	{ 35, 0, "Bvd Lyautey", "Angle Rue Lechesne,", 49.1682856318, -0.361510813236 },
	{ 36, 0, "Demi-Lune", "Devant La Clinique De La Planche,", 49.1743672087, -0.338328480721 },
	{ 37, 0, "Saint-Ouen", "Devant Le Centre Commercial St Ouen, Près Du Zénith,", 49.1747757769, -0.377566516399 },
	{ 38, 0, "Caponiere", "Angle Bd Detolle,", 49.1747249252, -0.388990044594 },
	{ 39, 0, "La Haie Vigne", "Devant Le Centre Sportif, Au Croisement De La Rue De Bayeux Et De La Rue Damozanne,", 49.1829061087, -0.384298861027 },
	{ 40, 0, "Guynemer", "Angle Avenue Du 43E Régiment D'Artillerie / A Côté De La Polyclinique Du Parc,", 49.1678647338, -0.346895456314 },
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

