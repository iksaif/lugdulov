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

#include <QtCore/QTimer>
#include <QtGui/QMenu>

#include "stationslistview.h"
#include "stationsmodel.h"
#include "station.h"
#include "stationsplugin.h"

StationsListView::StationsListView(QWidget *parent)
  : QListView(parent)
{
  createContextMenu();

  timer = new QTimer(this);
  timer->setInterval(30000);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}


StationsListView::~StationsListView()
{
}

void
StationsListView::createContextMenu()
{
  menu = new QMenu(this);
}

void
StationsListView::enableAutoUpdate(bool enabled)
{
  if (!enabled)
    timer->stop();
  else if(!timer->isActive())
    timer->start();
}

bool
StationsListView::autoUpdateEnabled()
{
  return timer->isActive();
}

void
StationsListView::setUpdateInterval(int sec)
{
  timer->setInterval(sec * 1000);
}

int
StationsListView::updateInterval()
{
  return timer->interval() / 1000;
}

void
StationsListView::forceUpdate()
{
  updated.clear();
  update();
}

void
StationsListView::update()
{
  QRect rect(0, 0, 0, 0);
  QModelIndex index;
  QModelIndexList list;
  QTime time = QTime::currentTime().addMSecs(-timer->interval());

  while (viewport()->rect().contains(0, rect.y() + rect.height() + 1)){
    index = indexAt(QPoint(rect.x(), rect.y() + rect.height() + 1));

    if (!index.isValid())
      break ;

    rect = visualRect(index);
    list << index;
  }
  foreach (QModelIndex index, list) {
    Station *station = (Station *)index.data(StationsModel::StationRole).value<void *>();

    if (!station || updated[station] > time)
      continue ;

    station->plugin()->update(station);
    updated[station] = QTime::currentTime();
  }
}

void
StationsListView::showContexMenu(const QPoint & pos)
{
  menu->exec(pos);
}

void
StationsListView::rowsInserted(const QModelIndex & parent, int start, int end)
{
  QListView::rowsInserted(parent, start, end);
  // Delayed to allow QSortFilterProxyModel to do is work
  QTimer::singleShot(500, this, SLOT(update()));
}

void
StationsListView::scrollContentsBy(int dx, int dy)
{
  QListView::scrollContentsBy(dx, dy);
  // Delayed a little because the user may be still scrolling
  QTimer::singleShot(500, this, SLOT(update()));
}
