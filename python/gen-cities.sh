#!/bin/sh

for ctry in `./gen.py countries | tr ' ' '-'`; do
    ctry_lower=$(echo $ctry | cut -f2 -d':' | tr "[:upper:]" "[:lower:]")
    ctry_uid=$(echo $ctry | cut -f1 -d':')
    out=../plugins/$ctry_lower/cities.xml

    echo "$ctry_lower/cities.xml"

    mkdir -p ../plugins/$ctry_lower
    echo '<?xml version="1.0" encoding="utf-8"?>' > $out
    echo '<cities>' >> $out
    ./gen.py xml-cities $city_id $ctry_uid | sed -e s,^,\ \ , >> $out
    echo '</cities>' >> $out
done
