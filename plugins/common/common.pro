include (../../lugdulov.pri)

INCLUDEPATH += ../../qmake/
INCLUDEPATH += $$QJSON_INCLUDE_PATH

TEMPLATE = lib

CONFIG += staticlib

TARGET = lugdulov_base

SOURCES =   tools.cpp \
  stationsplugin.cpp \
  stationspluginsimple.cpp \
  stationspluginsingle.cpp \
  stationsplugincyclocity.cpp \
  stationsplugincitybike.cpp \
  stationspluginnextbike.cpp \
  stationspluginvelin.cpp \
  stationsplugindupral.cpp \
  stationspluginbixi.cpp \
  stationsplugintransdev.cpp \
  stationspluginbcycle.cpp \
  station.cpp \
  settings.cpp \
  stationsmodel.cpp \
  stationssortfilterproxymodel.cpp \
  stationspluginmanager.cpp \
  stationspluginfactorysimple.cpp

HEADERS =  tools.h \
  stationsplugin.h \
  stationspluginsimple.h \
  stationspluginsingle.h \
  stationsplugincyclocity.h \
  stationsplugincitybike.h \
  stationspluginnextbike.h \
  stationspluginvelin.h \
  stationsplugindupral.h \
  stationspluginbixi.h \
  stationsplugintransdev.h \
  stationspluginbcycle.h \
  settings.h \
  stationspluginmanager.h \
  stationsmodel.h \
  stationssortfilterproxymodel.h \
  stationspluginfactorysimple.h


contains(LUGDULOV_CONFIG, bearer) {
    SOURCES += onlinestatemanager.cpp
    HEADERS += onlinestatemanager.h
}
