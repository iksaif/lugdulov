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

#include <QtCore/QTimer>
#include <QtGui/QMenu>
#include <QtGui/QSortFilterProxyModel>

#include "lugdulov.h"

#include "stationslistview.h"
#include "stationsmodel.h"
#include "station.h"
#include "stationsplugin.h"
#include "settings.h"
#include "stationdialog.h"
#include "mapdialog.h"

StationsListView::StationsListView(QWidget *parent)
  : QListView(parent)
{
  plugin = NULL;

  createContextMenu();

  timer = new QTimer(this);
  timer->setInterval(30000);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));

  scrollTimer = new QTimer(this);
  scrollTimer->setInterval(500);
  scrollTimer->setSingleShot(true);
  connect(scrollTimer, SIGNAL(timeout()), this, SLOT(update()));

#if defined(Q_WS_MAEMO_5) || defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  connect(this, SIGNAL(clicked(const QModelIndex &)), this, SLOT(showDetails(const QModelIndex &)));
#else
  connect(this, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(showDetails(const QModelIndex &)));
#endif
  setContextMenuPolicy(Qt::CustomContextMenu);
  connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));

  installKineticScroller(this);
}


StationsListView::~StationsListView()
{
}

StationsPlugin *
StationsListView::stationsPlugin()
{
  return plugin;
}

void
StationsListView::setStationsPlugin(StationsPlugin *p)
{
  plugin = p;
  delete menu;
  createContextMenu();
}

void
StationsListView::createContextMenu()
{

  menu = new QMenu(this);
  details  = menu->addAction(QIcon(":/res/slot.png"), tr("Details..."));
  map      = menu->addAction(QIcon(":/res/map.png"), tr("Show on a map..."));
  bookmark = menu->addAction(QIcon::fromTheme("bookmarks", QPixmap(":/res/favorites.png")),
			     tr("Bookmark this station"));

  if (plugin) {
    foreach (QAction *action, plugin->actions()) {
      action->setParent(menu);
      menu->addAction(action);
    }
  }

  connect(menu, SIGNAL(triggered(QAction *)), this, SLOT(action(QAction *)));

  bookmark->setCheckable(true);
}

void
StationsListView::showDetails(const QModelIndex & index)
{
    Station *station = (Station *)index.data(StationsModel::StationRole).value<void *>();

    if (!station)
      return ;

    StationDialog *dlg = new StationDialog(station, parentWidget());

    showAndDelete(dlg);
}

void
StationsListView::action(QAction *action)
{
  foreach (QModelIndex index, selectedIndexes()) {
    Station *station = (Station *)index.data(StationsModel::StationRole).value<void *>();

    if (action == details)
      showDetails(index);
    else if (action == map) {
       MapDialog *map = new MapDialog(station->plugin(), this);

       map->centerView(station->pos());
       showAndDelete(map);
    } else if (action == bookmark) {
      model()->setData(index, !Settings::bookmarked(station),
		       StationsModel::StationBookmarkRole);
    } else if (plugin)
	plugin->actionTriggered(action, station, this);
  }
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
  if (plugin)
    plugin->clearCache();
  update();
}

void
StationsListView::update()
{
  QRect rect(0, 0, 0, 0);
  QModelIndex index;
  QModelIndexList list;

  if (!plugin)
    return ;
  while (viewport()->rect().contains(0, rect.y() + rect.height() + 1)){
    index = indexAt(QPoint(rect.x(), rect.y() + rect.height() + 1));

    if (!index.isValid())
      break ;

    rect = visualRect(index);
    list << index;
  }
  foreach (QModelIndex index, list) {
    Station *station = (Station *)index.data(StationsModel::StationRole).value<void *>();

    if (!station)
      continue ;

    plugin->updateCached(station);
  }
}

void
StationsListView::showContextMenu(const QPoint & pos)
{
  foreach (QModelIndex index, selectedIndexes()) {
    Station *station = (Station *)index.data(StationsModel::StationRole).value<void *>();

    if (station)
      bookmark->setChecked(Settings::bookmarked(station) ? Qt::Checked : Qt::Unchecked);
  }
  menu->exec(mapToGlobal(pos));
}

void
StationsListView::rowsInserted(const QModelIndex & parent, int start, int end)
{
  QListView::rowsInserted(parent, start, end);
  // Delayed to allow QSortFilterProxyModel doing is work
  scrollTimer->start();
}

void
StationsListView::scrollContentsBy(int dx, int dy)
{
  QListView::scrollContentsBy(dx, dy);
  // Delayed a little because the user may still be scrolling
  scrollTimer->start();
}
