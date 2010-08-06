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

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QMap>

#include "stationsplugin.h"

class Station;
class StationsPluginFactoryLyon : public QObject, public StationsPluginFactory
{
  Q_OBJECT
  Q_INTERFACES(StationsPluginFactory)
 public:
  QString id() const;
  QString name() const;
  QIcon icon() const;
  QList < StationsPlugin * > stations(QObject * parent);
};

class StationsPluginLyon : public StationsPlugin
{
  Q_OBJECT
 private:
  struct Request {
    enum Type { Null = 0, Properties, Status } type;
    int id;
    QString region;
  };

 public:
  StationsPluginLyon(QObject *parent);
  ~StationsPluginLyon();

  QString id() const;
  QString name() const;
  QString bikeName() const;
  QIcon bikeIcon() const;
  bool intersect(const QPointF &pos);

  QUrl stationImageUrl(int id);
  QStringList regions();

  enum StationsLyonActions {
    ActionVelovMap = 1,
  };

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
  QUrl stationJsonUrl(int id);
  QUrl stationsJsonUrl(const QString &region);
  QUrl stationsJsonUrl(const QPointF &pos, int num = 5);
  QUrl stationStatusUrl(int id);

  void fetch(int id);
  void fetchStatus(int id);
  void fetch(const QString & region);

  void request(const QUrl & url, Request::Type type, int id = -1,
	       const QString & region = QString());
  void handleProperties(const QByteArray & data, Request req);
  void handleStatus(const QByteArray & data, Request req);

 private:
  QNetworkAccessManager *nm;

  QMap < int , Station * > stations;
  QMap < QNetworkReply *, Request > replies;
  int step;
  int count;

  static const QString baseUrl;
};

#endif /* STATIONS_LYON_H */
