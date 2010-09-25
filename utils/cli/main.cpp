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

#include <QtCore/QCoreApplication>
#include <QtCore/QtPlugin>

#include "config.h"

#include "cli.h"

#ifdef BUILD_STATIC_PLUGINS
Q_IMPORT_PLUGIN(stationsfrance);
Q_IMPORT_PLUGIN(stationsbelgium);
Q_IMPORT_PLUGIN(stationsireland);
Q_IMPORT_PLUGIN(stationsjapan);
Q_IMPORT_PLUGIN(stationsluxembourg);
Q_IMPORT_PLUGIN(stationsspain);
Q_IMPORT_PLUGIN(stationsgermany);
Q_IMPORT_PLUGIN(stationsunitedkingdom);
Q_IMPORT_PLUGIN(stationscanada);
Q_IMPORT_PLUGIN(stationsswitzerland);
Q_IMPORT_PLUGIN(stationsaustria);
Q_IMPORT_PLUGIN(stationsloweraustria);
Q_IMPORT_PLUGIN(stationslatvia);
Q_IMPORT_PLUGIN(stationsnewzealand);
#endif

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
#ifdef BUILD_STATIC_PLUGINS
    Q_INIT_RESOURCE(france);
    Q_INIT_RESOURCE(belgium);
    Q_INIT_RESOURCE(ireland);
    Q_INIT_RESOURCE(japan);
    Q_INIT_RESOURCE(luxembourg);
    Q_INIT_RESOURCE(spain);
    Q_INIT_RESOURCE(germany);
    Q_INIT_RESOURCE(united_kingdom);
    Q_INIT_RESOURCE(canada);
    Q_INIT_RESOURCE(switzerland);
    Q_INIT_RESOURCE(austria);
    Q_INIT_RESOURCE(lower_austria);
    Q_INIT_RESOURCE(latvia);
    Q_INIT_RESOURCE(new_zealand);
#endif

    QCoreApplication::setOrganizationName("Lugdulov");
    QCoreApplication::setApplicationName("Lugdulov");
    QCoreApplication::setApplicationVersion(LUGDULOV_VERSION);

    Cli cli;
    return app.exec();
}
