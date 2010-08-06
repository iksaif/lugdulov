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

#include <QtGui/QDesktopServices>
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QtCore/QtPlugin>

#include <QtCore/QDebug>

#include "station.h"
#include "skel.h"

QString
StationsPluginFactorySkel::id() const
{
  return QLatin1String("skel");
}

QString
StationsPluginFactorySkel::name() const
{
  return QLatin1String("Skeleton StationsPlugin - Author: Corentin Chary <corentin.chary@gmail.com>");
}

QIcon
StationsPluginFactorySkel::icon() const
{
  return QIcon(":/skel/bike.png");
}

QList < StationsPlugin * >
StationsPluginFactorySkel::stations(QObject *parent)
{
  QList < StationsPlugin * > ret;

  ret << new StationsPluginSkel(parent);
  return ret;
}

StationsPluginSkel::StationsPluginSkel(QObject *parent)
  : StationsPlugin(parent)
{
}

StationsPluginSkel::~StationsPluginSkel()
{
  qDeleteAll(stations);
}

QString
StationsPluginSkel::id() const
{
  return QLatin1String("skel");
}

QString
StationsPluginSkel::name() const
{
  return QLatin1String("Skel");
}

QString
StationsPluginSkel::bikeName() const
{
  return QLatin1String("Fake Bikes");
}

QIcon
StationsPluginSkel::bikeIcon() const
{
  return QIcon(":/skel/bike.png");
}

bool
StationsPluginSkel::intersect(const QPointF & pos)
{
  if (pos.x() > 45.815042 && pos.x() < 45.61764 &&
      pos.y() > 4.799995  && pos.y() < 5.090103)
    return true;
  return false;
}

void
StationsPluginSkel::fetchPos(const QPointF & pos, int num)
{
  /* Not Implemented */
}

void
StationsPluginSkel::fetchFromFile(const QString & file)
{
  /* Not Implemented */
}

void
StationsPluginSkel::fetchAll()
{
  if (!stations.count()) {
    Station *station = new Station(this);

    emit started();
    emit progress(0, 1);

    station->setId(0);
    station->setName("Foo");
    station->setDescription("Bar");
    station->setPos(QPointF(45.815042, 4.799995));

    emit progress(1, 1);
    emit done();

    stations[station->id()] = station;
  }
  emit stationsCreated(stations.values());
}

void
StationsPluginSkel::fetchFromUrl(const QUrl & url)
{
  /* Not Implemented */
}

void
StationsPluginSkel::fetchOnline()
{
  /* Not Implemented */
}

void
StationsPluginSkel::update(Station *station)
{
  emit started();
  emit progress(0, 1);
  station->setBikes(1);
  station->setFreeSlots(1);
  station->setTotalSlots(2);
  emit progress(1, 1);
  emit done();

  QList < Station * > list;

  list << station;
  emit stationsUpdated(list);
}

void
StationsPluginSkel::update(QList < Station * > stations)
{
  foreach (Station *station, stations)
    update(station);
}

QUrl
StationsPluginSkel::stationImageUrl(int id)
{
  /* Not implemented */
  return QUrl();
}

QStringList
StationsPluginSkel::regions()
{
  QStringList reg;

  reg << "Station NoWhere";
  return reg;
}

QList < QAction * >
StationsPluginSkel::actions()
{
  QList < QAction * > ret;
  QAction *action;

  action = new QAction(QIcon(":/skel/icon.png"), tr("Hello World !"), this);
  action->setToolTip(tr("Print Hello World"));
  action->setData(ActionDump);
  ret << action;
  return ret;
}

void
StationsPluginSkel::actionTriggered(QAction *action, Station *station, QWidget *parent)
{
  int data = action->data().toInt();

  if (data == ActionDump) {
    qDebug() << "Hello World !";
  }
}

Q_EXPORT_PLUGIN2(stationsskel, StationsPluginFactorySkel)
