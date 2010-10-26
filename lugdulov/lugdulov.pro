TEMPLATE = app

QT += gui \
    xml \
    network

TARGET = lugdulov
ICON = lugdulov.svg

DESTDIR = ../bin

include(../lugdulov.pri)

INCLUDEPATH += ../qmake/ \
    ../plugins/common/ \
    ../qmapcontrol/

LIBS +=  -lqjson \
    -llugdulov_base \
    -lqmapcontrol

unix {
    suffix = ""
}
win32 {
    CONFIG(debug, debug|release) {
      suffix = debug
    } else {
      suffix = release
    }
}

LIBS += -L../plugins/common/$${suffix}
LIBS += -L../qmapcontrol/$${suffix}

HEADERS += mainwindow.h \
    stationdialog.h \
    stationslistdialog.h \
    bookmarklistdialog.h \
    stationdelegate.h \
    stationslistview.h \
    mapdialog.h \
    mapwidget.h \
    pluginsdialog.h \
    aboutdialog.h

SOURCES += main.cpp \
    mainwindow.cpp \
    stationdialog.cpp \
    stationslistdialog.cpp \
    bookmarklistdialog.cpp \
    stationdelegate.cpp \
    stationslistview.cpp \
    mapdialog.cpp \
    mapwidget.cpp \
    pluginsdialog.cpp \
    aboutdialog.cpp

TRANSLATIONS = i18n/lugdulov_fr.ts

symbian: {
    LIBS += -lstationsfrance -lstationsbelgium -lstationsireland -lstationsluxembourg
    LIBS += -lstationsspain -lstationsjapan -lstationsaustria -lstationsgermany -lstationslatvia -lstationslower_austria
    LIBS += -lstationsnew_zealand -lstationsswitzerland -lstationsunited_kingdom -lstationscanada

    TARGET.EPOCALLOWDLLDATA = 1
    TARGET.CAPABILITY = ReadUserData UserEnvironment NetworkServices Location

#ReadDeviceData \
#        WriteDeviceData

    vendorinfo = \
    "%{\"Corentin Chary - iksaif.net \"}" \
    ":\"Corentin Chary - iksaif.net \""

    LugdulovDeployment.pkg_prerules = vendorinfo
    #LugdulovDeployment.sources = $(EPOCROOT)\\epoc32\\release\\$(PLATFORM)\\lugdulov.exe
    #LugdulovDeployment.sources = $${TARGET}.exe
    LugdulovDeployment.path = /sys/bin

    DEPLOYMENT += LugdulovDeployment
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
    mapdialog.ui \
    pluginsdialog.ui \
    aboutdialog.ui

RESOURCES += res/lugdulov.qrc \
    i18n/i18n.qrc
