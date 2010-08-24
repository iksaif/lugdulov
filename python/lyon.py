#!/usr/bin/env python

import urllib2
import json
import sys
import getopt

regions = ["69381", "69382", "69383", "69384", "69385", "69386", "69387",
           "69388", "69389", "69266", "69034", "69256"]

def station_json_url(id):
    return "http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParId.php?gid=%d" % id

def stations_json_url(region):
    return "http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParArrondissement.php?arrondissement=%s" % region

def station_status_url(id):
    return "http://www.velov.grandlyon.com/velovmap/zhp/inc/DispoStationsParId.php?id=%d" % id

def station_image_url(id):
    return "http://www.velov.grandlyon.com/uploads/tx_gsstationsvelov/%d.jpg" % id

def usage():
    print "lyon.py [options] [-o out]"
    print "Options:"
    print " -v           verbose"
    print " -h, --help   help"
    print " -o, --output output file"
    print " -f, --full   also dump status"
    print " -c, --cpp    dump cpp file"
    print " -p, --class  dump class file"
    print " -t, --header dump header file"
    sys.exit(1)

def stations(region):
    url = stations_json_url(region)
    fp = urllib2.urlopen(url)
    data = fp.read()
    return json.loads(data)

def station(id):
    url = station_json_url(id)
    fp = urllib2.urlopen(url)
    data = fp.read()
    return json.loads(data)

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
    stations = """
static const struct {
        int number;
        int arrondissementNumber;
        const char *name;
        const char *address;
        double x;
        double y;
} stations[] = {\n"""

    lat_min  = 999.0
    lat_max  = -999.0
    lng_min = 999.0
    lng_max = -999.0

    center = (45.767299, 4.8343287) # FIXME
    limits = {'max_lat' : center[0] + 0.2,
              'min_lat' : center[0] - 0.2,
              'max_lng' : center[1] + 0.2,
              'min_lng' : center[1] - 0.2}
    reg = {}

    for j in total['markers']:
        lat = float(j['x'])
        lng = float(j['y'])
        skip = False

	if lat > limits['max_lat'] or lat < limits['min_lat'] or \
                lng > limits['max_lng'] or lng < limits['min_lng']:
            skip = True
        if skip:
            stations += "//"
        stations += '\t{ %s, %s, "%s", "%s", %s, %s },\n' % (j['numStation'], j['codePostal'], j['nomStation'], j['infoStation'], j['x'], j['y'])

        if not skip:
            reg[j['codePostal']] = True
            if lat_min > float(lat) : lat_min = float(lat)
            if lat_max < float(lat) : lat_max = float(lat)
            if lng_min > float(lng) : lng_min = float(lng)
            if lng_max < float(lng) : lng_max = float(lng)

    stations += "\t{0, 0, NULL, NULL, 0., 0.}\n"
    stations += "};\n"

    lat_border = (lat_max - lat_min) / 50
    lng_border = (lng_max - lng_min) / 50

    rect = "QRectF(QPointF(%.12f, %.12f), " % (lat_min - lat_border, lng_min - lng_border)
    rect += "QPointF(%.12f, %.12f))" % (lat_max + lat_border, lng_max + lng_border)
    center = "QPointF(%.12f, %.12f)" % ((lat_min + lat_max) / 2, (lng_min + lng_max) / 2)

    regions = ""
    for region in reg.keys():
        regions += '    ret << "%s";\n' % region

    data = open('carto_p.tpl').read()
    data = data.replace('<stations>', stations)
    data = data.replace('<rect>', rect)
    data = data.replace('<center>', center);
    data = data.replace('<CITY>', "LYON");
    data = data.replace('<City>', "Lyon");
    data = data.replace('<statusUrl>', '')
    data = data.replace('<cartoUrl>', '')
    data = data.replace('<regions>', regions)
    print >>output, data.encode('utf8')

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
    for i in regions:
        if verbose:
            print >>sys.stderr, stations_json_url(i)
        data = stations(i)
        if 'markers' not in data or not data['markers']:
            continue
        for j in data['markers']:
            if full:
                id = int(j['numStation'])
                if verbose:
                    print >>sys.stderr, station_status_url(id)
                try:
                    j['status'] = status(id)
                except Exception, err:
                    print err
            j['codePostal'] = i
            total['markers'].append(j)
    if cpp:
        dump_cpp(total, output)
    else:
        dump_json(total, output)

if __name__ == "__main__":
    main()

