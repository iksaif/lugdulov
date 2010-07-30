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

#ifndef STATIONDIALOG_H
# define STATIONDIALOG_H

#include "config.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include "ui_stationdialog.h"

class StationsPlugin;
class Station;

class StationDialog : public QDialog, private Ui_StationDialog
{
  Q_OBJECT

public:
  StationDialog(StationsPlugin *stations, Station *station,
		QWidget * parent = 0);
  ~StationDialog();

private:
  void fetchImage();
  void setupWidgets();
  void setupButtons();

private slots:
  void bookmark(bool checked);

  void requestError(QNetworkReply::NetworkError code);
  void requestFinished();
  void orientationChanged();

private:
  Station *station;
  StationsPlugin *stations;
  QNetworkAccessManager *nm;
};

#endif /* STATIONDIALOG_H */
