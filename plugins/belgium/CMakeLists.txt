project(belgium)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(belgium_SRCS
  factory.cpp
  bruxelles.cpp)

set(belgium_HDRS
  factory.h
  bruxelles.h)

qt4_wrap_cpp(belgium_MOC_SRCS ${belgium_HDRS})
qt4_add_resources(belgium_RC_SRCS belgium.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationsbelgium ${belgium_SRCS} ${belgium_MOC_SRCS} ${belgium_RC_SRCS})

target_link_libraries(
  stationsbelgium
  lugdulov_base
  ${QT_LIBRARIES}
)
