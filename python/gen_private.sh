#!/bin/sh

for ctry in `./gen.py countries | tr ' ' '-'`; do
    ctry_lower=$(echo $ctry | cut -f2 -d':' | tr "[:upper:]" "[:lower:]")
    ctry_uid=$(echo $ctry | cut -f1 -d':')
    for city in `./gen.py cities $ctry_uid | tr ' ' '_'`; do
	city_lower=$(echo $city | cut -d':' -f2 | tr '-' '_' | tr -d '.')
	city_id=$(echo $city | cut -d':' -f1)
	echo "$ctry_lower/$city_lower ($city_id)"
	mkdir -p ../plugins/$ctry_lower
	./gen.py gen-priv $city_id $ctry_uid > ../plugins/$ctry_lower/${city_lower}_p.h
    done
done
