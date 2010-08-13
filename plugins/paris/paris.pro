TARGET  = stationsparis
include(../pluginbase.pri)

HEADERS += paris.h builtin.h
SOURCES += paris.cpp builtin.cpp
RESOURCES += paris.qrc

TRANSLATIONS = lugdulov_paris_fr.ts

#target.path += $$[LUGDULOV_INSTALL_PLUGINS]
#INSTALLS += target
