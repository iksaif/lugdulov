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

#ifndef STATIONS_SIMPLE_PRIVATE_PERPIGNAN_H
#define STATIONS_SIMPLE_PRIVATE_PERPIGNAN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "Palais Des Rois", "Rue Des Archers, Sur La Gauche De L'Entrée Principale", 42.6940361044, 2.89406597614 },
	{ 2, 0, "Gare Sncf Boulevard Du Conflent", "Face À L'Hôtel Paris Barcelone.", 42.6960922237, 2.87994682789 },
	{ 3, 0, "Place De Catalogne", "Angle Rue Gal Legrand / Côté Fnac, Sur La Droite De L'Entrée", 42.6982921763, 2.88837701082 },
	{ 4, 0, "Place Gabriel Péri", "4 Place Gabriel Péri, Rue Du 4 Septembre, À Côté Du Palmarium", 42.698613489, 2.89150714874 },
	{ 5, 0, "Place De La République", "Devant Le Théâtre", 42.6983335725, 2.89573431015 },
	{ 6, 0, "Victoire", "Sur Le Pont Général De Larminat / Devant Le Castillet / A Côté Du Cinéma Du Castillet", 42.7012470079, 2.89371728897 },
	{ 7, 0, "Palais Des Congrès", "Place Du 8 Mai 45 / Devant L'Entrée De L'Office De Tourisme", 42.70260709, 2.89858818054 },
	{ 8, 0, "Universite", "Avenue Paul Alduy", 42.683239868, 2.90196239948 },
	{ 9, 0, "Kennedy", "Angle Avenue Kennedy Et Avenue P.Cambres ( Du Côté De La Rue De St André)", 42.6909567264, 2.89872229099 },
	{ 10, 0, "Conservatoire De Musique", "Face Au 54 Avenue Foch / A Gauche De L'Entrée Du Parking St Martin", 42.6953510035, 2.88993269205 },
	{ 11, 0, "Parc Des Expositions", "Avenue Du Palais Des Expositions / Angle Rd Point Du Palais Des Expositions.", 42.7079603987, 2.90254712105 },
	{ 12, 0, "Annexe Mairie De Quartier Nord", "39 Av Maréchal Joffre / Devant L'Entrée De La Mairie Annexe", 42.7073080136, 2.8911665082 },
	{ 13, 0, "Stade Gilbert Brutus", "Angle Av De L'Aérodrome / Devant La Mairie Annexe / Devant L'Entrée Du Stade", 42.7217259006, 2.8856921196 },
	{ 14, 0, "Hôpital", "Hôpital", 42.723400807, 2.88687229156 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivatePerpignan : StationsPluginSimplePrivate {
  StationsPluginSimplePrivatePerpignan() {
    rect = QRectF(QPointF(42.501574, 2.694150), QPointF(42.901574, 3.094150));
    center = QPointF(42.701574, 2.894150);
    statusUrl = "";
    infosUrl = "http://www.bip-perpignan.fr/localizaciones/localizaciones.php";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Perpignan %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_PERPIGNAN_H */

