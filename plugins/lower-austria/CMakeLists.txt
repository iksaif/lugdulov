project(lower-austria)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(lower-austria_SRCS
  factory.cpp
)

set(lower-austria_HDRS
  factory.h
)

qt4_wrap_cpp(lower-austria_MOC_SRCS ${lower-austria_HDRS})
qt4_add_resources(lower-austria_RC_SRCS lower-austria.qrc)

add_plugin(stationslower-austria ${lower-austria_SRCS} ${lower-austria_MOC_SRCS} ${lower-austria_RC_SRCS})
