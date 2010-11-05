#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  nextBike.py

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

  nextbike.net

"""
# Copyright Patrick Installé 2010
# GPL
# get nextbike info
# http://www.nextbike.net
# un seul fichier xml contient (presque) toutes les informations sur les stations, dans les villes dans les pays.
#
#
import sys
import os
import datetime
import xml.dom.minidom
from unicodedata import normalize
from plugin import *

class NextBike(Provider):
# TODO Aller chercher les icones
# FIXME Les noms 'country' ne correspondent pas à la nomenclature officieles.

    dom = None

    def get_dom(self):
        if self.dom:
            return self.dom
        url = 'http://nextbike.net/maps/nextbike-official.xml'
        fp = urlopen(url)
        data = fp.read()
        self.dom = xml.dom.minidom.parseString(data)
        return self.dom

    def get_countries(self):
        # <country lat="50.7086" lng="10.6348" zoom="5" name="Germany" hotline="+493069205046" domain="de">
        ret = []

        nodes = self.get_dom().getElementsByTagName("country")
        if not nodes:
            return ret
        for node in nodes:
            country = Country()
            country.uid = node.getAttribute('domain')
            country.name = node.getAttribute('name')
            ret.append(country)
        return ret

    def get_cities(self, country):
        #    <city uid="1" lat="51.3402" lng="12.3722" zoom="14" maps_icon="" break="0" name="Leipzig">
        ret = []
        countries = self.get_dom().getElementsByTagName("country")
        cnode = None

        for node in countries:
            if node.getAttribute('name') == country.name:
                cnode = node
                break
        if cnode == None:
            return ret

        nodes = cnode.getElementsByTagName("city")
        for node in nodes:
            city = City()
            city.id = node.getAttribute('uid')
            city.name = node.getAttribute('name')
            city.oname = city.name
            if city.name.find("(") != -1:
                city.name = city.name.split('(')[0]
            city.uid = city.name.lower().strip().replace(' ', '-')
            city.uid = normalize("NFD", city.uid).encode("ascii", "ignore")
            city.bikeName = 'nextbike'
            city.lat = float(node.getAttribute('lat'))
            city.lng = float(node.getAttribute('lng'))
            city.type = "NextBike"
            city.create_rect(1)
            ret.append(city)
        return ret

    def get_zones(self, city):
        return []

    def get_stations(self, city):
        # <place uid="28" lat="51.3404998779297" lng="12.3689002990723" name="Bosestraße / Gottschedstraße - Schauspielhaus" spot="1" number="4013" bikes="3" bike_numbers="10051,10290,10337"/>

        cnode = None

        dom = self.get_dom()
        for anode in dom.getElementsByTagName("country"):
            for node in anode.getElementsByTagName("city"):
                if node.getAttribute('uid') == city.id:
                    cnode = node
        if not cnode:
            return []

        stations = []
        nodes = cnode.getElementsByTagName("place")

        for node in nodes:
            station = Station()
            station.uid = node.getAttribute('uid')
            station.id = station.uid
            station.name = node.getAttribute('name')
            station.description = ""
            station.lat = float(node.getAttribute('lat'))
            station.lng = float(node.getAttribute('lng'))
            station.bikes = station.slots = -1
            station.zone = ""
            if node.hasAttribute('bikes'):
                station.bikes = int(node.getAttribute('bikes').replace('+', ''))
            if node.hasAttribute('bike_racks'):
                station.slots = int(node.getAttribute('bike_racks'))
            stations.append(station)
        return stations

    def get_status(self, station, city):
        return station

    def dump_city(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        city.status = ''
        city.infos = 'http://nextbike.net/maps/nextbike-official.xml'
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
        print data.encode('utf8')


def test():
    prov = NextBike()

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

