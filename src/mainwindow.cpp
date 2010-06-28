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

#include <QtGui/QDesktopServices>
#include <QtGui/QMessageBox>
#include <QtCore/QTimer>

#include <QDebug>

#include "config.h"
#include "stations.h"
#include "station.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  setupUi(this);

  updateBar = new QProgressBar();
  updateBar->hide();
  statusBar()->addPermanentWidget(updateBar, 0);

  quitAction->setIcon(QIcon::fromTheme("dialog-close"));
  aboutAction->setIcon(QIcon::fromTheme("dialog-information"));
  aboutQtAction->setIcon(QPixmap(":/trolltech/qmessagebox/images/qtlogo-64.png"));
  pushButton->setIcon(QIcon::fromTheme("view-refresh"));

  connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
  connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));
  connect(velovAction, SIGNAL(triggered()), this, SLOT(velov()));

  stations = new Stations(this);
  comboBox->addItems(Station::regions());

  connect(stations, SIGNAL(done()), this, SLOT(done()));
  connect(stations, SIGNAL(started()), this, SLOT(started()));
  connect(stations, SIGNAL(progress(qint64, qint64)), this, SLOT(progress(qint64, qint64)));

  connect(stations, SIGNAL(stationUpdated(Station *)),
	  treeWidget, SLOT(stationUpdated(Station *)));
  connect(stations, SIGNAL(stationsUpdated(QList < Station *>)),
	  treeWidget, SLOT(stationsUpdated(QList < Station *>)));
  connect(stations, SIGNAL(statusUpdated(Station *)),
	  treeWidget, SLOT(statusUpdated(Station *)));

  connect(lineEdit, SIGNAL(textEdited(const QString &)),
	  treeWidget, SLOT(filter(const QString &)));
  connect(pushButton, SIGNAL(clicked()), treeWidget, SLOT(update()));
  connect(comboBox, SIGNAL(activated(const QString &)), treeWidget, SLOT(setRegion(const QString &)));

  lineEdit->setFocus(Qt::OtherFocusReason);

  QTimer::singleShot(100, stations, SLOT(fetchBuiltIn()));
  //stations->fetchFromFile(":/res/stations.json");
  //stations->fetchAll();
}

MainWindow::~MainWindow()
{
}

void
MainWindow::about()
{
  QMessageBox::about(this, tr("About Quick Velo'V " QUICK_VELOV_VERSION),
		     tr("Version: " QUICK_VELOV_VERSION "\n"
			"Home: http://xf.iksaif.net/dev/quickvelov.html\n\n"
			"Copyright (C) 2010 Corentin Chary <corentin.chary@gmail.com>\n"
			"\n"
			"This program is free software; you can redistribute it and/or modify\n"
			"it under the terms of the GNU General Public License as published by\n"
			"the Free Software Foundation; either version 2 of the License, or\n"
			"(at your option) any later version.\n"
			"\n"
			"This program is distributed in the hope that it will be useful, but\n"
			"WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY\n"
			"or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License\n"
			"for more details.\n"
			"\n"
			"You should have received a copy of the GNU General Public License along\n"
			"with this program; if not, write to the Free Software Foundation, Inc.,\n"
			"59 Temple Place, Suite 330, Boston, MA 02111-1307 USA\n"));
}

void
MainWindow::aboutQt()
{
  QMessageBox::aboutQt(this);
}

void
MainWindow::velov()
{
  QDesktopServices::openUrl(QUrl("http://www.velov.grandlyon.com/"));
}

void
MainWindow::started()
{
  updateBar->setRange(0, 1);
  updateBar->setValue(0);
  updateBar->show();
}

void
MainWindow::done()
{
  updateBar->hide();
}

void
MainWindow::progress(qint64 done, qint64 total)
{
  if (total != updateBar->maximum()) {
    updateBar->reset();
    updateBar->setRange(0, total);
  }
  updateBar->setValue(done);
}

void
MainWindow::error(const QString & title, const QString & message)
{
  QMessageBox::warning(this, title, message);
}
