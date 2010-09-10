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

#ifndef STATIONS_SIMPLE_PRIVATE_LEIPZIG_H
#define STATIONS_SIMPLE_PRIVATE_LEIPZIG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 28, 0, "Bosestraße / Gottschedstraße - Schauspielhaus", "", 51.340500, 12.368900 },
	{ 72, 0, "Augustusplatz / Oper", "", 51.339017, 12.381506 },
	{ 125, 0, "Thomaskirchhof", "", 51.339671, 12.373280 },
	{ 128, 0, "Burgplatz", "", 51.337006, 12.373191 },
	{ 149, 0, "Mercure Johannisplatz", "", 51.335201, 12.388400 },
	{ 172, 0, "Brühl / Nicolaistr. / Bagelbrothers", "", 51.342744, 12.378432 },
	{ 801, 0, "Karl-Liebknecht-Str. / Kurt-Eisner-Straße", "", 51.320629, 12.373717 },
	{ 1615, 0, "Jahnallee /Thomasiusstr.", "", 51.342999, 12.365100 },
	{ 1727, 0, "Südplatz", "", 51.324464, 12.373626 },
	{ 2031, 0, "Grassistr. / Beethovenstr.", "", 51.332199, 12.367100 },
	{ 5214, 0, "Hauptbahnhof Westseite", "", 51.344379, 12.380015 },
	{ 6067, 0, "Marriott Hotel Leipzig", "", 51.343387, 12.376914 },
	{ 8008, 0, "Karl-Liebknecht-Straße 12 / Lvb", "", 51.330122, 12.373461 },
	{ 8296, 0, "Hauptbahnhof / Unterführung", "", 51.344018, 12.379467 },
	{ 8371, 0, "Stadtwerke Leipzig / Goerdelerring", "", 51.344830, 12.371880 },
	{ 8407, 0, "Zoo", "", 51.348728, 12.371432 },
	{ 8408, 0, "Nikolaikirche", "", 51.340344, 12.378464 },
	{ 8678, 0, "Gottschedstraße / Thomasiusstraße", "", 51.341376, 12.365112 },
	{ 9520, 0, "Könneritzstraße / Anton-Bruckner-Allee", "", 51.328996, 12.346637 },
	{ 9623, 0, "Hainstraße / Baguette Company", "", 51.342589, 12.373116 },
	{ 9889, 0, "Wilhelm-Leuschner-Platz", "", 51.335999, 12.375297 },
	{ 10054, 0, "Dittrichring", "", 51.339822, 12.371517 },
	{ 10057, 0, "Htwk/Subway", "", 51.315043, 12.373030 },
	{ 10069, 0, "Bayrischer Platz", "", 51.331205, 12.380621 },
	{ 10780, 0, "Münzgasse / Petersteinweg", "", 51.332898, 12.373465 },
	{ 10882, 0, "Könneritzstraße / Industriestraße / Apotheke", "", 51.323997, 12.343809 },
	{ 11343, 0, "Käthe-Kollwitz-Straße / Dittrichring", "", 51.341886, 12.369061 },
	{ 11373, 0, "Westplatz", "", 51.338789, 12.363138 },
	{ 14311, 0, "Nordplatz", "", 51.353211, 12.373502 },
	{ 15091, 0, "Philipp-Rosenthal-Straße/Johannisallee", "", 51.327682, 12.388512 },
	{ 16337, 0, "Lvb Mobilitätszentrale", "", 51.343656, 12.379095 },
	{ 18268, 0, "Arthotel / Eutritzscher Straße / Erich-Weinert-Straße", "", 51.349673, 12.376128 },
	{ 17010, 0, "Mr.Moto Sushi/Fleischergasse", "", 51.341507, 12.372075 },
	{ 17012, 0, "Großer Brockhaus 3 / Penta Hotel", "", 51.340519, 12.386978 },
	{ 19094, 0, "Waldplatz", "", 51.342211, 12.359512 },
	{ 19780, 0, "Ostplatz / Dresdner-Bank", "", 51.332403, 12.395398 },
	{ 21223, 0, "Roßplatz / Haltestelle Linie 16", "", 51.335507, 12.378674 },
	{ 21226, 0, "Petersstraße / Musikschule", "", 51.336752, 12.375240 },
	{ 21231, 0, "Uni Kliniken Haupteingang", "", 51.331577, 12.385798 },
	{ 22521, 0, "Richard-Wagner-Str. / Touristinformation", "", 51.342904, 12.380497 },
	{ 24394, 0, "Wilhelm-Liebknecht-Platz", "", 51.349586, 12.377499 },
	{ 26928, 0, "Könneritzstraße / Oeserstr.", "", 51.319496, 12.341187 },
	{ 32097, 0, "Hauptbahnhof / Westhalle", "", 51.344406, 12.379789 },
	{ 32021, 0, "Hauptbahnhof / Osthalle", "", 51.343910, 12.381592 },
	{ 32663, 0, "Hauptbahnhof / Westseite", "", 51.345558, 12.379180 },
	{ 32710, 0, "Hauptbahnhof / Ostseite", "", 51.344010, 12.383265 },
	{ 40487, 0, "Poetenweg/ Gohliser Str.", "", 51.357150, 12.368460 },
	{ 41466, 0, "Gottschedstraße / Käthe-Kollwitz-Straße", "", 51.341095, 12.367430 },
	{ 42446, 0, "Schaubühne Lindenfels", "", 51.331600, 12.334630 },
	{ 41763, 0, "Haltestelle Gerichtsweg", "", 51.339155, 12.395861 },
	{ 43753, 0, "Straßenbahnhof Angerbrücke", "", 51.337504, 12.340026 },
	{ 46301, 0, "Listhaus / Friedrich-List-Platz", "", 51.345478, 12.391140 },
	{ 51552, 0, "Nextbike Laden", "", 51.341140, 12.365210 },
	{ 52750, 0, "Grimmasche Str. Kaufhof", "", 51.339671, 12.376657 },
	{ 52805, 0, "Lehmanns Buchhandlung Grimmasche Str.", "", 51.339587, 12.378003 },
	{ 52806, 0, "Vapiano Augustusplatz", "", 51.339426, 12.379805 },
	{ 60112, 0, "Käthe Kollwitz Str. / Dittrichring", "", 51.340102, 12.371830 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateLeipzig : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateLeipzig() {
    rect = QRectF(QPointF(50.340200, 11.372200), QPointF(52.340200, 13.372200));
    center = QPointF(51.340200, 12.372200);
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
      station->setRegion(QString("Leipzig %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_LEIPZIG_H */

