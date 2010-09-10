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

#ifndef STATIONS_SIMPLE_PRIVATE_WIESELBURG_H
#define STATIONS_SIMPLE_PRIVATE_WIESELBURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 48304, 0, "Wieselburg / Freizeitzentrum", "", 48.134074, 15.146284 },
	{ 48303, 0, "Wieselburg / Bahnhof", "", 48.131608, 15.141508 },
	{ 48306, 0, "Petzenkirchen / Haubiversum", "", 48.144440, 15.150280 },
	{ 48309, 0, "Pöchlarn / Oskar Kokoschka Geburtshaus", "", 48.211670, 15.206670 },
	{ 48305, 0, "Wieselburg / Fachhochschule", "", 48.139170, 15.139170 },
	{ 48307, 0, "Pöchlarn / Bahnhof", "", 48.208410, 15.216959 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateWieselburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateWieselburg() {
    rect = QRectF(QPointF(47.190800, 14.316300), QPointF(49.190800, 16.316300));
    center = QPointF(48.190800, 15.316300);
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
      station->setRegion(QString("Wieselburg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_WIESELBURG_H */

