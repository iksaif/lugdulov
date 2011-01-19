#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  velIn.py

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

  This program parse the data of Vel'in Calais - France, VeloBleu - Nice - France, OYBike - cardiff - Great-Britain, OYBike - Reading - Great-Britain
"""

import sys
import os
import re
import xml.dom.minidom
import datetime
import time
import random
import urllib
import json
from plugin import *


class VelIn(Provider):
    config = [
        {
            'country_uid' : 'fr',
            'country_name' : 'France',
            'city_uid'    : 'calais',
            'city_name'    : 'Calais',
            'bike_name'    : 'Vel''in',
            'server' : 'www.vel-in.fr',
            'url' : 'http://www.vel-in.fr/calais/cms.nsf/customFrmMap?OpenForm&lang=fr',
            'lat'  : 50.9580293,
            'lng'  : 1.8524129,
            'service_class' : 'VelIn'
            },
        {
            'country_uid' : 'fr',
            'country_name' : 'France',
            'city_uid'    : 'nice',
            'city_name'    : 'Nice',
            'bike_name'    : 'VeloBleu',
            'server' : 'www.velobleu.org',
            'url' : 'http://www.velobleu.org/nice/nicecms.nsf/customFrmMap?OpenForm',
            'lat'  : 43.7034273,
            'lng'  : 7.2662656,
            'service_class' : 'VelIn'
            },
        {
            'country_uid' : 'uk',
            'country_name' : 'United-Kingdom',
            'city_uid'    : 'cardiff',
            'city_name'    : 'Cardiff',
            'bike_name'    : 'OYBike',
            'server' : 'oybike.com',
            'url' : 'http://www.oybike.com/oybike/cms.nsf/customFrmMap?openform',
            'lat'  : 51.4813069,
            'lng'  : -3.1804979,
            'service_class' : 'VelIn'
            },
        {
            'country_uid' : 'uk',
            'country_name' : 'United-Kingdom',
            'city_uid'    : 'reading',
            'city_name'    : 'Reading',
            'bike_name'    : 'OYBike',
            'server' : 'oybike.com',
            'url' : 'http://www.oybike.com/oybike/cms.nsf/customFrmMap?openform',
            'lat'  : 51.4550410,
            'lng'  : -0.9690884,
            'service_class' : 'VelIn'
         },
        {
            'country_uid' : 'fr',
            'country_name' : 'France',
            'city_uid'    : 'vannes',
            'city_name'    : 'Vannes',
            'bike_name'    : 'Velocea',
            'server' : 'www.velocea.fr',
            'url' : 'http://www.velocea.fr/vannes/vannescms.nsf/customFrmMap?OpenForm',
            'lat'  : 47.6549032,
            'lng'  : -2.7595206,
            'service_class' : 'Velocea'
        }]

    def service_by_city(self, city):
        for service in self.config:
            if service['city_uid'] == city.uid:
                return service
        return None

    def url(self, city):
        return self.forge_url(city)

    def forge_url(self, city):
        service = self.service_by_city(city)

        if 0:
            mapdb = 'oybike/stands.nsf'

            # for the key follow the path
            fp = urlopen('http://' + service['server']  + "/")
            html = fp.read()
            rg = re.compile('window\.location = \'(.*?)\';')
            location = rg.search(html).group(1)

            fp = urlopen('http://' + service['server']  + location)
            html = fp.read()
            rg = re.compile('(customFrmMap\?OpenForm\&ParentUNID=.*?\?open\&lang=fr)')
            request = rg.search(html).group(1)
            rg = re.compile('var webdbname = \'(.*?)\';')
            webdbname = rg.search(html).group(1)
            url_map = 'http://' + service['server'] + '/' + webdbname + '/' + request
            fp = urlopen(url_map)
        else:
            fp = urlopen(service['url'])

        html = fp.read()
        rg = re.compile('var mapdbkey = \'(.*?)\';')
        mapdbkey = rg.search(html).group(1)
        rg = re.compile('var mapdb=\'(.*?)\';')
        mapdb = rg.search(html).group(1)

        url = 'http://' + service['server']  + "/" + mapdb
        url += "/getSite?openagent&site=" + service['city_uid'] + "&format=json&key=" + mapdbkey
        return url

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
            city.type = "VelIn"
            #city.rect = self.get_city_bike_zone(service, city)
            ret.append(city)
        return ret

    def get_zones(self, city):
        return []

    def get_stations(self, city):
        stations = []

        fp = urlopen(self.url(city))
        data = fp.read()
        data = json.loads(data)
        for marker in data['site']['stands']:
            """
            {u'disp': u'1', u'ac': 15, u'ab': 6, u'name': u'1%20:%20Lafayette',
            u'tc': 15, u'ap': 9, u'lat': 50.946610999999997, u'lng': 1.858303,
            u'id': u'1', u'wcom': u''}
            """
            station = Station()
            station.uid = marker['id']
            station.id = station.uid
            station.name = urllib.unquote(marker['name'])
            station.lat = float(marker['lat'])
            station.lng = float(marker['lng'])
            station.slots = marker['ap']
            station.bikes = marker['ab']
            station.zone = ""
            stations.append(station)
        return stations

    def get_status(self, station, city):
        return station

    def get_zones(self, city):
        return []

    def dump_city(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        #city.infos = 'http://' + self.service_by_city(city)['server'] + "/"
        city.infos = self.service_by_city(city)['url']
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
        print data.encode('utf8')

def test():
    prov = VelIn()

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
