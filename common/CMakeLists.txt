project(lugdulov_base)

include_directories(
  ${QJSON_INCLUDE_DIR}
)

if (QT_MOBILITY_FOUND)
  include_directories(
    ${QT_MOBILITY_INCLUDE_DIR}
    ${QT_MOBILITY_LOCATION_INCLUDE_DIR}
  )
  link_directories(${QT_MOBILITY_LIBRARY_DIR})
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
  stationspluginbixi2.cpp
  stationsplugintransdev.cpp
  stationspluginbcycle.cpp
  stationsplugincallabike.cpp
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
  stationspluginbixi2.h
  stationsplugintransdev.h
  stationspluginbcycle.h
  stationsplugincallabike.h
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

link_directories(
  ${QT_LIBRARY_DIR}
  ${QJSON_LIBRARY_DIRS}
)

if (CMAKE_COMPILER_IS_GNUCC)
  add_library(lugdulov_base SHARED ${lugdulov_base_SRCS} ${lugdulov_base_MOC_SOURCE})
  set_target_properties(lugdulov_base PROPERTIES
    VERSION ${LUGDULOV_VERSION_MAJOR}.${LUGDULOV_VERSION_MINOR}.${LUGDULOV_VERSION_PATCH}
    SOVERSION ${LUGDULOV_VERSION_MAJOR}.${LUGDULOV_VERSION_MINOR}
    DEFINE_SYMBOL LUGDULOV_BASE_MAKEDLL
  )
  install(TARGETS lugdulov_base
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
  )
else()
  add_library(lugdulov_base STATIC ${lugdulov_base_SRCS} ${lugdulov_base_MOC_SOURCE})
  if (CMAKE_COMPILER_IS_GNUCC)
    set_target_properties(lugdulov_base PROPERTIES COMPILE_FLAGS "-fPIC")
  endif()
endif()

target_link_libraries(lugdulov_base
  ${QJSON_LIBRARIES}
  ${QT_LIBRARIES}
)

if (QT_MOBILITY_LOCATION_FOUND)
  target_link_libraries(lugdulov_base ${QT_MOBILITY_LOCATION_LIBRARY})
endif ()
