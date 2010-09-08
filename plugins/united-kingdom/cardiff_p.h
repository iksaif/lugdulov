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

#ifndef STATIONS_SIMPLE_PRIVATE_CARDIFF_H
#define STATIONS_SIMPLE_PRIVATE_CARDIFF_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 2, 0, "County Hall", "", 51.469304, -3.162300 },
	{ 4, 0, "Cardiff Bay Train Station", "", 51.467242, -3.166198 },
	{ 5, 0, "Queen St (Capitol Centre)", "", 51.483003, -3.171600 },
	{ 6, 0, "Churchill Way", "", 51.482637, -3.173694 },
	{ 7, 0, "City Hall", "", 51.484536, -3.179061 },
	{ 8, 0, "Queen St (Castle End)", "", 51.481650, -3.178788 },
	{ 11, 0, "Central Station - Front", "", 51.476069, -3.178734 },
	{ 12, 0, "Central Station - Rear", "", 51.475082, -3.178552 },
	{ 20, 0, "Cardiff International White Water", "", 51.448598, -3.181669 },
	{ 21, 0, "Roath Community Centre", "", 51.496611, -3.164851 },
	{ 22, 0, "Cathedral Road", "", 51.489305, -3.202863 },
	{ 23, 0, "Bute Street (Mermaid Quay)", "", 51.464873, -3.165876 },
	{ 24, 0, "Llandaff Train Station", "", 51.507435, -3.228250 },
	{ 25, 0, "Cardiff National Museum", "", 51.485705, -3.176590 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateCardiff : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateCardiff() {
    rect = QRectF(QPointF(51.281307, -3.380498), QPointF(51.681307, -2.980498));
    center = QPointF(51.481307, -3.180498);
    statusUrl = "";
    infosUrl = "http://www.vel-in.fr/oybike/stands.nsf/getSite?openagent&site=cardiff&format=json&key=D";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Cardiff %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_CARDIFF_H */

