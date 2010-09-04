project(switzerland)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(switzerland_SRCS
  factory.cpp
  rotkreuz.cpp
  sarnen.cpp
  kussnacht_am_rigi.cpp
  brunnen.cpp
  schupfheim.cpp
  langenthal.cpp
  sursee.cpp
  zug.cpp
  bern.cpp
  schwyz.cpp
  luzern.cpp
  hochdorf.cpp
  sempach_station.cpp
  stans.cpp
  stansstad.cpp
  arth_goldau.cpp
)

set(switzerland_HDRS
  factory.h
  zug.h
  schupfheim.h
  schwyz.h
  luzern.h
  sempach_station.h
  hochdorf.h
  arth_goldau.h
  stansstad.h
  sarnen.h
  kussnacht_am_rigi.h
  sursee.h
  bern.h
  stans.h
  langenthal.h
  rotkreuz.h
  brunnen.h
)

qt4_wrap_cpp(switzerland_MOC_SRCS ${switzerland_HDRS})
qt4_add_resources(switzerland_RC_SRCS switzerland.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationsswitzerland ${switzerland_SRCS} ${switzerland_MOC_SRCS} ${switzerland_RC_SRCS})

target_link_libraries(
  stationsswitzerland
  lugdulov_base
  ${QT_LIBRARIES}
)
