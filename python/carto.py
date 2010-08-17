#!/usr/bin/env python
# -*- coding: utf-8 -*-

import urllib2
import sys
import getopt
import json

# This files is for cities that implements the "carto" standard

cities = {}
cities['cergypontoise'] = {'code'    : 'cergypontoise',
                           'city'    : 'Cergy-Pontoise',
                           'bike'    : 'Velo2',
                           'service' : 'http://www.velo2.cergypontoise.fr/service/',
                           'center'  : (49.03, 2.06)}

cities['paris'] = {'code'    : 'paris',
                   'city'    : 'Paris',
                   'bike'    : 'Vélib\'',
                   'service' : 'http://www.velib.paris.fr/service/',
                   'center'  : (48.86, 2.33)}

cities['creteil'] = {'code'    : 'creteil',
                     'city'    : 'Creteil',
                     'bike'    : 'Cristolib',
                     'service' : 'http://www.cristolib.fr/service/',
                     'center'  : (48.78, 2.46)}

cities['aixenprovence'] = {'code'    : 'aixenprovence',
                           'city'    : 'Aix-en-Provence',
                           'bike'    : 'V\'Hello',
                           'service' : 'http://www.vhello.fr/service/',
                           'center'  : (43.53, 5.43)}

cities['amiens'] = {'code'    : 'amiens',
                    'city'    : 'Amiens',
                    'bike'    : 'Velam',
                    'service' : 'http://www.velam.amiens.fr/service/',
                    'center'  : (49.90, 2.30)}

cities['besancon'] = {'code'    : 'besancon',
                      'city'    : u'Besançon',
                      'bike'    : 'VéloCité',
                      'service' : 'http://www.velocite.besancon.fr/service/',
                      'center'  : (47.25, 6.03)}

cities['marseille'] = {'code'    : 'marseille',
                       'city'    : 'Marseille',
                       'bike'    : 'Le Vélo',
                       'service' : 'http://www.levelo-mpm.fr/service/',
                       'center'  : (43.30, 5.40)}

cities['mulhouse'] = {'code'    : 'mulhouse',
                      'city'    : 'Mulhouse',
                      'bike'    : 'VéloCité',
                      'service' : 'http://www.velocite.mulhouse.fr/service/',
                      'center'  : (47.75, 7.32)}

cities['nancy'] = {'code'    : 'nancy',
                   'city'    : 'Nancy',
                   'bike'    : 'vélOStan',
                   'service' : 'http://www.velostanlib.fr/service/',
                   'center'  : (48.68, 6.20)}

cities['nantes'] = {'code'    : 'nantes',
                    'city'    : 'Nantes',
                    'bike'    : 'Bicloo',
                    'service' : 'http://www.bicloo.nantesmetropole.fr/service/',
                    'center'  : (47.21, -1.55)}

cities['plainecommune'] = {'code'    : 'plainecommune',
                           'city'    : 'Plaine Commune',
                           'bike'    : 'Velcom',
                           'service' : 'http://www.velcom.fr/service/',
                           'center'  : (48.92, 2.37)}

cities['rouen'] = {'code'    : 'rouen',
                   'city'    : 'Rouen',
                   'bike'    : 'Cyclic',
                   'service' : 'http://cyclic.rouen.fr/service/',
                   'center'  : (49.43, 1.08)}

cities['toulouse'] = {'code'    : 'toulouse',
                      'city'    : 'Toulouse',
                      'bike'    : 'Vélouse',
                      'service' : 'http://www.velo.toulouse.fr/service/',
                      'center'  : (43.60, 1.43)}

cities['bruxelles'] = {'code'    : 'bruxelles',
                       'city'    : 'Bruxelles',
                       'bike'    : 'Villo',
                       'service' : 'http://www.villo.be/service/',
                       'center'  : (50.833, 4.333)}

cities['dublin'] = {'code'    : 'dublin',
                    'city'    : 'Dublin',
                    'bike'    : 'Dubline Bikes',
                    'service' : 'http://www.dublinbikes.ie/service/',
                    'center'  : (53.333, -6.249)}

cities['luxembourg'] = {'code'    : 'luxembourg',
                        'city'    : 'Luxembourg',
                        'bike'    : 'Veloh',
                        'service' : 'http://www.veloh.lu/service/',
                        'center'  : (49.612, 6.130)}

cities['santander'] = {'code'    : 'santander',
                       'city'    : 'Santander',
                       'bike'    : 'Tusbic',
                       'service' : 'http://www.tusbic.es/service/',
                       'center'  : (43.465, -3.804)}

cities['seville'] = {'code'    : 'seville',
                     'city'    : 'Seville',
                     'bike'    : 'Sevici',
                     'service' : 'http://www.sevici.es/service/',
                     'center'  : (37.377, -5.987)}

cities['toyama'] = {'code'    : 'toyama',
                    'city'    : 'Toyama',
                    'bike'    : 'Cyclocity',
                    'service' : 'http://www.cyclocity.jp/service/',
                    'center'  : (36.69, 137.21)}

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

    if 'center' in city:
        city['limits'] = {'max_lat' : city['center'][0] + 0.2,
                          'min_lat' : city['center'][0] - 0.2,
                          'max_lng' : city['center'][1] + 0.2,
                          'min_lng' : city['center'][1] - 0.2}

    for j in total['markers']:
        lat = float(j['lat'])
        lng = float(j['lng'])
        skip = False

	# begin dirty hack for dirty data :-(
	if ('exclude' in city and int(j['number']) in city['exclude']) or \
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

def dump_tpl(city, data, output):
    data = data.replace('<BikeName>', city['bike']);
    data = data.replace('<CityName>', city['city'].encode('utf8'));
    data = data.replace('<City>', city['code'].title());
    data = data.replace('<city>', city['code']);
    data = data.replace('<CITY>', city['code'].upper());
    print >>output, data

def dump_header(city, output):
    data = open('carto_header.tpl').read()
    return dump_tpl(city, data, output)

def dump_class(city, output):
    data = open('carto_class.tpl').read()
    return dump_tpl(city, data, output)

def main():

    try:
        opts, args = getopt.getopt(sys.argv[1:], "ho:fvcpt",
                                   ["help", "output=", "full", "version", "cpp", "class", "header"])
    except getopt.GetoptError, err:
        print str(err)
        usage()
        sys.exit(2)
    output = None
    verbose = False
    full = False
    mode = "json"
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
            mode = "cpp"
        elif o in ("-p", "--class"):
            mode = "class"
        elif o in ("-t", "--header"):
            mode = "header"
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

    if mode == "header":
        dump_header(city, output)
        return

    if mode == "class":
        dump_class(city, output)
        return

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
    if mode == "cpp":
        dump_cpp(city, data, total, output)
    else:
        dump_json(total, output)

if __name__ == "__main__":
    main()

