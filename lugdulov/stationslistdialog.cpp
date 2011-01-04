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
#include "ui_stationslistwidget.h"

#include "lugdulov.h"
#include "stationslistdialog.h"
#include "stationslistwidget.h"
#include "stationsplugin.h"

StationsListDialog::StationsListDialog(StationsPlugin *plugin, QWidget *parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  ui(new Ui_StationsListDialog())
{
  ui->setupUi(this);
  setupDialog(this);

  connect(plugin, SIGNAL(progress(qint64, qint64)), this, SLOT(progress(qint64, qint64)));
  connect(plugin, SIGNAL(error(const QString &, const QString &)),
	  this, SLOT(error(const QString &, const QString &)));

  ui->widget->setPlugin(plugin);
  ui->widget->ui->bookmarksButton->hide();
}

StationsListDialog::~StationsListDialog()
{
  delete ui;
}

void
StationsListDialog::onlyBookmarks(bool enabled)
{
  ui->widget->onlyBookmarks(enabled);
}

#ifdef HAVE_QT_LOCATION
void
StationsListDialog::positionRequestTimeout()
{
  ui->widget->positionRequestTimeout();
}

void
StationsListDialog::positionUpdated(QGeoPositionInfo info)
{
  ui->widget->positionUpdated(info);
}
#endif

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
