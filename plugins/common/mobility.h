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

#ifndef MOBILITY_H
# define MOBILITY_H

#include "config.h"

#ifdef HAVE_QT_LOCATION
/* Can't use QtLocation/ prefix because Maemo installation is crappy */
# ifdef Q_WS_MAEMO_5
#  include <QGeoCoordinate>
#  include <QGeoPositionInfo>
#  include <QGeoPositionInfoSource>
# else
#  include <QtLocation/QGeoCoordinate>
#  include <QtLocation/QGeoPositionInfo>
#  include <QtLocation/QGeoPositionInfoSource>
# endif
#endif

#ifdef HAVE_QT_BEARER
# ifdef Q_WS_MAEMO_5
#  include <QNetworkConfigurationManager>
#  include <QNetworkConfiguration>
#  include <QNetworkSession>
# else
#  include <QtBearer/QNetworkConfigurationManager>
#  include <QtBearer/QNetworkConfiguration>
#  include <QtBearer/QNetworkSession>
# endif
#endif

#if defined(HAVE_QT_LOCATION) || defined(HAVE_QT_BEARER)
using namespace QtMobility;
#endif

#endif
