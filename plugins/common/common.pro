include (../../lugdulov.pri)

INCLUDEPATH += ../../qmake/

TEMPLATE = lib

CONFIG += staticlib

TARGET = lugdulov_base

SOURCES = station.cpp stationsplugin.cpp
HEADERS = station.h stationsplugin.h

