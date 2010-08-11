include_directories(${lugdulov_SOURCE_DIR}/src/plugins/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

set(skel_SRCS skel.cpp)

qt4_wrap_cpp(skel_MOC_SRCS skel.h)
qt4_add_resources(skel_RC_SRCS skel.qrc)

add_plugin(stationsskel ${skel_SRCS} ${skel_MOC_SRCS} ${skel_RC_SRCS})
target_link_libraries(stationsskel ${QT_LIBRARIES} lugdulov_base)
