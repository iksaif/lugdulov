LUGDULOV_BASE = ..
LUGDULOV_SRCBASE = .

TEMPLATE = app

QT += gui xml

TARGET = lugdulov
DESTDIR = $$LUGDULOV_BASE/bin

CONFIG += create_prl

VERSION = 0.1.0

LUGDULOV_CPP = $$LUGDULOV_SRCBASE
INCLUDEPATH += $$LUGDULOV_CPP ../qmake/
LIBS+= -lQtBearer -lQtLocation -lqjson

HEADERS += mainlistwidget.h \
    mainwindow.h \
    settings.h \
    stationdialog.h \
    station.h \
    stationsbuiltin.h \
    stations.h \
    stationwidget.h

SOURCES += main.cpp \
    mainlistwidget.cpp \
    mainwindow.cpp \
    settings.cpp \
    station.cpp \
    stationdialog.cpp \
    stationsbuiltin.cpp \
    stations.cpp \
    stationwidget.cpp

TRANSLATIONS = ../i18n/lugdulov_fr.ts

symbian: {
    TARGET.EPOCALLOWDLLDATA = 1

    TARGET.CAPABILITY = ReadDeviceData \
        WriteDeviceData

    LugdulovDeployment.sources = $${TARGET}.exe
    LugdulovDeployment.path = /sys/bin
    DEPLOYMENT += LugdulovDeployment
}

OTHER_FILES += \
    ../res/stations.json \
    ../res/velov.png \
    ../res/slot.png \
    ../res/icon.png \
    ../res/google-maps.png \
    ../res/favorites.png \
    ../res/bike.png

FORMS += mainwindow.ui stationdialog.ui stationwidget.ui
RESOURCES += ../res/lugdulov.qrc ../i18n/i18n.qrc
