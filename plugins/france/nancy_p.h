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

#ifndef STATIONS_SIMPLE_PRIVATE_NANCY_H
#define STATIONS_SIMPLE_PRIVATE_NANCY_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 14, 0, "00014 - Port St Georges - Capitainerie (Cb)", "Boulevard Du 2E Ra", 48.692305, 6.193054 },
	{ 20, 0, "00020 - Porte St Nicolas", "Rue St Dizier", 48.685867, 6.186229 },
	{ 25, 0, "00025 - Place Commanderie", "Place De La Commanderie Face Au 13", 48.685918, 6.167422 },
	{ 13, 0, "00013 - Saint Nicolas - Charles Iii", "77 ,Rue Saint Nicolas", 48.687832, 6.187802 },
	{ 4, 0, "00004 - Marche Central (Cb)", "Place Mengin", 48.689095, 6.182431 },
	{ 18, 0, "00018 - Gare Saint Leon (Cb)", "Rue Saint Leon", 48.689560, 6.172515 },
	{ 15, 0, "00015 - Port Ste Catherine", "Quai Ste Catherine", 48.695487, 6.190679 },
	{ 17, 0, "00017 - Conservatoire - Manufacture", "27 Rue Baron Louis", 48.695718, 6.171338 },
	{ 5, 0, "00005 - Place Colonel Driant (Cb)", "Rue Drouin Face Au 2", 48.692463, 6.188185 },
	{ 24, 0, "00024 - 3 Maisons - Charles V (Cb)", "15 Rue Du Faubourg Des 3 Maisons", 48.700878, 6.177062 },
	{ 6, 0, "00006 - Place Du Colonel Fabien", "16, Place Du Colonel Fabien", 48.695175, 6.179781 },
	{ 9, 0, "00009 - Mazagran - Poincare", "Rue Raymond Poincare", 48.690791, 6.175080 },
	{ 7, 0, "00007 - Place Saint Epvre (Cb)", "Rue Pierre Gringoire", 48.696314, 6.179892 },
	{ 23, 0, "00023 - Promenade Des Canaux", "Rue Des Tiercelins", 48.692794, 6.196284 },
	{ 12, 0, "00012 - St Sebastien - St Thiebaut (Cb)", "Rue Saint Thiebaut", 48.688614, 6.179500 },
	{ 21, 0, "00021 - Hopital Central (Cb)", "45 Avenue Du Marechal De Lattre De Tassigny", 48.683350, 6.190297 },
	{ 19, 0, "00019 - Commanderie - Chalnot", "Rue P. Chalnot", 48.686920, 6.172348 },
	{ 16, 0, "00016 - Porte De La Craffe (Cb)", "Place Des Bourgets", 48.698472, 6.177986 },
	{ 1, 0, "00001 - Dominicains - Fourrier (Cb)", "Rue Pierre Fourrier", 48.692465, 6.183401 },
	{ 11, 0, "00011 - Mazagran - Foch (Cb)", "Boulevard Foch", 48.689476, 6.176505 },
	{ 22, 0, "00022 - Hopital St Julien", "Rue Molitor", 48.685857, 6.192902 },
	{ 3, 0, "00003 - Place De Dombasle (Cb)", "Rue De Stanislas Face Au 68", 48.691958, 6.178510 },
	{ 8, 0, "00008 - Cours Leopold - Saint Michel (Cb)", "Rue Saint Michel", 48.695614, 6.176768 },
	{ 2, 0, "00002 - Place De La Carriere (Cb)", "Place De La Carriere", 48.694598, 6.182294 },
	{ 10, 0, "00010 - Gare Thiers (Cb)", "Rue Pirou Crampel", 48.690188, 6.174519 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateNancy : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateNancy() {
    rect = QRectF(QPointF(48.490789, 6.167422), QPointF(48.700878, 6.382504));
    center = QPointF(48.690789, 6.182504);
    statusUrl = "http://www.velostanlib.fr/service/stationdetails/%1";
    infosUrl = "http://www.velostanlib.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Nancy %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;

    ret << "0";

    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_NANCY_H */

