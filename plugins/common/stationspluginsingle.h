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

#ifndef STATIONS_SINGLE_H
#define STATIONS_SINGLE_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QMap>

#include "stationspluginsimple.h"

class Station;

class StationsPluginSingle : public StationsPluginSimple
{
  Q_OBJECT
 public:
  StationsPluginSingle(QObject *parent);
  virtual ~StationsPluginSingle();

  void updateCached(Station *station);
  void updateCached(const QList < Station * > & stations);


 public slots:
  virtual void update(Station *station);
  virtual void update(const QList < Station * > & station);

 protected:
  virtual QUrl statusUrl(int id);

  virtual void handleInfos(const QByteArray & data) = 0;
  virtual void handleStatus(const QByteArray & data, int id);
};

#endif /* STATIONS_SINGLE_H */
