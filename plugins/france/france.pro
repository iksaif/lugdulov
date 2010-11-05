TARGET  = stationsfrance
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h \
  larochelle.h \
  lyon.h \
  orleans.h \
  rennes.h \
  avignon.h \

SOURCES += factory.cpp \
  larochelle.cpp \
  lyon.cpp \
  orleans.cpp \
  rennes.cpp \
  avignon.cpp \

RESOURCES += france.qrc

TRANSLATIONS = lugdulov_france_fr.ts

#target.path += $$[LUGDULOV_INSTALL_PLUGINS]
#INSTALLS += target
