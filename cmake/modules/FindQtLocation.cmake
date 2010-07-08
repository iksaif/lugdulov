# Find QTLOCATION
#
# This module defines
#  QTLOCATION_FOUND - whether the qsjon library was found
#  QTLOCATION_LIBRARIES - the qwebdav library
#  QTLOCATION_INCLUDE_DIR - the include path of the qwebdav library
#

if (QTLOCATION_INCLUDE_DIR AND QTLOCATION_LIBRARIES)

  # Already in cache
  set (QTLOCATION_FOUND TRUE)

else (QTLOCATION_INCLUDE_DIR AND QTLOCATION_LIBRARIES)

  find_library (QTLOCATION_LIBRARIES
    NAMES
    QtLocation
    PATHS
    ${QTLOCATION_LIBRARY_DIRS}
    ${QT_LIBRARY_DIR}
    ${LIB_INSTALL_DIR}
  )

  find_path (QTLOCATION_INCLUDE_DIR
    NAMES
    QGeoCoordinate
    PATH_SUFFIXES
    QtLocation
    PATHS
    ${QTLOCATION_INCLUDE_DIRS}
    ${QT_INCLUDES}
    ${INCLUDE_INSTALL_DIR}
  )

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(QTLOCATION DEFAULT_MSG QTLOCATION_LIBRARIES QTLOCATION_INCLUDE_DIR)

endif (QTLOCATION_INCLUDE_DIR AND QTLOCATION_LIBRARIES)
