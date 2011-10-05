#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  bcycle.py

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
import json

from plugin import *

class BCycle(Provider):
    config = [
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'louisville',
            'city_name'    : 'Louisville',
            'bike_name'    : 'BCycle',
            'server' : 'http://louisville.bcycle.com/',
            'lat'  : 38.254167,
            'lng'  : -85.760278,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'spartanburg',
            'city_name'    : 'Spartanburg',
            'bike_name'    : 'BCycle',
            'server' : 'http://spartanburg.bcycle.com/',
            'lat'  : 34.946667,
            'lng'  : -81.9275,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'omaha',
            'city_name'    : 'Omaha',
            'bike_name'    : 'BCycle',
            'server' : 'http://omaha.bcycle.com/',
            'lat'  : 41.25,
            'lng'  : -96,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'browardcounty',
            'city_name'    : 'Broward County',
            'bike_name'    : 'BCycle',
            'server' : 'http://browardcounty.bcycle.com/',
            'lat'  : 45.767299,
            'lng'  : 4.834329
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'denver',
            'city_name'    : 'Denver',
            'bike_name'    : 'BCycle',
            'server' : 'http://denver.bcycle.com/',
            'lat'  : 39.739167,
            'lng'  : -104.984722,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'chicago',
            'city_name'    : 'Chicago',
            'bike_name'    : 'BCycle',
            'server' : 'http://chicago.bcycle.com/',
            'lat'  : 41.877741,
            'lng'  : -87.63382,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'sanantonio',
            'city_name'    : 'San Antonio',
            'bike_name'    : 'BCycle',
            'server' : 'http://sanantonio.bcycle.com/',
            'lat'  : 29.416667,
            'lng'  : -98.5,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'hawaii',
            'city_name'    : 'Hawaii',
            'bike_name'    : 'BCycle',
            'server' : 'http://hawaii.bcycle.com/',
            'lat'  : 21.333611,
            'lng'  : -157.698056,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'desmoines',
            'city_name'    : 'Des Moines',
            'bike_name'    : 'BCycle',
            'server' : 'http://desmoines.bcycle.com/',
            'lat'  : 41.590833,
            'lng'  : -93.620833,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'boulder',
            'city_name'    : 'Boulder',
            'bike_name'    : 'BCycle',
            'server' : 'http://boulder.bcycle.com/',
            'lat'  : 40.019444,
            'lng'  : -105.292778,
            },
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'madison',
            'city_name'    : 'Madison',
            'bike_name'    : 'BCycle',
            'server' : 'http://madison.bcycle.com/',
            'lat'  : 43.066667,
            'lng'  : -89.4,
            },
        ]

    api_url = 'http://api.bcycle.com/services/mobile.svc/ListKiosks'
    data = None

    def service_by_city(self, city):
        for service in self.config:
            if service['city_uid'] == city.uid:
                return service
        return None

    def service_by_name(self, name):
        for service in self.config:
            if name.lower() in [service['city_uid'].lower(), service['city_name'].lower()]:
                return service
        return None

    def fix_city_name(self, name):
        name = name.strip()
        if name == 'Kailua':
            name = 'Hawaii'
        if name in ['Ft. Lauderdale', 'Hollywood', 'Pompano Beach', 'Coconut Creek', 'Dania Beach', 'Lauderdale by the Sea', 'Hallandale']:
            name = 'Broward County'
        if name in ['SSF']:
            name = 'San Antonio'
        if name in ["San Fransico", "City"]:
            name = None
        return name

    def load_data(self):
        if self.data:
            return

        fp = urlopen(self.api_url)
        self.data = json.loads(fp.read())

        for station in self.data['d']['list']:
            name = station['Address']['City']
            name = self.fix_city_name(name)
            if not name:
                continue

            service = self.service_by_name(name)
            if not service:
                raise Exception("%s not supported" % station['Address']['City'])
            if 'active' not in service:
                service['active'] = False
            if station['Status'] != 'ComingSoon' or int(station['TotalDocks']) > 1:
                service['active'] = True

    def get_countries(self):
        ret = []
        done = {}
        self.load_data()

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
            if 'active' not in service or service['active'] == False:
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
            city.type = "BCycle"
            #city.rect = self.get_city_bike_zone(service, city)
            ret.append(city)
        return ret

    def get_stations(self, city):
        stations = []

        for marker in self.data['d']['list']:
            name = marker['Address']['City']
            name = self.fix_city_name(name)
            if name != city.name:
                continue
            if marker['Status'] == "ComingSoon":
                continue

            station = Station()
            station.uid = str
            station.id = str(marker['Id'])
            station.lat = float(marker['Location']['Latitude'])
            station.lng = float(marker['Location']['Longitude'])
            station.zone = ""
            station.description = marker['Address']['Street']
            station.bikes = int(marker['BikesAvailable'])
            station.slots = int(marker['TotalDocks']) - station.bikes
            stations.append(station)

        return stations


    def get_status(self, station, city):
        return station

    def get_zones(self, city):
        return []

    def dump_city(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        city.infos = self.api_url;
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
        print data.encode('utf8')

def test():
    prov = BCycle()
    prov.selftest()

def main():
    test()

if __name__ == '__main__':
    main()
