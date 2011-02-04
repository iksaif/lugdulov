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

#ifndef STATIONSLISTWIDGET_H
# define STATIONSLISTWIDGET_H

#include <QtCore/QTimer>
#include <QtGui/QWidget>
#include <QtCore/QModelIndex>

#include "mobility.h"

class StationsModel;
class StationsPlugin;
class StationsSortFilterProxyModel;
class StationsListDialog;
class StationsView;
class Station;
class Ui_StationsListWidget;

class StationsListWidget : public QWidget
{
  Q_OBJECT

 public:
  StationsListWidget(QWidget *parent = 0);
  ~StationsListWidget();

 public slots:
  void setPlugin(StationsPlugin *plugin);
  void positionUpdated(const QPointF & pos);
#ifdef HAVE_QT_LOCATION
  void positionUpdated(QGeoPositionInfo info);
  void positionRequestTimeout();
#endif

 signals:
  void stationSelected(Station *station);

 private:
  void setupListWidget();

 private slots:
  void stationClicked(const QModelIndex & index);
  void onlyBookmarks(bool enabled);
  void filterEdited(const QString & text);
  void filter(void);

 private:
  StationsPlugin *plugin;
  StationsModel *model;
  StationsSortFilterProxyModel *proxy;
  StationsView *view;
#ifdef HAVE_QT_LOCATION
  QGeoPositionInfo position;
#endif
  QTimer filterTimer;
  Ui_StationsListWidget *ui;
  bool clicked;
  Station *currentStation;

  friend class StationsListDialog;
};

#endif
