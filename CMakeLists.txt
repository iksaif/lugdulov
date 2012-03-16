cmake_minimum_required(VERSION 2.6)

project(lugdulov)

include(CMakeDependentOption)

set(LUGDULOV_VERSION_MAJOR "0")
set(LUGDULOV_VERSION_MINOR "6")
set(LUGDULOV_VERSION_PATCH "2")

if(CMAKE_SYSTEM_NAME MATCHES Linux)
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/share/apps/cmake/modules/)
endif()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/)

cmake_dependent_option(BUILD_STATIC_PLUGINS "build static plugins [default: off]" OFF "NOT BUILD_SHARED_LIBS" ON)
option(BUILD_UTILS "build cli utilities [default: off]" OFF)
option(LUGDULOV_LITE "build lite version [default: off]" OFF)
option(LUGDULOV_FULL_UI "use the 'full' ui [default: off]" OFF)
option(LUGDULOV_MEEGO "build for MeeGo [default: off]"  OFF)
option(LUGDULOV_QWIDGET "build the qwidget version [default: on]"  ON)
option(LUGDULOV_MEEGO "build the qml version [default: off]"  OFF)
option(LUGDULOV_APPUP "build AppUp stuff [default: off]" OFF)

include(lugdulov)

set(QTMOBILITY_MKSPEC_VERSION "11")

find_package(Qt4 REQUIRED)
find_package(QJSON REQUIRED)
find_package(QtMobility)

CHECK_SYMBOL_EXISTS(Q_WS_MAEMO_5 "QtCore/qglobal.h" Q_WS_MAEMO_5)

if (QT_MOBILITY_FOUND)
  message(STATUS "Found QtMobility ${QT_MOBILITY_VERSION}")
endif()

if (QT_MOBILITY_LOCATION_FOUND)
  message(STATUS "Found QtLocation")
endif()

if (LUGDULOV_APPUP)
  if (WIN32)
    set(HAVE_APPUP_SDK 1)
    message(STATUS "Building for AppUp")
	set(APPUP_LIBRARY_DIR "C:/Program Files/Intel/IntelAppUpSDK/Cpp/lib")
	set(APPUP_INCLUDE_DIR "C:/Program Files/Intel/IntelAppUpSDK/Cpp/include")
  else()
    message(FATAL_ERROR "AppUp SDK not supported on this platform")
  endif()
endif()

set(HAVE_QT_LOCATION ${QT_MOBILITY_LOCATION_FOUND})
set(HAVE_QT_BEARER ${QT_MOBILITY_BEARER_FOUND})

if (QT_MOBILITY_LOCATION_FOUND AND QT_MOBILITY_VERSION VERSION_GREATER 1.1.0 OR QT_MOBILITY_VERSION VERSION_EQUAL 1.1.0)
  option(QMAPCONTROL "use qmapcontrol [default: on]" ON)
else()
  message(STATUS "QGraphicsGeoMap not available, falling back to QMapControl")
  set(QMAPCONTROL 1)
endif()

set(USE_QMAPCONTROL ${QMAPCONTROL})

if (QT_VERSION VERSION_LESS "4.7.0")
  set(HAVE_QT_BEARER TRUE)
endif()

if (QT_VERSION VERSION_LESS "4.8.0")
  set(HAVE_KINETIC_SCROLLER_SOLUTION TRUE)
endif()

## GCC  ##
if (CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -ggdb3 -DDEBUG=1")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Wall -Wstrict-prototypes -Werror-implicit-function-declaration -Wno-pointer-sign")

  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb3 -DDEBUG=1")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

if(NOT EXECUTABLE_OUTPUT_PATH)
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE STRING
    "Single output directory for building all executables."
    FORCE)
endif()

if(NOT LIBRARY_OUTPUT_PATH)
  set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE STRING
    "Single output directory for building all libraries."
    FORCE)
endif()

# compile in debug mode
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif()

if("${CMAKE_BUILD_TYPE}" MATCHES "^Rel.*")
  add_definitions("-DQT_NO_DEBUG_OUTPUT")
