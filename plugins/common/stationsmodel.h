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

#ifndef STATIONSMODEL_H
# define STATIONSMODEL_H

#include <QtCore/QAbstractListModel>

class StationsPlugin;
class Station;

class StationsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum {
      StationRole = Qt::UserRole,
      StationIdRole,
      StationNameRole,
      StationBikesRole,
      StationSlotsRole,
      StationBookmarkRole,
    } Roles;

    StationsModel(StationsPlugin *plugin, QObject *parent = 0);
    ~StationsModel();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

    void clear();
    void updateStatus(const QModelIndex & index);
    StationsPlugin *plugin();

public slots:
    void stationsCreated(const QList < Station * > & station);
    void stationsUpdated(const QList < Station * > & station);

private:
    QList < Station * > stations;
    QMap < int , bool > bookmarks;

    StationsPlugin *plugin_;
};

#endif
