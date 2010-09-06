project(lower-austria)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(lower-austria_SRCS
  factory.cpp
  wiener_neustadt.cpp
  romerland.cpp
  triestingtal.cpp
  obb_bahnhofe.cpp
  wachau.cpp
  wieselburg.cpp
  st_polten.cpp
  baden.cpp
  modling.cpp
  tulln.cpp
)

set(lower-austria_HDRS
  factory.h
  modling.h
  baden.h
  romerland.h
  wachau.h
  triestingtal.h
  st_polten.h
  wiener_neustadt.h
  tulln.h
  wieselburg.h
  obb_bahnhofe.h
)

qt4_wrap_cpp(lower-austria_MOC_SRCS ${lower-austria_HDRS})
qt4_add_resources(lower-austria_RC_SRCS lower-austria.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationslower-austria ${lower-austria_SRCS} ${lower-austria_MOC_SRCS} ${lower-austria_RC_SRCS})

target_link_libraries(
  stationslower-austria
  lugdulov_base
  ${QT_LIBRARIES}
)
