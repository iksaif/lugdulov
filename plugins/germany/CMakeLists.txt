project(germany)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
)

set(germany_SRCS
  factory.cpp
  hamburg.cpp
  leipzig.cpp
  duisburg.cpp
  gelsenkirchen.cpp
  berlin.cpp
  essen.cpp
  offenburg.cpp
  erfurt.cpp
  koln.cpp
  magdeburg.cpp
  furth.cpp
  oberhausen.cpp
  hamm.cpp
  koblenz.cpp
  munchen.cpp
  dortmund.cpp
  frankfurt.cpp
  bochum.cpp
  flensburg.cpp
  erlangen.cpp
  mulheim_adr.cpp
  dresden.cpp
  aschaffenburg.cpp
  kiel.cpp
  herne.cpp
  bottrop.cpp
  coburg.cpp
  hannover.cpp
  lubeck.cpp
  potsdam.cpp
  dusseldorf.cpp
  friedrichshafen.cpp
  tubingen.cpp
  offenbach_am_main.cpp
  bielefeld.cpp
  nurnberg.cpp
)

set(germany_HDRS
  factory.h
  nurnberg.h
  potsdam.h
  hamburg.h
  erlangen.h
  offenbach_am_main.h
  herne.h
  bielefeld.h
  friedrichshafen.h
  hannover.h
  offenburg.h
  coburg.h
  hamm.h
  berlin.h
  bottrop.h
  frankfurt.h
  furth.h
  tubingen.h
  kiel.h
  koblenz.h
  essen.h
  gelsenkirchen.h
  dusseldorf.h
  leipzig.h
  duisburg.h
  bochum.h
  koln.h
  munchen.h
  mulheim_adr.h
  oberhausen.h
  lubeck.h
  dortmund.h
  erfurt.h
  dresden.h
  aschaffenburg.h
  magdeburg.h
  flensburg.h
)

qt4_wrap_cpp(germany_MOC_SRCS ${germany_HDRS})
qt4_add_resources(germany_RC_SRCS germany.qrc)

link_directories(
  ${QT_LIBRARY_DIR}
)

add_plugin(stationsgermany ${germany_SRCS} ${germany_MOC_SRCS} ${germany_RC_SRCS})

target_link_libraries(
  stationsgermany
  lugdulov_base
  ${QT_LIBRARIES}
)
