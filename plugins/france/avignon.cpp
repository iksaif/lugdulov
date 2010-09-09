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

#include "tools.h"
#include "station.h"
#include "avignon.h"
#include "avignon_p.h"

StationsPluginAvignon::StationsPluginAvignon(QObject *parent)
  : StationsPluginSingle(parent)
{
  d = new StationsPluginSimplePrivateAvignon();
}

StationsPluginAvignon::~StationsPluginAvignon()
{
  delete d;
}

QString
StationsPluginAvignon::id() const
{
  return QLatin1String("avignon");
}

QString
StationsPluginAvignon::name() const
{
  return QString::fromUtf8("Avignon");
}

QString
StationsPluginAvignon::bikeName() const
{
  return QString::fromUtf8("Velocea");
}

QIcon
StationsPluginAvignon::bikeIcon() const
{
  return QIcon(":/res/bike.png");
}

void
StationsPluginAvignon::handleInfos(const QByteArray & data)
{
  QRegExp re("map\\.addOverlay\\(newmark_0[1|3]\\((\\d+), ([0-9\\.]+),([0-9\\.]+), "
	     "\"<div .*>(.*)<br>.*disponibles: (\\d+)<br>Emplacements libres: (\\d+)<br>");
  int ofs = 0;

  re.setMinimal(true);

  while ((ofs = re.indexIn(data, ofs)) >= 0) {
    int id;
    QPointF pos;
    Station *station;
    QStringList capt = re.capturedTexts();

    if (capt.size() != 7)
      continue ;

    id = capt.at(1).toInt();
    pos = QPointF(capt.at(2).toDouble(),
		  capt.at(3).toDouble());

    if (!d->rect.contains(pos))
      continue ;

    if (stations.find(id) == stations.end())
      stations[id] = new Station(this);
    station = stations[id];

    if (station->name().isEmpty())
      station->setName(capt.at(4));

    station->setBikes(capt.at(5).toInt());
    station->setFreeSlots(capt.at(6).toInt());
    station->setTotalSlots(station->bikes() + station->freeSlots());

    ofs++;
  }

  emit stationsCreated(stations.values());
  emit stationsUpdated(stations.values());
}
