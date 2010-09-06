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

#ifndef STATIONS_SIMPLE_PRIVATE_DUISBURG_H
#define STATIONS_SIMPLE_PRIVATE_DUISBURG_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 50418, 0, "Haltestelle Landschaftspark", "", 51.4798155846, 6.79295042868 },
	{ 50417, 0, "Landschaftspark", "", 51.4804806798, 6.78360518841 },
	{ 50416, 0, "Bahnhof Meiderich", "", 51.4676003326, 6.77955632546 },
	{ 50415, 0, "Yitzhak-Rabin-Platz", "", 51.4383973229, 6.76448986385 },
	{ 50414, 0, "Verknüpfungshalle West", "", 51.4315503636, 6.77508831737 },
	{ 50412, 0, "Steinsche Gasse", "", 51.4341125568, 6.76269262009 },
	{ 50411, 0, "Stadttheater", "", 51.4341128234, 6.77088948523 },
	{ 50409, 0, "Rathaus", "", 51.4352242873, 6.7617476373 },
	{ 50410, 0, "Schwanentor", "", 51.435868773, 6.75800492502 },
	{ 50408, 0, "Museum Küppersmühle  Holzgracht", "", 51.4407773336, 6.77300095947 },
	{ 50407, 0, "Lehmbruckmuseum", "", 51.4309485516, 6.76545826151 },
	{ 50406, 0, "Lego Discovery", "", 51.4406163416, 6.77015050346 },
	{ 50405, 0, "Kuhtor", "", 51.4337091422, 6.7639082239 },
	{ 50404, 0, "Hauptbahnhof  Ost", "", 51.4295320581, 6.77718223075 },
	{ 50403, 0, "Hauptbahnhof  Haupteingang", "", 51.4304140307, 6.77294093509 },
	{ 50402, 0, "Forum", "", 51.4334097001, 6.76846175979 },
	{ 50401, 0, "Dellplatz", "", 51.4302344533, 6.76193778342 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateDuisburg : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateDuisburg() {
    rect = QRectF(QPointF(50.448700, 5.775130), QPointF(52.448700, 7.775130));
    center = QPointF(51.448700, 6.775130);
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
      station->setRegion(QString("Duisburg %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_DUISBURG_H */

