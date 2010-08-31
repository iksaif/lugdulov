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
	{ 1, 0, "001_Glorieta Olimpica", "Glorieta Olimpica - Aprox. Concejal Alberto Jiménez-Becerril", 37.4129235511, -5.98890593824 },
	{ 4, 0, "004_Calle Leonardo Da Vinci", "Aprox C/ Thomas Alba Edison", 37.4101115576, -6.00572226878 },
	{ 6, 0, "006_Camino De Los Descubrimientos", "Aprox. Calle Isaac Newton", 37.4066137898, -6.00297794758 },
	{ 7, 0, "007_Calle Américo Vespucio", "Aprox. Calle De Jacques Cousteau", 37.4074694907, -6.0076033504 },
	{ 8, 0, "008_Calle Leonardo Da Vinci", "Aprox. C/ Gregor Mendel", 37.4009693829, -6.00938173538 },
	{ 10, 0, "010_Calle Jose Diaz", "Aprox. Avda Concejal Alberto Jiménez-Becerril", 37.4093850256, -5.99076600871 },
	{ 11, 0, "011_Calle Avicena", "Aprox. Calle Avenzoar", 37.4071428839, -5.99259029973 },
	{ 12, 0, "012_Plaza Duquesa De Alba", "Barqueta", 37.4038695366, -5.99490422725 },
	{ 14, 0, "014_Avenida Sanchez Pizjuan", "Facultad De Medicina", 37.4064737058, -5.98911873909 },
	{ 15, 0, "015_Calle Dr Marañon", "Aprox. C/ San Juan De Ribera", 37.4060415718, -5.98573370001 },
	{ 16, 0, "016_Calle De Manuel Villalobos", "Aprox. C/ Sor Francisca Dorotea", 37.4070507995, -5.98243050582 },
	{ 17, 0, "017_Calle De Madreselva", "Aprox. Ronda De Pio Xii", 37.4071515556, -5.97884017278 },
	{ 19, 0, "019_Parlamento", "Aprox. C/ Don Fadrique", 37.4033275366, -5.98903720635 },
	{ 20, 0, "020_Calle San Juan De Ribera", "Aprox. C/ Fray Isidoro De Sevilla", 37.4048695437, -5.98653719846 },
	{ 22, 0, "022_Avenida De Llanes", "Aprox. Avda De Miraflores", 37.405129549, -5.97483115756 },
	{ 23, 0, "023_Parlamento", "Aprox. C/ San Juan De Ribera", 37.403337537, -5.98787920229 },
	{ 27, 0, "027_Avenida De Llanes", "Aprox C/ Escultor Francisco Buiza", 37.403877545, -5.97209014722 },
	{ 29, 0, "029_Carretera De Carmona", "Aprox. Avda De Llanes", 37.40246354, -5.97014513959 },
	{ 35, 0, "035_Alameda De Hercules", "Aprox. Calle Peris Mencheta", 37.4006825244, -5.99363022094 },
	{ 36, 0, "036_Calle San Vicente", "Aprox. C/ Guadalquivir", 37.4005005219, -5.99840323758 },
	{ 40, 0, "040_Avenida Reina Mercedes", "Aprox. Glorieta Alcalde De Parias Merry", 37.3563508267, -5.9864598774 },
	{ 42, 0, "042_Plaza Cronista", "Aprox. C/ Divina Pastora", 37.3987059175, -5.98946001682 },
	{ 43, 0, "043_Ronda Capuchinos", "Aprox. C/ Maestro Quiroga", 37.3991560874, -5.98273663003 },
	{ 44, 0, "044_Ronda Capuchinos", "Aprox. C/ Corinto", 37.3983389723, -5.98164002676 },
	{ 46, 0, "046_Plaza Del Pelicano", "Aprox. C/ Enladrilladas", 37.3975935156, -5.98387318493 },
	{ 48, 0, "048_Calle Churruca", "Aprox. C/ Gonzáles Cuadrado", 37.3971565112, -5.99106620992 },
	{ 49, 0, "049_Alameda De Hercules", "Aprox. C/ Amor De Dios", 37.396865509, -5.99392721979 },
	{ 51, 0, "051_Avenida Torneo", "Aprox. C/ Luis Rey Romero", 37.3955195006, -6.00232124847 },
	{ 52, 0, "052_Calle Del Inca Garcilaso", "Aprox. C/ Jerónimo De Aguilar", 37.3942264925, -6.01030927576 },
	{ 55, 0, "055_Calle De Maria Auxiliadora", "Aprox. C/ Gonzalo De Bilbao", 37.3933184986, -5.9837661821 },
	{ 57, 0, "057_Plaza Cristo De Burgos", "Pza De San Pedro", 37.3923186167, -5.98970518709 },
	{ 58, 0, "058_Calle Regina", "Aprox. Pza De La Encarnación", 37.3943672228, -5.99154499304 },
	{ 62, 0, "062_Plaza De Armas", "Avda Torneo (Estación De Autobuses)", 37.3910614825, -6.00315024881 },
	{ 64, 0, "064_Calle Cuesta De Rosario", "Pza De La Pescadería", 37.3898564821, -5.99112520592 },
	{ 69, 0, "069_Calle Jose Laguillo", "Aprox. Pablo Iglesias", 37.3920104954, -5.97829316215 },
	{ 70, 0, "070_Estación Renfe Santa Justa", "Estación Renfe Santa Justa", 37.3911584928, -5.97597115351 },
	{ 73, 0, "073_Plaza San Agustin", "Aprox. C/ Concepción", 37.3895138623, -5.98436278955 },
	{ 75, 0, "075_Plaza San Francisco", "Aprox C/ Hernando Colón", 37.3879973777, -5.99358744664 },
	{ 77, 0, "077_Plaza Chapina", "Aprox. Hotel Abba Triana", 37.3896294751, -6.00758126354 },
	{ 78, 0, "078_Calle Alfareria", "Aprox. Ronda De Triana", 37.3885711332, -6.01028237835 },
	{ 79, 0, "079_Plaza De Las Mercedarias", "Aprox. C/ Ibarra", 37.3883264775, -5.98690419023 },
	{ 81, 0, "081_Calle Luis Montoto", "Aprox. C/ Benitos Mas Y Prat", 37.3871562027, -5.97101676789 },
	{ 85, 0, "085_Paseo Catalina Ribera", "Frente A La Diputación Provincial", 37.3853514657, -5.9867851881 },
	{ 92, 0, "092_Ronda De Triana", "Aprox. C/ De Manuel Arellano", 37.3858384698, -6.01122037762 },
	{ 93, 0, "093_Ronda De Triana", "Aprox. C/ San Vicente De Paul", 37.3831234479, -6.01087627136 },
	{ 98, 0, "098_Avenida De Roma", "Puerta De Jerez", 37.3820433503, -5.99303016926 },
	{ 100, 0, "100_Paseo Catalina Ribera", "Aprox. C/ San Fernando", 37.3815161483, -5.98899864814 },
	{ 101, 0, "101_Prado De San Sebastian", "Estación De Autobuses", 37.3811156819, -5.98694975128 },
	{ 104, 0, "104_Avenida Eduardo Dato", "Aprox. C/ Fuenteovejuna", 37.3841359269, -5.9796766763 },
	{ 107, 0, "107_Calle Luis Morales", "Aprox. Nervión Plaza", 37.3842594665, -5.97259113768 },
	{ 108, 0, "108_Avenida Eduardo Dato", "Aprox. Avda De San Francisco Javier", 37.3828525035, -5.97324949194 },
	{ 109, 0, "109_Avenida San Francisco Javier", "Aprox. C/ Camilo José Cela", 37.3798841361, -5.97438277001 },
	{ 113, 0, "113_Plaza San Martín De Porres", "Aprox. Avda Alvar Núñez", 37.3807784392, -6.00917926405 },
	{ 118, 0, "118_Plaza De Cuba", "Aprox. Puente De San Telmo", 37.3797914163, -5.99710779642 },
	{ 125, 0, "125_Avenida San Francisco Javier", "Aprox. Avda De Ramón Y Cajal", 37.3774064383, -5.97490014182 },
	{ 129, 0, "129_Calle Virgen De Lujan", "Aprox. Virgen De La Victoria", 37.3746684173, -6.00245523693 },
	{ 130, 0, "130_Glorieta Republica Dominicana", "Aprox. C/ López De Gomara", 37.375745418, -6.0052477273 },
	{ 132, 0, "132_Calle Paez De Ribera", "Aprox. Paseo De La Palmera", 37.3636193796, -5.98478516853 },
	{ 133, 0, "133_Avenida Santa Fe", "Aprox. C/ Virgen De La Oliva", 37.3740394141, -6.00419824268 },
	{ 135, 0, "135_Calle Virgen De Luján", "Aprox. Glorieta Las Cigarreras", 37.3746514204, -5.99380120654 },
	{ 138, 0, "138_Calle Ramón Carande", "Aprox. C/ San Salvador", 37.3743704247, -5.97893415422 },
	{ 139, 0, "139_Avenida Diego Martinez Barrio", "Aprox. Avda Gal Garcia De La Herranz", 37.3750752589, -5.97586312558 },
	{ 142, 0, "142_Calle Ramon De Carranza", "Aprox. C/ Asunción", 37.3716514071, -5.99721221678 },
	{ 143, 0, "143_Calle Ramon De Carranza", "Aprox. C/ Virgen De La Oliva", 37.3717244052, -6.00331223824 },
	{ 145, 0, "145_Avenida Reina Mercedes", "Aprox. C/ Profesor García González", 37.3602332289, -5.98631823405 },
	{ 146, 0, "146_Avenida Reina Mercedes", "Aprox. C/ Profesor García González", 37.3601006264, -5.98631297488 },
	{ 148, 0, "148_Calle Tharsis", "Aprox. C/ Aorno", 37.3987676757, -5.97318239593 },
	{ 149, 0, "149_Calle Arroyo", "Aprox. C/ Tena", 37.3978299294, -5.9756717204 },
	{ 152, 0, "152_Calle Samaniego", "Aprox. C/ Esperanza De La Trinidad", 37.3957905119, -5.97437315058 },
	{ 154, 0, "154_Avenida Kansas City", "Aprox. C/ Naranjito De Triana", 37.3948365102, -5.96842612917 },
	{ 155, 0, "155_Avenida Kansas City", "Aprox. Avda El Greco", 37.3929105017, -5.97073913617 },
	{ 160, 0, "160_Calle Arjona", "Aprox. Puente De Triana", 37.3873864278, -6.0015848435 },
	{ 161, 0, "161_Avenida Alcalde Manuel Del Valle", "Aprox. C/ Baltasar De Alcázar", 37.4000005306, -5.96910313452 },
	{ 9, 0, "009_Camino De Los Descubrimientos", "Aprox. C/ Albert Einstein", 37.4033245311, -6.00402025891 },
	{ 122, 0, "122_Calle Enramadilla", "Aprox. C/ Balbino Marrón", 37.3784844413, -5.97838915468 },
	{ 124, 0, "124_Calle Enramadilla", "Aprox. C/ Barrau", 37.3777304387, -5.97724415023 },
	{ 157, 0, "157_Avenida Cardenal Bueno Monreal", "Aprox. Avda Ramón Carande", 37.3697994054, -5.97819472282 },
	{ 159, 0, "159_Avenida Cardenal Bueno Monreal", "Approx. Avda Manuel Siurot", 37.3680453973, -5.98485417133 },
	{ 158, 0, "158_Avenida Cardenal Bueno Monreal", "Aprox. C/ Bogota", 37.3688534017, -5.98161816044 },
	{ 140, 0, "140_Calle Felipe Ii", "Aprox. Avda Diego Martínez Barrio", 37.3723704173, -5.97736214754 },
	{ 116, 0, "116_Calle Manuel Siurot", "Aprox. Hospital Universitario Virgen Del Rocio", 37.3614303721, -5.98160315609 },
	{ 141, 0, "141_Calle Felipe Ii", "Aprox. C/ Ramón Carande", 37.3717334496, -5.98189535424 },
	{ 21, 0, "021_Calle Manuel Villalobos", "Aprox. C/ Madre San Marcelo", 37.4054735479, -5.98152718124 },
	{ 25, 0, "025_Avenida De La Cruz Roja", "Aprox. C/ Albaida", 37.4031325387, -5.98110917842 },
	{ 31, 0, "031_Avenida De Miraflores", "Aprox. C/ Albaida", 37.4005415289, -5.97978117228 },
	{ 53, 0, "053_Calle Reyes Católicos", "Aprox. C/ Gravina", 37.3893414769, -5.99960523538 },
	{ 65, 0, "065_Calle Alhóndiga", "Aprox. Card. Cervantes", 37.3912994889, -5.98814019628 },
	{ 72, 0, "072_Calle Amador De Los Rios", "Aprox. C/ Lope De Vega", 37.3907124885, -5.9827681771 },
	{ 74, 0, "074_Plaza Pilatos", "Aprox. C/ San Esteban", 37.3897714833, -5.98689719104 },
	{ 83, 0, "083_Avenida La Buhaira", "Aprox. Avda Luis Montoto", 37.3869554753, -5.97805115838 },
	{ 84, 0, "084_Calle José María Moreno Galván", "Aprox. C/ Juan Antonio Cabestany", 37.387350475, -5.98306817621 },
	{ 97, 0, "097_Paseo De Cristóbal Colón", "Aprox. Torre Del Oro", 37.3815354472, -5.99555221666 },
	{ 106, 0, "106_Avenida Eduardo Dato", "Aprox. C/ Oscar Carvallo", 37.3837974629, -5.97745415447 },
	{ 131, 0, "131_Calle Tabladilla", "Aprox. C/ Cardenal Ilundaín", 37.3647503854, -5.98145215749 },
	{ 134, 0, "134_Calle Virgen De Luján", "Aprox. C/ Asunción", 37.3747704191, -5.99853622323 },
	{ 137, 0, "137_Avenida De La Borbolla", "Aprox. C/ Porvenir", 37.3737584198, -5.98551717696 },
	{ 150, 0, "150_Calle San Juan Bosco", "Aprox. C/ Arroyo", 37.3967485141, -5.97863416607 },
	{ 24, 0, "024_Calle León Xiii", "Aprox. C/ Fray Isidoro De Sevilla", 37.404035541, -5.98459219116 },
	{ 32, 0, "032_Calle Muñoz León", "Aprox. C/ Morera", 37.4020195324, -5.98632319607 },
	{ 80, 0, "080_Calle Luis Montoto", "Aprox. C/ Alberto Duero", 37.3876274769, -5.98102716921 },
	{ 82, 0, "082_Calle Luis Montoto", "Aprox. C/ Maese Farfán", 37.387098477, -5.97484314721 },
	{ 102, 0, "102_Calle Juan De Mata Carriazo", "Aprox. Antigua Estación San Bernardo", 37.3827394564, -5.98372017584 },
	{ 5, 0, "005_Camino De Los Descubrimientos", "Aprox. C/ Thomás Alba Edison", 37.4110435627, -6.00195925611 },
	{ 68, 0, "068_Calle Juan Antonio Cabestany", "Aprox. Calle Júpiter", 37.3902924879, -5.97996416702 },
	{ 119, 0, "119_Avenida De Chile", "Aprox. Costurero De La Reina", 37.377404432, -5.99196520169 },
	{ 164, 0, "164_Calle Luis Montoto", "Aprox. C/ El Greco", 37.3876493509, -5.96565525205 },
	{ 166, 0, "166_Ronda Del Tamarguillo", "Aprox. Centro Comercial Los Arcos", 37.3885904887, -5.95924009336 },
	{ 165, 0, "165_Avenida De Andalucia", "Aprox. Centro Comercial Los Arcos", 37.3876454843, -5.96095309882 },
	{ 112, 0, "112_Avda Esperanza De Triana", "Aprox. Plaza Amadeo Janone", 37.3801534385, -6.00438324686 },
	{ 144, 0, "144_Avenida De La Palmera", "Aprox. Clinica De Fátima", 37.3691263394, -5.98808039728 },
	{ 162, 0, "162_Avenida Solea", "Aprox. C/ Media Granaína", 37.3915404971, -5.96846612741 },
	{ 156, 0, "156_Avenida Kansas City", "Aprox. C/ Baltasar Gracián", 37.3914534111, -5.97276175509 },
	{ 76, 0, "076_Plaza Nueva", "Aprox. C/ Jaen", 37.3889394767, -5.99564622126 },
	{ 87, 0, "087_Plaza Nueva", "Aprox. C/ Tetuan", 37.388966477, -5.99529422004 },
	{ 121, 0, "121_Calle Doctor Pedro De Castro", "Aprox. C/ Doc. Gabriel Sánchez", 37.3771584347, -5.98193516636 },
	{ 153, 0, "153_Avenida Reina Mercedes", "Aprox. Escuela De Arquitectura", 37.3629713765, -5.98626217333 },
	{ 94, 0, "094_Plaza Del Zurraque", "Aprox. C/ Doc. Jeronimo Pou", 37.3833694499, -6.00829426244 },
	{ 38, 0, "038_Calle De Inca Garcilaso", "Aprox. C/ Juan Antonio De Vizarrón", 37.3920814836, -6.01105127713 },
	{ 114, 0, "114_Glorieta Plus Ultra", "Aprox. Estadio Manuel Ruiz De Lopera", 37.3563723527, -5.97926214495 },
	{ 136, 0, "136_Calle Asunción", "Aprox. C/ Virgen De La Antigua", 37.3731194128, -5.99761021903 },
	{ 18, 0, "018_Avenida Eduardo Dato", "Aprox. C/ Marqués Del Nervión", 37.3820754594, -5.96812112074 },
	{ 128, 0, "128_Calle Arqueros", "Aprox. C/ Naos", 37.3764534251, -6.00063223156 },
	{ 168, 0, "168_Avenida Ramón Y Cajal", "Aprox. Avda De La Ciudad Jardín", 37.3750574317, -5.96749211448 },
	{ 105, 0, "105_Calle Francisco Murillo", "Aprox. C/ Manuel Siurot", 37.3589103624, -5.98062015118 },
	{ 117, 0, "117_Avda Esperanza De Triana", "Aprox. Avda Republica Argentina", 37.3778064297, -6.00261323929 },
	{ 71, 0, "071_Avenida Kansas City", "Aprox. Hotel Occidental", 37.3900304888, -5.97449114767 },
	{ 2, 0, "002_Gran Plaza", "Gran Plaza - Aprox. Calle Marquez De Pickman", 37.3815780453, -5.9652239664 },
	{ 167, 0, "167_Glorieta Bizco Amate", "Aprox. Avda Ramón Y Cajal", 37.3733496683, -5.9649336132 },
	{ 126, 0, "126_Avenida Reina Mercedes", "Aprox. Facultad De Informática", 37.3581648588, -5.98648270871 },
	{ 169, 0, "169_Avenida Ramón Y Cajal", "Aprox. C/ Villegas Marmolejo", 37.3765014355, -5.97266713346 },
	{ 170, 0, "170_Plaza Antonio Aparicio Herrero", "Aprox. C/ San Juan De Dios", 37.3789664467, -5.96892312176 },
	{ 28, 0, "028_Calle Rafael Salgado", "Aprox. C/ Castillo Alcala De Guadaira", 37.3602613692, -5.97665913807 },
	{ 33, 0, "033_Calle León Xiii", "Aprox. C/ Antonio Pantión", 37.4014605311, -5.98369018652 },
	{ 89, 0, "089_Calle Adriano", "Aprox. C/ Antonia Díaz", 37.3864814661, -5.99779022737 },
	{ 171, 0, "171_Calle Alfonso Laso De La Vega", "Aprox. Parroco Antonio González", 37.3661463934, -5.9748701352 },
	{ 172, 0, "172_Ronda Tamarguillo", "Aprox. Alfonso Laso De La Vega", 37.3671723988, -5.97121112296 },
	{ 173, 0, "173_Ronda Tamarguillo", "Aprox. Avda De La Paz", 37.3700484115, -5.96806411358 },
	{ 30, 0, "030_Avenida Eduardo Dato", "Detrás Estadio Sánchez Pizjuan", 37.3826284606, -5.97085313064 },
	{ 111, 0, "111_Pza Farmacéutico Murillo Herrera", "Aprox. C/ Pajes De Corro", 37.3813174443, -6.00105323584 },
	{ 115, 0, "115_Calle Lopez De Gomara", "En Frente Instituto Adolfo Becker", 37.3778924284, -6.00723725557 },
	{ 163, 0, "163_Calle Sinaí", "Aprox. C/ Baltazar Gracián", 37.3899544899, -5.97080213469 },
	{ 34, 0, "034_Plaza Pumarejo", "Aprox. Calle San Luis", 37.4010275276, -5.98857820341 },
	{ 47, 0, "047_Calle Hiniesta", "Aprox. Convento Santa Isabel", 37.3971325126, -5.98703719577 },
	{ 50, 0, "050_Calle De Hernán Cortés", "Aprox. C/ Eslava", 37.3975545107, -5.9966952299 },
	{ 174, 0, "174_Ronda Tamarguillo", "Aprox. Marqués De Pickman", 37.3806124564, -5.96057409343 },
	{ 151, 0, "151_Calle Urquiza", "Aprox. C/ Venecia", 37.3945444669, -5.97989719435 },
	{ 54, 0, "054_Plaza San Juan De La Palma", "Aprox. Iglesia", 37.3952395036, -5.99105020876 },
	{ 127, 0, "127_Calle Virgen De La Victoria", "Aprox. C/ Asunción", 37.3776404308, -5.99794722282 },
	{ 39, 0, "039_Plaza San Antonio De Padua", "Aprox. C/ Marqués De La Mina", 37.3978400223, -5.99850468688 },
	{ 63, 0, "063_Calle San Pablo", "Aprox. C/ Bailén", 37.3904564819, -5.99810323075 },
	{ 175, 0, "175_Ronda Tamarguillo", "Plaza Ruperto Chapí", 37.3777574449, -5.96087009281 },
	{ 26, 0, "026_Avenida De Miraflores", "Aprox. C/ Manuel Ródenas", 37.4024945374, -5.97767816602 },
	{ 41, 0, "041_Plaza Calderón De La Barca", "Aprox. C/ Amargura", 37.3995825209, -5.99102921118 },
	{ 60, 0, "060_Plaza De La Concordia", "Aprox. C/ Teniente Borges", 37.3939574963, -5.99689922854 },
	{ 176, 0, "176_Avenida De La Ciudad Jardín", "Aprox. C/ Profesor Braña", 37.377559442, -5.96655711264 },
	{ 178, 0, "178_Calle José Saramago", "Aprox. Avda Del Alcalde Juan Fernández", 37.3733040763, -5.97391890132 },
	{ 59, 0, "059_Avenida De La Palmera", "Aprox. Avenida Del Líbano", 37.3712384084, -5.98921018846 },
	{ 147, 0, "147_Carretera De Carmona", "Aprox. C/ Maestro Solano", 37.4007955315, -5.97522815646 },
	{ 13, 0, "013_Calle Feria", "Aprox. C/ Resolana", 37.4031335348, -5.99191821634 },
	{ 3, 0, "003_Puerta De La Barqueta", "Aprox. Puente De La Barqueta", 37.4056415424, -5.99848824083 },
	{ 45, 0, "045_Carretera De Carmona", "Aprox. C/ De Francisco De Ariño", 37.3999205271, -5.97781616503 },
	{ 88, 0, "088_Calle Americo Vespucio", "Aprox. C/ Hermanos D'Eluyar", 37.4093412771, -6.00633885939 },
	{ 67, 0, "067_Calle Leonardo Da Vinci", "Aprox. C/ Albert Einstein", 37.4041625333, -6.00730227091 },
	{ 95, 0, "095_Calle Américo Vespucio", "Aprox. C/ Juan Bautista Muñoz", 37.4121735656, -6.00633827212 },
	{ 184, 0, "184_Avenida Alcalde Manuel Del Valle", "Aprox. C/ San Juan De La Salle", 37.4085245641, -5.97049314429 },
	{ 99, 0, "099_Calle Américo Vespucio", "Aprox. Gerencia De Urbanismo De Sevilla", 37.397394505, -6.01064127874 },
	{ 179, 0, "179_Ronda Urbana Norte", "Aprox. C/ De Rimas", 37.4131631774, -5.98513122164 },
	{ 91, 0, "091_Calle Procurador", "Clara De Jesús Monteto", 37.3869074642, -6.0076742623 },
	{ 180, 0, "180_Calle Doctor Jaime Marcos", "Aprox. Avda. Doc. Fedriani", 37.4096495635, -5.98440119371 },
	{ 181, 0, "181_Ronda Urbana Norte", "Aprox. C/ Doctor Fedriani", 37.4133515789, -5.98256818941 },
	{ 185, 0, "185_Avenida Alcalde Manuel Del Valle", "Aprox. C/ Alejandro Sawa", 37.4050943157, -5.96886213517 },
	{ 186, 0, "186_Calle Orfebre Dominguez Vázquez", "Aprox. C/ Pino Montano", 37.4086045634, -5.9731611537 },
	{ 197, 0, "197_Calle Agricultores", "Aprox. C/ Estrella Betelgeuse", 37.4234386251, -5.96640413852 },
	{ 196, 0, "196_Calle Estrella Canopus", "Aprox. C/ Estrella Betelgeuse", 37.4247016288, -5.9701011522 },
	{ 194, 0, "194_Calle Parque De Doñana", "Aprox. Calle Corral De Los Olmos", 37.4187326038, -5.97319415962 },
	{ 182, 0, "182_Calle Victoria Kent", "Aprox. Avda Alcalde Manuel Del Valle", 37.4145965871, -5.97388115966 },
	{ 198, 0, "198_Calle Mar De Alborán", "Aprox. C/ Camino De Los Toros", 37.4204466126, -5.96795614224 },
	{ 191, 0, "191_Glorieta Carlos Cano", "Aprox. C/ Blas Infante", 37.3741164127, -6.00885325908 },
	{ 66, 0, "066_Calle Arroyo", "Aprox. Avda. José Laguillo", 37.3936255005, -5.98186917562 },
	{ 201, 0, "201_Calle Pino Montano", "Aprox. C/ Estafeta", 37.4156835936, -5.96785813917 },
	{ 61, 0, "061_Plaza Del Museo", "Aprox. C/ Alfonso Xii", 37.3928134909, -5.99934423646 },
	{ 86, 0, "086_Camino De Los Descubrimientos", "Aprox. Pasarela De La Cartuja", 37.3970725053, -6.00630426334 },
	{ 96, 0, "096_Calle Betis", "Aprox. C/ Juan De Lugo", 37.3835407312, -5.99991072282 },
	{ 183, 0, "183_Alcalde Manuel Del Valle", "Aprox. C/ Pino Montano", 37.4110175738, -5.97121914827 },
	{ 203, 0, "203_Calle Tesalónica", "Calle Mazzantini", 37.3960935188, -5.95876409602 },
	{ 200, 0, "200_Camino De Los Toros", "Aprox. C/ Mediterráneo", 37.4189136082, -5.96321712475 },
	{ 187, 0, "187_Calle Doctor Laffon", "Aprox. C/ Efeso", 37.3954005141, -5.96404311413 },
	{ 199, 0, "199_Mar De Alborán", "Aprox. Corral De Los Olmos", 37.4178556017, -5.96929614546 },
	{ 202, 0, "202_Avenida Mujer Trabajadora", "Aprox. Avda Miraflores", 37.4114665772, -5.96676313291 },
	{ 195, 0, "195_Calle Corral Del Agua", "Aprox. Camino De Los Toros", 37.4217156163, -5.97164815591 },
	{ 177, 0, "177_Avenida Alcalde Juan Fernández", "Aprox. C/ Profesor Buenaventura Pinillos", 37.3730684231, -5.96909411894 },
	{ 207, 0, "207_Calle Ifni", "Aprox. Avda De Holanda", 37.3550163462, -5.98237015507 },
	{ 205, 0, "205_Avenida Kansas City", "Aprox. Pza El Tato", 37.3998171463, -5.96192234187 },
	{ 208, 0, "208_Avenida De Grecia", "Aprox. Avda De Italia", 37.3506563281, -5.98419015892 },
	{ 193, 0, "193_Avenida De Coria", "Aprox. C/ Coruña", 37.3811114395, -6.01200527417 },
	{ 213, 0, "213_Avenida De Andalucia", "Aprox. Cochera De Tussam", 37.3871434869, -5.94841005455 },
	{ 90, 0, "090_Calle Roma", "Aprox. C/ Palos De La Frontera", 37.3811984466, -5.99352820936 },
	{ 192, 0, "192_Avenida De Alvar Nuñez", "Aprox. C/ Collante", 37.3783344286, -6.01155627099 },
	{ 120, 0, "120_Glorieta San Diego", "Aprox. C/ Palos De La Frontera", 37.3789614414, -5.98996619559 },
	{ 188, 0, "188_Avenida Hytasa", "Aprox. C/ Romeral", 37.3725604236, -5.96336209845 },
	{ 189, 0, "189_Avenida Hytasa", "Aprox. Nuestra Señora De Los Dolores", 37.3700534164, -5.9594960837 },
	{ 123, 0, "123_Estadio Olimpico", "Aprox. Puerta ???", 37.4158505801, -6.00547427133 },
	{ 206, 0, "206_Avenida Kansas City", "Aprox. C/ Macedonia", 37.4029635484, -5.95821109781 },
	{ 190, 0, "190_Avenida Hytasa", "Aprox. C/ Herramienta", 37.36873541, -5.9572930748 },
	{ 204, 0, "204_Calle Doctor Laffon", "Aprox. C/ Tesalonica", 37.3976896919, -5.96160136487 },
	{ 211, 0, "211_Avenida De Alemania", "Aprox. Glorieta De Letonia", 37.3462023107, -5.97620012854 },
	{ 212, 0, "212_Avenida Reinido Unido", "Aprox. Avda De Italia", 37.3515823377, -5.97778413753 },
	{ 210, 0, "210_Paseo De Europa", "Aprox. Ava De Francia", 37.3480613203, -5.98005814259 },
	{ 214, 0, "214_Avenida De Andalucia", "Aprox. Entrada Tussam", 37.3871434869, -5.94841005455 },
	{ 215, 0, "215_Calle Zorzal", "Aprox. Avenida De Andalucia", 37.3866414803, -5.95398107415 },
	{ 209, 0, "209_Avenida Alemania", "Aprox. Glorieta Chekia", 37.3453173116, -5.98265615037 },
	{ 221, 0, "221_Avenida Alcalde Luis Uruñuela", "Aprox. Hotel Sevilla Congresos", 37.405608563, -5.93052400216 },
	{ 219, 0, "219_Calle De La A.D.A.", "Aprox. C/ De Tesalónica", 37.390536501, -5.9590720937 },
	{ 217, 0, "217_Calle De La A.D.A.", "Aprox. C/ Jerusalén", 37.3938745054, -5.96237110682 },
	{ 216, 0, "216_Calle Antioquia", "Aprox. Avda De Pedro Romero", 37.3999375308, -5.95628508909 },
	{ 220, 0, "220_Avenida Alcalde Luis Uruñuela", "Aprox. Centro Comercial Zona Este", 37.4051895619, -5.93578002062 },
	{ 225, 0, "225_Calle Flor De Retama", "Aprox. Centro Deportivo Entreflores", 37.3973905402, -5.91877695628 },
	{ 226, 0, "226_Avenida Doctor Emilio Lemos", "Aprox. C/ De Birmania", 37.4028628717, -5.92175367633 },
	{ 222, 0, "222_Avenida Alcalde Luis Uruñuela", "Aprox. Palacio De Los Congresos", 37.405083565, -5.9336160129 },
	{ 224, 0, "224_Avenida De Las Ciencias", "Aprox. C/ De Ulises", 37.3970135395, -5.92375697414 },
	{ 227, 0, "227_Avenida Alcalde Luis Uruñuela", "Aprox. C/ Carlinga", 37.3907535142, -5.91963595581 },
	{ 233, 0, "233_Avenida Alcalde Luis Uruñuela", "Aprox. Estación De Renfe", 37.4041125561, -5.93709202497 },
	{ 230, 0, "230_Avenida De Las Ciencias", "Aprox. Avda De La Republica China", 37.4039275594, -5.9281399932 },
	{ 229, 0, "229_Avenida Aeronautica", "Aprox. Avda Del Deporte", 37.3873544949, -5.91991895459 },
	{ 228, 0, "228_Avenida De Las Ciencias", "Aprox. C/ Flor De Salvia", 37.3944495238, -5.92123096356 },
	{ 232, 0, "232_Avenida Alcalde Luis Uruñuela", "Aprox. Pza De La Acogida", 37.4039395588, -5.93973903344 },
	{ 234, 0, "234_Calle Médicos Sin Frontera", "Aprox. Avda De Las Ciencias", 37.3999401269, -5.92516396434 },
	{ 237, 0, "237_Ciudad De Chiva", "Aprox. C/ Ildefonso Marañon", 37.4093345857, -5.92325497977 },
	{ 235, 0, "235_Ciudad De Chiva", "Aprox. C/ Ciudad De Alfajar", 37.411735811, -5.9298590713 },
	{ 231, 0, "231_Avenida Alcalde Luis Uruñuela", "Aprox. Paseo Miguel De Unamuno", 37.4016735465, -5.94213904101 },
	{ 238, 0, "238_Ciudad De Chiva", "Aprox. Pza Del Árbol Rey", 37.4081325738, -5.91999304849 },
	{ 236, 0, "236_Ciudad De Chiva", "Aprox. C/ Ciudad De Liria", 37.4102171143, -5.92642237406 },
	{ 239, 0, "239_Calle Ciudad De Liria", "Aprox. Avda De Fernando", 37.4086915827, -5.92771899455 },
	{ 240, 0, "240_Avenida Alcalde Luis Uruñuela", "Aprox. Cueva De La Pileta", 37.4025795445, -5.94043558509 },
	{ 243, 0, "243_Glorieta Del Primero De Mayo", "Aprox. C/ Carlos Marx", 37.3804394812, -5.95348119746 },
	{ 245, 0, "245_Calle Las Leandras", "Aprox. Avda Los Gavilanes", 37.3753988112, -5.95254946625 },
	{ 244, 0, "244_Avenida Los Gavilanes", "Aprox. Avda Juan Xxiii", 37.378040029, -5.95178368563 },
	{ 223, 0, "223_Calle Gema", "Aprox. Avda De Las Ciencias", 37.4007313596, -5.92632420198 },
	{ 246, 0, "246_Puerto De Los Azores", "Aprox. C/ Paulo Orosio", 37.3761390625, -5.95501731701 },
	{ 37, 0, "037_Alameda De Hércules", "Aprox. C/ Vulcano", 37.3987857728, -5.99318901314 },
	{ 241, 0, "241_Plaza Nueva", "Aprox. C/ Mendez Núñez", 37.3888154433, -5.99586378805 },
	{ 242, 0, "242_Plaza Nueva", "Aprox. C/ Mendez Núñez", 37.3888183039, -5.9957509763 },
	{ 248, 0, "248_Glorieta De Los Ferroviarios", "Aprox. C/ Navarra", 37.4219030237, -5.98300428809 },
	{ 250, 0, "250_Calle De Salvador Allende", "Aprox. C/ De Marruecos", 37.4218256116, -5.98561720497 },
	{ 249, 0, "249_Calle Navarra", "Aprox. C/ Cataluña", 37.4247584317, -5.98482367336 },
	{ 218, 0, "218_Plaza Del Altozano", "Aprox. C/ San Jorge", 37.3851244185, -6.00354214744 },
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

