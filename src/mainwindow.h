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

#ifndef MAINWINDOW_H
# define MAINWINDOW_H

#include <QtGui/QProgressBar>

#ifdef HAVE_QT_LOCATION
#include <QtLocation/QGeoCoordinate>
#include <QtLocation/QGeoPositionInfo>
#include <QtLocation/QGeoPositionInfoSource>
#endif

#include "ui_mainwindow.h"

class Stations;
class Station;

class MainWindow : public QMainWindow, private Ui_MainWindow
{
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

 private:
  void createStations();
  void createActions();
  void createStatusBar();
  void setupTreeWidget();
  void fetchStations();

 private slots:
  void about();
  void velov();
  void aboutQt();

  void error(const QString & title, const QString & message);
  void started();
  void progress(qint64 done, qint64 total);
  void done();

#ifdef HAVE_QT_LOCATION
  void positionUpdated(QtMobility::QGeoPositionInfo info);
  void requestTimeout();
#endif

 private:
  Stations *stations;
  QProgressBar *updateBar;
#ifdef HAVE_QT_LOCATION
  QtMobility::QGeoPositionInfoSource *localisation;
  QtMobility::QGeoPositionInfo position;
#endif
};

#endif
