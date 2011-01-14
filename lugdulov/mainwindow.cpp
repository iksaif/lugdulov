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
#include <QtCore/QDebug>

#include "lugdulov.h"

#if defined(LUGDULOV_FULL_UI)
#include "ui_fullwindow.h"
#else
#include "ui_mainwindow.h"
#endif

#include "tools.h"
#include "stationsplugin.h"
#include "stationspluginmanager.h"
#include "station.h"
#include "mainwindow.h"
#include "stationslistdialog.h"
#include "pluginsdialog.h"
#include "mapdialog.h"
#include "settings.h"
#include "aboutdialog.h"
#include "settingsdialog.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    ui(new Ui_MainWindow)
{
  ui->setupUi(this);

#ifdef HAVE_QT_LOCATION
  localisation = NULL;
#endif
#if defined(Q_WS_MAEMO_5)
  ui->menu_File->removeAction(ui->quitAction);
  ui->menu_Help->removeAction(ui->aboutQtAction);
  setAttribute(Qt::WA_Maemo5StackedWindow);
  setAttribute(Qt::WA_Maemo5AutoOrientation, true);

# if !defined(LUGDULOV_FULL_UI)
  ui->searchLinkButton->setDescription(tr("Search stations by name"));
  ui->bookmarkLinkButton->setDescription(tr("Manage your favorites stations."));
# endif
#elif defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  ui->pushButton->setIconSize(QSize(24,24));
# if !defined(LUGDULOV_FULL_UI)
  ui->searchLinkButton->setDescription(QString());
  ui->bookmarkLinkButton->setDescription(QString());
  ui->mapLinkButton->setDescription(QString());
# endif
#else
  ui->pushButton->setIconSize(QSize(24,24));
#endif

#if defined(Q_WS_S60) || defined(Q_WS_SIMULATOR) || defined(Q_WS_MAEMO_5)
  ui->iconLabel->hide();
  ui->titleLabel->hide();
#endif


#if defined(LUGDULOV_FULL_UI)
  connect(ui->mapWidget, SIGNAL(centerChanged(const QPointF &)),
	  ui->listWidget, SLOT(positionUpdated(const QPointF &)));
  connect(ui->listWidget, SIGNAL(stationSelected(Station *)),
	  ui->mapWidget, SLOT(centerOnStation(Station *)));
#endif

#if defined(Q_WS_MAEMO_5)
  progressBar = NULL;
#else
  progressBar = new QProgressBar(this);
  progressBar->hide();
  statusBar()->addPermanentWidget(progressBar, 0);
#endif

  plugin = NULL;

  createActions();
  createButton();

  QTimer::singleShot(0, this, SLOT(delayedInit()));
}


MainWindow::~MainWindow()
{
  delete ui;
}

void
MainWindow::createButton()
{
  Settings conf;
  QString selected = conf.value("StationsPlugin").toString();
  StationsPlugin *selectedPlugin = NULL;

  manager = new StationsPluginManager(this);

  selectedPlugin = manager->station(selected);

  setStationsPlugin(selectedPlugin);
  connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
}

void
MainWindow::createActions()
{
  ui->quitAction->setIcon(QIcon::fromTheme("dialog-close"));
  ui->aboutAction->setIcon(QIcon::fromTheme("dialog-information"));
  ui->aboutQtAction->setIcon(QPixmap(":/trolltech/qmessagebox/images/qtlogo-64.png"));
  ui->settingsAction->setIcon(QIcon::fromTheme("configure", QPixmap(":/res/configure.png")));
  ui->settingsButton->setIcon(QIcon::fromTheme("configure", QPixmap(":/res/configure.png")));

  connect(ui->aboutAction, SIGNAL(triggered()), this, SLOT(about()));
  connect(ui->aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));

#if !defined(LUGDULOV_FULL_UI)
  connect(ui->searchLinkButton, SIGNAL(clicked(bool)), this, SLOT(search()));
  connect(ui->mapLinkButton, SIGNAL(clicked(bool)), this, SLOT(map()));
  connect(ui->bookmarkLinkButton, SIGNAL(clicked(bool)), this, SLOT(bookmarks()));
