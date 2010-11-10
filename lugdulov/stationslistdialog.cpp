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

#include "ui_stationslistdialog.h"

#include "tools.h"
#include "lugdulov.h"
#include "settings.h"
#include "stationsplugin.h"
#include "station.h"
#include "stationslistdialog.h"
#include "stationsmodel.h"
#include "stationdelegate.h"
#include "stationssortfilterproxymodel.h"
#include "stationslistview.h"

#if defined(Q_WS_MAEMO_5) || defined(Q_OS_SYMBIAN) || defined(Q_OS_SIMULATOR)
static const int filterTimeout = 1000;
#else
static const int filterTimeout = 200;
#endif

StationsListDialog::StationsListDialog(StationsPlugin *plugin, QWidget *parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  plugin(plugin),
  ui(new Ui_StationsListDialog())
{
  ui->setupUi(this);
  setupDialog(this);

  ui->refreshButton->setIcon(QIcon::fromTheme("view-refresh", QPixmap(":/res/view-refresh.png")));
#ifdef Q_WS_MAEMO_5
  ui->refreshButton->setText("");
#endif
  ui->lineEdit->setFocus(Qt::OtherFocusReason);

  connect(ui->lineEdit, SIGNAL(textEdited(const QString &)),
	  this, SLOT(filterEdited(const QString &)));
  connect(ui->refreshButton, SIGNAL(clicked()), ui->listView, SLOT(forceUpdate()));
  connect(&filterTimer, SIGNAL(timeout()), this, SLOT(filter()));

  ui->listView->setAlternatingRowColors(true);
  ui->listView->setItemDelegate(new StationDelegate(ui->listView));

  model = new StationsModel(plugin, this);
  proxy = new StationsSortFilterProxyModel(this);

  //proxy->setStationLimit(5);
  proxy->setSourceModel(model);
  proxy->setBookmarks(Settings::bookmarks(plugin));
  proxy->setSortRole(StationsSortFilterProxyModel::StationDistanceRole);
  ui->listView->setStationsPlugin(plugin);
  ui->listView->setModel(proxy);


  connect(plugin, SIGNAL(progress(qint64, qint64)), this, SLOT(progress(qint64, qint64)));
  connect(plugin, SIGNAL(error(const QString &, const QString &)),
	  this, SLOT(error(const QString &, const QString &)));

  QTimer::singleShot(1, plugin, SLOT(fetchAll())); // First fetch cached data
}

StationsListDialog::~StationsListDialog()
{
  delete ui;
}

#ifdef HAVE_QT_LOCATION
void
StationsListDialog::positionRequestTimeout()
{
  position = QGeoPositionInfo();
}

void
StationsListDialog::positionUpdated(QGeoPositionInfo info)
{
  QGeoCoordinate coord = info.coordinate();

  if (!coord.isValid())
    return ;

  position = info;

  proxy->setPosition(QPointF(coord.latitude(), coord.longitude()));
  proxy->sort(0);
}
#endif

void
StationsListDialog::filterEdited(const QString & text)
{
  filterTimer.start(filterTimeout);
}

void
StationsListDialog::filter(void)
{
  proxy->setFilterRole(StationsModel::StationNameRole);
  proxy->setFilterWildcard(QString("*%1*").arg(ui->lineEdit->text()));
  proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void
StationsListDialog::progress(qint64 done, qint64 total)
{
#ifdef Q_WS_MAEMO_5
  setAttribute(Qt::WA_Maemo5ShowProgressIndicator, !(done == total));
#endif
}

void
StationsListDialog::error(const QString & title, const QString & message)
{
  if (isVisible())
    QMessageBox::warning(this, title, message);
}
