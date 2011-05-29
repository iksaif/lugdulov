install(FILES lugdulov.desktop DESTINATION share/applications/hildon)
install(FILES lugdulov.png DESTINATION share/icons/hicolor/64x64/hildon)

# FIXME: remove when upstream libQtLocation is fixed (or if you use libqtm-11)
install(FILES libQtLocation.so.1 libQtLocation.so.1.0 libQtLocation.so.1.0.2 DESTINATION lib)
install(FILES lugdulov-wrapper DESTINATION bin)