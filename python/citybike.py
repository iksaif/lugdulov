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
import urllib
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
            {'country_uid' : 'es',
             'country_name' : 'Spain',
             'city_uid'    : 'zaragoza',
             'city_name'    : 'Zaragoza',
             'bike_name'    : 'Bizi',
             'server' : 'www.bizizaragoza.com',
             'lat'  : 41.65,
             'lng'  : -0.883333,
             'infos_url' : '/localizaciones/station_map.php'
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
            city.lat = service['lat']
            city.lng = service['lng']
            city.create_rect()
            city.type = "CityBike"
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

    def get_stations_kml_dom(self, city, data):
        match = re.search(r'(<kml .*kml>)', data, re.MULTILINE|re.DOTALL)

        data_kml = match.group(0)

        # the html page is coded in iso8859-1 and the kml is declared as utf-8
        # dirty hack there is sometimes 0x92 char as single quote
        #data_kml_mod = data_kml.replace(chr(146), "'")
        data = data_kml.decode('iso-8859-1')
        data = data.encode('utf-8')

        dom = xml.dom.minidom.parseString(data)
        return dom

    def get_stations_kml(self, city, data):
        service = self.service_by_city(city)
        dom = self.get_stations_kml_dom(city, data)

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
            name = dom_desc.childNodes[0].childNodes[0].childNodes[0].nodeValue
            name = name.replace(u'\x92', "'")
            name = name.split(' - ')
            if (len(name) < 2):
                name = name[0]
                name = name.split(',')
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
            station.zone = ""

            stations.append(station)
        return stations

    def get_stations_js(self, city, data):
        points = []
        ids = []
        names = []
        urls = []

        #point = new GLatLng(41.65188900000000000,-0.88064700000000000);
        for matches in re.findall("point = new GLatLng\((.+?),(.+?)\);", data):
            points.append(matches)
        for matches in re.findall("data:.*?idStation=.*?([\d]+)", data):
            ids.append(matches)
        for matches in re.findall("url:.*?\"([^,]+).*?\"", data):
            urls.append(matches)
        for matches in re.findall("<a href=\"javascript:.*?ada\('([0-9]+)'\)\">(.+)</a>", data):
            if matches[0] in ['0', '-1']:
                continue
            names.append(matches)

        stations = []

        for uid in ids:
            station = Station()

            station.uid = uid
            station.id = station.uid

            if len(names) == len(points):
                name = names[len(stations)][1]
            else:
                name = "Station %s" % uid

            name = re.sub('<[^<]+?>', '', name)
            name = name.split(' - ')
            if (len(name) < 2):
                name = name[0]
                name = name.split(',')
            if (len(name) < 2):
                name = [name[0], name[0]]
            station.name = name[0]
            station.description = name[1]
            station.name = station.name.replace("\\", "")
            station.description = station.description.replace("\\", "")

            station.status_url = urls[len(stations)]

            if not city.status:
                service = self.service_by_city(city)
                city.status = 'http://' + service['server'] + '/' + station.status_url

            station.slots = -1
            station.bikes = -1
            #print params[len(stations)]
            station.lng = float(points[len(stations)][1])
            station.lat = float(points[len(stations)][0])
            station.zone = ""

            stations.append(station)
        return stations

    def get_stations(self, city):
        service = self.service_by_city(city)

        if 'infos_url' in service:
            url = 'http://' + service['server'] + service['infos_url']
        else:
            url = 'http://' + service['server'] + "/localizaciones/localizaciones.php"

        fp = urlopen(url)
        data = fp.read()

        if '<kml xmlns="http://earth.google.com/kml/2.0">' in data:
            city.mode = 'kml'
            return self.get_stations_kml(city, data)
        else:
            city.mode = 'js'
            return self.get_stations_js(city, data)

    def get_status(self, station, city):
        if city.mode == 'kml':
            return station

        service = self.service_by_city(city)

        url = 'http://' + service['server'] + '/' + station.status_url

        fp = urlopen(url, "idStation=%s" % station.id)
        data = fp.read()

        matches = re.findall("^\s*\:\s*(\d+)", data, re.M)

        station.bikes = matches[0]
        station.slots = matches[1]
        return station

    def dump_city(self, city):
        service = self.service_by_city(city)
        city.rect = self.get_city_bike_zone(service, city)

        if 'infos_url' in service:
            url = 'http://' + service['server'] + service['infos_url']
        else:
            url = 'http://' + service['server'] + "/localizaciones/localizaciones.php"

        city.infos = url
        data = self._dump_city(city)
        print data

    def dump_stations(self, city):
        service = self.service_by_city(city)
        city.rect = self.get_city_bike_zone(service, city)
        data = self._dump_stations(city)
        print data.encode('utf8')

def test():
    prov = CityBike()
    prov.selftest()

def main():
    test()

if __name__ == '__main__':
    main()
