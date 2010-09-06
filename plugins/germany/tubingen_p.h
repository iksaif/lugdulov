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

#ifndef STATIONS_SIMPLE_PRIVATE_TUBINGEN_H
#define STATIONS_SIMPLE_PRIVATE_TUBINGEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 27497, 0, "Nr.1 / Eberhardsbrücke / Tourismusinformation", "", 48.5185942174, 9.05807733536 },
	{ 27498, 0, "Nr.2 / Europaplatz / Hauptbahnhof", "", 48.5170200957, 9.05694007874 },
	{ 27506, 0, "Nr. 4 / Schnarrenbergstraße / Parkhaus König", "", 48.5235045942, 9.05180096626 },
	{ 27507, 0, "Nr.6/ Silcherstraße / Universität / Alter Botanischer Garten", "", 48.5243359712, 9.05851185322 },
	{ 27508, 0, "Nr.5 / Nauklerstraße / Universität", "", 48.5252170739, 9.05962228775 },
	{ 28183, 0, "Nr.3 / Österbergstraße / Lustnauertor", "", 48.5214509634, 9.05776619911 },
	{ 28185, 0, "Nr. 8/ Haagtorplatz", "", 48.5206301984, 9.04974102974 },
	{ 28192, 0, "Rappenberghalde / Campingplatz", "", 48.5109764, 9.0354792 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateTubingen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateTubingen() {
    rect = QRectF(QPointF(47.520300, 8.055910), QPointF(49.520300, 10.055910));
    center = QPointF(48.520300, 9.055910);
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
      station->setRegion(QString("Tubingen %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_TUBINGEN_H */

