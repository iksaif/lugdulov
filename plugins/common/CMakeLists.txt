project(lugdulov_base)

set(lugdulov_base_SRCS
  tools.cpp
  stationsplugin.cpp
  stationspluginsimple.cpp
  stationspluginsingle.cpp
  stationsplugincyclocity.cpp
  stationsplugincitybike.cpp
  stationspluginnextbike.cpp
  station.cpp
)

set(lugdulov_base_MOC_HDRS
  stationsplugin.h
  stationspluginsimple.h
  stationspluginsingle.h
  stationsplugincyclocity.h
  stationsplugincitybike.h
  stationspluginnextbike.h
)

qt4_wrap_cpp(lugdulov_base_MOC_SOURCE ${lugdulov_base_MOC_HDRS})

add_convenience_library(lugdulov_base ${lugdulov_base_SRCS} ${lugdulov_base_MOC_SOURCE})
