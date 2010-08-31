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

#ifndef STATIONS_SIMPLE_PRIVATE_LUXEMBOURG_H
#define STATIONS_SIMPLE_PRIVATE_LUXEMBOURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 45, 0, "Aubepines", "Val Sainte Croix", 49.61268, 6.0977 },
	{ 47, 0, "Leopold Goebel", "Allée Léopold Goebel 109", 49.6122, 6.10721 },
	{ 44, 0, "Areler Strooss", "Rue Des Aubépines 187", 49.61628, 6.0984 },
	{ 46, 0, "Lonkecher Strooss", "Route De Longwy 241", 49.60556, 6.1 },
	{ 37, 0, "Piscine Bonnevoie", "", 49.597158, 6.135328 },
	{ 43, 0, "Lycee Tech De Bonnevoie", "", 49.590848, 6.141625 },
	{ 27, 0, "Mercier", "", 49.598668, 6.132132 },
	{ 28, 0, "Charly'S Gare", "", 49.612457, 6.123668 },
	{ 18, 0, "Campus Lampertsbierg", "", 49.621819, 6.111472 },
	{ 24, 0, "Bricherhaff", "", 49.632234, 6.170215 },
	{ 26, 0, "Hollerecher Plaz", "", 49.598672, 6.118202 },
	{ 32, 0, "Piscine Olympique", "", 49.624098, 6.150189 },
	{ 25, 0, "Kiem", "", 49.634835, 6.167143 },
	{ 22, 0, "Campus Kirchberg", "", 49.626185, 6.16043 },
	{ 4, 0, "Rocade", "", 49.603039, 6.136168 },
	{ 2, 0, "Gare Centrale", "", 49.600727, 6.133682 },
	{ 38, 0, "Helleg Geescht", "", 49.607965, 6.134491 },
	{ 8, 0, "Metzer Plaz", "", 49.607926, 6.127328 },
	{ 39, 0, "Kraizgrennchen", "", 49.613516, 6.116942 },
	{ 42, 0, "Square Andre", "", 49.62382, 6.119118 },
	{ 40, 0, "Glacis Kapell", "", 49.614776, 6.121037 },
	{ 36, 0, "Rue J.B. Gelle", "", 49.596872, 6.14046 },
	{ 11, 0, "Winston Churchill", "", 49.611422, 6.119684 },
	{ 20, 0, "Coque", "", 49.621723, 6.151343 },
	{ 35, 0, "Gaston Diderich", "", 49.610184, 6.106015 },
	{ 23, 0, "Reimerwee", "", 49.629429, 6.157089 },
	{ 34, 0, "Kolleisch", "", 49.604648, 6.111777 },
	{ 41, 0, "Place Laurent", "", 49.620315, 6.122983 },
	{ 16, 0, "Amelie", "", 49.613438, 6.125687 },
	{ 29, 0, "Monterey", "", 49.609669, 6.119533 },
	{ 19, 0, "Philharmonie", "", 49.61896, 6.141836 },
	{ 10, 0, "Merl Parc", "", 49.608032, 6.111457 },
	{ 14, 0, "Knuedler", "", 49.610949, 6.13139 },
	{ 1, 0, "Leon Xiii", "", 49.598535, 6.137776 },
	{ 30, 0, "Merkels Plaz", "", 49.599879, 6.122489 },
	{ 3, 0, "Stroossbuerger Plaz", "", 49.600602, 6.128214 },
	{ 13, 0, "Gelle Fra", "", 49.609294, 6.129696 },
	{ 5, 0, "Paraiser Plaz", "", 49.603664, 6.131081 },
	{ 6, 0, "Aal Breck", "", 49.60489, 6.133303 },
	{ 7, 0, "Rousegaertchen", "", 49.605788, 6.129042 },
	{ 12, 0, "Aldringen", "", 49.610867, 6.126755 },
	{ 15, 0, "Theater Plaz", "", 49.612902, 6.130939 },
	{ 17, 0, "Robert Schuman", "", 49.61681, 6.125975 },
	{ 21, 0, "Jean Monnet", "", 49.625466, 6.148512 },
	{ 9, 0, "Convict", "", 49.60618, 6.119633 },
	{ 31, 0, "Place De France", "", 49.606246, 6.105798 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateLuxembourg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateLuxembourg() {
    rect = QRectF(QPointF(49.410004, 6.097700), QPointF(49.634835, 6.329596));
    center = QPointF(49.610004, 6.129596);
    statusUrl = "http://www.veloh.lu/service/stationdetails/%1";
    infosUrl = "http://www.veloh.lu/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Luxembourg %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_LUXEMBOURG_H */

