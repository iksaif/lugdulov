LUGDULOV_BASE = ..
LUGDULOV_SRCBASE = .
TEMPLATE = lib
QT -= gui
TARGET = lugdulov
DESTDIR = $$LUGDULOV_BASE/bin
CONFIG += create_prl
VERSION = 0.0.1
LUGDULOV_CPP = $$LUGDULOV_SRCBASE
INCLUDEPATH += $$LUGDULOV_CPP
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

TRANSLATIONS = lugdulov_fr.ts

symbian: { 
    TARGET.EPOCALLOWDLLDATA = 1
    
    # uid for the dll
    # TARGET.UID3=
    TARGET.CAPABILITY = ReadDeviceData \
        WriteDeviceData
    
    # add dll to the sis
    LugdulovDeployment.sources = $${TARGET}.exe
    LugdulovDeployment.path = /sys/bin
    DEPLOYMENT += LugdulovDeployment
}
OTHER_FILES += *ui \
    ../res/stations.json \
    ../res/velov.png \
    ../res/slot.png \
    ../res/icon.png \
    ../res/google-maps.png \
    ../res/favorites.png \
    ../res/bike.png
RESOURCES += ../res/lugdulov.qrc
