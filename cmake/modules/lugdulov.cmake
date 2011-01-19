macro(CAR var)
  set(${var} ${ARGV1})
endmacro(CAR)

macro(CDR var junk)
  set(${var} ${ARGN})
endmacro(CDR)

macro(ADD_CONVENIENCE_LIBRARY)
  car(LIBNAME ${ARGN})
  cdr(SRCFILES ${ARGN})

  add_library(${LIBNAME} STATIC ${SRCFILES})
  if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
    set_target_properties(${LIBNAME} PROPERTIES COMPILE_FLAGS "-fPIC")
  endif()
endmacro()

macro(ADD_PLUGIN)
  car(LIBNAME ${ARGN})
  cdr(SRCFILES ${ARGN})

  add_definitions(${QT_DEFINITIONS})
  add_definitions(-DQT_PLUGIN)

  link_directories(
	${QT_LIBRARY_DIR}
	${QJSON_LIBRARY_DIRS}
  )

  if (QT_MOBILITY_FOUND)
    include_directories(${QT_MOBILITY_INCLUDE_DIR})
    link_directories(${QT_MOBILITY_LIBRARY_DIR})
  endif()

  if(BUILD_STATIC_PLUGINS)
    add_definitions(-DQT_STATICPLUGIN)
    add_library(${LIBNAME} STATIC ${SRCFILES})
  else()
    add_definitions(-DQT_SHARED)
    add_library(${LIBNAME} SHARED ${SRCFILES})
    install(TARGETS ${LIBNAME}
      LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR}
      RUNTIME DESTINATION ${PLUGIN_INSTALL_DIR}
      )
  endif()

  target_link_libraries(
    ${LIBNAME}
    lugdulov_base
    ${QT_LIBRARIES}
    ${QJSON_LIBRARIES}
  )

  if (QT_MOBILITY_LOCATION_FOUND)
    target_link_libraries(${LIBNAME} ${QT_MOBILITY_LOCATION_LIBRARY})
  endif ()

endmacro()
