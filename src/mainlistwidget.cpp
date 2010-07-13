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

#include "mainlistwidget.h"
#include "stationdialog.h"
#include "stationwidget.h"
#include "station.h"
#include "stations.h"
#include "settings.h"

MainListWidget::MainListWidget(QWidget *parent)
  : QListWidget(parent)
{
  stations = NULL;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));

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
  connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem *)),
	  this, SLOT(openStationDialog(QListWidgetItem *)));

  loadBookmarks();
}

MainListWidget::~MainListWidget()
{
}

void
MainListWidget::clear()
{
  QListWidget::clear();
  items.clear();
  itemsById.clear();
}

void
MainListWidget::clearNear()
{
  nearest.clear();
  filter();
}

void
MainListWidget::loadBookmarks()
{
  Settings conf;

  bookmarks.clear();
  conf.beginGroup("Bookmarks");
  foreach (QString id, conf.childKeys())
    bookmarks[id.toInt()] = true;
}

void
MainListWidget::setRegion(const QString & code)
{
  region = code;

  filter(word);
}

void
MainListWidget::filter(const QString & term)
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
MainListWidget::update()
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
MainListWidget::filter()
{
  QList<QListWidgetItem *> items;
  bool checkRegion = (!region.isEmpty() && region != tr("All"));

  if (word.isEmpty() && checkRegion)
    items = findItems("*", Qt::MatchWildcard|Qt::MatchRecursive);
  else
    items = findItems(word, Qt::MatchWildcard|Qt::MatchRecursive);

  for (int i = 0; i < count(); ++i)
    item(i)->setHidden(true);

  foreach (int i, bookmarks.keys()) {
    if (bookmarks[i] && itemsById[i])
      itemsById[i]->setHidden(false);
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
MainListWidget::addStation(Station *station, bool near)
{
  QListWidgetItem *item;
  int idx;

  if (!stations)
    stations = dynamic_cast<Stations *>(sender());

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
MainListWidget::stationsUpdated(QList < Station * > list, bool near)
{
  foreach (Station *station, list)
    addStation(station, near);
  filter();
  update();
}

void
MainListWidget::stationUpdated(Station *station, bool near)
{
  addStation(station, near);
  filter();
}

void
MainListWidget::statusUpdated(Station *station)
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
MainListWidget::openStationDialog(QListWidgetItem *item)
{
  Station *station = (Station *)item->data(Qt::UserRole).value<void *>();

  if (!station)
    return ;

  StationDialog dialog(station, this);

  dialog.exec();

  // Reload bookmarks
  loadBookmarks();
  filter();
}

void
MainListWidget::action(QAction *action)
{
  foreach (QListWidgetItem *item,  selectedItems()) {
    Station *station = (Station *)item->data(Qt::UserRole).value<void *>();

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

      if (!bookmark)
	conf.setValue(key, true);
      else
	conf.remove(key);
      bookmarks[station->id()] = !bookmark;
    }
  }
}

void
MainListWidget::contextMenuEvent(QContextMenuEvent * event)
{
  QListWidgetItem *item = itemAt(event->pos());
  Station *station = (Station *)item->data(Qt::UserRole).value<void *>();
  Settings conf;
  bool bookmark;

  if (!station)
    return ;

  conf.beginGroup("Bookmarks");
  bookmark = conf.value(QString("%1").arg(station->id())).toBool();
  bookmarkAction->setChecked(bookmark ? Qt::Checked : Qt::Unchecked);
  menu->exec(event->globalPos());
}
