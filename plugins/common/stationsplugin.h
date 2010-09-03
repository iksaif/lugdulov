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

#include <QtCore/QTime>
#include <QtCore/QUrl>
#include <QtGui/QIcon>
#include <QtGui/QAction>

class Station;

class StationsPlugin : public QObject
{
 Q_OBJECT

public:
  StationsPlugin(QObject *parent);
  virtual ~StationsPlugin();

  /**
   * Unique identifier (used for settings)
   */
  virtual QString id() const = 0;

  /**
   * Name of this plugin
   */
  virtual QString name() const = 0;

  /**
   * Bikes names (Velo'V, Velib, etc...)
   */
  virtual QString bikeName() const = 0;

  /**
   * Return an icon for bikes
   */
  virtual QIcon bikeIcon() const = 0;

  /**
   * Return the rect handled by this plugin
   */
  virtual QRectF rect() const = 0;

  /**
   * Returns the center of the city
   */
  virtual QPointF center() const = 0;

  /**
   * List of all regions
   */
  virtual QStringList regions() = 0;

  /**
   * Return an image url for a given station id
   */
  virtual QUrl imageUrl(int id) = 0;

  /**
   * Returns all custom actions for that plugin
   */
  virtual QList < QAction * > actions() = 0;

  /**
   * Execute the associated action for that action
   */
  virtual void actionTriggered(QAction *action, Station *station,
			       QWidget *parent = 0) = 0;

 public slots:
  /**
   * emit stationsCreated() for each available stations
   */
  virtual void fetchAll() = 0;

  /**
   * emit stationsCreated() for each available stations using
   * online content only (not required)
   */
  virtual void fetchOnline() = 0;

  /**
   * emit stationsCreated() for each available stations using
   * a file (not required)
   */
  virtual void fetchFromFile(const QString & file) = 0;

  /**
   * emit stationsCreated() for each available stations using
   * an URL (not required)
   */
  virtual void fetchFromUrl(const QUrl & url) = 0;

  /**
   * Update the status of this/these station(s) (slots, bike)
   * and emit stationsUpdated()
   */
  virtual void update(Station *station) = 0;
  virtual void update(const QList < Station * > & station) = 0;

  virtual void updateCached(Station *station);
  virtual void updateCached(const QList < Station * > & station);
  virtual void clearCache();

 signals:
  /**
   * emited when the plugin is doing some online stuff (fetching
   * stations updates, etc....)
   * @sa done
   */
  void started();

  /**
   * emited to report progress of a long task
   * @sa started
   * @sa done
   */
  void progress(qint64 done, qint64 total);

  /**
   * emited when the plugin is done with a task
   * @sa started
   */
  void done();

  /**
   * emited by fetch*() functions
   */
  void stationsCreated(const QList < Station * > & stations);

  /**
   * emited by update() functions
   */
  void stationsUpdated(const QList < Station * > & stations);

  /**
   * emited when an error occured
   */
  void error(const QString & title, const QString & message);

 protected:
  QMap < Station * , QTime > updated;
};

/**
 * Each *.so / *.dll plugin provides a StationsPluginFactory
 * This factory holds all StationsPlugins embedded in that *.so / *.dll
 */
class StationsPluginFactory {
 public:
  virtual ~StationsPluginFactory() {}

  /**
   * Return an unique identifier
   */
  virtual QString id() const = 0;

  /**
   * Return the name of this plugin factory
   */
  virtual QString name() const = 0;

  /**
   * Returns an icon for this plugin factory
   */
  virtual QIcon icon() const = 0;

  /**
   * Returns all the plugins in this factory
   */
  virtual QList < StationsPlugin * > stations(QObject * parent) = 0;
};

Q_DECLARE_INTERFACE(StationsPluginFactory,
		    "net.iksaif.lugdulov.StationsPluginFactoryInterface/1.0")

#endif /* STATIONS_H */
