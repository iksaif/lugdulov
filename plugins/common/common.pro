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
  station.cpp \
  settings.cpp \
  stationsmodel.cpp \
  stationssortfilterproxymodel.cpp \
  stationspluginmanager.cpp

HEADERS =  stationsplugin.h \
  stationspluginsimple.h \
  stationspluginsingle.h \
  stationsplugincyclocity.h \
  stationsplugincitybike.h \
  stationspluginnextbike.h \
  stationspluginvelin.h \
  stationsplugindupral.h \
  settings.h \
  stationspluginmanager.h \
  stationsmodel.h \
  stationssortfilterproxymodel.h


