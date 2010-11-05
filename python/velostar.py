#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  veloStar.py

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

  This program parse the data of veloStar - Rennes - France

"""
import sys
import os
import urllib2
import re
import datetime
import xml.dom.minidom

from plugin import *

class VeloStar(Provider):
    config = {
        'country_uid' : 'fr',
        'country_Name' : 'France',
        'city_uid'    : 'rennes',
        'city_Name'    : 'Rennes',
        'bike_name'    : 'VeloStar',
        'server' : 'data.keolis-rennes.com',
        'lat'  : 48.1117611,
        'lng'  : -1.6802654,
        'service_class' : 'VeloStar'
        }

    def get_countries(self):
        country = Country()
        country.uid = "fr"
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
        city.type = "VeloStar"
        return [city]

    def url(self):
        # key = 5O3IN1BU3MK100U
        # http://data.keolis-rennes.com/xml/?version=1.0&key=5O3IN1BU3MK100U&cmd=getstation
        key = '5O3IN1BU3MK100U'
        url ='http://' + self.config['server'] + '/xml/?version=1.0&key='+ key + '&cmd=getstation'
        return url

    def get_stations(self, city):
        stations = []
        url = self.url()
        fp = urlopen(url)

        data = fp.read()
        dom = xml.dom.minidom.parseString(data)
        for node in  dom.getElementsByTagName('station'):
            station = Station()
            station.uid = node.getElementsByTagName('id')[0].firstChild.toxml()
            station.id = station.uid
            station.name = node.getElementsByTagName('name')[0].firstChild.toxml().title()
            station.lat = float(node.getElementsByTagName('latitude')[0].firstChild.toxml())
            station.lng = float(node.getElementsByTagName('longitude')[0].firstChild.toxml())
            station.slots = int(node.getElementsByTagName('slotsavailable')[0].firstChild.toxml())
            station.bikes = int(node.getElementsByTagName('bikesavailable')[0].firstChild.toxml())
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
    prov = VeloStar()

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
