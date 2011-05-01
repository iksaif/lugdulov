project(lugdulov_base)

include_directories(
  ${QJSON_INCLUDE_DIR}
)

if (QT_MOBILITY_FOUND)
  include_directories(
    ${QT_MOBILITY_INCLUDE_DIR}
    ${QT_MOBILITY_INCLUDE_DIR}/QtMobility
  )
endif()

set(lugdulov_base_SRCS
  tools.cpp
  stationspluginfactorysimple.cpp
  stationsplugin.cpp
  stationspluginsimple.cpp
  stationspluginsingle.cpp
  stationsplugincyclocity.cpp
  stationsplugincitybike.cpp
  stationspluginnextbike.cpp
  stationspluginvelin.cpp
  stationsplugindupral.cpp
  stationspluginbixi.cpp
  stationsplugintransdev.cpp
  stationspluginbcycle.cpp
  station.cpp
  stationspluginmanager.cpp
  stationsmodel.cpp
  stationssortfilterproxymodel.cpp
  settings.cpp
)

set(lugdulov_base_MOC_HDRS
  stationsplugin.h
  stationspluginfactorysimple.h
  stationspluginsimple.h
  stationspluginsingle.h
  stationsplugincyclocity.h
  stationsplugincitybike.h
  stationspluginnextbike.h
  stationspluginvelin.h
  stationsplugindupral.h
  stationspluginbixi.h
  stationsplugintransdev.h
  stationspluginbcycle.h
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
