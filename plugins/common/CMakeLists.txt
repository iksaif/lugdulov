project(lugdulov_base)

include_directories(
  ${QJSON_INCLUDE_DIR}
)

set(lugdulov_base_SRCS
  tools.cpp
  stationsplugin.cpp
  stationspluginsimple.cpp
  stationspluginsingle.cpp
  stationsplugincyclocity.cpp
  stationsplugincitybike.cpp
  stationspluginnextbike.cpp
  stationspluginvelin.cpp
  stationsplugindupral.cpp
  station.cpp
  stationspluginmanager.cpp
  stationsmodel.cpp
  stationssortfilterproxymodel.cpp
  settings.cpp
)

set(lugdulov_base_MOC_HDRS
  stationsplugin.h
  stationspluginsimple.h
  stationspluginsingle.h
  stationsplugincyclocity.h
  stationsplugincitybike.h
  stationspluginnextbike.h
  stationspluginvelin.h
  stationsplugindupral.h
  stationspluginmanager.h
  stationsmodel.h
  stationssortfilterproxymodel.h
  settings.h
)

if (HAVE_QT_BEARER)
  set(lugdulov_base_SRCS ${lugdulov_base_SRCS} onlinestatemanager.cpp)
  set(lugdulov_base_MOC_HDRS ${lugdulov_base_MOC_HDRS} onlinestatemanager.h)
endif()

qt4_wrap_cpp(lugdulov_base_MOC_SOURCE ${lugdulov_base_MOC_HDRS})

add_convenience_library(lugdulov_base ${lugdulov_base_SRCS} ${lugdulov_base_MOC_SOURCE})
