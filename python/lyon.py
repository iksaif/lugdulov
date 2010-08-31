#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  cyclocity.py

  Copyright (C) 2010 Corentin Chary <corentincj@iksaif.net>

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

  JCDecaux CycloCity

"""

import sys
import os
import urllib2
import xml.dom.minidom
import json
import datetime
from plugin import *

class LyonVelov(Provider):
    regions = ["69381", "69382", "69383", "69384", "69385", "69386", "69387",
               "69388", "69389", "69266", "69034", "69256"]
    center = (45.760747, 4.85235)

    def station_json_url(self, id):
        return "http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParId.php?gid=%d" % int(id)

    def stations_json_url(self, region):
        return "http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParArrondissement.php?arrondissement=%s" % region

    def station_status_url(self, id):
        return "http://www.velov.grandlyon.com/velovmap/zhp/inc/DispoStationsParId.php?id=%d" % int(id)

    def station_image_url(self, id):
        return "http://www.velov.grandlyon.com/uploads/tx_gsstationsvelov/%d.jpg" % int(id)

    def get_countries(self):
        country = Country()
        country.uid = "fr"
        country.name = "France"
        return [country]

    def get_cities(self, country):
        city = City()
        city.uid = "lyon"
        city.name = "Lyon"
        city.bikeName = "Velo'V"
        city.bikeIcon = ""
        city.lat = self.center[0]
        city.lng = self.center[1]
        city.create_rect()
        return [city]

    def get_city_bike_zone(self, city):
        lat_min  = city.rect[0]
        lat_max  = city.rect[1]
        lng_min = city.rect[2]
        lng_max = city.rect[3]
        lat_center = city.lat
        lng_center = city.lng
        stations = self.get_stations(city)
        for station in stations:
            lat_place = float(station.lat)
            lng_place = float(station.lng)
            if lat_place > city.rect[0] \
                and lat_place < city.rect[2] \
                and lng_place > city.rect[1] \
                and lng_place < city.rect[3]:
                if lat_min > lat_place : lat_min = lat_place
                if lat_max < lat_place : lat_max = lat_place
                if lng_min > lng_place : lng_min = lng_place
                if lng_max < lng_place : lng_max = lng_place
        return lat_min, lng_min, lat_max, lng_max

    def get_zones(self, city):
        zones = []
        for region in self.regions:
            zone = Zone()
            zone.uid = region
            zone.rect = (0, 0, 0, 0)
            zone.create_center()
            zones.append(zone)
        return zones

    def get_stations(self, city):
        stations = []

        for i in self.regions:
            url = self.stations_json_url(i)
            fp = urllib2.urlopen(url)
            data = fp.read()
            data = json.loads(data)

            for j in data['markers']:
                station = Station()
                station.name = j['nomStation']
                station.uid = j['numStation']
                station.id = j['numStation']
                station.description = j['infoStation']
                station.zone = i
                if station.zone == '':
                    station.zone = '0' # FIXME, try to guess zone
                station.lat = float(j['x'])
                station.lng = float(j['y'])
                stations.append(station)
        return stations

    def get_status(self, station, city):
        import xml.dom.minidom

        url = self.station_status_url(station.id)
        fp = urllib2.urlopen(url)
        data = fp.read()

        dom = xml.dom.minidom.parseString(data)
        node = dom.getElementsByTagName("station")[0]

        status = {}
        for elem in ["available", "free", "total", "ticket"]:
            status[elem] = int(node.getElementsByTagName(elem)[0].childNodes[0].data)
        station.ticket = status['ticket']
        station.bikes = status['available']
        station.slots = status['free']
        return station

    def dump_priv(self, city):
        data = open('cyclocity/priv.tpl.h').read()
        city.rect = self.get_city_bike_zone(city)
        data = self._dump_priv(data, city)
        data = data.replace('<statusUrl>', '')
        data = data.replace('<infosUrl>', '')
        print data.encode('utf8')

def test():
    prov = LyonVelov()

    countries = prov.get_countries()
    print countries
    print countries[0]
    cities = prov.get_cities(countries[0])
    print cities
    print cities[0]
    zones = prov.get_zones(cities[0])
    print zones
    print zones[0]
    stations = prov.get_stations(cities[0])
    print "Stations: ", len(stations)
    station = prov.get_status(stations[0], cities[0])
    print station

def main():
    test()

if __name__ == "__main__":
    main()

