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
    print "velov.py [options] [-o out]"
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
    struct = """
struct {
        int codePostal;
        int numStation;
        const char *nomStation;
        const char *infoStation;
        double x;
        double y;
} stations[] = {"""
    print >>output, struct
    for j in total['markers']:
        line = '\t{ %s, %s, "%s", "%s", %s, %s },' % (j['codePostal'], j['numStation'], j['nomStation'], j['infoStation'], j['x'], j['y'])
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

