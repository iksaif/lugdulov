project(japan)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(japan_SRCS
  factory.cpp
)

set(japan_HDRS
  factory.h
)

qt4_wrap_cpp(japan_MOC_SRCS ${japan_HDRS})
qt4_add_resources(japan_RC_SRCS japan.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationsjapan ${japan_SRCS} ${japan_MOC_SRCS} ${japan_RC_SRCS})

target_link_libraries(
  stationsjapan
  lugdulov_base
  ${QT_LIBRARIES}
)
