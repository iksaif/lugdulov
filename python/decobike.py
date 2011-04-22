#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  decobike.py

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

"""
import sys
import os
import re
import xml.dom.minidom
import datetime
import urllib2

from plugin import *

class DecoBikes(Provider):
    config = [
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'miamibeach',
            'city_name'    : 'Miami Beach',
            'bike_name'    : 'DecoBikes',
            'server' : 'http://www.decobike.com/playmoves.xml',
            'lat'  : 25.796027,
            'lng'  : -80.133934,
            },
        ]

    def service_by_city(self, city):
        for service in self.config:
            if service['city_uid'] == city.uid:
                return service
        return Non

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
            city.type = "DecoBikes"
            #city.rect = self.get_city_bike_zone(service, city)
            ret.append(city)
        return ret

    def get_stations(self, city):
        stations = []
        url = self.url(city)
        fp = urlopen(url)
        data = fp.read()
        dom = xml.dom.minidom.parseString(data)

        """
        <?xml version="1.0"?>
         <locations>
          <location>
           <Id>201</Id>
           <Address>19th Street &amp; Dade Blvd</Address>
           <Distance>0</Distance>
           <Latitude>25.7948074</Latitude>
           <Longitude>-80.13935</Longitude>
           <Bikes>9</Bikes>
           <Dockings>7</Dockings>
           <StationAdList></StationAdList>
          </location>
         </locations>
        """
        for node in dom.getElementsByTagName("location"):
            station = Station()
            station.uid = node.getElementsByTagName("Id")[0].firstChild.toxml()
            station.id = station.uid
            station.lat = float(node.getElementsByTagName("Latitude")[0].firstChild.toxml())
            station.lng = float(node.getElementsByTagName("Longitude")[0].firstChild.toxml())
            station.name = node.getElementsByTagName("Address")[0].firstChild.toxml()
            station.description = ""
            station.bikes = int(node.getElementsByTagName("Bikes")[0].firstChild.toxml())
            station.slots = int(node.getElementsByTagName("Dockings")[0].firstChild.toxml())
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
    prov = Decobikes()

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
