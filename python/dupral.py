#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  vCub.py

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

  This program parse the data of VCub - Bordeaux - France

"""

import sys
import os
import urllib2
import re
import xml.dom.minidom
import datetime
from plugin import *

class Dupral(Provider):
    config = [
        {
            'country_uid' : 'fr',
            'country_name' : 'France',
            'city_uid'    : 'bordeaux',
            'city_name'    : 'Bordeaux',
            'bike_name'    : 'Vcub',
            'server' : 'www.vcub.fr',
            'lat'  : 44.8373682,
            'lng'  : -0.5761440
            },
        {
            'country_uid' : 'fr',
            'country_name' : 'France',
            'city_uid'    : 'pau',
            'city_name'    : 'Pau',
            'bike_name'    : 'IDEcycle',
            'server' : 'www.idecycle.com',
            'lat'  : 43.29461,
            'lng'  : -0.37078
            }]

    def service_by_city(self, city):
        for service in self.config:
            if service['city_uid'] == city.uid:
                return service
        return None

    def url(self, city):
        service = self.service_by_city(city)
        return 'http://' + service['server'] + "/stations/plan"

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
            city.type = "Dupral"
            ret.append(city)
        return ret

    def get_stations(self, city):
        stations = []
        url = self.url(city)
        fp = urlopen(url)

        data = fp.read()
        rg = re.compile(r'jQuery.extend\(.*?} } }\);')
        match = rg.search(data)
        data = match.group(0)

        rg = re.compile(r'"markers": \[(.*?)]')
        match = rg.search(data)
        data = match.group(1)
        # convert \x ->
        data = data.decode('string-escape')
        rg = re.compile('{(.*?)}', re.DOTALL|re.MULTILINE)
        for node in rg.findall(data):
            """
            "latitude": "44.84386", "longitude": "-0.55736", "text": "<div class="gmap-popup"><div class="gmap-infobulle">
            <div class="gmap-titre">#67 - Allee de Serr  Abadie</div>
            <div class="gmap-adresse">ALLÉE SERR FACE À L'ÉGLISE STE MARIE</div><div class="gmap-velos">
            <table><tr>
            <td class="ok"><strong>17</strong> vélos disponibles</td>
            <td class="ok"><strong>1</strong> places disponibles</td></tr></table></div><div class="gmap-datemaj">dernière mise à jour il y a <strong>01 min</strong>  </div>
            </div></div>", "markername": "vcub"
            """
            station = Station()
            for data in node.split('", "'):
                name, value = data.split(': ')
                name = name.strip().replace('"', '')
                value = value.strip().strip('"')
                if name == "latitude":
                    station.lat = float(value)
                if name == "longitude":
                    station.lng = float(value)
                if name == "text":
                    dom = xml.dom.minidom.parseString(value)
                    for div in dom.getElementsByTagName('div'):
                        if div.hasAttribute('class'):
                            c = div.getAttribute('class')
                            if c == 'gmap-titre':
                                text = div.childNodes[0].toxml()
                                text = text.split(' - ')
                                station.uid = text[0].replace('#', '')
                                station.id = station.uid
                                station.name = text[1]
                            if c == 'gmap-adresse':
                                station.description = div.childNodes[0].toxml()
                                if station.description == "A MODIFIER":
                                    station.description = ""
                    strongs = dom.getElementsByTagName('strong')
                    if (len(strongs) >= 2):
                        station.bikes = int(strongs[0].childNodes[0].toxml())
                        station.slots = int(strongs[1].childNodes[0].toxml())
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
    prov = Dupral()

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
