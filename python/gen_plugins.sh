#!/bin/sh

for i in paris cergypontoise creteil aixenprovence amiens besancon marseille mulhouse nancy nantes plainecommune rouen toulouse; do
    echo $i
    python carto.py --class $i > ../plugins/france/${i}.cpp
    python carto.py --header $i > ../plugins/france/${i}.h
done

for i in bruxelles; do
    echo $i
    python carto.py --class $i > ../plugins/belgium/${i}.cpp
    python carto.py --header $i > ../plugins/belgium/${i}.h
done

for i in dublin; do
    echo $i
    python carto.py --class $i > ../plugins/ireland/${i}.cpp
    python carto.py --header $i > ../plugins/ireland/${i}.h
done

for i in luxembourg; do
    echo $i
    python carto.py --class $i > ../plugins/luxembourg/${i}.cpp
    python carto.py --header $i > ../plugins/luxembourg/${i}.h
done

for i in seville santander; do
    echo $i
    python carto.py --class $i > ../plugins/spain/${i}.cpp
    python carto.py --header $i > ../plugins/spain/${i}.h
done

for i in toyama; do
    echo $i
    python carto.py --class $i > ../plugins/japan/${i}.cpp
    python carto.py --header $i > ../plugins/japan/${i}.h
done
