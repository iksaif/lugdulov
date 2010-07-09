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

#include "stationdialog.h"
#include "station.h"
#include "stations.h"

StationDialog::StationDialog(Station *s, QWidget * parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  station(s)
{
  setupUi(this);

  setWindowTitle(QString("Quick Velo'v - %1").arg(station->name()));

  slotsSlider->setRange(0, station->totalSlots());
  bikeSlider->setRange(0, station->totalSlots());
  slotsSlider->setValue(station->freeSlots());
  bikeSlider->setValue(station->bikes());

  slotSpinBox->setValue(station->freeSlots());
  bikeSpinBox->setValue(station->bikes());

  descriptionLabel->setText(station->description());
  stationLabel->setText(station->name());

#ifdef Q_WS_MAEMO_5
  orientationChanged();
  connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(orientationChanged()));
#endif

  iconLabel->hide();
  resize(sizeHint());

  // connect push
  nm = new QNetworkAccessManager(this);
  QNetworkReply *rep = nm->get(QNetworkRequest(Station::stationImageUrl(station->id())));
  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));
  connect(rep, SIGNAL(finished()), this, SLOT(requestFinished()));
#ifdef Q_WS_MAEMO_5
  setAttribute(Qt::WA_Maemo5ShowProgressIndicator, true);
  setAttribute(Qt::WA_Maemo5StackedWindow);
#endif
}

StationDialog::~StationDialog()
{
}

void
StationDialog::requestError(QNetworkReply::NetworkError code)
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());

  if (rep)
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

void StationDialog::bookmark()
{
}

void StationDialog::gmap()
{
}

void StationDialog::velov()
{
}
