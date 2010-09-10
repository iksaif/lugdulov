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

#ifndef STATIONS_SIMPLE_PRIVATE_BOTTROP_H
#define STATIONS_SIMPLE_PRIVATE_BOTTROP_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50364, 0, "Fuhlenbrock Markt", "", 51.531778, 6.891634 },
	{ 50363, 0, "Boyer Markt", "", 51.536802, 6.972085 },
	{ 50362, 0, "Tetraeder", "", 51.525366, 6.953772 },
	{ 50361, 0, "Josef Albers Museum / Stadtgarten", "", 51.531376, 6.919296 },
	{ 50360, 0, "Marienhospital", "", 51.533318, 6.916871 },
	{ 50359, 0, "Eigen Markt", "", 51.547648, 6.937053 },
	{ 50358, 0, "Pendlerparkplatz A 42", "", 51.504101, 6.935742 },
	{ 50357, 0, "Berufsschule", "", 51.528873, 6.929001 },
	{ 50356, 0, "Gladbecker Straße", "", 51.524286, 6.928144 },
	{ 50355, 0, "Untere Hochstraße", "", 51.519036, 6.925948 },
	{ 50354, 0, "Ernst-Wilczok-Platz", "", 51.524132, 6.924856 },
	{ 50353, 0, "Kulturzentrum", "", 51.523592, 6.922727 },
	{ 50352, 0, "Knappschaftskrankenhaus", "", 51.515308, 6.908542 },
	{ 50351, 0, "Berliner Platz", "", 51.523042, 6.926375 },
	{ 50349, 0, "Hauptbahnhof", "", 51.509964, 6.936481 },
	{ 50350, 0, "Pferdemarkt", "", 51.522083, 6.923690 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBottrop : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBottrop() {
    rect = QRectF(QPointF(50.526300, 5.946110), QPointF(52.526300, 7.946110));
    center = QPointF(51.526300, 6.946110);
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
      station->setRegion(QString("Bottrop %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_BOTTROP_H */

