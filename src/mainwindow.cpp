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

#include "stationsplugin.h"
#include "stationspluginmanager.h"
#include "station.h"
#include "mainwindow.h"
#include "stationslistdialog.h"
#include "bookmarklistdialog.h"
#include "mapdialog.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  setupUi(this);

#ifdef Q_WS_MAEMO_5
  menu_File->removeAction(quitAction);
  menu_Help->removeAction(aboutQtAction);
  setAttribute(Qt::WA_Maemo5StackedWindow);
  setAttribute(Qt::WA_Maemo5AutoOrientation, true);

  mapLinkButton->setMaximumHeight(70);
  searchLinkButton->setMaximumHeight(70);
  bookmarkLinkButton->setMaximumHeight(70);

  searchLinkButton->setDescription(tr("Search stations by name"));
  bookmarkLinkButton->setDescription(tr("Manage your favorites stations."));
#endif

  plugin = NULL;

  createActions();
  createCombo();

  QTimer::singleShot(0, this, SLOT(delayedInit()));
}


MainWindow::~MainWindow()
{
}

void
MainWindow::createCombo()
{
  Settings conf;
  QString selected = conf.value("StationsPlugin").toString();
  StationsPlugin *selectedPlugin = NULL;

  manager = new StationsPluginManager(this);

  foreach(StationsPlugin *plugin, manager->stations()) {
    stationsComboBox->addItem(plugin->bikeIcon(), plugin->name(),
			      qVariantFromValue((void *) plugin));

    if (plugin->id() == selected)
      selectedPlugin = plugin;
  }

  setStationsPlugin(selectedPlugin);
  connect(stationsComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboIndexChanged(int)));
}

void
MainWindow::createActions()
{
  quitAction->setIcon(QIcon::fromTheme("dialog-close"));
  aboutAction->setIcon(QIcon::fromTheme("dialog-information"));
  aboutQtAction->setIcon(QPixmap(":/trolltech/qmessagebox/images/qtlogo-64.png"));

  connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
  connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));

  connect(searchLinkButton, SIGNAL(clicked(bool)), this, SLOT(search()));
  connect(mapLinkButton, SIGNAL(clicked(bool)), this, SLOT(map()));
  connect(bookmarkLinkButton, SIGNAL(clicked(bool)), this, SLOT(bookmarks()));
}

void
MainWindow::delayedInit()
{
#ifdef HAVE_QT_BEARER
  QNetworkConfigurationManager mgr;
  QNetworkConfiguration ap = mgr.defaultConfiguration();
  QNetworkSession* session = new QNetworkSession(ap);

  session->open();
  if (!session->waitForOpened(-1)) {
    QMessageBox::critical(this, tr("Network Error"), session->errorString());
    QApplication::instance()->quit();
    return ;
  }
#endif
#ifdef HAVE_QT_LOCATION
  localisation = QGeoPositionInfoSource::createDefaultSource(this);

  if (!localisation)
    return ;

  statusMsg(tr("Waiting for GPS fix..."));

  connect(localisation, SIGNAL(positionUpdated(QGeoPositionInfo)),
	  this, SLOT(positionUpdated(QGeoPositionInfo)));
  connect(localisation, SIGNAL(requestTimeout()), this, SLOT(positionRequestTimeout()));
  localisation->setUpdateInterval(30000);
  localisation->startUpdates();
  localisation->requestUpdate(15000);
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

  if (!coord.isValid())
    return ;

  if (!position.coordinate().isValid())
    statusMsg(tr("Got GPS Fix."));
  position = info;

  foreach (StationsPlugin *plugin, manager->stations()) {
    if (plugin->rect().contains(QPointF(coord.latitude(), coord.longitude()))) {
      setStationsPlugin(plugin);
      break;
    }
  }
}
#endif

void
MainWindow::comboIndexChanged(int index)
{
  QVariant data = stationsComboBox->itemData(index);
  StationsPlugin *plugin = (StationsPlugin *)data.value<void *>();

  if (plugin) {
    Settings conf;

    setStationsPlugin(plugin);
    conf.setValue("StationsPlugin", plugin->id());
  }
}

void
MainWindow::setStationsPlugin(StationsPlugin *sta)
{
  if (!sta || plugin == sta)
    return ;

  plugin = sta;

  for (int i = 0; i < stationsComboBox->count(); ++i) {
    QVariant data = stationsComboBox->itemData(i);

    if (plugin == (StationsPlugin *)data.value<void *>())
      stationsComboBox->setCurrentIndex(i);
  }
}

void
MainWindow::about()
{
  QMessageBox::about(this, tr("About Lugdulo'v " LUGDULOV_VERSION),
		     tr("Version: " LUGDULOV_VERSION "\n"
			"Home: http://xf.iksaif.net/dev/lugdulov.html\n\n"
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
MainWindow::search()
{
  if (!plugin) {
    chooseStationsPlugin();
    return ;
  }

  StationsListDialog *dlg = new StationsListDialog(plugin, this);

#ifdef HAVE_QT_LOCATION
  if (localisation) {
    connect(localisation, SIGNAL(positionUpdated(QGeoPositionInfo)), dlg, SLOT(positionUpdated(QGeoPositionInfo)));
    connect(localisation, SIGNAL(requestTimeout()), dlg, SLOT(positionRequestTimeout()));

    if (position.isValid())
      dlg->positionUpdated(position);
  }
#endif
  showAndDelete(dlg);
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
    connect(localisation, SIGNAL(positionUpdated(QGeoPositionInfo)), map, SLOT(positionUpdated(QGeoPositionInfo)));

    if (position.isValid()) {
      zoom = 0;
      map->positionUpdated(position);
    }
  }
#endif
  if (zoom)
    map->centerView(pt, zoom);
  map->positionUpdated(position);
  showAndDelete(map);
}

void
MainWindow::bookmarks()
{
  if (!plugin) {
    chooseStationsPlugin();
    return ;
  }

  BookmarkListDialog *dlg = new BookmarkListDialog(plugin, this);

#ifdef HAVE_QT_LOCATION
  if (localisation) {
    connect(localisation, SIGNAL(positionUpdated(QGeoPositionInfo)), dlg, SLOT(positionUpdated(QGeoPositionInfo)));
    connect(localisation, SIGNAL(requestTimeout()), dlg, SLOT(positionRequestTimeout()));

    if (position.isValid())
      dlg->positionUpdated(position);
  }
#endif
  showAndDelete(dlg);
}

void
MainWindow::chooseStationsPlugin()
{
  QMessageBox::warning(this, tr("Please set Location."),
		       tr("We can't guess your current location, "
			  "please choose one in the list."));
  stationsComboBox->showPopup();
}