#endif

  connect(ui->settingsAction, SIGNAL(triggered(bool)), this, SLOT(settings()));
  connect(ui->settingsButton, SIGNAL(clicked(bool)), this, SLOT(settings()));
}

void
MainWindow::delayedInit()
{
#if defined(HAVE_QT_BEARER) || QT_VERSION >= 0x040700
  QNetworkConfigurationManager manager;
  const bool selectIap = (manager.capabilities()& QNetworkConfigurationManager::CanStartAndStopInterfaces);
  QNetworkConfiguration ap = manager.defaultConfiguration();
  QNetworkSession* session = new QNetworkSession(ap, this);

  (void) selectIap;

  session->open();
#endif
#ifdef HAVE_QT_LOCATION
  Settings conf;

  localisation = QGeoPositionInfoSource::createDefaultSource(this);

  if (!localisation) {
    if (!plugin)
      buttonClicked();
    return ;
  }

  statusMsg(tr("Waiting for GPS fix..."));

  connect(localisation, SIGNAL(positionUpdated(QGeoPositionInfo)), this, SLOT(positionUpdated(QGeoPositionInfo)));
  connect(localisation, SIGNAL(updateTimeout()), this, SLOT(positionRequestTimeout()));

  if (conf.value("GpsPowerSave").toBool())
    localisation->setUpdateInterval(200000);
  else
    localisation->setUpdateInterval(10000);
  localisation->startUpdates();
  localisation->requestUpdate(15000);
#endif

#if defined(LUGDULOV_FULL_UI) && !defined(HAVE_QT_LOCATION)
  if (!plugin)
    buttonClicked();
#endif
}

#ifdef HAVE_QT_LOCATION
void
MainWindow::positionRequestTimeout()
{

}

void
MainWindow::positionUpdated(QGeoPositionInfo info)
{
  QGeoCoordinate coord = info.coordinate();

  if (!coord.isValid() || (coord.latitude() == 0 && coord.longitude() == 0))
    return ;

  if (!position.coordinate().isValid())
    statusMsg(tr("Got GPS Fix."));

  position = info;

  QPointF pt(coord.latitude(), coord.longitude());

#if defined(LUGDULOV_FULL_UI)
  ui->mapWidget->positionUpdated(info);
#endif

  if (plugin) // && plugin->rect().contains(pt))
    return ;

  StationsPlugin *p = manager->station(pt);

  if (p)
    setStationsPlugin(p);
}
#endif

void
MainWindow::buttonClicked()
{
  PluginsDialog dlg(manager, this);

  if (dlg.exec())
    setStationsPlugin(dlg.plugin(), true);
  else
    setStationsPlugin(NULL, true);
}

void
MainWindow::setStationsPlugin(StationsPlugin *sta, bool save)
{
  if (plugin)
    plugin->deleteLater();

  plugin = sta;

  if (plugin)
    plugin->setParent(this);

  if (plugin) {
    ui->pushButton->setText(plugin->name());
    ui->pushButton->setIcon(plugin->bikeIcon());

    connect(plugin, SIGNAL(progress(qint64, qint64)), this, SLOT(progress(qint64, qint64)));

    QTimer::singleShot(1, this, SLOT(updatePlugin()));
  } else {
    ui->pushButton->setText(tr("Auto"));
  }
  if (save) {
    Settings conf;
    conf.setValue("StationsPlugin", plugin ? plugin->id() : "auto");
  }

  fullUiSetStationPlugin(plugin);
}

void
MainWindow::about()
{
  AboutDialog dialog(this);

  dialog.exec();
}

void
MainWindow::aboutQt()
{
  QMessageBox::aboutQt(this);
}

void
MainWindow::statusMsg(const QString & msg, int timeout)
{
#ifdef Q_WS_MAEMO_5
  if (!timeout)
    timeout = QMaemo5InformationBox::NoTimeout;
  QMaemo5InformationBox::information(this, msg, timeout);
#else
  statusBar()->showMessage(msg, timeout);
#endif
}

void
MainWindow::chooseStationsPlugin()
{
  QMessageBox::warning(this, tr("Please set Location."),
		       tr("We can't guess your current location, "
			  "please choose one in the list."));

  buttonClicked();
}

