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

#ifndef STATIONS_SIMPLE_PRIVATE_BIELEFELD_H
#define STATIONS_SIMPLE_PRIVATE_BIELEFELD_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 42241, 0, "Hauptbahnhof", "", 52.028756, 8.533121 },
	{ 42243, 0, "Turmstraße 10 / Puddingtown-Bikes", "", 52.030132, 8.524468 },
	{ 42244, 0, "Jahnplatz S-Bahn-Hst", "", 52.022983, 8.532718 },
	{ 42245, 0, "Alex Am Theater", "", 52.020547, 8.534274 },
	{ 42433, 0, "Niederwall 10 / Galerie Samuelis Baumgarte E.K.", "", 52.021626, 8.534167 },
	{ 42452, 0, "Stresemannstraße Hst", "", 52.024831, 8.534253 },
	{ 47357, 0, "Niedernstraße (Neue Westfälische)", "", 52.022105, 8.531806 },
	{ 61803, 0, "Bunnemannplatz (Mercur Hotel)", "", 52.019226, 8.529704 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBielefeld : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBielefeld() {
    rect = QRectF(QPointF(51.025700, 7.532860), QPointF(53.025700, 9.532860));
    center = QPointF(52.025700, 8.532860);
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
      station->setRegion(QString("Bielefeld %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_BIELEFELD_H */

