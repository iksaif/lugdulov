TEMPLATE = app

QT += gui \
    xml \
    network

TARGET = lugdulov

DESTDIR = ../bin

include(../lugdulov.pri)

INCLUDEPATH += ../qmake/ \
    ../plugins/common/ \
    ../qmapcontrol/

LIBS += -L../plugins/common/ \
    -llugdulov_base \
    -L../qmapcontrol/ \
    -lqmapcontrol \
    -lqjson

HEADERS += mainwindow.h \
    settings.h \
    stationdialog.h \
    stationspluginmanager.h \
    stationslistdialog.h \
    bookmarklistdialog.h \
    stationdelegate.h \
    stationsmodel.h \
    stationssortfilterproxymodel.h \
    stationslistview.h \
    mapdialog.h \
    mapwidget.h \
    pluginsdialog.h


SOURCES += main.cpp \
    mainwindow.cpp \
    settings.cpp \
    stationdialog.cpp \
    stationspluginmanager.cpp \
    stationslistdialog.cpp \
    bookmarklistdialog.cpp \
    stationdelegate.cpp \
    stationsmodel.cpp \
    stationssortfilterproxymodel.cpp \
    stationslistview.cpp \
    mapdialog.cpp \
    mapwidget.cpp \
    pluginsdialog.cpp

TRANSLATIONS = i18n/lugdulov_fr.ts

symbian: {
    TARGET.EPOCALLOWDLLDATA = 1
    TARGET.CAPABILITY = ReadDeviceData \
        WriteDeviceData
    LugdulovDeployment.sources = $${TARGET}.exe
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
    pluginsdialog.ui

RESOURCES += res/lugdulov.qrc \
    i18n/i18n.qrc
