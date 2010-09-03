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

#include <QtCore/QUrl>

#include "stationsplugin.h"

StationsPlugin::StationsPlugin(QObject *parent)
  : QObject(parent)
{
}

StationsPlugin::~StationsPlugin()
{
}

void
StationsPlugin::clearCache()
{
  updated.clear();
}

void
StationsPlugin::updateCached(Station *station)
{
  QTime time = QTime::currentTime().addMSecs(-30000);
  QTime now = QTime::currentTime();
  QList <Station * > stations;

  stations << station;

  if (updated[station] > time)
    emit stationsUpdated(stations);
  else {
    update(station);
    updated[station] = now;
  }
}

void
StationsPlugin::updateCached(const QList < Station * > & stations)
{
  QTime time = QTime::currentTime().addMSecs(-30000);
  QTime now = QTime::currentTime();

  QList < Station * > done;
  QList < Station * > todo;

  foreach (Station *station, stations) {
    if (updated[station] > time)
      done << station;
    else {
      todo << station;
      updated[station] = now;
    }
  }

  emit stationsUpdated(done);
  update(todo);
}

