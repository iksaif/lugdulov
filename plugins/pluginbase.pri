include (../lugdulov.pri)

INCLUDEPATH += ../../qmake/ ../common/

!CONFIG(android): DESTDIR = ../../lib/

TEMPLATE = lib
CONFIG += qt plugin

win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release
TARGET = $${TARGET}

LIBS += -llugdulov_base -lqjson

unix {
    LIBS += -L../common/
}
win32 {
    CONFIG(debug, debug|release) {
        LIBS += -L../common/debug/
    } else {
        LIBS += -L../common/release
    }
}

wince*:LIBS += $$QMAKE_LIBS_GUI

contains(LUGDULOV_CONFIG, staticplugins) {
   CONFIG += staticlib
}

symbian: {
    TARGET.EPOCALLOWDLLDATA=1
    TARGET.CAPABILITY = All -Tcb
    TARGET = $${TARGET}
    load(armcc_warnings)
}
