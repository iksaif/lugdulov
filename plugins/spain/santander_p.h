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

#ifndef STATIONS_SIMPLE_PRIVATE_SANTANDER_H
#define STATIONS_SIMPLE_PRIVATE_SANTANDER_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 7, 0, "007_Facultad De Derecho", "Aprox. Facultad De Ciencias", 43.470166, -3.806499 },
	{ 6, 0, "006_Faculdad De Ciencias", "Aprox. Glorieta De Los Delfines", 43.471106, -3.800586 },
	{ 11, 0, "011_Puerto Chico", "Aprox.Paseo Pereda Y San Martín", 43.462678, -3.796569 },
	{ 12, 0, "012_Calle Alta", "Aprox. Mercado De México", 43.457966, -3.824801 },
	{ 13, 0, "013_Calle De San Fernando", "Aprox. Paseo Del Alameda", 43.460726, -3.817978 },
	{ 4, 0, "004_Cormorán", "Aprox. C/ De Manuel García Lago", 43.478472, -3.788653 },
	{ 1, 0, "001_Jardines De Pereda", "Aprox. Correos Y Castelar", 43.461433, -3.803315 },
	{ 10, 0, "010_Plaza De San Martin", "Aprox. Avda De La Reina Victoria Y Castelar", 43.463552, -3.788005 },
	{ 5, 0, "005_Glorieta De Los Delfines", "Aprox. Avda De Los Castros", 43.471966, -3.792854 },
	{ 2, 0, "002_Plaza De Las Brisas", "Aprox. Jardines De Piquio", 43.474413, -3.785781 },
	{ 8, 0, "008_Plaza De Italia", "Aprox. C/ De Joaquín Costa", 43.471805, -3.781346 },
	{ 3, 0, "003_Parque Las Llamas", "Aprox. Palacio De Deportes", 43.475732, -3.798064 },
//	{ 9, 0, "009_Avenida De La Magdalena", "Aprox. Avda De La Reina Victoria", 89.998906, -136.261831 },
	{ 14, 0, "014_Atilano Rodriguez", "Aprox. Paseo De Pereda Y San Fernando", 43.458384, -3.810468 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateSantander : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateSantander() {
    rect = QRectF(QPointF(43.260960, -3.824801), QPointF(43.478472, -3.607934));
    center = QPointF(43.460960, -3.807934);
    statusUrl = "http://www.tusbic.es/service/stationdetails/%1";
    infosUrl = "http://www.tusbic.es/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Santander %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_SANTANDER_H */

