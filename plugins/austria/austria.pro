TARGET  = stationsaustria
include(../pluginbase.pri)

HEADERS += factory.h \
        neusiedler_see.h \
	bregenzerwald.h \
        wien.h

SOURCES += factory.cpp \
        neusiedler_see.cpp \
	bregenzerwald.cpp \
        wien.cpp

RESOURCES += austria.qrc

