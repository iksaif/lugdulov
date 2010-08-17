include (../../lugdulov.pri)

INCLUDEPATH += ../../qmake/

TEMPLATE = lib

CONFIG += staticlib

TARGET = lugdulov_base

SOURCES = station.cpp stationsplugin.cpp stationsplugincarto.cpp
HEADERS = station.h stationsplugin.h stationsplugincarto.h

