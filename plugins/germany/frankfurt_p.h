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

#ifndef STATIONS_SIMPLE_PRIVATE_FRANKFURT_H
#define STATIONS_SIMPLE_PRIVATE_FRANKFURT_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 46, 0, "Südbahnhof / Hedderichstr.", "", 50.099716, 8.685358 },
	{ 529, 0, "Hauptbahnhof - Vorplatz", "", 50.107451, 8.664351 },
	{ 683, 0, "Löwengasse / Berger Str.", "", 50.127691, 8.709701 },
	{ 896, 0, "Hauptwache / Sport Arena", "", 50.113836, 8.679618 },
	{ 1572, 0, "Fressgass / Neue Mainzer Str.", "", 50.114875, 8.672762 },
	{ 1640, 0, "Friedberger Platz / Café Harveys", "", 50.123104, 8.692944 },
	{ 2304, 0, "Römer / Touristeninformation", "", 50.110393, 8.682262 },
	{ 2612, 0, "Opernplatz / Bockenheimer Landstr. *", "", 50.115350, 8.671174 },
	{ 3364, 0, "Höhenstraße / Berger Str.", "", 50.123137, 8.701558 },
	{ 3804, 0, "Fachhochschule Vorplatz / Nibelungenallee", "", 50.130462, 8.692052 },
	{ 7374, 0, "Merianplatz / Berger Str.", "", 50.120227, 8.695571 },
	{ 7378, 0, "Bockenheimer Warte / Café Extrablatt", "", 50.119887, 8.650408 },
	{ 7421, 0, "Sandweg / Pfingstweidstr.", "", 50.115735, 8.695486 },
	{ 7603, 0, "Saalburgstr. / Bergerstr.", "", 50.126329, 8.708038 },
	{ 7634, 0, "Schaumainkai / Schweizer Str.", "", 50.105414, 8.677826 },
	{ 7644, 0, "Leipziger Str. / Markgrafenstr.", "", 50.122759, 8.645275 },
	{ 7647, 0, "Schweizer Platz / Diesterwegstr. *", "", 50.101781, 8.680980 },
	{ 7648, 0, "Zoo / Alfred-Brehm-Platz", "", 50.115556, 8.698522 },
	{ 7649, 0, "Konstabler Wache / Conrad-Elektronik", "", 50.114802, 8.687270 },
	{ 29169, 0, "Willy-Brandt-Platz / Neue Mainzer Str.", "", 50.109254, 8.674736 },
	{ 42517, 0, "Bockenheimer Landstr. / Mendelssohnstr.", "", 50.119078, 8.659759 },
	{ 42647, 0, "Eiserner Steg / Mainkai", "", 50.108992, 8.681796 },
	{ 42728, 0, "Kaiserplatz / Friedensstr.", "", 50.110664, 8.675433 },
	{ 42800, 0, "Uni-Campus Westend / Grüneburgstr.", "", 50.127154, 8.666443 },
	{ 42801, 0, "Messe / Festhalle", "", 50.112204, 8.650850 },
	{ 52745, 0, "Konstabler Wache / Conrad-Elektronik*", "", 50.111512, 8.680506 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateFrankfurt : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateFrankfurt() {
    rect = QRectF(QPointF(49.107200, 7.663750), QPointF(51.107200, 9.663750));
    center = QPointF(50.107200, 8.663750);
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
      station->setRegion(QString("Frankfurt %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_FRANKFURT_H */

