#!/usr/bin/env python
# -*- coding: utf-8 -*-

import getopt
import sys
import random

def getproviders():
    import cyclocity
    import lyon
    import citybike
    import nextbike
    import citybikewien
    import yelo
    import dupral
    import velin
    import veloplus
    import transdev
    import velostar
    import cyclehire
    import bixi
    import bcycle
    import melbourne
    import decobike
    import callabike
    import youbike

    ret = []
    ret.append(cyclocity.CycloCity())
    ret.append(lyon.LyonVelov())
    ret.append(citybike.CityBike())
    ret.append(nextbike.NextBike())
    ret.append(citybikewien.CityBikeWien())
    # Disabled, site is broken
    #ret.append(yelo.Yelo())
    ret.append(dupral.Dupral())
    ret.append(velin.VelIn())
    ret.append(veloplus.VeloPlus())
    ret.append(transdev.Transdev())
    ret.append(velostar.VeloStar())
    ret.append(cyclehire.CycleHire())
    ret.append(bixi.Bixi())
    ret.append(bcycle.BCycle())
    ret.append(melbourne.Melbourne())
    ret.append(decobike.DecoBikes())
    ret.append(callabike.CallABike())
    ret.append(youbike.Youbike())

    return ret

def dolist(args):
    ret = {}
    cities = []
    bikes = []
    for p in getproviders():
        for c in p.get_countries():
            if c.name not in ret:
                ret[c.name] = []
            for j in p.get_cities(c):
                cname = j.name.encode('utf8')
                bname = j.bikeName.encode('utf8')
                ret[c.name].append(cname + " (" + bname + ")")
                if cname not in cities:
                    cities.append(cname)
                if bname not in bikes:
                    bikes.append(bname)

    for i in ret.keys():
        print i + ":"
        print ", ".join(ret[i])
        print

    print "<dl>"
    for i in ret.keys():
        print "<dt>%s</dt>" % i
        print "<dd>" + ", ".join(ret[i]) + "</dd>"
    print "</dl>"

    print ", ".join(cities)
    print ", ".join(bikes)
    print
    print "%d countries %d cities %d networks" % (len(ret.keys()), len(cities), len(bikes))

def docountries(args):
    ret = {}

    for p in getproviders():
        for c in p.get_countries():
            if c.name not in ret:
                ret[c.name] = c
    for k in ret.keys():
        c = ret[k]
        print c.uid + ":" + c.name

def docities(args):
    ret = []
    country = args[0]

    for p in getproviders():
        for c in p.get_countries():
            if c.name != country and c.uid != country:
                continue
            for j in p.get_cities(c):
                ret.append(j)

    for i in ret:
        print i.id.encode('utf8') + ":" + i.uid.encode('utf8') + ":" + i.name.encode('utf8')

def find(city, country):
    for p in getproviders():
        for c in p.get_countries():
            if c.name != country and c.uid != country:
                continue
            for j in p.get_cities(c):
                if j.name == city or j.uid == city or j.id == city:
                    return p, c, j
    return None, None, None


def doxmlcities(args):
    country = args[0]

    for p in getproviders():
        for c in p.get_countries():
            if c.name != country and c.uid != country:
                continue
            for j in p.get_cities(c):
                p.dump_city(j)

def doxmlstations(args):
    p, country, city = find(args[0], args[1])
    p.dump_stations(city)


def test(provider, country, city):
    try:
        stations = provider.get_stations(city)
        status = "%s %s: %d stations" % (country.uid, city.uid, len(stations))
        #for s in stations:
        #    print s.id, s.lat, s.lng
        if city.id in ['lyon']:
            return
        if len(stations):
            i = random.randint(0, len(stations) - 1)
            i = 0
            station = stations[i]
            station = provider.get_status(station, city)
            status += "\t\t-> random station: %s %s %d %d" % (station.id, station.name, station.bikes, station.slots)
        else:
            station = None
        print status.encode('utf8')
    except Exception as e:
        print '%s %s %s: fail: %s' % (provider, country.uid, city.uid, e)


def dotest(args):
    for p in getproviders():
        for c in p.get_countries():
            for j in p.get_cities(c):
                test(p, c, j)

def dotestcity(args):
    p, country, city = find(args[0], args[1])
    test(p, country, city)

def usage():
    print "gen.py list"
    print "gen.py providers"
    print "gen.py countries"
    print "gen.py cities <country>"
    print "gen.py xml-cities <country>"
    print "gen.py xml-stations <city> <country>"
    print "gen.py test"
    print "gen.py test-city <city> <country>"
    sys.exit(1)

def main():
    if len(sys.argv) == 1:
        usage()

    cmds = []
    cmds.append(('list', 0, dolist))
    cmds.append(('countries', 0, docountries))
    cmds.append(('cities', 1, docities))
    cmds.append(('xml-cities', 1, doxmlcities))
    cmds.append(('xml-stations', 2, doxmlstations))
    cmds.append(('test', 0, dotest))
    cmds.append(('test-city', 2, dotestcity))

    for cmd in cmds:
        if sys.argv[1] == cmd[0]:
            if len(sys.argv) - 2 != cmd[1]:
                usage()
            cmd[2](sys.argv[2:])

if __name__ == '__main__':
    main()
