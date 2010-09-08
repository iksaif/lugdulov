#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  velocea.py

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

  This program parse the data of velocea - Vannes - France

"""

import sys
import os
import urllib2
import re
import xml.dom.minidom
import datetime
import time
import random
import urllib
from plugin import *


class Velocea(Provider):
    config = {
        'country_uid' : 'fr',
        'country_Name' : 'France',
        'city_uid'    : 'vannes',
        'city_Name'    : 'Vannes',
        'bike_name'    : 'Velocea',
        'server' : 'www.velocea.fr',
        'lat'  : 47.6549032,
        'lng'  : -2.7595206,
        'service_class' : 'Velocea'
        }

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

    def url(self):
        webdbname = 'vannes/vannescms.nsf'
        since_epoch = int(time.time())
        url = 'http://' + self.config['server'] + "/"
        url+= webdbname + "/vStands?readviewentries&ms=" + str(since_epoch)
        return url

    def get_stations(self, city):
        '''
  <viewentry position="1" unid="A9C59A245C7D42F8802575CC005479CF" noteid="D4A" siblings="18">
    <entrydata columnnumber="0" name="standId">
      <number>1</number>
    </entrydata>
    <entrydata columnnumber="1" name="standName">
      <text>Hôtel de Ville</text>
    </entrydata>
    <entrydata columnnumber="2" name="standComments">
      <text/>
    </entrydata>
    <entrydata columnnumber="3" name="$1">
      <text>47.65818357,-2.76028303</text>
    </entrydata>
    <entrydata columnnumber="4" name="Capacity">
      <number>24</number>
    </entrydata>
    <entrydata columnnumber="5" name="bikesAvaile">
      <number>8</number>
    </entrydata>
    <entrydata columnnumber="6" name="portsFree">
      <number>16</number>
    </entrydata>
  </viewentry>
  '''
        stations = []
        url = self.url()
        fp = urllib2.urlopen(url)
        data = fp.read()
        #data = data.decode('utf8')
        data = data.decode('string-escape')

        dom = xml.dom.minidom.parseString(data)
        for node in dom.getElementsByTagName('viewentry'):
            station = Station()
            entries =  node.getElementsByTagName('entrydata')
            station.uid = entries[0].childNodes[1].childNodes[0].toxml()
            station.id = station.uid
            station.name = entries[1].childNodes[1].firstChild.toxml()
            lat_lng = entries[3].childNodes[1].firstChild.toxml()
            station.lat = float(lat_lng.split(',')[0])
            station.lng = float(lat_lng.split(',')[1])
            station.zone = "0"

            station.slots = int(entries[5].childNodes[1].firstChild.toxml())
            station.bikes = int(entries[6].childNodes[1].firstChild.toxml())
            stations.append(station)
        return stations

    def get_status(self, station, city):
        return station

    def get_zones(self, city):
        return []

    def dump_priv(self, city):
        data = open('velin/priv.tpl.h').read()
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_priv(data, city)
        data = data.replace('<statusUrl>', '')
        data = data.replace('<infosUrl>', self.url())
        print data.encode('utf8')

def test():
    prov = Velocea()

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
