TEMPLATE = subdirs
SUBDIRS = sub_plugins sub_qmapcontrol sub_lugdulov

sub_plugins.subdir     = plugins
sub_qmapcontrol.subdir = qmapcontrol
sub_lugdulov.subdir    = lugdulov


sub_lugdulov.depends = sub_plugins sub_qmapcontrol
