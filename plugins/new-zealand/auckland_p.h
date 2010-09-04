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
	{ 162, 0, "209 Queen St", "", -36.8494533, 174.765095 },
	{ 210, 0, "148 Quay St", "", -36.8432998657, 174.768005371 },
	{ 280, 0, "103 Customs St W", "", -36.84349823, 174.763000488 },
	{ 1414, 0, "157 Hobson St (Ac Hotel)", "", -36.8512992859, 174.759994507 },
	{ 1494, 0, "23 Viaduct Harbour Ave", "", -36.8452120056, 174.758097231 },
	{ 5152, 0, "242 Queen St", "", -36.850116, 174.764578 },
	{ 6786, 0, "Aut Wellesley St E", "", -36.8530006409, 174.766998291 },
	{ 23640, 0, "1 Tyler St", "", -36.8439970994, 174.767975807 },
	{ 23638, 0, "1 Queen St", "", -36.84348, 174.766887 },
	{ 23641, 0, "77 Broadway", "", -36.8658538744, 174.778575897 },
	{ 31851, 0, "173 Karangahape Rd", "", -36.8577634756, 174.76020813 },
	{ 31853, 0, "130 Broadway", "", -36.8675448098, 174.778382778 },
	{ 31854, 0, "1 Morrow St", "", -36.8705575003, 174.777084589 },
	{ 31855, 0, "152 Vincent St", "", -36.8552481956, 174.758845568 },
	{ 31856, 0, "75 Queen St", "", -36.845349, 174.766262 },
	{ 31857, 0, "154 Queen St", "", -36.847741, 174.765908 },
	{ 31858, 0, "175 Queen St", "", -36.848075, 174.765333 },
	{ 31859, 0, "315 Queen St", "", -36.8535284, 174.7632915 },
	{ 31860, 0, "450 Queen St", "", -36.855118, 174.7629 },
	{ 31861, 0, "21 Pakenham St", "", -36.8440829591, 174.759113789 },
	{ 31863, 0, "1 Wakefield St", "", -36.8524269, 174.76405 },
	{ 31865, 0, "1 Burnley Tce", "", -36.8792901982, 174.749704599 },
	{ 31866, 0, "292 Dominion Rd", "", -36.877688, 174.750682 },
	{ 31867, 0, "451 Mt Eden Rd", "", -36.882757253, 174.761881828 },
	{ 31868, 0, "412 Mt Eden Rd", "", -36.8807877449, 174.762117863 },
	{ 31869, 0, "1 Khyber Pass Rd", "", -36.8641113993, 174.761085212 },
	{ 31870, 0, "1 Anzac Av", "", -36.845720715, 174.771296382 },
	{ 36968, 0, "79 Park Rd", "", -36.8610469503, 174.768917263 },
	{ 37282, 0, "291 Queen St", "", -36.851534, 174.76384 },
	{ 39146, 0, "1 Scotland St", "", -36.8483586518, 174.75061655 },
	{ 39320, 0, "191 Queen St", "", -36.848501, 174.765209 },
	{ 39727, 0, "44 Queen St", "", -36.845296, 174.766642 },
	{ 39768, 0, "347 Karangahape Rd", "", -36.8578707809, 174.756731987 },
	{ 39772, 0, "50 Remuera Rd", "", -36.8708064068, 174.778897762 },
	{ 40043, 0, "2 Fort St", "", -36.8458044264, 174.766302109 },
	{ 40130, 0, "121 Customs St W", "", -36.8437953286, 174.76034224 },
	{ 42605, 0, "131 Queen St", "", -36.846936, 174.7657284 },
	{ 42828, 0, "193 Park Rd", "", -36.8655105327, 174.770518541 },
	{ 53734, 0, "239 Queen St", "", -36.8496121228, 174.765229225 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateAuckland : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateAuckland() {
    rect = QRectF(QPointF(-37.060300, 174.563000), QPointF(-36.660300, 174.963000));
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

