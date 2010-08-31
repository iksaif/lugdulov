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

class Country():
    uid = ""
    name = ""

    def __str__(self):
        return self.name.encode('utf8') + " (" + self.uid + ")"

class City():
    uid = ""
    name = ""
    bikeName = "Bike"
    bikeIcon = ""
    lat = 0.
    lng = 0.
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

    def _dump_priv(self, data, city):
        builtin = """
static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {\n"""

        zones = self.get_zones(city)
        stations = self.get_stations(city)
        for station in stations:
            skip = False

            if not city.contains((station.lat, station.lng)):
                skip = True

            for zone in zones:
                if zone.contains((station.lat, station.lng)):
                    station.zone = int(zone.uid)
                    break

            if skip:
                builtin += "//"

            builtin += '\t{ %s, %s, "%s", "%s", %s, %s },\n' % \
                (station.id, station.zone, station.name.title(), \
                     station.description.title(), station.lat, station.lng)
        builtin += "\t{0, 0, NULL, NULL, 0., 0.}\n"
        builtin += "};\n"

        rect = "QRectF(QPointF(%.6f, %.6f), QPointF(%.6f, %.6f))" % city.rect
        center = "QPointF(%.6f, %.6f)" % (city.lat, city.lng)

        regions = ""
        for zone in zones:
            regions += '    ret << "%d";\n' % int(zone.uid)

        data = data.replace('<stations>', builtin)
        data = data.replace('<rect>', rect)
        data = data.replace('<center>', center);
        data = data.replace('<CITY>', city.uid.upper());
        data = data.replace('<City>', city.uid.title());
        data = data.replace('<regions>', regions)
        return data

    def _dump_gen(self, data, city):
        data = data.replace('<BikeName>', city.bikeName);
        data = data.replace('<CityName>', city.name);
        data = data.replace('<City>', city.uid.title());
        data = data.replace('<city>', city.uid.lower());
        data = data.replace('<CITY>', city.uid.upper());
        return data

    def _dump_class(self, tpl, city):
        return self._dump_gen(tpl, city)

    def _dump_header(self, tpl, city):
        return self._dump_gen(tpl, city)

    def __init__(self):
        pass
