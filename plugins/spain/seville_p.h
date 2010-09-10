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

#ifndef STATIONS_SIMPLE_PRIVATE_SEVILLE_H
#define STATIONS_SIMPLE_PRIVATE_SEVILLE_H

#include "stationspluginsimple_p.h"


static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {
	{ 1, 0, "001_Glorieta Olimpica", "Glorieta Olimpica - Aprox. Concejal Alberto Jiménez-Becerril", 37.412924, -5.988906 },
	{ 4, 0, "004_Calle Leonardo Da Vinci", "Aprox C/ Thomas Alba Edison", 37.410112, -6.005722 },
	{ 6, 0, "006_Camino De Los Descubrimientos", "Aprox. Calle Isaac Newton", 37.406614, -6.002978 },
	{ 7, 0, "007_Calle Américo Vespucio", "Aprox. Calle De Jacques Cousteau", 37.407469, -6.007603 },
	{ 8, 0, "008_Calle Leonardo Da Vinci", "Aprox. C/ Gregor Mendel", 37.400969, -6.009382 },
	{ 10, 0, "010_Calle Jose Diaz", "Aprox. Avda Concejal Alberto Jiménez-Becerril", 37.409385, -5.990766 },
	{ 11, 0, "011_Calle Avicena", "Aprox. Calle Avenzoar", 37.407143, -5.992590 },
	{ 12, 0, "012_Plaza Duquesa De Alba", "Barqueta", 37.403870, -5.994904 },
	{ 14, 0, "014_Avenida Sanchez Pizjuan", "Facultad De Medicina", 37.406474, -5.989119 },
	{ 15, 0, "015_Calle Dr Marañon", "Aprox. C/ San Juan De Ribera", 37.406042, -5.985734 },
	{ 16, 0, "016_Calle De Manuel Villalobos", "Aprox. C/ Sor Francisca Dorotea", 37.407051, -5.982431 },
	{ 17, 0, "017_Calle De Madreselva", "Aprox. Ronda De Pio Xii", 37.407152, -5.978840 },
	{ 19, 0, "019_Parlamento", "Aprox. C/ Don Fadrique", 37.403328, -5.989037 },
	{ 20, 0, "020_Calle San Juan De Ribera", "Aprox. C/ Fray Isidoro De Sevilla", 37.404870, -5.986537 },
	{ 22, 0, "022_Avenida De Llanes", "Aprox. Avda De Miraflores", 37.405130, -5.974831 },
	{ 23, 0, "023_Parlamento", "Aprox. C/ San Juan De Ribera", 37.403338, -5.987879 },
	{ 27, 0, "027_Avenida De Llanes", "Aprox C/ Escultor Francisco Buiza", 37.403878, -5.972090 },
	{ 29, 0, "029_Carretera De Carmona", "Aprox. Avda De Llanes", 37.402464, -5.970145 },
	{ 35, 0, "035_Alameda De Hercules", "Aprox. Calle Peris Mencheta", 37.400683, -5.993630 },
	{ 36, 0, "036_Calle San Vicente", "Aprox. C/ Guadalquivir", 37.400501, -5.998403 },
	{ 40, 0, "040_Avenida Reina Mercedes", "Aprox. Glorieta Alcalde De Parias Merry", 37.356351, -5.986460 },
	{ 42, 0, "042_Plaza Cronista", "Aprox. C/ Divina Pastora", 37.398706, -5.989460 },
	{ 43, 0, "043_Ronda Capuchinos", "Aprox. C/ Maestro Quiroga", 37.399156, -5.982737 },
	{ 44, 0, "044_Ronda Capuchinos", "Aprox. C/ Corinto", 37.398339, -5.981640 },
	{ 46, 0, "046_Plaza Del Pelicano", "Aprox. C/ Enladrilladas", 37.397594, -5.983873 },
	{ 48, 0, "048_Calle Churruca", "Aprox. C/ Gonzáles Cuadrado", 37.397157, -5.991066 },
	{ 49, 0, "049_Alameda De Hercules", "Aprox. C/ Amor De Dios", 37.396866, -5.993927 },
	{ 51, 0, "051_Avenida Torneo", "Aprox. C/ Luis Rey Romero", 37.395520, -6.002321 },
	{ 52, 0, "052_Calle Del Inca Garcilaso", "Aprox. C/ Jerónimo De Aguilar", 37.394226, -6.010309 },
	{ 55, 0, "055_Calle De Maria Auxiliadora", "Aprox. C/ Gonzalo De Bilbao", 37.393318, -5.983766 },
	{ 57, 0, "057_Plaza Cristo De Burgos", "Pza De San Pedro", 37.392319, -5.989705 },
	{ 58, 0, "058_Calle Regina", "Aprox. Pza De La Encarnación", 37.394367, -5.991545 },
	{ 62, 0, "062_Plaza De Armas", "Avda Torneo (Estación De Autobuses)", 37.391061, -6.003150 },
	{ 64, 0, "064_Calle Cuesta De Rosario", "Pza De La Pescadería", 37.389856, -5.991125 },
	{ 69, 0, "069_Calle Jose Laguillo", "Aprox. Pablo Iglesias", 37.392010, -5.978293 },
	{ 70, 0, "070_Estación Renfe Santa Justa", "Estación Renfe Santa Justa", 37.391158, -5.975971 },
	{ 73, 0, "073_Plaza San Agustin", "Aprox. C/ Concepción", 37.389514, -5.984363 },
	{ 75, 0, "075_Plaza San Francisco", "Aprox C/ Hernando Colón", 37.387997, -5.993587 },
	{ 77, 0, "077_Plaza Chapina", "Aprox. Hotel Abba Triana", 37.389629, -6.007581 },
	{ 78, 0, "078_Calle Alfareria", "Aprox. Ronda De Triana", 37.388571, -6.010282 },
	{ 79, 0, "079_Plaza De Las Mercedarias", "Aprox. C/ Ibarra", 37.388326, -5.986904 },
	{ 81, 0, "081_Calle Luis Montoto", "Aprox. C/ Benitos Mas Y Prat", 37.387156, -5.971017 },
	{ 85, 0, "085_Paseo Catalina Ribera", "Frente A La Diputación Provincial", 37.385351, -5.986785 },
	{ 92, 0, "092_Ronda De Triana", "Aprox. C/ De Manuel Arellano", 37.385838, -6.011220 },
	{ 93, 0, "093_Ronda De Triana", "Aprox. C/ San Vicente De Paul", 37.383123, -6.010876 },
	{ 98, 0, "098_Avenida De Roma", "Puerta De Jerez", 37.382043, -5.993030 },
	{ 100, 0, "100_Paseo Catalina Ribera", "Aprox. C/ San Fernando", 37.381516, -5.988999 },
	{ 101, 0, "101_Prado De San Sebastian", "Estación De Autobuses", 37.381116, -5.986950 },
	{ 104, 0, "104_Avenida Eduardo Dato", "Aprox. C/ Fuenteovejuna", 37.384136, -5.979677 },
	{ 107, 0, "107_Calle Luis Morales", "Aprox. Nervión Plaza", 37.384259, -5.972591 },
	{ 108, 0, "108_Avenida Eduardo Dato", "Aprox. Avda De San Francisco Javier", 37.382853, -5.973249 },
	{ 109, 0, "109_Avenida San Francisco Javier", "Aprox. C/ Camilo José Cela", 37.379884, -5.974383 },
	{ 113, 0, "113_Plaza San Martín De Porres", "Aprox. Avda Alvar Núñez", 37.380778, -6.009179 },
	{ 118, 0, "118_Plaza De Cuba", "Aprox. Puente De San Telmo", 37.379791, -5.997108 },
	{ 125, 0, "125_Avenida San Francisco Javier", "Aprox. Avda De Ramón Y Cajal", 37.377406, -5.974900 },
	{ 129, 0, "129_Calle Virgen De Lujan", "Aprox. Virgen De La Victoria", 37.374668, -6.002455 },
	{ 130, 0, "130_Glorieta Republica Dominicana", "Aprox. C/ López De Gomara", 37.375745, -6.005248 },
	{ 132, 0, "132_Calle Paez De Ribera", "Aprox. Paseo De La Palmera", 37.363619, -5.984785 },
	{ 133, 0, "133_Avenida Santa Fe", "Aprox. C/ Virgen De La Oliva", 37.374039, -6.004198 },
	{ 135, 0, "135_Calle Virgen De Luján", "Aprox. Glorieta Las Cigarreras", 37.374651, -5.993801 },
	{ 138, 0, "138_Calle Ramón Carande", "Aprox. C/ San Salvador", 37.374370, -5.978934 },
	{ 139, 0, "139_Avenida Diego Martinez Barrio", "Aprox. Avda Gal Garcia De La Herranz", 37.375075, -5.975863 },
	{ 142, 0, "142_Calle Ramon De Carranza", "Aprox. C/ Asunción", 37.371651, -5.997212 },
	{ 143, 0, "143_Calle Ramon De Carranza", "Aprox. C/ Virgen De La Oliva", 37.371724, -6.003312 },
	{ 145, 0, "145_Avenida Reina Mercedes", "Aprox. C/ Profesor García González", 37.360233, -5.986318 },
	{ 146, 0, "146_Avenida Reina Mercedes", "Aprox. C/ Profesor García González", 37.360101, -5.986313 },
	{ 148, 0, "148_Calle Tharsis", "Aprox. C/ Aorno", 37.398768, -5.973182 },
	{ 149, 0, "149_Calle Arroyo", "Aprox. C/ Tena", 37.397830, -5.975672 },
	{ 152, 0, "152_Calle Samaniego", "Aprox. C/ Esperanza De La Trinidad", 37.395791, -5.974373 },
	{ 154, 0, "154_Avenida Kansas City", "Aprox. C/ Naranjito De Triana", 37.394837, -5.968426 },
	{ 155, 0, "155_Avenida Kansas City", "Aprox. Avda El Greco", 37.392911, -5.970739 },
	{ 160, 0, "160_Calle Arjona", "Aprox. Puente De Triana", 37.387386, -6.001585 },
	{ 161, 0, "161_Avenida Alcalde Manuel Del Valle", "Aprox. C/ Baltasar De Alcázar", 37.400001, -5.969103 },
	{ 9, 0, "009_Camino De Los Descubrimientos", "Aprox. C/ Albert Einstein", 37.403325, -6.004020 },
	{ 122, 0, "122_Calle Enramadilla", "Aprox. C/ Balbino Marrón", 37.378484, -5.978389 },
	{ 124, 0, "124_Calle Enramadilla", "Aprox. C/ Barrau", 37.377730, -5.977244 },
	{ 157, 0, "157_Avenida Cardenal Bueno Monreal", "Aprox. Avda Ramón Carande", 37.369799, -5.978195 },
	{ 159, 0, "159_Avenida Cardenal Bueno Monreal", "Approx. Avda Manuel Siurot", 37.368045, -5.984854 },
	{ 158, 0, "158_Avenida Cardenal Bueno Monreal", "Aprox. C/ Bogota", 37.368853, -5.981618 },
	{ 140, 0, "140_Calle Felipe Ii", "Aprox. Avda Diego Martínez Barrio", 37.372370, -5.977362 },
	{ 116, 0, "116_Calle Manuel Siurot", "Aprox. Hospital Universitario Virgen Del Rocio", 37.361430, -5.981603 },
	{ 141, 0, "141_Calle Felipe Ii", "Aprox. C/ Ramón Carande", 37.371733, -5.981895 },
	{ 21, 0, "021_Calle Manuel Villalobos", "Aprox. C/ Madre San Marcelo", 37.405474, -5.981527 },
	{ 25, 0, "025_Avenida De La Cruz Roja", "Aprox. C/ Albaida", 37.403133, -5.981109 },
	{ 31, 0, "031_Avenida De Miraflores", "Aprox. C/ Albaida", 37.400542, -5.979781 },
	{ 53, 0, "053_Calle Reyes Católicos", "Aprox. C/ Gravina", 37.389341, -5.999605 },
	{ 65, 0, "065_Calle Alhóndiga", "Aprox. Card. Cervantes", 37.391299, -5.988140 },
	{ 72, 0, "072_Calle Amador De Los Rios", "Aprox. C/ Lope De Vega", 37.390712, -5.982768 },
	{ 74, 0, "074_Plaza Pilatos", "Aprox. C/ San Esteban", 37.389771, -5.986897 },
	{ 83, 0, "083_Avenida La Buhaira", "Aprox. Avda Luis Montoto", 37.386955, -5.978051 },
	{ 84, 0, "084_Calle José María Moreno Galván", "Aprox. C/ Juan Antonio Cabestany", 37.387350, -5.983068 },
	{ 97, 0, "097_Paseo De Cristóbal Colón", "Aprox. Torre Del Oro", 37.381535, -5.995552 },
	{ 106, 0, "106_Avenida Eduardo Dato", "Aprox. C/ Oscar Carvallo", 37.383797, -5.977454 },
	{ 131, 0, "131_Calle Tabladilla", "Aprox. C/ Cardenal Ilundaín", 37.364750, -5.981452 },
	{ 134, 0, "134_Calle Virgen De Luján", "Aprox. C/ Asunción", 37.374770, -5.998536 },
	{ 137, 0, "137_Avenida De La Borbolla", "Aprox. C/ Porvenir", 37.373758, -5.985517 },
	{ 150, 0, "150_Calle San Juan Bosco", "Aprox. C/ Arroyo", 37.396749, -5.978634 },
	{ 24, 0, "024_Calle León Xiii", "Aprox. C/ Fray Isidoro De Sevilla", 37.404036, -5.984592 },
	{ 32, 0, "032_Calle Muñoz León", "Aprox. C/ Morera", 37.402020, -5.986323 },
	{ 80, 0, "080_Calle Luis Montoto", "Aprox. C/ Alberto Duero", 37.387627, -5.981027 },
	{ 82, 0, "082_Calle Luis Montoto", "Aprox. C/ Maese Farfán", 37.387098, -5.974843 },
	{ 102, 0, "102_Calle Juan De Mata Carriazo", "Aprox. Antigua Estación San Bernardo", 37.382739, -5.983720 },
	{ 5, 0, "005_Camino De Los Descubrimientos", "Aprox. C/ Thomás Alba Edison", 37.411044, -6.001959 },
	{ 68, 0, "068_Calle Juan Antonio Cabestany", "Aprox. Calle Júpiter", 37.390292, -5.979964 },
	{ 119, 0, "119_Avenida De Chile", "Aprox. Costurero De La Reina", 37.377404, -5.991965 },
	{ 164, 0, "164_Calle Luis Montoto", "Aprox. C/ El Greco", 37.387649, -5.965655 },
	{ 166, 0, "166_Ronda Del Tamarguillo", "Aprox. Centro Comercial Los Arcos", 37.388590, -5.959240 },
	{ 165, 0, "165_Avenida De Andalucia", "Aprox. Centro Comercial Los Arcos", 37.387645, -5.960953 },
	{ 112, 0, "112_Avda Esperanza De Triana", "Aprox. Plaza Amadeo Janone", 37.380153, -6.004383 },
	{ 144, 0, "144_Avenida De La Palmera", "Aprox. Clinica De Fátima", 37.369126, -5.988080 },
	{ 162, 0, "162_Avenida Solea", "Aprox. C/ Media Granaína", 37.391540, -5.968466 },
	{ 156, 0, "156_Avenida Kansas City", "Aprox. C/ Baltasar Gracián", 37.391453, -5.972762 },
	{ 76, 0, "076_Plaza Nueva", "Aprox. C/ Jaen", 37.388939, -5.995646 },
	{ 87, 0, "087_Plaza Nueva", "Aprox. C/ Tetuan", 37.388966, -5.995294 },
	{ 121, 0, "121_Calle Doctor Pedro De Castro", "Aprox. C/ Doc. Gabriel Sánchez", 37.377158, -5.981935 },
	{ 153, 0, "153_Avenida Reina Mercedes", "Aprox. Escuela De Arquitectura", 37.362971, -5.986262 },
	{ 94, 0, "094_Plaza Del Zurraque", "Aprox. C/ Doc. Jeronimo Pou", 37.383369, -6.008294 },
	{ 38, 0, "038_Calle De Inca Garcilaso", "Aprox. C/ Juan Antonio De Vizarrón", 37.392081, -6.011051 },
	{ 114, 0, "114_Glorieta Plus Ultra", "Aprox. Estadio Manuel Ruiz De Lopera", 37.356372, -5.979262 },
	{ 136, 0, "136_Calle Asunción", "Aprox. C/ Virgen De La Antigua", 37.373119, -5.997610 },
	{ 18, 0, "018_Avenida Eduardo Dato", "Aprox. C/ Marqués Del Nervión", 37.382075, -5.968121 },
	{ 128, 0, "128_Calle Arqueros", "Aprox. C/ Naos", 37.376453, -6.000632 },
	{ 168, 0, "168_Avenida Ramón Y Cajal", "Aprox. Avda De La Ciudad Jardín", 37.375057, -5.967492 },
	{ 105, 0, "105_Calle Francisco Murillo", "Aprox. C/ Manuel Siurot", 37.358910, -5.980620 },
	{ 117, 0, "117_Avda Esperanza De Triana", "Aprox. Avda Republica Argentina", 37.377806, -6.002613 },
	{ 71, 0, "071_Avenida Kansas City", "Aprox. Hotel Occidental", 37.390030, -5.974491 },
	{ 2, 0, "002_Gran Plaza", "Gran Plaza - Aprox. Calle Marquez De Pickman", 37.381578, -5.965224 },
	{ 167, 0, "167_Glorieta Bizco Amate", "Aprox. Avda Ramón Y Cajal", 37.373350, -5.964934 },
	{ 126, 0, "126_Avenida Reina Mercedes", "Aprox. Facultad De Informática", 37.358165, -5.986483 },
	{ 169, 0, "169_Avenida Ramón Y Cajal", "Aprox. C/ Villegas Marmolejo", 37.376501, -5.972667 },
	{ 170, 0, "170_Plaza Antonio Aparicio Herrero", "Aprox. C/ San Juan De Dios", 37.378966, -5.968923 },
	{ 28, 0, "028_Calle Rafael Salgado", "Aprox. C/ Castillo Alcala De Guadaira", 37.360261, -5.976659 },
	{ 33, 0, "033_Calle León Xiii", "Aprox. C/ Antonio Pantión", 37.401461, -5.983690 },
	{ 89, 0, "089_Calle Adriano", "Aprox. C/ Antonia Díaz", 37.386481, -5.997790 },
	{ 171, 0, "171_Calle Alfonso Laso De La Vega", "Aprox. Parroco Antonio González", 37.366146, -5.974870 },
	{ 172, 0, "172_Ronda Tamarguillo", "Aprox. Alfonso Laso De La Vega", 37.367172, -5.971211 },
	{ 173, 0, "173_Ronda Tamarguillo", "Aprox. Avda De La Paz", 37.370048, -5.968064 },
	{ 30, 0, "030_Avenida Eduardo Dato", "Detrás Estadio Sánchez Pizjuan", 37.382628, -5.970853 },
	{ 111, 0, "111_Pza Farmacéutico Murillo Herrera", "Aprox. C/ Pajes De Corro", 37.381317, -6.001053 },
	{ 115, 0, "115_Calle Lopez De Gomara", "En Frente Instituto Adolfo Becker", 37.377892, -6.007237 },
	{ 163, 0, "163_Calle Sinaí", "Aprox. C/ Baltazar Gracián", 37.389954, -5.970802 },
	{ 34, 0, "034_Plaza Pumarejo", "Aprox. Calle San Luis", 37.401028, -5.988578 },
	{ 47, 0, "047_Calle Hiniesta", "Aprox. Convento Santa Isabel", 37.397133, -5.987037 },
	{ 50, 0, "050_Calle De Hernán Cortés", "Aprox. C/ Eslava", 37.397555, -5.996695 },
	{ 174, 0, "174_Ronda Tamarguillo", "Aprox. Marqués De Pickman", 37.380612, -5.960574 },
	{ 151, 0, "151_Calle Urquiza", "Aprox. C/ Venecia", 37.394544, -5.979897 },
	{ 54, 0, "054_Plaza San Juan De La Palma", "Aprox. Iglesia", 37.395240, -5.991050 },
	{ 127, 0, "127_Calle Virgen De La Victoria", "Aprox. C/ Asunción", 37.377640, -5.997947 },
	{ 39, 0, "039_Plaza San Antonio De Padua", "Aprox. C/ Marqués De La Mina", 37.397840, -5.998505 },
	{ 63, 0, "063_Calle San Pablo", "Aprox. C/ Bailén", 37.390456, -5.998103 },
	{ 175, 0, "175_Ronda Tamarguillo", "Plaza Ruperto Chapí", 37.377757, -5.960870 },
	{ 26, 0, "026_Avenida De Miraflores", "Aprox. C/ Manuel Ródenas", 37.402495, -5.977678 },
	{ 41, 0, "041_Plaza Calderón De La Barca", "Aprox. C/ Amargura", 37.399583, -5.991029 },
	{ 60, 0, "060_Plaza De La Concordia", "Aprox. C/ Teniente Borges", 37.393957, -5.996899 },
	{ 176, 0, "176_Avenida De La Ciudad Jardín", "Aprox. C/ Profesor Braña", 37.377559, -5.966557 },
	{ 178, 0, "178_Calle José Saramago", "Aprox. Avda Del Alcalde Juan Fernández", 37.373304, -5.973919 },
	{ 59, 0, "059_Avenida De La Palmera", "Aprox. Avenida Del Líbano", 37.371238, -5.989210 },
	{ 147, 0, "147_Carretera De Carmona", "Aprox. C/ Maestro Solano", 37.400796, -5.975228 },
	{ 13, 0, "013_Calle Feria", "Aprox. C/ Resolana", 37.403134, -5.991918 },
	{ 3, 0, "003_Puerta De La Barqueta", "Aprox. Puente De La Barqueta", 37.405642, -5.998488 },
	{ 45, 0, "045_Carretera De Carmona", "Aprox. C/ De Francisco De Ariño", 37.399921, -5.977816 },
	{ 88, 0, "088_Calle Americo Vespucio", "Aprox. C/ Hermanos D'Eluyar", 37.409341, -6.006339 },
	{ 67, 0, "067_Calle Leonardo Da Vinci", "Aprox. C/ Albert Einstein", 37.404163, -6.007302 },
	{ 95, 0, "095_Calle Américo Vespucio", "Aprox. C/ Juan Bautista Muñoz", 37.412174, -6.006338 },
	{ 184, 0, "184_Avenida Alcalde Manuel Del Valle", "Aprox. C/ San Juan De La Salle", 37.408525, -5.970493 },
	{ 99, 0, "099_Calle Américo Vespucio", "Aprox. Gerencia De Urbanismo De Sevilla", 37.397395, -6.010641 },
	{ 179, 0, "179_Ronda Urbana Norte", "Aprox. C/ De Rimas", 37.413163, -5.985131 },
	{ 91, 0, "091_Calle Procurador", "Clara De Jesús Monteto", 37.386907, -6.007674 },
	{ 180, 0, "180_Calle Doctor Jaime Marcos", "Aprox. Avda. Doc. Fedriani", 37.409650, -5.984401 },
	{ 181, 0, "181_Ronda Urbana Norte", "Aprox. C/ Doctor Fedriani", 37.413352, -5.982568 },
	{ 185, 0, "185_Avenida Alcalde Manuel Del Valle", "Aprox. C/ Alejandro Sawa", 37.405094, -5.968862 },
	{ 186, 0, "186_Calle Orfebre Dominguez Vázquez", "Aprox. C/ Pino Montano", 37.408605, -5.973161 },
	{ 197, 0, "197_Calle Agricultores", "Aprox. C/ Estrella Betelgeuse", 37.423439, -5.966404 },
	{ 196, 0, "196_Calle Estrella Canopus", "Aprox. C/ Estrella Betelgeuse", 37.424702, -5.970101 },
	{ 194, 0, "194_Calle Parque De Doñana", "Aprox. Calle Corral De Los Olmos", 37.418733, -5.973194 },
	{ 182, 0, "182_Calle Victoria Kent", "Aprox. Avda Alcalde Manuel Del Valle", 37.414597, -5.973881 },
	{ 198, 0, "198_Calle Mar De Alborán", "Aprox. C/ Camino De Los Toros", 37.420447, -5.967956 },
	{ 191, 0, "191_Glorieta Carlos Cano", "Aprox. C/ Blas Infante", 37.374116, -6.008853 },
	{ 66, 0, "066_Calle Arroyo", "Aprox. Avda. José Laguillo", 37.393626, -5.981869 },
	{ 201, 0, "201_Calle Pino Montano", "Aprox. C/ Estafeta", 37.415684, -5.967858 },
	{ 61, 0, "061_Plaza Del Museo", "Aprox. C/ Alfonso Xii", 37.392813, -5.999344 },
	{ 86, 0, "086_Camino De Los Descubrimientos", "Aprox. Pasarela De La Cartuja", 37.397073, -6.006304 },
	{ 96, 0, "096_Calle Betis", "Aprox. C/ Juan De Lugo", 37.383541, -5.999911 },
	{ 183, 0, "183_Alcalde Manuel Del Valle", "Aprox. C/ Pino Montano", 37.411018, -5.971219 },
	{ 203, 0, "203_Calle Tesalónica", "Calle Mazzantini", 37.396094, -5.958764 },
	{ 200, 0, "200_Camino De Los Toros", "Aprox. C/ Mediterráneo", 37.418914, -5.963217 },
	{ 187, 0, "187_Calle Doctor Laffon", "Aprox. C/ Efeso", 37.395401, -5.964043 },
	{ 199, 0, "199_Mar De Alborán", "Aprox. Corral De Los Olmos", 37.417856, -5.969296 },
	{ 202, 0, "202_Avenida Mujer Trabajadora", "Aprox. Avda Miraflores", 37.411467, -5.966763 },
	{ 195, 0, "195_Calle Corral Del Agua", "Aprox. Camino De Los Toros", 37.421716, -5.971648 },
	{ 177, 0, "177_Avenida Alcalde Juan Fernández", "Aprox. C/ Profesor Buenaventura Pinillos", 37.373068, -5.969094 },
	{ 207, 0, "207_Calle Ifni", "Aprox. Avda De Holanda", 37.355016, -5.982370 },
	{ 205, 0, "205_Avenida Kansas City", "Aprox. Pza El Tato", 37.399817, -5.961922 },
	{ 208, 0, "208_Avenida De Grecia", "Aprox. Avda De Italia", 37.350656, -5.984190 },
	{ 193, 0, "193_Avenida De Coria", "Aprox. C/ Coruña", 37.381111, -6.012005 },
	{ 213, 0, "213_Avenida De Andalucia", "Aprox. Cochera De Tussam", 37.387143, -5.948410 },
	{ 90, 0, "090_Calle Roma", "Aprox. C/ Palos De La Frontera", 37.381198, -5.993528 },
	{ 192, 0, "192_Avenida De Alvar Nuñez", "Aprox. C/ Collante", 37.378334, -6.011556 },
	{ 120, 0, "120_Glorieta San Diego", "Aprox. C/ Palos De La Frontera", 37.378961, -5.989966 },
	{ 188, 0, "188_Avenida Hytasa", "Aprox. C/ Romeral", 37.372560, -5.963362 },
	{ 189, 0, "189_Avenida Hytasa", "Aprox. Nuestra Señora De Los Dolores", 37.370053, -5.959496 },
	{ 123, 0, "123_Estadio Olimpico", "Aprox. Puerta ???", 37.415851, -6.005474 },
	{ 206, 0, "206_Avenida Kansas City", "Aprox. C/ Macedonia", 37.402964, -5.958211 },
	{ 190, 0, "190_Avenida Hytasa", "Aprox. C/ Herramienta", 37.368735, -5.957293 },
	{ 204, 0, "204_Calle Doctor Laffon", "Aprox. C/ Tesalonica", 37.397690, -5.961601 },
	{ 211, 0, "211_Avenida De Alemania", "Aprox. Glorieta De Letonia", 37.346202, -5.976200 },
	{ 212, 0, "212_Avenida Reinido Unido", "Aprox. Avda De Italia", 37.351582, -5.977784 },
	{ 210, 0, "210_Paseo De Europa", "Aprox. Ava De Francia", 37.348061, -5.980058 },
	{ 214, 0, "214_Avenida De Andalucia", "Aprox. Entrada Tussam", 37.387143, -5.948410 },
	{ 215, 0, "215_Calle Zorzal", "Aprox. Avenida De Andalucia", 37.386641, -5.953981 },
	{ 209, 0, "209_Avenida Alemania", "Aprox. Glorieta Chekia", 37.345317, -5.982656 },
	{ 221, 0, "221_Avenida Alcalde Luis Uruñuela", "Aprox. Hotel Sevilla Congresos", 37.405609, -5.930524 },
	{ 219, 0, "219_Calle De La A.D.A.", "Aprox. C/ De Tesalónica", 37.390537, -5.959072 },
	{ 217, 0, "217_Calle De La A.D.A.", "Aprox. C/ Jerusalén", 37.393875, -5.962371 },
	{ 216, 0, "216_Calle Antioquia", "Aprox. Avda De Pedro Romero", 37.399938, -5.956285 },
	{ 220, 0, "220_Avenida Alcalde Luis Uruñuela", "Aprox. Centro Comercial Zona Este", 37.405190, -5.935780 },
	{ 225, 0, "225_Calle Flor De Retama", "Aprox. Centro Deportivo Entreflores", 37.397391, -5.918777 },
	{ 226, 0, "226_Avenida Doctor Emilio Lemos", "Aprox. C/ De Birmania", 37.402863, -5.921754 },
	{ 222, 0, "222_Avenida Alcalde Luis Uruñuela", "Aprox. Palacio De Los Congresos", 37.405084, -5.933616 },
	{ 224, 0, "224_Avenida De Las Ciencias", "Aprox. C/ De Ulises", 37.397014, -5.923757 },
	{ 227, 0, "227_Avenida Alcalde Luis Uruñuela", "Aprox. C/ Carlinga", 37.390754, -5.919636 },
	{ 233, 0, "233_Avenida Alcalde Luis Uruñuela", "Aprox. Estación De Renfe", 37.404113, -5.937092 },
	{ 230, 0, "230_Avenida De Las Ciencias", "Aprox. Avda De La Republica China", 37.403928, -5.928140 },
	{ 229, 0, "229_Avenida Aeronautica", "Aprox. Avda Del Deporte", 37.387354, -5.919919 },
	{ 228, 0, "228_Avenida De Las Ciencias", "Aprox. C/ Flor De Salvia", 37.394450, -5.921231 },
	{ 232, 0, "232_Avenida Alcalde Luis Uruñuela", "Aprox. Pza De La Acogida", 37.403940, -5.939739 },
	{ 234, 0, "234_Calle Médicos Sin Frontera", "Aprox. Avda De Las Ciencias", 37.399940, -5.925164 },
	{ 237, 0, "237_Ciudad De Chiva", "Aprox. C/ Ildefonso Marañon", 37.409335, -5.923255 },
	{ 235, 0, "235_Ciudad De Chiva", "Aprox. C/ Ciudad De Alfajar", 37.411736, -5.929859 },
	{ 231, 0, "231_Avenida Alcalde Luis Uruñuela", "Aprox. Paseo Miguel De Unamuno", 37.401674, -5.942139 },
	{ 238, 0, "238_Ciudad De Chiva", "Aprox. Pza Del Árbol Rey", 37.408133, -5.919993 },
	{ 236, 0, "236_Ciudad De Chiva", "Aprox. C/ Ciudad De Liria", 37.410217, -5.926422 },
	{ 239, 0, "239_Calle Ciudad De Liria", "Aprox. Avda De Fernando", 37.408692, -5.927719 },
	{ 240, 0, "240_Avenida Alcalde Luis Uruñuela", "Aprox. Cueva De La Pileta", 37.402580, -5.940436 },
	{ 243, 0, "243_Glorieta Del Primero De Mayo", "Aprox. C/ Carlos Marx", 37.380439, -5.953481 },
	{ 245, 0, "245_Calle Las Leandras", "Aprox. Avda Los Gavilanes", 37.375399, -5.952549 },
	{ 244, 0, "244_Avenida Los Gavilanes", "Aprox. Avda Juan Xxiii", 37.378040, -5.951784 },
	{ 223, 0, "223_Calle Gema", "Aprox. Avda De Las Ciencias", 37.400731, -5.926324 },
	{ 246, 0, "246_Puerto De Los Azores", "Aprox. C/ Paulo Orosio", 37.376139, -5.955017 },
	{ 37, 0, "037_Alameda De Hércules", "Aprox. C/ Vulcano", 37.398786, -5.993189 },
	{ 241, 0, "241_Plaza Nueva", "Aprox. C/ Mendez Núñez", 37.388815, -5.995864 },
	{ 242, 0, "242_Plaza Nueva", "Aprox. C/ Mendez Núñez", 37.388818, -5.995751 },
	{ 248, 0, "248_Glorieta De Los Ferroviarios", "Aprox. C/ Navarra", 37.421903, -5.983004 },
	{ 250, 0, "250_Calle De Salvador Allende", "Aprox. C/ De Marruecos", 37.421826, -5.985617 },
	{ 249, 0, "249_Calle Navarra", "Aprox. C/ Cataluña", 37.424758, -5.984824 },
	{ 218, 0, "218_Plaza Del Altozano", "Aprox. C/ San Jorge", 37.385124, -6.003542 },
	{0, 0, NULL, NULL, 0., 0.}
};


struct StationsPluginSimplePrivateSeville : StationsPluginSimplePrivate {
  StationsPluginSimplePrivateSeville() {
    rect = QRectF(QPointF(37.182640, -6.012005), QPointF(37.424758, -5.796295));
    center = QPointF(37.382640, -5.996295);
    statusUrl = "http://www.sevici.es/service/stationdetails/%1";
    infosUrl = "http://www.sevici.es/service/carto";
  }

  QList < Station * > fetchAll(StationsPlugin *plugin) {
    QList < Station * > list;

    for (int i = 0; stations[i].name; ++i) {
      Station *station = new Station(plugin);

      station->setId(stations[i].number);
      station->setName(QString::fromUtf8(stations[i].name));
      station->setDescription(QString::fromUtf8(stations[i].address));
      station->setPos(QPointF(stations[i].x, stations[i].y));
      station->setRegion(QString("Seville %1").arg(stations[i].arrondissementNumber));
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

#endif /* STATIONS_SIMPLE_PRIVATE_SEVILLE_H */

