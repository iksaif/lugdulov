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
	{ 50400, 0, "Technologiepark", "", 51.49306, 7.40612 },
	{ 50398, 0, "Busbahnhof Huckarde", "", 51.5345656713, 7.41529136896 },
	{ 50396, 0, "Bhf Signal-Iduna-Park", "", 51.490743, 7.457327 },
	{ 50394, 0, "Westfalenpark", "", 51.4961086842, 7.47012028918 },
	{ 50393, 0, "Westfalenpark/Am Kaiserhain", "", 51.498563359, 7.47721284826 },
	{ 50392, 0, "Karl-Liebknecht-Straße", "", 51.4988451252, 7.48975136482 },
	{ 50389, 0, "Hohe Straße", "", 51.5052610324, 7.45991476264 },
	{ 50388, 0, "Stadthaus", "", 51.5082995735, 7.46852503675 },
	{ 50387, 0, "Platz Am Südwall", "", 51.5100377175, 7.46754378783 },
	{ 50386, 0, "Städtische Kliniken", "", 51.508994312, 7.45751332365 },
	{ 50385, 0, "Möllerbrücke", "", 51.507472108, 7.45124206846 },
	{ 50384, 0, "Platz Von Netanya", "", 51.5151153527, 7.46403334941 },
	{ 50382, 0, "Unionstraße", "", 51.5129562777, 7.44898182629 },
	{ 50383, 0, "Westentor", "", 51.5137785062, 7.4558941313 },
	{ 50381, 0, "Berswordthalle", "", 51.5111779647, 7.46693220257 },
	{ 50380, 0, "Stadtgarten", "", 51.5109744162, 7.46451995709 },
	{ 50379, 0, "Hiltropwall", "", 51.5103107749, 7.46223704786 },
	{ 50378, 0, "Volksbank", "", 51.5131180497, 7.46705218257 },
	{ 50376, 0, "Hansastraße", "", 51.5126230349, 7.46350681807 },
	{ 50377, 0, "Wißstraße", "", 51.5128352449, 7.46522793634 },
	{ 50375, 0, "Schwanenwall", "", 51.5140286465, 7.47257028453 },
	{ 50374, 0, "Brüderweg", "", 51.5148473838, 7.47251026242 },
	{ 50373, 0, "Freistuhl", "", 51.515364426, 7.46208201586 },
	{ 50372, 0, "Kuckelke", "", 51.5168306458, 7.46918854894 },
	{ 50371, 0, "Rwe Tower", "", 51.5167256849, 7.46176544829 },
	{ 50370, 0, "Hbf Gegenüber Hauptausgang", "", 51.5166054298, 7.45987425551 },
	{ 50369, 0, "Dortmunder U", "", 51.5148875797, 7.45489223443 },
	{ 50368, 0, "Cinestar", "", 51.5190837396, 7.46008321519 },
	{ 50367, 0, "Hbf Nordausgang", "", 51.5189787661, 7.45912893295 },
	{ 50366, 0, "Arbeitsamt", "", 51.5201872416, 7.4580869544 },
	{ 50365, 0, "Leopoldstraße", "", 51.5220625132, 7.45980390646 },
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

