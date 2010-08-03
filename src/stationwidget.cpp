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

#include <QtGui/QDesktopWidget>

#include "stationwidget.h"
#include "station.h"
#include "stationsplugin.h"
#include "settings.h"

StationWidget::StationWidget(Station *station, QWidget * parent)
  : QWidget(parent), station(station)
{
  setupUi(this);

#ifdef Q_WS_MAEMO_5
  QFont font;
  font.setPointSize(10);
  dstLabel->setFont(font);
#endif

  if (station->plugin())
    bikeIcon->setPixmap(station->plugin()->bikeIcon().pixmap(bikeIcon->pixmap()->size()));
  update();
}

StationWidget::~StationWidget()
{
}

void
StationWidget::update()
{
  if (station->bikes() != -1)
    bikeLabel->setNum(station->bikes());
  if (station->freeSlots() != -1)
    slotLabel->setNum(station->freeSlots());

  QString descr = station->description();

#ifdef Q_WS_MAEMO_5
  QRect screenGeometry = QApplication::desktop()->screenGeometry();

  if (screenGeometry.width() < screenGeometry.height()) {
    if (descr.size() > 30) {
      descr = descr.left(30) + tr("...");
    }
  }
#endif

  if (station->distanceTo(QPointF()) != -1)
    descr += QString(" (%2m)").arg((int)station->distanceTo(QPointF()));
  dstLabel->setText(descr);

  if (!Settings::bookmarked(station))
    bookmarkLabel->hide();
}
