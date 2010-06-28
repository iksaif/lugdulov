# Use it
set(QT_USE_QTGUI TRUE)
set(QT_USE_QTNETWORK TRUE)
set(QT_USE_QTXML TRUE)
set(QT_USE_QTSQL TRUE)

INCLUDE( ${QT_USE_FILE} )

# Include the library include directories, and the current build directory (moc)
INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	${quickvelov_BINARY_DIR}
	${QJSON_INCLUDE_DIR}
)

LINK_DIRECTORIES(
	${QJSON_LIBRARY_DIRS}
)

SET(quickvelov_SRCS
  main.cpp
  mainwindow.cpp
  maintreewidget.cpp
  stations.cpp
  stationsbuiltin.cpp
  station.cpp)

SET(quickvelov_UIS
  mainwindow.ui)

SET(quickvelov_MOC_HDRS
  mainwindow.h
  maintreewidget.h
  stations.h)

SET(quickvelov_RCS ../res/quickvelov.qrc)

QT4_WRAP_CPP(MOC_SOURCE ${quickvelov_MOC_HDRS})
QT4_WRAP_UI(UI_HDRS ${quickvelov_UIS})
QT4_ADD_RESOURCES(RC_SRCS ${quickvelov_RCS})

ADD_EXECUTABLE(
	quickvelov
	${quickvelov_SRCS}
	${UI_HDRS}
	${MOC_SOURCE}
	${RC_SRCS}
)

TARGET_LINK_LIBRARIES(
	quickvelov
	${QT_LIBRARIES}
	${QJSON_LIBRARIES}
)

install(TARGETS quickvelov
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
)
