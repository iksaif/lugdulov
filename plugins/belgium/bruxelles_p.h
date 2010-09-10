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

#ifndef STATIONS_SIMPLE_PRIVATE_BRUXELLES_H
#define STATIONS_SIMPLE_PRIVATE_BRUXELLES_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 99, 0, "99 - Jubile/Jubile", "Jubile - Boulevard Du Jubile/ Jubelfeestlaan 79", 50.865036, 4.338339 },
	{ 83, 0, "083 - Simonis/Simonis", "Simonis / Bd Leopold Ii (Devant 282)/ Leopold Ii-Laan (N° 282)", 50.863056, 4.331167 },
	{ 84, 0, "084 - Ste Anne/Sint-Anna", "Ste Anne/Sint-Anna  -  Rue De L'Eglise Ste Anne/Sint-Annakerkstraat 116", 50.860534, 4.331422 },
	{ 85, 0, "085 - Etangs Noirs/Zwarte Vijvers", "Etangs Noirs /Zwarte Vijvers - Chee De Gand/Steenweg Op Gent", 50.857266, 4.332368 },
	{ 86, 0, "086 - Maison Communal De Jette/Gemeentehuis Jette", "Maison Communale De Jette / Gemeentehuis Van Jette - Chaussee De Wemmel/Wemmelsesteenweg 102", 50.876457, 4.324577 },
	{ 89, 0, "089 - Athenee De Jette/Atheneum Van Jette", "Athenee De Jette/Atheneum Van Jette - Avenue De Levis Mirepoix / De Levis Mirepoixlaan 100", 50.871193, 4.329925 },
	{ 100, 0, "100 - Gare Du Luxembourg/Station Luxembourg", "Gare Du Luxembourg/Station  Luxembourg - Rue De Treves / Trierstraat", 50.838570, 4.373207 },
	{ 101, 0, "101 - Parnasse/Parnassus", "Parnasse/Parnassus - Rue Du Trone (Devant 111 - 113) / Troonstraat  (N° 111-113)", 50.837063, 4.370056 },
	{ 102, 0, "102 - Museum/Museum", "Museum - Chaussee De Wavre (Face 229 - 233)  /  Waversesteenweg (Tegenover 229 - 233)", 50.835853, 4.375940 },
	{ 103, 0, "103 - Ernest Solvay/Ernest Solvay", "Ernest Solvay - Rue De L'Arbre Benit/Gewijde Boomstraat 2-4-6", 50.834952, 4.364019 },
	{ 104, 0, "104 - Fernand Cocq/Fernand Cocq", "Fernand Cocq - Place Fernand Cocq (Face Au 19-23) / Fernand Cocqplein (Tegenover 19 - 23)", 50.833362, 4.367128 },
	{ 105, 0, "105 - De Hennin", "De Hennin -  Chaussee D'Ixelles/Elsense Steenweg 254 - 260", 50.830137, 4.369511 },
	{ 106, 0, "106 - Germoir/Mouterij", "Germoir/Mouterij - Avenue De La Couronne/Kroonlaan 92-94-96", 50.829906, 4.378954 },
	{ 107, 0, "107 - Defacqz/Defacqz", "Defacqz - Rue Defacqz/ Defacqzstraat 25-27-29", 50.828142, 4.359554 },
	{ 108, 0, "108 - Flagey/Flagey", "Flagey - Place Flagey (Face 11)/Eugene Flageyplein (Tegenover 11)", 50.827923, 4.371915 },
	{ 109, 0, "109 - Chatelain/Kastelein", "Chatelain/Kastelein - Rue De L'Aqueduc /Aquaductstraat 115-117-119", 50.824131, 4.360071 },
	{ 110, 0, "110 - Rodin/Rodin", "Rodin - Avenue De La Couronne (Devant 145 D) / Kroonlaan (N° 145 D)", 50.827464, 4.382116 },
	{ 111, 0, "111 - Leemans/Leemans", "Leemans - Place Albert Leemans/Albert Leemansplein 13/14", 50.822218, 4.363532 },
	{ 112, 0, "112 - Page/Edelknaap", "Page-Edelknaap  -  Chaussee De Waterloo/  Waterloose Steenweg 440 - 442", 50.821567, 4.356647 },
	{ 113, 0, "113 - Abbaye De La Cambre / Abdij Ter Kameren", "Abbaye De La Cambre/Abdij Ter Kameren - Avenue Emile Duray (Face Au N° 2) /Emile Duraylaan (Tegenover N° 2)", 50.819950, 4.375362 },
	{ 114, 0, "114 - De Beco/De Beco", "De Beco  -  Avenue Emile De Beco (N° 128) / Emile De Becolaan (N° 128)", 50.820773, 4.384763 },
	{ 115, 0, "115 - Petite Suisse/Klein Zwitserland", "Petite Suisse / Klein Zwitserland - Place De La Petite Suisse (Face 16-18) / Klein Zwitserlandplein (Tegenover 16 - 18)", 50.818042, 4.385618 },
	{ 116, 0, "116 - Fraiteur", "Fraiteur - Boulevard De La Plaine  (Entree Ulb) / Pleinlaan (Ingang Vub)", 50.818537, 4.395552 },
	{ 117, 0, "117 - Cimetiere D'Ixelles/Begraafplaats Elsene", "Cimetiere D'Ixelles / Begraafplaats Van Elsene - Avenue De L'Universite/Hogeschoollaan 1-3-5", 50.815726, 4.389625 },
	{ 118, 0, "118 - Buyl/Buyl", "Buyl -  Avenue Adolphe Buyl / Adolphe Buyllaan 1-3", 50.818015, 4.379840 },
	{ 119, 0, "119 - Paquot/Pacquot", "Paquot -  Rue Jean Paquot (44 A 48) /Jean Paquotstraat (44 T.E.M 48)", 50.825603, 4.379491 },
	{ 120, 0, "120 - Blyckaerts/Blyckaerts", "Blyckaerts - Place Raymond Blyckaerts/Raymond Blyckaertsplein", 50.833285, 4.374648 },
	{ 121, 0, "121 - Etangs / Vijvers", "Etangs / Vijvers - Rue Guillaume Stocq (Face Au N° 1-3-5)/ Guillaume Stocqstraat (Tegenover N° 1-3-5)", 50.824152, 4.374013 },
	{ 122, 0, "122 - Gare D'Etterbeek/Station Van Etterbeek", "Gare D'Etterbeek/Station Van Etterbeek - Boulevard General Jacques/Generaal Jacqueslaan", 50.822383, 4.389347 },
	{ 123, 0, "123 - Van Eyck/Van Eyck", "Van Eyck -  Chaussee De Vleurgat (Devant 215 - 217) / Vleurgatsesteenweg  (N° 215 - 217)", 50.820999, 4.366461 },
	{ 124, 0, "124 - Charles Graux", "Charles Graux - Chaussee De Waterloo (Devant N° 585 - 587)/ Waterloosesteenweg (N° 585 - 587)", 50.818567, 4.363015 },
	{ 125, 0, "125 - Georges Brugmann/Georges Brugmann", "Georges Brugmann - Place Georges Brugmann/Georges Brugmannplein N° 10 - 11", 50.816904, 4.353774 },
	{ 127, 0, "127 - Gray/Gray", "Gray  -  Rue Des Deux Ponts (Face 4)/ Tweebruggenstraat (Tegenover 4)", 50.832295, 4.377811 },
	{ 133, 0, "133 - Château/Kasteel", "Chateau-Kasteel - Avenue Du Château/Kasteellaan", 50.866980, 4.309109 },
	{ 134, 0, "134 - Place De Bastogne/Bastenaken", "Bastogne/Bastenaken - Place De Bastogne/Bastenakenplein", 50.862901, 4.316819 },
	{ 135, 0, "135 - Parc Lacroix/Lacroix Park", "Parc Lacroix / Lacroix Park - Av Princesse Elisabeth/Prinses Elisabethlaan", 50.872645, 4.376517 },
	{ 136, 0, "136 - Pavillon/Paviljoen", "Pavillon/Paviljoen - Place Pavillon /Paviljoenplaats 92-94-96", 50.870106, 4.371534 },
	{ 137, 0, "137 - Maison Communale De Schaerbeek", "Maison Communale De Schaerbeek/Gemeentehuis Van Schaarbeek - Rue Royale Sainte Marie/Koninklijke Sinte-Mariastraat 241-243-245", 50.866957, 4.373069 },
	{ 138, 0, "138 - Houffalize/Houffalize", "Houffalize - Place De Houffalize /Houffalizeplein 58", 50.865270, 4.378032 },
	{ 139, 0, "139 - Liedts/Liedts", "Liedts - Place Liedts (Face Au 38)/ Liedtsplein (Tegenover 38)", 50.863888, 4.366715 },
	{ 140, 0, "140 - Azalees/Azalea", "Azalees / Azalea - Avenue Des Azalees (Face 68) / Azalealaan (Tegenover 68)", 50.862892, 4.381178 },
	{ 141, 0, "141 - Gare Du Nord/Noordstation", "Gare Du Nord/Noordstation - Place Simon Bolivar/ Simon Bolivarlaan", 50.860644, 4.359001 },
	{ 142, 0, "142 - Bienfaiteurs/Weldoeners", "Bienfaiteurs/Weldoeners - Avenue Rogier / Rogierlaan 269/271", 50.857549, 4.386741 },
	{ 143, 0, "143 - Rtl/Rtl", "Rtl  - Chaussee De Louvain (Dvt 770)/ Leuvense Steenweg (N° 770)", 50.857456, 4.407489 },
	{ 144, 0, "144 - Sainte-Marie/Sinte-Maria", "Sainte Marie/Sinte-Maria - Rue Royale/ Koningsstraat 257 - 259", 50.857924, 4.368128 },
	{ 145, 0, "145 - Coteaux/Wijnheuvelen", "Coteaux/Wijnheuvelen - Avenue Rogier / Rogierlaan 128", 50.859172, 4.379148 },
	{ 146, 0, "146 - Leopold Iii/Leopold Iii", "Leopold Iii -  Boulevard Leopold Iii / Leopold Iii-Laan", 50.859600, 4.401097 },
	{ 147, 0, "147 - Emile Max Lycee/Lyceum Emile Max", "Emile Max Lycee/Lyceum Emile Max - Chaussee D'Haecht/ Haachtsesteenweg 226 - 230", 50.861989, 4.372190 },
	{ 148, 0, "148 - Gare Meiser/Meiser Station", "Gare Meiser / Meiser Station - Avenue Rogier/ Rogierlaan 377 - 379", 50.855712, 4.394250 },
	{ 149, 0, "149 - Jules Lebrun/Jules Lebrun", "Jules Lebrun - Chaussee De Louvain (Face 593) / Leuvense Steenweg (Tegenover 593)", 50.856399, 4.403296 },
	{ 150, 0, "150 - Meiser/Meiser", "Meiser - Place General Meiser (Face 1 - 3) / Generaal Meiserplein (Tegenover 1 - 3)", 50.854640, 4.398390 },
	{ 151, 0, "151 - Louvain 488-494/Leuven 488-494", "Louvain / Leuven - Chaussee De Louvain - Leuvensesteenweg  488-494", 50.853856, 4.394025 },
	{ 152, 0, "152 - Place Dailly/Daillyplein", "Place Dailly / Daillyplein - Place Dailly / Daillyplein 24 - 25", 50.852362, 4.387434 },
	{ 153, 0, "153 - Square Armand Steurs/Armand Steurssquare", "Square Armand Steurs/Armand Steurssquare - Avenue Paul Deschanel (Face N° 267 - 269) / Paul Deschanellaan (Tegenover 267 - 269)", 50.854325, 4.377787 },
	{ 154, 0, "154 - Plasky/Plasky", "Plasky - Square Eugene Plasky (Face 100) / Eugene Plaskysquare (Tegenover 100)", 50.851352, 4.396544 },
	{ 156, 0, "156 - Jambline De Meux/Jamblinne De Meux", "Jambline De Meux - Place Jamblinne De Meux / Jamblinne De Meuxplein 43 - 44 - 45", 50.847130, 4.393577 },
	{ 157, 0, "157 - Heliotropes/Heliotropen", "Heliotropes/Heliotropen - Boulevard Lambermont /  Lambermontlaan 374", 50.863374, 4.386305 },
	{ 158, 0, "158 - Van Ysendijck:Van Ysendijck", "Van Ysendijck - Avenue Voltaire (Face 6) / Voltairelaan (Tegenover 6)", 50.867923, 4.379665 },
	{ 159, 0, "159 - Masui/Masui", "Masui - Avenue De La Reine / Koninginnelaan 153", 50.869600, 4.362639 },
	{ 160, 0, "160 - Elisa/Elisa", "Elisa - Place Princesse Elisabeth / Prinses Elisabethplein 8 - 19", 50.877650, 4.380449 },
	{ 161, 0, "161 - Demolder/Demolder", "Demolder - Avenue Eugene Demolder / Eugene Demolderlaan 68", 50.872597, 4.379984 },
	{ 162, 0, "162 - Brabant/Brabant", "Brabant - Rue De Quatrecht/ Kwatrechtstraat 39", 50.861361, 4.363923 },
	{ 163, 0, "163 - Chazal/Chazal", "Chazal - Avenue Ernest Cambier (Face 7)/ Ernest Cambierlaan (Tegenover 7)", 50.859413, 4.391556 },
	{ 164, 0, "164 - Kennis/Kennis", "Kennis - Boulevard Lambermont (20 M Apres 284)/Lambermontlaan   (20 M Na N° 284)", 50.867483, 4.385839 },
	{ 165, 0, "165 - Cimetiere De Jette/ Begraafplaats Jette", "Cimetiere De Jette/Begraafplaats Van Jette - Bld De Smet De Naeyer (Face Au 322)/ De Smet De Naeyerstraat (Tegenover 322)", 50.879606, 4.334231 },
	{ 166, 0, "166 - Tref Centrum", "Tref Centrum - Rue Amelie Gomand 51- 45", 50.876208, 4.337272 },
	{ 167, 0, "167 - Charles V/Karel V", "Charles V/Karel V - Avenue Charles Quint/Keizer Karellaan 129-131", 50.869057, 4.309915 },
	{ 168, 0, "168 - Hopital Français/Frans Hospitaal", "Hopital Francais/Frans Hospitaal - Avenue Josse Goffin/Josse Goffinstraat 133-135", 50.866643, 4.303489 },
	{ 169, 0, "169 - G.Eeckhoud/ G . Eekhoud", "Eeckhoud - Avenue Georges Eekhoud/Georges Eekhoudlaan 56", 50.877607, 4.387638 },
	{ 170, 0, "170 - Riga/Riga", "Riga/Riga - Square Francois Riga / Francois Rigasquare", 50.874762, 4.385586 },
	{ 171, 0, "171 - Apollo/Apollo", "Apollo/Apollo - Square Apollo / Apollosquare", 50.872203, 4.392089 },
	{ 172, 0, "172 - Aeropolis/Aeropolis", "Aeropolis - Chaussee D'Haecht (Face 586) / Haachtsesteenweg (Tegenover 586)", 50.869724, 4.388117 },
	{ 173, 0, "173 - Bichon/Bichon", "Bichon - Place Bichon / Bichonplein", 50.865071, 4.394227 },
	{ 174, 0, "174 - Mennekens/Mennekens", "Mennekens - Avenue Brigade Piron (Face Aux 80 - 82 - 84)/ Brigade Pironlaan (Tegenover 80 - 82 - 84)", 50.854123, 4.316330 },
	{ 175, 0, "175 - Beekant", "Beekant - Boulevard Edmond Machtens / Edmond Machtenslaan", 50.854321, 4.322847 },
	{ 176, 0, "176 - Colonel Bourg/Kolonel Bourg", "Colonel Bourg/Kolonel Bourg - Rue Colonel Bourg/ Kolonel Bourgstraat 104", 50.852426, 4.408695 },
	{ 177, 0, "177 - Chasseurs Ardennais/Ardense Jagers", "Chasseurs Ardennais/Ardense Jagersplein - Rue Du Noyer 81-87 /Notelaarsstraat 81-87", 50.849476, 4.389400 },
	{ 178, 0, "178 - Diamant/Diamant", "Diamant/Diamant - Boulevard Auguste Reyers / Auguste Reyerslaan", 50.849234, 4.402473 },
	{ 179, 0, "179 - Celtes/Kelten", "Celtes/Kelten - Avenue De Tervueren (Face Au 17) / Tervurenlaan (Tegenover 17)", 50.839508, 4.398029 },
	{ 180, 0, "180 - Jourdan/Jourdan", "Jourdan/Jourdan - Rue Froissart (Face 3 - 5) / Froissartstraat (Tegenover 3 - 5)", 50.837638, 4.381594 },
	{ 181, 0, "181 - Louis Titz/Louis Titz", "Louis / Titz - Avenue De La Chasse/ Jachtlaan 182 - 184", 50.835730, 4.394261 },
	{ 182, 0, "182 - Boileau/Boileau", "Boileau/Boileau - Boulevard Saint Michel / Sint-Michielslaan", 50.831747, 4.404755 },
	{ 183, 0, "183 - La Chasse/Jacht", "La Chasse/Jacht - Avenue Des Casernes/ Kazernenlaan 4 - 6", 50.830146, 4.390532 },
	{ 184, 0, "184 - Philippe Baucq/Philippe Baucq", "Philippe Baucq - Rue Philippe Baucq / Philippe Baucqstraat 32 - 38", 50.831683, 4.385663 },
	{ 185, 0, "185 - Pere De Deken/Pater De Deken", "Pere De Deken/Pater De Deken - Rue Père De Deken/ Pater De Dekenstraat 40", 50.835915, 4.401512 },
	{ 186, 0, "186 - Etangs/Vijvers", "Etangs/Vijvers - Chaussee De Wavre / Waversesteenweg 490", 50.834178, 4.384890 },
	{ 187, 0, "187 - Arsenal/Arsenaal", "Arsenal/Arsenaal - Boulevard Louis Schmidt/ Louis Schmidtlaan 2", 50.826518, 4.397058 },
	{ 188, 0, "188 - Osseghem/Osseghem", "Osseghem -  Avenue Mahatma Gandhi/ Mahatma Gandhilaan 10", 50.857273, 4.324761 },
	{ 189, 0, "189 - Place Van Meyel/Van Meyelplein", "Place Van Meyel/Van Meyelplein", 50.835918, 4.387274 },
	{ 190, 0, "190 - Terdelt/Terdelt", "Terdelt/Terdelt  - Place Terdelt / Terdeltplein", 50.868079, 4.390658 },
	{ 25, 0, "025 - Porte D'Anderlecht / Anderlechtsepoort", "Porte D'Anderlecht/Anderlechtsepoort - Bld Poincare/ Poincarelaan 27/28/29", 50.844551, 4.338484 },
	{ 26, 0, "026 - Van Lint / Van Lint", "Van Lint - Rue Van Lint/ Van Lintstraat 6 - 8", 50.839550, 4.328933 },
	{ 27, 0, "027 - Square Albert I / Albert I Square", "Square Albert I / Albert I-Square 25 - 26 - 27", 50.839177, 4.322277 },
	{ 28, 0, "028 - Clemenceau / Clemenceau", "Clemenceau - Chee De Mons/ Bergense Steenweg 159-161-163", 50.842210, 4.330586 },
	{ 29, 0, "029 - Baudouin / Boudewijn", "Baudouin/Boudewijn - Rue De Laeken / Lakensestraat", 50.856769, 4.352850 },
	{ 30, 0, "030 - Laeken / Laken", "Laeken/Laken - Rue De Laeken (Entre N° 119 Et 109) / Lakensestraat (Tussen N° 119 En 109)", 50.854308, 4.352050 },
	{ 3, 0, "003 - Porte De Flandres / Vlaamsepoort", "Porte De Flandres/Vlaamsepoort - Bld De Nieuport/Nieuwpoortlaan 1", 50.853260, 4.341856 },
	{ 24, 0, "024 - Rogier / Rogier", "Rogier - Boulevard Du Jardin Botanique/Kruidtuinlaan", 50.855248, 4.358075 },
	{ 31, 0, "031 - Musee De La Bd / Stripmuseum", "Musee De La Bd/Stripmuseum - Boulevard Pacheco/Pachecolaan", 50.850796, 4.361122 },
	{ 32, 0, "032 - Dansaert / Dansaert", "Dansaert - Rue Antoine Dansaert/Antoine Dansaertstraat 60-62-64", 50.850189, 4.346166 },
	{ 33, 0, "033 - Mort Subite / Mort Subite", "Mort Subite - Rue Montagne Aux-Herbes-Potageres (Face N° 7)/Warmoesberg (Tegenover N°7)", 50.848630, 4.356125 },
	{ 4, 0, "004 - Jardin Aux Fleurs / Bloemenhof", "Jardin Aux Fleurs/Bloemenhof - Place Du Jardin Aux Fleurs/Bloemenhofplein", 50.847894, 4.343562 },
	{ 5, 0, "005 - Bourse / Beurs", "Bourse/Beurs - Rue Paul Devaux/Paul Devauxstraat", 50.848737, 4.349472 },
	{ 7, 0, "007 - Parc / Park", "Parc/Park - Rue Royale  (Face N°66-68)/Koningsstraat (Tegenover N°66-68)", 50.846436, 4.362473 },
	{ 34, 0, "034 - Fontainas / Fontainas", "Fontainas - Bld Anspach N°180 A 192/Anspachlaan N°180 Tot 192", 50.845702, 4.346933 },
	{ 35, 0, "035 - Cantersteen / Kantersteen", "Cantersteen/Kantersteen - Rue Cantersteen/Kantersteenstraat 41-43-45", 50.845730, 4.358225 },
	{ 8, 0, "008 - Arts-Loi / Kunst-Wet", "Arts-Loi/Kunst-Wet -  Avenue Des Arts/Kunstlaan 24", 50.846079, 4.368908 },
	{ 36, 0, "036 - Place St Jean / Sint-Jansplein", "Place St Jean/Sint-Jansplein - Rue Du Lombard/Lombardstraat 42", 50.845203, 4.351545 },
	{ 9, 0, "009 - Anneesens / Anneessens", "Anneesens - Bld Maurice Lemonnier/Maurice Lemonnierlaan 42-44-46", 50.843855, 4.345094 },
	{ 10, 0, "010 - Chapelle / Kapel", "Chapelle/Kapel - Place De La Chapelle/Kapelleplein", 50.841382, 4.351591 },
	{ 11, 0, "011 - Sablon / Zavel", "Sablon/Zavel - Rue De La Regence/Regentschapsstraat 20", 50.840037, 4.356513 },
	{ 12, 0, "012 - Trone / Troon", "Trone/Troon - Av. Des Arts/Kunstlaan, 58", 50.840617, 4.366156 },
	{ 13, 0, "013 - Lemonnier / Lemonnier", "Lemonnier - Bld. Maurice Lemonnier/De Maurice Lemonnierlaan 202-204-206", 50.840156, 4.341252 },
	{ 14, 0, "014 - Porte De Namur / Naamsepoort", "Porte De Namur/Naamsepoort - Bld Du Regent /Regentlaan 1", 50.839029, 4.362219 },
	{ 37, 0, "037 - Poelaert / Poelaert", "Poelaert - Place Poelaert/Poelaertplein 3", 50.838177, 4.352702 },
	{ 38, 0, "038 - Jeu De Balle / Vossenplein", "Jeu De Balle/Vossenplein - Rue Blaes/Blaesstraat 135-141", 50.837589, 4.346965 },
	{ 16, 0, "016 - Louise / Louiza", "Louise/Louiza - Place Louise/Louizaplein 53", 50.836046, 4.355476 },
	{ 39, 0, "039 - Hotel Des Monnaies / Munthotel", "Hotel Des Monnaies/Munthotel - Bld De Waterloo- Waterloolaan 93/94/95/96/98", 50.834446, 4.350795 },
	{ 40, 0, "040 - Porte De Hal / Hallepoort", "Porte De Hal/Hallepoort - Boulevard Du Midi/Zuidlaan 142", 50.834186, 4.342939 },
	{ 42, 0, "042 - Porte De Ninove /Ninoofsepoort", "Porte De Ninove/Ninoofsepoort - Place De Ninove/Ninoofseplein/Sur Bld De L'Abattoir/Op Slachthuislaan", 50.849308, 4.338484 },
	{ 18, 0, "018 - Gutenberg / Gutenberg", "Gutenberg - Square Gutenberg (Face N° 5)/Gutenbergssquare (Tegenover N° 5)", 50.848142, 4.377745 },
	{ 56, 0, "056 - Archimede / Archimedes", "Archimede/Archimedes - Rue Archimede/Archimedesstraat 58-64", 50.846035, 4.384097 },
	{ 79, 0, "079 - Loi / Wet", "Loi/Wet - Rue De Treves/Trierstraat 128-126", 50.844099, 4.375636 },
	{ 43, 0, "043 - Joseph Ii / Jozef Ii", "Joseph Ii/Jozef Ii - Rue Joseph Ii/Jozef Ii-Straat", 50.845625, 4.374293 },
	{ 61, 0, "061 - Maelbeek / Maalbeek", "Maelbeek/Maalbeek - Chaussee D'Etterbeek/Etterbeeksesteenweg 15", 50.843798, 4.378083 },
	{ 44, 0, "044 - Charlemagne / Karel De Grote", "Charlemagne/Karel De Grote - Rue De La Science/Wetenschapsstraat 11", 50.841999, 4.371040 },
	{ 62, 0, "062 - Cortenbergh / Kortenberg", "Cortenbergh/Kortenberg - Avenue De Cortenbergh/Kortenberglaan", 50.842833, 4.385010 },
	{ 66, 0, "066 - Schuman / Schuman", "Schuman - Rue De La Loi/Wetstraat 170", 50.843349, 4.379876 },
	{ 45, 0, "045 - Stephanie / Stefania", "Stephanie/Stefania - Av Louise/Louizalaan 61A-63-65", 50.833198, 4.357592 },
	{ 20, 0, "020 - Palais Royal / Koninklijk Paleis", "Palais Royal/Koningsstraat Paleis - Rue Royale (Devant N°14)/Koninklijkestraat (N°14)", 50.843239, 4.360414 },
	{ 46, 0, "046 - Albertine / Albertina", "Albertine/Albertina - Bld De L'Empereur/Keizerslaan 2", 50.843819, 4.355435 },
	{ 47, 0, "047 - Les Quais / Kaaien", "Les Quais/Kaaien - Quai A La Chaux/Kalkkaai 1-2", 50.854927, 4.347181 },
	{ 48, 0, "048 - Congres / Congres", "Congres - Rue Royale/Koningsstraat 144-146-148", 50.849525, 4.363611 },
	{ 23, 0, "023 - Agora / Agora", "Agora - Place Agora/Agoraplein 120", 50.846716, 4.354751 },
	{ 21, 0, "021 - De Brouckere / De Brouckere", "De Brouckere - Place De Brouckere/De Brouckereplein", 50.851879, 4.352753 },
	{ 22, 0, "022 - Jacqmain / Jacqmain", "Jacqmain - Bld. D'Anvers/Antwerpselaan", 50.855980, 4.355597 },
	{ 93, 0, "093 - Clovis / Clovis", "Clovis/Clovis - Chaussee De Louvain - Leuvensesteenweg 260-264", 50.850550, 4.381107 },
	{ 53, 0, "053 - Gare Du Midi / Zuidstation", "Gare Du Midi / Zuidstation - Place Victor Horta / Victor Hortaplein", 50.837278, 4.335765 },
	{ 64, 0, "064 - Veterinaires / Veeartsen", "Veterinaires/Veeartsen - Rue De France / Frankrijkstraat", 50.833092, 4.331011 },
	{ 58, 0, "058 - Gare Du Nord / Noordstation", "Gare Du Nord/Noordstation - Place Du Nord / Noordplaats", 50.859161, 4.359274 },
	{ 80, 0, "080 - Ceres/Ceres", "Ceres - Av. F. Roosevelt/F. Rooseveltlaan, 14", 50.815026, 4.376703 },
	{ 72, 0, "072 - Ulb F.Roosevelt / Vub F Roosevelt", "Ulb F.Roosevelt / Vub F.Roosevelt - Av. F.Roosevelt/F.Rooseveltlaan 19", 50.812566, 4.379146 },
	{ 71, 0, "071 - Legrand/Legrand", "Legrand - Av Louise/Louizalaan 525", 50.815547, 4.371835 },
	{ 68, 0, "068 - Jean Rey/Jean Rey", "Jean Rey - Place Jean Rey/Jean Reyplaats", 50.840454, 4.380294 },
	{ 49, 0, "049 - Willebroek/Willebroek", "Willebroeck/Willebroek - Quai De Willebroeck/Willebroekkaai 22 Bis", 50.860808, 4.350500 },
	{ 41, 0, "041 - Saint-Roch/Sint-Rochus", "Saint Roch/Sint-Rochus - Chaussee D'Anvers/Antwerpselaan 37", 50.859430, 4.354819 },
	{ 75, 0, "075 - General Baron/Generaal Baron", "General Baron/Generaal Baron - Av Du Parc / Parklaan 51 - 55", 50.826027, 4.340441 },
	{ 78, 0, "078 - Duc Petiaux/Duc Petiaux", "Duc Petiaux - Chaussee De Waterloo/ Waterloosesteenweg 376 - 370", 50.823807, 4.351723 },
	{ 77, 0, "077 - Paul Janson/Paul Janson", "Paul Janson - Chaussee De Charleroi/ Charleroisesteenweg 159", 50.826268, 4.354656 },
	{ 70, 0, "070 - Aurore/Dageraad", "Aurore/Dageraad - Avenue Louise/Louizalaan 440", 50.818361, 4.371539 },
	{ 69, 0, "069 - Lesbroussart/Lesbroussart", "Lesbroussart - Avenue Louise/Louizalaan 192", 50.827828, 4.363871 },
	{ 73, 0, "073 - Vleurgat/Vleurgat", "Vleurgat - Avenue Louise/Louizalaan 300", 50.824061, 4.367696 },
	{ 67, 0, "067 - Parc Cinquantenaire / Jubelpark", "Parc Cinquantenaire/Jubelpark - Avenue D'Auderghem/Oudergemsesteenweg 45", 50.839955, 4.385521 },
	{ 2, 0, "002 - Eloy/Eloy", "Eloy - Rue Eloy / Eloystraat", 50.836246, 4.326091 },
	{ 87, 0, "087 - Miroir/Spiegel", "Miroir/Spiegel - Avenue De Laeken (Face 36) / Lakense Laan (Tegenover 36)", 50.871677, 4.323870 },
	{ 88, 0, "088 - Woeste/Woeste", "Woeste - Avenue Notre Dame De Lourdes / Onze-Lieve-Vrouw Van Lourdeslaan", 50.873340, 4.334445 },
	{ 90, 0, "090 - Broustin/Broustin", "Broustin - Av De Jette/ Jetselaan 73 - 81", 50.867693, 4.326748 },
	{ 91, 0, "091 - Belgica/Belgica", "Belgica - Place Werrie/ Werrieplein 24", 50.867909, 4.335243 },
	{ 92, 0, "092 - Lenoir/Lenoir", "Lenoir - Bld De Smet De Naeyer/De Smet De Naeyerlaan 187 - 189", 50.875997, 4.330069 },
	{ 82, 0, "082 - Pannenhuis/Pannenhuis", "Pannenhuis/Pannenhuis - Rue Charles Demeer/Charles Demeerstraat  71", 50.873269, 4.341701 },
	{ 57, 0, "057 - Madou/Madou", "Madou - Rue Scailquin/Scailquinstraat", 50.849866, 4.369470 },
	{ 55, 0, "055 - Botanique/Kruidtuin", "Botanique/Kruidtuin - Avenue Galilee/Galileelaan", 50.853359, 4.366229 },
	{ 6, 0, "006 - Gare Centrale/Centraal Station", "Gare Centrale/Centraal Station - Bld De L'Imperatrice/Keizerinlaan", 50.846145, 4.356735 },
	{ 51, 0, "051 - Midi Fonsny/Zuid Fonsny", "Midi Fonsny/Zuid Fonsny - Rue D'Angleterre / Engelandstraat", 50.835991, 4.338649 },
	{ 52, 0, "052 - Sainctelette/Sainctelette", "Sainctelette - Place Sainctelette/Saincteletteplein", 50.859211, 4.345475 },
	{ 50, 0, "050 - Ribeaucourt/Ribaucourt", "Ribeaucourt - Bld Leopold Ii / Leopold Ii-Laan 121-123", 50.861166, 4.338809 },
	{ 54, 0, "054 - Tour Et Taxis/Thurn&Taxis", "Tour Et Taxis/Thurn&Taxis - Rue Picard/ Picardstraat 3", 50.863705, 4.345788 },
	{ 76, 0, "076 - Place Van Meenen/Van Meenenplein", "Place Van Meenen/Van Meenenplein - Av Paul Dejaer (Face 35 - 39) / Paul Dejaerlaan (Tegenover 35 - 39)", 50.825982, 4.345058 },
	{ 65, 0, "065 - Parvis De St Gilles/St-Gillisvoorplein", "Parvis De St Gilles/St-Gillisvoorplein - Chaussee De Waterloo/ Waterloosesteenweg 65-69", 50.830260, 4.344548 },
	{ 74, 0, "074 - Place Loix/Loixplein", "Place Loix/Loixplein - Rue Berckmans/ Berckmansstraat 78 - 84", 50.831949, 4.353128 },
	{ 19, 0, "019 - Place Morichar/Moricharplein", "Place Morichar / Moricharplein - Rue Des Etudiants/ Studentenstraat 32 - 34", 50.827982, 4.347740 },
	{ 59, 0, "059 - Place St-Josse/St Joostplein", "Place St-Josse/St-Joostplein  -  Rue Willems (Face 5 - 11) / Willemsstraat (Tegenover 5 - 11)", 50.849831, 4.375140 },
	{ 60, 0, "060 - St-Lazarre/St Lazarus", "St-Lazarre/Sint-Lazarus   -   Bld Saint-Lazarre/Sint-Lazaruslaan 4 -10", 50.857285, 4.361456 },
	{ 96, 0, "096 - Hotel President/President Hotel", "Hotel President/President Hotel - Boulevard Du Roi Albert Ii/Koning Albert-Ii Laan", 50.863769, 4.358704 },
	{ 95, 0, "095 - Place Bockstael/Bockstaelplaats", "Place Bockstael/Bockstaelplaats - Bld Emile Bockstael/Emile Bockstaellaan 254", 50.878212, 4.347851 },
	{ 97, 0, "097 - Karreveld/Karreveld", "Karreveld - Chaussee De Gand/ Gentsesteenweg 1-3", 50.858133, 4.318780 },
	{ 94, 0, "094 - Duchesse De Brabant/Hertogin Van Brabant", "Duchesse De Brabant/Hertogin Van Brabant - Rue De Birmingham / Birminghamstraat", 50.849400, 4.329168 },
	{ 98, 0, "098 - Cimetiere/Kerkhof", "Cimetiere/Kerkhof - Bld Mettewie/Mettewielaan", 50.859244, 4.312433 },
	{ 81, 0, "081 - Pont Bockstael/Brug Bockstael", "Pont Bockstael/Brug Bockstael - Bld Emile Bockstael/Emile Bockstaellaan 5", 50.870386, 4.343161 },
//	{ 191, 0, "191 - Artan", "Rue Clays", 27.140973, -3.404561 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateBruxelles : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateBruxelles() {
    rect = QRectF(QPointF(50.646281, 4.303489), QPointF(50.879606, 4.554727));
    center = QPointF(50.846281, 4.354727);
    statusUrl = "http://www.villo.be/service/stationdetails/%1";
    infosUrl = "http://www.villo.be/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Bruxelles %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_BRUXELLES_H */

