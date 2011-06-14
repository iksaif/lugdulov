project(turkey)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(turkey_SRCS
  factory.cpp
)

set(turkey_HDRS
  factory.h
)

qt4_wrap_cpp(turkey_MOC_SRCS ${turkey_HDRS})
qt4_add_resources(turkey_RC_SRCS turkey.qrc)

add_plugin(stationsturkey ${turkey_SRCS} ${turkey_MOC_SRCS} ${turkey_RC_SRCS})
