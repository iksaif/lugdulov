project(lugdulov_qml)

# Include the library include directories, and the current build directory (moc)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${qmapcontrol_SOURCE_DIR}
  ${QT_INCLUDE_DIR}
)

if (QT_MOBILITY_FOUND)
  include_directories(
    ${QT_MOBILITY_INCLUDE_DIR}
    ${QT_MOBILITY_INCLUDE_DIR}/QtMobility
  )
  link_directories(${QT_MOBILITY_LIBRARY_DIR})
endif()

set(lugdulov_SRCS
  main.cpp
)
set(lugdulov_MOC_HDRS
)

#set(lugdulov_RCS res/lugdulov.qrc i18n/i18n.qrc)
#set(lugdulov_TRS
#  i18n/lugdulov_fr.ts
#  i18n/lugdulov_cs.ts
#)
#set_source_files_properties(${lugdulov_TRS} PROPERTIES OUTPUT_LOCATION ${lugdulov_core_SOURCE_DIR}/i18n)

#_qt4_add_translation(QM_FILES ${lugdulov_TRS})
#qt4_wrap_cpp(MOC_SOURCE ${lugdulov_MOC_HDRS})
#qt4_wrap_ui(UI_HDRS ${lugdulov_UIS})
#qt4_add_resources(RC_SRCS ${lugdulov_RCS})

#if (WIN32)
# if("${CMAKE_BUILD_TYPE}" MATCHES "^Rel.*")
#	set(GUI_TYPE WIN32)
# endif()
# add_custom_command( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/icon.o
#                     COMMAND windres.exe -I${CMAKE_CURRENT_SOURCE_DIR} -i${CMAKE_CURRENT_SOURCE_DIR}/lugdulov.rc
#                     -o ${CMAKE_CURRENT_BINARY_DIR}/icon.o )
# set(lugdulov_SRCS ${lugdulov_SRCS} ${CMAKE_CURRENT_BINARY_DIR}/icon.o)
#endif ()

link_directories(
  ${QT_LIBRARY_DIR}
  ${QJSON_LIBRARY_DIRS}
)

add_executable(
  lugdulov_qml
#  ${GUI_TYPE}
  ${lugdulov_SRCS}
#  ${UI_HDRS}
#  ${MOC_SOURCE}
#  ${RC_SRCS}
#  ${QM_FILES}
)

if (QT_MOBILITY_LOCATION_FOUND)
  target_link_libraries(lugdulov_qml ${QT_MOBILITY_LOCATION_LIBRARY})
endif ()

if (QT_LOCATION_BEARER_FOUND)
  target_link_libraries(lugdulov_qml ${QT_LOCATION_BEARER_LIBRARY})
endif ()

#if (Q_WS_MAEMO_5)
#  target_link_libraries(lugdulov_qml QtMaemo5)
#endif()

if (BUILD_STATIC_PLUGINS)
  target_link_libraries(lugdulov_qml stationsfrance)
  target_link_libraries(lugdulov_qml stationsbelgium)
  target_link_libraries(lugdulov_qml stationsireland)
  target_link_libraries(lugdulov_qml stationsjapan)
  target_link_libraries(lugdulov_qml stationsluxembourg)
  target_link_libraries(lugdulov_qml stationsspain)
  target_link_libraries(lugdulov_qml stationsgermany)
  target_link_libraries(lugdulov_qml stationsunited-kingdom)
  target_link_libraries(lugdulov_qml stationscanada)
  target_link_libraries(lugdulov_qml stationsswitzerland)
  target_link_libraries(lugdulov_qml stationsaustria)
  target_link_libraries(lugdulov_qml stationslower-austria)
  target_link_libraries(lugdulov_qml stationslatvia)
  target_link_libraries(lugdulov_qml stationsnew-zealand)
  target_link_libraries(lugdulov_qml stationsusa)
  target_link_libraries(lugdulov_qml stationsaustralia)
  target_link_libraries(lugdulov_qml stationsturkey)
  target_link_libraries(lugdulov_qml stationsslovenia)
  target_link_libraries(lugdulov_qml stationspoland)
endif ()

target_link_libraries(
  lugdulov_qml
  lugdulov_base
  ${QT_LIBRARIES}
)

install(TARGETS lugdulov_qml
  RUNTIME DESTINATION ${BIN_INSTALL_DIR}
)

