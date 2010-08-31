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

#ifndef STATIONS_SIMPLE_PRIVATE_DUBLIN_H
#define STATIONS_SIMPLE_PRIVATE_DUBLIN_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 25, 0, "Merrion Square East", "Merrion Square East", 53.339434, -6.246548 },
	{ 26, 0, "Merrion Square West", "Merrion Square West", 53.339764, -6.251988 },
	{ 27, 0, "Molesworth Street", "Molesworth Street", 53.341288, -6.258117 },
	{ 28, 0, "Mountjoy Square West", "Mountjoy Square West", 53.356299, -6.258586 },
	{ 29, 0, "Ormond Quay Upper", "Ormond Quay Upper", 53.346057, -6.268001 },
	{ 30, 0, "Parnell Square North", "Parnell Square North", 53.353462, -6.265305 },
	{ 3, 0, "Bolton Street", "Bolton Street", 53.351182, -6.269859 },
	{ 24, 0, "Cathal Brugha Street", "Cathal Brugha Street", 53.352149, -6.260533 },
	{ 31, 0, "Parnell Street", "Parnell Street", 53.350929, -6.265125 },
	{ 32, 0, "Pearse Street", "Pearse Street", 53.344304, -6.250427 },
	{ 4, 0, "Greek Street", "Greek Street", 53.346874, -6.272976 },
	{ 5, 0, "Charlemont Place", "Charlemont Street", 53.330662, -6.260177 },
	{ 7, 0, "High Street", "High Street", 53.343565, -6.275071 },
	{ 34, 0, "Portobello Harbour", "Portobello Harbour", 53.330362, -6.265163 },
	{ 35, 0, "Smithfield", "Smithfield", 53.347692, -6.278214 },
	{ 8, 0, "Custom House Quay", "Custom House Quay", 53.347884, -6.248048 },
	{ 36, 0, "St. Stephen'S Green East", "St. Stephen'S Green East", 53.337824, -6.256035 },
	{ 9, 0, "Exchequer Street", "Exchequer Street", 53.343034, -6.263578 },
	{ 10, 0, "Dame Street", "Dame Street", 53.344007, -6.266802 },
	{ 11, 0, "Earlsfort Terrace", "Earlsfort Terrace", 53.334019, -6.258371 },
	{ 12, 0, "Eccles Street", "Eccles Street", 53.359246, -6.269779 },
	{ 13, 0, "Fitzwilliam Square West", "Fitzwilliam Square West", 53.336074, -6.252825 },
	{ 14, 0, "Fownes Street Upper", "Fownes Street Upper", 53.344603, -6.263371 },
	{ 37, 0, "St. Stephen'S Green South", "St. Stephen'S Green South", 53.337494, -6.26199 },
	{ 38, 0, "Talbot Street", "Talbot Street", 53.350974, -6.25294 },
	{ 16, 0, "Georges Quay", "Georges Quay", 53.347508, -6.252192 },
	{ 39, 0, "Wilton Terrace", "Wilton Terrace", 53.332383, -6.252717 },
	{ 40, 0, "Jervis Street", "Jervis Street", 53.3483, -6.266651 },
	{ 20, 0, "James Street East", "James Street East", 53.336485, -6.248174 },
	{ 23, 0, "Custom House", "Custom House", 53.348279, -6.254662 },
	{ 21, 0, "Leinster Street South", "Leinster Street South", 53.34218, -6.254485 },
	{ 22, 0, "Townsend Street", "Townsend Street", 53.345922, -6.254614 },
	{ 2, 0, "Blessington Street", "Blessington Street", 53.356769, -6.26814 },
	{ 6, 0, "Christchurch Place", "Christchurch Place", 53.343368, -6.27012 },
	{ 19, 0, "Herbert Place", "Herbert Place", 53.334432, -6.245575 },
	{ 1, 0, "Chatham Street", "Chatham Street", 53.340962, -6.262287 },
	{ 18, 0, "Grantham Street", "Grantham Street", 53.334123, -6.265436 },
	{ 15, 0, "Hardwicke Street", "Hardwicke Street", 53.355473, -6.264423 },
	{ 17, 0, "Golden Lane", "Golden Lane", 53.340803, -6.267732 },
	{ 33, 0, "Princes Street / O'Connell Street", "Princes Street / O'Connell Street", 53.349013, -6.260311 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateDublin : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateDublin() {
    rect = QRectF(QPointF(53.144104, -6.278214), QPointF(53.359246, -6.067494));
    center = QPointF(53.344104, -6.267494);
    statusUrl = "http://www.dublinbikes.ie/service/stationdetails/%1";
    infosUrl = "http://www.dublinbikes.ie/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Dublin %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;

    ret << "0";

    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_DUBLIN_H */

