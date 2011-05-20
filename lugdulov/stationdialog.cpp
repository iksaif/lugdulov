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

#include <QtGui/QMessageBox>
#include <QtGui/QDesktopWidget>
#include <QtGui/QDesktopServices>
#include <QtGui/QPushButton>

#include "lugdulov.h"
#include "tools.h"

#include "stationdialog.h"
#include "station.h"
#include "stationsplugin.h"
#include "settings.h"
#include "mapdialog.h"

StationDialog::StationDialog(Station *station, QWidget * parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  station(station)
{
  setupUi(this);
  setupDialog(this);
  setupWidgets();
  setupButtons();

  /* Update Station Status */
  if (station->freeSlots() == -1) {
    station->plugin()->updateCached(station);
    connect(station->plugin(), SIGNAL(stationsUpdated(const QList < Station * > &)),
	    this, SLOT(setupWidgets()));
  }

#if defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  QFont font = descriptionLabel->font();
  stationLabel->setFont(font);
#endif

#if defined(Q_WS_MAEMO_5) || defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  orientationChanged();
  connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(orientationChanged()));
#endif

  if (station->plugin()) {
    bikeLabel->setPixmap(station->plugin()->bikeIcon().pixmap(bikeLabel->pixmap()->size()));
  }

  fetchImage();
  resize(sizeHint());
}

StationDialog::~StationDialog()
{
}

void
StationDialog::setupWidgets()
{
  setWindowTitle(QString("%1").arg(station->name()));

  if (station->totalSlots() >= 0) {
    slotsProgressBar->setRange(0, station->totalSlots());
    bikeProgressBar->setRange(0, station->totalSlots());
    if (!station->freeSlots() >= 0)
      slotsProgressBar->setValue(station->freeSlots());
    if (!station->bikes() >= 0)
      bikeProgressBar->setValue(station->bikes());
    slotsProgressBar->setFormat("%v/%m");
    bikeProgressBar->setFormat("%v/%m");
  } else {
    if (station->freeSlots() >= 0) {
      if (station->freeSlots())
	slotsProgressBar->setRange(0, station->freeSlots());
      else
	slotsProgressBar->setRange(0, 1);
      slotsProgressBar->setValue(station->freeSlots());
    }
    if (station->bikes() >= 0) {
      if (station->bikes())
	bikeProgressBar->setRange(0, station->bikes());
      else
	bikeProgressBar->setRange(0, 1);
      bikeProgressBar->setValue(station->bikes());
    }
    slotsProgressBar->setFormat("%v");
    bikeProgressBar->setFormat("%v");
  }

  descriptionLabel->setText(station->description());
  stationLabel->setText(station->name());
}

void
StationDialog::setupButtons()
{
  connect(bookmarkButton, SIGNAL(clicked(bool)), this, SLOT(bookmark(bool)));
  connect(mapButton, SIGNAL(clicked(bool)), this, SLOT(showMap()));

  bookmarkButton->setChecked(Settings::bookmarked(station) ? Qt::Checked : Qt::Unchecked);

  foreach (QAction *action, station->plugin()->actions()) {
    QPushButton *button = new QPushButton(this);

    action->setParent(this);
    button->addAction(action);
    button->setIcon(action->icon());
    button->setText(action->text());
    connect(button, SIGNAL(clicked(bool)), this, SLOT(pluginAction()));
    pluginButtonsLayout->addWidget(button);
  }
}

void
StationDialog::showMap()
{
  MapDialog *map = new MapDialog(station->plugin(), this);

  map->centerView(station->pos());
  showAndDelete(map);
}

void
StationDialog::pluginAction()
{
  QAction *action = ((QPushButton *)sender())->actions()[0];

  station->plugin()->actionTriggered(action, station, this);
}

void
StationDialog::fetchImage()
{
  QUrl url = station->plugin()->imageUrl(station->id());

  if (url.isEmpty()) {
    iconLabel->hide();
    return ;
  }

  nm = new QNetworkAccessManager(this);
  QNetworkReply *rep;
  QNetworkRequest req(url);

  Tools::fixupRequest(&req);
  rep = nm->get(req);

  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));
  connect(rep, SIGNAL(finished()), this, SLOT(requestFinished()));

#if defined(Q_WS_MAEMO_5)
  setAttribute(Qt::WA_Maemo5ShowProgressIndicator, true);
#endif
}

void
StationDialog::requestError(QNetworkReply::NetworkError code)
{
  QNetworkReply *rep = qobject_cast<QNetworkReply *>(sender());

  if (rep && code != QNetworkReply::ContentNotFoundError)
    QMessageBox::warning(this, tr("Network Error"), rep->errorString());
}

void
StationDialog::requestFinished()
{
  QNetworkReply *rep = qobject_cast<QNetworkReply *>(sender());

  if (!rep)
    return ;

  rep->deleteLater();

  QPixmap pix;
  pix.loadFromData(rep->readAll());

  if (!pix.isNull()) {
    pix = pix.scaled(iconLabel->width(), iconLabel->height(),
		     Qt::KeepAspectRatio, Qt::SmoothTransformation);
    iconLabel->setPixmap(pix);
#if defined(Q_WS_MAEMO_5) || defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
    orientationChanged();
#else
    iconLabel->show();
    resize(sizeHint());
#endif
  }
}

void
StationDialog::orientationChanged()
{
  QRect screenGeometry = QApplication::desktop()->screenGeometry();

  if (screenGeometry.width() < screenGeometry.height() && iconLabel->pixmap())
    iconLabel->show();
  else
    iconLabel->hide();
  resize(sizeHint());
#if defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  showMaximized();
#endif
}

void StationDialog::bookmark(bool bookmark)
{
  Settings::bookmark(station, bookmark);
}
