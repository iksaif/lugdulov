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

#ifndef STATIONS_SIMPLE_PRIVATE_DUSSELDORF_H
#define STATIONS_SIMPLE_PRIVATE_DUSSELDORF_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1992, 0, "Spichernplatz", "", 51.247200, 6.783630 },
	{ 2001, 0, "Grafenberger Allee / Uhlandstr.", "", 51.230701, 6.800920 },
	{ 2003, 0, "Luegplatz", "", 51.231300, 6.761700 },
	{ 2008, 0, "Medienhafen / Hammerstr.", "", 51.213001, 6.751890 },
	{ 2009, 0, "Jugendherberge Djh / Düsseldorfer Str.", "", 51.226700, 6.758570 },
	{ 2011, 0, "Goethe Museum / Alt Pempelfort", "", 51.231400, 6.787280 },
	{ 2014, 0, "Technisches Rathaus / Aufm Hennekamp / Mecumstr.", "", 51.203800, 6.784400 },
	{ 2108, 0, "Fürstenplatz / Antoniusstr.", "", 51.213699, 6.786330 },
	{ 2288, 0, "Lorettostr. / Bürgerstr.", "", 51.213094, 6.764874 },
	{ 2353, 0, "Brehmstr. / Graf-Recke-Str.", "", 51.238465, 6.803155 },
	{ 2349, 0, "Rheinterrassen", "", 51.236500, 6.771520 },
	{ 2382, 0, "Zoo S / Franklinbrücke", "", 51.236198, 6.797500 },
	{ 2396, 0, "Corneliusstr. / Hüttenstr.", "", 51.217300, 6.782770 },
	{ 2680, 0, "Tonhallenstr.", "", 51.227004, 6.788006 },
	{ 3521, 0, "Graf-Adolf-Str. / Oststr.", "", 51.219002, 6.784230 },
	{ 2728, 0, "Arag Platz", "", 51.250198, 6.800880 },
	{ 2751, 0, "Heinrich-Heine-Platz", "", 51.225498, 6.776000 },
	{ 3002, 0, "Belsenplatz", "", 51.231300, 6.747480 },
	{ 3130, 0, "Burgplatz", "", 51.226898, 6.771640 },
	{ 3522, 0, "Rathausufer / Schulstraße", "", 51.224098, 6.769920 },
	{ 3598, 0, "Dreieck", "", 51.240398, 6.781910 },
	{ 4208, 0, "Hauptbahnhof Vorplatz", "", 51.220701, 6.792126 },
	{ 5920, 0, "Nordstraße U", "", 51.235294, 6.778049 },
	{ 7061, 0, "Bahnhof Bilk / Düsseldorf Arcaden / Elisabethstr", "", 51.208927, 6.776419 },
	{ 7744, 0, "Königsallee / Schadowstr.", "", 51.225353, 6.779232 },
	{ 8249, 0, "Fürstenwall / Talstr.", "", 51.213959, 6.778718 },
	{ 20725, 0, "Apollo Theater", "", 51.219707, 6.765904 },
	{ 51636, 0, "Plus-Energiehaus Inselstr.", "", 51.233406, 6.775778 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateDusseldorf : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateDusseldorf() {
    rect = QRectF(QPointF(50.224300, 5.772040), QPointF(52.224300, 7.772040));
    center = QPointF(51.224300, 6.772040);
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
      station->setRegion(QString("Dusseldorf %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_DUSSELDORF_H */

