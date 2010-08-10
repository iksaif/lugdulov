# Use it
set(QT_USE_QTGUI TRUE)
set(QT_USE_QTNETWORK TRUE)
set(QT_USE_QTXML TRUE)
set(QT_USE_QTSQL TRUE)

include( ${QT_USE_FILE} )

# Include the library include directories, and the current build directory (moc)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/plugins
  ${CMAKE_CURRENT_SOURCE_DIR}/qmapcontrol
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_BINARY_DIR}
  ${QJSON_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)

link_directories(
  ${QJSON_LIBRARY_DIRS}
)

set(lugdulov_SRCS
  main.cpp
  mainwindow.cpp
  settings.cpp
  stationdialog.cpp
  stationspluginmanager.cpp
  stationslistdialog.cpp
  bookmarklistdialog.cpp
  stationdelegate.cpp
  stationsmodel.cpp
  stationssortfilterproxymodel.cpp
  stationslistview.cpp
  mapdialog.cpp
  mapwidget.cpp)

set(lugdulov_UIS
  mainwindow.ui
  stationdialog.ui
  stationslistdialog.ui
  mapdialog.ui)

set(lugdulov_MOC_HDRS
  mainwindow.h
  settings.h
  stationdialog.h
  stationspluginmanager.h
  stationslistdialog.h
  bookmarklistdialog.h
  stationdelegate.h
  stationsmodel.h
  stationssortfilterproxymodel.h
  stationslistview.h
  mapdialog.h
  mapwidget.h)

set(lugdulov_RCS ../res/lugdulov.qrc ../i18n/i18n.qrc)
set(lugdulov_TRS ../i18n/lugdulov_fr.ts)
set_source_files_properties(${lugdulov_TRS} PROPERTIES OUTPUT_LOCATION ${lugdulov_SOURCE_DIR}/i18n)

if (Q_WS_MAEMO_5)
  maemo_qt4_add_translation(QM_FILES ${lugdulov_TRS})
else()
  qt4_add_translation(QM_FILES ${lugdulov_TRS})
endif()

qt4_wrap_cpp(MOC_SOURCE ${lugdulov_MOC_HDRS})
qt4_wrap_ui(UI_HDRS ${lugdulov_UIS})
qt4_add_resources(RC_SRCS ${lugdulov_RCS})

add_executable(
  lugdulov
  ${lugdulov_SRCS}
  ${UI_HDRS}
  ${MOC_SOURCE}
  ${RC_SRCS}
  ${QM_FILES}
)

add_subdirectory(plugins)
add_subdirectory(qmapcontrol)

if (QTLOCATION_FOUND)
  include_directories(${QTLOCATION_INCLUDE_DIR})
  link_directories(${QTLOCATION_LIBRARY_DIRS})
  target_link_libraries(lugdulov ${QTLOCATION_LIBRARIES})
endif ()

if (QTBEARER_FOUND)
  include_directories(${QTBEARER_INCLUDE_DIR})
  link_directories(${QTBEARER_LIBRARY_DIRS})
  target_link_libraries(lugdulov ${QTBEARER_LIBRARIES})
endif ()

if (Q_WS_MAEMO_5)
  target_link_libraries(lugdulov QtMaemo5)
endif()

if (BUILD_STATIC_PLUGINS)
  target_link_libraries(lugdulov stationslyon)
  target_link_libraries(lugdulov stationsparis)
endif ()

target_link_libraries(
  lugdulov
  lugdulov_base
  qmapcontrol
  ${QT_LIBRARIES}
  ${QJSON_LIBRARIES}
)

install(TARGETS lugdulov
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
)
