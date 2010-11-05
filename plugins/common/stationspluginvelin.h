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

#ifndef STATIONS_VELIN_H
#define STATIONS_VELIN_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QMap>

#include "stationspluginsingle.h"

class Station;

class StationsPluginVelIn : public StationsPluginSingle
{
  Q_OBJECT
 public:
  StationsPluginVelIn(QObject *parent = NULL);
  virtual ~StationsPluginVelIn();

 protected:
  virtual QUrl infosUrl(void);

  virtual void handleInfos(const QByteArray & data);
  virtual void handleStatus(const QByteArray & data, int id);

 private:
  enum { HomePage = 1, FormPage = 2, MapPage = 3 } Page;

  void forgeUrl();

  QUrl forgedUrl;
  QUrl baseUrl;
};

#endif /* STATIONS_VELIN_H */
