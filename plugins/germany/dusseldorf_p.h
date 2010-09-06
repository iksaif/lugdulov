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
	{ 1992, 0, "Spichernplatz", "", 51.2472000122, 6.78362989426 },
	{ 2001, 0, "Grafenberger Allee / Uhlandstr.", "", 51.2307014465, 6.80092000961 },
	{ 2003, 0, "Luegplatz", "", 51.231300354, 6.76170015335 },
	{ 2008, 0, "Medienhafen / Hammerstr.", "", 51.2130012512, 6.7518901825 },
	{ 2009, 0, "Jugendherberge Djh / Düsseldorfer Str.", "", 51.2266998291, 6.75857019424 },
	{ 2011, 0, "Goethe Museum / Alt Pempelfort", "", 51.2313995361, 6.7872800827 },
	{ 2014, 0, "Technisches Rathaus / Aufm Hennekamp / Mecumstr.", "", 51.2038002014, 6.78439998627 },
	{ 2108, 0, "Fürstenplatz / Antoniusstr.", "", 51.2136993408, 6.78633022308 },
	{ 2288, 0, "Lorettostr. / Bürgerstr.", "", 51.21309385, 6.76487445831 },
	{ 2353, 0, "Brehmstr. / Graf-Recke-Str.", "", 51.2384646679, 6.80315494537 },
	{ 2349, 0, "Rheinterrassen", "", 51.2364997864, 6.77152013779 },
	{ 2382, 0, "Zoo S / Franklinbrücke", "", 51.2361984253, 6.79750013351 },
	{ 2396, 0, "Corneliusstr. / Hüttenstr.", "", 51.217300415, 6.78277015686 },
	{ 2680, 0, "Tonhallenstr.", "", 51.2270038428, 6.78800582886 },
	{ 3521, 0, "Graf-Adolf-Str. / Oststr.", "", 51.21900177, 6.78423023224 },
	{ 2728, 0, "Arag Platz", "", 51.2501983643, 6.80087995529 },
	{ 2751, 0, "Heinrich-Heine-Platz", "", 51.2254981995, 6.77600002289 },
	{ 3002, 0, "Belsenplatz", "", 51.231300354, 6.74747991562 },
	{ 3130, 0, "Burgplatz", "", 51.2268981934, 6.77163982391 },
	{ 3522, 0, "Rathausufer / Schulstraße", "", 51.2240982056, 6.76991987228 },
	{ 3598, 0, "Dreieck", "", 51.240398407, 6.78190994263 },
	{ 4208, 0, "Hauptbahnhof Vorplatz", "", 51.2207011881, 6.7921257019 },
	{ 5920, 0, "Nordstraße U", "", 51.2352940804, 6.77804946899 },
	{ 7061, 0, "Bahnhof Bilk / Düsseldorf Arcaden / Elisabethstr", "", 51.2089267539, 6.77641868591 },
	{ 7744, 0, "Königsallee / Schadowstr.", "", 51.225352671, 6.77923232317 },
	{ 8249, 0, "Fürstenwall / Talstr.", "", 51.2139586, 6.7787178 },
	{ 20725, 0, "Apollo Theater", "", 51.2197066605, 6.76590442657 },
	{ 51636, 0, "Plus-Energiehaus Inselstr.", "", 51.2334062, 6.7757783 },
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

