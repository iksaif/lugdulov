/*
 * Copyright (C) 2010-2011 Corentin Chary <corentin.chary@gmail.com>
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
# define MAPWIDGET_H

#include <QtGui/QGraphicsView>
#include <QtCore/QModelIndex>
#include <QtCore/QTimer>

#include "mobility.h"

class StationsPlugin;
class MapGraphicsWidget;
class StationsModel;
class StationsSortFilterProxyModel;
class StationsPlugin;
class Station;
class QPushButton;

class MapWidget : public QGraphicsView
{
  Q_OBJECT

 public:
  MapWidget(QWidget *parent = 0);
  ~MapWidget();

  void setPlugin(StationsPlugin *p);

 public slots:
  void centerOnStation(Station *station);
  void centerView(const QPointF & position, int zoom = -1);
  void positionUpdated(const QGeoPositionInfo & info);

 signals:
  void centerChanged(const QPointF & position);

 protected:
  virtual void resizeEvent(QResizeEvent* event);
  virtual void showEvent(QShowEvent* event);

 private slots:
  void zoomIn();
  void zoomOut();
  void viewChanged(const QGeoCoordinate & coordinate);
  void refreshStations();
  void refreshStatus();
  void dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
  void mapClicked(const QPointF & pos);
  void objectsClicked(QList < QGeoMapObject * > geom);

 private:
  void createInnerLayout();
  void setProvider(QString providerId);
  void showStation(Station *station);

 private:
  QGeoServiceProvider *serviceProvider;
  QGeoMappingManager *mapManager;

  MapGraphicsWidget *mapWidget;
  StationsPlugin *plugin;

  QGeoMapPixmapObject *positionMarker;

  QMap < QGeoMapObject *, Station * > stations;
  QMap < Station *, QGeoMapObject * > objects;

  QPushButton *follow;
  StationsModel *model;
  StationsSortFilterProxyModel *proxy;

  QTimer *stationsTimer;
  QTimer *statusTimer;
};

#endif
