#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  cyclehire.py

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

  This program parse the data of Velodi - Dijon - France, Bip! Perpingan France, ...

"""
import sys
import os
import re
import xml.dom.minidom
import datetime
import urllib2

from plugin import *

class CycleHire(Provider):
    config = {
        'country_uid' : 'uk',
        'country_Name' : 'United-Kingdom',
        'city_uid'    : 'london',
        'city_Name'    : 'London',
        'bike_name'    : 'Cycle Hire',
        'server' : 'web.barclayscyclehire.tfl.gov.uk',
        'lat'  : 51.5001524,
        'lng'  : -0.1262362,
        'data_model' : 'cycleHire'
        }

    def url(self):
        return 'https://' + self.config['server'] + "/maps"

    def get_countries(self):
        country = Country()
        country.uid = "uk"
        country.name = "United-Kingdom"
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
        city.type = "CycleHire"
        return [city]


    def get_stations(self, city):
        stations = []
        url = self.url()
        fp = urlopen(url)
        data = fp.read()

        # id:"1",name:"River Street , Clerkenwell",lat:"51.52916347",long:"-0.109970527",nbBikes:"6",nbEmptyDocks:"13",installed:"true",locked:"false",temporary:"false"
        rg = re.compile(r'id:"(\d+)",name:"(.*)",lat:"(.*)",long:"(.*)",nbBikes:"(\d+)",nbEmptyDocks:"(\d+)"')
        for node in rg.findall(data):
            station = Station()
            station.uid = node[0]
            station.id = station.uid
            station.name = node[1]
            station.lat = float(node[2])
            station.lng = float(node[3])
            station.bikes = int(node[4])
            station.slots = int(node[5])
            station.zone = ""
            stations.append(station)
        return stations


    def get_status(self, station, city):
        return station

    def get_zones(self, city):
        return []

    def dump_city(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        city.infos = self.url()
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
        print data.encode('utf8')

def test():
    prov = CycleHire()

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
