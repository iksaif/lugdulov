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
import re
import datetime
from plugin import *

class Transdev(Provider):
    config = [
        {
        'country_uid' : 'fr',
        'country_name' : 'France',
        'city_uid'    : 'avignon',
        'city_name'    : 'Avignon',
        'bike_name'    : 'Velopop',
        'server' : 'http://www.velopop.fr/stations.html',
        'lat'  : 43.9486126,
        'lng'  : 4.8059666,
        },
        {
        'country_uid' : 'fr',
        'country_name' : 'France',
        'city_uid'    : 'saint-etienne',
        'city_name'    : 'Saint-Etienne',
        'bike_name'    : u'VéliVert',
        'server' : 'http://www.velivert.fr/sag_vls_stations_ste.html',
        'lat'  : 45.42753,
        'lng'  : 4.39176,
        },
        {
        'country_uid' : 'fr',
        'country_name' : 'France',
        'city_uid'    : 'saint-chamond',
        'city_name'    : 'Saint-Chamond',
        'bike_name'    : u'VéliVert',
        'server' : 'http://www.velivert.fr/sag_vls_stations_stc.html',
        'lat'  : 45.47269,
        'lng'  : 4.51075,
        },
        {
        'country_uid' : 'fr',
        'country_name' : 'France',
        'city_uid'    : 'firminy',
        'city_name'    : 'Firminy',
        'bike_name'    : u'VéliVert',
        'server' : 'http://www.velivert.fr/sag_vls_stations_fir.html',
        'lat'  : 45.38509,
        'lng'  : 4.28788,
        },
        {
        'country_uid' : 'fr',
        'country_name' : 'France',
        'city_uid'    : 'rive-de-gier',
        'city_name'    : 'Rive de Gier',
        'bike_name'    : u'VéliVert',
        'server' : 'http://www.velivert.fr/sag_vls_stations_rdg.html',
        'lat'  : 45.52366,
        'lng'  : 4.61041,
        },
        {
        'country_uid' : 'fr',
        'country_name' : 'France',
        'city_uid'    : 'strasbourg',
        'city_name'    : 'Strasbourg',
        'bike_name'    : u'Vel\'hop',
        'server' : 'http://www.velhop.strasbourg.eu/sag_vls_stations.html',
        'lat'  : 48.574350,
        'lng'  : 7.747500,
        }

        ]

    def service_by_city(self, city):
        for service in self.config:
            if service['city_uid'] == city.uid:
                return service
        return None

    def url(self, city):
        service = self.service_by_city(city)
        return service['server']

    def get_countries(self):
        ret = []
        done = {}

        for service in self.config:
            if service['country_uid'] in done:
                continue
            done[service['country_uid']] = True

            country = Country()
            country.uid = service['country_uid']
            country.name = service['country_name']
            ret.append(country)
        return ret

    def get_cities(self, country):
        ret = []
        for service in self.config:
            if country.uid != service['country_uid']:
                continue

            city = City()
            city.uid = service['city_uid']
            city.id = city.uid
            city.name = service['city_name']
            city.bikeName = service['bike_name']
            city.bikeIcon = ""
            city.lat = service['lat']
            city.lng = service['lng']
            city.create_rect(offset = 0.05)
            city.rect = self.get_city_bike_zone(service, city)
            city.type = "Transdev"
            ret.append(city)
        return ret

    def get_stations(self, city):
        stations = []
        url = self.url(city)
        fp = urlopen(url)
        data = fp.read()

        # map.addOverlay(newmark_03(3, 43.943233,4.805682, "<div align=\"left\">01 Jaures<br>Vélos disponibles: 1<br>Emplacements libres: 31<br>CB: Oui<br></div>"));
        rg = re.compile(r'map\.addOverlay\(newmark_\d+\((\d+), ([0-9\.]+),([0-9\.]+), "<div .*>(.*)<br>.*disponibles: (\d+)<br>(Emplacements libres: (\d+)<br>)?')

        #print data
        for node in rg.findall(data):
            station = Station()
            station.uid = node[0]
            station.id = station.uid
            station.name = node[3].decode('latin9')
            station.lat = float(node[1])
            station.lng = float(node[2])
            station.bikes = node[4]
            station.slots = node[5]
            station.zone = ""
            stations.append(station)
        return stations

    def get_status(self, station, city):
        return station

    def get_zones(self, city):
        return []

    def dump_city(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        city.infos = self.url(city)
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
        print data.encode('utf8')


def test():
    prov = Transdev()

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
