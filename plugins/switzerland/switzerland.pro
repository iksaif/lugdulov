TARGET  = stationsswitzerland
include(../pluginbase.pri)

HEADERS += factory.h \
        zug.h \
	schupfheim.h \
	schwyz.h \
	luzern.h \
	sempach_station.h \
	hochdorf.h \
	arth_goldau.h \
	stansstad.h \
	sarnen.h \
	kussnacht_am_rigi.h \
	sursee.h \
	bern.h \
	stans.h \
	langenthal.h \
	rotkreuz.h \
	brunnen.h

SOURCES += factory.cpp \
	rotkreuz.cpp \
	sarnen.cpp \
	kussnacht_am_rigi.cpp \
	brunnen.cpp \
	schupfheim.cpp \
	langenthal.cpp \
	sursee.cpp \
	zug.cpp \
	bern.cpp \
	schwyz.cpp \
	luzern.cpp \
	hochdorf.cpp \
	sempach_station.cpp \
	stans.cpp \
	stansstad.cpp \
	arth_goldau.cpp

RESOURCES += switzerland.qrc

