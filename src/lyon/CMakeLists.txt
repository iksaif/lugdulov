include_directories(${lugdulov_SOURCE_DIR}/src/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

set(lyon_SRCS stationslyon.cpp stationslyonbuiltin.cpp)

qt4_wrap_cpp(lyon_MOC_SRCS stationslyon.h)
qt4_add_resources(lyon_RC_SRCS lyon.qrc)

add_plugin(stationslyon ${lyon_SRCS} ${lyon_MOC_SRCS} ${lyon_RC_SRCS})
target_link_libraries(stationslyon ${QT_LIBRARIES})
