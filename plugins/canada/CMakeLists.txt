project(canada)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(canada_SRCS
  factory.cpp
  montreal.cpp
)

set(canada_HDRS
  factory.h
  montreal.h
)

qt4_wrap_cpp(canada_MOC_SRCS ${canada_HDRS})
qt4_add_resources(canada_RC_SRCS canada.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationscanada ${canada_SRCS} ${canada_MOC_SRCS} ${canada_RC_SRCS})

target_link_libraries(
  stationscanada
  lugdulov_base
  ${QT_LIBRARIES}
)
