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

#ifndef MAINWINDOW_H
# define MAINWINDOW_H

#include <QtGui/QProgressBar>
#include <QtGui/QMainWindow>

#ifdef Q_WS_MAEMO_5
#include <QtMaemo5/QMaemo5InformationBox>
#endif

#include "mobility.h"

class Ui_MainWindow;
class StationsPluginManager;
class StationsPlugin;
class Station;
class QProgressBar;

class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

 private:
  void createActions();
  void createButton();

 private slots:
  void delayedInit();
  void updatePlugin();

  void about();
  void aboutQt();

  void search(bool bookmarks = false);
  void map();
  void bookmarks();

  void settings();

  void buttonClicked();
  void setStationsPlugin(StationsPlugin *plugin, bool save = false);

  void progress(qint64 done, qint64 total);

#ifdef Q_WS_MAEMO_5
  void statusMsg(const QString & msg, int timeout = QMaemo5InformationBox::DefaultTimeout);
#else
  void statusMsg(const QString & msg, int timeout = 2000);
#endif

#ifdef HAVE_QT_LOCATION
  void positionUpdated(QGeoPositionInfo info);
  void positionRequestTimeout();
#endif

 private:
  void chooseStationsPlugin();
  void fullUiSetStationPlugin(StationsPlugin *plugin);

 private:
  StationsPluginManager *manager;
  StationsPlugin *plugin;
  QProgressBar *progressBar;
#ifdef HAVE_QT_LOCATION
  QGeoPositionInfoSource *localisation;
  QGeoPositionInfo position;
#endif
  Ui_MainWindow *ui;
};

#endif
