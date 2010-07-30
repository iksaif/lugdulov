#!/usr/bin/env python

import urllib2
import sys
import getopt
import json

def station_status_url(id):
    return "http://www.velib.paris.fr/service/stationdetails/%d" % id

def stations_xml_url():
    return "http://www.velib.paris.fr/service/carto"

def usage():
    print "lyon.py [options] [-o out]"
    print "Options:"
    print " -v           verbose"
    print " -h, --help   help"
    print " -o, --output output file"
    print " -f, --full   also dump status"
    print " -c, --cpp    dump cpp file"
    sys.exit(1)

# <marker name="20008 - MARAICHERS" number="20008" address="73 RUE DES PYRENEES -" fullAddress="73 RUE DES PYRENEES - 75020 PARIS" lat="48.85316690359092" lng="2.405881834065018" open="1" bonus="0"/>
# <arrondissement number="20" minLat="48.81155366000667" minLng="2.303560301490029" maxLat="48.87821186640261" maxLng="2.475836648494102"/>

def find_region(data, marker):
    pass

def stations():
    import xml.dom.minidom

    url = stations_xml_url()

    fp = urllib2.urlopen(url)
    data = fp.read()

    dom = xml.dom.minidom.parseString(data)
    markers = dom.getElementsByTagName("marker")
    arrondissements = dom.getElementsByTagName("arrondissement")

    data = {'markers' : [], 'arrondissements' : {}}

    for marker in markers:
        ret = {}
        for elem in ["name", "number", "address", "fullAddress", "lat", "lng"]:
            ret[elem] = marker.getAttribute(elem)
        data['markers'].append(ret)

    for arrondissement in arrondissements:
        ret = {}
        for elem in ["number"]:
            ret[elem] = int(arrondissement.getAttribute(elem))
        for elem in ["minLat", "minLng", "maxLat", "maxLng"]:
            ret[elem] = float(arrondissement.getAttribute(elem))
        data['arrondissements'][ret['number']] = ret

    return data

def status(id):
    import xml.dom.minidom

    url = station_status_url(id)
    fp = urllib2.urlopen(url)
    data = fp.read()

    dom = xml.dom.minidom.parseString(data)
    station = dom.getElementsByTagName("station")[0]

    ret = {}
    for elem in ["available", "free", "total", "ticket"]:
        ret[elem] = station.getElementsByTagName(elem)[0].childNodes[0].data
    return ret

def dump_json(total, output):
    print >>output, json.dumps(total)

def dump_cpp(total, output):
    struct = """
struct {
        int number;
        int arrondissementNumber;
        const char *address;
        const char *fullAddress;
        double x;
        double y;
} stations[] = {"""
    print >>output, struct
    for j in total['markers']:
        line = '\t{ %s, %s, "%s", "%s", %s, %s },' % (j['number'], j['arrondissementNumber'], j['name'], j['address'], j['fullAddress'], j['x'], j['y'])
        print >>output, line
    print >>output, "\t{0, 0, NULL, NULL, 0., 0.}"
    print >>output, "};"

def main():

    try:
        opts, args = getopt.getopt(sys.argv[1:], "ho:fvc", ["help", "output=", "full", "version", "cpp"])
    except getopt.GetoptError, err:
        print str(err)
        usage()
        sys.exit(2)
    output = None
    verbose = False
    full = False
    cpp = False
    for o, a in opts:
        if o == "-v":
            verbose = True
        elif o in ("-h", "--help"):
            usage()
            sys.exit()
        elif o in ("-o", "--output"):
            output = a
        elif o in ("-f", "--full"):
            full = True
        elif o in ("-c", "--cpp"):
            cpp = True
        else:
            assert False, "unhandled option"

    if output:
        output = open(output, "w")
    else:
        output = sys.stdout

    total = {u'markers' : []}
    if verbose:
        print >>sys.stderr, stations_xml_url(i)
    data = stations()
    if 'markers' not in data:
        return
    for j in data['markers']:
        if full:
            id = int(j['number'])
            if verbose:
                print >>sys.stderr, station_status_url(id)
            try:
                j['status'] = status(id)
            except Exception, err:
                print err
        j['arrondissementNumber'] = find_region(data, j)
        total['markers'].append(j)
    if cpp:
        dump_cpp(total, output)
    else:
        dump_json(total, output)

if __name__ == "__main__":
    main()

