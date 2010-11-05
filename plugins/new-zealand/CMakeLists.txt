project(new-zealand)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(new-zealand_SRCS
  factory.cpp
)

set(new-zealand_HDRS
  factory.h
)

qt4_wrap_cpp(new-zealand_MOC_SRCS ${new-zealand_HDRS})
qt4_add_resources(new-zealand_RC_SRCS new-zealand.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationsnew-zealand ${new-zealand_SRCS} ${new-zealand_MOC_SRCS} ${new-zealand_RC_SRCS})

target_link_libraries(
  stationsnew-zealand
  lugdulov_base
  ${QT_LIBRARIES}
)
