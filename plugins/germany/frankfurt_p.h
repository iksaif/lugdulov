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
	{ 46, 0, "Südbahnhof / Hedderichstr.", "", 50.0997162704, 8.68535757065 },
	{ 529, 0, "Hauptbahnhof - Vorplatz", "", 50.1074510686, 8.66435050964 },
	{ 683, 0, "Löwengasse / Berger Str.", "", 50.1276905086, 8.70970129967 },
	{ 896, 0, "Hauptwache / Sport Arena", "", 50.1138361529, 8.67961764336 },
	{ 1572, 0, "Fressgass / Neue Mainzer Str.", "", 50.1148750247, 8.67276191711 },
	{ 1640, 0, "Friedberger Platz / Café Harveys", "", 50.1231035031, 8.69294419885 },
	{ 2304, 0, "Römer / Touristeninformation", "", 50.1103925791, 8.68226230145 },
	{ 2612, 0, "Opernplatz / Bockenheimer Landstr. *", "", 50.1153497334, 8.67117404938 },
	{ 3364, 0, "Höhenstraße / Berger Str.", "", 50.1231370367, 8.7015581131 },
	{ 3804, 0, "Fachhochschule Vorplatz / Nibelungenallee", "", 50.1304622742, 8.69205236435 },
	{ 7374, 0, "Merianplatz / Berger Str.", "", 50.1202272651, 8.69557142258 },
	{ 7378, 0, "Bockenheimer Warte / Café Extrablatt", "", 50.1198867483, 8.65040838718 },
	{ 7421, 0, "Sandweg / Pfingstweidstr.", "", 50.1157350008, 8.69548559189 },
	{ 7603, 0, "Saalburgstr. / Bergerstr.", "", 50.1263286395, 8.70803833008 },
	{ 7634, 0, "Schaumainkai / Schweizer Str.", "", 50.1054142678, 8.67782592773 },
	{ 7644, 0, "Leipziger Str. / Markgrafenstr.", "", 50.1227587076, 8.64527463913 },
	{ 7647, 0, "Schweizer Platz / Diesterwegstr. *", "", 50.1017808405, 8.68098020554 },
	{ 7648, 0, "Zoo / Alfred-Brehm-Platz", "", 50.1155561271, 8.69852185249 },
	{ 7649, 0, "Konstabler Wache / Conrad-Elektronik", "", 50.114801926, 8.68726998568 },
	{ 29169, 0, "Willy-Brandt-Platz / Neue Mainzer Str.", "", 50.1092538403, 8.67473602295 },
	{ 42517, 0, "Bockenheimer Landstr. / Mendelssohnstr.", "", 50.1190784413, 8.65975856781 },
	{ 42647, 0, "Eiserner Steg / Mainkai", "", 50.1089923738, 8.68179559708 },
	{ 42728, 0, "Kaiserplatz / Friedensstr.", "", 50.1106643586, 8.67543339729 },
	{ 42800, 0, "Uni-Campus Westend / Grüneburgstr.", "", 50.1271540194, 8.66644263268 },
	{ 42801, 0, "Messe / Festhalle", "", 50.1122037, 8.6508497 },
	{ 52745, 0, "Konstabler Wache / Conrad-Elektronik*", "", 50.1115118, 8.6805059 },
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

