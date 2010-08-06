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

#ifndef STATIONS_PARIS_H
#define STATIONS_PARIS_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QMap>

#include "stationsplugin.h"

class Station;
class StationsPluginFactoryParis : public QObject, public StationsPluginFactory
{
  Q_OBJECT
  Q_INTERFACES(StationsPluginFactory)
 public:
  QString id() const;
  QString name() const;
  QIcon icon() const;
  QList < StationsPlugin * > stations(QObject * parent);
};

class StationsPluginParis : public StationsPlugin
{
  Q_OBJECT
 private:
 public:
  StationsPluginParis(QObject *parent);
  ~StationsPluginParis();

  QString id() const;
  QString name() const;
  QString bikeName() const;
  QIcon bikeIcon() const;
  bool intersect(const QPointF &pos);

  QUrl stationImageUrl(int id);
  QStringList regions();

  QList < QAction * > actions();
  void actionTriggered(QAction *action, Station *station, QWidget *parent = 0);

 public slots:
  void fetchOnline();
  void fetchPos(const QPointF & pos, int num = 5);
  void fetchAll();
  void fetchFromFile(const QString & file);
  void fetchFromUrl(const QUrl & url);
  void update(Station *station);
  void update(QList < Station * > station);

 private slots:
  void error(QNetworkReply::NetworkError code);
  void finished();

 signals:
  void started();
  void progress(qint64 done, qint64 total);
  void done();

  void stationsCreated(QList < Station * > stations);
  void stationsUpdated(QList < Station * > stations);

  void error(const QString & title, const QString & message);

 private:
  QUrl stationStatusUrl(int id);
  QUrl stationCartoUrl();


  void request(const QUrl & url, int id = -1);
  void handleStatus(const QByteArray & data, int id);

 private:
  QNetworkAccessManager *nm;

  QMap < int , Station * > stations;
  QMap < QNetworkReply *, int > replies;
  int step;
  int count;
};

#endif /* STATIONS_PARIS_H */
