TARGET  = stationstaiwan
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h taipei.h

SOURCES += factory.cpp taipei.cpp

RESOURCES += taiwan.qrc

