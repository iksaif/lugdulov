project(lugdulov_core)

# Include the library include directories, and the current build directory (moc)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${qmapcontrol_SOURCE_DIR}
  ${QT_INCLUDE_DIR}
)

if (QT_MOBILITY_FOUND)
  include_directories(${QT_MOBILITY_INCLUDE_DIR})
  link_directories(${QT_MOBILITY_LIBRARY_DIR})
endif()

set(lugdulov_SRCS
  main.cpp
  mainwindow.cpp
  stationdialog.cpp
  stationslistdialog.cpp
  stationslistwidget.cpp
  stationdelegate.cpp
  stationslistview.cpp
  pluginsdialog.cpp
  aboutdialog.cpp
  settingsdialog.cpp
  mapdialog.cpp)

set(lugdulov_UIS
  mainwindow.ui
  fullwindow.ui
  stationdialog.ui
  stationslistdialog.ui
  stationslistwidget.ui
  pluginsdialog.ui
  aboutdialog.ui
  settingsdialog.ui
  mapdialog.ui)

set(lugdulov_MOC_HDRS
  mainwindow.h
  stationdialog.h
  stationslistdialog.h
  stationslistwidget.h
  stationdelegate.h
  stationslistview.h
  pluginsdialog.h
  aboutdialog.h
  settingsdialog.h
  mapdialog.h)

if(LUGDULOV_LITE)
    set(lugdulov_SRCS ${lugdulov_SRCS} mapwidget_lite.cpp)
    set(lugdulov_MOC_HDRS ${lugdulov_MOC_HDRS} mapwidget_lite.h)
else()
  if (QMAPCONTROL)
    set(lugdulov_SRCS ${lugdulov_SRCS} mapwidget_qmapcontrol.cpp)
    set(lugdulov_MOC_HDRS ${lugdulov_MOC_HDRS} mapwidget_qmapcontrol.h)
  else()
    set(lugdulov_SRCS ${lugdulov_SRCS} mapwidget_qtm.cpp mapgraphicswidget_qtm.cpp)
    set(lugdulov_MOC_HDRS ${lugdulov_MOC_HDRS} mapwidget_qtm.h mapgraphicswidget_qtm.h)
  endif()
endif()

set(lugdulov_RCS res/lugdulov.qrc i18n/i18n.qrc)
set(lugdulov_TRS
  i18n/lugdulov_fr.ts
  i18n/lugdulov_cs.ts
)
set_source_files_properties(${lugdulov_TRS} PROPERTIES OUTPUT_LOCATION ${lugdulov_core_SOURCE_DIR}/i18n)

_qt4_add_translation(QM_FILES ${lugdulov_TRS})
qt4_wrap_cpp(MOC_SOURCE ${lugdulov_MOC_HDRS})
qt4_wrap_ui(UI_HDRS ${lugdulov_UIS})
qt4_add_resources(RC_SRCS ${lugdulov_RCS})

if (WIN32)
 set(GUI_TYPE WIN32)
 add_custom_command( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/icon.o
                     COMMAND windres.exe -I${CMAKE_CURRENT_SOURCE_DIR} -i${CMAKE_CURRENT_SOURCE_DIR}/lugdulov.rc
                     -o ${CMAKE_CURRENT_BINARY_DIR}/icon.o )
 set(lugdulov_SRCS ${lugdulov_SRCS} ${CMAKE_CURRENT_BINARY_DIR}/icon.o)
endif ()

link_directories(
  ${QT_LIBRARY_DIR}
  ${QJSON_LIBRARY_DIRS}
)

add_executable(
  lugdulov
  ${GUI_TYPE}
  ${lugdulov_SRCS}
  ${UI_HDRS}
  ${MOC_SOURCE}
  ${RC_SRCS}
  ${QM_FILES}
)

if (QT_MOBILITY_LOCATION_FOUND)
  target_link_libraries(lugdulov ${QT_MOBILITY_LOCATION_LIBRARY})
endif ()

if (QT_LOCATION_BEARER_FOUND)
  target_link_libraries(lugdulov ${QT_LOCATION_BEARER_LIBRARY})
endif ()

if (Q_WS_MAEMO_5)
  target_link_libraries(lugdulov QtMaemo5)
endif()

if (BUILD_STATIC_PLUGINS)
  target_link_libraries(lugdulov stationsfrance)
  target_link_libraries(lugdulov stationsbelgium)
  target_link_libraries(lugdulov stationsireland)
  target_link_libraries(lugdulov stationsjapan)
  target_link_libraries(lugdulov stationsluxembourg)
  target_link_libraries(lugdulov stationsspain)
  target_link_libraries(lugdulov stationsgermany)
  target_link_libraries(lugdulov stationsunited-kingdom)
  target_link_libraries(lugdulov stationscanada)
  target_link_libraries(lugdulov stationsswitzerland)
  target_link_libraries(lugdulov stationsaustria)
  target_link_libraries(lugdulov stationslower-austria)
  target_link_libraries(lugdulov stationslatvia)
  target_link_libraries(lugdulov stationsnew-zealand)
  target_link_libraries(lugdulov stationsusa)
  target_link_libraries(lugdulov stationsaustralia)
endif ()

target_link_libraries(
  lugdulov
  lugdulov_base
  ${QT_LIBRARIES}
)

if (QMAPCONTROL)
  target_link_libraries(lugdulov qmapcontrol)
endif()

install(TARGETS lugdulov
  RUNTIME DESTINATION ${BIN_INSTALL_DIR}
)

