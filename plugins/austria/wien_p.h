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

#ifndef STATIONS_SIMPLE_PRIVATE_WIEN_H
#define STATIONS_SIMPLE_PRIVATE_WIEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 102, 0, "Fahnengasse", "Ecke Herrengasse U3 Station Herrengasse Links Beim Ausgang Fahnengasse", 48.209481, 16.366086 },
	{ 108, 0, "Friedrich Schmidtplatz", "Ecke Lichtenfelsgasse U2 Station Rathaus", 48.210425, 16.3561 },
	{ 109, 0, "Johannesgasse", "Parkring / Stadtpark Beim Haupteingang Des Kursalons", 48.203366, 16.376719 },
	{ 105, 0, "Julius Raab Platz", "Urania /Franz Josefs Kai Bei Aspernbrücke U4 Station Schwedenplatz - Ausgang Urania", 48.211534, 16.382375 },
	{ 112, 0, "Kärntnerring", "Ecke Akademiestraße In Der Mitte Der Beiden Einkaufszentren Der Ringstraßengalerien", 48.202157, 16.371317 },
	{ 111, 0, "Oper", "Opernring - Kärntnerstraße U-Bahnstation Karlsplatz - Ausgang Oper", 48.202675, 16.369512 },
	{ 110, 0, "Rathausplatz", "Dr. Karl Lueger Ring Gegenüber Des Burgtheaters", 48.209921, 16.36025 },
	{ 104, 0, "Schwedenplatz", "Franz-Josefs-Kai / Rotenturmstraße Bei Der U-Bahnstation Schwedenplatz - Ausgang Rotenturmstraße", 48.211699, 16.376655 },
	{ 106, 0, "Stadtpark Stubenring", "Parkring / Weiskirchner Str. / Stadtpark Gegenüber Dem Museum Für Angewandte Kunst", 48.207001, 16.38054 },
	{ 101, 0, "Stephansplatz", "Ecke Schulerstraße Hinter Dem Stephansdom", 48.208514, 16.374044 },
	{ 103, 0, "U4 Schottenring", "Franz-Josefs-Kai / Ringturm / Höhe Werdertorgasse U4 Station Schottenring Beim Ausgang Salztorbrücke", 48.215964, 16.372222 },
	{ 107, 0, "Volksgarten", "Burgring / Volkstheater / Bellaria U2, U3 Station Volkstheater - Ausgang Volksgarten", 48.206507, 16.360413 },
	{ 201, 0, "Heinestraße", "U-Bahn Aufgang Heinestraße", 48.218315, 16.390165 },
	{ 203, 0, "Karmeliterplatz", "", 48.215679, 16.379656 },
	{ 208, 0, "Krieau", "Vorgartenstraße/Trabrennstraße, Unter U2 Krieau", 48.214382, 16.414372 },
	{ 207, 0, "Messeplatz", "Messeplatz", 48.217296, 16.406171 },
	{ 202, 0, "Nepomukgasse", "Nestroyplatz U1", 48.215878, 16.38621 },
	{ 205, 0, "Novaragasse", "Novaragasse/ Glockengasse, U2 Taborstraße Ausgang Novaragasse", 48.2195207051, 16.3822111487 },
	{ 204, 0, "Obere Donaustraße", "Obere Donaustraße Ecke Herminengasse, U2 Schottenring Ausgang Obere Donaustraße", 48.2177746805, 16.3730862737 },
	{ 206, 0, "Praterstern", "Praterstern Schnellbahnunterführung", 48.2178318696, 16.3920307159 },
	{ 209, 0, "Stadion Center", "Meiereistraße/Vorgartenstraße, Unter U2 Stadion", 48.209983, 16.421406 },
	{ 304, 0, "Fasanplatz", "Schnellbahnstation Rennweg", 48.19424, 16.386581 },
	{ 302, 0, "Radetzkyplatz", "Bei Der Schnellbahnunterführung", 48.210683, 16.390219 },
	{ 305, 0, "Salmgasse", "Landstraßer Hauptstraße Beim Rochusmarkt", 48.20341, 16.389782 },
	{ 301, 0, "Schwarzenbergplatz", "Rennweg / Ecke Zaunergasse Vis À Vis Des Hochstrahlbrunnens", 48.198857, 16.376977 },
	{ 303, 0, "Wassergasse", "Landstraßer Hauptstraße Nr. 95 Bei Galeria", 48.199239, 16.394331 },
	{ 401, 0, "Treitlstraße", "Vor Der Tu-Bibliothek, U-Bahn Karlsplatz", 48.19973, 16.36816 },
	{ 504, 0, "Arbeitergasse", "Margaretengürtel Ecke Arbeitergasse Bei Busstation", 48.183886, 16.345832 },
	{ 502, 0, "Falco Stiege", "Kettenbrückengasse U4 Station Kettenbrückengasse - Ausgang Eggerthgasse", 48.19636, 16.357409 },
	{ 506, 0, "Hartmanngasse", "Vor Wiedner Hauptstraße 92", 48.187184, 16.3639 },
	{ 503, 0, "Margaretengürtel U4", "St. Johann Park U4 Station Margaretengürtel", 48.188476, 16.343868 },
	{ 501, 0, "Pilgramgasse U4", "Hamburgerstraße U4 Station Pilgramgasse", 48.192705, 16.354705 },
	{ 505, 0, "Reinprechtsdorfer Brücke", "Rechte Wienzeile Ecke Reinprechtsdorferstraße", 48.189527, 16.351027 },
	{ 601, 0, "Kollergerngasse", "Mariahilferstraße Ecke Kollergerngasse", 48.198527, 16.350918 },
	{ 702, 0, "Burggasse U6", "Neubaugürtel / Burggasse U6 Station Burggasse - Ausgang Burggasse", 48.2036756294, 16.3374263048 },
	{ 701, 0, "Museumsplatz", "Mariahilfer Straße / Museumsquartier U2 Station Museumsquartier", 48.202107, 16.360843 },
	{ 703, 0, "Schottenfeldgasse", "Vor Der Kirche Bei Lerchenfelderstraße", 48.207249, 16.343241 },
	{ 705, 0, "Siebensternplatz", "Siebensterngasse Vor 38 - 40", 48.202161, 16.352033 },
	{ 704, 0, "Urban Loritz Platz", "Neubaugürtel/Märzstraße U6 Station Burggasse - Ausgang Urban Loritz Platz", 48.201035, 16.337727 },
	{ 707, 0, "Webgasse", "Mariahilferstraße 104 Ecke Schottenfeldgasse", 48.196727, 16.343983 },
	{ 706, 0, "Weghuberpark", "Museumstraße 7 Nähe Neustiftgasse", 48.206007, 16.356432 },
	{ 801, 0, "Alser Straße/Feldgasse", "Alser Straße Onr 47", 48.215225, 16.346449 },
	{ 905, 0, "Boltzmanngasse", "Währinger Straße Ecke Boltzmanngasse", 48.220343, 16.356392 },
	{ 904, 0, "Frankhplatz", "Bei Altem Akh Vis À Vis Otto-Wagner-Platz", 48.215156, 16.355145 },
	{ 902, 0, "Julius-Tandler-Platz", "Nordbergstraße Franz Josefs Bahnhof", 48.226085, 16.361919 },
	{ 903, 0, "Roßauer Lände U4", "U4 Station Rossauer Lände - Ausgang Nordwest", 48.2227427415, 16.3674402237 },
	{ 901, 0, "Sigmund Freud Park", "Währingerstraße Ecke Universitätsstraße / Votivkirche Im Park Zwischen Der Votivkirche Und Dem Schottentor", 48.214592, 16.361394 },
	{ 906, 0, "Spittelau U4/U6", "Nordbergbrücke Bei Müllverbrennungsanlage U4 Station Spittelau - Ausgang Wirtschaftsuniversität", 48.235207235, 16.3587445021 },
	{ 1201, 0, "Längenfeldgasse", "U-Bahn Ausgang Storchensteg", 48.184268, 16.333931 },
	{ 1203, 0, "Philadelphiabrücke", "Meidlinger Hauptstraße Ecke Edelsinnstraße", 48.1746, 16.330276 },
	{ 1202, 0, "Reschgasse", "U-Bahnstation Niederhofstraße Vor Reschgassse 24", 48.180249, 16.33078 },
	{ 1301, 0, "Schönbrunn Haupteingang", "Schloß Schönbrunn Gegenüber Haupteingang", 48.186833, 16.314242 },
	{ 1507, 0, "Schmelzbrücke", "Felberstraße 42", 48.1961401257, 16.3302540779 },
	{ 1503, 0, "Schönbrunner Brücke", "", 48.185866, 16.319898 },
	{ 1506, 0, "Schwendermarkt", "", 48.190817229, 16.3255012035 },
	{ 1502, 0, "Westbahnhof", "Europaplatz Beim Westbahnhof", 48.197436347, 16.3385421038 },
	{ 1602, 0, "Hofferplatz", "Hofferplatz Gegenüber 8", 48.2091991735, 16.3334351778 },
	{ 1601, 0, "Josefstädter Straße U6", "Äusserer Hernalser Gürtel U6 Station Josefstädterstraße", 48.211754, 16.339051 },
	{ 1603, 0, "Richard-Wagner-Platz", "Richard-Wagner-Platz Gegenüber 1", 48.2100964698, 16.3279902935 },
	{ 1701, 0, "Alser Straße U6", "Äusserer Hernalser Gürtel U6 Station Alserstraße", 48.216588, 16.341481 },
	{ 1702, 0, "Elterleinplatz", "Kalvarienberggasse Vor 27", 48.2180391794, 16.3322925568 },
	{ 1802, 0, "Nussdorfer Straße U6", "Äusserer Währinger Gürtel U6 Station Nußdorfer Straße", 48.2317287031, 16.3529804349 },
	{ 1801, 0, "Währinger Straße U6", "Äusserer  Währinger Gürtel - Schulgasse U6 Station Währinger Straße", 48.224201, 16.34903 },
	{ 2006, 0, "Friedrich Engels Platz", "Zwischen Bus Und Bim-Haltestelle", 48.244026674, 16.3792365789 },
	{ 2003, 0, "Hellwagstraße", "Meldemannstraße 26 Ecke Hellwagstraße", 48.237464, 16.380315 },
	{ 2002, 0, "Jägerstraße U6", "Jägerstraße - Leipziger Straße U6 Station Jägerstraße", 48.235136, 16.369846 },
	{ 2005, 0, "Millenium Tower", "Am Maria Restituta Platz Zwischen Rivergate Und Schnellbahn", 48.2416741387, 16.3846707344 },
	{ 2004, 0, "Traisengasse", "Dresdnerstraße Vor 85 Ecke Traisengasse", 48.233619, 16.383445 },
	{ 2001, 0, "Wallensteinplatz", "", 48.229912, 16.371582 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateWien : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateWien() {
    rect = QRectF(QPointF(48.009206, 16.172778), QPointF(48.409206, 16.572778));
    center = QPointF(48.209206, 16.372778);
    statusUrl = "";
    infosUrl = "http://dynamisch.citybikewien.at/citybike_xml.php";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Wien %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_WIEN_H */

