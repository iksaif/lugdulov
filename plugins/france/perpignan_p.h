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
	{ 1, 0, "Palais Des Rois", "Rue Des Archers, Sur La Gauche De L'Entrée Principale", 42.694036, 2.894066 },
	{ 2, 0, "Gare Sncf Boulevard Du Conflent", "Face À L'Hôtel Paris Barcelone.", 42.696092, 2.879947 },
	{ 3, 0, "Place De Catalogne", "Angle Rue Gal Legrand / Côté Fnac, Sur La Droite De L'Entrée", 42.698292, 2.888377 },
	{ 4, 0, "Place Gabriel Péri", "4 Place Gabriel Péri, Rue Du 4 Septembre, À Côté Du Palmarium", 42.698613, 2.891507 },
	{ 5, 0, "Place De La République", "Devant Le Théâtre", 42.698334, 2.895734 },
	{ 6, 0, "Victoire", "Sur Le Pont Général De Larminat / Devant Le Castillet / A Côté Du Cinéma Du Castillet", 42.701247, 2.893717 },
	{ 7, 0, "Palais Des Congrès", "Place Du 8 Mai 45 / Devant L'Entrée De L'Office De Tourisme", 42.702607, 2.898588 },
	{ 8, 0, "Universite", "Avenue Paul Alduy", 42.683240, 2.901962 },
	{ 9, 0, "Kennedy", "Angle Avenue Kennedy Et Avenue P.Cambres ( Du Côté De La Rue De St André)", 42.690957, 2.898722 },
	{ 10, 0, "Conservatoire De Musique", "Face Au 54 Avenue Foch / A Gauche De L'Entrée Du Parking St Martin", 42.695351, 2.889933 },
	{ 11, 0, "Parc Des Expositions", "Avenue Du Palais Des Expositions / Angle Rd Point Du Palais Des Expositions.", 42.707960, 2.902547 },
	{ 12, 0, "Annexe Mairie De Quartier Nord", "39 Av Maréchal Joffre / Devant L'Entrée De La Mairie Annexe", 42.707308, 2.891167 },
	{ 13, 0, "Stade Gilbert Brutus", "Angle Av De L'Aérodrome / Devant La Mairie Annexe / Devant L'Entrée Du Stade", 42.721726, 2.885692 },
	{ 14, 0, "Hôpital", "Hôpital", 42.723401, 2.886872 },
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

