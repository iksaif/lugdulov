if(APPLE)
  add_subdirectory(osx)
elseif(Q_WS_MAEMO_5)
  add_subdirectory(maemo5)
elseif("${CMAKE_SYSTEM}" MATCHES "Linux")
  add_subdirectory(linux)
endif()

if(APPLE OR WIN32)
  if(APPLE)
    set(plugins_dest "lugdulov.app/Contents/PlugIns")
    set(APPS "\${CMAKE_INSTALL_PREFIX}/lugdulov.app/Contents/MacOS/lugdulov")
  elseif(WIN32)
    set(plugins_dest "plugins")
    set(APPS "\${CMAKE_INSTALL_PREFIX}/lugdulov.exe")
  endif()

  if(WIN32)
    if(CMAKE_BUILD_TYPE MATCHES Debug OR CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
      install(FILES "${QT_PLUGINS_DIR}/imageformats/qjpegd4.dll" DESTINATION "${plugins_dest}/imageformats")
	endif()
	install(FILES "${QT_PLUGINS_DIR}/imageformats/qjpeg4.dll" DESTINATION "${plugins_dest}/imageformats")
  else()
  	install(DIRECTORY "${QT_PLUGINS_DIR}/imageformats" DESTINATION ${plugins_dest})
  endif()
  
  install(FILES "${QJSON_LIBRARIES}" DESTINATION .)

  #INSTALL(CODE "
  #  file(WRITE \"\${CMAKE_INSTALL_PREFIX}/qt.conf\" \"\")")
  
  set(DIRS
   ${QT_BINARY_DIR}
   ${QT_LIBRARY_DIR}
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

  install(CODE "
    file(GLOB_RECURSE QTPLUGINS
      \"\${CMAKE_INSTALL_PREFIX}/${plugins_dest}/*/*${CMAKE_SHARED_LIBRARY_SUFFIX}\"
      )
    include(BundleUtilities)
    fixup_bundle(\"${APPS}\" \"\${QTPLUGINS}\" \"${DIRS}\")")
endif()
