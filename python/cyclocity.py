#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  cyclocity.py

  Copyright (C) 2010 Patrick Installé <PatrickInstalle@P-Installe.be>
  Copyright (C) 2010-2011 Corentin Chary <corentincj@iksaif.net>

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
import re
import xml.dom.minidom
import datetime
from plugin import *

class CycloCity(Provider):
    config = [
    {
            'city_uid'    : 'cergy',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Cergy-Pontoise',
            'bike_name'    : 'Velo2',
            'server' :  'www.velo2.cergypontoise.fr',
            'lat': 49.0485219,
            'lng': 2.0342372
            },
    {
            'city_uid'    : 'paris',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Paris',
            'bike_name'    : u'Vélib\'',
            'server' :  'www.velib.paris.fr',
            'lat': 48.8566667,
            'lng': 2.3509871
            },
    {
            'city_uid'    : 'creteil',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : u'Créteil',
            'bike_name'    : 'Cristolib',
            'server' :  'www.cristolib.fr',
            'lat': 48.7896130,
            'lng': 2.4526276
            },

    {
            'city_uid'    : 'aixenprovence',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Aix-en-Provence',
            'bike_name'    : 'V\'Hello',
            'server' :  'www.vhello.fr',
            'lat': 43.5249088,
            'lng': 5.4541444
            },

    {
            'city_uid'    : 'amiens',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Amiens',
            'bike_name'    : 'Velam',
            'server' :  'www.velam.amiens.fr',
            'lat': 49.8939183,
            'lng': 2.2942436
            },

    {
            'city_uid'    : 'besancon',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : u'Besançon',
            'bike_name'    : u'VéloCité',
            'server' :  'www.velocite.besancon.fr',
            'lat': 47.2412254,
            'lng': 6.0255656
            },

    {
            'city_uid'    : 'marseille',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Marseille',
            'bike_name'    : u'Le Vélo',
            'server' :  'www.levelo-mpm.fr',
            'lat': 43.2976116,
            'lng': 5.3810421
            },

    {
            'city_uid'    : 'mulhouse',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Mulhouse',
            'bike_name'    : u'VéloCité',
            'server' :  'www.velocite.mulhouse.fr',
            'lat': 47.7494919,
            'lng': 7.3397806
            },

    {
            'city_uid'    : 'nancy',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Nancy',
            'bike_name'    : u'vélOStan',
            'server' :  'www.velostanlib.fr',
            'lat': 48.6907887,
            'lng': 6.1825044
            },

    {
            'city_uid'    : 'nantes',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Nantes',
            'bike_name'    : 'Bicloo',
            'server' :  'www.bicloo.nantesmetropole.fr',
            'lat': 47.2168424,
            'lng': -1.5567445
            },

    {
            'city_uid'    : 'plainecommune',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Plaine Commune',
            'bike_name'    : 'Velcom',
            'server' :  'www.velcom.fr',
            'lat': 48.9360802,
            'lng': 2.3648843
            },

    {
            'city_uid'    : 'rouen',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Rouen',
            'bike_name'    : 'Cyclic',
            'server' :  'cyclic.rouen.fr',
            'lat': 49.4423668,
            'lng': 1.0984924
            },

    {
            'city_uid'    : 'toulouse',
            'country_uid' : 'fr',
            'country_Name' : 'France',
            'city_Name'    : 'Toulouse',
            'bike_name'    : u'Vélouse',
            'server' :  'www.velo.toulouse.fr',
            'lat': 43.6043630,
            'lng': 1.4429513
            },

    {
            'city_uid'    : 'bruxelles',
            'country_uid' : 'be',
            'country_Name' : 'Belgium',
            'city_Name'    : 'Bruxelles',
            'bike_name'    : 'Villo',
            'server' :  'www.villo.be',
            'lat': 50.8462807,
            'lng': 4.3547273
            },

    {
            'city_uid'    : 'dublin',
            'country_uid' : 'ir',
            'country_Name' : 'Ireland',
            'city_Name'    : 'Dublin',
            'bike_name'    : 'Dubline Bikes',
            'server' :  'www.dublinbikes.ie',
            'lat': 53.3441040,
            'lng': -6.2674937
            },

    {
            'city_uid'    : 'luxembourg',
            'country_uid' : 'lu',
            'country_Name' : 'Luxembourg',
            'city_Name'    : 'Luxembourg',
            'bike_name'    : 'Veloh',
            'server' :  'www.veloh.lu',
            'lat': 49.6100036,
            'lng': 6.1295960
            },
    {
            'city_uid'     : 'valencia',
            'country_uid'  : 'es',
            'country_Name' : 'Spain',
            'city_Name'    : 'Valencia',
            'bike_name'    : 'Valenbisi',
            'lat'          : 39.459258,
            'lng'          : -0.376453,
            'server'       : 'www.valenbisi.es'
            },

    {
            'city_uid'    : 'santander',
            'country_uid' : 'es',
            'country_Name' : 'Spain',
            'city_Name'    : 'Santander',
            'bike_name'    : 'Tusbic',
            'server' :  'www.tusbic.es',
            'lat': 43.4609602,
            'lng': -3.8079336
            },

    {
            'city_uid'    : 'seville',
            'country_uid' : 'es',
            'country_Name' : 'Spain',
            'city_Name'    : u'Séville',
            'bike_name'    : 'Sevici',
            'server' :  'www.sevici.es',
            'lat': 37.3826400,
            'lng': -5.9962951
            },
    {
            'city_uid'    : 'toyama',
            'country_uid' : 'jp',
            'country_Name' : 'Japan',
            'city_Name'    : 'Toyama',
            'bike_name'    : 'Cyclocity',
            'server' :  'www.cyclocity.jp',
            'lat': 36.6959518,
            'lng': 137.2136768
            },
    {
            'city_uid'    : 'brisbane',
            'country_uid' : 'au',
            'country_Name' : 'Australia',
            'city_Name'    : 'Brisbane',
            'bike_name'    : 'CycloCycle',
            'server' :  'www.citycycle.com.au',
            'lat': -27.47538,
            'lng': 153.019466
            },
    {
            'city_uid'    : 'ljubljana',
            'country_uid' : 'si',
            'country_Name' : 'Slovenia',
            'city_Name'    : 'Ljubljana',
            'bike_name'    : 'Bicike(lj)',
            'server' :  'www.bicikelj.si',
            'lat': 46.055556,
            'lng': 14.508333
            },
    ]

    cache = {}

    def service_by_country(self, country):
        for service in self.config:
            if country.uid == service['country_uid']:
                return service
        return None

    def service_by_city(self, city):
        for service in self.config:
            if city.uid == service['city_uid']:
                return service
        return None

    def get_countries(self):
        ret = []
        done = {}

        for service in self.config:
            if service['country_uid'] in done:
                continue
            done[service['country_uid']] = True

            country = Country()
            country.uid = service['country_uid']
            country.name = service['country_Name']
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
            city.name = service['city_Name']
            city.bikeName = service['bike_name']
            city.lat = service['lat']
            city.lng = service['lng']
            city.create_rect()
            city.type = "CycloCity"
            #city.rect = self.get_city_bike_zone(service, city)
            ret.append(city)
        return ret

    def get_carto(self, service):
        if service['server'] in self.cache:
            return self.cache[service['server']]

        url = 'http://' + service['server'] + "/service/carto"
        fp = urlopen(url)
        data = fp.read()
        dom = xml.dom.minidom.parseString(data)
        self.cache[service['server']] = dom
        return dom

    def get_zones(self, city):
        zones = []
        service = self.service_by_city(city)
        dom = self.get_carto(service)
        arrondissements = dom.getElementsByTagName("arrondissement")
        for arrondissement in arrondissements:
            zone = Zone()
            zone.uid = arrondissement.getAttribute('number')

            elems = {}
            for elem in ["minLat", "minLng", "maxLat", "maxLng"]:
                elems[elem] = float(arrondissement.getAttribute(elem))

            zone.rect = (elems["minLat"], elems["maxLat"], elems["minLng"], elems["maxLng"])
            zone.create_center()
            zones.append(zone)
        return zones

    def get_stations(self, city):
        stations = None
        service = self.service_by_city(city)
        dom = self.get_carto(service)
        stations = []
        markers = dom.getElementsByTagName("marker")
        for marker in markers:
            station = Station()
            station.name = marker.getAttribute('name')
            station.uid = marker.getAttribute('number')
            station.id = station.uid
            station.description = marker.getAttribute('address')
                # marker.getAttribute('fullAddress')
            station.zone = marker.getAttribute('arrondissement')
            station.lat = float(marker.getAttribute('lat'))
            station.lng = float(marker.getAttribute('lng'))
            stations.append(station)
        return stations

    def get_status(self, station, city):
        service = self.service_by_city(city)
        url = 'http://' + service['server'] + "/service/stationdetails/" + city.uid + "/%d" % int(station.id)
        print url
        fp = urlopen(url)
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

    def dump_city(self, city):
        service = self.service_by_city(city)
        city.rect = self.get_city_bike_zone(service, city)
        city.status = 'http://' +  service['server'] + '/service/stationdetails/' + city.uid + '/%1'
        city.infos = 'http://' +  service['server'] + '/service/carto'
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        service = self.service_by_city(city)
        city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
        print data.encode('utf8')

def test():
    prov = CycloCity()

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

if __name__ == '__main__':
    main()
