project(austria)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(austria_SRCS
  factory.cpp
  neusiedler_see.cpp
  bregenzerwald.cpp
  wien.cpp
)

set(austria_HDRS
  factory.h
  neusiedler_see.h
  bregenzerwald.h
  wien.h
)

qt4_wrap_cpp(austria_MOC_SRCS ${austria_HDRS})
qt4_add_resources(austria_RC_SRCS austria.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationsaustria ${austria_SRCS} ${austria_MOC_SRCS} ${austria_RC_SRCS})

target_link_libraries(
  stationsaustria
  lugdulov_base
  ${QT_LIBRARIES}
)
