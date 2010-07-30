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

#include <QtCore/QUrl>
#include <QtGui/QIcon>

class Station;

class StationsPlugin : public QObject
{
  Q_OBJECT

 public:
  StationsPlugin(QObject *parent);
  virtual ~StationsPlugin();

  virtual QString name() const = 0;
  virtual QString bikeName() const = 0;
  virtual QIcon bikeIcon() const = 0;
  virtual bool intersect(const QPointF & pos) = 0;

  virtual QStringList regions() = 0;
  virtual QUrl stationImageUrl(int id) = 0;

 public slots:
  virtual void fetchAll() = 0;
  virtual void fetchOnline() = 0;
  virtual void fetchPos(const QPointF & pos, int num = 5) = 0;
  virtual void fetchFromFile(const QString & file) = 0;
  virtual void fetchFromUrl(const QUrl & url) = 0;
  virtual void update(Station *station) = 0;
  virtual void update(QList < Station * > station) = 0;

 signals:
  void started();
  void progress(qint64 done, qint64 total);
  void done();

  void stationsUpdated(QList < Station * > stations, bool nearest);
  void stationUpdated(Station *station, bool nearest);
  void statusUpdated(Station *station);
  void error(const QString & title, const QString & message);
};

class StationsPluginFactory {
 public:
  virtual ~StationsPluginFactory() {}

  virtual QString id() const = 0;
  virtual QString name() const = 0;
  virtual QIcon icon() const = 0;
  virtual QList < StationsPlugin * > stations(QObject * parent) = 0;
};

Q_DECLARE_INTERFACE(StationsPluginFactory,
		    "net.iksaif.lugdulov.StationsPluginFactoryInterface/1.0")

#endif /* STATIONS_H */
