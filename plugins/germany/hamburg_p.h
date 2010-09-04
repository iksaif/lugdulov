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

#ifndef STATIONS_SIMPLE_PRIVATE_HAMBURG_H
#define STATIONS_SIMPLE_PRIVATE_HAMBURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1418, 0, "Europa Passage / Reesendamm / Jungfernstieg", "", 53.5519981384, 9.9939699173 },
	{ 1420, 0, "Neuer Jungfernstieg", "", 53.5564994812, 9.99252986908 },
	{ 1422, 0, "Bahnhof Dammtor/ Dag Hammarskjoeld Bruecke", "", 53.5606919298, 9.98929738998 },
	{ 1429, 0, "Mönckebergstr.", "", 53.5512008667, 10.0010995865 },
	{ 4291, 0, "A&O Hostel Amsinckstraße", "", 53.5477025428, 10.0111305714 },
	{ 4691, 0, "Glockengießerwall", "", 53.5536994934, 10.0036001205 },
	{ 4897, 0, "U- Bahn Hallerstraße", "", 53.5727996826, 9.98892974854 },
	{ 8246, 0, "Golden Tulip Finkenwerder", "", 53.540103369, 9.86203193665 },
	{ 14294, 0, "St. Pauli Jugendherberge Stintfang", "", 53.5468610907, 9.97159481049 },
	{ 13713, 0, "Mittelweg Ecke Milchstraße", "", 53.5707212397, 9.99476909637 },
	{ 13715, 0, "Hafen City Marco Polo Terassen", "", 53.5422838084, 9.99324560165 },
	{ 13717, 0, "Jungfernstieg", "", 53.5547904749, 9.9897480011 },
	{ 18404, 0, "Eppendorf Marie-Jonas-Platz", "", 53.5905371057, 9.98702287674 },
	{ 18411, 0, "Haltestelle St. Michaelis Ludwig-Erhard-Straße", "", 53.5490794283, 9.97837543488 },
	{ 19314, 0, "Mittelweg Ecke Hallerstraße", "", 53.5728873603, 9.99361038208 },
	{ 19315, 0, "U-Bahn Station Hudtwalckerstraße/ Bebelallee", "", 53.5945169934, 9.99562740326 },
	{ 25147, 0, "Mühlenkamp/ Ecke Gertigstraße", "", 53.5813469093, 10.0118923187 },
	{ 27352, 0, "U-Bahn Station Mundsburg", "", 53.5701733211, 10.0273633003 },
	{ 28133, 0, "Dammtor /  Rothenbaumchausee", "", 53.5615585968, 9.99019861221 },
	{ 42495, 0, "Kennedybrücke", "", 53.5577731706, 9.99788045883 },
	{ 44524, 0, "Ballindamm Ecke Lombardsbrücke", "", 53.5555043016, 9.99994039536 },
	{ 48334, 0, "Preystraße / Mühlenkamp", "", 53.5818564666, 10.0114202499 },
	{ 55206, 0, "Alsterufer/ Ecke Alte Rabenstraße", "", 53.5674463644, 10.0010669231 },
	{ 55210, 0, "Alsterufer/Ecke Alsterterassen", "", 53.5592007112, 9.99579906464 },
	{ 55215, 0, "Alsterufer Gegenüber Cliff Restaurant", "", 53.5736773296, 10.0022578239 },
	{ 55217, 0, "Fernsicht/ Ecke Agnesstraße", "", 53.5805061262, 10.0003910065 },
	{ 55219, 0, "An Der Alster/ Schwanenwik Brücke", "", 53.5632281553, 10.0155508518 },
	{ 58577, 0, "Kampnagel Kulturfabrik Jarrestraße 20", "", 53.5837927284, 10.0211405754 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateHamburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateHamburg() {
    rect = QRectF(QPointF(53.350600, 9.790520), QPointF(53.750600, 10.190520));
    center = QPointF(53.550600, 9.990520);
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
      station->setRegion(QString("Hamburg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_HAMBURG_H */

