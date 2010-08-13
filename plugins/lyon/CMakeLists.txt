project(lyon)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${QJSON_INCLUDE_DIR}
)

set(lyon_SRCS lyon.cpp builtin.cpp)
set(lyon_TRS lugdulov_lyon_fr.ts)
set_source_files_properties(${lyon_TRS} PROPERTIES OUTPUT_LOCATION ${lyon_SOURCE_DIR})

qt4_wrap_cpp(lyon_MOC_SRCS lyon.h)
qt4_add_resources(lyon_RC_SRCS lyon.qrc)

if (Q_WS_MAEMO_5)
  maemo_qt4_add_translation(QM_FILES ${lyon_TRS})
else()
  qt4_add_translation(QM_FILES ${lyon_TRS})
endif()

link_directories(
  ${QT_LIBRARY_DIR}
  ${QJSON_LIBRARY_DIRS}
)

add_plugin(stationslyon ${lyon_SRCS} ${lyon_MOC_SRCS} ${lyon_RC_SRCS})

target_link_libraries(
  stationslyon
  lugdulov_base
  ${QT_LIBRARIES}
  ${QJSON_LIBRARIES}
)
