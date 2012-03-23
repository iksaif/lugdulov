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

#ifdef HAVE_APPUP_SDK
//Header for Intel AppUp(TM) software
#include "adpcppf.h"
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
Q_IMPORT_PLUGIN(stationsslovenia);
Q_IMPORT_PLUGIN(stationsturkey);
Q_IMPORT_PLUGIN(stationspoland);
Q_IMPORT_PLUGIN(stationstaiwan);

Q_IMPORT_PLUGIN(qtgeoservices_google);
Q_IMPORT_PLUGIN(qtgeoservices_osm);
#endif

static void init_ressources()
{
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
}
static void init_translations(QApplication *app)
{
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
		      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app->installTranslator(&qtTranslator);

    QTranslator lugdulovTranslator;
    lugdulovTranslator.load("lugdulov_" + QLocale::system().name(), ":/");
    app->installTranslator(&lugdulovTranslator);
}

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
}
#ifdef HAVE_APPUP_SDK
static Application *appupApp = NULL;

static void clear_appup()
{
	//Cleanup code for Intel AppUp(TM) software
	if (appupApp != NULL)
		delete appupApp;
	appupApp = NULL;
}

static bool init_appup()
{
	//Authorization code for Intel AppUp(TM) software	
	try {
#ifdef _DEBUG
		appupApp = new Application(ApplicationId(ADP_DEBUG_APPLICATIONID));
#else
		appupApp = new Application(ApplicationId(0x8967B317, 0x8ABB492C, 0x831882D0, 0x42A04973));
#endif
	} catch (AdpException& e) {
			MessageBoxA(0, e.what(), "AppUp error", MB_ICONERROR|MB_OK);
			clear_appup();
			return false;
	}
	return true;
}
#else
static bool init_appup()
{
	return true;
}
static void clear_appup()
{
}
#endif


int main(int argc, char *argv[])
{
	if (!init_appup())
		return EXIT_FAILURE;

#if defined(LUGDULOV_MEEGO)
    QCoreApplication::setOrganizationName("net.iksaif.lugdulov");
#else
    QCoreApplication::setOrganizationName("Lugdulov");
#endif
    QCoreApplication::setApplicationName("Lugdulov");
    QCoreApplication::setApplicationVersion(LUGDULOV_VERSION);

	QApplication app(argc, argv);

	init_ressources();
	init_translations(&app);
	init_libraries();

    Settings::settings();
    MainWindow w;

#ifdef Q_OS_SYMBIAN
    w.showMaximized();
#else
    w.show();
#endif

    int ret = app.exec();
    clear_appup();
    return ret;
}
