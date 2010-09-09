project(united-kingdom)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${QJSON_INCLUDE_DIR}
)

set(united-kingdom_SRCS
  factory.cpp
  cardiff.cpp
  reading.cpp
  london.cpp
)

set(united-kingdom_HDRS
  factory.h
  reading.h
  cardiff.h
  london.h
)

qt4_wrap_cpp(united-kingdom_MOC_SRCS ${united-kingdom_HDRS})
qt4_add_resources(united-kingdom_RC_SRCS united-kingdom.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
  ${QJSON_LIBRARY_DIRS}
)

add_plugin(stationsunited-kingdom ${united-kingdom_SRCS} ${united-kingdom_MOC_SRCS} ${united-kingdom_RC_SRCS})

target_link_libraries(
  stationsunited-kingdom
  lugdulov_base
  ${QT_LIBRARIES}
  ${QJSON_LIBRARIES}
)
