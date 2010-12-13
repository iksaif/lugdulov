#!/usr/bin/env python
# -*- coding: utf-8 -*-

import getopt
import sys

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

    ret = []
    ret.append(cyclocity.CycloCity())
    ret.append(lyon.LyonVelov())
    ret.append(citybike.CityBike())
    ret.append(nextbike.NextBike())
    ret.append(citybikewien.CityBikeWien())
    ret.append(yelo.Yelo())
    ret.append(dupral.Dupral())
    ret.append(velin.VelIn())
    ret.append(veloplus.VeloPlus())
    ret.append(transdev.Transdev())
    ret.append(velostar.VeloStar())
    ret.append(cyclehire.CycleHire())
    ret.append(bixi.Bixi())

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

def usage():
    print "gen.py list"
    print "gen.py providers"
    print "gen.py countries"
    print "gen.py cities <country>"
    print "gen.py xml-cities <country>"
    print "gen.py xml-stations <city> <country>"
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

    for cmd in cmds:
        if sys.argv[1] == cmd[0]:
            if len(sys.argv) - 2 != cmd[1]:
                usage()
            cmd[2](sys.argv[2:])

if __name__ == '__main__':
    main()
