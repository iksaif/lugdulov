TARGET  = stationsaustria
include(../pluginbase.pri)

HEADERS += factory.h \
        neusiedler_see.h \
	bregenzerwald.h

SOURCES += factory.cpp \
        neusiedler_see.cpp \
	bregenzerwald.cpp

RESOURCES += austria.qrc

