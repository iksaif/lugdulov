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

#include <QtCore/QDebug>

#include "lugdulov.h"
#include "pluginsdialog.h"
#include "stationsplugin.h"
#include "stationspluginfactory.h"
#include "stationspluginmanager.h"

PluginsDialog::PluginsDialog(StationsPluginManager *manager, QWidget *parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window)
#else
  QDialog(parent)
#endif
{
  selected = NULL;

  setupUi(this);
  setupDialog(this, false);

#ifdef Q_WS_MAEMO_5
  buttonBox->hide();
#elif !defined(Q_OS_SYMBIAN) && !defined(Q_WS_SIMULATOR)
  treeWidget->setIconSize(QSize(24, 24));
#endif

  QMap < StationsPluginFactory *, StationsPlugin * > ret = manager->stations();

  foreach (StationsPluginFactory *factory, ret.uniqueKeys()) {
    QTreeWidgetItem *parent = new QTreeWidgetItem(treeWidget, Factory);
    QFont font = parent->font(0);

    font.setBold(true);
    parent->setText(0, factory->name());
    parent->setIcon(0, factory->icon());
    parent->setFont(0, font);
    parent->setText(1, factory->description());
    parent->setFont(1, font);
    parent->setFlags(Qt::ItemIsEnabled);
    parent->setExpanded(true);

    foreach (StationsPlugin *plugin, ret.values(factory)) {
      QTreeWidgetItem *item = new QTreeWidgetItem(parent, Plugin);

      plugin->setParent(this);
      item->setText(0, plugin->name());
      item->setText(1, plugin->bikeName());
      item->setIcon(1, plugin->bikeIcon());
      item->setData(0, Qt::UserRole, QVariant::fromValue((void *)plugin));
    }
  }
  treeWidget->header()->setResizeMode(0, QHeaderView::Stretch);

  connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)),
	  this, SLOT(itemClicked(QTreeWidgetItem *, int)));
  connect(treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)),
	  this, SLOT(itemDoubleClicked(QTreeWidgetItem *, int)));

  lineEdit->setFocus(Qt::OtherFocusReason);
  connect(lineEdit, SIGNAL(textEdited(const QString &)), this, SLOT(filter(const QString &)));

  installKineticScroller(treeWidget);
}

PluginsDialog::~PluginsDialog()
{
}

void
PluginsDialog::hideItems(QTreeWidgetItem *item, bool hide)
{
  if (!item)
    return ;

  item->setHidden(hide);

  for (int i = 0; i < item->childCount(); ++i)
    hideItems(item->child(i), hide);
}

void
PluginsDialog::showItems(QTreeWidgetItem *item)
{
  if (!item)
    return ;

  item->setHidden(false);
  showItems(item->parent());
}

void
PluginsDialog::filter(const QString &txt)
{
  QList<QTreeWidgetItem *> match;

  if (txt.isEmpty()) {
    hideItems(treeWidget->invisibleRootItem(), false);
    return ;
  }

  match << treeWidget->findItems(txt, Qt::MatchContains | Qt::MatchRecursive, 0);
  match << treeWidget->findItems(txt, Qt::MatchContains | Qt::MatchRecursive, 1);

  hideItems(treeWidget->invisibleRootItem(), true);

  foreach (QTreeWidgetItem *item, match)
    showItems(item);
}

void
PluginsDialog::itemClicked(QTreeWidgetItem *item, int column)
{
  if (item->type() == Plugin) {
    selected = (StationsPlugin *)item->data(0, Qt::UserRole).value<void *>();
#ifdef Q_WS_MAEMO_5
    accept();
#endif
  }
}

void
PluginsDialog::itemDoubleClicked(QTreeWidgetItem *item, int column)
{
  if (item->type() == Plugin) {
    selected = (StationsPlugin *)item->data(0, Qt::UserRole).value<void *>();
    accept();
  }
}

StationsPlugin *
PluginsDialog::plugin()
{
  return selected;
}

