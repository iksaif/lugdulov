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

#ifndef STATIONS_SIMPLE_PRIVATE_NEUSIEDLER_SEE_H
#define STATIONS_SIMPLE_PRIVATE_NEUSIEDLER_SEE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 94, 0, "Purbach / Bhf", "", 47.906200, 16.698299 },
	{ 522, 0, "Neusiedl / Bahnhof Bad", "", 47.942251, 16.846504 },
	{ 556, 0, "Neusiedl / Tourismuszentrale", "", 47.948546, 16.843693 },
	{ 568, 0, "Breitenbrunn / Bhf", "", 47.941338, 16.746265 },
	{ 572, 0, "Mörbisch / Bootsverleih Drescher", "", 47.754617, 16.697245 },
	{ 584, 0, "Eisenstadt / Schloss", "", 47.845678, 16.519146 },
	{ 592, 0, "Rust / Hotel Am Greiner", "", 47.797820, 16.673555 },
	{ 744, 0, "Neusiedl / Post", "", 47.945707, 16.847931 },
	{ 781, 0, "Eisenstadt / Parkplatz Osterwiese", "", 47.847302, 16.527944 },
	{ 1431, 0, "Fertörakos / Drescher Line", "", 47.716230, 16.685486 },
	{ 1450, 0, "Podersdorf Am See / Gasthof Kummer", "", 47.859570, 16.831409 },
	{ 1451, 0, "Illmitz / Hotel Tauber Apetloner Str.", "", 47.761556, 16.805633 },
	{ 1452, 0, "Illmitz / Heuriger Gruber", "", 47.767116, 16.803868 },
	{ 3401, 0, "Eisenstadt / Bahnhof", "", 47.888697, 16.660337 },
	{ 3403, 0, "Eisenstadt / Domplatz", "", 47.845646, 16.525170 },
	{ 6245, 0, "Neusiedl / Bezirkshauptmannschaft", "", 47.951543, 16.836183 },
	{ 11321, 0, "Purbach / Bad Im Erholungsgebiet", "", 47.908662, 16.705399 },
	{ 11322, 0, "Breitenbrunn / Hauptplatz", "", 47.945636, 16.732929 },
	{ 11323, 0, "Breitenbrunn / Seebad", "", 47.916860, 16.764514 },
	{ 19304, 0, "Illmitz / Seebad", "", 47.754329, 16.741962 },
	{ 40201, 0, "Frauenkirchen/Therme St. Martin", "", 47.821454, 16.912079 },
	{ 40236, 0, "Gols / Weinkulturhaus", "", 47.897010, 16.906757 },
	{ 40237, 0, "Gols / Bahnhof", "", 47.891543, 16.904869 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateNeusiedler_See : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateNeusiedler_See() {
    rect = QRectF(QPointF(46.839000, 15.761000), QPointF(48.839000, 17.761000));
    center = QPointF(47.839000, 16.761000);
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
      station->setRegion(QString("Neusiedler_See %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_NEUSIEDLER_SEE_H */

