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

#ifndef STATIONS_SIMPLE_PRIVATE_ERFURT_H
#define STATIONS_SIMPLE_PRIVATE_ERFURT_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 18466, 0, "Hauptbahnhof", "", 50.972734, 11.037333 },
	{ 18468, 0, "Domplatz / Eingang Parkhaus", "", 50.977213, 11.022968 },
	{ 18471, 0, "Benediktplatz / Tourismusinformation", "", 50.978397, 11.029522 },
	{ 35140, 0, "Domplatz / Ecke Marktstraße", "", 50.977619, 11.024896 },
	{ 42470, 0, "Anger 1 / Krämpferstraße / Krämpfertor", "", 50.978574, 11.037033 },
	{ 42471, 0, "Wenigemarkt / Südlicher Gehweg", "", 50.978353, 11.032076 },
	{ 42472, 0, "Schlösserstraße / Barfüsserstraße", "", 50.976440, 11.030729 },
	{ 42473, 0, "Hirschlachufer / Mühlgasse", "", 50.974891, 11.034169 },
	{ 42474, 0, "Lange Brücke / Regierungsstraße", "", 50.973934, 11.027334 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateErfurt : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateErfurt() {
    rect = QRectF(QPointF(49.971800, 10.025900), QPointF(51.971800, 12.025900));
    center = QPointF(50.971800, 11.025900);
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
      station->setRegion(QString("Erfurt %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_ERFURT_H */

