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
import re
import xml.dom.minidom
import datetime
import urllib2

from plugin import *

class BCycle(Provider):
    """
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'spartanburg',
            'city_name'    : 'Spartanburg',
            'bike_name'    : 'BCycle',
            'server' : 'http://spartanburg.bcycle.com/',
            'lat'  : 34.946667,
            'lng'  : -81.9275,
            }
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
            'city_uid'    : 'madison',
            'city_name'    : 'Madison',
            'bike_name'    : 'BCycle',
            'server' : 'http://madison.bcycle.com/',
            'lat'  : 43.066667,
            'lng'  : -89.4,
            },
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
            'city_uid'    : 'boulder',
            'city_name'    : 'Boulder',
            'bike_name'    : 'BCycle',
            'server' : 'http://boulder.bcycle.com/',
            'lat'  : 40.019444,
            'lng'  : -105.292778,
            },
    """

    config = [
        {
            'country_uid' : 'usa',
            'country_name' : 'USA',
            'city_uid'    : 'denver',
            'city_name'    : 'denver',
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
        ]

    def service_by_city(self, city):
        for service in self.config:
            if service['city_uid'] == city.uid:
                return service
        return Non

    def url(self, city):
        service = self.service_by_city(city)
        return service['server']

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
            city.type = "BCycle"
            #city.rect = self.get_city_bike_zone(service, city)
            ret.append(city)
        return ret

    def get_stations(self, city):
        stations = []
        url = self.url(city)
        fp = urlopen(url)
        data = fp.read()

        """
        var icon = '/images/maps/marker.png';
        var back = 'infowin-available'
        var point = new google.maps.LatLng(41.86727, -87.61527);
        kioskpoints.push(point);
        var marker = new createMarker(point, "<div class='location'><strong>Shedd Aquarium</strong><br />1200 S Lakeshore Drive<br />Chicago, IL 60605</div><div class='avail'>Bikes available: <strong>9</strong><br />Docks available: <strong>12</strong></div><br/>", icon, back);
        markers.push(marker);
        """
        rgpos = re.compile(r'point = new google\.maps\.LatLng\((.*?), (.*?)\);')
        rgmark = re.compile(r'var marker = new createMarker\(point, \"(.*?)\", icon, back\);')
        rghtml = re.compile(r'<div class=\'location\'><strong>(.*?)</strong><br />(.*?)</div><div class=\'avail\'>Bikes available: <strong>(\d+)</strong><br />Docks available: <strong>(\d+)</strong></div><br/>')

        id = 1

        for node in rgpos.findall(data):
            station = Station()
            station.uid = str(id)
            station.id = str(id)
            station.lat = float(node[0])
            station.lng = float(node[1])
            station.zone = ""
            stations.append(station)
            id += 1

        id = 1
        for node in rghtml.findall(data):
            station = stations[id - 1]
            station.name = node[0]
            station.description = node[1].replace("<br />", "")
            station.bikes = int(node[2])
            station.slots = int(node[3])
            id += 1

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
    prov = BCycle()

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
