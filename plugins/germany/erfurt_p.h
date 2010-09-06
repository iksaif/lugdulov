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
	{ 18466, 0, "Hauptbahnhof", "", 50.9727344228, 11.0373330116 },
	{ 18468, 0, "Domplatz / Eingang Parkhaus", "", 50.9772133302, 11.0229684412 },
	{ 18471, 0, "Benediktplatz / Tourismusinformation", "", 50.9783971623, 11.029522419 },
	{ 35140, 0, "Domplatz / Ecke Marktstraße", "", 50.9776186399, 11.0248956084 },
	{ 42470, 0, "Anger 1 / Krämpferstraße / Krämpfertor", "", 50.9785744812, 11.0370326042 },
	{ 42471, 0, "Wenigemarkt / Südlicher Gehweg", "", 50.9783532547, 11.032075882 },
	{ 42472, 0, "Schlösserstraße / Barfüsserstraße", "", 50.9764398545, 11.030729413 },
	{ 42473, 0, "Hirschlachufer / Mühlgasse", "", 50.9748911754, 11.0341693461 },
	{ 42474, 0, "Lange Brücke / Regierungsstraße", "", 50.9739335693, 11.0273337364 },
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

