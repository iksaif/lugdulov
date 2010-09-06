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

#ifndef STATIONS_SIMPLE_PRIVATE_TULLN_H
#define STATIONS_SIMPLE_PRIVATE_TULLN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 43847, 0, "Tulln / Die Garten Tulln", "", 48.32892, 16.03773 },
	{ 43848, 0, "Tulln / Donaulände - Nibelungenplatz", "", 48.33297, 16.04987 },
	{ 43849, 0, "Tulln / Stadtbahnhof", "", 48.32872, 16.05382 },
	{ 43850, 0, "Tulln Bh / Marc Aurel Park", "", 48.3324, 16.05644 },
	{ 43851, 0, "Tulln / Hauptbahnhof", "", 48.3267, 16.06382 },
	{ 44615, 0, "Tulln / Hauptplatz - Rosenarcade", "", 48.33084, 16.05046 },
	{ 44612, 0, "Tulln / Campus Fachhochschule", "", 48.32048, 16.06404 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateTulln : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateTulln() {
    rect = QRectF(QPointF(48.126900, 15.856900), QPointF(48.526900, 16.256900));
    center = QPointF(48.326900, 16.056900);
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
      station->setRegion(QString("Tulln %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_TULLN_H */

