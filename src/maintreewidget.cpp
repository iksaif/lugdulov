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

#include "maintreewidget.h"
#include "stationdialog.h"
#include "station.h"
#include "stations.h"
#include "settings.h"

MainTreeWidget::MainTreeWidget(QWidget *parent)
  : QTreeWidget(parent)
{
  stations = NULL;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));

  header()->resizeSections(QHeaderView::ResizeToContents);
  header()->setResizeMode(0, QHeaderView::Stretch);

  bookmarkAction = new QAction(QIcon::fromTheme("bookmarks", QPixmap(":/res/favorites.png")),
			       tr("Bookmark this station"), this);
  gmapAction = new QAction(QPixmap(":/res/google-maps.png"), tr("Show in Google Maps..."), this);
  velovAction = new QAction(QPixmap(":/res/velov.png"), tr("Show in Velo'v Website..."), this);

  bookmarkAction->setCheckable(true);

  menu = new QMenu(this);
  menu->addAction(bookmarkAction);
  menu->addSeparator();
  menu->addAction(gmapAction);
  menu->addAction(velovAction);

  connect(menu, SIGNAL(triggered(QAction *)), this, SLOT(action(QAction *)));
  connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)),
	  this, SLOT(openStationDialog(QTreeWidgetItem *)));

  loadBookmarks();
}

MainTreeWidget::~MainTreeWidget()
{
}

void
MainTreeWidget::clear()
{
  QTreeWidget::clear();
  items.clear();
  itemsById.clear();
}

void
MainTreeWidget::clearNear()
{
  nearest.clear();
  filter();
}

void
MainTreeWidget::loadBookmarks()
{
  Settings conf;

  bookmarks.clear();
  conf.beginGroup("Bookmarks");
  foreach (QString id, conf.childKeys())
    bookmarks[id.toInt()] = true;
}

void
MainTreeWidget::setRegion(const QString & code)
{
  region = code;

  filter(word);
}

void
MainTreeWidget::filter(const QString & term)
{
  if (!term.isEmpty())
    word = QString("*%1*").arg(term);

  filter();

  bigUpdate = false;
  timer->start(2000);
}

void
MainTreeWidget::update()
{
  QTreeWidgetItem *root = invisibleRootItem();

  if (!stations)
    return ;

  for (int i = 0; i < root->childCount(); ++i) {
    if (!root->child(i)->isHidden()) {
      Station *station = (Station *)root->child(i)->data(0, Qt::UserRole).value<void *>();

      if (station->freeSlots() == -1 || bigUpdate)
	stations->update(station);
    }
  }

  bigUpdate = true;
  timer->start(30000);
}

void
MainTreeWidget::filter()
{
  QList<QTreeWidgetItem *> items;
  QTreeWidgetItem *root = invisibleRootItem();
  bool checkRegion = (!region.isEmpty() && region != tr("All"));

  if (!root)
    return ;

  if (word.isEmpty() && checkRegion)
    items = findItems("*", Qt::MatchWildcard|Qt::MatchRecursive, 0);
  else
    items = findItems(word, Qt::MatchWildcard|Qt::MatchRecursive, 0);

  for (int i = 0; i < root->childCount(); ++i)
    root->child(i)->setHidden(true);

  foreach (int i, bookmarks.keys())
    if ((bookmarks[i] || nearest[i]) && itemsById[i])
      itemsById[i]->setHidden(false);

  foreach (QTreeWidgetItem *item, items) {
    if (checkRegion) {
      Station *station = (Station *)item->data(0, Qt::UserRole).value<void *>();

      if (!station || station->region() != region)
	continue ;
    }

    item->setHidden(false);
  }
}

void
MainTreeWidget::stationsUpdated(QList < Station * > list, bool near)
{
  if (!stations)
    stations = dynamic_cast<Stations *>(sender());

  foreach (Station *station, list) {
    QTreeWidgetItem *item;
    int idx;

    if (!items[station]) {
      items[station] = new QTreeWidgetItem(this);
      itemsById[station->id()] = items[station];
    }
    item = items[station];
    idx = station->name().indexOf(" - ") + 3;
    item->setText(0, station->name().mid(idx));
    item->setData(0, Qt::UserRole, QVariant::fromValue((void *)station));
    item->setHidden(true);

    if (near)
      nearest[station->id()] = true;
  }

  filter();
}

void
MainTreeWidget::stationUpdated(Station *station, bool near)
{
  QTreeWidgetItem *item;
  int idx;

  if (!stations)
    stations = dynamic_cast<Stations *>(sender());

  if (!items[station]) {
    items[station] = new QTreeWidgetItem(this);
    itemsById[station->id()] = items[station];
  }
  item = items[station];
  idx = station->name().indexOf(" - ") + 3;
  item->setText(0, station->name().mid(idx));
  item->setData(0, Qt::UserRole, QVariant::fromValue((void *)station));
  item->setHidden(true);

  if (near)
    nearest[station->id()] = true;

  filter();
}

void
MainTreeWidget::statusUpdated(Station *station)
{
  QTreeWidgetItem *item = items[station];

  if (!item)
    return ;
  item->setData(1, Qt::DisplayRole, station->bikes());
  item->setData(2, Qt::DisplayRole, station->freeSlots());
  item->setData(3, Qt::DisplayRole, station->totalSlots());
  filter();
}

void
MainTreeWidget::openStationDialog(QTreeWidgetItem *item)
{
  Station *station = (Station *)item->data(0, Qt::UserRole).value<void *>();

  if (!station)
    return ;

  StationDialog dialog(station, this);

  dialog.exec();

  // Reload bookmarks
  loadBookmarks();
  filter();
}

void
MainTreeWidget::action(QAction *action)
{
  foreach (QTreeWidgetItem *item,  selectedItems()) {
    Station *station = (Station *)item->data(0, Qt::UserRole).value<void *>();

    if (!station)
      continue;

    if (action == gmapAction) {
      QLocale c(QLocale::C);
      QString str("http://maps.google.com/maps?q=");

      str += c.toString(station->pos().x());
      str += ",";
      str += c.toString(station->pos().y());

      QDesktopServices::openUrl(str);
    }
    if (action == velovAction) {
      QString str("http://www.velov.grandlyon.com/Plan-interactif.61.0.html?&gid=%1");

      str = str.arg(station->id());

      QDesktopServices::openUrl(str);
    }
    if (action == bookmarkAction) {
      Settings conf;
      bool bookmark;
      QString key("%1");

      key = key.arg(station->id());

      conf.beginGroup("Bookmarks");
      bookmark = conf.value(key).toBool();
      if (bookmark)
	conf.setValue(key, bookmark);
      else
	conf.remove(key);
      bookmarks[station->id()] = !bookmark;
    }
  }
}

void
MainTreeWidget::contextMenuEvent(QContextMenuEvent * event)
{
  QTreeWidgetItem *item = itemAt(event->pos());
  Station *station = (Station *)item->data(0, Qt::UserRole).value<void *>();
  Settings conf;
  bool bookmark;

  if (!station)
    return ;

  conf.beginGroup("Bookmarks");
  bookmark = conf.value(QString("%1").arg(station->id())).toBool();
  bookmarkAction->setChecked(bookmark ? Qt::Checked : Qt::Unchecked);
  menu->exec(event->globalPos());
}
