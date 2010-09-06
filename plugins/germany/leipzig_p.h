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
	{ 28, 0, "Bosestraße / Gottschedstraße - Schauspielhaus", "", 51.3404998779, 12.3689002991 },
	{ 72, 0, "Augustusplatz / Oper", "", 51.3390172461, 12.3815059662 },
	{ 125, 0, "Thomaskirchhof", "", 51.3396707276, 12.3732796311 },
	{ 128, 0, "Burgplatz", "", 51.3370064752, 12.3731911182 },
	{ 149, 0, "Mercure Johannisplatz", "", 51.3352012634, 12.3884000778 },
	{ 172, 0, "Brühl / Nicolaistr. / Bagelbrothers", "", 51.3427436415, 12.3784321547 },
	{ 801, 0, "Karl-Liebknecht-Str. / Kurt-Eisner-Straße", "", 51.3206288142, 12.3737168312 },
	{ 1615, 0, "Jahnallee /Thomasiusstr.", "", 51.3429985046, 12.3650999069 },
	{ 1727, 0, "Südplatz", "", 51.324464, 12.3736256 },
	{ 2031, 0, "Grassistr. / Beethovenstr.", "", 51.3321990967, 12.367099762 },
	{ 5214, 0, "Hauptbahnhof Westseite", "", 51.3443788704, 12.380014658 },
	{ 6067, 0, "Marriott Hotel Leipzig", "", 51.3433870172, 12.3769140244 },
	{ 8008, 0, "Karl-Liebknecht-Straße 12 / Lvb", "", 51.3301222, 12.3734613 },
	{ 8296, 0, "Hauptbahnhof / Unterführung", "", 51.3440178183, 12.3794674873 },
	{ 8371, 0, "Stadtwerke Leipzig / Goerdelerring", "", 51.3448295534, 12.371879518 },
	{ 8407, 0, "Zoo", "", 51.3487280274, 12.3714315891 },
	{ 8408, 0, "Nikolaikirche", "", 51.3403444, 12.3784638 },
	{ 8678, 0, "Gottschedstraße / Thomasiusstraße", "", 51.3413764381, 12.3651123047 },
	{ 9520, 0, "Könneritzstraße / Anton-Bruckner-Allee", "", 51.3289960292, 12.346637249 },
	{ 9623, 0, "Hainstraße / Baguette Company", "", 51.342589498, 12.3731160164 },
	{ 9889, 0, "Wilhelm-Leuschner-Platz", "", 51.335999381, 12.3752966523 },
	{ 10054, 0, "Dittrichring", "", 51.3398215297, 12.3715174198 },
	{ 10057, 0, "Htwk/Subway", "", 51.3150431167, 12.3730301857 },
	{ 10069, 0, "Bayrischer Platz", "", 51.331204907, 12.3806208372 },
	{ 10780, 0, "Münzgasse / Petersteinweg", "", 51.3328975259, 12.3734647036 },
	{ 10882, 0, "Könneritzstraße / Industriestraße / Apotheke", "", 51.3239968, 12.3438088 },
	{ 11343, 0, "Käthe-Kollwitz-Straße / Dittrichring", "", 51.3418857931, 12.3690605164 },
	{ 11373, 0, "Westplatz", "", 51.3387893631, 12.3631381989 },
	{ 14311, 0, "Nordplatz", "", 51.3532107788, 12.3735022545 },
	{ 15091, 0, "Philipp-Rosenthal-Straße/Johannisallee", "", 51.3276820484, 12.3885118961 },
	{ 16337, 0, "Lvb Mobilitätszentrale", "", 51.3436559255, 12.3790946603 },
	{ 18268, 0, "Arthotel / Eutritzscher Straße / Erich-Weinert-Straße", "", 51.3496728591, 12.3761281371 },
	{ 17010, 0, "Mr.Moto Sushi/Fleischergasse", "", 51.3415073, 12.3720747 },
	{ 17012, 0, "Großer Brockhaus 3 / Penta Hotel", "", 51.3405185641, 12.3869776726 },
	{ 19094, 0, "Waldplatz", "", 51.3422108391, 12.3595118523 },
	{ 19780, 0, "Ostplatz / Dresdner-Bank", "", 51.3324035, 12.3953978 },
	{ 21223, 0, "Roßplatz / Haltestelle Linie 16", "", 51.3355067, 12.3786736 },
	{ 21226, 0, "Petersstraße / Musikschule", "", 51.3367517713, 12.3752403259 },
	{ 21231, 0, "Uni Kliniken Haupteingang", "", 51.3315769533, 12.3857975006 },
	{ 22521, 0, "Richard-Wagner-Str. / Touristinformation", "", 51.3429044863, 12.3804974556 },
	{ 24394, 0, "Wilhelm-Liebknecht-Platz", "", 51.3495857477, 12.3774987459 },
	{ 26928, 0, "Könneritzstraße / Oeserstr.", "", 51.3194956364, 12.3411870003 },
	{ 32097, 0, "Hauptbahnhof / Westhalle", "", 51.344405677, 12.3797893524 },
	{ 32021, 0, "Hauptbahnhof / Osthalle", "", 51.3439097534, 12.3815917969 },
	{ 32663, 0, "Hauptbahnhof / Westseite", "", 51.3455583436, 12.379180491 },
	{ 32710, 0, "Hauptbahnhof / Ostseite", "", 51.3440102788, 12.3832654953 },
	{ 40487, 0, "Poetenweg/ Gohliser Str.", "", 51.3571504134, 12.3684597015 },
	{ 41466, 0, "Gottschedstraße / Käthe-Kollwitz-Straße", "", 51.3410949499, 12.3674297333 },
	{ 42446, 0, "Schaubühne Lindenfels", "", 51.3316, 12.33463 },
	{ 41763, 0, "Haltestelle Gerichtsweg", "", 51.3391546, 12.3958611 },
	{ 43753, 0, "Straßenbahnhof Angerbrücke", "", 51.3375041, 12.3400256 },
	{ 46301, 0, "Listhaus / Friedrich-List-Platz", "", 51.345477926, 12.391140461 },
	{ 51552, 0, "Nextbike Laden", "", 51.34114, 12.36521 },
	{ 52750, 0, "Grimmasche Str. Kaufhof", "", 51.3396707276, 12.3766565323 },
	{ 52805, 0, "Lehmanns Buchhandlung Grimmasche Str.", "", 51.3395869484, 12.3780030012 },
	{ 52806, 0, "Vapiano Augustusplatz", "", 51.339426092, 12.3798054457 },
	{ 60112, 0, "Käthe Kollwitz Str. / Dittrichring", "", 51.3401015, 12.3718305 },
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

