#!/usr/bin/env python

import urllib2
import sys
import getopt
import json

# This files is for cities that implements the "carto" standard

france = {'max_lat' : 50, 'min_lat' : 42, 'max_lng' : 9, 'min_lng' : -9}

cities = {}
cities['paris'] = {'code'    : 'paris',
                   'city'    : 'Paris',
                   'service' : 'http://www.velib.paris.fr/service/',
                   'exclude' : [],
                   'limits'  : france}

def station_status_url(service, id):
    return service + "stationdetails/%d" % id

def stations_xml_url(service):
    return service + "carto"

def usage():
    print "cergypontoise.py [options] [-o out] city"
    print "Options:"
    print " -v           verbose"
    print " -h, --help   help"
    print " -o, --output output file"
    print " -f, --full   also dump status"
    print " -c, --cpp    dump cpp file"
    print "Cities:"
    print " " + ",".join(cities.keys())
    sys.exit(1)

# <marker name="20008 - MARAICHERS" number="20008" address="73 RUE DES PYRENEES -" fullAddress="73 RUE DES PYRENEES - 75020 PARIS" lat="48.85316690359092" lng="2.405881834065018" open="1" bonus="0"/>
# <arrondissement number="20" minLat="48.81155366000667" minLng="2.303560301490029" maxLat="48.87821186640261" maxLng="2.475836648494102"/>

def find_region(data, marker):
    for region in data['arrondissements']:
        ret = data['arrondissements'][region]

        if region == 0:
            continue

        if marker['lat'] >= ret['minLat'] and marker['lat'] <= ret['maxLat'] \
                and marker['lng'] >= ret['minLng'] and marker['lng'] <= ret['maxLng']:
            return region
    return 0

def stations(city):
    import xml.dom.minidom

    url = stations_xml_url(city['service'])

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
            if elem in ['lat', 'lng']:
                ret[elem] = float(ret[elem])
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

def dump_cpp(city, data, total, output):
    stations = """
static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        const char *fullAddress;
        double x;
        double y;
} stations[] = {\n"""

    lat_min  = 999.0
    lat_max  = -999.0
    lng_min = 999.0
    lng_max = -999.0

    for j in total['markers']:
        lat = float(j['lat'])
        lng = float(j['lng'])
        skip = False

	# begin dirty hack for dirty data :-(
	if int(j['number']) in city['exclude'] or \
                lat > city['limits']['max_lat'] or lat < city['limits']['min_lat'] or \
                lng > city['limits']['max_lng'] or lng < city['limits']['min_lng']:
            skip = True

        if skip:
            stations += "//"
        stations += '\t{ %s, %s, "%s", "%s", "%s", %s, %s },\n' % \
            (j['number'], j['arrondissementNumber'], j['name'].title(), \
                 j['address'].title(), j['fullAddress'].title(), j['lat'], j['lng'])

        if not skip:
            if lat_min > float(j['lat']) : lat_min = float(j['lat'])
            if lat_max < float(j['lat']) : lat_max = float(j['lat'])
            if lng_min > float(j['lng']) : lng_min = float(j['lng'])
            if lng_max < float(j['lng']) : lng_max = float(j['lng'])

    stations += "\t{0, 0, NULL, NULL, NULL, 0., 0.}\n"
    stations += "};\n"

    lat_border = (lat_max - lat_min) / 50
    lng_border = (lng_max - lng_min) / 50

    rect = "QRectF(QPointF(%.12f, %.12f), " % (lat_min - lat_border, lng_min - lng_border)
    rect += "QPointF(%.12f, %.12f))" % (lat_max + lat_border, lng_max + lng_border)
    center = "QPointF(%.12f, %.12f)" % ((lat_min + lat_max) / 2, (lng_min + lng_max) / 2)

    regions = ""
    for region in data['arrondissements']:
        regions += '    ret << "%d";\n' % region

    data = open('carto_template.h').read()
    data = data.replace('<stations>', stations)
    data = data.replace('<rect>', rect)
    data = data.replace('<center>', center);
    data = data.replace('<CITY>', city['code'].upper());
    data = data.replace('<City>', city['code'].title());
    data = data.replace('<statusUrl>', city['service'] + 'stationdetails/%1')
    data = data.replace('<cartoUrl>', city['service'] + 'carto')
    data = data.replace('<regions>', regions)
    print >>output, data.encode('utf8')

def main():

    try:
        opts, args = getopt.getopt(sys.argv[1:], "ho:fvc",
                                   ["help", "output=", "full", "version", "cpp"])
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

    if not args or args[0] not in cities:
        usage()
    city = cities[args[0]]

    total = {u'markers' : []}

    if verbose:
        print >>sys.stderr, stations_xml_url(city['service'], i)

    data = stations(city)
    if 'markers' not in data:
        return
    for j in data['markers']:
        if full:
            id = int(j['number'])
            if verbose:
                print >>sys.stderr, station_status_url(city['service'], id)
            try:
                j['status'] = status(id)
            except Exception, err:
                print err
        j['arrondissementNumber'] = find_region(data, j)
        total['markers'].append(j)
    if cpp:
        dump_cpp(city, data, total, output)
    else:
        dump_json(total, output)

if __name__ == "__main__":
    main()

