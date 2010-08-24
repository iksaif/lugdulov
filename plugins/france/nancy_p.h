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

#ifndef STATIONS_SIMPLE_PRIVATE_NANCY_H
#define STATIONS_SIMPLE_PRIVATE_NANCY_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        const char *fullAddress;
        double x;
        double y;
} stations[] = {
	{ 14, 0, "00014 - Port St Georges - Capitainerie (Cb)", "Boulevard Du 2E Ra", "Boulevard Du 2E Ra  ", 48.6923050673, 6.19305360568 },
	{ 20, 0, "00020 - Porte St Nicolas", "Rue St Dizier", "Rue St Dizier  ", 48.6858671393, 6.18622889173 },
	{ 25, 0, "00025 - Place Commanderie", "Place De La Commanderie Face Au 13", "Place De La Commanderie Face Au 13  ", 48.6859179817, 6.16742181615 },
	{ 13, 0, "00013 - Saint Nicolas - Charles Iii", "77 ,Rue Saint Nicolas", "77 ,Rue Saint Nicolas  ", 48.6878319691, 6.18780151508 },
	{ 4, 0, "00004 - Marche Central (Cb)", "Place Mengin", "Place Mengin  ", 48.6890951179, 6.18243085151 },
	{ 18, 0, "00018 - Gare Saint Leon (Cb)", "Rue Saint Leon", "Rue Saint Leon  ", 48.6895601111, 6.1725154523 },
	{ 15, 0, "00015 - Port Ste Catherine", "Quai Ste Catherine", "Quai Ste Catherine  ", 48.695487004, 6.19067948967 },
	{ 17, 0, "00017 - Conservatoire - Manufacture", "27 Rue Baron Louis", "27 Rue Baron Louis  ", 48.6957176857, 6.17133838702 },
	{ 5, 0, "00005 - Place Colonel Driant (Cb)", "Rue Drouin Face Au 2", "Rue Drouin Face Au 2  ", 48.6924632065, 6.18818527638 },
	{ 24, 0, "00024 - 3 Maisons - Charles V (Cb)", "15 Rue Du Faubourg Des 3 Maisons", "15 Rue Du Faubourg Des 3 Maisons  ", 48.7008781485, 6.17706203367 },
	{ 6, 0, "00006 - Place Du Colonel Fabien", "16, Place Du Colonel Fabien", "16, Place Du Colonel Fabien  ", 48.6951745524, 6.17978102303 },
	{ 9, 0, "00009 - Mazagran - Poincare", "Rue Raymond Poincare", "Rue Raymond Poincare  ", 48.6907910639, 6.17508015574 },
	{ 7, 0, "00007 - Place Saint Epvre (Cb)", "Rue Pierre Gringoire", "Rue Pierre Gringoire  ", 48.6963138587, 6.17989241729 },
	{ 23, 0, "00023 - Promenade Des Canaux", "Rue Des Tiercelins", "Rue Des Tiercelins  ", 48.6927939743, 6.19628435757 },
	{ 12, 0, "00012 - St Sebastien - St Thiebaut (Cb)", "Rue Saint Thiebaut", "Rue Saint Thiebaut  ", 48.6886141256, 6.17950010442 },
	{ 21, 0, "00021 - Hopital Central (Cb)", "45 Avenue Du Marechal De Lattre De Tassigny", "45 Avenue Du Marechal De Lattre De Tassigny  ", 48.6833502131, 6.19029660802 },
	{ 19, 0, "00019 - Commanderie - Chalnot", "Rue P. Chalnot", "Rue P. Chalnot  ", 48.6869197241, 6.17234789239 },
	{ 16, 0, "00016 - Porte De La Craffe (Cb)", "Place Des Bourgets", "Place Des Bourgets  ", 48.6984724452, 6.17798553706 },
	{ 1, 0, "00001 - Dominicains - Fourrier (Cb)", "Rue Pierre Fourrier", "Rue Pierre Fourrier  ", 48.6924654452, 6.18340055389 },
	{ 11, 0, "00011 - Mazagran - Foch (Cb)", "Boulevard Foch", "Boulevard Foch  ", 48.6894760345, 6.1765054624 },
	{ 22, 0, "00022 - Hopital St Julien", "Rue Molitor", "Rue Molitor  ", 48.6858574027, 6.1929017147 },
	{ 3, 0, "00003 - Place De Dombasle (Cb)", "Rue De Stanislas Face Au 68", "Rue De Stanislas Face Au 68  ", 48.6919579484, 6.17851021951 },
	{ 8, 0, "00008 - Cours Leopold - Saint Michel (Cb)", "Rue Saint Michel", "Rue Saint Michel  ", 48.6956140663, 6.17676840786 },
	{ 2, 0, "00002 - Place De La Carriere (Cb)", "Place De La Carriere", "Place De La Carriere  ", 48.6945981637, 6.18229408638 },
	{ 10, 0, "00010 - Gare Thiers (Cb)", "Rue Pirou Crampel", "Rue Pirou Crampel  ", 48.6901882593, 6.17451913851 },
	{0, 0, NULL, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateNancy : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateNancy() {
    rect = QRectF(QPointF(48.682999654389, 6.166844565318), QPointF(48.701228707210, 6.196861608399));
    center = QPointF(48.692114180800, 6.181853086858);
    statusUrl = "http://www.velostanlib.fr/service/stationdetails/%1";
    infosUrl = "http://www.velostanlib.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Nancy %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_NANCY_H */

