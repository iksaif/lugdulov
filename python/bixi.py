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
import json
import re
import xml.dom.minidom
import datetime
import urllib2

from plugin import *

''' Bixi
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

''' Bixi2
var station = {id:"1",name:"Notre Dame / Place Jacques Cartier",lat:"45.508183",long:"-73.554094",nbBikes:"12",nbEmptyDocks:"19",installed:"true",locked:"false",temporary:"false", sponsorName:null, sponsorLink:null, sponsorLogo:null};
'''

class Bixi(Provider):
    config = [
        {
        'country_uid' : 'ca',
        'country_name' : 'Canada',
        'city_uid'    : 'montreal',
        'city_name'    : 'Montreal',
        'bike_name'    : 'Bixi2',
        'server' : 'https://montreal.bixi.com/maps/statajax',
        'lat'  : 45.5088670,
        'lng'  : -73.5542420,
        },
        {
        'country_uid' : 'ca',
        'country_name' : 'Canada',
        'city_uid'    : 'toronto',
        'city_name'    : 'Toronto',
        'bike_name'    : 'Bixi2',
        'server' : 'https://toronto.bixi.com/maps/statajax',
        'lat'  : 43.656152,
        'lng'  : -79.385225,
        },
        {
        'country_uid' : 'usa',
        'country_name' : 'USA',
        'city_uid'    : 'washington',
        'city_name'    : 'Washington, DC',
        'bike_name'    : 'Bixi',
        'server' : 'http://www.capitalbikeshare.com/stations/bikeStations.xml',
        'lat'  : 38.90752,
        'lng'  : -77.02708,
        },
       {
        'country_uid' : 'usa',
        'country_name' : 'USA',
        'city_uid'    : 'minneapolis',
        'city_name'    : 'Minneapolis',
        'bike_name'    : 'Bixi',
        'server' : 'http://secure.niceridemn.org/data2/bikeStations.xml',
        'lat'  : 44.9801,
        'lng'  : -93.251867,
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
            city.create_rect()
            city.type = service['bike_name']
            #city.rect = self.get_city_bike_zone(service, city)
            ret.append(city)
        return ret

    def get_stations(self, city):

        if city.type == 'Bixi2':
            return self.get_stations_bixi2(city)
        else:
            return self.get_stations_bixi(city)

    def get_stations_bixi(self, city):
        stations = []
        url = self.url(city)
        fp = urlopen(url)

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

    def get_stations_bixi2(self, city):
        stations = []
        url = self.url(city)
        fp = urlopen(url)

        data = fp.read()

        rg = re.compile(r'id:"(\d+)",name:"(.*)",lat:"(.*)",long:"(.*)",nbBikes:"(\d+)",nbEmptyDocks:"(\d+)",installed:"(true|false)",locked:"(true|false)",temporary:"(true|false)"')
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
        city.infos = self.url(city)
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
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
