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

#ifndef STATIONS_SIMPLE_PRIVATE_NICE_H
#define STATIONS_SIMPLE_PRIVATE_NICE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 2, 0, "Station N°2", "", 43.676697, 7.199092 },
	{ 3, 0, "Station N°3", "", 43.677581, 7.205679 },
	{ 4, 0, "Station N°4", "", 43.675409, 7.199264 },
	{ 5, 0, "Station N°5", "", 43.670815, 7.207847 },
	{ 6, 0, "Station N°6", "", 43.664948, 7.203104 },
	{ 7, 0, "Station N°7", "", 43.666081, 7.212095 },
	{ 8, 0, "Station N°8", "", 43.668325, 7.211838 },
	{ 9, 0, "Station N°9", "", 43.670101, 7.213576 },
	{ 10, 0, "Station N°10", "", 43.668108, 7.215528 },
	{ 11, 0, "Station N°11", "", 43.669557, 7.217073 },
	{ 12, 0, "Station N°12", "", 43.674757, 7.225270 },
	{ 13, 0, "Station N°13", "", 43.676855, 7.229197 },
	{ 14, 0, "Station N°14", "", 43.688462, 7.239797 },
	{ 15, 0, "Station N°15", "", 43.691987, 7.245054 },
	{ 16, 0, "Station N°16", "", 43.693833, 7.252264 },
	{ 17, 0, "Station N°17", "", 43.697600, 7.265450 },
	{ 18, 0, "Station N°18", "", 43.696153, 7.266834 },
	{ 19, 0, "Station N°19", "", 43.697332, 7.270342 },
	{ 20, 0, "Station N°20", "", 43.695633, 7.270482 },
	{ 21, 0, "Station N°21", "", 43.696600, 7.274560 },
	{ 22, 0, "Station N°22", "", 43.694600, 7.278310 },
	{ 23, 0, "Station N°23", "", 43.699597, 7.276458 },
	{ 24, 0, "Station N°24", "", 43.694974, 7.274333 },
	{ 25, 0, "Station N°25", "", 43.701916, 7.277842 },
	{ 26, 0, "Station N°26", "", 43.703111, 7.279451 },
	{ 27, 0, "Station N°27", "", 43.699713, 7.280760 },
	{ 28, 0, "Station N°28", "", 43.698495, 7.283206 },
	{ 29, 0, "Station N°29", "", 43.693647, 7.289976 },
	{ 30, 0, "Station N°30", "", 43.708043, 7.281682 },
	{ 31, 0, "Station N°31", "", 43.706415, 7.283024 },
	{ 32, 0, "Station N°32", "", 43.705026, 7.286274 },
	{ 33, 0, "Station N°33", "", 43.702343, 7.273443 },
	{ 34, 0, "Station N°34", "", 43.702700, 7.271210 },
	{ 35, 0, "Station N°35", "", 43.700753, 7.268239 },
	{ 36, 0, "Station N°36", "", 43.704445, 7.263250 },
	{ 37, 0, "Station N°37", "", 43.705600, 7.289760 },
	{ 38, 0, "Station N°38", "", 43.670908, 7.222738 },
	{ 39, 0, "Station N°39", "", 43.673509, 7.225399 },
	{ 40, 0, "Station N°40", "", 43.675424, 7.227287 },
	{ 41, 0, "Station N°41", "", 43.674643, 7.223049 },
	{ 42, 0, "Station N°42", "", 43.677414, 7.225302 },
	{ 43, 0, "Station N°43", "", 43.690076, 7.242340 },
	{ 44, 0, "Station N°44", "", 43.679956, 7.231193 },
	{ 45, 0, "Station N°45", "", 43.678812, 7.228146 },
	{ 46, 0, "Station N° 46", "", 43.685545, 7.235291 },
	{ 47, 0, "Station N°47", "", 43.682780, 7.234025 },
	{ 48, 0, "Station N°48", "", 43.686515, 7.238134 },
	{ 49, 0, "Station N°49", "", 43.693104, 7.248820 },
	{ 50, 0, "Station N°50", "", 43.695889, 7.251931 },
	{ 51, 0, "Station N°51", "", 43.695951, 7.256448 },
	{ 52, 0, "Station N°52", "", 43.694586, 7.254581 },
	{ 53, 0, "Station N°53", "", 43.697759, 7.251577 },
	{ 54, 0, "Station N°54", "", 43.699713, 7.255912 },
	{ 55, 0, "Station N°55", "", 43.699457, 7.252167 },
	{ 56, 0, "Station N°56", "", 43.702157, 7.257822 },
	{ 57, 0, "Station N°57", "", 43.701094, 7.255086 },
	{ 58, 0, "Station N°58", "", 43.695478, 7.258680 },
	{ 59, 0, "Station N°59", "", 43.698317, 7.260236 },
	{ 60, 0, "Station N°60", "", 43.700600, 7.260330 },
	{ 61, 0, "Station N°61", "", 43.702475, 7.262639 },
	{ 62, 0, "Station N°62", "", 43.699690, 7.265021 },
	{ 63, 0, "Station N°63", "", 43.703429, 7.265943 },
	{ 64, 0, "Station N°64", "", 43.696060, 7.263325 },
	{ 65, 0, "Station N°65", "", 43.699139, 7.269977 },
	{ 66, 0, "Station N°66", "", 43.700497, 7.272756 },
	{ 67, 0, "Station N°67", "", 43.697800, 7.273050 },
	{ 68, 0, "Station N°68", "", 43.700745, 7.275674 },
	{ 69, 0, "Station N°69", "", 43.703902, 7.273582 },
	{ 70, 0, "Station N°70", "", 43.702544, 7.275610 },
	{ 71, 0, "Station N°71", "", 43.706384, 7.268733 },
	{ 72, 0, "Station N°72", "", 43.704274, 7.270042 },
	{ 73, 0, "Station N°73", "", 43.694900, 7.286390 },
	{ 74, 0, "Station N°74", "", 43.698883, 7.287422 },
	{ 75, 0, "Station N°75", "", 43.697262, 7.286843 },
	{ 76, 0, "Station N°76", "", 43.697247, 7.282755 },
	{ 77, 0, "Station N°77", "", 43.700551, 7.285631 },
	{ 78, 0, "Station N°78", "", 43.701939, 7.282122 },
	{ 79, 0, "Station N°79", "", 43.702296, 7.286350 },
	{ 80, 0, "Station N°80", "", 43.704770, 7.281693 },
	{ 81, 0, "Station N°81", "", 43.704018, 7.287326 },
	{ 82, 0, "Station N°82", "", 43.702273, 7.288699 },
	{ 83, 0, "Station N°83", "", 43.703809, 7.283785 },
	{ 84, 0, "Station N°84", "", 43.693989, 7.282208 },
	{ 85, 0, "Station N°85", "", 43.695144, 7.277627 },
	{ 86, 0, "Station N°86", "", 43.700489, 7.278593 },
	{ 87, 0, "Station N°87", "", 43.699457, 7.277541 },
	{ 88, 0, "Station N°88", "", 43.702552, 7.259581 },
	{ 89, 0, "Station N°89", "", 43.693640, 7.256384 },
	{ 90, 0, "Station N°90", "", 43.691599, 7.248960 },
	{ 91, 0, "Station N°91", "", 43.668952, 7.220914 },
	{ 92, 0, "Station N° 92", "", 43.670784, 7.210314 },
	{ 93, 0, "Station N°93", "", 43.673282, 7.208984 },
	{ 94, 0, "Station N° 94", "", 43.675626, 7.207053 },
	{ 95, 0, "Station N°95", "", 43.677069, 7.203641 },
	{ 96, 0, "Station N°96", "", 43.681410, 7.231557 },
	{ 99, 0, "Station N°99", "", 43.708338, 7.288527 },
	{ 100, 0, "Station N°100", "", 43.693795, 7.244325 },
	{ 107, 0, "Station N°107", "", 43.705918, 7.256212 },
	{ 108, 0, "Station N°108", "", 43.702700, 7.255120 },
	{ 109, 0, "Station N°109", "", 43.708100, 7.256800 },
	{ 110, 0, "Station N°110", "", 43.709843, 7.255762 },
	{ 111, 0, "Station N°111", "", 43.709967, 7.258433 },
	{ 112, 0, "Station N°112", "", 43.712216, 7.261920 },
	{ 113, 0, "Station N°113", "", 43.713984, 7.258798 },
	{ 121, 0, "Station N°121", "", 43.712728, 7.259023 },
	{ 123, 0, "Station N°123", "", 43.707144, 7.262864 },
	{ 124, 0, "Station N°124", "", 43.706058, 7.265332 },
	{ 125, 0, "Station N°125", "", 43.710409, 7.284054 },
	{ 135, 0, "Station N°135", "", 43.707609, 7.292819 },
	{ 136, 0, "Station N°136", "", 43.711719, 7.264613 },
	{ 137, 0, "Station N°137", "", 43.709005, 7.266533 },
	{ 153, 0, "Station N°153", "", 43.710928, 7.282948 },
	{ 161, 0, "Station N°161", "", 43.708700, 7.260180 },
	{ 162, 0, "Station N°162", "", 43.710277, 7.262950 },
	{ 163, 0, "Station N°163", "", 43.709052, 7.289536 },
	{ 167, 0, "Station N°167", "", 43.715868, 7.261577 },
	{ 168, 0, "Station N°168", "", 43.714700, 7.254040 },
	{ 172, 0, "Station N°172", "", 43.715899, 7.265557 },
	{ 173, 0, "Station N°173", "", 43.705631, 7.259592 },
	{ 174, 0, "Station N°174", "", 43.694400, 7.260730 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateNice : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateNice() {
    rect = QRectF(QPointF(43.503427, 7.066266), QPointF(43.903427, 7.466266));
    center = QPointF(43.703427, 7.266266);
    statusUrl = "";
    infosUrl = "http://www.velobleu.org/oybike/stands.nsf/getSite?openagent&site=nice&format=json&key=D2652BE27FAFB0267752831BFEC4334C";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Nice %1").arg(stations[i].arrondissementNumber));
      list.append(station);
    }

    return list;
  }

  QStringList regions() {
    QStringList ret;


    return ret;
  }
};

#endif /* STATIONS_SIMPLE_PRIVATE_NICE_H */

