TEMPLATE = app

QT += gui xml network

include(../lugdulov.pri)

symbian: {
  contains(LUGDULOV_CONFIG, lite) {
	TARGET = LugdulovLite
  } else {
	TARGET = Lugdulov
  }
} else {
  contains(LUGDULOV_CONFIG, lite) {
	TARGET = lugdulov_lite
  } else {
	TARGET = lugdulov
  }
}

ICON = lugdulov.svg

!CONFIG(android): DESTDIR = ../bin

INCLUDEPATH += ../qmake/
INCLUDEPATH += ../plugins/common/

unix {
    suffix = ""
	libsuffix = "" # Not needed
} else: win32 {
    CONFIG(debug, debug|release) {
      suffix = debug
    } else {
      suffix = release
    }
	libsuffix = "" # Not needed
} else: symbian {
	contains(LUGDULOV_CONFIG, staticplugins): libsuffix = ".lib"
	else: libsuffix = ".dll"
}

lessThan(QT_VER_MAJ, 4) | lessThan(QT_VER_MIN, 8) {
	DEFINES += HAVE_KINETIC_SCROLLER_SOLUTION
	INCLUDEPATH += ../kineticscroller/include/
	LIBS += -lQtScroller$${libsuffix}
}

LIBS += -L../plugins/common/$${suffix}

contains(LUGDULOV_CONFIG, staticplugins) {
	!contains(LUGDULOV_CONFIG, qmapcontrol) {
		symbian:LIBS += -lqtgeoservices_google$${libsuffix} -lqtgeoservices_osm$${libsuffix}
	}
    LIBS += -L../lib/
    LIBS += -lstationsfrance$${libsuffix} -lstationsbelgium$${libsuffix} -lstationsireland$${libsuffix} -lstationsluxembourg$${libsuffix}
    LIBS += -lstationsspain$${libsuffix} -lstationsjapan$${libsuffix} -lstationsaustria$${libsuffix} -lstationsgermany -lstationslatvia$${libsuffix}
    LIBS += -lstationsswitzerland$${libsuffix} -lstationscanada$${libsuffix} -lstationsusa$${libsuffix} -lstationsaustralia$${libsuffix}
    LIBS += -lstationsnew-zealand$${libsuffix} -lstationslower-austria$${libsuffix} -lstationsunited-kingdom$${libsuffix}
}

LIBS += -lqjson -llugdulov_base

HEADERS += mainwindow.h \
    stationdialog.h \
    stationslistdialog.h \
    stationslistwidget.h \
    stationdelegate.h \
    stationslistview.h \
    mapdialog.h \
    pluginsdialog.h \
    aboutdialog.h \
    settingsdialog.h

SOURCES += main.cpp \
    mainwindow.cpp \
    stationdialog.cpp \
    stationslistdialog.cpp \
    stationslistwidget.cpp \
    stationdelegate.cpp \
    stationslistview.cpp \
    mapdialog.cpp \
    pluginsdialog.cpp \
    aboutdialog.cpp \
    settingsdialog.cpp

contains(LUGDULOV_CONFIG, lite) {
  SOURCES += mapwidget_lite.cpp
  HEADERS += mapwidget_lite.h
} else: contains(LUGDULOV_CONFIG, qmapcontrol) {
  SOURCES += mapwidget_qmapcontrol.cpp
  HEADERS += mapwidget_qmapcontrol.h
  INCLUDEPATH +=  ../qmapcontrol/
  LIBS += -L../qmapcontrol/$${suffix} -lqmapcontrol
} else {
  SOURCES += mapwidget_qtm.cpp mapgraphicswidget_qtm.cpp
  HEADERS += mapwidget_qtm.h mapgraphicswidget_qtm.h
}

TRANSLATIONS = i18n/lugdulov_fr.ts i18n/lugdulov_cs.ts

symbian: {

    # 0x20036C9F 0xE25eb14f 0x20036CA0 0xE25eb14d
    contains(LUGDULOV_CONFIG, debug) {
        TARGET.UID3 = 0xE25eb20f
    } else {
        contains(LUGDULOV_CONFIG, lite) {
            TARGET.UID3 = 0x20036CA0
        } else {
            TARGET.UID3 = 0x20036C9F
       }
    }

    TARGET.EPOCALLOWDLLDATA = 1
    TARGET.CAPABILITY = ReadUserData UserEnvironment NetworkServices Location

	# Need more RAM for map
	TARGET.EPOCHEAPSIZE = 0x100000 0x2000000

    contains(LUGDULOV_CONFIG, lite) {
        packageheader = "$${LITERAL_HASH}{\"Lugdulo'V Lite\"}, ($${TARGET.UID3}), 0, 4, 1, TYPE=SA"
    } else {
        packageheader = "$${LITERAL_HASH}{\"Lugdulo'V\"}, ($${TARGET.UID3}), 0, 4, 1, TYPE=SA"
    }

    vendorinfo = \
    "%{\"Corentin Chary - iksaif.net \"}" \
    ":\"Corentin Chary - iksaif.net \""

    # Remove all the existing platform dependencies
    default_deployment.pkg_prerules -= pkg_platform_dependencies

    #Add a dependency for just the S60 5th edition (Symbian^1) and later phones
    supported_platforms = \
	"; Application that only supports >= S60 5th edition" \
	#"[0x101F7961],0,0,0,{\"Series603rdProductID\"}" \
	"[0x1028315F],0,0,0,{\"S60ProductID\"}" \
	"[0x20022E6D],0,0,0,{\"S60ProductID\"}"
 
    #LugdulovDeployment.sources = $(EPOCROOT)\\epoc32\\release\\$(PLATFORM)\\lugdulov.exe
    #LugdulovDeployment.sources = $${TARGET}.exe

    LugdulovDeployment.pkg_prerules += packageheader  vendorinfo supported_platforms
    LugdulovDeployment.path = /sys/bin

    DEPLOYMENT += LugdulovDeployment
    contains(LUGDULOV_CONFIG, lite) {
        DEPLOYMENT.installer_header = "$${LITERAL_HASH}{\"Lugdulo'V Lite installer\"},(0x2002CCCF),0,4,1"
    } else {
        DEPLOYMENT.installer_header = "$${LITERAL_HASH}{\"Lugdulo'V installer\"},(0x2002CCCF),0,4,1"
    }
}

OTHER_FILES += res/velov.png \
    res/slot.png \
    res/icon.png \
    res/google-maps.png \
    res/favorites.png \
    res/bike.png \
    res/view-refresh.png \
    res/zoom-out.png \
    res/zoom-in.png \
    res/slot.png \
    res/map.png \
    res/icon64.png \
    res/icon.png \
    res/gps.png \
    res/google-maps.png \
    res/favorites.png \
    res/circle.png \
    res/bike.png

FORMS += mainwindow.ui \
    stationdialog.ui \
    stationslistdialog.ui \
    stationslistwidget.ui \
    mapdialog.ui \
    pluginsdialog.ui \
    aboutdialog.ui \
    settingsdialog.ui

RESOURCES += res/lugdulov.qrc \
    i18n/i18n.qrc
