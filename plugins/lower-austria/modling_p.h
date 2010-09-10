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

#ifndef STATIONS_SIMPLE_PRIVATE_MODLING_H
#define STATIONS_SIMPLE_PRIVATE_MODLING_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 7443, 0, "Moedling / Bahnhof", "", 48.085734, 16.295514 },
	{ 7418, 0, "Ma. Enzersdorf / Hst", "", 48.096541, 16.313839 },
	{ 7430, 0, "Wiener Neudorf / Hst Griesfeld", "", 48.077620, 16.312423 },
	{ 7431, 0, "Voesendorf / Schoenbrunner Allee", "", 48.135220, 16.325083 },
	{ 7432, 0, "Wiener Neudorf / Ecocenter", "", 48.073498, 16.315641 },
	{ 7433, 0, "Voesendorf / Siebenhirten Hst", "", 48.125481, 16.319675 },
	{ 7434, 0, "Wiener Neudorf / Hst", "", 48.087253, 16.314011 },
	{ 7515, 0, "Laxenburg / Franz-Josephs-Platz", "", 48.067569, 16.354973 },
	{ 7946, 0, "Moedling / Bike+Ride (Bach)", "", 48.084731, 16.296072 },
	{ 7947, 0, "Moedling / Badstrasse", "", 48.085677, 16.285944 },
	{ 7948, 0, "Moedling / Landesklinikum", "", 48.088629, 16.297038 },
	{ 7949, 0, "Moedling / Stadtbad", "", 48.081921, 16.287274 },
	{ 7951, 0, "Moedling / Schrannenplatz", "", 48.085419, 16.283412 },
	{ 7952, 0, "Brunn / Freizeitanlage Stierwiese", "", 48.102846, 16.297359 },
	{ 7953, 0, "Brunn / Campus21", "", 48.114366, 16.294699 },
	{ 7955, 0, "Biedermannsdorf / Beim Radlheurigen", "", 48.085533, 16.341133 },
	{ 7956, 0, "Laxenburg / Parapluiewiese", "", 48.063999, 16.353149 },
	{ 7957, 0, "Laxenburg / Schlosspark Haupteingang", "", 48.064802, 16.358471 },
	{ 7960, 0, "Ma. Enzersdorf / Franziskanerplatz", "", 48.101126, 16.284099 },
	{ 7961, 0, "Ma. Enzersdorf / Friedhof", "", 48.093732, 16.285429 },
	{ 7962, 0, "Ma. Enzersdorf / Theissplatz", "", 48.095165, 16.304784 },
	{ 7963, 0, "Ma. Enzersdorf / Gemeindeamt", "", 48.098948, 16.284871 },
	{ 7966, 0, "Voesendorf / Schloss", "", 48.121385, 16.341176 },
	{ 7967, 0, "Wiener Neudorf / Rathaus", "", 48.086709, 16.318045 },
	{ 7968, 0, "Wiener Neudorf / C.-Migazzi-Haus", "", 48.084300, 16.324053 },
	{ 7969, 0, "Wiener Neudorf / Reisenbauer Ring", "", 48.089375, 16.310492 },
	{ 9161, 0, "Moedling / Josef-Deutsch-Platz", "", 48.086576, 16.287957 },
	{ 9172, 0, "Brunn / Bahnhof", "", 48.104938, 16.288047 },
	{ 9192, 0, "Biedermannsdorf / Jubiläumshalle", "", 48.081931, 16.346070 },
	{ 11184, 0, "Biedermannsdorf / Laxenburgerstraße /Ortstraße", "", 48.082552, 16.352334 },
	{ 45250, 0, "Perchtoldsdorf / Rodaun", "", 48.121471, 16.276975 },
	{ 45251, 0, "Perchtoldsdorf / Freizeitzentrum", "", 48.121528, 16.263456 },
	{ 45252, 0, "Perchtoldsdorf / Bahnhof", "", 48.120497, 16.284485 },
	{ 45253, 0, "Perchtoldsdorf / Marktplatz", "", 48.121184, 16.277876 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateModling : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateModling() {
    rect = QRectF(QPointF(47.104700, 15.320200), QPointF(49.104700, 17.320200));
    center = QPointF(48.104700, 16.320200);
    statusUrl = "";
    infosUrl = "http://nextbike.net/maps/nextbike-official.xml";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Modling %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_MODLING_H */

