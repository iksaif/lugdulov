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
	{ 50433, 0, "Werden Folkwang", "", 51.3876055003, 7.00351094456 },
	{ 50431, 0, "Kettwig-Bf", "", 51.363685008, 6.95314909922 },
	{ 50432, 0, "Werden Bf.", "", 51.3865818392, 6.99813011157 },
	{ 50430, 0, "Kettwig-Ruhrufer", "", 51.361386546, 6.9372359681 },
	{ 50429, 0, "Bm-Fiedler-Platz", "", 51.3630831854, 6.93863466807 },
	{ 50428, 0, "Uniklinikum", "", 51.4362299265, 6.99025306395 },
	{ 50427, 0, "Gemarkenplatz", "", 51.4416378712, 6.99698629304 },
	{ 50426, 0, "Messe/Gruga", "", 51.4304128147, 6.99889869561 },
	{ 50425, 0, "Rüttenscheider Stern", "", 51.4382474687, 7.00559912326 },
	{ 50423, 0, "Philharmonie", "", 51.4453627313, 7.00916457594 },
	{ 50424, 0, "Grillo Theater", "", 51.4544228408, 7.01129235517 },
	{ 50422, 0, "Viehofer Platz", "", 51.4613608811, 7.0135034691 },
	{ 50421, 0, "Kopstadtplatz", "", 51.4583694324, 7.01122136601 },
	{ 50420, 0, "Rathaus/ Porscheplatte", "", 51.4578635472, 7.01670644601 },
	{ 50419, 0, "Berliner Platz", "", 51.4587444745, 7.00419372981 },
	{ 50444, 0, "Hbf. Nord", "", 51.4521669951, 7.01437869689 },
	{ 50445, 0, "Hbf. Süd", "", 51.4505752691, 7.01238692115 },
	{ 50446, 0, "Helbingstr. / Rvr / Emschergen.", "", 51.4465106337, 7.01984886244 },
	{ 50434, 0, "Werden Mitte", "", 51.3885219254, 7.0035597389 },
	{ 50435, 0, "Regattaturm", "", 51.4032146872, 7.00712937353 },
	{ 50436, 0, "Kupferdreh Bf", "", 51.3906706762, 7.08126081119 },
	{ 50443, 0, "Bf. Süd", "", 51.4394496915, 7.02350280212 },
	{ 50437, 0, "Alte Margarethenhöhe", "", 51.426655076, 6.97549508988 },
	{ 50438, 0, "Universität", "", 51.4636412506, 7.00965434535 },
	{ 50439, 0, "Bf. Steele", "", 51.4501004039, 7.07575991041 },
	{ 50440, 0, "Zollverein", "", 51.4843206873, 7.04286329762 },
	{ 50441, 0, "Zollverein Bf.", "", 51.492996601, 7.04566765928 },
	{ 50442, 0, "Handwerker Park", "", 51.4890972661, 7.06346071364 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateEssen : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateEssen() {
    rect = QRectF(QPointF(51.242500, 6.823010), QPointF(51.642500, 7.223010));
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

