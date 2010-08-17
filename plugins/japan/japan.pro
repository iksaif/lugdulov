TARGET  = stationsjapan
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h \
        toyama.h

SOURCES += factory.cpp \
        toyama.cpp

RESOURCES += japan.qrc

