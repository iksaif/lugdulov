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
	{ 6059, 0, "Alexanderplatz/Rotes Rathaus", "", 52.518741, 13.409200 },
	{ 8451, 0, "Ballongarten, Zimmerstr. 95-100", "", 52.507654, 13.387098 },
	{ 15073, 0, "Hotel Villa Kastania", "", 52.510214, 13.267879 },
	{ 15074, 0, "Hotel Domicil", "", 52.506717, 13.305675 },
	{ 15349, 0, "Bahnhof Potsdamer Platz", "", 52.509701, 13.375967 },
	{ 17204, 0, "Arthotel Berlin City-Center / West", "", 52.499892, 13.322786 },
	{ 21216, 0, "Victors Residenz Hotel", "", 52.529417, 13.434654 },
	{ 23226, 0, "Arthotel Berlin-Mitte Wallstr.", "", 52.512467, 13.410369 },
	{ 24719, 0, "Unter Den Linden/ Friedrichsstraße", "", 52.517014, 13.388568 },
	{ 24740, 0, "Budapesterstr./ Eingang Zoo", "", 52.505460, 13.340439 },
	{ 24741, 0, "Hardenbergplatz / Eingang Zoo", "", 52.508418, 13.334752 },
	{ 24764, 0, "Gedächtniskirche", "", 52.504555, 13.335305 },
	{ 26307, 0, "Alexanderplatz / Cubix-Filmpalast", "", 52.520507, 13.411490 },
	{ 29253, 0, "Potsdamer Straße / Bülowstraße", "", 52.497936, 13.362207 },
	{ 31016, 0, "Hackescher Markt / Neue Promenade", "", 52.523232, 13.402934 },
	{ 31007, 0, "Dom / Am Lustgarten*", "", 52.518375, 13.400499 },
	{ 31035, 0, "Alexanderplatz/Park Inn Hotel", "", 52.522553, 13.413770 },
	{ 32563, 0, "Oranienburgerstr. / S-Bahn", "", 52.525373, 13.391905 },
	{ 35697, 0, "Unter Den Linden - Madame Tussaud", "", 52.517057, 13.384480 },
	{ 40509, 0, "Pariser Platz / Hotel Adlon", "", 52.516462, 13.379653 },
	{ 40510, 0, "S. + U.-Bahnhof Friedrichstr.", "", 52.520021, 13.387785 },
	{ 40511, 0, "U-Bahnhof Wittenbergplatz", "", 52.501750, 13.343668 },
	{ 40512, 0, "Am Kupfergraben / Museumsinsel", "", 52.519446, 13.397226 },
	{ 42387, 0, "Reichstag / Friedrich-Ebert Platz", "", 52.519550, 13.376498 },
	{ 42389, 0, "Holocaust Mahnmal", "", 52.514523, 13.377678 },
	{ 42879, 0, "Mercure Hotel / Invalidenstr.", "", 52.530334, 13.381412 },
	{ 42880, 0, "Bundestag / Paul-Löbel Allee", "", 52.519472, 13.372293 },
	{ 42881, 0, "Gendarmenmarkt / Sofitel Hotel", "", 52.514798, 13.391272 },
	{ 43793, 0, "Hu-Dorotheenstr.", "", 52.519381, 13.393085 },
	{ 43964, 0, "Savignyplatz", "", 52.505943, 13.322908 },
	{ 43890, 0, "Hauptbahnhof / Washingtonplatz*", "", 52.524127, 13.370522 },
	{ 44340, 0, "S-Bahn Zoologischer Garten", "", 52.506511, 13.332934 },
	{ 44437, 0, "Ku\'Damm / Joachimstaler", "", 52.503919, 13.330450 },
	{ 46000, 0, "Nationalgalerie / Reichpietschufer", "", 52.506544, 13.368258 },
	{ 46258, 0, "Humboldt-Uni - Unter Den Linden", "", 52.517553, 13.393943 },
	{ 45675, 0, "Kino International-Karl-Marx-Allee", "", 52.520334, 13.422890 },
	{ 45969, 0, "Eingang Tempelhofer Feld", "", 52.471599, 13.386176 },
	{ 46980, 0, "Adenauer Platz / Kurfürstenstr.", "", 52.500301, 13.307619 },
	{ 49129, 0, "Werderscher Markt / Auswärtiges Amt", "", 52.515646, 13.398471 },
	{ 49394, 0, "Kastanienallee / Schönhauser Allee", "", 52.540352, 13.411785 },
	{ 49399, 0, "Hauptbahnhof / Europaplatz", "", 52.525406, 13.369235 },
	{ 50580, 0, "Comfort Hotel Lichtenberg", "", 52.534394, 13.517432 },
	{ 50796, 0, "Kleiststr. / Lietzenburger Strasse", "", 52.500973, 13.346082 },
	{ 53490, 0, "Maritim Hotel / Stauffenbergstr.", "", 52.507288, 13.363495 },
	{ 56659, 0, "Novotel Berlin Mitte / Fischerinsel 12", "", 52.513070, 13.405270 },
	{ 58455, 0, "Ibis Hotel  Berlin-City West (Brandenburgische Str. 11)", "", 52.489080, 13.316760 },
	{ 62575, 0, "Novotel - Am Tiergarten", "", 52.513779, 13.335203 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBerlin : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBerlin() {
    rect = QRectF(QPointF(51.508700, 12.356300), QPointF(53.508700, 14.356300));
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

