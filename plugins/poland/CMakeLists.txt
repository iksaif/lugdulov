project(poland)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(poland_SRCS
  factory.cpp
)

set(poland_HDRS
  factory.h
)

qt4_wrap_cpp(poland_MOC_SRCS ${poland_HDRS})
qt4_add_resources(poland_RC_SRCS poland.qrc)

add_plugin(stationspoland ${poland_SRCS} ${poland_MOC_SRCS} ${poland_RC_SRCS})
