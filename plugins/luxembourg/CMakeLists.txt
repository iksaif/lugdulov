project(luxembourg)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(luxembourg_SRCS
  factory.cpp
)

set(luxembourg_HDRS
  factory.h
)

qt4_wrap_cpp(luxembourg_MOC_SRCS ${luxembourg_HDRS})
qt4_add_resources(luxembourg_RC_SRCS luxembourg.qrc)

add_plugin(stationsluxembourg ${luxembourg_SRCS} ${luxembourg_MOC_SRCS} ${luxembourg_RC_SRCS})
