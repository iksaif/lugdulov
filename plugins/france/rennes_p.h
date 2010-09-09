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

#ifndef STATIONS_SIMPLE_PRIVATE_RENNES_H
#define STATIONS_SIMPLE_PRIVATE_RENNES_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 75, 0, "Zac Saint Sulpice", "", 48.132100, -1.635280 },
	{ 52, 0, "Villejean-Universite", "", 48.121075, -1.704122 },
	{ 81, 0, "Turmel", "", 48.122475, -1.651089 },
	{ 12, 0, "Tnb", "", 48.107697, -1.673695 },
	{ 71, 0, "Ste Therese", "", 48.094994, -1.663705 },
	{ 5, 0, "Sainte Anne", "", 48.114510, -1.680984 },
	{ 9, 0, "Saint Georges", "", 48.112385, -1.674417 },
	{ 23, 0, "Rotonde", "", 48.106663, -1.686713 },
	{ 1, 0, "Republique", "", 48.109990, -1.678027 },
	{ 8, 0, "Rectorat", "", 48.119396, -1.674450 },
	{ 55, 0, "Prefecture", "", 48.128407, -1.693916 },
	{ 39, 0, "Pontchaillou (Metro)", "", 48.121490, -1.692816 },
	{ 42, 0, "Pont De Strasbourg", "", 48.109756, -1.656451 },
	{ 20, 0, "Pont De Nantes", "", 48.102016, -1.683961 },
	{ 35, 0, "Pont De Chateaudun", "", 48.110310, -1.663955 },
	{ 19, 0, "Plelo Colombier", "", 48.105907, -1.681306 },
	{ 4, 0, "Place Hoche", "", 48.115074, -1.677062 },
	{ 24, 0, "Place De Bretagne", "", 48.109657, -1.684020 },
	{ 59, 0, "Piscine Gayeulles", "", 48.134563, -1.651560 },
	{ 66, 0, "Piscine Brequigny", "", 48.089664, -1.690234 },
	{ 40, 0, "Pierre Martin", "", 48.103497, -1.662321 },
	{ 36, 0, "Paul Bert", "", 48.110115, -1.670039 },
	{ 80, 0, "Painleve", "", 48.123020, -1.660502 },
	{ 25, 0, "Office De Tourisme", "", 48.110294, -1.683107 },
	{ 22, 0, "Oberthur", "", 48.113510, -1.661840 },
	{ 10, 0, "Musee Beaux Arts", "", 48.109573, -1.674072 },
	{ 46, 0, "Moulin De Joue", "", 48.112038, -1.645745 },
	{ 76, 0, "Monts D'Arree", "", 48.136700, -1.666673 },
	{ 44, 0, "Metz Sevigne", "", 48.115967, -1.658260 },
	{ 70, 0, "Mermoz", "", 48.097942, -1.688113 },
	{ 38, 0, "Marbeuf", "", 48.111725, -1.702033 },
	{ 31, 0, "Malakoff", "", 48.105255, -1.692976 },
	{ 2, 0, "Mairie", "", 48.111626, -1.678745 },
	{ 65, 0, "Lycee Brequigny", "", 48.084850, -1.691921 },
	{ 11, 0, "Liberte", "", 48.107513, -1.678163 },
	{ 26, 0, "Les Lices", "", 48.112766, -1.685036 },
	{ 21, 0, "Les Halles", "", 48.107660, -1.680087 },
	{ 14, 0, "Laennec", "", 48.106850, -1.665818 },
	{ 32, 0, "La Touche", "", 48.116608, -1.690943 },
	{ 58, 0, "La Harpe", "", 48.125570, -1.710290 },
	{ 29, 0, "Jules Ferry", "", 48.121384, -1.671111 },
	{ 53, 0, "Jf Kennedy", "", 48.121530, -1.711088 },
	{ 61, 0, "Jacques Cartier", "", 48.097534, -1.674305 },
	{ 64, 0, "Italie", "", 48.086770, -1.667567 },
	{ 77, 0, "Houx Cite U", "", 48.130510, -1.663130 },
	{ 6, 0, "Hotel Dieu", "", 48.117596, -1.677851 },
	{ 27, 0, "Horizons", "", 48.112060, -1.688515 },
	{ 63, 0, "Henri Freville", "", 48.087296, -1.674850 },
	{ 78, 0, "Gros Chene", "", 48.126823, -1.665083 },
	{ 73, 0, "Geniaux", "", 48.108936, -1.709452 },
	{ 79, 0, "Gast", "", 48.131290, -1.656476 },
	{ 45, 0, "Gares (Sud)", "", 48.102257, -1.673103 },
	{ 15, 0, "Gares (Nord)", "", 48.104088, -1.672139 },
	{ 7, 0, "Fac De Droit", "", 48.118170, -1.670735 },
	{ 30, 0, "Duchesse Anne", "", 48.119530, -1.667023 },
	{ 13, 0, "Dinan", "", 48.117214, -1.682698 },
	{ 74, 0, "De Lesseps", "", 48.100910, -1.707072 },
	{ 18, 0, "Dalle Du Colombier", "", 48.105118, -1.678678 },
	{ 60, 0, "Cucille", "", 48.128803, -1.698018 },
	{ 72, 0, "Cleunay", "", 48.104210, -1.712630 },
	{ 62, 0, "Clemenceau", "", 48.093285, -1.674116 },
	{ 43, 0, "Cite Judiciaire", "", 48.104816, -1.684110 },
	{ 41, 0, "Cimetiere Est", "", 48.104330, -1.650099 },
	{ 28, 0, "Cheques Postaux", "", 48.108880, -1.693359 },
	{ 17, 0, "Charles De Gaulle", "", 48.105110, -1.677122 },
	{ 69, 0, "Champs Manceaux", "", 48.091145, -1.682269 },
	{ 16, 0, "Champs Libres", "", 48.105530, -1.674394 },
	{ 3, 0, "Champs Jacquet", "", 48.112804, -1.680054 },
	{ 34, 0, "Brest Verdun", "", 48.113014, -1.693273 },
	{ 51, 0, "Bouzat", "", 48.128730, -1.635132 },
	{ 67, 0, "Binquenais", "", 48.091568, -1.667300 },
	{ 56, 0, "Berger", "", 48.116290, -1.705127 },
	{ 48, 0, "Beaulieu Restau U.", "", 48.121950, -1.638313 },
	{ 50, 0, "Beaulieu Insa", "", 48.118954, -1.635186 },
	{ 47, 0, "Beaulieu Chimie", "", 48.116455, -1.633916 },
	{ 49, 0, "Beaulieu Bois Perrin", "", 48.117950, -1.642867 },
	{ 37, 0, "Auberge De Jeunesse", "", 48.120857, -1.681836 },
	{ 57, 0, "Atalante Champeaux", "", 48.116070, -1.713711 },
	{ 33, 0, "Anatole France", "", 48.117985, -1.686405 },
	{ 68, 0, "Alma", "", 48.082397, -1.677634 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateRennes : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateRennes() {
    rect = QRectF(QPointF(47.911761, -1.880265), QPointF(48.311761, -1.480265));
    center = QPointF(48.111761, -1.680265);
    statusUrl = "";
    infosUrl = "http://data.keolis-rennes.com/xml/?version=1.0&key=5O3IN1BU3MK100U&cmd=getstation";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Rennes %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_RENNES_H */

