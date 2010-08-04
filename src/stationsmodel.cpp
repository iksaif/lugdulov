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

#include "stationsmodel.h"
#include "stationsplugin.h"
#include "station.h"

StationsModel::StationsModel(StationsPlugin *plugin, QObject *parent)
  : QAbstractListModel(parent), plugin_(plugin)
{
  connect(plugin_, SIGNAL(stationsCreated(QList < Station *>)),
	  this, SLOT(stationsCreated(QList < Station *>)));
  connect(plugin_, SIGNAL(stationsUpdated(QList < Station *>)),
	  this, SLOT(stationsUpdated(QList < Station *>)));
}

StationsModel::~StationsModel()
{
}

int
StationsModel::rowCount(const QModelIndex & parent) const
{
  Q_ASSERT(!parent.isValid());
  return stations.size();
}

QVariant
StationsModel::data(const QModelIndex & index, int role) const
{
  Station *station;

  if (!index.isValid())
    return QVariant();

  Q_ASSERT(index.column() == 0);

  station = stations.at(index.row());

  if (!station)
    return QVariant();

  if (role == Qt::DisplayRole)
    return station->name();
  else if (role == StationRole)
    return QVariant::fromValue((void *)station);
  else if (role == StationIdRole)
    return station->id();
  else if (role == StationNameRole)
    return station->name();
  else if (role == StationSlotsRole)
    return station->freeSlots();
  else if (role == StationBikesRole)
    return station->bikes();

  return QVariant();
}

void
StationsModel::clear()
{
  stations.clear();
}

void
StationsModel::stationsCreated(QList < Station * > list)
{
  QList < Station * > copy;

  foreach (Station *station, list)
    if (!stations.contains(station))
	copy.append(station);

  beginInsertRows(QModelIndex(), stations.size(), stations.size() + copy.size());
  stations.append(copy);
  endInsertRows();
}

void
StationsModel::stationsUpdated(QList < Station * > list)
{
  foreach (Station *station, list) {
    QModelIndex idx = index(stations.indexOf(station));

    emit dataChanged(idx, idx);
  }
  //emit layoutChanged() ?
}

void
StationsModel::updateStatus(const QModelIndex & index)
{
  if (!index.isValid() || index.column() != 0)
    return;

  plugin_->update((Station *)index.data(StationsModel::StationRole).value<void *>());
}

StationsPlugin *
StationsModel::plugin()
{
  return plugin_;
}
