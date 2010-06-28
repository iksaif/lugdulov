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

#ifndef STATIONS_H
#define STATIONS_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QMap>

class Station;

class Stations : public QObject
{
  Q_OBJECT
 private:
  struct Request {
    enum Type { Null = 0, Properties, Status } type;
    int id;
    QString region;
  };

 public:
  Stations(QObject *parent);
  ~Stations();

 public slots:
  void fetchBuiltIn();
  void fetchPos(const QPointF & pos, int num = 5);
  void fetchAll();
  void fetchFromFile(const QString & file);
  void fetchFromUrl(const QUrl & url);
  void update(Station *station);

 private slots:
  void error(QNetworkReply::NetworkError code);
  void finished();

 signals:
  void started();
  void progress(qint64 done, qint64 total);
  void done();

  void stationsUpdated(QList < Station * > stations);
  void stationUpdated(Station *station);
  void statusUpdated(Station *station);
  void error(const QString & title, const QString & message);

 private:
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
};

#endif /* STATIONS_H */