endif("${CMAKE_BUILD_TYPE}" MATCHES "^Rel.*")


#add extra search paths for libraries and includes
set(LIB_SUFFIX "" CACHE STRING "Define suffix of directory name (32/64)" )
set(LIB_INSTALL_DIR "lib${LIB_SUFFIX}" CACHE STRING "Directory where lib will install")
set(INCLUDE_INSTALL_DIR "include" CACHE STRING "Directory where include will install")

if (APPLE)
   set(PLUGIN_INSTALL_DIR "lugdulov.app/Contents/PlugIns/lugdulov")
   set(BIN_INSTALL_DIR "lugdulov.app/Contents/MacOS")
   set(LIB_INSTALL_DIR "lugdulov.app/Contents/MacOS")
elseif (WIN32)
   set(PLUGIN_INSTALL_DIR "bin/plugins/lugdulov")
   set(BIN_INSTALL_DIR "bin") # FIXME CMake bug
   set(LIB_INSTALL_DIR "bin") # FIXME CMake bug
else()
   set(PLUGIN_INSTALL_DIR "lib/lugdulov/plugins")
   set(BIN_INSTALL_DIR "bin")
   set(LIB_INSTALL_DIR "lib")
endif()

set (LUGDULOV_VERSION "${LUGDULOV_VERSION_MAJOR}.${LUGDULOV_VERSION_MINOR}.${LUGDULOV_VERSION_PATCH}")

# Use it
set(QT_USE_QTGUI TRUE)
set(QT_USE_QTNETWORK TRUE)
set(QT_USE_QTXML TRUE)
if(WIN32) 
   set(QT_USE_QTMAIN TRUE) 
endif(WIN32) 
   
include(${QT_USE_FILE})

# Find config.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

if (HAVE_KINETIC_SCROLLER_SOLUTION)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/kineticscroller/include/)
  add_subdirectory(kineticscroller)
endif()

add_subdirectory(data)
add_subdirectory(common)
add_subdirectory(plugins)

if(QMAPCONTROL)
  add_subdirectory(qmapcontrol)
endif()

if(LUGDULOV_QWIDGET)
  add_subdirectory(lugdulov)
endif()
if(LUGDULOV_QML)
  add_subdirectory(lugdulov-qml)
endif()

if(BUILD_UTILS)
  add_subdirectory(utils)
endif()

add_subdirectory(pkg)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake config.h ESCAPE_QUOTES)

## Package ##

