#!/bin/sh

for c in `./gen.py countries | cut -f2 -d' '`; do
    lower=$(echo $c | tr "[:upper:]" "[:lower:]")
    for p in `./gen.py cities $c | cut -f1 -d' '`; do
	if [ "$p" != "lyon" ]; then
	    echo $lower/$p
	    ./gen.py gen-plugin $p $c > ../plugins/$lower/$p.cpp
	    ./gen.py gen-header $p $c > ../plugins/$lower/$p.h
	fi
    done
done
