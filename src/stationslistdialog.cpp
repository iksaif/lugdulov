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

#include "settings.h"
#include "stationsplugin.h"
#include "station.h"
#include "stationslistdialog.h"
#include "stationsmodel.h"
#include "stationdelegate.h"
#include "stationssortfilterproxymodel.h"
#include "stationslistview.h"

StationsListDialog::StationsListDialog(StationsPlugin *plugin, QWidget *parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  plugin(plugin)
{
  setupUi(this);

#ifdef Q_WS_MAEMO_5
  setAttribute(Qt::WA_Maemo5StackedWindow);
  setAttribute(Qt::WA_Maemo5AutoOrientation, true);
#endif

  refreshButton->setIcon(QIcon::fromTheme("view-refresh", QPixmap(":/res/view-refresh.png")));
  nearButton->setIcon(QPixmap(":/res/gps.png"));
#ifdef Q_WS_MAEMO_5
  refreshButton->setText("");
  nearButton->setText("");
#endif
  nearButton->hide();
  lineEdit->setFocus(Qt::OtherFocusReason);

  connect(lineEdit, SIGNAL(textEdited(const QString &)), this, SLOT(filter(const QString &)));
  connect(refreshButton, SIGNAL(clicked()), listView, SLOT(forceUpdate()));
#ifdef HAVE_QT_LOCATION
  connect(nearButton, SIGNAL(clicked()), this, SLOT(fetchNear()));
#endif

  listView->setAlternatingRowColors(true);
  listView->setItemDelegate(new StationDelegate(listView));

  model = new StationsModel(plugin, this);
  proxy = new StationsSortFilterProxyModel(this);

  //proxy->setStationLimit(5);
  proxy->setSourceModel(model);
  proxy->setBookmarks(Settings::bookmarks(plugin));
  listView->setStationsPlugin(plugin);
  listView->setModel(proxy);


  connect(plugin, SIGNAL(progress(qint64, qint64)), this, SLOT(progress(qint64, qint64)));
  connect(plugin, SIGNAL(error(const QString &, const QString &)),
	  this, SLOT(error(const QString &, const QString &)));

  QTimer::singleShot(1, plugin, SLOT(fetchAll()));
}

StationsListDialog::~StationsListDialog()
{
}

#ifdef HAVE_QT_LOCATION
void
StationsListDialog::fetchNear()
{
  QGeoCoordinate coord = position.coordinate();

  proxy->setSortRole(StationsSortFilterProxyModel::StationDistanceRole);
  proxy->sort(0);
}

void
StationsListDialog::positionRequestTimeout()
{
  position = QGeoPositionInfo();
  nearButton->hide();
}

void
StationsListDialog::positionUpdated(QGeoPositionInfo info)
{
  QGeoCoordinate coord = info.coordinate();

  if (!coord.isValid())
    return ;

  position = info;

  nearButton->show();
  proxy->setPosition(QPointF(coord.latitude(), coord.longitude()));
}
#endif

void
StationsListDialog::filter(const QString & text)
{
  proxy->setFilterRole(StationsModel::StationNameRole);
  proxy->setFilterWildcard(QString("*%1*").arg(text));
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
