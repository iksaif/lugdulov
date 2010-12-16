project(ireland)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(ireland_SRCS
  factory.cpp
)

set(ireland_HDRS
  factory.h
)

qt4_wrap_cpp(ireland_MOC_SRCS ${ireland_HDRS})
qt4_add_resources(ireland_RC_SRCS ireland.qrc)

add_plugin(stationsireland ${ireland_SRCS} ${ireland_MOC_SRCS} ${ireland_RC_SRCS})
