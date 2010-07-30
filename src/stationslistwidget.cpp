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

#include <QtGui/QHeaderView>
#include <QtGui/QContextMenuEvent>
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QDesktopServices>
#include <QDebug>

#include "stationslistwidget.h"
#include "stationdialog.h"
#include "stationwidget.h"
#include "station.h"
#include "stations.h"
#include "settings.h"

StationsListWidget::StationsListWidget(QWidget *parent)
  : QListWidget(parent)
{
  stations = NULL;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));

  bookmarkAction = new QAction(QIcon::fromTheme("bookmarks", QPixmap(":/res/favorites.png")),
			       tr("Bookmark this station"), this);
  mapAction = new QAction(QPixmap(":/res/maps.png"), tr("Show in on a map..."), this);

  bookmarkAction->setCheckable(true);

  menu = new QMenu(this);
  menu->addAction(bookmarkAction);
  menu->addSeparator();
  menu->addAction(mapAction);

  connect(menu, SIGNAL(triggered(QAction *)), this, SLOT(action(QAction *)));
#ifdef Q_WS_MAEMO_5
  connect(this, SIGNAL(itemClicked(QListWidgetItem *)),
	  this, SLOT(openStationDialog(QListWidgetItem *)));
#else
  connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem *)),
	  this, SLOT(openStationDialog(QListWidgetItem *)));
#endif

  loadBookmarks();
}

StationsListWidget::~StationsListWidget()
{
}

void
StationsListWidget::clear()
{
  QListWidget::clear();
  items.clear();
  itemsById.clear();
}

void
StationsListWidget::clearNear()
{
  nearest.clear();
  filter();
}

void
StationsListWidget::loadBookmarks()
{
  Settings conf;

  bookmarks.clear();
  conf.beginGroup("Bookmarks");
  foreach (QString id, conf.childKeys())
    bookmarks[id.toInt()] = true;
}

void
StationsListWidget::setRegion(const QString & code)
{
  region = code;

  filter(word);
}

void
StationsListWidget::showBookmarks(bool show)
{
  bookmarksEnabled = show;
  filter();
}

void
StationsListWidget::setStations(Stations *sta)
{
  if (stations == sta)
    return ;

  if (stations) {
    disconnect(stations, 0, this, 0);
    clear();
  }

  stations = sta;

  if (!stations)
    return ;

  connect(stations, SIGNAL(stationUpdated(Station *, bool)),
	  this, SLOT(stationUpdated(Station *, bool)));
  connect(stations, SIGNAL(stationsUpdated(QList < Station *>, bool)),
	  this, SLOT(stationsUpdated(QList < Station *>, bool)));
  connect(stations, SIGNAL(statusUpdated(Station *)),
	  this, SLOT(statusUpdated(Station *)));
  connect(stations, SIGNAL(done()), this, SLOT(update()));
}

void
StationsListWidget::filter(const QString & term)
{
  if (!term.isEmpty())
    word = QString("*%1*").arg(term);
  else
    word = term;

  filter();

  bigUpdate = false;
  timer->start(2000);
}

void
StationsListWidget::update()
{
  if (!stations)
    return ;

  for (int i = 0; i < count(); ++i) {
    if (!item(i)->isHidden()) {
      Station *station = (Station *)item(i)->data(Qt::UserRole).value<void *>();

      if (station->freeSlots() == -1 || bigUpdate)
	stations->update(station);
    }
  }

  bigUpdate = true;
  timer->start(30000);
}

void
StationsListWidget::filter()
{
  QList<QListWidgetItem *> items;
  bool checkRegion = (!region.isEmpty() && region != tr("All"));

  if (word.isEmpty() && checkRegion)
    items = findItems("*", Qt::MatchWildcard|Qt::MatchRecursive);
  else
    items = findItems(word, Qt::MatchWildcard|Qt::MatchRecursive);

  for (int i = 0; i < count(); ++i)
    item(i)->setHidden(true);

  if (bookmarksEnabled) {
    foreach (int i, bookmarks.keys()) {
      if (bookmarks[i] && itemsById[i])
	itemsById[i]->setHidden(false);
    }
  }

  foreach (int i, nearest.keys()) {
    if (nearest[i] && itemsById[i])
      itemsById[i]->setHidden(false);
  }

  foreach (QListWidgetItem *item, items) {
    if (checkRegion) {
      Station *station = (Station *)item->data(Qt::UserRole).value<void *>();

      if (!station || station->region() != region)
	continue ;
    }

    item->setHidden(false);
  }
}

void
StationsListWidget::addStation(Station *station, bool near)
{
  QListWidgetItem *item;
  int idx;

  if (!items[station]) {
    items[station] = new QListWidgetItem(this);
    itemsById[station->id()] = items[station];
  }
  item = items[station];
  idx = station->name().indexOf(" - ") + 3;

  item->setText(station->name().mid(idx)); // for findItems
  setItemWidget(item, new StationWidget(station));

  item->setData(Qt::UserRole, QVariant::fromValue((void *)station));
  item->setTextAlignment(Qt::AlignTop|Qt::AlignLeft);
  item->setSizeHint(itemWidget(item)->sizeHint());
  item->setHidden(true);

#ifndef Q_WS_MAEMO_5
  QFont font;
  font.setPointSize(12);
  item->setFont(font);
#endif

  if (near)
    nearest[station->id()] = true;
}

void
StationsListWidget::stationsUpdated(QList < Station * > list, bool near)
{
  foreach (Station *station, list)
    addStation(station, near);
  filter();
  update();
}

void
StationsListWidget::stationUpdated(Station *station, bool near)
{
  addStation(station, near);
  filter();
}

void
StationsListWidget::statusUpdated(Station *station)
{
  QListWidgetItem *item = items[station];
  StationWidget *widget;

  if (!item)
    return ;
  widget = dynamic_cast<StationWidget *>(itemWidget(item));
  if (widget)
    widget->update();

  filter();
}

void
StationsListWidget::openStationDialog(QListWidgetItem *item)
{
  Station *station = (Station *)item->data(Qt::UserRole).value<void *>();

  if (!station)
    return ;

  StationDialog dialog(stations, station, this);

  dialog.exec();

  // Reload bookmarks
  loadBookmarks();
  filter();
}

void
StationsListWidget::action(QAction *action)
{
  foreach (QListWidgetItem *item,  selectedItems()) {
    Station *station = (Station *)item->data(Qt::UserRole).value<void *>();

    if (!station)
      continue;

    if (action == mapAction) {

    }
    if (action == bookmarkAction) {
      Settings conf;
      bool bookmark;
      QString key("%1");

      key = key.arg(station->id());

      conf.beginGroup("Bookmarks");
      bookmark = conf.value(key).toBool();

      if (!bookmark)
	conf.setValue(key, true);
      else
	conf.remove(key);
      bookmarks[station->id()] = !bookmark;
    }
  }
}

void
StationsListWidget::contextMenuEvent(QContextMenuEvent * event)
{
  QListWidgetItem *item = itemAt(event->pos());
  Station *station;
  Settings conf;
  bool bookmark;

  if (!item)
    return ;

  station = (Station *)item->data(Qt::UserRole).value<void *>();

  if (!station)
    return ;

  conf.beginGroup("Bookmarks");
  bookmark = conf.value(QString("%1").arg(station->id())).toBool();
  bookmarkAction->setChecked(bookmark ? Qt::Checked : Qt::Unchecked);
  menu->exec(event->globalPos());
}
