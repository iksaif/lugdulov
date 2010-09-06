#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  cityBikeWein.py

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

  This program parse the data of  CityBike - Wien - austria

"""
import sys
import os
import urllib2
import re
import xml.dom.minidom
import datetime
from plugin import *

class CityBikeWien(Provider):
    config = {
        'country_uid' : 'at',
        'country_Name' : 'Autriche',
        'city_uid'    : 'wien',
        'city_Name'    : 'Wien',
        'bike_name'    : 'CityBike',
        'server' : 'dynamisch.citybikewien.at',
        'lat'  : 48.2092062,
        'lng'  : 16.3727778,
         }

    def url(self):
        return 'http://' + self.config['server'] + "/citybike_xml.php"

    def get_countries(self):
        country = Country()
        country.uid = "austria"
        country.name = "Austria"
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

        dom = xml.dom.minidom.parseString(data)
        for node in dom.getElementsByTagName('station'):
            station =  Station()
            station.uid = node.getElementsByTagName('id')[0].childNodes[0].toxml()
            station.id = station.uid
            station.name = node.getElementsByTagName('name')[0].childNodes[0].toxml()
            if node.getElementsByTagName('description')[0].hasChildNodes():
                station.description = node.getElementsByTagName('description')[0].childNodes[0].toxml()
            else:
                station.description = ''
            station.lat = float(node.getElementsByTagName('latitude')[0].childNodes[0].toxml())
            station.lng = float(node.getElementsByTagName('longitude')[0].childNodes[0].toxml())
            station.zone = "0"

            station.bikes = node.getElementsByTagName('free_bikes')[0].childNodes[0].toxml()
            station.slots = node.getElementsByTagName('free_boxes')[0].childNodes[0].toxml()
            #status.total = node.getElementsByTagName('boxes')[0].childNodes[0].toxml()
            #status.status = node.getElementsByTagName('status')[0].childNodes[0].toxml()
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
    prov = CityBikeWien()

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
