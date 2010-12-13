TEMPLATE = subdirs
SUBDIRS = sub_common sub_france sub_belgium sub_ireland sub_luxembourg \
        sub_spain sub_japan sub_austria sub_germany sub_latvia sub_lower_austria \
        sub_new_zealand sub_switzerland sub_united_kingdom sub_canada sub_usa

sub_france.subdir     = france
sub_belgium.subdir     = belgium
sub_ireland.subdir     = ireland
sub_luxembourg.subdir     = luxembourg
sub_spain.subdir     = spain
sub_japan.subdir     = japan
sub_austria.subdir     = austria
sub_germany.subdir     = germany
sub_latvia.subdir     = latvia
sub_lower_austria.subdir     = lower-austria
sub_new_zealand.subdir     = new-zealand
sub_switzerland.subdir     = switzerland
sub_united_kingdom.subdir     = united-kingdom
sub_canada.subdir     = canada
sub_usa.subdir     = usa
sub_common.subdir   = common

sub_france.depends = sub_common
sub_belgium.depends = sub_common
sub_ireland.depends = sub_common
sub_luxembourg.depends = sub_common
sub_spain.depends = sub_common
sub_japan.depends = sub_common
sub_austria.depends = sub_common
sub_germany.depends = sub_common
sub_latvia.depends = sub_common
sub_lower_austria.depends = sub_common
sub_new_zealand.depends = sub_common
sub_switzerland.depends = sub_common
sub_united_kingdom.depends = sub_common
sub_canada.depends = sub_common
sub_usa.depends = sub_common
