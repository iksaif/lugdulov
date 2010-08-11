TARGET  = stationslyon
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += lyon.h builtin.h
SOURCES += lyon.cpp builtin.cpp
RESOURCES += lyon.qrc

#target.path += $$[LUGDULOV_INSTALL_PLUGINS]
#INSTALLS += target
