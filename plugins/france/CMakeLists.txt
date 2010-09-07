project(france)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${QJSON_INCLUDE_DIR}
)

set(france_SRCS
  factory.cpp
  lyon.cpp
# cyclocity
  aixenprovence.cpp
  amiens.cpp
  besancon.cpp
  cergypontoise.cpp
  creteil.cpp
  marseille.cpp
  mulhouse.cpp
  nancy.cpp
  nantes.cpp
  paris.cpp
  plainecommune.cpp
  rouen.cpp
  toulouse.cpp
# citybike
  caen.cpp
  dijon.cpp
  perpignan.cpp
# other
  larochelle.cpp
)

set(france_TRS
  lugdulov_france_fr.ts)

set(france_HDRS
  factory.h
  lyon.h
  aixenprovence.h
  amiens.h
  besancon.h
  cergypontoise.h
  creteil.h
  marseille.h
  mulhouse.h
  nancy.h
  nantes.h
  paris.h
  plainecommune.h
  rouen.h
  toulouse.h
  caen.h
  dijon.h
  perpignan.h
  larochelle.h
)

set_source_files_properties(${france_TRS} PROPERTIES OUTPUT_LOCATION ${france_SOURCE_DIR})

qt4_wrap_cpp(france_MOC_SRCS ${france_HDRS})

qt4_add_resources(france_RC_SRCS france.qrc)

_qt4_add_translation(QM_FILES ${france_TRS})

link_directories(
  ${QT_LIBRARY_DIR}
  ${QJSON_LIBRARY_DIRS}
)

add_plugin(stationsfrance ${france_SRCS} ${france_MOC_SRCS} ${france_RC_SRCS})

target_link_libraries(
  stationsfrance
  lugdulov_base
  ${QT_LIBRARIES}
  ${QJSON_LIBRARIES}
)
