TEMPLATE = subdirs
SUBDIRS = sub_common sub_lyon sub_paris

sub_lyon.subdir     = lyon
sub_paris.subdir    = paris
sub_common.subdir   = common

sub_lyon.depends = sub_common
sub_paris.depends = sub_common

