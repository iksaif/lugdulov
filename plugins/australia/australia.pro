TARGET  = stationsaustralia
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h melbourne.h

SOURCES += factory.cpp melbourne.cpp

RESOURCES += australia.qrc

