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

#ifndef STATIONS_SIMPLE_PRIVATE_LUZERN_H
#define STATIONS_SIMPLE_PRIVATE_LUZERN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 16871, 0, "Bahnhof Sbb / Zentralstr. 5", "", 47.049467, 8.309569 },
	{ 19515, 0, "Hotel Radisson / Inseliquai 12", "", 47.048151, 8.314054 },
	{ 23220, 0, "Jugendherberge / Sedelstr. 12", "", 47.061713, 8.301630 },
	{ 24871, 0, "Verkehrshaus / Lidostr.", "", 47.053254, 8.334546 },
	{ 25987, 0, "Horw, Bahnhof Zb / Gleis 1", "", 47.017395, 8.307080 },
	{ 26816, 0, "Emmen, Bahnhofstrasse 11", "", 47.070568, 8.281921 },
	{ 34380, 0, "Kkl / Robert-Zündstr.", "", 47.050388, 8.311586 },
	{ 34386, 0, "Inseliquai 1 / Frohburgstrasse", "", 47.049920, 8.313035 },
	{ 34387, 0, "Werftestr. / Ufschötti", "", 47.046541, 8.317938 },
	{ 34389, 0, "Pilatusstr. 1", "", 47.049847, 8.308829 },
	{ 34390, 0, "Pilatusstr. 8 / Seidenhofstr.", "", 47.049686, 8.307724 },
	{ 34394, 0, "Morgartenstr. / Frankenstr.", "", 47.048897, 8.308089 },
	{ 34395, 0, "Habsburgerstr. 1A / Zentralstr.", "", 47.047522, 8.309484 },
	{ 34396, 0, "Pilatusstr. 35 / Winkelriedstr.", "", 47.048451, 8.305610 },
	{ 34397, 0, "Bundesplatz / Zentralstr.", "", 47.045991, 8.309172 },
	{ 34398, 0, "Habsburgerstr. / Winkelriedstr.", "", 47.046623, 8.306774 },
	{ 34399, 0, "Moosstr. / Obergrundstr.", "", 47.045808, 8.304216 },
	{ 34401, 0, "Paulusplatz / Obergrundstr.", "", 47.043077, 8.303282 },
	{ 34404, 0, "Bireggstr. / Neustadtstr.", "", 47.041315, 8.307660 },
	{ 34405, 0, "Stadttheater / Hirschengraben", "", 47.050595, 8.305710 },
	{ 34407, 0, "Kasernenplatz / Naturmuseum", "", 47.051587, 8.300740 },
	{ 34408, 0, "Pilatusplatz / Hallwilerweg", "", 47.047771, 8.303325 },
	{ 38563, 0, "Rösslimattstr. / Werkhofstr.", "", 47.044390, 8.314438 },
	{ 38564, 0, "Tribschenstr. / Werkhofstr.", "", 47.043428, 8.314118 },
	{ 38565, 0, "Tribschenstr. /  Eisfeldstr.", "", 47.040972, 8.320298 },
	{ 38566, 0, "Schönbühlcenter", "", 47.037272, 8.327293 },
	{ 38567, 0, "Kriens, Matthof Sbb-Station", "", 47.026623, 8.302427 },
	{ 38568, 0, "Allmend / Horwerstr. 85", "", 47.033989, 8.303132 },
	{ 38569, 0, "Kriens, Gallusstr. / Luzernerstr.", "", 47.033740, 8.279582 },
	{ 38570, 0, "Horw, Station Zentrum", "", 47.019486, 8.311543 },
	{ 38571, 0, "Bahnhof Littau / P& R", "", 47.053261, 8.257309 },
	{ 38572, 0, "Hauptpost / Bahnhofstr. 1", "", 47.050885, 8.309054 },
	{ 38574, 0, "Roupigenplatz 1", "", 47.062752, 8.273832 },
	{ 38576, 0, "Burgerstr. / Bahnhofstr.", "", 47.050319, 8.302853 },
	{ 38582, 0, "Maihofstr. / Vellasterstr.", "", 47.061761, 8.308593 },
	{ 38583, 0, "St. Karlistr. /  Geissmattstr.", "", 47.053941, 8.299087 },
	{ 38584, 0, "Kantonspital Personalhaus 2 / Spitalstr.", "", 47.057442, 8.296652 },
	{ 38585, 0, "Bruchstr. / Schützenstr.", "", 47.050521, 8.299581 },
	{ 38586, 0, "Löwengraben (Mühleplatz)", "", 47.052393, 8.303148 },
	{ 38587, 0, "Grendelstr. 8", "", 47.053513, 8.307756 },
	{ 38588, 0, "Seehofstr. / Matthäuskirche", "", 47.054361, 8.309011 },
	{ 38589, 0, "Löwenplatz / Bourbaki-Panorama", "", 47.057175, 8.310782 },
	{ 38590, 0, "Hofkirche / Luzernerstr.", "", 47.054862, 8.312552 },
	{ 38591, 0, "Lido Strandbad / Park&Ride", "", 47.049949, 8.336563 },
	{ 38592, 0, "Kriens, Bellpark / Luzernerstr.", "", 47.034088, 8.282313 },
	{ 39632, 0, "Haldenstrasse 33", "", 47.055249, 8.317155 },
	{ 39633, 0, "Ewl / Industriestrasse 6", "", 47.040972, 8.311018 },
	{ 39635, 0, "Kreuzstutz / Baselstr.", "", 47.054423, 8.290987 },
	{ 39636, 0, "Obergrundstr. / Eichhof", "", 47.040577, 8.301415 },
	{ 39637, 0, "Kriens, Luzernerstr. / St. Kupferhammer", "", 47.037002, 8.292124 },
	{ 39638, 0, "Moosstr. / Bundesstr.", "", 47.045415, 8.307657 },
	{ 42813, 0, "Horw, Kantonsstr. / Winkelstr.", "", 47.014264, 8.311436 },
	{ 42814, 0, "Horw, Kantonsstr. / Kastanienbaumstr.", "", 47.022968, 8.309033 },
	{ 42821, 0, "Kantonalbank / Pilatusstr. 12", "", 47.049178, 8.306597 },
	{ 42822, 0, "Nationalquai / Seebad (Badesaison)", "", 47.054825, 8.317734 },
	{ 43708, 0, "Haldenstr. 16 / Vis-A-Vis Beau Sejour", "", 47.055344, 8.322980 },
	{ 43734, 0, "Velostation Bhf, 04.45-01.15", "", 47.049569, 8.311393 },
	{ 57172, 0, "Weinberglistr. 4", "", 47.041800, 8.316640 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateLuzern : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateLuzern() {
    rect = QRectF(QPointF(46.047600, 7.301100), QPointF(48.047600, 9.301100));
    center = QPointF(47.047600, 8.301100);
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
      station->setRegion(QString("Luzern %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_LUZERN_H */

