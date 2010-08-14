project(paris)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${QJSON_INCLUDE_DIR}
)

set(paris_SRCS paris.cpp builtin.cpp)
set(paris_TRS lugdulov_paris_fr.ts)
set_source_files_properties(${paris_TRS} PROPERTIES OUTPUT_LOCATION ${paris_SOURCE_DIR})

qt4_wrap_cpp(paris_MOC_SRCS paris.h)
qt4_add_resources(paris_RC_SRCS paris.qrc)

_qt4_add_translation(QM_FILES ${paris_TRS})

add_plugin(stationsparis ${paris_SRCS} ${paris_MOC_SRCS} ${paris_RC_SRCS})

target_link_libraries(
  stationsparis
  lugdulov_base
  ${QT_LIBRARIES}
)
