isEmpty(PREFIX) {
  PREFIX = /usr/local/
}

BINDIR = $${PREFIX}/bin
LIBDIR = $${PREFIX}/lib


VERSION = 0.2.2
LUGDULOV_CONFIG = bearer location
LUGDULOV_INSTALL_PLUGINS = $${LIBDIR}/lugdulov

QJSON_INCLUDE_PATH = "/usr/include/qjson/"

maemo5: {
	DEFINES += Q_WS_MAEMO_5
}

CONFIG += create_prl release qt thread

DEFINES += LUGDULOV_VERSION=\\\"$${VERSION}\\\"
DEFINES += PLUGINS_INSTALL_DIR=\\\"$${LUGDULOV_INSTALL_PLUGINS}\\\"

contains(LUGDULOV_CONFIG, bearer) {
  DEFINES += HAVE_QT_BEARER
  LIBS += -lQtBearer
}

contains(LUGDULOV_CONFIG, location) {
  DEFINES += HAVE_QT_LOCATION
  LIBS += -lQtLocation
}


