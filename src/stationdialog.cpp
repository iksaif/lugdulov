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
#include "stations.h"
#include "settings.h"

StationDialog::StationDialog(Station *s, QWidget * parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  station(s)
{
  Settings conf;
  bool bookmark;

  setupUi(this);

  setWindowTitle(QString("Quick Velo'v - %1").arg(station->name()));

  slotsProgressBar->setRange(0, station->totalSlots());
  bikeProgressBar->setRange(0, station->totalSlots());
  slotsProgressBar->setValue(station->freeSlots());
  bikeProgressBar->setValue(station->bikes());

  descriptionLabel->setText(station->description());
  stationLabel->setText(station->name());

#ifdef Q_WS_MAEMO_5
  orientationChanged();
  connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(orientationChanged()));
#endif

  iconLabel->setText("");
  iconLabel->hide();
  resize(sizeHint());

  nm = new QNetworkAccessManager(this);
  QNetworkReply *rep = nm->get(QNetworkRequest(Station::stationImageUrl(station->id())));
  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));
  connect(rep, SIGNAL(finished()), this, SLOT(requestFinished()));
#ifdef Q_WS_MAEMO_5
  setAttribute(Qt::WA_Maemo5ShowProgressIndicator, true);
  setAttribute(Qt::WA_Maemo5StackedWindow);
#endif

  connect(gmapButton, SIGNAL(clicked()), this, SLOT(gmap()));
  connect(bookmarkButton, SIGNAL(clicked(bool)), this, SLOT(bookmark(bool)));
  connect(velovButton, SIGNAL(clicked()), this, SLOT(velov()));

  conf.beginGroup("Bookmarks");
  bookmark = conf.value(QString("%1").arg(station->id())).toBool();
  bookmarkButton->setChecked(bookmark ? Qt::Checked : Qt::Unchecked);
}

StationDialog::~StationDialog()
{
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

void StationDialog::gmap()
{
  QLocale c(QLocale::C);
  QString str("http://maps.google.com/maps?q=");

  str += c.toString(station->pos().x());
  str += ",";
  str += c.toString(station->pos().y());

  QDesktopServices::openUrl(str);
}

void StationDialog::velov()
{
  QString str("http://www.velov.grandlyon.com/Plan-interactif.61.0.html?&gid=%1");

  str = str.arg(station->id());

  QDesktopServices::openUrl(str);
}
