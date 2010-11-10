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

#ifndef STATIONSLISTDIALOG_H
# define STATIONSLISTDIALOG_H

#include <QtCore/QTimer>
#include <QtGui/QDialog>

#include "mobility.h"

class StationsModel;
class StationsPlugin;
class Station;
class StationsSortFilterProxyModel;
class StationsView;
class Ui_StationsListDialog;

class StationsListDialog : public QDialog
{
  Q_OBJECT

 public:
  StationsListDialog(StationsPlugin *plugin, QWidget *parent = 0);
  ~StationsListDialog();

#ifdef HAVE_QT_LOCATION
 public slots:
  void positionUpdated(QGeoPositionInfo info);
  void positionRequestTimeout();
#endif

 private:
  void setupListWidget();

 private slots:
  void filterEdited(const QString & text);
  void filter(void);
  void progress(qint64 done, qint64 total);
  void error(const QString & title, const QString & message);

 protected:
  StationsSortFilterProxyModel *proxy;

 private:
  StationsPlugin *plugin;
  StationsModel *model;
  StationsView *view;
#ifdef HAVE_QT_LOCATION
  QGeoPositionInfo position;
#endif
  QTimer filterTimer;
  Ui_StationsListDialog *ui;
};

#endif
