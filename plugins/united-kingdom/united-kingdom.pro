TARGET  = stationsunited-kingdom
include(../pluginbase.pri)

HEADERS += factory.h \
        reading.h \
	cardiff.h \
        london.h

SOURCES += factory.cpp \
        cardiff.cpp \
	reading.cpp \
        london.cpp

RESOURCES += united-kingdom.qrc

