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

#ifndef STATIONS_SIMPLE_PRIVATE_MARSEILLE_H
#define STATIONS_SIMPLE_PRIVATE_MARSEILLE_H

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
	{ 1001, 0, "1001 - Canebiere Reine Elizabeth", "", "  ", 43.2956861099, 5.37533951418 },
	{ 1002, 0, "1002-Hotel De Ville", "", "  ", 43.2960838626, 5.37080541567 },
	{ 1003, 0, "1003-Place Aux Huiles", "", "  ", 43.2931223973, 5.37186760649 },
	{ 1004, 0, "1004-General De Gaulle Paradis", "", "  ", 43.2949473063, 5.3760267473 },
	{ 1006, 0, "1006-Cours Jean Ballard", "", "  ", 43.2933679092, 5.37463817729 },
	{ 1130, 0, "1130- 1 National Longchamp", "", "  ", 43.3012331984, 5.38777326179 },
	{ 1156, 0, "1156-Quai Des Belges Pytheas", "", "  ", 43.2942268079, 5.37447435685 },
	{ 1191, 0, "1191-Canebiere-St Ferreol", "", "  ", 43.2962076706, 5.37693066221 },
	{ 1210, 0, "1210-Beauvau - Canebiere", "", "  ", 43.2954212561, 5.37516544677 },
	{ 1211, 0, "1211-Beauvau - Suffren", "", "  ", 43.2947747736, 5.37513122034 },
	{ 1213, 0, "1213-Grignan - Marcelle Paul", "", "  ", 43.2913574652, 5.37354694538 },
	{ 1216, 0, "1216-Sainte - Lulli", "", "  ", 43.292666663, 5.37590597428 },
	{ 1224, 0, "1224-Plaine - Bibliotheque", "", "  ", 43.2958251833, 5.38599609072 },
	{ 1226, 0, "1226-Plaine-St Pierre", "", "  ", 43.2938800063, 5.38672987972 },
	{ 1228, 0, "1228-La Plaine Sud", "", "  ", 43.2944107821, 5.38545312564 },
	{ 1230, 0, "1230-Roosevelt - Reformes", "", "  ", 43.2990809543, 5.38661231792 },
	{ 1245, 0, "1245-Gambetta - Lafayette", "", "  ", 43.2990279383, 5.38150004673 },
	{ 2012, 0, "2012-Grand Rue", "", "  ", 43.2978095561, 5.37083509373 },
	{ 2030, 0, "2030-Republique Dames", "", "  ", 43.3025502837, 5.36949742819 },
	{ 2031, 0, "2031 - Schumann Leca", "", "  ", 43.3013667113, 5.36618441943 },
	{ 2179, 0, "2179-Quai Du Port", "", "  ", 43.295341504, 5.36523850862 },
	{ 2184, 0, "2184-Republique-Cathala", "", "  ", 43.300562012, 5.37048813461 },
	{ 2221, 0, "2221-91 Libération", "", "  ", 43.3005065096, 5.38929828518 },
	{ 2222, 0, "2222-151 Liberation", "", "  ", 43.3014318752, 5.39217938333 },
	{ 2240, 0, "2240-Dames - Terras", "", "  ", 43.3018057412, 5.37230225573 },
	{ 4022, 0, "4022-Sakakini Foch", "", "  ", 43.2995227479, 5.40112714211 },
	{ 4057, 0, "4057-Place Sebastopol", "", "  ", 43.2986808799, 5.39721623378 },
	{ 4111, 0, "4111-Foch Fayolle", "", "  ", 43.3011855155, 5.39863031171 },
	{ 4238, 0, "4238-Liberation-Chape-Esperandieu", "", "  ", 43.3020081437, 5.39468490636 },
	{ 5024, 0, "5024-Baille Pauriol", "", "  ", 43.2878144559, 5.3913313928 },
	{ 5060, 0, "5060-Sakakini Chave", "", "  ", 43.2957095684, 5.3998770703 },
	{ 5103, 0, "5103-Rue Georges", "", "  ", 43.2974861126, 5.39780503676 },
	{ 5106, 0, "5106-Jean Moulin Baille", "", "  ", 43.29024078, 5.39960982406 },
	{ 5107, 0, "5107-Baille Conception", "", "  ", 43.2887266909, 5.39403885378 },
	{ 5220, 0, "5220-Roosevelt - Oran", "", "  ", 43.2989919565, 5.38879911529 },
	{ 6020, 0, "6020-Place De La Corderie", "", "  ", 43.2907643324, 5.3722599324 },
	{ 6100, 0, "6100-Paul Peytral", "", "  ", 43.2899858791, 5.37912464186 },
	{ 6113, 0, "6113-Lodi Village", "", "  ", 43.2886166718, 5.38777964271 },
	{ 6114, 0, "6114-Julien Barthelemy", "", "  ", 43.2926045981, 5.38413843526 },
	{ 6154, 0, "6154-Pierre Puget Breteuil", "", "  ", 43.2903297702, 5.37554834185 },
	{ 6160, 0, "6160-153 Paradis", "", "  ", 43.2868383512, 5.37945018017 },
	{ 6176, 0, "6176-Cantini Rouet", "", "  ", 43.2847759836, 5.38559376362 },
	{ 6177, 0, "6177-Baille Friedland", "", "  ", 43.2865946021, 5.38678589002 },
	{ 6187, 0, "6187-Delpuech Corinthe", "", "  ", 43.2829293026, 5.39109605124 },
	{ 6206, 0, "6206-Toulon - Menpenti", "", "  ", 43.2844560971, 5.39211276734 },
	{ 6208, 0, "6208-Rouet", "", "  ", 43.2835014485, 5.38646152233 },
	{ 6209, 0, "6209-Salvator - Gondard", "", "  ", 43.2911267223, 5.38170871132 },
	{ 6217, 0, "6217-Rostand - Prefecture", "", "  ", 43.2896832564, 5.37965023647 },
	{ 6237, 0, "6237-Lieutaud Julien", "", "  ", 43.2921244874, 5.38299269173 },
	{ 7025, 0, "7025-Livon Pasteur", "", "  ", 43.2919890825, 5.35782316122 },
	{ 7026, 0, "7026-Catalans Corniche", "", "  ", 43.2898562015, 5.35596290321 },
	{ 7027, 0, "7027-Place Du 4 Septembre", "", "  ", 43.2884327278, 5.35862073513 },
	{ 7062, 0, "7062-88 Corniche - Kennedy", "", "  ", 43.2842139794, 5.34969647547 },
	{ 7064, 0, "7064-Corniche  Le Prophete", "", "  ", 43.2737083172, 5.36260827509 },
	{ 7138, 0, "7138-Corniche  Endoume", "", "  ", 43.2825063347, 5.35062842503 },
	{ 7142, 0, "7142-Corniche Rapatries", "", "  ", 43.2701722626, 5.36523990697 },
	{ 7146, 0, "7146-Livon Vieux Port", "", "  ", 43.2922453218, 5.36022485322 },
	{ 7151, 0, "7151-Pasteur", "", "  ", 43.2907168343, 5.35925801451 },
	{ 7153, 0, "7153-Corse St Maurice", "", "  ", 43.2894676089, 5.36370990786 },
	{ 7212, 0, "7212-Sainte - Notre Dame", "", "  ", 43.2916347097, 5.37137038486 },
	{ 7214, 0, "7214-Pkg Corderie", "", "  ", 43.2902770223, 5.36945210415 },
	{ 7215, 0, "7215-Endoume - Corderie", "", "  ", 43.2892367549, 5.36647973028 },
	{ 8053, 0, "8053-Prado - Perier", "", "  ", 43.2797421461, 5.38743104726 },
	{ 8065, 0, "8065-Promenade Pompidou Palm Beach", "", "  ", 43.2672725157, 5.37208852426 },
	{ 8066, 0, "8066-Mendes France Huveaune", "", "  ", 43.2602178538, 5.37544360266 },
	{ 8067, 0, "8067-Prado Gabes", "", "  ", 43.2668438148, 5.38279581908 },
	{ 8068, 0, "8068-Prado Borelly", "", "  ", 43.2624559209, 5.37579581617 },
	{ 8078, 0, "8078-Vieille Chapelle", "", "  ", 43.2478999477, 5.37444748476 },
	{ 8093, 0, "8093-Hambourg Rond Point Guerre", "", "  ", 43.2498678746, 5.3894116483 },
	{ 8131, 0, "8131-Promenade Pompidou David", "", "  ", 43.2617820218, 5.37450515258 },
	{ 8134, 0, "8134-Rond Point Du Prado", "", "  ", 43.2727873445, 5.39104874448 },
	{ 8144, 0, "8144-Escale Borely Pointe Rouge", "", "  ", 43.2539437255, 5.37599738916 },
	{ 8145, 0, "8145-Escale Borely", "", "  ", 43.2550559785, 5.37641302365 },
	{ 8149, 0, "8149-391 Michelet", "", "  ", 43.2540272781, 5.40187359469 },
	{ 8202, 0, "8202-397 Prado", "", "  ", 43.2686990085, 5.38555221654 },
	{ 8246, 0, "8246-Paradis - Lord Duveen", "", "  ", 43.2756181478, 5.38445514774 },
	{ 9074, 0, "9074-Michelet Luce", "", "  ", 43.2585087948, 5.39891393087 },
	{ 9085, 0, "9085-Schloesing Teissere", "", "  ", 43.2693522531, 5.40274096224 },
	{ 9087, 0, "9087-Mazargues", "", "  ", 43.2509038696, 5.40324461649 },
	{ 9219, 0, "9219-Pugette - Andre", "", "  ", 43.2684051407, 5.40063537111 },
	{ 1196, 0, "1196-Rue De Rome", "", "  ", 43.2934973166, 5.37928616378 },
	{ 8132, 0, "8132-Promenade Pompidou Amiral Muselier", "", "  ", 43.2646940721, 5.37328110813 },
	{ 6254, 0, "6254-Rome - Berlioz - Italie", "", "  ", 43.2889200086, 5.38310574213 },
	{ 8255, 0, "8255-Prado - Paradis", "", "  ", 43.2695417969, 5.38627377944 },
	{ 8262, 0, "8262-Mazargues-Barral", "", "  ", 43.2639994558, 5.39240235831 },
	{ 9259, 0, "9259-Lancier-Martheline", "", "  ", 43.2474636129, 5.39711956381 },
	{ 1005, 0, "1005-Centre Bourse", "", "  ", 43.2971380047, 5.37710306196 },
	{ 8148, 0, "8148-Michelet Barral", "", "  ", 43.2651937178, 5.39530830949 },
	{ 8257, 0, "8257-Rabatau - Teisseire", "", "  ", 43.2752426925, 5.39640980614 },
	{ 8261, 0, "8261- 318 Mazargues", "", "  ", 43.2606996091, 5.39397389933 },
	{ 8279, 0, "8279- Clot Bey Daumier", "", "  ", 43.260666384, 5.38722967309 },
	{ 8289, 0, "8289- Pointe Rouge - Régates", "", "  ", 43.2439193983, 5.37116195678 },
	{ 9207, 0, "9207- Teisseire - Roubaud", "", "  ", 43.2725236709, 5.39968606241 },
	{ 8147, 0, "8147 - Michelet Huveaune", "", "  ", 43.2679654997, 5.39396701684 },
	{ 8265, 0, "8265- Négresko - Paulet", "", "  ", 43.2693185564, 5.38938754231 },
	{ 8290, 0, "8290- Pointe Rouge - Montredon", "", "  ", 43.243802056, 5.37054075664 },
	{ 9260, 0, "9260- Mazargues - Almeras", "", "  ", 43.250962851, 5.39517783172 },
	{ 4293, 0, "4293- Blancarde", "", "  ", 43.2962634052, 5.40600080338 },
	{ 5104, 0, "5104-Chave Eugène Pierre", "", "  ", 43.2953631454, 5.39087139017 },
	{ 5280, 0, "5280-Chave Camas", "", "  ", 43.2958110232, 5.39631219912 },
	{ 1275, 0, "1275- Julien - 3 Mages", "", "  ", 43.2956215918, 5.3823904011 },
	{ 1287, 0, "1287- Stalingrad - Réformés", "", "  ", 43.2995209756, 5.38504744864 },
	{ 6009, 0, "6009- Place De Rome", "", "  ", 43.2913866146, 5.38078691824 },
	{ 1297, 0, "1297- St Férréol Davso", "", "  ", 43.2934857362, 5.37842379972 },
	{ 1299, 0, "1299- St Charles Voltaire Liberté", "", "  ", 43.3023665575, 5.38395503254 },
	{ 1301, 0, "1301- St Charles Marseillaises", "", "  ", 43.3015102787, 5.37989570205 },
	{ 2032, 0, "2032- Dames  Schumann", "", "  ", 43.3033116729, 5.36673035952 },
	{ 2272, 0, "2272- Joliette-Dunkerque", "", "  ", 43.3051302608, 5.36697414687 },
	{ 6023, 0, "6023- Castellane", "", "  ", 43.2860463621, 5.3832855751 },
	{ 2341, 0, "2341- Joliette Forbin", "", "  ", 43.3047137106, 5.36771555893 },
	{ 8313, 0, "8313- Parc Pastre", "", "  ", 43.2398425234, 5.36650659965 },
	{ 1302, 0, "1302-Colbert -Sainte Barbe", "", "  ", 43.2992460347, 5.37474004733 },
	{ 2323, 0, "2323 -Forbin Paris", "", "  ", 43.3059889568, 5.37224035119 },
	{ 2327, 0, "2327- République Plumier", "", "  ", 43.3041901559, 5.36778640789 },
	{ 8309, 0, "8309- Prado Duveen", "", "  ", 43.2765470225, 5.38879964968 },
	{ 8308, 0, "8308-Prado Latil", "", "  ", 43.2743522697, 5.39040590659 },
	{ 1264, 0, "1264 - Canebière Dugommier", "", "  ", 43.2978963133, 5.38113221556 },
	{ 2304, 0, "2304 - République Moisson", "", "  ", 43.3017977481, 5.36971621812 },
	{ 1343, 0, "1343 - Flammarion Grobet", "Bd Flammarion, Angle Grobet", "Bd Flammarion, Angle Grobet  ", 43.3046818705, 5.39014837811 },
	{ 1344, 0, "1344 - Flammarion National", "Bd National, Angle Flammarion", "Bd National, Angle Flammarion  ", 43.3035394613, 5.38635677106 },
	{ 4342, 0, "4342 - Flammarion Montrichet", "Place Le Verrier, Angle Flammarion Montrichet", "Place Le Verrier, Angle Flammarion Montrichet  ", 43.3061241524, 5.39319268237 },
	{ 5284, 0, "5284 - Baille-Hopital-Conception", "", "  ", 43.2897052141, 5.39757470966 },
	{ 1345, 0, "1345 - Saint Charles Leclerc Zattara", "", "  ", 43.3038027664, 5.37769013612 },
//	{ 602, 0, "Point 4 / Mimines", "", "  ", 43.5294309859, 5.43919801638 },
	{ 3320, 0, "3320 - Belle De Mai Cadenat", "", "  ", 43.3118196459, 5.38737567843 },
	{ 3321, 0, "3321 - Belle De Mai Friche", "", "  ", 43.3095177795, 5.39022101749 },
	{ 1316, 0, "1316 -St Charles Faculté", "", "  ", 43.3030175384, 5.37906449099 },
	{ 5058, 0, "5058 -Sakakini - Saint Pierre", "", "  ", 43.2928008635, 5.40128528646 },
	{ 1346, 0, "1346- Republique Coutellerie", "", "  ", 43.296824935, 5.37386088619 },
	{0, 0, NULL, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateMarseille : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateMarseille() {
    rect = QRectF(QPointF(43.238402980905, 5.348570388909), QPointF(43.313259188305, 5.407126889936));
    center = QPointF(43.275831084605, 5.377848639422);
    statusUrl = "http://www.levelo-mpm.fr/service/stationdetails/%1";
    infosUrl = "http://www.levelo-mpm.fr/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Marseille %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_MARSEILLE_H */

