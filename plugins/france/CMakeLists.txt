project(france)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${QJSON_INCLUDE_DIR}
)

set(france_SRCS
  factory.cpp
  larochelle.cpp
  lyon.cpp
  orleans.cpp
  rennes.cpp
)

set(france_TRS
  lugdulov_france_fr.ts
)

set(france_HDRS
  factory.h
  larochelle.h
  lyon.h
  orleans.h
  rennes.h
)

set_source_files_properties(${france_TRS} PROPERTIES OUTPUT_LOCATION ${france_SOURCE_DIR})

qt4_wrap_cpp(france_MOC_SRCS ${france_HDRS})

qt4_add_resources(france_RC_SRCS france.qrc)

qt4_add_translation(QM_FILES ${france_TRS})

add_plugin(stationsfrance ${france_SRCS} ${france_MOC_SRCS} ${france_RC_SRCS})
