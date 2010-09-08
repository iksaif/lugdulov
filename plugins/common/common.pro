include (../../lugdulov.pri)

INCLUDEPATH += ../../qmake/
INCLUDEPATH += $$QJSON_INCLUDE_PATH

TEMPLATE = lib

CONFIG += staticlib

TARGET = lugdulov_base

SOURCES = station.cpp stationsplugin.cpp stationsplugincarto.cpp
HEADERS = station.h stationsplugin.h stationsplugincarto.h

