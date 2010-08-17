TARGET  = stationsspain
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h \
        seville.h \
        santander.h

SOURCES += factory.cpp \
        seville.cpp \
        santander.cpp

RESOURCES += spain.qrc

