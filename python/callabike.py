#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  callabike.py

  Copyright (C) 2011 Corentin Chary <corentin.chary@gmail.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
  for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  www.callabike-interaktiv.de

"""

import sys
import os
import datetime
import xml.dom.minidom
import json
import re
import urllib
from unicodedata import normalize
from plugin import *

class CallABike(Provider):
    def get_countries(self):
        country = Country()
        country.uid = 'de'
        country.name = 'Germany'
        return [country]

    def nametoid(self, name):
        name = name.lower().strip().replace(' ', '-')
        return name #return normalize("NFD", name).encode("ascii", "ignore")

    def getcookies(self):
        """
        <option class="jq-cabfix" value="100006" >Aachen</option>
        <option class="jq-cab(fix|flex)" value="(\d+)" (.*)>(.*)</option>
        """

        fp = urlopen('http://www.callabike-interaktiv.de/kundenbuchung/process.php?proc=bikesuche')
        fp.read()

    def hal2marker(self, data):

        ret = []

        for node in re.findall('createHAL2Marker\((.*?),{(.*)}\);', data):
            marker = {}

            data = node[0].strip()
            elems = data.split(",")

            marker['lat'] = elems[1][1:-1]
            marker['lng'] = elems[0][1:-1]
            marker['id'] = elems[3][1:-1]
            marker['name'] = elems[4][1:-1]

            matches = re.search("bikes: \"([0-9,]*?)\"", node[1])
            if matches:
                marker['bikes'] = matches.group(1)
            else:
                marker['bikes'] = ""
            ret.append(marker)
        return ret

    def get_cities(self, country):
        ret = []

        """
        http://www.callabike-interaktiv.de/kundenbuchung/process.php?proc=jsoncall&callee=staedtemarker
        createHAL2Marker('6.090898520000000','50.768286300000010','stadtIcon500','s100006','Aachen',4,11,'openDynamicInfoWindow', '', '', '', '',false,{minZoom: 4,maxZoom: 11,proc: "bikesuche",infotyp: "cab_stadt_info",objectname: "stadtmarker"});
        """

        self.getcookies()
        fp = urlopen('http://www.callabike-interaktiv.de/kundenbuchung/process.php?proc=jsoncall&callee=staedtemarker')
        data = fp.read()
        markers = self.hal2marker(data)

        for marker in markers:
            city = City()
            city.name = marker['name'].decode('latin9')
            city.internalId = marker['id'][1:]
            city.id = self.nametoid(city.name) + "_" + city.internalId
            city.uid = city.id
            city.bikeName = "CallABike"
            city.lat = float(marker['lat'])
            city.lng = float(marker['lng'])
            city.type = "CallABike"
            city.create_rect(1)
            ret.append(city)
        return ret

    def get_zones(self, city):
        return []

    def get_stations(self, city):
        url = 'http://www.callabike-interaktiv.de/kundenbuchung/hal2ajax_process.php?ajxmod=bikesearch&f=500&requester=/kundenbuchung/process.php&popup='

        values = [('xajax', 'showStadtOverview'),
                  #('xajaxr', 1316849844001),
                  ('xajaxargs[]', city.internalId),
                  ('xajaxargs[]', '<xjxobj><e><k>kerngebiet</k><v>true</v></e></xjxobj>')]

        data = urllib.urlencode(values)
        data = data.replace("xajaxargs%5B%5D=", "xajaxargs[]=");

        fp = urlopen(url, data)

        data = fp.read()
        markers = self.hal2marker(data)

        """
        POST /kundenbuchung/hal2ajax_process.php?ajxmod=bikesearch&f=500&requester=/kundenbuchung/process.php&popup= HTTP/1.1
        Content-Type: application/x-www-form-urlencoded
        Cookie: PHPSESSID=73931c1c2e79247fcdd27250d01e0687; fe_typo_user=73b86752a1094cdc98d4530391e63a71; _skey=a%3A3%3A%7Bs%3A1%3A%22f%22%3Bs%3A3%3A%22500%22%3Bs%3A4%3A%22sess%22%3Bs%3A32%3A%220659d6c46bf2de813af876b3151614d4%22%3Bs%3A1%3A%22s%22%3Bb%3A0%3B%7D

        createHAL2Marker('6.090320000000000','50.768200000000000','bikeIcon','17583929703681','5200 5200 Hauptbahnhof',11,false,'openDynamicInfoWindow', '', '', '', '',false,{minZoom: 11,maxZoom: false,proc: "bikesuche",cabfixflex: "fix",firmen: "500,510,590",objectname: "bikemarker",meta_id: "594",standort_id: "207778",bikes: "",clustername: "bikecluster"});

        createHAL2Marker('13.379531800000000','52.522852090000000','bikeIcon','26509077120203','1115 Luisenstraﬂe / Karlplatz',11,false,'openDynamicInfoWindow', '', '', '', '',false,{minZoom: 11,maxZoom: false,proc: "bikesuche",cabfixflex: "fix",firmen: "500,510,590",objectname: "bikemarker",meta_id: "492",standort_id: "29700",bikes: "2705,2721,2731,2983,3054,3159,3247,3285,3308,3403,3409,3485,3792,4868,4914,5498,7388,7964,8242",clustername: "bikecluster"});
        """

        stations = []

        for marker in markers:
            station = Station()
            station.uid = marker['id']
            station.id = station.uid
            station.name = marker['name'].decode('latin-1')
            station.description = ""
            station.lat = float(marker['lat'])
            station.lng = float(marker['lng'])
            if marker['bikes']:
                station.bikes = len(marker['bikes'].split(","))
            else:
                station.bikes = 0
            station.slots = -1
            station.zone = ""
            stations.append(station)

        return stations

    def get_status(self, station, city):
        return station

    def dump_city(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        city.status = ''
        city.infos = 'http://www.callabike-interaktiv.de/kundenbuchung/hal2ajax_process.php?ajxmod=bikesearch&f=500&requester=/kundenbuchung/process.php&popup='
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
        print data.encode('utf-8')


def test():
    prov = CallABike()
    prov.selftest()

def main():
    test()

if __name__ == '__main__':
    main()
