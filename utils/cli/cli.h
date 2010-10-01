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

#ifndef CLI_H
# define CLI_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QTimer>
#include <QtCore/QVariant>

#include <QCommandLine>

class StationsPluginManager;
class StationsPlugin;
class Station;

class Cli : public QObject
{
  Q_OBJECT
 public:
  Cli(QObject *parent = NULL);
  ~Cli();

 private slots:
  void run();
  void parseError(const QString & name);
  void switchFound(const QString & name);
  void optionFound(const QString & name, const QVariant & value);
  void paramFound(const QString & name, const QVariant & value);

  void stationsCreated(const QList < Station *> & stations);
  void stationsUpdated(const QList < Station *> & stations);
  void stationsError();

  void infosFinished();

 private:
  void list();
  void infos();
  void serialize(const QVariant & out);

  StationsPluginManager *manager;

  QCommandLine *cmdline;
  enum Action { List, Infos } action;
  enum Format { Xml, Json } format;
  QStringList plugins;

  QMap < StationsPlugin *, bool > working;
  QMap < StationsPlugin *, QList < Station * > > stations;
  QMap < StationsPlugin *, QMap < Station * , bool > >  updated;
};

#endif
