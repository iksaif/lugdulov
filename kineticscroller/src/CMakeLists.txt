project(kineticscroller)

add_definitions(-DQTSCROLLER_NO_WEBKIT=1)

set(kineticscroller_SRCS
  qtflickgesture.cpp
  qtscroller.cpp
  qtscrollerfilter.cpp
  qtscrollerproperties.cpp
  qtscrollevent.cpp
)

if (APPLE)
  set(kineticscroller_SRCS
    ${kineticscroller_SRCS}
    qtscroller_mac.mm
  )
endif ()


set(kineticscroller_MOC_HDRS
  qtflickgesture_p.h
  qtscroller.h
  qtscroller_p.h
  qtscrollerfilter_p.h
)

qt4_wrap_cpp(kineticscroller_MOC_SOURCE ${kineticscroller_MOC_HDRS})

link_directories(${QT_LIBRARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_library(kineticscroller STATIC
  ${kineticscroller_SRCS}
  ${kineticscroller_MOC_SOURCE}
)

target_link_libraries(kineticscroller ${QT_LIBRARIES})

if (APPLE)
  target_link_libraries(kineticscroller -framework Cocoa)
endif()
