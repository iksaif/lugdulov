project(switzerland)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(switzerland_SRCS
  factory.cpp
)

set(switzerland_HDRS
  factory.h
)

qt4_wrap_cpp(switzerland_MOC_SRCS ${switzerland_HDRS})
qt4_add_resources(switzerland_RC_SRCS switzerland.qrc)

add_plugin(stationsswitzerland ${switzerland_SRCS} ${switzerland_MOC_SRCS} ${switzerland_RC_SRCS})
