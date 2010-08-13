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

#include <QtGui/QApplication>
#include <QtCore/QTranslator>
#include <QtCore/QLibraryInfo>
#include <QtCore/QtPlugin>

#include "config.h"

#include "mainwindow.h"
#include "settings.h"

#ifdef BUILD_STATIC_PLUGINS
Q_IMPORT_PLUGIN(stationslyon);
Q_IMPORT_PLUGIN(stationsparis);
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
#ifdef BUILD_STATIC_PLUGINS
    Q_INIT_RESOURCE(lyon);
    Q_INIT_RESOURCE(paris);
#endif

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
		      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator lugdulovTranslator;
    qDebug() << lugdulovTranslator.load("lugdulov_" + QLocale::system().name(), ":/");
    app.installTranslator(&lugdulovTranslator);

    QCoreApplication::setOrganizationName("Lugdulov");
    QCoreApplication::setApplicationName("Lugdulov");
    QCoreApplication::setApplicationVersion(LUGDULOV_VERSION);

    Settings::settings();

    MainWindow w;
    w.show();
    return app.exec();
}
