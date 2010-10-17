isEmpty(PREFIX) {
  PREFIX = /usr/local/
}

BINDIR = $${PREFIX}/bin
LIBDIR = $${PREFIX}/lib


VERSION = 0.2.2
LUGDULOV_CONFIG = bearer location
LUGDULOV_INSTALL_PLUGINS = $${LIBDIR}/lugdulov

CONFIG += qt thread mobility
MOBILITY += location

contains($$list($$[QT_VERSION]), 4.6*) {
    MOBILITY += bearer
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
    DEFINES += PLUGINS_INSTALL_DIR=\\\"$${LUGDULOV_INSTALL_PLUGINS}\\\"
}

contains(LUGDULOV_CONFIG, bearer) {
  DEFINES += HAVE_QT_BEARER
  #LIBS += -lQtBearer
}

contains(LUGDULOV_CONFIG, location) {
  DEFINES += HAVE_QT_LOCATION
  #LIBS += -lQtLocation
}


