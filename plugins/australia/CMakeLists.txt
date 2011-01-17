project(australia)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(australia_SRCS
  factory.cpp
  melbourne.cpp
)

set(australia_HDRS
  factory.h
  melbourne.h
)

qt4_wrap_cpp(australia_MOC_SRCS ${australia_HDRS})
qt4_add_resources(australia_RC_SRCS australia.qrc)

add_plugin(stationsaustralia ${australia_SRCS} ${australia_MOC_SRCS} ${australia_RC_SRCS})
