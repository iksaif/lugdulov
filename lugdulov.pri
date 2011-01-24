isEmpty(PREFIX) {
  PREFIX = /usr/local/
}

BINDIR = $${PREFIX}/bin
LIBDIR = $${PREFIX}/lib


VERSION = 0.4.0
LUGDULOV_CONFIG = bearer location qmapcontrol
LUGDULOV_INSTALL_PLUGINS = $${LIBDIR}/lugdulov

CONFIG += qt thread mobility

contains(LUGDULOV_CONFIG, location) {
   MOBILITY += location
}

QT_VERSION = $$[QT_VERSION]
QT_VERSION = $$split(QT_VERSION, ".")
QT_VER_MAJ = $$member(QT_VERSION, 0)
QT_VER_MIN = $$member(QT_VERSION, 1)

contains(LUGDULOV_CONFIG, location) {
    lessThan(QT_VER_MAJ, 4) | lessThan(QT_VER_MIN, 7) {
        MOBILITY += bearer
    }
}

QT += gui xml network

maemo5: {
        DEFINES += Q_WS_MAEMO_5
}

symbian: {
    QJSON_INCLUDE_PATH = "C:\NokiaQtSDK\Symbian\SDK\epoc32\include\qjson"
    DEFINES += BUILD_STATIC_PLUGINS=1
    DEFINES += LUGDULOV_VERSION=\"\\\"$${VERSION}\\\"\"
}

!symbian: {
    win32 {
        QJSON_INCLUDE_PATH = "C:\\Program Files\\qjson\\include"
        LIBS += -L"C:\\Program Files\\qjson\\lib"
    }
    unix {
        QJSON_INCLUDE_PATH = "/usr/include/qjson/"
    }
    DEFINES += LUGDULOV_VERSION=\\\"$${VERSION}\\\"
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
} else {
contains(LUGDULOV_CONFIG, qmapcontrol) {
  DEFINES += USE_QMAPCONTROL=1
}
}

