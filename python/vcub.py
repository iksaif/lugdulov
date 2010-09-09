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

class vCub(Provider):
    config = {
        'country_uid' : 'fr',
        'country_Name' : 'France',
        'city_uid'    : 'bordeaux',
        'city_Name'    : 'Bordeaux',
        'bike_name'    : 'Vcub',
        'server' : 'www.vcub.fr',
        'lat'  : 44.8373682,
        'lng'  : -0.5761440
        }

    def url(self):
        return 'http://' + self.config['server'] + "/stations/plan"

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
            for data in node.split(', '):
                name, value = data.split(': ')
                name = name.strip().replace('"', '')
                value = value.strip()[1:-1]
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
    prov = vCub()

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
