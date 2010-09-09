#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  veloPlus.py

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

  This program parse the data of Velo+ - Orléans - France

"""
import sys
import os
import urllib2
import re
import datetime
import xml.dom.minidom
from plugin import *

class VeloPlus(Provider):
    config = {
        'country_uid' : 'fr',
        'country_Name' : 'France',
        'city_uid'    : 'orleans',
        'city_Name'    : 'Orleans',
        'bike_name'    : 'Velo+',
        'server' : 'www.agglo-veloplus.fr',
        'lat'  : 47.9013866,
        'lng'  : 1.9039759,
        'service_class' : 'VeloPlus'
        }

    def url(self):
        return 'https://' + self.config['server'] + '/component/data_1.xml'

    def url_status(self, uid):
        return 'https://' + self.config['server'] + '/getStatusBorne?idBorne=%s' % uid

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

        dom = xml.dom.minidom.parseString(data)
        for node in dom.getElementsByTagName('marker'):
            '''
            <markers center_lat="47.908" center_lng="1.908188" zoom_level="13">
            <marker id="1" lat="47.927011" lng="1.907435" name="GARE DES AUBRAIS"/>
            <marker id="2" lat="47.915510" lng="1.899200" name="COLIGNY"/>
            '''
            station = Station()
            station.uid = node.getAttribute('id')
            station.id = station.uid
            station.lat = float(node.getAttribute('lat'))
            station.lng = float(node.getAttribute('lng'))
            station.name = node.getAttribute('name')
            station.zone = "0"
            stations.append(station)
        return stations

    def get_status(self, station, city):
        url = self.url_status(station.id)
        fp = urllib2.urlopen(url)
        data = fp.read()

        dom = xml.dom.minidom.parseString(data)

        '''
        <station>
            <status>En service</status>
            <bikes>12</bikes>
            <attachs>0</attachs>
            <paiement>SANS_TPE</paiement>
        </station>
        '''
        station.bikes = int(dom.getElementsByTagName('bikes')[0].firstChild.toxml())
        station.slots = int(dom.getElementsByTagName('attachs')[0].firstChild.toxml())
        return station

    def get_zones(self, city):
        return []

    def dump_priv(self, city):
        data = open('citybike/priv.tpl.h').read()
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_priv(data, city)
        data = data.replace('<statusUrl>', self.url_status("%1"))
        data = data.replace('<infosUrl>', self.url())
        print data.encode('utf8')


def test():
    prov = VeloPlus()

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
