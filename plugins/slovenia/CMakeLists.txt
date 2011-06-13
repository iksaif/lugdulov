project(slovenia)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(slovenia_SRCS
  factory.cpp)

set(slovenia_HDRS
  factory.h)

qt4_wrap_cpp(slovenia_MOC_SRCS ${slovenia_HDRS})
qt4_add_resources(slovenia_RC_SRCS slovenia.qrc)

add_plugin(stationsslovenia ${slovenia_SRCS} ${slovenia_MOC_SRCS} ${slovenia_RC_SRCS})
