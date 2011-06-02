TEMPLATE = subdirs
SUBDIRS = sub_plugins sub_kineticscroller sub_lugdulov

include(lugdulov.pri)

sub_plugins.subdir     = plugins
sub_qmapcontrol.subdir = qmapcontrol
sub_kineticscroller.subdir    = kineticscroller
sub_lugdulov.subdir    = lugdulov
sub_lugdulov.depends   = sub_plugins sub_kineticscroller

contains(LUGDULOV_CONFIG, qmapcontrol) {
	SUBDIRS += sub_qmapcontrol 
	sub_lugdulov.depends += sub_qmapcontrol 
}

OTHER_FILES += \
    android/res/drawable-mdpi/icon.png \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/src/eu/licentia/necessitas/ministro/IMinistroCallback.aidl \
    android/src/eu/licentia/necessitas/ministro/IMinistro.aidl \
    android/src/eu/licentia/necessitas/industrius/QtActivity.java \
    android/src/eu/licentia/necessitas/industrius/QtApplication.java \
    android/src/eu/licentia/necessitas/industrius/QtSurface.java \
    android/AndroidManifest.xml
