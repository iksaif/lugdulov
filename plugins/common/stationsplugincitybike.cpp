/*
 * Copyright (C) 2010 Corentin Chary <corentin.chary@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <QtNetwork/QNetworkReply>
#include <QtGui/QDesktopServices>
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QtCore/QFile>
#include <QtCore/QtPlugin>
#include <QtCore/QStringList>
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include "station.h"
#include "stationsplugincitybike.h"

StationsPluginCityBike::StationsPluginCityBike(QObject *parent)
  : StationsPluginSingle(parent)
{
}

StationsPluginCityBike::~StationsPluginCityBike()
{
}

void
StationsPluginCityBike::handleInfos(const QByteArray & data)
{
  /*
        url = 'http://' + service['server'] + "/localizaciones/localizaciones.php"
        fp = urllib2.urlopen(url)
        data_html = fp.read()

        match = re.search(r'(<kml .*kml>)', data_html, re.MULTILINE|re.DOTALL)
        data_kml = match.group(0)

        # the html page is coded in iso8859-1 and the kml is declared as utf-8
        # dirty hack there is sometimes 0x92 char as single quote
        #data_kml_mod = data_kml.replace(chr(146), "'")
        data = data_kml.decode('iso-8859-1')
        data = data.encode('utf-8')

        dom = xml.dom.minidom.parseString(data)

        placemarkers = dom.getElementsByTagName("Placemark")
        stations = []
        n = 1

        for placemarker in placemarkers:
            station = Station()

            desc =  placemarker.childNodes[0].firstChild.toxml()#data

            #<div style="margin:10px">
            #    <div style="font:bold 11px verdana;color:#379FC5;margin-bottom:10px">Place St Fiacre - Angle rue Vauban, </div>
            #    <div style="text-align:right;float:left;font:bold 11px verdana">V�los<br />Parcs de stationnement</div>
            #    <div style="margin-left:5px;float:left;font:bold 11px verdana;color:green">10<br />5<br /></div>
            #</div>

            desc = desc.replace('<![CDATA[', '').replace(']]>', '')
            desc = desc.encode('utf8')
            dom_desc = xml.dom.minidom.parseString(desc)

            #print dom_desc.childNodes[0].nodeValue
            #print dom_desc.childNodes[0].toxml()
            #print dom_desc.childNodes[0].childNodes[0].nodeValue
            #print dom_desc.childNodes[0].childNodes[0].toxml()
            #print dom_desc.childNodes[0].childNodes[0].childNodes[0].nodeValue
            #print dom_desc.childNodes[0].childNodes[0].childNodes[0].toxml()

            name = dom_desc.childNodes[0].childNodes[0].childNodes[0].nodeValue.split(' - ')
            if (len(name) < 2):
                name = name[0]
                name = name.split(',')
            if (len(name) < 2):
                name = name[0]
                name = name.split(', ')
            if (len(name) < 2):
                name = [name[0], name[0]]

            station.name = name[0]
            station.description = name[1]
            station.name = station.name.replace("\\", "")
            station.description = station.description.replace("\\", "")

            station.uid = str(n)
            station.id = station.uid
            n += 1

            #print dom_desc.childNodes[0].childNodes[2].childNodes[2].nodeValue
            #print dom_desc.childNodes[0].childNodes[2].childNodes[2].toxml()

            station.slots = int(dom_desc.childNodes[0].childNodes[2].childNodes[2].toxml())
            station.bikes = int(dom_desc.childNodes[0].childNodes[2].childNodes[0].nodeValue)

            coord = placemarker.childNodes[2].childNodes[0].childNodes[0].toxml()
            station.lng = float(re.sub('[^0-9.-]','' , coord.split(',')[0]))
            station.lat = float(re.sub('[^0-9.-]','' , coord.split(',')[1]))
            station.zone = "0"
*/
}
