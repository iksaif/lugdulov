cmake_minimum_required(VERSION 2.6)

project(lugdulov)

include(CMakeDependentOption)

set(VERSION_MAJOR "0")
set(VERSION_MINOR "2")
set(VERSION_PATCH "2")

if(CMAKE_SYSTEM_NAME MATCHES Linux)
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/share/apps/cmake/modules/)
endif()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/)

cmake_dependent_option(BUILD_STATIC_PLUGINS "build static plugins [default: off]" OFF "NOT BUILD_SHARED_LIBS" ON)
option(BUILD_UTILS "build cli utilities [default: off]" OFF)

include(lugdulov)
include(QtTranslations) # Local file for maemo_qt4_add_translation()

set(PLUGINS_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}lib/lugdulov/plugins")

find_package(Qt4 REQUIRED)
find_package(QJSON REQUIRED)
find_package(QtLocation)
find_package(QtBearer)

CHECK_SYMBOL_EXISTS(Q_WS_MAEMO_5 "QtCore/qglobal.h" Q_WS_MAEMO_5)

set(HAVE_QT_LOCATION ${QTLOCATION_FOUND})
set(HAVE_QT_BEARER ${QTBEARER_FOUND})

if (QT_VERSION_MAJOR EQUAL "4" AND QT_VERSION_MINOR EQUAL "7")
  set(HAVE_QT_BEARER TRUE)
endif()

## GCC  ##
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -ggdb3 -DDEBUG=1")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Wall -Wstrict-prototypes -Werror-implicit-function-declaration -Wno-pointer-sign")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb3 -DDEBUG=1")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

if(NOT EXECUTABLE_OUTPUT_PATH)
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE STRING
    "Single output directory for building all executables."
    FORCE)
endif(NOT EXECUTABLE_OUTPUT_PATH)

if(NOT LIBRARY_OUTPUT_PATH)
  set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE STRING
    "Single output directory for building all libraries."
    FORCE)
endif(NOT LIBRARY_OUTPUT_PATH)

# compile in debug mode
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if("${CMAKE_BUILD_TYPE}" MATCHES "^Rel.*")
  add_definitions("-DQT_NO_DEBUG_OUTPUT")
endif("${CMAKE_BUILD_TYPE}" MATCHES "^Rel.*")


#add extra search paths for libraries and includes
set(LIB_SUFFIX "" CACHE STRING "Define suffix of directory name (32/64)" )
set(LIB_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}" CACHE STRING "Directory where lib will install")
set(BIN_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin" CACHE STRING "Directory where binary will install")
set(INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include" CACHE STRING "Directory where include will install")

set (LUGDULOV_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# Use it
set(QT_USE_QTGUI TRUE)
set(QT_USE_QTNETWORK TRUE)
set(QT_USE_QTXML TRUE)
set(QT_USE_QTSQL TRUE)

include( ${QT_USE_FILE} )

# Find config.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(plugins)
add_subdirectory(qmapcontrol)
add_subdirectory(lugdulov)
if (BUILD_UTILS)
  add_subdirectory(utils)
endif ()
add_subdirectory(pkg)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake config.h ESCAPE_QUOTES)

## Package ##
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Lugdulo'V")
set(CPACK_PACKAGE_VENDOR "iksaif.net")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_VERSION ${LUGDULOV_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_RESOURCE_FILE_WELCOME "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_CONTACT "Corentin Chary <corentin.chary@gmail.com>")
set(CPACK_PACKAGE_VENDOR "http://xf.iksaif.net/dev/lugdulov.html")
set(CPACK_SOURCE_IGNORE_FILES
  "~$"
  "^${PROJECT_SOURCE_DIR}/\\\\.git"
  "^${PROJECT_SOURCE_DIR}/build/")

if(WIN32)
  install(FILES
        "${QT_BINARY_DIR}/QtCore${QT_VERSION_MAJOR}.dll"
        "${QT_BINARY_DIR}/QtXml${QT_VERSION_MAJOR}.dll"
        "${QT_BINARY_DIR}/QtGui${QT_VERSION_MAJOR}.dll"
        "${QT_BINARY_DIR}/QtNetwork${QT_VERSION_MAJOR}.dll"
        "${QT_BINARY_DIR}/mingwm10.dll"
        "${QT_BINARY_DIR}/libgcc_s_dw2-1.dll"
        "${CMAKE_BINARY_DIR}/bin/libqjson.dll"
        DESTINATION bin
  )
  set(CPACK_PACKAGE_FILE_NAME "lugdulov-${CPACK_VERSION}-win32")
  set(CPACK_SOURCE_PACKAGE_FILE_NAME "lugdulov")
  # set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\MyExecutable.exe")
  set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/lugdulov/res/lugdulov.ico")
  set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/lugdulov/res/lugdulov.ico")
  #set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/lugdulov/res/lugdulov.ico")
  set(CPACK_PACKAGE_EXECUTABLES "lugdulov;Lugdulo'V")
  set(CPACK_BINARY_NSIS "ON")
  set(CPACK_NSIS_MODIFY_PATH "OFF")
  set(CPACK_BINARY_CYGWIN "OFF")
  set(CPACK_SOURCE_CYGWIN "OFF")
  set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY} Lugdulo'v")
  set(CPACK_NSIS_HELP_LINK "http://xf.iksaif.net/dev/lugdulov.html")
  set(CPACK_NSIS_URL_INFO_ABOUT "http://xf.iksaif.net/dev/lugdulov.html")
  set(CPACK_NSIS_CONTACT "Corentin Chary <corentin.chary@gmail.com>")
  set(CPACK_PACKAGE_INSTALL_DIRECTORY "lugdulov")
else(WIN32)
  set(CPACK_PACKAGE_FILE_NAME "lugdulov-${CPACK_VERSION}-${CMAKE_SYSTEM_NAME}")
  set(CPACK_SOURCE_PACKAGE_FILE_NAME "lugdulov-${CPACK_VERSION}")
  set(CPACK_GENERATOR "DEB")
  set(CPACK_SOURCE_GENERATOR "TGZ;TBZ2")
  ## Debian specific ##
  set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt4-core (>= 4.6), libqt4-xml (>= 4.6), libqt4-gui (>= 4.6), libqt4-network (>= 4.6), qjson | libqjson0")
  set(CPACK_DEBIAN_PACKAGE_BUILDS_DEPENDS "libqt4-dev (>= 4.6), cmake (>= 2.6), qjson | libqjson-dev")
endif(WIN32)
include(CPack)
