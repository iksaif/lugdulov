TARGET  = stationsfrance
include(../pluginbase.pri)

INCLUDEPATH += $$QJSON_INCLUDE_PATH

HEADERS += factory.h lyon.h paris.h \
        cergypontoise.h

SOURCES += factory.cpp lyon.cpp lyon_p.cpp paris.cpp \
        cergypontoise.cpp

RESOURCES += france.qrc

TRANSLATIONS = lugdulov_france_fr.ts

#target.path += $$[LUGDULOV_INSTALL_PLUGINS]
#INSTALLS += target
