#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  Yelo.py

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

  This program parse the data of Yelo -La Rochelle - France

  need shareBike.py

"""
import sys
import os
import urllib2
import re
import datetime
from plugin import *

class Yelo(Provider):
    config = {
        'country_uid' : 'fr',
        'country_Name' : 'France',
        'city_uid'    : 'larochelle',
        'city_Name'    : 'La Rochelle',
        'bike_name'    : 'yelo',
        'server' : 'www.rtcr.fr',
        'lat'  : 46.1580216,
        'lng'  : -1.1535951,
        'service_class' : 'Yelo'
        }

    def url(self):
        return 'http://' + self.config['server'] + "/ct_93_297__Carte_du_libre_service_velos.html"

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
        city.type = "Yelo"
        return [city]

    def get_stations(self, city):
        stations = []
        url = self.url()
        fp = urlopen(url)

        data = fp.read()
        data = data.decode('iso8859-15')

        ret = re.compile(r'var markers = \[(.*?)]')
        ret = ret.search(data)
        for node in ret.groups()[0][1:-2].split('},{'):
            #num: '26', lat: '46.13819583', lon: '-1.1517244', name: 'Maison du D�partement', color: 'vert', bikeCount: '4 v&eacute;los', freeLockCount: '4', lockCount: '8 places'
            station = Station()
            for data in node.split(', '):
                name, value = data.split(': ')
                value = value.replace("'", "")
                if name == 'num':
                    station.uid = station.id = value
                if name == 'lon':
                    station.lng = float(value)
                if name == 'lat':
                    station.lat = float(value)
                if name == 'name':
                    station.name = value
                if name == 'bikeCount':
                    station.bikes = int(value.split(" ")[0])
                if name == 'freeLockCount':
                    station.slots = int(value.split(" ")[0])
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
    prov = Yelo()
    prov.selftest()

def main():
    test()

if __name__ == '__main__':
    main()
