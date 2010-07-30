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

  if(BUILD_STATIC_PLUGINS)
    add_definitions(-DQT_STATICPLUGIN)
    add_library(${LIBNAME} STATIC ${SRCFILES})
  else()
    add_definitions(-DQT_SHARED)
    add_library(${LIBNAME} SHARED ${SRCFILES})
    install(TARGETS ${LIBNAME} LIBRARY DESTINATION lib/lugdulov/plugins)
  endif()
endmacro()
