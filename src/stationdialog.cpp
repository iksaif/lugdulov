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

#include <QtGui/QMessageBox>
#include <QtGui/QDesktopWidget>
#include <QtGui/QDesktopServices>

#include "stationdialog.h"
#include "station.h"
#include "stationsplugin.h"
#include "settings.h"

StationDialog::StationDialog(StationsPlugin *stations, Station *station, QWidget * parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  station(station),
  stations(stations)
{
#ifdef Q_WS_MAEMO_5
  setAttribute(Qt::WA_Maemo5StackedWindow);
#endif

  setupUi(this);
  setupWidgets();
  setupButtons();

  fetchImage();
}

StationDialog::~StationDialog()
{
}

void
StationDialog::setupWidgets()
{
  setWindowTitle(QString("%1").arg(station->name()));

  slotsProgressBar->setValue(station->freeSlots());
  bikeProgressBar->setValue(station->bikes());
  slotsProgressBar->setRange(0, station->totalSlots());
  bikeProgressBar->setRange(0, station->totalSlots());

  descriptionLabel->setText(station->description());
  stationLabel->setText(station->name());

#ifdef Q_WS_MAEMO_5
  orientationChanged();
  connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(orientationChanged()));
#endif

  if (station->plugin()) {
    bikeLabel->setPixmap(station->plugin()->bikeIcon().pixmap(bikeLabel->pixmap()->size()));
  }

  iconLabel->setText("");
  iconLabel->hide();
  resize(sizeHint());
}

void
StationDialog::setupButtons()
{
  Settings conf;
  bool bookmark;

  connect(bookmarkButton, SIGNAL(clicked(bool)), this, SLOT(bookmark(bool)));

  conf.beginGroup("Bookmarks");
  bookmark = conf.value(QString("%1").arg(station->id())).toBool();
  bookmarkButton->setChecked(bookmark ? Qt::Checked : Qt::Unchecked);
}

void
StationDialog::fetchImage()
{
  if (!stations)
    return;

  QUrl url = stations->stationImageUrl(station->id());

  if (url.isEmpty())
    return ;

  nm = new QNetworkAccessManager(this);
  QNetworkReply *rep = nm->get(QNetworkRequest(url));

  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));
  connect(rep, SIGNAL(finished()), this, SLOT(requestFinished()));

#ifdef Q_WS_MAEMO_5
  setAttribute(Qt::WA_Maemo5ShowProgressIndicator, true);
#endif
}

void
StationDialog::requestError(QNetworkReply::NetworkError code)
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());

  if (rep && code != QNetworkReply::ContentNotFoundError)
    QMessageBox::warning(this, tr("Network Error"), rep->errorString());
}
#include <QDebug>

void
StationDialog::requestFinished()
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());

  if (!rep)
    return ;

  rep->deleteLater();

  QPixmap pix;
  pix.loadFromData(rep->readAll());

  if (!pix.isNull()) {
    pix = pix.scaled(iconLabel->width(), iconLabel->height(),
		     Qt::KeepAspectRatio, Qt::SmoothTransformation);
    iconLabel->setPixmap(pix);
#ifdef Q_WS_MAEMO_5
    orientationChanged();
#else
    iconLabel->show();
#endif
  }
}

void StationDialog::orientationChanged()
{
  QRect screenGeometry = QApplication::desktop()->screenGeometry();

  if (screenGeometry.width() > screenGeometry.height())
    iconLabel->hide();
  else
    iconLabel->show();
}
#include <QDebug>
void StationDialog::bookmark(bool bookmark)
{
  Settings conf;
  QString key("%1");

  key = key.arg(station->id());

  conf.beginGroup("Bookmarks");
  if (bookmark)
    conf.setValue(key, true);
  else
    conf.remove(key);
}
