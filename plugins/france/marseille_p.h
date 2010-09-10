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
        double x;
        double y;
} stations[] = {
	{ 1001, 0, "1001 - Canebiere Reine Elizabeth", "", 43.295686, 5.375340 },
	{ 1002, 0, "1002-Hotel De Ville", "", 43.296084, 5.370805 },
	{ 1003, 0, "1003-Place Aux Huiles", "", 43.293122, 5.371868 },
	{ 1004, 0, "1004-General De Gaulle Paradis", "", 43.294947, 5.376027 },
	{ 1006, 0, "1006-Cours Jean Ballard", "", 43.293368, 5.374638 },
	{ 1130, 0, "1130- 1 National Longchamp", "", 43.301233, 5.387773 },
	{ 1156, 0, "1156-Quai Des Belges Pytheas", "", 43.294227, 5.374474 },
	{ 1191, 0, "1191-Canebiere-St Ferreol", "", 43.296208, 5.376931 },
	{ 1210, 0, "1210-Beauvau - Canebiere", "", 43.295421, 5.375165 },
	{ 1211, 0, "1211-Beauvau - Suffren", "", 43.294775, 5.375131 },
	{ 1213, 0, "1213-Grignan - Marcelle Paul", "", 43.291357, 5.373547 },
	{ 1224, 0, "1224-Plaine - Bibliotheque", "", 43.295825, 5.385996 },
	{ 1226, 0, "1226-Plaine-St Pierre", "", 43.293880, 5.386730 },
	{ 1228, 0, "1228-La Plaine Sud", "", 43.294411, 5.385453 },
	{ 1230, 0, "1230-Roosevelt - Reformes", "", 43.299081, 5.386612 },
	{ 1245, 0, "1245-Gambetta - Lafayette", "", 43.299028, 5.381500 },
	{ 2012, 0, "2012-Grand Rue", "", 43.297810, 5.370835 },
	{ 2030, 0, "2030-Republique Dames", "", 43.302550, 5.369497 },
	{ 2031, 0, "2031 - Schumann Leca", "", 43.301367, 5.366184 },
	{ 2179, 0, "2179-Quai Du Port", "", 43.295342, 5.365239 },
	{ 2184, 0, "2184-Republique-Cathala", "", 43.300562, 5.370488 },
	{ 2221, 0, "2221-91 Libération", "", 43.300507, 5.389298 },
	{ 2222, 0, "2222-151 Liberation", "", 43.301432, 5.392179 },
	{ 2240, 0, "2240-Dames - Terras", "", 43.301806, 5.372302 },
	{ 4022, 0, "4022-Sakakini Foch", "", 43.299523, 5.401127 },
	{ 4057, 0, "4057-Place Sebastopol", "", 43.298681, 5.397216 },
	{ 4111, 0, "4111-Foch Fayolle", "", 43.301186, 5.398630 },
	{ 4238, 0, "4238-Liberation-Chape-Esperandieu", "", 43.302008, 5.394685 },
	{ 5024, 0, "5024-Baille Pauriol", "", 43.287814, 5.391331 },
	{ 5060, 0, "5060-Sakakini Chave", "", 43.295710, 5.399877 },
	{ 5103, 0, "5103-Rue Georges", "", 43.297486, 5.397805 },
	{ 5106, 0, "5106-Jean Moulin Baille", "", 43.290241, 5.399610 },
	{ 5107, 0, "5107-Baille Conception", "", 43.288727, 5.394039 },
	{ 5220, 0, "5220-Roosevelt - Oran", "", 43.298992, 5.388799 },
	{ 6020, 0, "6020-Place De La Corderie", "", 43.290764, 5.372260 },
	{ 6100, 0, "6100-Paul Peytral", "", 43.289986, 5.379125 },
	{ 6113, 0, "6113-Lodi Village", "", 43.288617, 5.387780 },
	{ 6114, 0, "6114-Julien Barthelemy", "", 43.292605, 5.384138 },
	{ 6154, 0, "6154-Pierre Puget Breteuil", "", 43.290330, 5.375548 },
	{ 6160, 0, "6160-153 Paradis", "", 43.286838, 5.379450 },
	{ 6176, 0, "6176-Cantini Rouet", "", 43.284776, 5.385594 },
	{ 6177, 0, "6177-Baille Friedland", "", 43.286595, 5.386786 },
	{ 6187, 0, "6187-Delpuech Corinthe", "", 43.282929, 5.391096 },
	{ 6206, 0, "6206-Toulon - Menpenti", "", 43.284456, 5.392113 },
	{ 6208, 0, "6208-Rouet", "", 43.283501, 5.386462 },
	{ 6209, 0, "6209-Salvator - Gondard", "", 43.291127, 5.381709 },
	{ 6217, 0, "6217-Rostand - Prefecture", "", 43.289683, 5.379650 },
	{ 6237, 0, "6237-Lieutaud Julien", "", 43.292124, 5.382993 },
	{ 7025, 0, "7025-Livon Pasteur", "", 43.291989, 5.357823 },
	{ 7026, 0, "7026-Catalans Corniche", "", 43.289856, 5.355963 },
	{ 7027, 0, "7027-Place Du 4 Septembre", "", 43.288433, 5.358621 },
	{ 7062, 0, "7062-88 Corniche - Kennedy", "", 43.284214, 5.349696 },
	{ 7064, 0, "7064-Corniche  Le Prophete", "", 43.273708, 5.362608 },
	{ 7138, 0, "7138-Corniche  Endoume", "", 43.282506, 5.350628 },
	{ 7142, 0, "7142-Corniche Rapatries", "", 43.270172, 5.365240 },
	{ 7146, 0, "7146-Livon Vieux Port", "", 43.292245, 5.360225 },
	{ 7151, 0, "7151-Pasteur", "", 43.290717, 5.359258 },
	{ 7153, 0, "7153-Corse St Maurice", "", 43.289468, 5.363710 },
	{ 7212, 0, "7212-Sainte - Notre Dame", "", 43.291635, 5.371370 },
	{ 7214, 0, "7214-Pkg Corderie", "", 43.290277, 5.369452 },
	{ 7215, 0, "7215-Endoume - Corderie", "", 43.289237, 5.366480 },
	{ 8053, 0, "8053-Prado - Perier", "", 43.279742, 5.387431 },
	{ 8065, 0, "8065-Promenade Pompidou Palm Beach", "", 43.267273, 5.372089 },
	{ 8066, 0, "8066-Mendes France Huveaune", "", 43.260218, 5.375444 },
	{ 8067, 0, "8067-Prado Gabes", "", 43.266844, 5.382796 },
	{ 8068, 0, "8068-Prado Borelly", "", 43.262456, 5.375796 },
	{ 8078, 0, "8078-Vieille Chapelle", "", 43.247900, 5.374447 },
	{ 8093, 0, "8093-Hambourg Rond Point Guerre", "", 43.249868, 5.389412 },
	{ 8131, 0, "8131-Promenade Pompidou David", "", 43.261782, 5.374505 },
	{ 8134, 0, "8134-Rond Point Du Prado", "", 43.272787, 5.391049 },
	{ 8144, 0, "8144-Escale Borely Pointe Rouge", "", 43.253944, 5.375997 },
	{ 8145, 0, "8145-Escale Borely", "", 43.255056, 5.376413 },
	{ 8149, 0, "8149-391 Michelet", "", 43.254027, 5.401874 },
	{ 8202, 0, "8202-397 Prado", "", 43.268699, 5.385552 },
	{ 8246, 0, "8246-Paradis - Lord Duveen", "", 43.275618, 5.384455 },
	{ 9074, 0, "9074-Michelet Luce", "", 43.258509, 5.398914 },
	{ 9085, 0, "9085-Schloesing Teissere", "", 43.269352, 5.402741 },
	{ 9087, 0, "9087-Mazargues", "", 43.250904, 5.403245 },
	{ 9219, 0, "9219-Pugette - Andre", "", 43.268405, 5.400635 },
	{ 1196, 0, "1196-Rue De Rome", "", 43.293497, 5.379286 },
	{ 8132, 0, "8132-Promenade Pompidou Amiral Muselier", "", 43.264694, 5.373281 },
	{ 6254, 0, "6254-Rome - Berlioz - Italie", "", 43.288920, 5.383106 },
	{ 8255, 0, "8255-Prado - Paradis", "", 43.269542, 5.386274 },
	{ 8262, 0, "8262-Mazargues-Barral", "", 43.263999, 5.392402 },
	{ 9259, 0, "9259-Lancier-Martheline", "", 43.247464, 5.397120 },
	{ 1005, 0, "1005-Centre Bourse", "", 43.297138, 5.377103 },
	{ 8148, 0, "8148-Michelet Barral", "", 43.265194, 5.395308 },
	{ 8257, 0, "8257-Rabatau - Teisseire", "", 43.275243, 5.396410 },
	{ 8261, 0, "8261- 318 Mazargues", "", 43.260700, 5.393974 },
	{ 8279, 0, "8279- Clot Bey Daumier", "", 43.260666, 5.387230 },
	{ 8289, 0, "8289- Pointe Rouge - Régates", "", 43.243919, 5.371162 },
	{ 9207, 0, "9207- Teisseire - Roubaud", "", 43.272524, 5.399686 },
	{ 8147, 0, "8147 - Michelet Huveaune", "", 43.267965, 5.393967 },
	{ 8265, 0, "8265- Négresko - Paulet", "", 43.269319, 5.389388 },
	{ 8290, 0, "8290- Pointe Rouge - Montredon", "", 43.243802, 5.370541 },
	{ 9260, 0, "9260- Mazargues - Almeras", "", 43.250963, 5.395178 },
	{ 4293, 0, "4293- Blancarde", "", 43.296263, 5.406001 },
	{ 5104, 0, "5104-Chave Eugène Pierre", "", 43.295363, 5.390871 },
	{ 5280, 0, "5280-Chave Camas", "", 43.295811, 5.396312 },
	{ 1275, 0, "1275- Julien - 3 Mages", "", 43.295622, 5.382390 },
	{ 1287, 0, "1287- Stalingrad - Réformés", "", 43.299521, 5.385047 },
	{ 6009, 0, "6009- Place De Rome", "", 43.291387, 5.380787 },
	{ 1297, 0, "1297- St Férréol Davso", "", 43.293486, 5.378424 },
	{ 1299, 0, "1299- St Charles Voltaire Liberté", "", 43.302367, 5.383955 },
	{ 1301, 0, "1301- St Charles Marseillaises", "", 43.301510, 5.379896 },
	{ 2032, 0, "2032- Dames  Schumann", "", 43.303312, 5.366730 },
	{ 2272, 0, "2272- Joliette-Dunkerque", "", 43.305130, 5.366974 },
	{ 6023, 0, "6023- Castellane", "", 43.286046, 5.383286 },
	{ 2341, 0, "2341- Joliette Forbin", "", 43.304714, 5.367716 },
	{ 8313, 0, "8313- Parc Pastre", "", 43.239843, 5.366507 },
	{ 1302, 0, "1302-Colbert -Sainte Barbe", "", 43.299246, 5.374740 },
	{ 2323, 0, "2323 -Forbin Paris", "", 43.305989, 5.372240 },
	{ 2327, 0, "2327- République Plumier", "", 43.304190, 5.367786 },
	{ 8309, 0, "8309- Prado Duveen", "", 43.276547, 5.388800 },
	{ 8308, 0, "8308-Prado Latil", "", 43.274352, 5.390406 },
	{ 1264, 0, "1264 - Canebière Dugommier", "", 43.297896, 5.381132 },
	{ 2304, 0, "2304 - République Moisson", "", 43.301798, 5.369716 },
	{ 1343, 0, "1343 - Flammarion Grobet", "Bd Flammarion, Angle Grobet", 43.304682, 5.390148 },
	{ 1344, 0, "1344 - Flammarion National", "Bd National, Angle Flammarion", 43.303539, 5.386357 },
	{ 4342, 0, "4342 - Flammarion Montrichet", "Place Le Verrier, Angle Flammarion Montrichet", 43.306124, 5.393193 },
	{ 5284, 0, "5284 - Baille-Hopital-Conception", "", 43.289705, 5.397575 },
	{ 1345, 0, "1345 - Saint Charles Leclerc Zattara", "", 43.303803, 5.377690 },
//	{ 602, 0, "Point 4 / Mimines", "", 43.529431, 5.439198 },
	{ 3320, 0, "3320 - Belle De Mai Cadenat", "", 43.311820, 5.387376 },
	{ 3321, 0, "3321 - Belle De Mai Friche", "", 43.309518, 5.390221 },
	{ 1316, 0, "1316 -St Charles Faculté", "", 43.303018, 5.379064 },
	{ 5058, 0, "5058 -Sakakini - Saint Pierre", "", 43.292801, 5.401285 },
	{ 1346, 0, "1346- Republique Coutellerie", "", 43.296825, 5.373861 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateMarseille : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateMarseille() {
    rect = QRectF(QPointF(43.097612, 5.349696), QPointF(43.311820, 5.581042));
    center = QPointF(43.297612, 5.381042);
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

