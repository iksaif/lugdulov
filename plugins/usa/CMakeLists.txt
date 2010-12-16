project(usa)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(usa_SRCS
  factory.cpp
)

set(usa_HDRS
  factory.h
)

qt4_wrap_cpp(usa_MOC_SRCS ${usa_HDRS})
qt4_add_resources(usa_RC_SRCS usa.qrc)

add_plugin(stationsusa ${usa_SRCS} ${usa_MOC_SRCS} ${usa_RC_SRCS})
