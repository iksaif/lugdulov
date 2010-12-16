project(germany)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(germany_SRCS
  factory.cpp
)

set(germany_HDRS
  factory.h
)

qt4_wrap_cpp(germany_MOC_SRCS ${germany_HDRS})
qt4_add_resources(germany_RC_SRCS germany.qrc)

add_plugin(stationsgermany ${germany_SRCS} ${germany_MOC_SRCS} ${germany_RC_SRCS})
