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

#ifndef STATIONS_SIMPLE_PRIVATE_POTSDAM_H
#define STATIONS_SIMPLE_PRIVATE_POTSDAM_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 57741, 0, "Volkspark Süd", "", 52.415862, 13.041211 },
	{ 57730, 0, "Bahnhof Golm", "", 52.409010, 12.972434 },
	{ 57747, 0, "Jägertor/ Lindenstraße", "", 52.402118, 13.052423 },
	{ 57748, 0, "Brandenburger Str./ Lindenstr.", "", 52.399820, 13.051865 },
	{ 57749, 0, "Dortusstr./ Charlottenstraße", "", 52.399205, 13.052949 },
	{ 57751, 0, "Stadthaus Potsdam", "", 52.405747, 13.058125 },
	{ 57755, 0, "Schiffbauergasse", "", 52.403807, 13.075147 },
	{ 57758, 0, "Rathaus Babelsberg", "", 52.392246, 13.091723 },
	{ 57759, 0, "Kopernikusstraße", "", 52.389168, 13.099952 },
	{ 57763, 0, "Bahnhof Griebnitzsee", "", 52.393981, 13.129005 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivatePotsdam : StationsPluginSimplePrivate {
  StationsPluginSimplePrivatePotsdam() {
    rect = QRectF(QPointF(51.399700, 12.067600), QPointF(53.399700, 14.067600));
    center = QPointF(52.399700, 13.067600);
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
      station->setRegion(QString("Potsdam %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_POTSDAM_H */

