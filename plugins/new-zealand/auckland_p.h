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

#ifndef STATIONS_SIMPLE_PRIVATE_AUCKLAND_H
#define STATIONS_SIMPLE_PRIVATE_AUCKLAND_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 162, 0, "209 Queen St", "", -36.849453, 174.765095 },
	{ 210, 0, "148 Quay St", "", -36.843300, 174.768005 },
	{ 280, 0, "103 Customs St W", "", -36.843498, 174.763000 },
	{ 1414, 0, "157 Hobson St (Ac Hotel)", "", -36.851299, 174.759995 },
	{ 1494, 0, "23 Viaduct Harbour Ave", "", -36.845212, 174.758097 },
	{ 5152, 0, "242 Queen St", "", -36.850116, 174.764578 },
	{ 6786, 0, "Aut Wellesley St E", "", -36.853001, 174.766998 },
	{ 23640, 0, "1 Tyler St", "", -36.843997, 174.767976 },
	{ 23638, 0, "1 Queen St", "", -36.843480, 174.766887 },
	{ 23641, 0, "77 Broadway", "", -36.865854, 174.778576 },
	{ 31851, 0, "173 Karangahape Rd", "", -36.857763, 174.760208 },
	{ 31853, 0, "130 Broadway", "", -36.867545, 174.778383 },
	{ 31854, 0, "1 Morrow St", "", -36.870558, 174.777085 },
	{ 31855, 0, "152 Vincent St", "", -36.855248, 174.758846 },
	{ 31856, 0, "75 Queen St", "", -36.845349, 174.766262 },
	{ 31857, 0, "154 Queen St", "", -36.847741, 174.765908 },
	{ 31858, 0, "175 Queen St", "", -36.848075, 174.765333 },
	{ 31859, 0, "315 Queen St", "", -36.853528, 174.763292 },
	{ 31860, 0, "450 Queen St", "", -36.855118, 174.762900 },
	{ 31861, 0, "21 Pakenham St", "", -36.844083, 174.759114 },
	{ 31863, 0, "1 Wakefield St", "", -36.852427, 174.764050 },
	{ 31865, 0, "1 Burnley Tce", "", -36.879290, 174.749705 },
	{ 31866, 0, "292 Dominion Rd", "", -36.877688, 174.750682 },
	{ 31867, 0, "451 Mt Eden Rd", "", -36.882757, 174.761882 },
	{ 31868, 0, "412 Mt Eden Rd", "", -36.880788, 174.762118 },
	{ 31869, 0, "1 Khyber Pass Rd", "", -36.864111, 174.761085 },
	{ 31870, 0, "1 Anzac Av", "", -36.845721, 174.771296 },
	{ 36968, 0, "79 Park Rd", "", -36.861047, 174.768917 },
	{ 37282, 0, "291 Queen St", "", -36.851534, 174.763840 },
	{ 39146, 0, "1 Scotland St", "", -36.848359, 174.750617 },
	{ 39320, 0, "191 Queen St", "", -36.848501, 174.765209 },
	{ 39727, 0, "44 Queen St", "", -36.845296, 174.766642 },
	{ 39768, 0, "347 Karangahape Rd", "", -36.857871, 174.756732 },
	{ 39772, 0, "50 Remuera Rd", "", -36.870806, 174.778898 },
	{ 40043, 0, "2 Fort St", "", -36.845804, 174.766302 },
	{ 40130, 0, "121 Customs St W", "", -36.843795, 174.760342 },
	{ 42605, 0, "131 Queen St", "", -36.846936, 174.765728 },
	{ 42828, 0, "193 Park Rd", "", -36.865511, 174.770519 },
	{ 53734, 0, "239 Queen St", "", -36.849612, 174.765229 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateAuckland : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateAuckland() {
    rect = QRectF(QPointF(-37.860300, 173.763000), QPointF(-35.860300, 175.763000));
    center = QPointF(-36.860300, 174.763000);
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
      station->setRegion(QString("Auckland %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_AUCKLAND_H */

