project(lugdulov_query)

find_package(QCommandLine)

# Include the library include directories, and the current build directory (moc)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${lugdulov_base_SOURCE_DIR}
  ${QT_INCLUDE_DIR}
  ${QCOMMANDLINE_INCLUDE_DIR}
)

set(lugdulov_query_SRCS
  main.cpp
  cli.cpp)

set(lugdulov_query_MOC_HDRS
  cli.h)

qt4_wrap_cpp(MOC_SOURCE ${lugdulov_query_MOC_HDRS})

link_directories(
  ${QT_LIBRARY_DIR}
  ${QJSON_LIBRARY_DIRS}
)

add_executable(
  lugdulov-query
  ${lugdulov_query_SRCS}
  ${MOC_SOURCE}
)

if (QT_MOBILITY_LOCATION_FOUND)
  include_directories(${QT_MOBILITY_LOCATION_INCLUDE_DIR})
  link_directories(${QT_MOBILITY_LOCATION_LIBRARY_DIR})
  target_link_libraries(lugdulov-query ${QT_MOBILITY_LOCATION_LIBRARY})
endif ()

if (BUILD_STATIC_PLUGINS)
  target_link_libraries(lugdulov-query stationsfrance)
  target_link_libraries(lugdulov-query stationsbelgium)
  target_link_libraries(lugdulov-query stationsireland)
  target_link_libraries(lugdulov-query stationsjapan)
  target_link_libraries(lugdulov-query stationsluxembourg)
  target_link_libraries(lugdulov-query stationsspain)
  target_link_libraries(lugdulov-query stationsgermany)
  target_link_libraries(lugdulov-query stationsunited-kingdom)
  target_link_libraries(lugdulov-query stationscanada)
  target_link_libraries(lugdulov-query stationsswitzerland)
  target_link_libraries(lugdulov-query stationsaustria)
  target_link_libraries(lugdulov-query stationslower-austria)
  target_link_libraries(lugdulov-query stationslatvia)
  target_link_libraries(lugdulov-query stationsnew-zealand)
endif ()

target_link_libraries(
  lugdulov-query
  lugdulov_base
  ${QT_LIBRARIES}
  ${QJSON_LIBRARIES}
  ${QCOMMANDLINE_LIBRARIES}
)

install(TARGETS lugdulov-query
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
)
