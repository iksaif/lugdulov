#!/usr/bin/env python
# -*- coding: utf-8 -*-

import getopt
import sys

def getproviders():
    import cyclocity
    import lyon

    ret = []
    ret.append(cyclocity.CycloCity())
    ret.append(lyon.LyonVelov())
    return ret

def dolist(args):
    ret = {}

    for p in getproviders():
        for c in p.get_countries():
            if c.name not in ret:
                ret[c.name] = []
            for j in p.get_cities(c):
                ret[c.name].append(j.name.encode('utf8'))

    for i in ret.keys():
        print i + ":"
        print ", ".join(ret[i])
        print

def docountries(args):
    ret = {}

    for p in getproviders():
        for c in p.get_countries():
            if c.name not in ret:
                ret[c.name] = c
    for k in ret.keys():
        c = ret[k]
        print c.uid + " " + c.name + " "

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
        print i.uid + " " + i.name.encode('utf8')

def find(city, country):
    for p in getproviders():
        for c in p.get_countries():
            if c.name != country and c.uid != country:
                continue
            for j in p.get_cities(c):
                if j.name == city or j.uid == city:
                    return p, c, j
    return None, None, None


def dopriv(args):
    p, country, city = find(args[0], args[1])
    p.dump_priv(city)

def doplugin(args):
    p, country, city = find(args[0], args[1])
    p.dump_class(city)

def doheader(args):
    p, country, city = find(args[0], args[1])
    p.dump_header(city)

def usage():
    print "gen.py list"
    print "gen.py providers"
    print "gen.py countries"
    print "gen.py cities <country>"
    print "gen.py gen-priv <city> <country>"
    print "gen.py gen-plugin <city> <country>"
    print "gen.py gen-header <city> <country>"
    sys.exit(1)

def main():
    if len(sys.argv) == 1:
        usage()

    cmds = []
    cmds.append(('list', 0, dolist))
    cmds.append(('countries', 0, docountries))
    cmds.append(('cities', 1, docities))
    cmds.append(('gen-priv', 2, dopriv))
    cmds.append(('gen-plugin', 2, doplugin))
    cmds.append(('gen-header', 2, doheader))

    for cmd in cmds:
        if sys.argv[1] == cmd[0]:
            if len(sys.argv) - 2 != cmd[1]:
                usage()
            cmd[2](sys.argv[2:])

if __name__ == '__main__':
    main()