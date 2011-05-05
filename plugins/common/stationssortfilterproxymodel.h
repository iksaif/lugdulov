/*
 * Copyright (C) 2010-2011 Corentin Chary <corentin.chary@gmail.com>
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

#ifndef STATIONSSORTFILTERPROXYMODEL_H
# define STATIONSSORTFILTERPROXYMODEL_H

#include <QtGui/QSortFilterProxyModel>
#include <QtCore/QPointF>

class Station;
class StationsPlugin;

class StationsSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    enum {
      StationDistanceRole,
    } Roles;

    StationsSortFilterProxyModel(QObject *parent = 0);
    ~StationsSortFilterProxyModel();

    QVariant data(const QModelIndex & index, int role) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    int stationLimit() const;
    double stationRadiusFilter() const;
    QPointF stationPositionFilter() const;
    bool bookmarksEnabled() const;

public slots:
    void setStationLimit(int limit);
    void onlyBookmarks(bool enabled);
    void setPosition(const QPointF &pos);
    void setPositionFilter(const QPointF &pos, double radius = -1);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;

private:
    qreal distance(Station *station) const;

private:
    int stationLimit_;
    double stationRadiusFilter_;
    QPointF position_;
    bool bookmarksEnabled_;

    static QMap < Station * , qreal > distancesCache;
};

#endif
