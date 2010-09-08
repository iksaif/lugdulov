TARGET  = stationsunited-kingdom
include(../pluginbase.pri)

HEADERS += factory.h \
        reading.h \
	cardiff.h

SOURCES += factory.cpp \
        cardiff.cpp \
	reading.cpp

RESOURCES += united-kingdom.qrc

