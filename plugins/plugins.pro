TEMPLATE = subdirs
SUBDIRS = sub_common sub_france

sub_france.subdir     = france
sub_common.subdir   = common

sub_france.depends = sub_common
