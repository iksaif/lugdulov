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

#ifndef STATIONS_SIMPLE_PRIVATE_ESSEN_H
#define STATIONS_SIMPLE_PRIVATE_ESSEN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50433, 0, "Werden Folkwang", "", 51.387606, 7.003511 },
	{ 50431, 0, "Kettwig-Bf", "", 51.363685, 6.953149 },
	{ 50432, 0, "Werden Bf.", "", 51.386582, 6.998130 },
	{ 50430, 0, "Kettwig-Ruhrufer", "", 51.361387, 6.937236 },
	{ 50429, 0, "Bm-Fiedler-Platz", "", 51.363083, 6.938635 },
	{ 50428, 0, "Uniklinikum", "", 51.436230, 6.990253 },
	{ 50427, 0, "Gemarkenplatz", "", 51.441638, 6.996986 },
	{ 50426, 0, "Messe/Gruga", "", 51.430413, 6.998899 },
	{ 50425, 0, "Rüttenscheider Stern", "", 51.438247, 7.005599 },
	{ 50423, 0, "Philharmonie", "", 51.445363, 7.009165 },
	{ 50424, 0, "Grillo Theater", "", 51.454423, 7.011292 },
	{ 50422, 0, "Viehofer Platz", "", 51.461361, 7.013503 },
	{ 50421, 0, "Kopstadtplatz", "", 51.458369, 7.011221 },
	{ 50420, 0, "Rathaus/ Porscheplatte", "", 51.457864, 7.016706 },
	{ 50419, 0, "Berliner Platz", "", 51.458744, 7.004194 },
	{ 50444, 0, "Hbf. Nord", "", 51.452167, 7.014379 },
	{ 50445, 0, "Hbf. Süd", "", 51.450575, 7.012387 },
	{ 50446, 0, "Helbingstr. / Rvr / Emschergen.", "", 51.446511, 7.019849 },
	{ 50434, 0, "Werden Mitte", "", 51.388522, 7.003560 },
	{ 50435, 0, "Regattaturm", "", 51.403215, 7.007129 },
	{ 50436, 0, "Kupferdreh Bf", "", 51.390671, 7.081261 },
	{ 50443, 0, "Bf. Süd", "", 51.439450, 7.023503 },
	{ 50437, 0, "Alte Margarethenhöhe", "", 51.426655, 6.975495 },
	{ 50438, 0, "Universität", "", 51.463641, 7.009654 },
	{ 50439, 0, "Bf. Steele", "", 51.450100, 7.075760 },
	{ 50440, 0, "Zollverein", "", 51.484321, 7.042863 },
	{ 50441, 0, "Zollverein Bf.", "", 51.492997, 7.045668 },
	{ 50442, 0, "Handwerker Park", "", 51.489097, 7.063461 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateEssen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateEssen() {
    rect = QRectF(QPointF(50.442500, 6.023010), QPointF(52.442500, 8.023010));
    center = QPointF(51.442500, 7.023010);
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
      station->setRegion(QString("Essen %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_ESSEN_H */

