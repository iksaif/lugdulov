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

#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QtGui/QLabel>
#include <QtCore/QTimer>
#include <QtCore/QMap>

#include "mobility.h"

class StationsPlugin;
class Station;

class MapWidget : public QLabel
{
  Q_OBJECT
 public:
  MapWidget(QWidget * parent = 0);
  ~MapWidget();

  void setPlugin(StationsPlugin *p);

 public slots:
  void centerOnStation(Station *station);
  void centerView(const QPointF & position, int zoom = -1);
#ifdef HAVE_QT_LOCATION
  void positionUpdated(const QGeoPositionInfo & info);
#endif

 signals:
  void centerChanged(const QPointF & position);
};

#endif
