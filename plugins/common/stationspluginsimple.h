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

#ifndef STATIONS_SIMPLE_H
#define STATIONS_SIMPLE_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QMap>

#include "stationsplugin.h"

class Station;
class StationsPluginSimplePrivate;

class StationsPluginSimple : public StationsPlugin
{
  Q_OBJECT
 public:
  StationsPluginSimple(QObject *parent);
  virtual ~StationsPluginSimple();

  virtual QRectF rect() const;
  virtual QPointF center() const;

  virtual QUrl imageUrl(int id);
  virtual QStringList regions();

  virtual QList < QAction * > actions();
  virtual void actionTriggered(QAction *action, Station *station, QWidget *parent = 0);

 public slots:
  virtual void fetchOnline();
  virtual void fetchAll();
  virtual void fetchFromFile(const QString & file);
  virtual void fetchFromUrl(const QUrl & url);
  virtual void update(Station *station);
  virtual void update(const QList < Station * > & station);

 private slots:
  virtual void networkError(QNetworkReply::NetworkError code);
  void ignoreSslErros(QNetworkReply *rep, const QList<QSslError> &errors);
  virtual void finished();

 protected:
  virtual QUrl infosUrl();
  virtual QUrl statusUrl(int id);

  virtual void handleInfos(const QByteArray & data) = 0;
  virtual void handleStatus(const QByteArray & data, int id) = 0;

  StationsPluginSimplePrivate *d;

  QMap < int , Station * > stations;

 private:
  virtual void request(const QUrl & url, int id = -1);

  QNetworkAccessManager *nm;
  QMap < QNetworkReply *, int > replies;
  int step;
  int count;
};

#endif /* STATIONS_SIMPLE_H */
