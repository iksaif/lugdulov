#!/bin/sh

mkdir -p stations

for ctry in `./gen.py countries | tr ' ' '-'`; do
    ctry_lower=$(echo $ctry | cut -f2 -d':' | tr "[:upper:]" "[:lower:]")
    ctry_uid=$(echo $ctry | cut -f1 -d':')
    for city in `./gen.py cities $ctry_uid | tr ' ' '_'`; do
	city_lower=$(echo $city | cut -d':' -f2 | tr '-' '_' | tr -d '.')
	city_id=$(echo $city | cut -d':' -f1)
	out=stations/${city_lower}.xml
	echo "$ctry_lower/$city_lower ($city_id)"
	echo '<?xml version="1.0" encoding="utf-8"?>' > $out
	echo '<stations>' >> $out
	./gen.py xml-stations $city_id $ctry_uid >> $out
	echo '</stations>' >> $out
    done
done
