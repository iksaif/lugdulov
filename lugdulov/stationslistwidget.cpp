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

#include "config.h"

#include <QtGui/QDesktopServices>
#include <QtGui/QMessageBox>
#include <QtCore/QTimer>
#include <QDebug>

#include "config.h"

#include "ui_stationslistwidget.h"

#include "tools.h"
#include "lugdulov.h"
#include "settings.h"
#include "stationsplugin.h"
#include "station.h"
#include "stationslistwidget.h"
#include "stationsmodel.h"
#include "stationdelegate.h"
#include "stationssortfilterproxymodel.h"
#include "stationslistview.h"

#if defined(Q_WS_MAEMO_5) || defined(Q_OS_SYMBIAN) || defined(Q_OS_SIMULATOR)
static const int filterTimeout = 1000;
#else
static const int filterTimeout = 200;
#endif

StationsListWidget::StationsListWidget(QWidget *parent)
  :
  QWidget(parent),
  plugin(NULL),
  model(NULL),
  proxy(NULL),
  ui(new Ui_StationsListWidget())
{
  ui->setupUi(this);

  ui->refreshButton->setIcon(QIcon::fromTheme("view-refresh", QPixmap(":/res/view-refresh.png")));
#ifdef Q_WS_MAEMO_5
  ui->refreshButton->setText("");
#endif
  ui->lineEdit->setFocus(Qt::OtherFocusReason);

  connect(ui->lineEdit, SIGNAL(textEdited(const QString &)),
	  this, SLOT(filterEdited(const QString &)));
  connect(ui->refreshButton, SIGNAL(clicked()), ui->listView, SLOT(forceUpdate()));
  connect(ui->bookmarksButton, SIGNAL(clicked(bool)), this, SLOT(onlyBookmarks(bool)));
  connect(&filterTimer, SIGNAL(timeout()), this, SLOT(filter()));
  connect(ui->listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(stationClicked(const QModelIndex &)));

  ui->listView->setAlternatingRowColors(true);
  ui->listView->setItemDelegate(new StationDelegate(ui->listView));
}

StationsListWidget::~StationsListWidget()
{
  delete ui;
}

void
StationsListWidget::setPlugin(StationsPlugin *p)
{
  ui->listView->setModel(NULL);
  ui->listView->reset();

  if (!plugin)
    ui->listView->setStationsPlugin(NULL);

  delete proxy;
  delete model;

  plugin = p;

  if (!plugin) {
    proxy = NULL;
    model = NULL;
    return ;
  }

  model = new StationsModel(plugin, this);
  proxy = new StationsSortFilterProxyModel(this);

  //proxy->setStationLimit(5);
  proxy->setSourceModel(model);
  proxy->setSortRole(StationsSortFilterProxyModel::StationDistanceRole);
  ui->listView->setStationsPlugin(plugin);
  ui->listView->setModel(proxy);

  QTimer::singleShot(1, plugin, SLOT(fetchAll())); // First fetch cached data
}

#ifdef HAVE_QT_LOCATION
void
StationsListWidget::positionRequestTimeout()
{
  position = QGeoPositionInfo();
}

void
StationsListWidget::positionUpdated(QGeoPositionInfo info)
{
  QGeoCoordinate coord = info.coordinate();

  if (!coord.isValid())
    return ;

  position = info;

  if (!proxy)
    return ;

  proxy->setPosition(QPointF(coord.latitude(), coord.longitude()));
  proxy->sort(0);
}
#endif

void
StationsListWidget::positionUpdated(const QPointF & center)
{
  if (!proxy)
    return ;

  proxy->setPosition(center);
  proxy->sort(0);
}

void
StationsListWidget::onlyBookmarks(bool enabled)
{
  proxy->onlyBookmarks(enabled);
}

void
StationsListWidget::filterEdited(const QString & text)
{
  filterTimer.start(filterTimeout);
}

void
StationsListWidget::filter(void)
{
  if (!proxy)
    return ;

  proxy->setFilterRole(StationsModel::StationNameRole);
  proxy->setFilterWildcard(QString("*%1*").arg(ui->lineEdit->text()));
  proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void
StationsListWidget::stationClicked(const QModelIndex & index)
{
  Station *station = (Station *)index.data(StationsModel::StationRole).value<void *>();

  if (station)
    emit stationSelected(station);
}