# Bundle only accept .txt files
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/COPYING ${CMAKE_CURRENT_BINARY_DIR}/COPYING.txt)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/README ${CMAKE_CURRENT_BINARY_DIR}/README.txt)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Lugdulo'V")
set(CPACK_PACKAGE_VENDOR "iksaif.net")
set(CPACK_PACKAGE_VERSION_MAJOR ${LUGDULOV_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${LUGDULOV_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${LUGDULOV_VERSION_PATCH})
set(CPACK_VERSION ${LUGDULOV_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_BINARY_DIR}/README.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_BINARY_DIR}/README.txt")
set(CPACK_RESOURCE_FILE_WELCOME "${CMAKE_CURRENT_BINARY_DIR}/README.txt")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_BINARY_DIR}/COPYING.txt")
set(CPACK_PACKAGE_CONTACT "Corentin Chary <corentin.chary@gmail.com>")
set(CPACK_SOURCE_IGNORE_FILES
  "~$"
  "^${PROJECT_SOURCE_DIR}/\\\\.git"
  "^${PROJECT_SOURCE_DIR}/build/")

if(WIN32)
  set(CPACK_PACKAGE_FILE_NAME "lugdulov-${CPACK_VERSION}-win32")
  set(CPACK_SOURCE_PACKAGE_FILE_NAME "lugdulov")
  set(CPACK_SOURCE_GENERATOR "ZIP")
  # set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\MyExecutable.exe")
  set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/data/icons/lugdulov.ico")
  set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/data/icons/lugdulov.ico")
  #set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/data/icons/lugdulov.ico")

  set(CPACK_PACKAGE_EXECUTABLES "lugdulov" "Lugdulo'V")

  set(CPACK_GENERATOR "ZIP;NSIS")
  set(CPACK_BINARY_NSIS "ON")
  set(CPACK_NSIS_MODIFY_PATH "OFF")
  set(CPACK_BINARY_CYGWIN "OFF")
  set(CPACK_SOURCE_CYGWIN "OFF")
  set(CPACK_NSIS_DISPLAY_NAME "Lugdulo'V")
  set(CPACK_NSIS_HELP_LINK "http://xf.iksaif.net/dev/lugdulov.html")
  set(CPACK_NSIS_URL_INFO_ABOUT "http://xf.iksaif.net/dev/lugdulov.html")
  set(CPACK_NSIS_CONTACT "Corentin Chary <corentin.chary@gmail.com>")
  set(CPACK_PACKAGE_INSTALL_DIRECTORY "lugdulov")
elseif(APPLE)
  set(CPACK_GENERATOR "DragNDrop")

  set(CPACK_PACKAGE_FILE_NAME "lugdulov-${CPACK_VERSION}-osx")
  set(CPACK_PACKAGE_ICON ${CMAKE_SOURCE_DIR}/data/icons/lugdulov.icns)

  set(CPACK_BUNDLE_ICON ${CMAKE_SOURCE_DIR}/data/icons/lugdulov.icns)
  set(CPACK_BUNDLE_NAME "Lugdulo'V")
  set(CPACK_BUNDLE_STARTUP_COMMAND "${CMAKE_SOURCE_DIR}/pkg/osx/lugdulov-startup")
  set(CPACK_BUNDLE_PLIST ${CMAKE_BINARY_DIR}/Info.plist)

  #set(CPACK_DMG_BACKGROUND_IMAGE pkg/osx/background.png)
  #set(CPACK_DMG_DS_STORE pkg/osx/DS_Store)

  set(MACOSX_BUNDLE_GUI_IDENTIFIER "http://xf.iksaif.net/dev/lugdulov.html")
  set(MACOSX_BUNDLE_LONG_VERSION_STRING "Lugdulo'V" ${CPACK_VERSION})
  set(MACOSX_BUNDLE_BUNDLE_NAME "Lugdulo'V")
  set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${CPACK_VERSION})
  set(MACOSX_BUNDLE_BUNDLE_VERSION ${CPACK_VERSION})
  set(MACOSX_BUNDLE_COPYRIGHT "Copyright 2010-2011 Corentin Chary")
  set(MACOSX_BUNDLE_INFO_STRING "Lugdulo'V - Find a bike in your city")
  set(MACOSX_BUNDLE_ICON_FILE "lugdulov.icns")
  set(MACOSX_BUNDLE_EXECUTABLE_NAME "${CMAKE_SOURCE_DIR}/pkg/osx/lugdulov-startup")
  configure_file(pkg/osx/Info.plist.in ${CMAKE_BINARY_DIR}/Info.plist)
  set(MACOSX_BUNDLE_INFO_PLIST ${CMAKE_BINARY_DIR}/Info.plist)

  install(FILES ${CMAKE_BINARY_DIR}/Info.plist DESTINATION lugdulov.app/Contents/)
  install(FILES data/icons/lugdulov.icns DESTINATION lugdulov.app/Contents/Resources)

  set(CPACK_BINARY_DRAGNDROP ON)
else()
  if (LUGDULOV_MEEGO)
    set(CPACK_PACKAGE_FILE_NAME "net.iksaif.lugdulov-${CPACK_VERSION}-${CMAKE_SYSTEM_NAME}")
    set(CPACK_SOURCE_PACKAGE_FILE_NAME "net.iksaif.lugdulov-${CPACK_VERSION}")
  else()
    set(CPACK_PACKAGE_FILE_NAME "lugdulov-${CPACK_VERSION}-${CMAKE_SYSTEM_NAME}")
    set(CPACK_SOURCE_PACKAGE_FILE_NAME "lugdulov-${CPACK_VERSION}")
  endif()

  set(CPACK_SOURCE_GENERATOR "TGZ;TBZ2")
endif()
include(CPack)
