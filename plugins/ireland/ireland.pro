TARGET  = stationsireland
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h \
        dublin.h

SOURCES += factory.cpp \
        dublin.cpp

RESOURCES += ireland.qrc

