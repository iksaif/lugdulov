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

#ifndef MAINTREEWIDGET_H
# define MAINTREEWIDGET_H

#include <QtGui/QTreeWidget>
#include <QtCore/QTimer>

class Station;
class Stations;

class MainTreeWidget : public QTreeWidget
{
  Q_OBJECT
public:
  MainTreeWidget(QWidget *parent = 0);
  ~MainTreeWidget();

protected:
  virtual void contextMenuEvent(QContextMenuEvent * event);

public slots:
  void filter(const QString & filter);
  void setRegion(const QString & region);

  void stationsUpdated(QList < Station * > station);
  void stationUpdated(Station *station);
  void statusUpdated(Station *station);

private slots:
  void filter();
  void update();
  void action(QAction *action);

private:
  QString word;
  QString region;
  QTimer *timer;
  Stations *stations;
  bool bigUpdate;
  QMap < Station * , QTreeWidgetItem * > items;
  QMenu *menu;
  QAction *bookmarkAction;
  QAction *gmapAction;
  QAction *velovAction;
};

#endif /* MAINTREEWIDGET_H */
