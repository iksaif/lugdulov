include_directories(${lugdulov_SOURCE_DIR}/src/plugins/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

set(paris_SRCS paris.cpp builtin.cpp)

qt4_wrap_cpp(paris_MOC_SRCS paris.h)
qt4_add_resources(paris_RC_SRCS paris.qrc)

add_plugin(stationsparis ${paris_SRCS} ${paris_MOC_SRCS} ${paris_RC_SRCS})
target_link_libraries(stationsparis ${QT_LIBRARIES} lugdulov_base)
