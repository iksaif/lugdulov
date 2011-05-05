isEmpty(PREFIX) {
  PREFIX = /usr/local/
}

BINDIR = $${PREFIX}/bin
LIBDIR = $${PREFIX}/lib

VERSION = 0.5.0
LUGDULOV_INSTALL_PLUGINS = $${LIBDIR}/lugdulov

CONFIG(android): LUGDULOV_CONFIG = qmapcontrol staticplugins
else:symbian: LUGDULOV_CONFIG = bearer location qmapcontrol staticplugins debug
else: LUGDULOV_CONFIG = bearer location qmapcontrol

CONFIG += qt thread

contains(LUGDULOV_CONFIG, location) {
   CONFIG += mobility
   MOBILITY += location
}

QT_VERSION = $$[QT_VERSION]
QT_VERSION = $$split(QT_VERSION, ".")
QT_VER_MAJ = $$member(QT_VERSION, 0)
QT_VER_MIN = $$member(QT_VERSION, 1)

contains(LUGDULOV_CONFIG, bearer) {
    lessThan(QT_VER_MAJ, 4) | lessThan(QT_VER_MIN, 7) {
        MOBILITY += bearer
    }
}

QT += gui xml network

# Add missing Q_WS_MAEMO_5
maemo5: {
        DEFINES += Q_WS_MAEMO_5
}

# Version
symbian: DEFINES += LUGDULOV_VERSION=\"\\\"$${VERSION}\\\"\"
else: DEFINES += LUGDULOV_VERSION=\\\"$${VERSION}\\\"

# Plugins
contains(LUGDULOV_CONFIG, staticplugins) {
    DEFINES += BUILD_STATIC_PLUGINS=1
}

# QJson
symbian {
    QJSON_INCLUDE_PATH = "C:\\NokiaQtSDK\\Symbian\\SDK\\epoc32\\include\\qjson"
} else:win32 {
    QJSON_INCLUDE_PATH = "C:\\Program Files\\qjson\\include"
    LIBS += -L"C:\\Program Files\\qjson\\lib"
} else:CONFIG(android) {
    # You'll need to install libqjson.a somewhete and setup
    # these paths
    #QJSON_INCLUDE_PATH = -I$[QT_INSTALL_HEADERS]
    #LIBS += -L$[QT_INSTALL_LIBS]
} else {
    QJSON_INCLUDE_PATH = "/usr/include/qjson/"
}

contains(LUGDULOV_CONFIG, bearer) {
  DEFINES += HAVE_QT_BEARER
  #LIBS += -lQtBearer
}

contains(LUGDULOV_CONFIG, location) {
  DEFINES += HAVE_QT_LOCATION
  #LIBS += -lQtLocation
}

contains(LUGDULOV_CONFIG, lite) {
  DEFINES += LUGDULOV_LITE=1
} else:contains(LUGDULOV_CONFIG, qmapcontrol) {
  DEFINES += USE_QMAPCONTROL=1
}


