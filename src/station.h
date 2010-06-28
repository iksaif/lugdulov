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

#ifndef STATION_H
#define STATION_H

#include <QtCore/QUrl>
#include <QtCore/QStringList>
#include <QtCore/QPointF>

class Station
{
 public:
  Station();
  ~Station();

  bool isValid();

  int id();
  QString name();
  QString description();
  QString region();
  QPointF pos();
  int bikes();
  int freeSlots();
  int totalSlots();
  int ticket();

  void setId(int id);
  void setName(const QString & name);
  void setDescription(const QString & description);
  void setRegion(const QString & region);
  void setPos(const QPointF & pos);
  void setBikes(int bikes);
  void setFreeSlots(int freeSlots);
  void setTotalSlots(int totalSlots);
  void setTicket(int ticket);

  static QUrl stationJsonUrl(int id);
  static QUrl stationsJsonUrl(const QString &region);
  static QUrl stationStatusUrl(int id);
  static QUrl stationImageUrl(int id);
  static QStringList regions();

 private:
  void setStatus(const QString & xml);
  void setProperties(const QString & json);

  int id_;
  QString name_;
  QString description_;
  QString region_;
  QPointF pos_;
  int bikes_;
  int freeSlots_;
  int totalSlots_;
  int ticket_;
};

#endif /* STATION_H */
