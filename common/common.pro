include (../lugdulov.pri)

INCLUDEPATH += ../qmake/
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
  stationspluginbixi2.cpp \
  stationsplugintransdev.cpp \
  stationspluginbcycle.cpp \
  stationsplugincallabike.cpp \
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
  stationspluginbixi2.h \
  stationsplugintransdev.h \
  stationspluginbcycle.h \
  stationsplugincallabike.h \
  settings.h \
  stationspluginmanager.h \
  stationsmodel.h \
  stationssortfilterproxymodel.h \
  stationspluginfactorysimple.h


contains(LUGDULOV_CONFIG, bearer) {
    SOURCES += onlinestatemanager.cpp
    HEADERS += onlinestatemanager.h
}
