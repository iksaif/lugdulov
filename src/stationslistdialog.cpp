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

#include "stations.h"
#include "station.h"
#include "stationslistdialog.h"

StationsListDialog::StationsListDialog(QWidget *parent)
  : QDialog(parent)
{
  setupUi(this);

#ifdef Q_WS_MAEMO_5
  setAttribute(Qt::WA_Maemo5StackedWindow);
  setAttribute(Qt::WA_Maemo5AutoOrientation, true);
#endif

  setupListWidget();

  refreshButton->setIcon(QIcon::fromTheme("view-refresh"));
  nearButton->hide();
  lineEdit->setFocus(Qt::OtherFocusReason);

  stations = NULL;
}

StationsListDialog::~StationsListDialog()
{
}

void
StationsListDialog::setupListWidget()
{
  connect(lineEdit, SIGNAL(textEdited(const QString &)),
	  listWidget, SLOT(filter(const QString &)));
  connect(comboBox, SIGNAL(activated(const QString &)),
	  listWidget, SLOT(setRegion(const QString &)));
  connect(refreshButton, SIGNAL(clicked()), listWidget, SLOT(update()));
#ifdef HAVE_QT_LOCATION
  connect(nearButton, SIGNAL(clicked()), this, SLOT(fetchNear()));
#endif
}

void
StationsListDialog::setMode(Mode mode)
{
  if (mode == Search) {
    setWindowTitle(tr("Search Stations"));
    lineEdit->show();
    nearButton->show();
    refreshButton->show();
    listWidget->showBookmarks(false);
    comboBox->show();
  } else {
    setWindowTitle(tr("Favorites Stations"));
    lineEdit->hide();
    nearButton->hide();
    refreshButton->hide();
    listWidget->showBookmarks(true);
    comboBox->hide();
  }
}


#ifdef HAVE_QT_LOCATION
void
StationsListDialog::fetchNear()
{
  QGeoCoordinate coord = position.coordinate();

  listWidget->clearNear();
  stations->fetchPos(QPointF(coord.latitude(), coord.longitude()), 5);
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

  if (stations)
    nearButton->show();
}
#endif

void
StationsListDialog::setStations(Stations *sta)
{
  if (sta == stations)
    return ;

  if (stations) {
    disconnect(stations, 0, this, 0);
  }

  stations = sta;

  if (!stations)
    return ;

  comboBox->clear();
  comboBox->addItem(tr("All"));
  comboBox->addItems(stations->regions());

  listWidget->setStations(stations);

  connect(stations, SIGNAL(progress(qint64, qint64)), this, SLOT(progress(qint64, qint64)));
  connect(stations, SIGNAL(error(const QString &, const QString &)),
	  this, SLOT(error(const QString &, const QString &)));

  if (position.coordinate().isValid())
    nearButton->show();
  QTimer::singleShot(1, stations, SLOT(fetchAll()));
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
