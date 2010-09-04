project(<name>)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(<name>_SRCS
  factory.cpp
  <Sources>
)

set(<name>_HDRS
  factory.h
  <Headers>
)

qt4_wrap_cpp(<name>_MOC_SRCS ${<name>_HDRS})
qt4_add_resources(<name>_RC_SRCS <name>.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stations<name> ${<name>_SRCS} ${<name>_MOC_SRCS} ${<name>_RC_SRCS})

target_link_libraries(
  stations<name>
  lugdulov_base
  ${QT_LIBRARIES}
)
