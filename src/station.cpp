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

#include "station.h"

Station::Station()
{
  id_ = -1;
  distance_ = bikes_ = freeSlots_ = ticket_ = totalSlots_ = -1;
}

Station::~Station()
{
}

bool
Station::isValid()
{
  return id_ != -1;
}

int
Station::id()
{
  return id_;
}

QString
Station::name()
{
  return name_;
}

QString
Station::description()
{
  return description_;
}

QString
Station::region()
{
  return region_;
}

QPointF
Station::pos()
{
  return pos_;
}

double
Station::distance()
{
  return distance_;
}

int
Station::bikes()
{
  return bikes_;
}

int
Station::freeSlots()
{
  return freeSlots_;
}

int
Station::totalSlots()
{
  return totalSlots_;
}

int
Station::ticket()
{
  return ticket_;
}

void
Station::setId(int id)
{
  id_ = id;
}

void
Station::setName(const QString & name)
{
  name_ = name;
}

void
Station::setDescription(const QString & description)
{
  description_ = description;
}

void
Station::setRegion(const QString & region)
{
  region_ = region;
}

void
Station::setPos(const QPointF & pos)
{
  pos_ = pos;
}

void
Station::setDistance(double distance)
{
  distance_ = distance;
}

void
Station::setBikes(int bikes)
{
  bikes_ = bikes;
}

void
Station::setFreeSlots(int freeSlots)
{
  freeSlots_ = freeSlots;
}

void
Station::setTotalSlots(int totalSlots)
{
  totalSlots_ = totalSlots;
}

void
Station::setTicket(int ticket)
{
  ticket_ = ticket;
}

QUrl
Station::stationJsonUrl(int id)
{
  return QString("http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParId.php?gid=%1").arg(id);
}

QUrl
Station::stationsJsonUrl(const QString &region)
{
  return QString("http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParArrondissement.php?arrondissement=%1").arg(region);
}

QUrl
Station::stationStatusUrl(int id)
{
  return QString("http://www.velov.grandlyon.com/velovmap/zhp/inc/DispoStationsParId.php?id=%1").arg(id);
}

QUrl
Station::stationImageUrl(int id)
{
  return QString("http://www.velov.grandlyon.com/uploads/tx_gsstationsvelov/%1.jpg").arg(id);
}

QUrl
Station::stationsJsonUrl(const QPointF &pos, int num)
{
  return QString("http://www.velov.grandlyon.com/velovmap/zhp/inc/StationsParCoord.php?lat=%1&long=%2&nombreStation=%3").arg(pos.x()).arg(pos.y()).arg(num);
}

QStringList
Station::regions()
{
  QStringList reg;

  reg << "69381";
  reg << "69382";
  reg << "69383";
  reg << "69384";
  reg << "69385";
  reg << "69386";
  reg << "69387";
  reg << "69388";
  reg << "69389";
  reg << "69266";
  reg << "69034";
  reg << "69256";
  return reg;
}
