project(austria)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(austria_SRCS
  factory.cpp
  wien.cpp
)

set(austria_HDRS
  factory.h
  wien.h
)

qt4_wrap_cpp(austria_MOC_SRCS ${austria_HDRS})
qt4_add_resources(austria_RC_SRCS austria.qrc)

add_plugin(stationsaustria ${austria_SRCS} ${austria_MOC_SRCS} ${austria_RC_SRCS})