void
MainWindow::progress(qint64 done, qint64 total)
{
  if (!progressBar)
    return ;

  if (done >= total)
    progressBar->hide();
  else if (!progressBar->isVisible())
    progressBar->show();

  progressBar->setRange(0, total);
  progressBar->setValue(done);
}

void
MainWindow::updatePlugin(void)
{
  if (!plugin)
    return ;

  plugin->fetchAll();

#if QT_VERSION >= 0x040700
  QNetworkConfigurationManager mgr;
  QList<QNetworkConfiguration> configs;

  configs = mgr.allConfigurations(QNetworkConfiguration::Active);

  foreach (QNetworkConfiguration config, configs) {
    QNetworkConfiguration::BearerType type = config.bearerType();

    /* Don't fetch stations from network on slow links */
    if (type != QNetworkConfiguration::BearerEthernet &&
	type != QNetworkConfiguration::BearerWLAN &&
	type != QNetworkConfiguration::BearerWiMAX)
      return ;
    else
      break ;
  }
#endif

  plugin->fetchOnline();
}

void
MainWindow::settings()
{
  Settings conf;
  QString provider = conf.value("MapProvider").toString();
  
  SettingsDialog dialog(this);

  if (dialog.exec())
    dialog.saveSettings();

#if defined(LUGDULOV_FULL_UI)	
  if (provider != conf.value("MapProvider").toString())
    QMessageBox::warning(this, tr("Please restart Lugdulo'V."),
		       tr("You need to restart Lugdulo'V  for changes to take effect."));
#endif
}

void
MainWindow::search(bool bookmarks)
{
  if (!plugin) {
    chooseStationsPlugin();
    return ;
  }

  StationsListDialog *dlg = new StationsListDialog(plugin, this);

#ifdef HAVE_QT_LOCATION
  if (localisation) {
    connect(localisation, SIGNAL(positionUpdated(QGeoPositionInfo)), dlg, SLOT(positionUpdated(QGeoPositionInfo)));
    connect(localisation, SIGNAL(updateTimeout()), dlg, SLOT(positionRequestTimeout()));

    localisation->requestUpdate(15000);
  }
#endif

  dlg->onlyBookmarks(bookmarks);

  showAndDelete(dlg);
}

void
MainWindow::bookmarks()
{
  search(true);
}

void
MainWindow::map()
{
  if (!plugin) {
    chooseStationsPlugin();
    return ;
  }

  MapDialog *map = new MapDialog(plugin, this);
  QPointF pt = plugin->center();
  int zoom = 15;

#ifdef HAVE_QT_LOCATION
  if (localisation) {
    QGeoCoordinate coord = position.coordinate();
    QPointF pt(coord.latitude(), coord.longitude());

    connect(localisation, SIGNAL(positionUpdated(QGeoPositionInfo)),
	    map, SLOT(positionUpdated(QGeoPositionInfo)));

    if (coord.isValid() && plugin->rect().contains(pt)) {
      zoom = 0;
      map->positionUpdated(position);
    }

    localisation->requestUpdate(15000);
  }
#endif

  if (zoom)
    map->centerView(pt, zoom);
  showAndDelete(map);
}

#if defined(LUGDULOV_FULL_UI)
void
MainWindow::fullUiSetStationPlugin(StationsPlugin *plugin)
{
  ui->mapWidget->setPlugin(plugin);
  ui->listWidget->setPlugin(plugin);

  if (plugin) {
    QPointF pt = plugin->center();
    int zoom = 15;

    ui->mapWidget->setPlugin(plugin);
    ui->listWidget->setPlugin(plugin);

#ifdef HAVE_QT_LOCATION
  if (localisation) {
    QGeoCoordinate coord = position.coordinate();
    QPointF pt(coord.latitude(), coord.longitude());

    if (coord.isValid() && plugin->rect().contains(pt)) {
      zoom = 0;
      ui->mapWidget->positionUpdated(position);
    }

    localisation->requestUpdate(15000);
  }
#endif

  if (zoom)
    ui->mapWidget->centerView(pt, zoom);
  }
}
#else
void
MainWindow::fullUiSetStationPlugin(StationsPlugin *plugin)
{
}
#endif
