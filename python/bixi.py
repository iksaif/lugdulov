#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  bixi.py

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

'''
<stations>
−
<station>
<id>1</id>
<name>Notre Dame / Place Jacques Cartier</name>
<terminalName>6001</terminalName>
<lat>45.508183</lat>
<long>-73.554094</long>
<installed>true</installed>
<locked>false</locked>
<installDate>1276012920000</installDate>
<removalDate/>
<temporary>false</temporary>
<nbBikes>2</nbBikes>
<nbEmptyDocks>29</nbEmptyDocks>
</station>
'''

class Bixi(Provider):
    config = {
        'country_uid' : 'ca',
        'country_Name' : 'Canada',
        'city_uid'    : 'montreal',
        'city_Name'    : 'Montreal',
        'bike_name'    : 'Bixi',
        'server' : 'profil.bixi.ca',
        'lat'  : 45.5088670,
        'lng'  : -73.5542420,
        'data_model' : 'bixi'
        }

    def url(self):
        return 'https://' + self.config['server'] + '/data/bikeStations.xml'

    def get_countries(self):
        country = Country()
        country.uid = "ca"
        country.name = "Canada"
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
        for node in  dom.getElementsByTagName('station'):
            station = Station()
            station.uid = node.getElementsByTagName('id')[0].childNodes[0].toxml()
            station.id = station.uid
            station.name = node.getElementsByTagName('name')[0].childNodes[0].toxml()
            station.lat = float(node.getElementsByTagName('lat')[0].childNodes[0].toxml())
            station.lng = float(node.getElementsByTagName('long')[0].childNodes[0].toxml())
            station.zone = "0"
            station.bikes = int(node.getElementsByTagName('nbBikes')[0].childNodes[0].toxml())
            station.slots = int(node.getElementsByTagName('nbEmptyDocks')[0].childNodes[0].toxml())
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
    prov = Bixi()

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
