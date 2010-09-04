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
	{ 16871, 0, "Bahnhof Sbb / Zentralstr. 5", "", 47.0494669976, 8.30956935883 },
	{ 19515, 0, "Hotel Radisson / Inseliquai 12", "", 47.0481511325, 8.3140540123 },
	{ 23220, 0, "Jugendherberge / Sedelstr. 12", "", 47.0617131, 8.3016302 },
	{ 24871, 0, "Verkehrshaus / Lidostr.", "", 47.0532535837, 8.33454608917 },
	{ 25987, 0, "Horw, Bahnhof Zb / Gleis 1", "", 47.0173945096, 8.30708026886 },
	{ 26816, 0, "Emmen, Bahnhofstrasse 11", "", 47.0705675758, 8.2819211483 },
	{ 34380, 0, "Kkl / Robert-Zündstr.", "", 47.0503880838, 8.31158638 },
	{ 34386, 0, "Inseliquai 1 / Frohburgstrasse", "", 47.0499202325, 8.31303477287 },
	{ 34387, 0, "Werftestr. / Ufschötti", "", 47.0465409812, 8.31793785095 },
	{ 34389, 0, "Pilatusstr. 1", "", 47.0498471303, 8.30882906914 },
	{ 34390, 0, "Pilatusstr. 8 / Seidenhofstr.", "", 47.0496863052, 8.30772399902 },
	{ 34394, 0, "Morgartenstr. / Frankenstr.", "", 47.0488967933, 8.30808877945 },
	{ 34395, 0, "Habsburgerstr. 1A / Zentralstr.", "", 47.0475224299, 8.30948352814 },
	{ 34396, 0, "Pilatusstr. 35 / Winkelriedstr.", "", 47.0484508601, 8.30561041832 },
	{ 34397, 0, "Bundesplatz / Zentralstr.", "", 47.0459908502, 8.30917239189 },
	{ 34398, 0, "Habsburgerstr. / Winkelriedstr.", "", 47.0466232262, 8.30677449703 },
	{ 34399, 0, "Moosstr. / Obergrundstr.", "", 47.0458080812, 8.30421566963 },
	{ 34401, 0, "Paulusplatz / Obergrundstr.", "", 47.0430774376, 8.30328226089 },
	{ 34404, 0, "Bireggstr. / Neustadtstr.", "", 47.0413154221, 8.30765962601 },
	{ 34405, 0, "Stadttheater / Hirschengraben", "", 47.050594595, 8.30570966005 },
	{ 34407, 0, "Kasernenplatz / Naturmuseum", "", 47.0515869341, 8.30073952675 },
	{ 34408, 0, "Pilatusplatz / Hallwilerweg", "", 47.0477709876, 8.30332517624 },
	{ 38563, 0, "Rösslimattstr. / Werkhofstr.", "", 47.0443897724, 8.31443756819 },
	{ 38564, 0, "Tribschenstr. / Werkhofstr.", "", 47.0434283715, 8.31411838531 },
	{ 38565, 0, "Tribschenstr. /  Eisfeldstr.", "", 47.0409717857, 8.32029819489 },
	{ 38566, 0, "Schönbühlcenter", "", 47.037272071, 8.327293396 },
	{ 38567, 0, "Kriens, Matthof Sbb-Station", "", 47.026622992, 8.30242663622 },
	{ 38568, 0, "Allmend / Horwerstr. 85", "", 47.0339889077, 8.30313205719 },
	{ 38569, 0, "Kriens, Gallusstr. / Luzernerstr.", "", 47.0337402858, 8.27958226204 },
	{ 38570, 0, "Horw, Station Zentrum", "", 47.0194864632, 8.31154346466 },
	{ 38571, 0, "Bahnhof Littau / P& R", "", 47.0532608935, 8.25730919838 },
	{ 38572, 0, "Hauptpost / Bahnhofstr. 1", "", 47.0508851714, 8.30905437469 },
	{ 38574, 0, "Roupigenplatz 1", "", 47.0627517611, 8.27383160591 },
	{ 38576, 0, "Burgerstr. / Bahnhofstr.", "", 47.0503186374, 8.30285310745 },
	{ 38582, 0, "Maihofstr. / Vellasterstr.", "", 47.0617614568, 8.30859303474 },
	{ 38583, 0, "St. Karlistr. /  Geissmattstr.", "", 47.053940696, 8.299087286 },
	{ 38584, 0, "Kantonspital Personalhaus 2 / Spitalstr.", "", 47.0574419074, 8.29665184021 },
	{ 38585, 0, "Bruchstr. / Schützenstr.", "", 47.0505214938, 8.29958081245 },
	{ 38586, 0, "Löwengraben (Mühleplatz)", "", 47.0523928534, 8.30314815044 },
	{ 38587, 0, "Grendelstr. 8", "", 47.0535130793, 8.30775618553 },
	{ 38588, 0, "Seehofstr. / Matthäuskirche", "", 47.0543609997, 8.30901145935 },
	{ 38589, 0, "Löwenplatz / Bourbaki-Panorama", "", 47.0571751217, 8.3107817173 },
	{ 38590, 0, "Hofkirche / Luzernerstr.", "", 47.054861705, 8.31255197525 },
	{ 38591, 0, "Lido Strandbad / Park&Ride", "", 47.0499494733, 8.33656311035 },
	{ 38592, 0, "Kriens, Bellpark / Luzernerstr.", "", 47.0340876249, 8.28231275082 },
	{ 39632, 0, "Haldenstrasse 33", "", 47.0552491088, 8.31715464592 },
	{ 39633, 0, "Ewl / Industriestrasse 6", "", 47.0409717857, 8.31101775169 },
	{ 39635, 0, "Kreuzstutz / Baselstr.", "", 47.0544231313, 8.29098701477 },
	{ 39636, 0, "Obergrundstr. / Eichhof", "", 47.0405769667, 8.30141544342 },
	{ 39637, 0, "Kriens, Luzernerstr. / St. Kupferhammer", "", 47.0370015284, 8.29212427139 },
	{ 39638, 0, "Moosstr. / Bundesstr.", "", 47.0454151257, 8.3076569438 },
	{ 42813, 0, "Horw, Kantonsstr. / Winkelstr.", "", 47.0142637408, 8.3114361763 },
	{ 42814, 0, "Horw, Kantonsstr. / Kastanienbaumstr.", "", 47.0229679943, 8.30903291702 },
	{ 42821, 0, "Kantonalbank / Pilatusstr. 12", "", 47.049178241, 8.30659747124 },
	{ 42822, 0, "Nationalquai / Seebad (Badesaison)", "", 47.0548251574, 8.31773400307 },
	{ 43708, 0, "Haldenstr. 16 / Vis-A-Vis Beau Sejour", "", 47.055344132, 8.3229804039 },
	{ 43734, 0, "Velostation Bhf, 04.45-01.15", "", 47.0495693413, 8.31139326096 },
	{ 57172, 0, "Weinberglistr. 4", "", 47.0418001, 8.3166403 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateLuzern : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateLuzern() {
    rect = QRectF(QPointF(46.847600, 8.101100), QPointF(47.247600, 8.501100));
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

