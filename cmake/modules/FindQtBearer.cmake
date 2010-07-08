# Find QTBEARER
#
# This module defines
#  QTBEARER_FOUND - whether the qsjon library was found
#  QTBEARER_LIBRARIES - the qwebdav library
#  QTBEARER_INCLUDE_DIR - the include path of the qwebdav library
#

if (QTBEARER_INCLUDE_DIR AND QTBEARER_LIBRARIES)

  # Already in cache
  set (QTBEARER_FOUND TRUE)

else (QTBEARER_INCLUDE_DIR AND QTBEARER_LIBRARIES)

  find_library (QTBEARER_LIBRARIES
    NAMES
    QtBearer
    PATHS
    ${QTBEARER_LIBRARY_DIRS}
    ${QT_LIBRARY_DIR}
    ${LIB_INSTALL_DIR}
  )

  find_path (QTBEARER_INCLUDE_DIR
    NAMES
    QNetworkConfiguration
    PATH_SUFFIXES
    QtBearer
    PATHS
    ${QTBEARER_INCLUDE_DIRS}
    ${QT_INCLUDES}
    ${INCLUDE_INSTALL_DIR}
  )

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(QTBEARER DEFAULT_MSG QTBEARER_LIBRARIES QTBEARER_INCLUDE_DIR)

endif (QTBEARER_INCLUDE_DIR AND QTBEARER_LIBRARIES)
