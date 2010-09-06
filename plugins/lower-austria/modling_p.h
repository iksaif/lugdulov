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
	{ 7443, 0, "Moedling / Bahnhof", "", 48.0857339269, 16.2955141068 },
	{ 7418, 0, "Ma. Enzersdorf / Hst", "", 48.0965407089, 16.3138389587 },
	{ 7430, 0, "Wiener Neudorf / Hst Griesfeld", "", 48.0776201817, 16.3124227524 },
	{ 7431, 0, "Voesendorf / Schoenbrunner Allee", "", 48.1352201093, 16.3250827789 },
	{ 7432, 0, "Wiener Neudorf / Ecocenter", "", 48.0734983105, 16.3156414032 },
	{ 7433, 0, "Voesendorf / Siebenhirten Hst", "", 48.1254813739, 16.3196754456 },
	{ 7434, 0, "Wiener Neudorf / Hst", "", 48.0872533199, 16.3140106201 },
	{ 7515, 0, "Laxenburg / Franz-Josephs-Platz", "", 48.0675694053, 16.3549733162 },
	{ 7946, 0, "Moedling / Bike+Ride (Bach)", "", 48.0847305295, 16.2960720062 },
	{ 7947, 0, "Moedling / Badstrasse", "", 48.0856765904, 16.285943985 },
	{ 7948, 0, "Moedling / Landesklinikum", "", 48.0886293352, 16.2970376015 },
	{ 7949, 0, "Moedling / Stadtbad", "", 48.0819209127, 16.2872743607 },
	{ 7951, 0, "Moedling / Schrannenplatz", "", 48.0854185755, 16.2834119797 },
	{ 7952, 0, "Brunn / Freizeitanlage Stierwiese", "", 48.1028460046, 16.2973594666 },
	{ 7953, 0, "Brunn / Campus21", "", 48.1143655019, 16.2946987152 },
	{ 7955, 0, "Biedermannsdorf / Beim Radlheurigen", "", 48.085533249, 16.3411331177 },
	{ 7956, 0, "Laxenburg / Parapluiewiese", "", 48.0639988282, 16.3531494141 },
	{ 7957, 0, "Laxenburg / Schlosspark Haupteingang", "", 48.0648018711, 16.3584709167 },
	{ 7960, 0, "Ma. Enzersdorf / Franziskanerplatz", "", 48.1011264552, 16.2840986252 },
	{ 7961, 0, "Ma. Enzersdorf / Friedhof", "", 48.0937317373, 16.2854290009 },
	{ 7962, 0, "Ma. Enzersdorf / Theissplatz", "", 48.0951649053, 16.3047838211 },
	{ 7963, 0, "Ma. Enzersdorf / Gemeindeamt", "", 48.0989482767, 16.2848711014 },
	{ 7966, 0, "Voesendorf / Schloss", "", 48.1213848247, 16.341176033 },
	{ 7967, 0, "Wiener Neudorf / Rathaus", "", 48.086708637, 16.3180446625 },
	{ 7968, 0, "Wiener Neudorf / C.-Migazzi-Haus", "", 48.0843004961, 16.3240528107 },
	{ 7969, 0, "Wiener Neudorf / Reisenbauer Ring", "", 48.0893746615, 16.3104915619 },
	{ 9161, 0, "Moedling / Josef-Deutsch-Platz", "", 48.0865763, 16.2879574 },
	{ 9172, 0, "Brunn / Bahnhof", "", 48.1049380455, 16.2880468369 },
	{ 9192, 0, "Biedermannsdorf / Jubiläumshalle", "", 48.0819309, 16.3460702 },
	{ 11184, 0, "Biedermannsdorf / Laxenburgerstraße /Ortstraße", "", 48.0825516564, 16.3523340225 },
	{ 45250, 0, "Perchtoldsdorf / Rodaun", "", 48.1214707696, 16.276974678 },
	{ 45251, 0, "Perchtoldsdorf / Freizeitzentrum", "", 48.1215280662, 16.2634563446 },
	{ 45252, 0, "Perchtoldsdorf / Bahnhof", "", 48.1204967185, 16.2844848633 },
	{ 45253, 0, "Perchtoldsdorf / Marktplatz", "", 48.1211842859, 16.2778759003 },
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

