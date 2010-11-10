#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
  plugin.py

  Copyright (C) 2010 Patrick Installé <PatrickInstalle@P-Installe.be>
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

  template lugdulov meta program

"""

cache = True

def urlopen(url):
    import urllib2
    from cache import CacheHandler

    if cache:
        opener = urllib2.build_opener(CacheHandler("cache"))
        return opener.open(url)
    else:
        return urllib2.urlopen(url)

class Country():
    uid = ""
    name = ""
    description = ""

    def __str__(self):
        return self.name.encode('utf8') + " (" + self.uid + ")"

class City():
    id = ""
    uid = ""
    name = ""
    bikeName = "Bike"
    bikeIcon = ""
    lat = 0.
    lng = 0.
    rect = (0., 0., 0., 0.)
    type = ""
    infos = ""
    status = ""

    def create_center(self):
        self.lat = (self.rect[0] + self.rect[2]) / 2
        self.lng = (self.rect[1] + self.rect[3]) / 2

    def create_rect(self, offset = 0.2):
        self.rect = (self.lat - offset, self.lng - offset, self.lat + offset, self.lng + offset)

    def contains(self, pt):
        if pt[0] >= self.rect[0] and pt[0] <= self.rect[2]:
            if pt[1] >= self.rect[1] and pt[1] <= self.rect[3]:
                return True
        return False

    def __str__(self):
        ret = self.name.encode('utf8') + " (" + self.uid + ")"
        ret += "\t" + self.bikeName.encode('utf8') + " " + self.bikeIcon
        ret += "\t" + str(self.lat) + "x" + str(self.lng)
        ret += "\t" + str(self.rect)
        return ret

class Zone():
    uid = ""
    name = ""
    lat = 0
    lng = 0
    rect = (0., 0., 0., 0.)

    def create_center(self):
        self.lat = (self.rect[0] + self.rect[2]) / 2
        self.lng = (self.rect[1] + self.rect[3]) / 2

    def create_rect(self, offset = 0.2):
        self.rect = (self.lat - offset, self.lng - offset, self.lat + offset, self.lng + offset)

    def contains(self, pt):
        if pt[0] >= self.rect[0] and pt[0] <= self.rect[2]:
            if pt[1] >= self.rect[1] and pt[1] <= self.rect[3]:
                return True
        return False

    def __str__(self):
        ret = self.name + " (" + self.uid + ")"
        ret += "\t" + str(self.rect)
        return ret

class Station():
    id = 0
    uid = ""
    name = ""
    description = ""
    zone = ""
    lat = 0.
    lng = 0.
    bikes = 0
    slots = 0
    ticket = 0

    def __str__(self):
        ret = self.name + " (" + self.id + ")"
        ret += "\t" + self.description
        ret += "\t" + self.zone
        ret += "\t" + str(self.lat) + "x" + str(self.lng)
        ret += "\t" + "bikes: " + str(self.bikes) + " slots: " + str(self.slots)
        return ret.encode('utf8')

class Provider():

    def get_countries(self):
        pass

    def get_cities(self, country):
        pass

    def get_zones(self, city):
        pass

    def get_stations(self, city):
        pass

    def get_status(self, station, city):
        pass

    def get_city_bike_zone(self, service, city, offset = 0.01):
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
        return lat_min - offset, lng_min - offset, lat_max + offset, lng_max + offset

    def _dump_city(self, city):

        uid = city.uid.replace(".", "").replace("-", "_")

        ret = '<city id="%s">\n' % uid
        ret += '  <type>%s</type>\n' % city.type
        ret += '  <latitude min="%f" max="%f">%f</latitude>\n' % (city.rect[0], city.rect[2], city.lat)
        ret += '  <longitude min="%f" max="%f">%f</longitude>\n' % (city.rect[1], city.rect[3], city.lng)
        if city.status:
            ret += '  <status>%s</status>\n' % city.status.replace('&', '&amp;')
        if city.infos:
            ret += '  <infos>%s</infos>\n' % city.infos.replace('&', '&amp;')
        ret += '  <name>%s</name>\n' % city.name.title()
        if city.bikeName:
            ret += '  <bikeName>%s</bikeName>\n' % city.bikeName
        if city.bikeIcon:
            ret += '  <bikeIcon>%s</bikeIcon>\n' % city.bikeIcon
        ret += '</city>'

        return ret.encode('utf8')

    def _dump_stations(self, city):
        zones = self.get_zones(city)
        stations = self.get_stations(city)
        ret = ""

        for station in stations:
            skip = False

            if not city.contains((station.lat, station.lng)):
                skip = True

            for zone in zones:
                if zone.contains((station.lat, station.lng)):
                    station.zone = int(zone.uid)
                    break

            if skip:
                ret += "<!--\n"

            ret += '<station id="%s">\n' % station.id;
            ret += '  <name>%s</name>\n' % station.name.title().strip()
            if station.description:
                ret += '  <description>%s</description>\n' % station.description.title().strip()
            if station.zone:
                ret += '  <region>%s</region>\n' % station.zone
            ret += '  <latitude>%.6f</latitude>\n' % station.lat
            ret += '  <longitude>%.6f</longitude>\n' % station.lng
            ret += "</station>";

            if skip:
                ret += '\n--/>'

        return ret

    def __init__(self):
        pass
