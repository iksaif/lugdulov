TARGET  = stationslower-austria
include(../pluginbase.pri)

HEADERS += factory.h \
        modling.h \
	baden.h \
	romerland.h \
	wachau.h \
	triestingtal.h \
	st_polten.h \
	wiener_neustadt.h \
	tulln.h \
	wieselburg.h \
	obb_bahnhofe.h

SOURCES += factory.cpp \
        wiener_neustadt.cpp \
	romerland.cpp \
	triestingtal.cpp \
	obb_bahnhofe.cpp \
	wachau.cpp \
	wieselburg.cpp \
	st_polten.cpp \
	baden.cpp \
	modling.cpp \
	tulln.cpp

RESOURCES += lower-austria.qrc

