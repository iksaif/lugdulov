#!/bin/sh

for c in `./gen.py countries | cut -f2 -d' '`; do
    lower=$(echo $c | tr "[:upper:]" "[:lower:]")
    for p in `./gen.py cities $c | cut -f1 -d' '`; do
	echo $lower/$p
	./gen.py gen-priv $p $c > ../plugins/$lower/${p}_p.h
    done
done
