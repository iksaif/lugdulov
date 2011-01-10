
INSTALL(DIRECTORY "${QT_PLUGINS_DIR}/imageformats" DESTINATION lugdulov.app/Contents/PlugIns)

set(APPS "\${CMAKE_INSTALL_PREFIX}/lugdulov.app/Contents/MacOS/lugdulov")

#INSTALL(CODE "
#  file(WRITE \"\${CMAKE_INSTALL_PREFIX}/qt.conf\" \"\")")

set(DIRS
   ${QT_LIBRARY_DIR}
   ${QJSON_LIBRARY_DIRS}
   ${PLUGINS_INSTALL_DIR}
   ${LIB_INSTALL_DIR}
)

if(UNIX)
  set(DIRS ${DIRS}
  	/lib/
        /usr/lib/
  	/usr/local/lib/
     )
endif()

INSTALL(CODE "
    file(GLOB_RECURSE QTPLUGINS
      \"\${CMAKE_INSTALL_PREFIX}/lugdulov.app/Contents/PlugIns/*/*${CMAKE_SHARED_LIBRARY_SUFFIX}\"
    )
    include(BundleUtilities)
    fixup_bundle(\"${APPS}\" \"\${QTPLUGINS}\" \"${DIRS}\")")
