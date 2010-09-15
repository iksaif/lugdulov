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

#include "pluginsmodel.h"
#include "stationsplugin.h"

PluginsModel::PluginsModel(StationsPluginManager *manager, QObject *parent)
  : QAbstractItemModel(parent)
{
  QMap < StationsPluginFactory *, StationsPlugin * > ret = manager->stations();

  foreach (StationsPluginFactory *factory, ret.uniqueKeys())
    factories[factory] = ret.values(factory);
}

PluginsModel::~PluginsModel()
{

}

int
PluginsModel::columnCount(const QModelIndex &parent) const
{
  return 2;
}

QVariant
PluginsModel::data(const QModelIndex &index, int role) const
{
  StationsPluginFactory *factory;
  StationsPlugin *plugin;

  if (!index.isValid())
    return QVariant();

  if (indexToItem(index, &factory, &plugin) == -1)
    return QVariant();

  if (plugin) {
    if (role == Qt::DisplayRole)
      if (index.column())
      return plugin->name;
  } else {

  }
}

Qt::ItemFlags
PluginsModel::flags(const QModelIndex &index) const
{
  if (!index.isValid())
    return 0;

  return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant
PluginsModel::headerData(int section, Qt::Orientation orientation,
			 int role) const
{
  if (role == Qt::DisplayRole) {
    if (section == 1)
      return tr("Name");
    if (section == 2)
      return tr("Description");
  }


  return QVariant();
}

QModelIndex
PluginsModel::index(int row, int column, const QModelIndex &parent) const
{
  if (!hasIndex(row, column, parent))
    return QModelIndex();

  TreeItem *parentItem;

  if (!parent.isValid())
    parentItem = rootItem;
  else
    parentItem = static_cast<TreeItem*>(parent.internalPointer());

  TreeItem *childItem = parentItem->child(row);
  if (childItem)
    return createIndex(row, column, childItem);
  else
    return QModelIndex();
}

QModelIndex
PluginsModel::parent(const QModelIndex &index) const
{
  StationsPluginFactory *factory;
  StationsPlugin *plugin;
  int idx;

  if (!index.isValid())
    return QModelIndex();

  idx = indexToItem(index, &factory, &plugin);

  if (!plugin || idx == -1)
    return QModelIndex();
  else
    return createIndex(plugins[factory].indexOf(plugin), 0, factory);
}

int
PluginsModel::rowCount(const QModelIndex &parent) const
{
  if (parent.column() > 0)
    return 0;

  if (!parent.isValid())
    return factories.count();
  else {
    StationsPluginFactory *factory = static_cast<StationsPluginFactory *>(parent.internalPointer());
    return plugins[factory].count();
  }
}

int
PluginsModel::indexToItem(const QModelIndex & index, StationsPluginFactory **factory, StationsPlugin **plugin)
{
  *factory = NULL;
  *plugin = NULL;

  if (!index.isValid())
    return -1;

  *factory = dynamic_cast<StationsPluginFactory *>(index.internalPointer());
  *plugin = dynamic_cast<StationsPlugin *>(index.internalPointer());

  if (*factory) {
    return factories.indexOf(*factory);
  } else {
    int idx;

    foreach (StationsPluginFactory *f, plugins.keys())
      if ((idx = plugins[f].indexOf(plugin)) != -1) {
	*factory = f;
	return idx;
      }
  }
}
