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

#ifndef STATIONS_SIMPLE_PRIVATE_WACHAU_H
#define STATIONS_SIMPLE_PRIVATE_WACHAU_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 42835, 0, "Krems / Bahnhof", "", 48.408796, 15.603609 },
	{ 42839, 0, "Krems / Südtiroler Platz", "", 48.409238, 15.595916 },
	{ 42840, 0, "Krems / Landstraße", "", 48.410571, 15.598589 },
	{ 42837, 0, "Krems / Nachtwächter Kreisverkehr", "", 48.412799, 15.605642 },
	{ 42841, 0, "Krems / Strandbad", "", 48.405303, 15.598526 },
	{ 42842, 0, "Stein / Donaustation Brandner 24", "", 48.402746, 15.588165 },
	{ 42843, 0, "Stein / Kunstmeile Krems", "", 48.404616, 15.587300 },
	{ 42844, 0, "Krems / Landesklinikum", "", 48.412625, 15.613332 },
	{ 42845, 0, "Stein / Campus Donau Uni Krems", "", 48.407290, 15.585197 },
	{ 42846, 0, "Krems / Arte Hotel", "", 48.407416, 15.584922 },
	{ 42847, 0, "Mautern A. D. Donau Römerhalle / Tourismus Information", "", 48.395208, 15.575838 },
	{ 42851, 0, "Dürnstein / Donaustation 21 - Busparkplatz", "", 48.388762, 15.523692 },
	{ 42853, 0, "Dürnstein / Donaustation Brandner 20", "", 48.395048, 15.518728 },
	{ 42854, 0, "Dürnstein / P2 Bhf", "", 48.393016, 15.524965 },
	{ 42855, 0, "Unterloiben / Zentrum", "", 48.386877, 15.540675 },
	{ 42856, 0, "Hofarnsdorf / Feuerwehr", "", 48.363152, 15.428070 },
	{ 42857, 0, "Rossatz / Camping - Fähre", "", 48.391197, 15.516354 },
	{ 42858, 0, "Weißenkirchen / Rollfährestraße", "", 48.395205, 15.471700 },
	{ 42859, 0, "Weißenkirchen / Bahnhof", "", 48.398861, 15.473336 },
	{ 42860, 0, "Spitz / Donaustation Brandner 15 - Tourismusinfo", "", 48.362572, 15.417770 },
	{ 42861, 0, "Spitz / Bahnhof", "", 48.365186, 15.417432 },
	{ 42862, 0, "Mühldorf / Elsarn, Bei Kapelle", "", 48.364575, 15.358554 },
	{ 42863, 0, "Mühldorf / Feuerwehr", "", 48.373246, 15.344930 },
	{ 42864, 0, "Aggsbach / Freizeitzentrum", "", 48.297927, 15.404631 },
	{ 42865, 0, "Aggsbach / Parkplatz - Info", "", 48.291535, 15.407051 },
	{ 42866, 0, "Schönbühel / Amtshaus", "", 48.294172, 15.415547 },
	{ 42867, 0, "Emmersdorf / Tourismusinfo", "", 48.244160, 15.341316 },
	{ 42868, 0, "Emmersdorf / Zentrum - Hotel Donauhof", "", 48.241844, 15.338113 },
	{ 42869, 0, "Melk / Bahnhof", "", 48.224612, 15.332422 },
	{ 42870, 0, "Melk / Parkplatz - Tourismusinfo", "", 48.226639, 15.333866 },
	{ 42871, 0, "Melk / Gasthof Fährhaus - Camping", "", 48.233619, 15.328674 },
	{ 42872, 0, "Melk / Radraststation", "", 48.228055, 15.327437 },
	{ 42873, 0, "Melk / Wachaubad, Fürnbergstraße", "", 48.225244, 15.347739 },
	{ 42874, 0, "Melk / Donaustation Brandner 10", "", 48.234007, 15.330498 },
	{ 42875, 0, "Melk / Konditorei Mistlbacher - Fußgängerzone", "", 48.227383, 15.329047 },
	{ 42882, 0, "Melk / Jugendherberge", "", 48.224242, 15.339842 },
	{ 44630, 0, "Melk / Bh, Abt Karlstraße", "", 48.224701, 15.338845 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateWachau : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateWachau() {
    rect = QRectF(QPointF(47.318800, 14.416600), QPointF(49.318800, 16.416600));
    center = QPointF(48.318800, 15.416600);
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
      station->setRegion(QString("Wachau %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_WACHAU_H */

