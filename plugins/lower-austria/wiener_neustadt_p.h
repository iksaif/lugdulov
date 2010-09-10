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

#ifndef STATIONS_SIMPLE_PRIVATE_WIENER_NEUSTADT_H
#define STATIONS_SIMPLE_PRIVATE_WIENER_NEUSTADT_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 54635, 0, "Wr. Neustadt / Hauptbahnhof", "", 47.811944, 16.234167 },
	{ 54636, 0, "Wr. Neustadt / Hst.Civitas Nova", "", 47.833889, 16.255833 },
	{ 54637, 0, "Wr. Neustadt / Hst. Nord", "", 47.834167, 16.238333 },
	{ 54638, 0, "Wr. Neustadt / Volksbad", "", 47.800556, 16.237500 },
	{ 54639, 0, "Wr. Neustadt / Aqua Nova / Graf Von Zeppelin Str.12", "", 47.841160, 16.259487 },
	{ 54640, 0, "Wr. Neustadt / Studentenwohnheim", "", 47.837778, 16.255000 },
	{ 54641, 0, "Wr. Neustadt / Fh", "", 47.838889, 16.248611 },
	{ 54642, 0, "Wr. Neustadt / Neunkirchnerstrasse", "", 47.809722, 16.243611 },
	{ 54643, 0, "Wr. Neustadt / Hauptplatz", "", 47.813333, 16.243611 },
	{ 54644, 0, "Wr. Neustadt / Siedlung Anemonensee", "", 47.811111, 16.208611 },
	{ 54645, 0, "Wr. Neustadt / Fischapark Dreipappelstrasse", "", 47.818181, 16.217431 },
	{ 54646, 0, "Wr. Neustadt / Neues Rathaus", "", 47.811944, 16.246389 },
	{ 54647, 0, "Wr. Neustadt / Theatergarage / Fußgängerzone", "", 47.813333, 16.239167 },
	{ 54648, 0, "Wr. Neustadt / Wienerstrasse / Eyerspergring", "", 47.816111, 16.244167 },
	{ 54649, 0, "Bad Erlach / Bhf Bad Erlach", "", 47.732222, 16.212500 },
	{ 54650, 0, "Bad Erlach / Therme Linsberg Asia", "", 47.733611, 16.205556 },
	{ 54651, 0, "Pitten / Marktplatz Pitten", "", 47.716389, 16.185833 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateWiener_Neustadt : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateWiener_Neustadt() {
    rect = QRectF(QPointF(46.809000, 15.249800), QPointF(48.809000, 17.249800));
    center = QPointF(47.809000, 16.249800);
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
      station->setRegion(QString("Wiener_Neustadt %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_WIENER_NEUSTADT_H */

