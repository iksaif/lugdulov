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

#include "settings.h"

static void init_libraries()
{
#if defined(Q_OS_MAC) || defined(Q_OS_WINDOWS) || defined(Q_WS_MAEMO5) || defined(LUGDULOV_MEEGO)
    QDir dir(QApplication::applicationDirPath());
#if defined(Q_OS_MAC) || defined(Q_WS_MAEMO5) || defined(LUGDULOV_MEEGO)
    dir.cdUp();
#endif
    dir.cd("plugins");
    QApplication::setLibraryPaths(QStringList(dir.absolutePath()));
#endif

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

    Q_IMPORT_PLUGIN(qtgeoservices_google);
    Q_IMPORT_PLUGIN(qtgeoservices_osm);
#endif
}

static void init_translations()
{
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
		      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator lugdulovTranslator;
    lugdulovTranslator.load("lugdulov_" + QLocale::system().name(), ":/");
    app.installTranslator(&lugdulovTranslator);
}

int main(int argc, char *argv[])
{
#if defined(LUGDULOV_MEEGO)
    QCoreApplication::setOrganizationName("net.iksaif.lugdulov");
#else
    QCoreApplication::setOrganizationName("Lugdulov");
#endif
    QCoreApplication::setApplicationName("Lugdulov");
    QCoreApplication::setApplicationVersion(LUGDULOV_VERSION);

#ifdef HAVE_MEEGOTOUCH
    QApplication *app = MDeclarativeCache::qApplication(argc, argv);
#else
    QApplication application(argc, argv);
    QApplication *app = &application;
#endif

    init_translations();
    init_libraries();

    Settings *settings = Settings::settings();
    PluginsModel *plugins = PluginsModel();

    qmlRegisterUncreatableType<Settings>("net.iksaif.lugdulov", 1, 0, "Settings");
    qmlRegisterUncreatableType<PluginsModel>("net.iksaif.lugdulov", 1, 0, "PluginsModel", "This object is created in the model.");
    qmlRegisterUncreatableType<StationsModel>("net.iksaif.lugdulov", 1, 0, "StationsModel", "This object is created in the model.");
    qmlRegisterUncreatableType<StationsSortFilterProxyModel>("net.iksaif.lugdulov", 1, 0, "StationsSortFilterModel", "This object is created in the model.");

#ifdef HAVE_MEEGOTOUCH
    QDeclarativeView *view = MDeclarativeCache::qDeclarativeView();
#else
    QDeclarativeView *view = new QDeclarativeView();
#endif

    QObject::connect(view->engine(), SIGNAL(quit()), app, SLOT(quit()));
    view->rootContext()->setContextProperty("plugins", plugins);
    view->rootContext()->setContextProperty("settings", settings);

#ifdef LUGDULOV_PLATFORM_HARMATTAN
    view->setSource(QUrl("qrc:/qml/harmattan/main.qml"));
    view->showFullScreen();
#elif defined(Q_OS_SYMBIAN)
    view->setSource(QUrl("qrc:/qml/symbian/main.qml"));
    view->showFullScreen();
#else
    view->setSource(QUrl("qrc:/qml/generic/main.qml"));
    view->show();
#endif


    int result = app->exec();
    delete view;
    delete app;
    return result;
}
