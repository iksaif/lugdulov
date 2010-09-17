TARGET  = stationsfrance
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h \
  aixenprovence.h \
  amiens.h \
  besancon.h \
  cergypontoise.h \
  creteil.h \
  lyon.h \
  marseille.h \
  mulhouse.h \
  nancy.h \
  nantes.h \
  paris.h \
  plainecommune.h \
  rouen.h \
  toulouse.h \
  caen.h \
  dijon.h \
  perpignan.h \
  larochelle.h \
  bordeaux.h \
  pau.h \
  vannes.h \
  orleans.h \
  avignon.h \
  rennes.h \
  calais.h \
  nice.h

SOURCES += factory.cpp \
  aixenprovence.cpp \
  amiens.cpp \
  besancon.cpp \
  cergypontoise.cpp \
  creteil.cpp \
  lyon.cpp \
  marseille.cpp \
  mulhouse.cpp \
  nancy.cpp \
  nantes.cpp \
  paris.cpp \
  plainecommune.cpp \
  rouen.cpp \
  toulouse.cpp \
  caen.cpp \
  dijon.cpp \
  perpignan.cpp \
  larochelle.cpp \
  bordeaux.cpp \
  pau.cpp \
  vannes.cpp \
  orleans.cpp \
  avignon.cpp \
  rennes.cpp \
  calais.cpp \
  nice.cpp

RESOURCES += france.qrc

TRANSLATIONS = lugdulov_france_fr.ts

#target.path += $$[LUGDULOV_INSTALL_PLUGINS]
#INSTALLS += target
