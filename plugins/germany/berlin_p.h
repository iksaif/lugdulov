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

#ifndef STATIONS_SIMPLE_PRIVATE_BERLIN_H
#define STATIONS_SIMPLE_PRIVATE_BERLIN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 6059, 0, "Alexanderplatz/Rotes Rathaus", "", 52.5187409438, 13.4091997147 },
	{ 8451, 0, "Ballongarten, Zimmerstr. 95-100", "", 52.5076541232, 13.3870983124 },
	{ 15073, 0, "Hotel Villa Kastania", "", 52.5102138731, 13.2678794861 },
	{ 15074, 0, "Hotel Domicil", "", 52.506717, 13.3056748 },
	{ 15349, 0, "Bahnhof Potsdamer Platz", "", 52.5097012821, 13.375967145 },
	{ 17204, 0, "Arthotel Berlin City-Center / West", "", 52.4998916, 13.3227862 },
	{ 21216, 0, "Victors Residenz Hotel", "", 52.5294170361, 13.4346538782 },
	{ 23226, 0, "Arthotel Berlin-Mitte Wallstr.", "", 52.5124665909, 13.4103691578 },
	{ 24719, 0, "Unter Den Linden/ Friedrichsstraße", "", 52.5170141171, 13.3885681629 },
	{ 24740, 0, "Budapesterstr./ Eingang Zoo", "", 52.5054599332, 13.3404386044 },
	{ 24741, 0, "Hardenbergplatz / Eingang Zoo", "", 52.5084181458, 13.3347523212 },
	{ 24764, 0, "Gedächtniskirche", "", 52.504555451, 13.3353048563 },
	{ 26307, 0, "Alexanderplatz / Cubix-Filmpalast", "", 52.5205068722, 13.4114903212 },
	{ 29253, 0, "Potsdamer Straße / Bülowstraße", "", 52.4979361644, 13.3622074127 },
	{ 31016, 0, "Hackescher Markt / Neue Promenade", "", 52.523232334, 13.4029340744 },
	{ 31007, 0, "Dom / Am Lustgarten*", "", 52.5183753453, 13.4004986286 },
	{ 31035, 0, "Alexanderplatz/Park Inn Hotel", "", 52.5225534324, 13.4137701988 },
	{ 32563, 0, "Oranienburgerstr. / S-Bahn", "", 52.5253734165, 13.3919048309 },
	{ 35697, 0, "Unter Den Linden - Madame Tussaud", "", 52.5170565541, 13.3844804764 },
	{ 40509, 0, "Pariser Platz / Hotel Adlon", "", 52.5164624323, 13.3796525002 },
	{ 40510, 0, "S. + U.-Bahnhof Friedrichstr.", "", 52.5200205145, 13.3877849579 },
	{ 40511, 0, "U-Bahnhof Wittenbergplatz", "", 52.5017504581, 13.343667984 },
	{ 40512, 0, "Am Kupfergraben / Museumsinsel", "", 52.519446018, 13.3972263336 },
	{ 42387, 0, "Reichstag / Friedrich-Ebert Platz", "", 52.5195504725, 13.3764982224 },
	{ 42389, 0, "Holocaust Mahnmal", "", 52.5145233193, 13.3776783943 },
	{ 42879, 0, "Mercure Hotel / Invalidenstr.", "", 52.5303340603, 13.3814120293 },
	{ 42880, 0, "Bundestag / Paul-Löbel Allee", "", 52.5194721316, 13.3722925186 },
	{ 42881, 0, "Gendarmenmarkt / Sofitel Hotel", "", 52.5147975425, 13.3912718296 },
	{ 43793, 0, "Hu-Dorotheenstr.", "", 52.5193807338, 13.3930850029 },
	{ 43964, 0, "Savignyplatz", "", 52.5059431868, 13.3229076862 },
	{ 43890, 0, "Hauptbahnhof / Washingtonplatz*", "", 52.5241266403, 13.3705222607 },
	{ 44340, 0, "S-Bahn Zoologischer Garten", "", 52.5065113296, 13.3329337835 },
	{ 44437, 0, "Ku\'Damm / Joachimstaler", "", 52.5039187104, 13.330450058 },
	{ 46000, 0, "Nationalgalerie / Reichpietschufer", "", 52.5065439812, 13.3682584763 },
	{ 46258, 0, "Humboldt-Uni - Unter Den Linden", "", 52.5175527376, 13.3939433098 },
	{ 45675, 0, "Kino International-Karl-Marx-Allee", "", 52.5203338731, 13.4228897095 },
	{ 45969, 0, "Eingang Tempelhofer Feld", "", 52.4715993681, 13.3861756325 },
	{ 46980, 0, "Adenauer Platz / Kurfürstenstr.", "", 52.500300543, 13.3076190948 },
	{ 49129, 0, "Werderscher Markt / Auswärtiges Amt", "", 52.5156463177, 13.3984708786 },
	{ 49394, 0, "Kastanienallee / Schönhauser Allee", "", 52.5403515468, 13.4117853642 },
	{ 49399, 0, "Hauptbahnhof / Europaplatz", "", 52.5254060541, 13.3692348003 },
	{ 50580, 0, "Comfort Hotel Lichtenberg", "", 52.5343935387, 13.5174322128 },
	{ 50796, 0, "Kleiststr. / Lietzenburger Strasse", "", 52.5009732573, 13.3460819721 },
	{ 53490, 0, "Maritim Hotel / Stauffenbergstr.", "", 52.5072884325, 13.363494873 },
	{ 56659, 0, "Novotel Berlin Mitte / Fischerinsel 12", "", 52.51307, 13.40527 },
	{ 58455, 0, "Ibis Hotel  Berlin-City West (Brandenburgische Str. 11)", "", 52.48908, 13.31676 },
	{ 62575, 0, "Novotel - Am Tiergarten", "", 52.5137789906, 13.3352029324 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBerlin : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBerlin() {
    rect = QRectF(QPointF(52.308700, 13.156300), QPointF(52.708700, 13.556300));
    center = QPointF(52.508700, 13.356300);
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
      station->setRegion(QString("Berlin %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_BERLIN_H */

