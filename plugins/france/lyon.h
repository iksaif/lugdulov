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

#ifndef STATIONS_LYON_H
#define STATIONS_LYON_H

#include "stationspluginsimple.h"

class Station;

class StationsPluginLyon : public StationsPluginSimple
{
  Q_OBJECT
 public:
  StationsPluginLyon(QObject *parent = NULL);
  ~StationsPluginLyon();

  QUrl imageUrl(int id);

  enum StationsLyonActions {
    ActionVelovMap = 1,
  };

  QList < QAction * > actions();
  void actionTriggered(QAction *action, Station *station, QWidget *parent = 0);

 public slots:
  void fetchOnline();

 private:
  void handleInfos(const QByteArray & data);
  void handleStatus(const QByteArray & data, int id);

  QUrl stationsJsonUrl(const QString &region);
  QUrl statusUrl(int id);
  QStringList regions();

  static const QString baseUrl;
};

#endif /* STATIONS_LYON_H */
