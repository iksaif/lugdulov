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

#ifndef STATIONS_SIMPLE_PRIVATE_OFFENBURG_H
#define STATIONS_SIMPLE_PRIVATE_OFFENBURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 52511, 0, "Bahnhof/Zob", "", 48.475482, 7.945218 },
	{ 52513, 0, "Bahnhof-Osteingang", "", 48.475197, 7.947278 },
	{ 52514, 0, "Gustav-Rée-Anlage", "", 48.472125, 7.943823 },
	{ 52515, 0, "Stadtbuckel", "", 48.468639, 7.942686 },
	{ 52516, 0, "City Parkhaus", "", 48.471790, 7.939875 },
	{ 52517, 0, "Landratsamt/Medienpark", "", 48.465253, 7.939339 },
	{ 52518, 0, "Bürgerbürobauen/Tech.Rathaus", "", 48.470517, 7.947729 },
	{ 52519, 0, "Kulturforum", "", 48.467970, 7.954853 },
	{ 52520, 0, "Schillerplatz", "", 48.473490, 7.950110 },
	{ 52521, 0, "Ortenau Klinikum", "", 48.476876, 7.954638 },
	{ 52522, 0, "Edeka/Sparkasse", "", 48.480745, 7.957524 },
	{ 52523, 0, "Messe", "", 48.464932, 7.932443 },
	{ 52525, 0, "Zentrum Nordweststadt", "", 48.479806, 7.941785 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateOffenburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateOffenburg() {
    rect = QRectF(QPointF(47.468000, 6.942390), QPointF(49.468000, 8.942390));
    center = QPointF(48.468000, 7.942390);
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
      station->setRegion(QString("Offenburg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_OFFENBURG_H */

