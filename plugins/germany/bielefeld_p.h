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
	{ 42241, 0, "Hauptbahnhof", "", 52.028755968, 8.53312075138 },
	{ 42243, 0, "Turmstraße 10 / Puddingtown-Bikes", "", 52.0301322735, 8.5244679451 },
	{ 42244, 0, "Jahnplatz S-Bahn-Hst", "", 52.0229829448, 8.53271842003 },
	{ 42245, 0, "Alex Am Theater", "", 52.0205467629, 8.53427410126 },
	{ 42433, 0, "Niederwall 10 / Galerie Samuelis Baumgarte E.K.", "", 52.0216262257, 8.5341668129 },
	{ 42452, 0, "Stresemannstraße Hst", "", 52.0248314496, 8.53425264359 },
	{ 47357, 0, "Niedernstraße (Neue Westfälische)", "", 52.0221048783, 8.53180646896 },
	{ 61803, 0, "Bunnemannplatz (Mercur Hotel)", "", 52.0192262837, 8.5297036171 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBielefeld : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBielefeld() {
    rect = QRectF(QPointF(51.825700, 8.332860), QPointF(52.225700, 8.732860));
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

