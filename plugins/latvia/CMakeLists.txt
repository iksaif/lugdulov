project(latvia)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(latvia_SRCS
  factory.cpp
)

set(latvia_HDRS
  factory.h
)

qt4_wrap_cpp(latvia_MOC_SRCS ${latvia_HDRS})
qt4_add_resources(latvia_RC_SRCS latvia.qrc)

add_plugin(stationslatvia ${latvia_SRCS} ${latvia_MOC_SRCS} ${latvia_RC_SRCS})
