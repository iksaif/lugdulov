project(luxembourg)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(luxembourg_SRCS
  factory.cpp
  luxembourg.cpp)

set(luxembourg_HDRS
  factory.h
  luxembourg.h)

qt4_wrap_cpp(luxembourg_MOC_SRCS ${luxembourg_HDRS})
qt4_add_resources(luxembourg_RC_SRCS luxembourg.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationsluxembourg ${luxembourg_SRCS} ${luxembourg_MOC_SRCS} ${luxembourg_RC_SRCS})

target_link_libraries(
  stationsluxembourg
  lugdulov_base
  ${QT_LIBRARIES}
)
