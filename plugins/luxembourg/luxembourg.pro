TARGET  = stationsluxembourg
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h \
        luxembourg.h

SOURCES += factory.cpp \
        luxembourg.cpp

RESOURCES += luxembourg.qrc

