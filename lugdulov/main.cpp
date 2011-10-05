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

#include <qglobal.h>
#include <QtGui/QApplication>
#include <QtCore/QTranslator>
#include <QtCore/QLibraryInfo>
#include <QtCore/QLocale>
#include <QtCore/QtPlugin>
#include <QtCore/QDir>

#include "config.h"

#include "mainwindow.h"
#include "settings.h"

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
Q_IMPORT_PLUGIN(stationsusa);
Q_IMPORT_PLUGIN(stationsaustralia);
Q_IMPORT_PLUGIN(stationstaiwan);

Q_IMPORT_PLUGIN(qtgeoservices_google);
Q_IMPORT_PLUGIN(qtgeoservices_osm);
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
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
    Q_INIT_RESOURCE(usa);
    Q_INIT_RESOURCE(australia);
    Q_INIT_RESOURCE(turkey);
    Q_INIT_RESOURCE(slovenia);
    Q_INIT_RESOURCE(poland);
    Q_INIT_RESOURCE(taiwan);
#endif
    Q_INIT_RESOURCE(i18n);
    Q_INIT_RESOURCE(icons);

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
		      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator lugdulovTranslator;
    lugdulovTranslator.load("lugdulov_" + QLocale::system().name(), ":/");
    app.installTranslator(&lugdulovTranslator);

#if defined(LUGDULOV_MEEGO)
    QCoreApplication::setOrganizationName("net.iksaif.lugdulov");
#else
    QCoreApplication::setOrganizationName("Lugdulov");
#endif
    QCoreApplication::setApplicationName("Lugdulov");
    QCoreApplication::setApplicationVersion(LUGDULOV_VERSION);

#if defined(Q_OS_MAC) || defined(Q_OS_WINDOWS) || defined(Q_WS_MAEMO5) || defined(LUGDULOV_MEEGO)
    QDir dir(QApplication::applicationDirPath());
#if defined(Q_OS_MAC) || defined(Q_WS_MAEMO5) || defined(LUGDULOV_MEEGO)
    dir.cdUp();
#endif
    dir.cd("plugins");
    QApplication::setLibraryPaths(QStringList(dir.absolutePath()));
#endif

    Settings::settings();

    MainWindow w;

#ifdef Q_OS_SYMBIAN
    w.showMaximized();
#else
    w.show();
#endif
    return app.exec();
}
