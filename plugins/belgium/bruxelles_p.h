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
	{ 99, 0, "99 - Jubile/Jubile", "Jubile - Boulevard Du Jubile/ Jubelfeestlaan 79", 50.8650361111, 4.33833888889 },
	{ 83, 0, "083 - Simonis/Simonis", "Simonis / Bd Leopold Ii (Devant 282)/ Leopold Ii-Laan (N° 282)", 50.8630556549, 4.33116685642 },
	{ 84, 0, "084 - Ste Anne/Sint-Anna", "Ste Anne/Sint-Anna  -  Rue De L'Eglise Ste Anne/Sint-Annakerkstraat 116", 50.8605340222, 4.33142211373 },
	{ 85, 0, "085 - Etangs Noirs/Zwarte Vijvers", "Etangs Noirs /Zwarte Vijvers - Chee De Gand/Steenweg Op Gent", 50.8572655241, 4.33236837869 },
	{ 86, 0, "086 - Maison Communal De Jette/Gemeentehuis Jette", "Maison Communale De Jette / Gemeentehuis Van Jette - Chaussee De Wemmel/Wemmelsesteenweg 102", 50.8764572294, 4.32457715726 },
	{ 89, 0, "089 - Athenee De Jette/Atheneum Van Jette", "Athenee De Jette/Atheneum Van Jette - Avenue De Levis Mirepoix / De Levis Mirepoixlaan 100", 50.8711927451, 4.32992476564 },
	{ 101, 0, "101 - Parnasse/Parnassus", "Parnasse/Parnassus - Rue Du Trone (Devant 111 - 113) / Troonstraat  (N° 111-113)", 50.8370633905, 4.3700560122 },
	{ 102, 0, "102 - Museum/Museum", "Museum - Chaussee De Wavre (Face 229 - 233)  /  Waversesteenweg (Tegenover 229 - 233)", 50.8358531161, 4.37594010588 },
	{ 103, 0, "103 - Ernest Solvay/Ernest Solvay", "Ernest Solvay - Rue De L'Arbre Benit/Gewijde Boomstraat 2-4-6", 50.8349517018, 4.36401860873 },
	{ 104, 0, "104 - Fernand Cocq/Fernand Cocq", "Fernand Cocq - Place Fernand Cocq (Face Au 19-23) / Fernand Cocqplein (Tegenover 19 - 23)", 50.8333623608, 4.36712794704 },
	{ 105, 0, "105 - De Hennin", "De Hennin -  Chaussee D'Ixelles/Elsense Steenweg 254 - 260", 50.8301365289, 4.36951135166 },
	{ 106, 0, "106 - Germoir/Mouterij", "Germoir/Mouterij - Avenue De La Couronne/Kroonlaan 92-94-96", 50.8299062048, 4.37895400503 },
	{ 107, 0, "107 - Defacqz/Defacqz", "Defacqz - Rue Defacqz/ Defacqzstraat 25-27-29", 50.8281420606, 4.3595536505 },
	{ 108, 0, "108 - Flagey/Flagey", "Flagey - Place Flagey (Face 11)/Eugene Flageyplein (Tegenover 11)", 50.8279234774, 4.37191500367 },
	{ 109, 0, "109 - Chatelain/Kastelein", "Chatelain/Kastelein - Rue De L'Aqueduc /Aquaductstraat 115-117-119", 50.8241314864, 4.36007117085 },
	{ 110, 0, "110 - Rodin/Rodin", "Rodin - Avenue De La Couronne (Devant 145 D) / Kroonlaan (N° 145 D)", 50.8274638961, 4.38211596202 },
	{ 111, 0, "111 - Leemans/Leemans", "Leemans - Place Albert Leemans/Albert Leemansplein 13/14", 50.8222176815, 4.36353184718 },
	{ 112, 0, "112 - Page/Edelknaap", "Page-Edelknaap  -  Chaussee De Waterloo/  Waterloose Steenweg 440 - 442", 50.8215673716, 4.35664748052 },
	{ 113, 0, "113 - Abbaye De La Cambre / Abdij Ter Kameren", "Abbaye De La Cambre/Abdij Ter Kameren - Avenue Emile Duray (Face Au N° 2) /Emile Duraylaan (Tegenover N° 2)", 50.8199500656, 4.37536158268 },
	{ 114, 0, "114 - De Beco/De Beco", "De Beco  -  Avenue Emile De Beco (N° 128) / Emile De Becolaan (N° 128)", 50.8207725364, 4.38476282561 },
	{ 115, 0, "115 - Petite Suisse/Klein Zwitserland", "Petite Suisse / Klein Zwitserland - Place De La Petite Suisse (Face 16-18) / Klein Zwitserlandplein (Tegenover 16 - 18)", 50.8180417598, 4.38561769287 },
	{ 116, 0, "116 - Fraiteur", "Fraiteur - Boulevard De La Plaine  (Entree Ulb) / Pleinlaan (Ingang Vub)", 50.8185366562, 4.39555211657 },
	{ 117, 0, "117 - Cimetiere D'Ixelles/Begraafplaats Elsene", "Cimetiere D'Ixelles / Begraafplaats Van Elsene - Avenue De L'Universite/Hogeschoollaan 1-3-5", 50.815725947, 4.38962490312 },
	{ 118, 0, "118 - Buyl/Buyl", "Buyl -  Avenue Adolphe Buyl / Adolphe Buyllaan 1-3", 50.8180154415, 4.37983998259 },
	{ 119, 0, "119 - Paquot/Pacquot", "Paquot -  Rue Jean Paquot (44 A 48) /Jean Paquotstraat (44 T.E.M 48)", 50.825603406, 4.3794910642 },
	{ 120, 0, "120 - Blyckaerts/Blyckaerts", "Blyckaerts - Place Raymond Blyckaerts/Raymond Blyckaertsplein", 50.8332847747, 4.37464750281 },
	{ 121, 0, "121 - Etangs / Vijvers", "Etangs / Vijvers - Rue Guillaume Stocq (Face Au N° 1-3-5)/ Guillaume Stocqstraat (Tegenover N° 1-3-5)", 50.8241515165, 4.37401257141 },
	{ 122, 0, "122 - Gare D'Etterbeek/Station Van Etterbeek", "Gare D'Etterbeek/Station Van Etterbeek - Boulevard General Jacques/Generaal Jacqueslaan", 50.8223834661, 4.38934741993 },
	{ 123, 0, "123 - Van Eyck/Van Eyck", "Van Eyck -  Chaussee De Vleurgat (Devant 215 - 217) / Vleurgatsesteenweg  (N° 215 - 217)", 50.8209985595, 4.36646113908 },
	{ 124, 0, "124 - Charles Graux", "Charles Graux - Chaussee De Waterloo (Devant N° 585 - 587)/ Waterloosesteenweg (N° 585 - 587)", 50.8185665797, 4.36301504913 },
	{ 125, 0, "125 - Georges Brugmann/Georges Brugmann", "Georges Brugmann - Place Georges Brugmann/Georges Brugmannplein N° 10 - 11", 50.816903866, 4.353774128 },
	{ 127, 0, "127 - Gray/Gray", "Gray  -  Rue Des Deux Ponts (Face 4)/ Tweebruggenstraat (Tegenover 4)", 50.8322954964, 4.37781096255 },
	{ 133, 0, "133 - Château/Kasteel", "Chateau-Kasteel - Avenue Du Château/Kasteellaan", 50.8669802442, 4.30910881909 },
	{ 134, 0, "134 - Place De Bastogne/Bastenaken", "Bastogne/Bastenaken - Place De Bastogne/Bastenakenplein", 50.8629006043, 4.31681882069 },
	{ 135, 0, "135 - Parc Lacroix/Lacroix Park", "Parc Lacroix / Lacroix Park - Av Princesse Elisabeth/Prinses Elisabethlaan", 50.872644624, 4.37651662649 },
	{ 136, 0, "136 - Pavillon/Paviljoen", "Pavillon/Paviljoen - Place Pavillon /Paviljoenplaats 92-94-96", 50.870105694, 4.3715344379 },
	{ 137, 0, "137 - Maison Communale De Schaerbeek", "Maison Communale De Schaerbeek/Gemeentehuis Van Schaarbeek - Rue Royale Sainte Marie/Koninklijke Sinte-Mariastraat 241-243-245", 50.8669570805, 4.37306859584 },
	{ 138, 0, "138 - Houffalize/Houffalize", "Houffalize - Place De Houffalize /Houffalizeplein 58", 50.865269795, 4.37803193593 },
	{ 139, 0, "139 - Liedts/Liedts", "Liedts - Place Liedts (Face Au 38)/ Liedtsplein (Tegenover 38)", 50.86388801, 4.36671478997 },
	{ 140, 0, "140 - Azalees/Azalea", "Azalees / Azalea - Avenue Des Azalees (Face 68) / Azalealaan (Tegenover 68)", 50.8628919644, 4.38117798099 },
	{ 141, 0, "141 - Gare Du Nord/Noordstation", "Gare Du Nord/Noordstation - Place Simon Bolivar/ Simon Bolivarlaan", 50.8606444709, 4.35900146937 },
	{ 142, 0, "142 - Bienfaiteurs/Weldoeners", "Bienfaiteurs/Weldoeners - Avenue Rogier / Rogierlaan 269/271", 50.8575494601, 4.38674097049 },
	{ 143, 0, "143 - Rtl/Rtl", "Rtl  - Chaussee De Louvain (Dvt 770)/ Leuvense Steenweg (N° 770)", 50.8574558624, 4.40748876447 },
	{ 144, 0, "144 - Sainte-Marie/Sinte-Maria", "Sainte Marie/Sinte-Maria - Rue Royale/ Koningsstraat 257 - 259", 50.85792437, 4.36812848088 },
	{ 145, 0, "145 - Coteaux/Wijnheuvelen", "Coteaux/Wijnheuvelen - Avenue Rogier / Rogierlaan 128", 50.859171629, 4.3791477265 },
	{ 146, 0, "146 - Leopold Iii/Leopold Iii", "Leopold Iii -  Boulevard Leopold Iii / Leopold Iii-Laan", 50.8595998464, 4.4010967571 },
	{ 147, 0, "147 - Emile Max Lycee/Lyceum Emile Max", "Emile Max Lycee/Lyceum Emile Max - Chaussee D'Haecht/ Haachtsesteenweg 226 - 230", 50.8619893915, 4.37218983382 },
	{ 148, 0, "148 - Gare Meiser/Meiser Station", "Gare Meiser / Meiser Station - Avenue Rogier/ Rogierlaan 377 - 379", 50.8557117765, 4.39424997255 },
	{ 149, 0, "149 - Jules Lebrun/Jules Lebrun", "Jules Lebrun - Chaussee De Louvain (Face 593) / Leuvense Steenweg (Tegenover 593)", 50.8563994071, 4.40329572894 },
	{ 150, 0, "150 - Meiser/Meiser", "Meiser - Place General Meiser (Face 1 - 3) / Generaal Meiserplein (Tegenover 1 - 3)", 50.8546401909, 4.39839019328 },
	{ 151, 0, "151 - Louvain 488-494/Leuven 488-494", "Louvain / Leuven - Chaussee De Louvain - Leuvensesteenweg  488-494", 50.8538561277, 4.39402533562 },
	{ 152, 0, "152 - Place Dailly/Daillyplein", "Place Dailly / Daillyplein - Place Dailly / Daillyplein 24 - 25", 50.852362048, 4.38743396793 },
	{ 153, 0, "153 - Square Armand Steurs/Armand Steurssquare", "Square Armand Steurs/Armand Steurssquare - Avenue Paul Deschanel (Face N° 267 - 269) / Paul Deschanellaan (Tegenover 267 - 269)", 50.8543250514, 4.37778687619 },
	{ 154, 0, "154 - Plasky/Plasky", "Plasky - Square Eugene Plasky (Face 100) / Eugene Plaskysquare (Tegenover 100)", 50.8513522723, 4.39654360603 },
	{ 156, 0, "156 - Jambline De Meux/Jamblinne De Meux", "Jambline De Meux - Place Jamblinne De Meux / Jamblinne De Meuxplein 43 - 44 - 45", 50.8471295664, 4.39357684795 },
	{ 157, 0, "157 - Heliotropes/Heliotropen", "Heliotropes/Heliotropen - Boulevard Lambermont /  Lambermontlaan 374", 50.8633737734, 4.38630548348 },
	{ 158, 0, "158 - Van Ysendijck:Van Ysendijck", "Van Ysendijck - Avenue Voltaire (Face 6) / Voltairelaan (Tegenover 6)", 50.8679230071, 4.37966500883 },
	{ 159, 0, "159 - Masui/Masui", "Masui - Avenue De La Reine / Koninginnelaan 153", 50.869599894, 4.3626392017 },
	{ 160, 0, "160 - Elisa/Elisa", "Elisa - Place Princesse Elisabeth / Prinses Elisabethplein 8 - 19", 50.8776500981, 4.38044930871 },
	{ 161, 0, "161 - Demolder/Demolder", "Demolder - Avenue Eugene Demolder / Eugene Demolderlaan 68", 50.8725974842, 4.37998386131 },
	{ 162, 0, "162 - Brabant/Brabant", "Brabant - Rue De Quatrecht/ Kwatrechtstraat 39", 50.8613611132, 4.36392252633 },
	{ 163, 0, "163 - Chazal/Chazal", "Chazal - Avenue Ernest Cambier (Face 7)/ Ernest Cambierlaan (Tegenover 7)", 50.8594126988, 4.39155603937 },
	{ 164, 0, "164 - Kennis/Kennis", "Kennis - Boulevard Lambermont (20 M Apres 284)/Lambermontlaan   (20 M Na N° 284)", 50.8674826452, 4.38583891638 },
	{ 165, 0, "165 - Cimetiere De Jette/ Begraafplaats Jette", "Cimetiere De Jette/Begraafplaats Van Jette - Bld De Smet De Naeyer (Face Au 322)/ De Smet De Naeyerstraat (Tegenover 322)", 50.8796060043, 4.3342305961 },
	{ 166, 0, "166 - Tref Centrum", "Tref Centrum - Rue Amelie Gomand 51- 45", 50.8762082441, 4.33727193042 },
	{ 167, 0, "167 - Charles V/Karel V", "Charles V/Karel V - Avenue Charles Quint/Keizer Karellaan 129-131", 50.8690571989, 4.30991496063 },
	{ 168, 0, "168 - Hopital Français/Frans Hospitaal", "Hopital Francais/Frans Hospitaal - Avenue Josse Goffin/Josse Goffinstraat 133-135", 50.8666425514, 4.30348884817 },
	{ 169, 0, "169 - G.Eeckhoud/ G . Eekhoud", "Eeckhoud - Avenue Georges Eekhoud/Georges Eekhoudlaan 56", 50.8776072262, 4.38763830666 },
	{ 170, 0, "170 - Riga/Riga", "Riga/Riga - Square Francois Riga / Francois Rigasquare", 50.8747621373, 4.3855862704 },
	{ 171, 0, "171 - Apollo/Apollo", "Apollo/Apollo - Square Apollo / Apollosquare", 50.8722028679, 4.39208885224 },
	{ 172, 0, "172 - Aeropolis/Aeropolis", "Aeropolis - Chaussee D'Haecht (Face 586) / Haachtsesteenweg (Tegenover 586)", 50.8697243809, 4.3881169995 },
	{ 173, 0, "173 - Bichon/Bichon", "Bichon - Place Bichon / Bichonplein", 50.865071401, 4.39422713913 },
	{ 174, 0, "174 - Mennekens/Mennekens", "Mennekens - Avenue Brigade Piron (Face Aux 80 - 82 - 84)/ Brigade Pironlaan (Tegenover 80 - 82 - 84)", 50.8541229112, 4.31633016015 },
	{ 175, 0, "175 - Beekant", "Beekant - Boulevard Edmond Machtens / Edmond Machtenslaan", 50.8543206594, 4.32284712898 },
	{ 176, 0, "176 - Colonel Bourg/Kolonel Bourg", "Colonel Bourg/Kolonel Bourg - Rue Colonel Bourg/ Kolonel Bourgstraat 104", 50.8524255635, 4.40869467866 },
	{ 177, 0, "177 - Chasseurs Ardennais/Ardense Jagers", "Chasseurs Ardennais/Ardense Jagersplein - Rue Du Noyer 81-87 /Notelaarsstraat 81-87", 50.8494762871, 4.38939994964 },
	{ 178, 0, "178 - Diamant/Diamant", "Diamant/Diamant - Boulevard Auguste Reyers / Auguste Reyerslaan", 50.8492338674, 4.40247289031 },
	{ 179, 0, "179 - Celtes/Kelten", "Celtes/Kelten - Avenue De Tervueren (Face Au 17) / Tervurenlaan (Tegenover 17)", 50.8395075809, 4.39802917919 },
	{ 180, 0, "180 - Jourdan/Jourdan", "Jourdan/Jourdan - Rue Froissart (Face 3 - 5) / Froissartstraat (Tegenover 3 - 5)", 50.8376381419, 4.38159441108 },
	{ 181, 0, "181 - Louis Titz/Louis Titz", "Louis / Titz - Avenue De La Chasse/ Jachtlaan 182 - 184", 50.8357303186, 4.39426118143 },
	{ 182, 0, "182 - Boileau/Boileau", "Boileau/Boileau - Boulevard Saint Michel / Sint-Michielslaan", 50.8317471238, 4.40475473482 },
	{ 183, 0, "183 - La Chasse/Jacht", "La Chasse/Jacht - Avenue Des Casernes/ Kazernenlaan 4 - 6", 50.8301461741, 4.39053231975 },
	{ 184, 0, "184 - Philippe Baucq/Philippe Baucq", "Philippe Baucq - Rue Philippe Baucq / Philippe Baucqstraat 32 - 38", 50.8316833158, 4.38566272603 },
	{ 185, 0, "185 - Pere De Deken/Pater De Deken", "Pere De Deken/Pater De Deken - Rue Père De Deken/ Pater De Dekenstraat 40", 50.8359146473, 4.40151201657 },
	{ 186, 0, "186 - Etangs/Vijvers", "Etangs/Vijvers - Chaussee De Wavre / Waversesteenweg 490", 50.8341779909, 4.38489001867 },
	{ 187, 0, "187 - Arsenal/Arsenaal", "Arsenal/Arsenaal - Boulevard Louis Schmidt/ Louis Schmidtlaan 2", 50.8265178652, 4.39705753109 },
	{ 188, 0, "188 - Osseghem/Osseghem", "Osseghem -  Avenue Mahatma Gandhi/ Mahatma Gandhilaan 10", 50.8572728943, 4.32476077203 },
	{ 189, 0, "189 - Place Van Meyel/Van Meyelplein", "Place Van Meyel/Van Meyelplein", 50.835917545, 4.38727368057 },
	{ 190, 0, "190 - Terdelt/Terdelt", "Terdelt/Terdelt  - Place Terdelt / Terdeltplein", 50.8680785663, 4.39065787209 },
	{ 25, 0, "025 - Porte D'Anderlecht / Anderlechtsepoort", "Porte D'Anderlecht/Anderlechtsepoort - Bld Poincare/ Poincarelaan 27/28/29", 50.844551, 4.338484 },
	{ 26, 0, "026 - Van Lint / Van Lint", "Van Lint - Rue Van Lint/ Van Lintstraat 6 - 8", 50.8395500668, 4.32893263881 },
	{ 27, 0, "027 - Square Albert I / Albert I Square", "Square Albert I / Albert I-Square 25 - 26 - 27", 50.8391768204, 4.32227697655 },
	{ 28, 0, "028 - Clemenceau / Clemenceau", "Clemenceau - Chee De Mons/ Bergense Steenweg 159-161-163", 50.8422103114, 4.33058645694 },
	{ 29, 0, "029 - Baudouin / Boudewijn", "Baudouin/Boudewijn - Rue De Laeken / Lakensestraat", 50.8567687859, 4.35284963187 },
	{ 30, 0, "030 - Laeken / Laken", "Laeken/Laken - Rue De Laeken (Entre N° 119 Et 109) / Lakensestraat (Tussen N° 119 En 109)", 50.854307561, 4.35204971595 },
	{ 3, 0, "003 - Porte De Flandres / Vlaamsepoort", "Porte De Flandres/Vlaamsepoort - Bld De Nieuport/Nieuwpoortlaan 1", 50.8532602184, 4.3418558299 },
	{ 24, 0, "024 - Rogier / Rogier", "Rogier - Boulevard Du Jardin Botanique/Kruidtuinlaan", 50.8552478103, 4.35807511348 },
	{ 31, 0, "031 - Musee De La Bd / Stripmuseum", "Musee De La Bd/Stripmuseum - Boulevard Pacheco/Pachecolaan", 50.8507961699, 4.36112200007 },
	{ 32, 0, "032 - Dansaert / Dansaert", "Dansaert - Rue Antoine Dansaert/Antoine Dansaertstraat 60-62-64", 50.850189, 4.346166 },
	{ 33, 0, "033 - Mort Subite / Mort Subite", "Mort Subite - Rue Montagne Aux-Herbes-Potageres (Face N° 7)/Warmoesberg (Tegenover N°7)", 50.8486301112, 4.35612505266 },
	{ 4, 0, "004 - Jardin Aux Fleurs / Bloemenhof", "Jardin Aux Fleurs/Bloemenhof - Place Du Jardin Aux Fleurs/Bloemenhofplein", 50.8478939031, 4.34356204344 },
	{ 5, 0, "005 - Bourse / Beurs", "Bourse/Beurs - Rue Paul Devaux/Paul Devauxstraat", 50.8487371368, 4.34947199856 },
	{ 7, 0, "007 - Parc / Park", "Parc/Park - Rue Royale  (Face N°66-68)/Koningsstraat (Tegenover N°66-68)", 50.846436, 4.362473 },
	{ 34, 0, "034 - Fontainas / Fontainas", "Fontainas - Bld Anspach N°180 A 192/Anspachlaan N°180 Tot 192", 50.845702191, 4.34693335067 },
	{ 35, 0, "035 - Cantersteen / Kantersteen", "Cantersteen/Kantersteen - Rue Cantersteen/Kantersteenstraat 41-43-45", 50.84573, 4.358225 },
	{ 8, 0, "008 - Arts-Loi / Kunst-Wet", "Arts-Loi/Kunst-Wet -  Avenue Des Arts/Kunstlaan 24", 50.8460794893, 4.36890806344 },
	{ 36, 0, "036 - Place St Jean / Sint-Jansplein", "Place St Jean/Sint-Jansplein - Rue Du Lombard/Lombardstraat 42", 50.8452026334, 4.35154547184 },
	{ 9, 0, "009 - Anneesens / Anneessens", "Anneesens - Bld Maurice Lemonnier/Maurice Lemonnierlaan 42-44-46", 50.8438552678, 4.34509403002 },
	{ 10, 0, "010 - Chapelle / Kapel", "Chapelle/Kapel - Place De La Chapelle/Kapelleplein", 50.8413817365, 4.35159051166 },
	{ 11, 0, "011 - Sablon / Zavel", "Sablon/Zavel - Rue De La Regence/Regentschapsstraat 20", 50.8400374623, 4.35651253148 },
	{ 12, 0, "012 - Trone / Troon", "Trone/Troon - Av. Des Arts/Kunstlaan, 58", 50.8406168982, 4.36615595612 },
	{ 13, 0, "013 - Lemonnier / Lemonnier", "Lemonnier - Bld. Maurice Lemonnier/De Maurice Lemonnierlaan 202-204-206", 50.8401564986, 4.34125188252 },
	{ 14, 0, "014 - Porte De Namur / Naamsepoort", "Porte De Namur/Naamsepoort - Bld Du Regent /Regentlaan 1", 50.839028551, 4.36221913609 },
	{ 37, 0, "037 - Poelaert / Poelaert", "Poelaert - Place Poelaert/Poelaertplein 3", 50.8381768295, 4.35270173087 },
	{ 38, 0, "038 - Jeu De Balle / Vossenplein", "Jeu De Balle/Vossenplein - Rue Blaes/Blaesstraat 135-141", 50.8375886246, 4.3469649374 },
	{ 16, 0, "016 - Louise / Louiza", "Louise/Louiza - Place Louise/Louizaplein 53", 50.8360464553, 4.35547628054 },
	{ 39, 0, "039 - Hotel Des Monnaies / Munthotel", "Hotel Des Monnaies/Munthotel - Bld De Waterloo- Waterloolaan 93/94/95/96/98", 50.8344457017, 4.35079469404 },
	{ 40, 0, "040 - Porte De Hal / Hallepoort", "Porte De Hal/Hallepoort - Boulevard Du Midi/Zuidlaan 142", 50.834186411, 4.34293860609 },
	{ 42, 0, "042 - Porte De Ninove /Ninoofsepoort", "Porte De Ninove/Ninoofsepoort - Place De Ninove/Ninoofseplein/Sur Bld De L'Abattoir/Op Slachthuislaan", 50.849308, 4.338484 },
	{ 18, 0, "018 - Gutenberg / Gutenberg", "Gutenberg - Square Gutenberg (Face N° 5)/Gutenbergssquare (Tegenover N° 5)", 50.8481419696, 4.37774503083 },
	{ 56, 0, "056 - Archimede / Archimedes", "Archimede/Archimedes - Rue Archimede/Archimedesstraat 58-64", 50.8460351537, 4.3840968356 },
	{ 79, 0, "079 - Loi / Wet", "Loi/Wet - Rue De Treves/Trierstraat 128-126", 50.8440986139, 4.37563558351 },
	{ 43, 0, "043 - Joseph Ii / Jozef Ii", "Joseph Ii/Jozef Ii - Rue Joseph Ii/Jozef Ii-Straat", 50.8456247489, 4.37429283795 },
	{ 61, 0, "061 - Maelbeek / Maalbeek", "Maelbeek/Maalbeek - Chaussee D'Etterbeek/Etterbeeksesteenweg 15", 50.8437975397, 4.37808329269 },
	{ 44, 0, "044 - Charlemagne / Karel De Grote", "Charlemagne/Karel De Grote - Rue De La Science/Wetenschapsstraat 11", 50.8419988886, 4.37103995402 },
	{ 62, 0, "062 - Cortenbergh / Kortenberg", "Cortenbergh/Kortenberg - Avenue De Cortenbergh/Kortenberglaan", 50.8428330948, 4.38501027916 },
	{ 66, 0, "066 - Schuman / Schuman", "Schuman - Rue De La Loi/Wetstraat 170", 50.8433488276, 4.37987597177 },
	{ 45, 0, "045 - Stephanie / Stefania", "Stephanie/Stefania - Av Louise/Louizalaan 61A-63-65", 50.8331977506, 4.35759215513 },
	{ 20, 0, "020 - Palais Royal / Koninklijk Paleis", "Palais Royal/Koningsstraat Paleis - Rue Royale (Devant N°14)/Koninklijkestraat (N°14)", 50.843239, 4.360414 },
	{ 46, 0, "046 - Albertine / Albertina", "Albertine/Albertina - Bld De L'Empereur/Keizerslaan 2", 50.843819, 4.355435 },
	{ 47, 0, "047 - Les Quais / Kaaien", "Les Quais/Kaaien - Quai A La Chaux/Kalkkaai 1-2", 50.8549265319, 4.34718130513 },
	{ 48, 0, "048 - Congres / Congres", "Congres - Rue Royale/Koningsstraat 144-146-148", 50.849525, 4.363611 },
	{ 23, 0, "023 - Agora / Agora", "Agora - Place Agora/Agoraplein 120", 50.8467157469, 4.354750685 },
	{ 21, 0, "021 - De Brouckere / De Brouckere", "De Brouckere - Place De Brouckere/De Brouckereplein", 50.851879, 4.352753 },
	{ 22, 0, "022 - Jacqmain / Jacqmain", "Jacqmain - Bld. D'Anvers/Antwerpselaan", 50.8559800422, 4.35559740973 },
	{ 93, 0, "093 - Clovis / Clovis", "Clovis/Clovis - Chaussee De Louvain - Leuvensesteenweg 260-264", 50.8505497944, 4.38110667265 },
	{ 53, 0, "053 - Gare Du Midi / Zuidstation", "Gare Du Midi / Zuidstation - Place Victor Horta / Victor Hortaplein", 50.8372782138, 4.33576520454 },
	{ 64, 0, "064 - Veterinaires / Veeartsen", "Veterinaires/Veeartsen - Rue De France / Frankrijkstraat", 50.8330920606, 4.33101103479 },
	{ 58, 0, "058 - Gare Du Nord / Noordstation", "Gare Du Nord/Noordstation - Place Du Nord / Noordplaats", 50.8591613189, 4.35927420097 },
	{ 80, 0, "080 - Ceres/Ceres", "Ceres - Av. F. Roosevelt/F. Rooseveltlaan, 14", 50.8150257318, 4.37670262761 },
	{ 72, 0, "072 - Ulb F.Roosevelt / Vub F Roosevelt", "Ulb F.Roosevelt / Vub F.Roosevelt - Av. F.Roosevelt/F.Rooseveltlaan 19", 50.8125663191, 4.37914601751 },
	{ 71, 0, "071 - Legrand/Legrand", "Legrand - Av Louise/Louizalaan 525", 50.815547357, 4.37183450729 },
	{ 68, 0, "068 - Jean Rey/Jean Rey", "Jean Rey - Place Jean Rey/Jean Reyplaats", 50.8404541673, 4.38029422008 },
	{ 49, 0, "049 - Willebroek/Willebroek", "Willebroeck/Willebroek - Quai De Willebroeck/Willebroekkaai 22 Bis", 50.8608083483, 4.35050043865 },
	{ 41, 0, "041 - Saint-Roch/Sint-Rochus", "Saint Roch/Sint-Rochus - Chaussee D'Anvers/Antwerpselaan 37", 50.8594297382, 4.35481936152 },
	{ 75, 0, "075 - General Baron/Generaal Baron", "General Baron/Generaal Baron - Av Du Parc / Parklaan 51 - 55", 50.8260272979, 4.34044109458 },
	{ 78, 0, "078 - Duc Petiaux/Duc Petiaux", "Duc Petiaux - Chaussee De Waterloo/ Waterloosesteenweg 376 - 370", 50.8238069351, 4.35172282643 },
	{ 77, 0, "077 - Paul Janson/Paul Janson", "Paul Janson - Chaussee De Charleroi/ Charleroisesteenweg 159", 50.8262675025, 4.3546556037 },
	{ 70, 0, "070 - Aurore/Dageraad", "Aurore/Dageraad - Avenue Louise/Louizalaan 440", 50.8183612592, 4.37153905584 },
	{ 69, 0, "069 - Lesbroussart/Lesbroussart", "Lesbroussart - Avenue Louise/Louizalaan 192", 50.8278278452, 4.36387146972 },
	{ 73, 0, "073 - Vleurgat/Vleurgat", "Vleurgat - Avenue Louise/Louizalaan 300", 50.8240611328, 4.36769630468 },
	{ 67, 0, "067 - Parc Cinquantenaire / Jubelpark", "Parc Cinquantenaire/Jubelpark - Avenue D'Auderghem/Oudergemsesteenweg 45", 50.8399549407, 4.38552091787 },
	{ 2, 0, "002 - Eloy/Eloy", "Eloy - Rue Eloy / Eloystraat", 50.8362457584, 4.32609149836 },
	{ 87, 0, "087 - Miroir/Spiegel", "Miroir/Spiegel - Avenue De Laeken (Face 36) / Lakense Laan (Tegenover 36)", 50.8716770097, 4.32386957601 },
	{ 88, 0, "088 - Woeste/Woeste", "Woeste - Avenue Notre Dame De Lourdes / Onze-Lieve-Vrouw Van Lourdeslaan", 50.8733403953, 4.33444454783 },
	{ 90, 0, "090 - Broustin/Broustin", "Broustin - Av De Jette/ Jetselaan 73 - 81", 50.8676929019, 4.32674788188 },
	{ 91, 0, "091 - Belgica/Belgica", "Belgica - Place Werrie/ Werrieplein 24", 50.8679085698, 4.33524270497 },
	{ 92, 0, "092 - Lenoir/Lenoir", "Lenoir - Bld De Smet De Naeyer/De Smet De Naeyerlaan 187 - 189", 50.8759974791, 4.33006854273 },
	{ 82, 0, "082 - Pannenhuis/Pannenhuis", "Pannenhuis/Pannenhuis - Rue Charles Demeer/Charles Demeerstraat  71", 50.8732687413, 4.34170080936 },
	{ 57, 0, "057 - Madou/Madou", "Madou - Rue Scailquin/Scailquinstraat", 50.8498662926, 4.3694699518 },
	{ 55, 0, "055 - Botanique/Kruidtuin", "Botanique/Kruidtuin - Avenue Galilee/Galileelaan", 50.853359, 4.366229 },
	{ 6, 0, "006 - Gare Centrale/Centraal Station", "Gare Centrale/Centraal Station - Bld De L'Imperatrice/Keizerinlaan", 50.846144806, 4.3567350444 },
	{ 51, 0, "051 - Midi Fonsny/Zuid Fonsny", "Midi Fonsny/Zuid Fonsny - Rue D'Angleterre / Engelandstraat", 50.8359910245, 4.33864925145 },
	{ 52, 0, "052 - Sainctelette/Sainctelette", "Sainctelette - Place Sainctelette/Saincteletteplein", 50.8592105972, 4.34547474859 },
	{ 50, 0, "050 - Ribeaucourt/Ribaucourt", "Ribeaucourt - Bld Leopold Ii / Leopold Ii-Laan 121-123", 50.8611655276, 4.33880942368 },
	{ 54, 0, "054 - Tour Et Taxis/Thurn&Taxis", "Tour Et Taxis/Thurn&Taxis - Rue Picard/ Picardstraat 3", 50.8637052913, 4.34578755177 },
	{ 76, 0, "076 - Place Van Meenen/Van Meenenplein", "Place Van Meenen/Van Meenenplein - Av Paul Dejaer (Face 35 - 39) / Paul Dejaerlaan (Tegenover 35 - 39)", 50.8259818158, 4.34505824459 },
	{ 65, 0, "065 - Parvis De St Gilles/St-Gillisvoorplein", "Parvis De St Gilles/St-Gillisvoorplein - Chaussee De Waterloo/ Waterloosesteenweg 65-69", 50.8302596457, 4.34454813513 },
	{ 74, 0, "074 - Place Loix/Loixplein", "Place Loix/Loixplein - Rue Berckmans/ Berckmansstraat 78 - 84", 50.8319492904, 4.35312784526 },
	{ 19, 0, "019 - Place Morichar/Moricharplein", "Place Morichar / Moricharplein - Rue Des Etudiants/ Studentenstraat 32 - 34", 50.8279819076, 4.34774049787 },
	{ 59, 0, "059 - Place St-Josse/St Joostplein", "Place St-Josse/St-Joostplein  -  Rue Willems (Face 5 - 11) / Willemsstraat (Tegenover 5 - 11)", 50.849830763, 4.37513976956 },
	{ 60, 0, "060 - St-Lazarre/St Lazarus", "St-Lazarre/Sint-Lazarus   -   Bld Saint-Lazarre/Sint-Lazaruslaan 4 -10", 50.8572847213, 4.36145557929 },
	{ 96, 0, "096 - Hotel President/President Hotel", "Hotel President/President Hotel - Boulevard Du Roi Albert Ii/Koning Albert-Ii Laan", 50.8637686799, 4.35870431116 },
	{ 95, 0, "095 - Place Bockstael/Bockstaelplaats", "Place Bockstael/Bockstaelplaats - Bld Emile Bockstael/Emile Bockstaellaan 254", 50.8782118365, 4.34785119303 },
	{ 97, 0, "097 - Karreveld/Karreveld", "Karreveld - Chaussee De Gand/ Gentsesteenweg 1-3", 50.8581326739, 4.31877967861 },
	{ 94, 0, "094 - Duchesse De Brabant/Hertogin Van Brabant", "Duchesse De Brabant/Hertogin Van Brabant - Rue De Birmingham / Birminghamstraat", 50.8494003162, 4.32916772454 },
	{ 98, 0, "098 - Cimetiere/Kerkhof", "Cimetiere/Kerkhof - Bld Mettewie/Mettewielaan", 50.8592437906, 4.31243332113 },
	{ 81, 0, "081 - Pont Bockstael/Brug Bockstael", "Pont Bockstael/Brug Bockstael - Bld Emile Bockstael/Emile Bockstaellaan 5", 50.8703863496, 4.34316067331 },
//	{ 191, 0, "191 - Artan", "Rue Clays", 27.1409734276, -3.40456063168 },
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

