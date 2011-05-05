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

#ifndef STATIONS_PLUGIN_FACTORY_H
#define STATIONS_PLUGIN_FACTORY_H

#include <QtGui/QIcon>

#include "stationsplugin.h"

/**
 * Each *.so / *.dll plugin provides a StationsPluginFactory
 * This factory holds all StationsPlugins embedded in that *.so / *.dll
 */
class StationsPluginFactory {
 public:
  virtual ~StationsPluginFactory() {}

  /**
   * Must be called once before using the factory
   */
  virtual void init() = 0;
	
  /**
   * Return an unique identifier
   */
  virtual QString id() const = 0;

  /**
   * Return the name of this plugin factory
   */
  virtual QString name() const = 0;

  /**
   * Return the description of this plugin factory
   */
  virtual QString description() const = 0;

  /**
   * Returns an icon for this plugin factory
   */
  virtual QIcon icon() const = 0;

  /**
   * Returns all the plugins in this factory
   */
  virtual QList < StationsPlugin * > plugins(void) = 0;

  /**
   * Return a plugin matching this name
   */
  virtual StationsPlugin *plugin(const QString & id) = 0;

  /**
   * Return a plugin matching this position
   */
  virtual StationsPlugin *plugin(const QPointF & pt) = 0;
};

Q_DECLARE_INTERFACE(StationsPluginFactory,
		    "net.iksaif.lugdulov.StationsPluginFactoryInterface/3.0")

#endif /* STATIONS_PLUGIN_FACTORY_H */
