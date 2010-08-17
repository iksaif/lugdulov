project(lugdulov_base)

set(lugdulov_base_SRCS
  stationsplugin.cpp
  stationsplugincarto.cpp
  station.cpp)

set(lugdulov_base_MOC_HDRS
  stationsplugin.h
  stationsplugincarto.h)

qt4_wrap_cpp(lugdulov_base_MOC_SOURCE ${lugdulov_base_MOC_HDRS})

add_convenience_library(lugdulov_base ${lugdulov_base_SRCS} ${lugdulov_base_MOC_SOURCE})
