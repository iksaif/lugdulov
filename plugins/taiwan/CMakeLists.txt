project(taiwan)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${QJSON_INCLUDE_DIR}
)

set(taiwan_SRCS
  factory.cpp
  taipei.cpp
)

set(taiwan_HDRS
  factory.h
  taipei.h
)

qt4_wrap_cpp(taiwan_MOC_SRCS ${taiwan_HDRS})
qt4_add_resources(taiwan_RC_SRCS taiwan.qrc)

add_plugin(stationstaiwan ${taiwan_SRCS} ${taiwan_MOC_SRCS} ${taiwan_RC_SRCS})
