#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  veloPop.py

  Copyright (C) 2010 Patrick Installé <PatrickInstalle@P-Installe.be>

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

  This program parse the data of VeloPop - Avignon - France

"""
import sys
import os
import urllib2
import re
import datetime
from plugin import *

class VeloPop(Provider):
    config = {
        'country_uid' : 'fr',
        'country_Name' : 'France',
        'city_uid'    : 'avignon',
        'city_Name'    : 'Avignon',
        'bike_name'    : 'Velopop',
        'server' : 'www.velopop.fr',
        'lat'  : 43.9486126,
        'lng'  : 4.8059666,
        'service_class' : 'VeloPop'
        }

    def url(self):
        return 'http://' + self.config['server'] + "/stations.html"

    def get_countries(self):
        country = Country()
        country.uid = "france"
        country.name = "France"
        return [country]

    def get_cities(self, country):
        city = City()
        city.uid = self.config['city_uid']
        city.id = city.uid
        city.name = self.config['city_Name']
        city.bikeName = self.config['bike_name']
        city.lat = self.config['lat']
        city.lng = self.config['lng']
        city.create_rect()
        return [city]


    def get_stations(self, city):
        stations = []
        url = self.url()
        fp = urllib2.urlopen(url)
        data = fp.read()

        # map.addOverlay(newmark_03(3, 43.943233,4.805682, "<div align=\"left\">01 Jaures<br>Vélos disponibles: 1<br>Emplacements libres: 31<br>CB: Oui<br></div>"));
        rg = re.compile(r'map\.addOverlay\(newmark_\d+\((\d+), ([0-9\.]+),([0-9\.]+), "<div align=\\"left\\">(.*)<br>.*disponibles: (\d+)<br>Emplacements libres: (\d+)<br>')
        #print data
        for node in rg.findall(data):
            station = Station()
            station.uid = node[0]
            station.id = station.uid
            station.name = node[3]
            station.lat = float(node[1])
            station.lng = float(node[2])
            station.bikes = node[4]
            station.slots = node[5]
            station.zone = "0"
            stations.append(station)
        return stations

    def get_status(self, station, city):
        return station

    def get_zones(self, city):
        return []

    def dump_priv(self, city):
        data = open('citybike/priv.tpl.h').read()
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_priv(data, city)
        data = data.replace('<statusUrl>', '')
        data = data.replace('<infosUrl>', self.url())
        print data.encode('utf8')


def test():
    prov = VeloPop()

    countries = prov.get_countries()
    print countries
    print countries[0]
    cities = prov.get_cities(countries[0])
    print cities
    print cities[0]
    zones = prov.get_zones(cities[0])
    print zones
    if (zones):
        print zones[0]
    stations = prov.get_stations(cities[0])
    print "Stations: ", len(stations)
    station = prov.get_status(stations[0], cities[0])
    print station

def main():
    test()

if __name__ == '__main__':
    main()
