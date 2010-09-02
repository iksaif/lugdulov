#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  cityBike.py

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

  Clear Channel CityBike

  http://' + dct_city['server'] + "/localizaciones/localizaciones.php"
  Dans ce fichier est incorporé un élément kml

  /!\ Encodage rare &#92; -> '

"""
import sys
import os
import urllib2
import re
import xml.dom.minidom
import datetime
from plugin import *


class CityBike(Provider):
    config = [
            {'country_uid' : 'es',
             'country_name' : 'Spain',
             'city_uid'    : 'barcelone',
             'city_name'    : 'Barcelone',
             'bike_name'    : 'Bicing',
             'server' : 'www.bicing.cat',
             'lat'  : 41.3879170,
             'lng'  : 2.1699187
             },
            {'country_uid' : 'fr',
             'country_name' : 'France',
             'city_uid'    : 'caen',
             'city_name'    : 'Caen',
             'bike_name'    : "V'eol",
             'server' : 'www.veol.caen.fr',
             'lat'  : 49.1846666,
             'lng'  : -0.3602696
             },
            {'country_uid' : 'fr',
             'country_name' : 'France',
             'city_uid'    : 'dijon',
             'city_name'    : 'Dijon',
             'bike_name'    : "Velodi",
             'server' : 'www.velodi.net',
             'lat'  : 47.3272130,
             'lng'  : 5.0439875
             },
            {'country_uid' : 'fr',
             'country_name' : 'France',
             'city_uid'    : 'perpignan',
             'city_name'    : 'Perpignan',
             'bike_name'    : "Bip!",
             'server' : 'www.bip-perpignan.fr',
             'lat'  : 42.7015739,
             'lng'  : 2.8941503
             }
          ]
    # ? Oslo Suède http://www.adshel.no/js/
    # ? Drammen (Norvège)
    # ? Trondheim (Norvège)
    # ? Bergen ?
    # ? Göteborg (Suède)
    # ? Stockolm ; http://www.stockholmcitybikes.se/ -> http://www.citybikes.se/en/Here-are-our-cycle-stands/
    # ? Washington DC :
    cache = {}

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
            city.name = service['city_name']
            city.bikeName = service['bike_name']
            city.bikeIcon = ""
            city.lat = service['lat']
            city.lng = service['lng']
            city.create_rect()
            #city.rect = self.get_city_bike_zone(service, city)
            ret.append(city)
        return ret

    def get_zones(self, city):
        return []

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

    def get_stations_kml_dom(self, city):
        service = self.service_by_city(city)
        if service['server'] in self.cache:
            return self.cache[service['server']]

        url = 'http://' + service['server'] + "/localizaciones/localizaciones.php"
        fp = urllib2.urlopen(url)
        data_html = fp.read()

        match = re.search(r'(<kml .*kml>)', data_html, re.MULTILINE|re.DOTALL)
        data_kml = match.group(0)

        # the html page is coded in iso8859-1 and the kml is declared as utf-8
        # dirty hack there is sometimes 0x92 char as single quote
        #data_kml_mod = data_kml.replace(chr(146), "'")
        data = data_kml.decode('iso-8859-1')
        data = data.encode('utf-8')

        dom = xml.dom.minidom.parseString(data)

        self.cache[service['server']] = dom
        return dom

    def get_stations(self, city):
        service = self.service_by_city(city)
        dom = self.get_stations_kml_dom(city)

        # <Placemark>
        #     <description><![CDATA[<div style="margin:10px"><div style="font:bold 11px verdana;color:#379FC5;margin-bottom:10px">Place St Fiacre - Angle rue Vauban, </div><div style="text-align:right;float:left;font:bold 11px verdana">V�los<br />Parcs de stationnement</div><div style="margin-left:5px;float:left;font:bold 11px verdana;color:green">10<br />5<br /></div></div>]]></description>
        #     <styleUrl>#icono</styleUrl>
        #     <Point>
        #         <coordinates>5.040962398052216,47.32049780635907,13</coordinates>
        #     </Point>
        # </Placemark>
        placemarkers = dom.getElementsByTagName("Placemark")
        stations = []
        n = 1

        for placemarker in placemarkers:
            station = Station()

            desc =  placemarker.childNodes[0].firstChild.toxml()#data

            #<div style="margin:10px">
            #    <div style="font:bold 11px verdana;color:#379FC5;margin-bottom:10px">Place St Fiacre - Angle rue Vauban, </div>
            #    <div style="text-align:right;float:left;font:bold 11px verdana">V�los<br />Parcs de stationnement</div>
            #    <div style="margin-left:5px;float:left;font:bold 11px verdana;color:green">10<br />5<br /></div>
            #</div>

            desc = desc.replace('<![CDATA[', '').replace(']]>', '')
            desc = desc.encode('utf8')
            dom_desc = xml.dom.minidom.parseString(desc)

            #print dom_desc.childNodes[0].nodeValue
            #print dom_desc.childNodes[0].toxml()
            #print dom_desc.childNodes[0].childNodes[0].nodeValue
            #print dom_desc.childNodes[0].childNodes[0].toxml()
            #print dom_desc.childNodes[0].childNodes[0].childNodes[0].nodeValue
            #print dom_desc.childNodes[0].childNodes[0].childNodes[0].toxml()

            name = dom_desc.childNodes[0].childNodes[0].childNodes[0].nodeValue.split(' - ')
            if (len(name) < 2):
                name = name[0]
                name = name.split(',')
            if (len(name) < 2):
                name = name[0]
                name = name.split(', ')
            if (len(name) < 2):
                name = [name[0], name[0]]

            station.name = name[0]
            station.description = name[1]
            station.name = station.name.replace("\\", "")
            station.description = station.description.replace("\\", "")

            station.uid = str(n)
            station.id = station.uid
            n += 1

            #print dom_desc.childNodes[0].childNodes[2].childNodes[2].nodeValue
            #print dom_desc.childNodes[0].childNodes[2].childNodes[2].toxml()

            station.slots = int(dom_desc.childNodes[0].childNodes[2].childNodes[2].toxml())
            station.bikes = int(dom_desc.childNodes[0].childNodes[2].childNodes[0].nodeValue)

            coord = placemarker.childNodes[2].childNodes[0].childNodes[0].toxml()
            station.lng = float(re.sub('[^0-9.-]','' , coord.split(',')[0]))
            station.lat = float(re.sub('[^0-9.-]','' , coord.split(',')[1]))
            station.zone = "0"

            stations.append(station)
        return stations

    def get_status(self, station, city):
        return station

    def dump_priv(self, city):
        data = open('citybike/priv.tpl.h').read()
        service = self.service_by_city(city)
        #city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_priv(data, city)
        data = data.replace('<statusUrl>', '')
        data = data.replace('<infosUrl>', 'http://' +  service['server'] + '/localizaciones/localizaciones.php')
        print data.encode('utf8')

    def dump_class(self, city):
        data = open('citybike/class.tpl.cpp').read()
        data = self._dump_class(data, city)
        print data.encode('utf8')

    def dump_header(self, city):
        data = open('citybike/header.tpl.h').read()
        data = self._dump_header(data, city)
        print data.encode('utf8')

def test():
    prov = CityBike()

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
