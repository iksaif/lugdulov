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

#ifndef STATIONS_SIMPLE_PRIVATE_RIGA_H
#define STATIONS_SIMPLE_PRIVATE_RIGA_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 39945, 0, "6706 Origo, Centrala Stacija", "", 56.9477128077, 24.1206228733 },
	{ 40599, 0, "6704 Hotel Islande", "", 56.950895916, 24.0847885609 },
	{ 40600, 0, "6710 Radisson Blu Hotel Latvia", "", 56.9546169995, 24.117924571 },
	{ 40601, 0, "6709 Hotel De Rome", "", 56.9503166574, 24.1116642952 },
	{ 40602, 0, "6707 Ratslaukums", "", 56.9475372607, 24.1061282158 },
	{ 40604, 0, "6711 Pulkveza Brieza", "", 56.9586477542, 24.1058492661 },
	{ 45886, 0, "6708 Galerija Centrs, Vecrīga", "", 56.9483915815, 24.1128659248 },
	{ 45887, 0, "6705 Radisson Blu Daugava", "", 56.944084669, 24.0941762924 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateRiga : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateRiga() {
    rect = QRectF(QPointF(55.950500, 23.103300), QPointF(57.950500, 25.103300));
    center = QPointF(56.950500, 24.103300);
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
      station->setRegion(QString("Riga %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_RIGA_H */

