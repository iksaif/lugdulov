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

#ifndef STATIONS_CARTO_H
#define STATIONS_CARTO_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QMap>

#include "stationsplugin.h"

class Station;
class StationsPluginCartoPrivate;

class StationsPluginCarto : public StationsPlugin
{
  Q_OBJECT
 private:
 public:
  StationsPluginCarto(QObject *parent);
  virtual ~StationsPluginCarto();

  virtual QRectF rect() const;
  virtual QPointF center() const;

  virtual QUrl stationImageUrl(int id);
  virtual QStringList regions();

  virtual QList < QAction * > actions();
  virtual void actionTriggered(QAction *action, Station *station, QWidget *parent = 0);

 public slots:
  virtual void fetchOnline();
  virtual void fetchPos(const QPointF & pos, int num = 5);
  virtual void fetchAll();
  virtual void fetchFromFile(const QString & file);
  virtual void fetchFromUrl(const QUrl & url);
  virtual void update(Station *station);
  virtual void update(const QList < Station * > & station);

 private slots:
  virtual void error(QNetworkReply::NetworkError code);
  virtual void finished();

 signals:
  void started();
  void progress(qint64 done, qint64 total);
  void done();

  void stationsCreated(QList < Station * > stations);
  void stationsUpdated(QList < Station * > stations);

  void error(const QString & title, const QString & message);

 protected:
  virtual QUrl stationStatusUrl(int id);
  virtual QUrl stationCartoUrl();


  void request(const QUrl & url, int id = -1);
  void handleStatus(const QByteArray & data, int id);

  StationsPluginCartoPrivate *d;

 private:
  QNetworkAccessManager *nm;

  QMap < int , Station * > stations;
  QMap < QNetworkReply *, int > replies;
  int step;
  int count;
};

#endif /* STATIONS_CARTO_H */
