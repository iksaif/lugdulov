include (../lugdulov.pri)

INCLUDEPATH += ../../qmake/ ../common/

DESTDIR = ../../bin/

TEMPLATE = lib
CONFIG += qt plugin

win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release
TARGET = $${TARGET}

LIBS += -L../common/ -llugdulov_base

wince*:LIBS += $$QMAKE_LIBS_GUI

symbian: {
    TARGET.EPOCALLOWDLLDATA=1
    TARGET.CAPABILITY = All -Tcb
    TARGET = $${TARGET}
    load(armcc_warnings)
}
