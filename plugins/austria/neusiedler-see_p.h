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
	{ 94, 0, "Purbach / Bhf", "", 47.9062004089, 16.698299408 },
	{ 522, 0, "Neusiedl / Bahnhof Bad", "", 47.9422505683, 16.8465042114 },
	{ 556, 0, "Neusiedl / Tourismuszentrale", "", 47.9485460189, 16.8436932564 },
	{ 568, 0, "Breitenbrunn / Bhf", "", 47.941337808, 16.7462646961 },
	{ 572, 0, "Mörbisch / Bootsverleih Drescher", "", 47.7546173235, 16.6972446442 },
	{ 584, 0, "Eisenstadt / Schloss", "", 47.8456783013, 16.5191459656 },
	{ 592, 0, "Rust / Hotel Am Greiner", "", 47.7978201096, 16.6735553741 },
	{ 744, 0, "Neusiedl / Post", "", 47.9457074118, 16.8479311466 },
	{ 781, 0, "Eisenstadt / Parkplatz Osterwiese", "", 47.8473019754, 16.5279436111 },
	{ 1431, 0, "Fertörakos / Drescher Line", "", 47.7162296241, 16.6854858398 },
	{ 1450, 0, "Podersdorf Am See / Gasthof Kummer", "", 47.8595696923, 16.8314087391 },
	{ 1451, 0, "Illmitz / Hotel Tauber Apetloner Str.", "", 47.7615558373, 16.8056327105 },
	{ 1452, 0, "Illmitz / Heuriger Gruber", "", 47.767116078, 16.8038678169 },
	{ 3401, 0, "Eisenstadt / Bahnhof", "", 47.888697486, 16.6603374481 },
	{ 3403, 0, "Eisenstadt / Domplatz", "", 47.8456458993, 16.525170207 },
	{ 6245, 0, "Neusiedl / Bezirkshauptmannschaft", "", 47.9515425565, 16.8361830711 },
	{ 11321, 0, "Purbach / Bad Im Erholungsgebiet", "", 47.9086618812, 16.7053985596 },
	{ 11322, 0, "Breitenbrunn / Hauptplatz", "", 47.9456355463, 16.7329287529 },
	{ 11323, 0, "Breitenbrunn / Seebad", "", 47.9168597627, 16.7645144463 },
	{ 19304, 0, "Illmitz / Seebad", "", 47.7543287998, 16.7419624329 },
	{ 40201, 0, "Frauenkirchen/Therme St. Martin", "", 47.8214539625, 16.9120788574 },
	{ 40236, 0, "Gols / Weinkulturhaus", "", 47.897010026, 16.9067573547 },
	{ 40237, 0, "Gols / Bahnhof", "", 47.8915428197, 16.9048690796 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateNeusiedler_See : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateNeusiedler_See() {
    rect = QRectF(QPointF(47.639000, 16.561000), QPointF(48.039000, 16.961000));
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

