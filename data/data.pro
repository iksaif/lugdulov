include (../lugdulov.pri)

INCLUDEPATH += ../qmake/

TEMPLATE = lib

CONFIG += staticlib

TARGET = lugdulov_data

TRANSLATIONS = i18n/lugdulov_fr.ts i18n/lugdulov_cs.ts

OTHER_FILES += icons/velov.png \
    icons/slot.png \
    icons/icon.png \
    icons/google-maps.png \
    icons/favorites.png \
    icons/bike.png \
    icons/view-refresh.png \
    icons/zoom-out.png \
    icons/zoom-in.png \
    icons/slot.png \
    icons/map.png \
    icons/icon64.png \
    icons/icon.png \
    icons/gps.png \
    icons/google-maps.png \
    icons/favorites.png \
    icons/circle.png \
    icons/bike.png

RESOURCES += icons/icons.qrc \
    i18n/i18n.qrc
