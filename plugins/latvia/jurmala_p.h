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

#ifndef STATIONS_SIMPLE_PRIVATE_JURMALA_H
#define STATIONS_SIMPLE_PRIVATE_JURMALA_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 41614, 0, "6702 Dzintari, Turaidas Iela", "", 56.9770789512, 23.8118577003 },
	{ 41613, 0, "6701 Majori", "", 56.9716935282, 23.7974756956 },
	{ 41615, 0, "6703 Bulduri, Vienības Prosp 1A", "", 56.985371915, 23.8545799255 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateJurmala : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateJurmala() {
    rect = QRectF(QPointF(55.973200, 22.822500), QPointF(57.973200, 24.822500));
    center = QPointF(56.973200, 23.822500);
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
      station->setRegion(QString("Jurmala %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_JURMALA_H */

