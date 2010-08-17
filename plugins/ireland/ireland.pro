TARGET  = stationsireland
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h \
        bruxelles.h

SOURCES += factory.cpp \
        bruxelles.cpp

RESOURCES += ireland.qrc

