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

#ifndef STATIONS_SIMPLE_PRIVATE_DORTMUND_H
#define STATIONS_SIMPLE_PRIVATE_DORTMUND_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50400, 0, "Technologiepark", "", 51.493060, 7.406120 },
	{ 50398, 0, "Busbahnhof Huckarde", "", 51.534566, 7.415291 },
	{ 50396, 0, "Bhf Signal-Iduna-Park", "", 51.490743, 7.457327 },
	{ 50394, 0, "Westfalenpark", "", 51.496109, 7.470120 },
	{ 50393, 0, "Westfalenpark/Am Kaiserhain", "", 51.498563, 7.477213 },
	{ 50392, 0, "Karl-Liebknecht-Straße", "", 51.498845, 7.489751 },
	{ 50389, 0, "Hohe Straße", "", 51.505261, 7.459915 },
	{ 50388, 0, "Stadthaus", "", 51.508300, 7.468525 },
	{ 50387, 0, "Platz Am Südwall", "", 51.510038, 7.467544 },
	{ 50386, 0, "Städtische Kliniken", "", 51.508994, 7.457513 },
	{ 50385, 0, "Möllerbrücke", "", 51.507472, 7.451242 },
	{ 50384, 0, "Platz Von Netanya", "", 51.515115, 7.464033 },
	{ 50382, 0, "Unionstraße", "", 51.512956, 7.448982 },
	{ 50383, 0, "Westentor", "", 51.513779, 7.455894 },
	{ 50381, 0, "Berswordthalle", "", 51.511178, 7.466932 },
	{ 50380, 0, "Stadtgarten", "", 51.510974, 7.464520 },
	{ 50379, 0, "Hiltropwall", "", 51.510311, 7.462237 },
	{ 50378, 0, "Volksbank", "", 51.513118, 7.467052 },
	{ 50376, 0, "Hansastraße", "", 51.512623, 7.463507 },
	{ 50377, 0, "Wißstraße", "", 51.512835, 7.465228 },
	{ 50375, 0, "Schwanenwall", "", 51.514029, 7.472570 },
	{ 50374, 0, "Brüderweg", "", 51.514847, 7.472510 },
	{ 50373, 0, "Freistuhl", "", 51.515364, 7.462082 },
	{ 50372, 0, "Kuckelke", "", 51.516831, 7.469189 },
	{ 50371, 0, "Rwe Tower", "", 51.516726, 7.461765 },
	{ 50370, 0, "Hbf Gegenüber Hauptausgang", "", 51.516605, 7.459874 },
	{ 50369, 0, "Dortmunder U", "", 51.514888, 7.454892 },
	{ 50368, 0, "Cinestar", "", 51.519084, 7.460083 },
	{ 50367, 0, "Hbf Nordausgang", "", 51.518979, 7.459129 },
	{ 50366, 0, "Arbeitsamt", "", 51.520187, 7.458087 },
	{ 50365, 0, "Leopoldstraße", "", 51.522063, 7.459804 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateDortmund : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateDortmund() {
    rect = QRectF(QPointF(50.514100, 6.462550), QPointF(52.514100, 8.462550));
    center = QPointF(51.514100, 7.462550);
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
      station->setRegion(QString("Dortmund %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_DORTMUND_H */

