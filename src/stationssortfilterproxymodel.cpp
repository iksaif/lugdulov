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

#include "stationssortfilterproxymodel.h"
#include "station.h"
#include "stationsmodel.h"

StationsSortFilterProxyModel::StationsSortFilterProxyModel(QObject *parent)
  : QSortFilterProxyModel(parent)
{
  stationLimit_ = -1;
  stationRadiusFilter_ = -1;
  bookmarksEnabled_ = false;
}

StationsSortFilterProxyModel::~StationsSortFilterProxyModel()
{
}

int
StationsSortFilterProxyModel::rowCount(const QModelIndex & parent) const
{
  if (stationLimit_ == -1)
    return QSortFilterProxyModel::rowCount(parent);
  else
    return qMin(stationLimit_, QSortFilterProxyModel::rowCount(parent));
}

bool
StationsSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
  return QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent);
}

bool
StationsSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
  if (sortRole() == StationBookmarkRole || sortRole() == StationDistanceRole) {
    Station *l = (Station *)sourceModel()->data(left, StationsModel::StationRole).value<void *>();
    Station *r = (Station *)sourceModel()->data(right, StationsModel::StationRole).value<void *>();

    if (sortRole() == StationBookmarkRole)
      return bookmarks[l->id()] < bookmarks[r->id()];
    else if (sortRole() == StationDistanceRole)
      return distance(l) < distance(r);
    else
      return false;
  } else
    return QSortFilterProxyModel::lessThan(left, right);
}

QMap < Station * , qreal > StationsSortFilterProxyModel::distancesCache;

qreal
StationsSortFilterProxyModel::distance(Station *station) const
{
  if (distancesCache.find(station) == distancesCache.end())
    distancesCache[station] = station->distanceTo(position_);
  return distancesCache[station];
}

int
StationsSortFilterProxyModel::stationLimit() const
{
  return stationLimit_;
}

double
StationsSortFilterProxyModel::stationRadiusFilter() const
{
  return stationRadiusFilter_;
}

QPointF
StationsSortFilterProxyModel::stationPositionFilter() const
{
  return position_;
}

bool
StationsSortFilterProxyModel::bookmarksEnabled() const
{
  return bookmarksEnabled_;
}

void
StationsSortFilterProxyModel::setStationLimit(int limit)
{
  stationLimit_ = limit;
  invalidateFilter();
}

void
StationsSortFilterProxyModel::setPosition(const QPointF &pos)
{
  position_ = pos;
  distancesCache.clear();
  invalidate();
}

void
StationsSortFilterProxyModel::setPositionFilter(const QPointF &pos, double radius)
{
  position_ = pos;
  stationRadiusFilter_ = radius;
  distancesCache.clear();
  invalidate();
}

void
StationsSortFilterProxyModel::setBookmarks(QList < int > list)
{
  bookmarks.clear();
  foreach (int id, list)
    bookmarks[id] = true;
  invalidate();
}

void
StationsSortFilterProxyModel::enableBookmarks(bool enabled)
{
  bookmarksEnabled_ = enabled;
  invalidate();
}

