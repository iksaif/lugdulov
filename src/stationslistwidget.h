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

#ifndef MAINLISTWIDGET_H
# define MAINLISTWIDGET_H

#include <QtGui/QListWidget>
#include <QtCore/QTimer>

class Station;
class Stations;

class StationsListWidget : public QListWidget
{
  Q_OBJECT
public:
  StationsListWidget(QWidget *parent = 0);
  ~StationsListWidget();

  void clear();
  void clearNear();
  void setStations(Stations *stations);

protected:
  virtual void contextMenuEvent(QContextMenuEvent * event);

public slots:
  void showBookmarks(bool show);

  void filter(const QString & filter);
  void setRegion(const QString & region);

  void stationsUpdated(QList < Station * > station, bool near);
  void stationUpdated(Station *station, bool near);
  void statusUpdated(Station *station);

private slots:
  void filter();
  void update();
  void action(QAction *action);
  void openStationDialog(QListWidgetItem *item);

private:
  void addStation(Station *station, bool near);
  void loadBookmarks();

private:
  QString word;
  QString region;

  QTimer *timer;
  bool bigUpdate;

  Stations *stations;

  QMap < Station * , QListWidgetItem * > items;
  QMap < int , QListWidgetItem * > itemsById;
  QMap < int , bool > bookmarks;
  QMap < int , bool > nearest;

  bool bookmarksEnabled;
  QMenu *menu;
  QAction *bookmarkAction;
  QAction *mapAction;
  QAction *infoAction;
};

#endif /* MAINLISTWIDGET_H */
