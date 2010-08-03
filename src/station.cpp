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

#ifdef HAVE_QT_LOCATION
#include "mobility.h"
#else
#include <cmath>
#endif

#include "station.h"

Station::Station(StationsPlugin *plugin)
  : plugin_(plugin)
{
  id_ = -1;
  bikes_ = freeSlots_ = ticket_ = totalSlots_ = -1;
}

Station::~Station()
{
}

StationsPlugin *
Station::plugin()
{
  return plugin_;
}

bool
Station::isValid() const
{
  return id_ != -1;
}

int
Station::id() const
{
  return id_;
}

QString
Station::name() const
{
  return name_;
}

QString
Station::description() const
{
  return description_;
}

QString
Station::region() const
{
  return region_;
}

QPointF
Station::pos() const
{
  return pos_;
}

int
Station::bikes() const
{
  return bikes_;
}

int
Station::freeSlots() const
{
  return freeSlots_;
}

int
Station::totalSlots() const
{
  return totalSlots_;
}

int
Station::ticket() const
{
  return ticket_;
}

#ifdef HAVE_QT_LOCATION
qreal
Station::distanceTo(const QPointF & a) const
{
  const QPointF & b = pos_;
  QGeoCoordinate ga(a.x(), a.y());
  QGeoCoordinate gb(b.x(), b.y());

  return ga.distanceTo(gb);
}
#else
qreal
Station::distanceTo(const QPointF & a) const
{
  const QPointF & b = pos_;
  const qreal R = 6371; // km
  qreal dLat = (b.x() - a.x()) * M_PI / 180;
  qreal dLon = (b.y() - a.y()) * M_PI / 180;
  qreal e = sin(dLat/2) * sin(dLat/2) +
    cos(a.x() * M_PI / 180) * cos(b.x() * M_PI / 180) *
    sin(dLon/2) * sin(dLon/2);
  qreal c = 2 * atan2(sqrt(e), sqrt(1-e));

  return R * c;
}
#endif

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
