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

#ifndef STATIONS_SIMPLE_PRIVATE_DUISBURG_H
#define STATIONS_SIMPLE_PRIVATE_DUISBURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50418, 0, "Haltestelle Landschaftspark", "", 51.479816, 6.792950 },
	{ 50417, 0, "Landschaftspark", "", 51.480481, 6.783605 },
	{ 50416, 0, "Bahnhof Meiderich", "", 51.467600, 6.779556 },
	{ 50415, 0, "Yitzhak-Rabin-Platz", "", 51.438397, 6.764490 },
	{ 50414, 0, "Verknüpfungshalle West", "", 51.431550, 6.775088 },
	{ 50412, 0, "Steinsche Gasse", "", 51.434113, 6.762693 },
	{ 50411, 0, "Stadttheater", "", 51.434113, 6.770889 },
	{ 50409, 0, "Rathaus", "", 51.435224, 6.761748 },
	{ 50410, 0, "Schwanentor", "", 51.435869, 6.758005 },
	{ 50408, 0, "Museum Küppersmühle  Holzgracht", "", 51.440777, 6.773001 },
	{ 50407, 0, "Lehmbruckmuseum", "", 51.430949, 6.765458 },
	{ 50406, 0, "Lego Discovery", "", 51.440616, 6.770151 },
	{ 50405, 0, "Kuhtor", "", 51.433709, 6.763908 },
	{ 50404, 0, "Hauptbahnhof  Ost", "", 51.429532, 6.777182 },
	{ 50403, 0, "Hauptbahnhof  Haupteingang", "", 51.430414, 6.772941 },
	{ 50402, 0, "Forum", "", 51.433410, 6.768462 },
	{ 50401, 0, "Dellplatz", "", 51.430234, 6.761938 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateDuisburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateDuisburg() {
    rect = QRectF(QPointF(50.448700, 5.775130), QPointF(52.448700, 7.775130));
    center = QPointF(51.448700, 6.775130);
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
      station->setRegion(QString("Duisburg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_DUISBURG_H */

