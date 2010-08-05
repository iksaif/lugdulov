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

#ifndef STATIONSLISTVIEW_H
#define STATIONSLISTVIEW_H

#include <QtGui/QListView>
#include <QtCore/QTime>

class Station;

class StationsListView : public QListView
{
  Q_OBJECT
 public:
  StationsListView(QWidget *parent);
  ~StationsListView();

  void enableAutoUpdate(bool enabled);
  bool autoUpdateEnabled();
  void setUpdateInterval(int sec);
  int updateInterval();

 protected:
  virtual void scrollContentsBy(int dx, int dy);
  virtual void rowsInserted(const QModelIndex & parent, int start, int end);

 private slots:
  void update();
  void showContexMenu(const QPoint & pos);

 private:
  void createContextMenu();

 private:
  QTimer *timer;
  QMenu *menu;
  QMap < Station * , QTime > updated;
};


#endif