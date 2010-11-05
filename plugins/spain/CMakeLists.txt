project(spain)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(spain_SRCS
  factory.cpp

)

set(spain_HDRS
  factory.h
)

qt4_wrap_cpp(spain_MOC_SRCS ${spain_HDRS})
qt4_add_resources(spain_RC_SRCS spain.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationsspain ${spain_SRCS} ${spain_MOC_SRCS} ${spain_RC_SRCS})

target_link_libraries(
  stationsspain
  lugdulov_base
  ${QT_LIBRARIES}
)
