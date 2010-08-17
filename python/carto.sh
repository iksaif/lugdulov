#!/bin/sh

for i in paris cergypontoise creteil aixenprovence amiens besancon marseille mulhouse nancy nantes plainecommune rouen toulouse; do
echo
#    python carto.py --cpp $i > ../plugins/france/${i}_p.h
#    python carto.py --class $i > ../plugins/france/${i}.cpp
#    python carto.py --header $i > ../plugins/france/${i}.h
done

for i in bruxelles; do
    python carto.py --cpp $i > ../plugins/belgium/${i}_p.h
#    python carto.py --class $i > ../plugins/belgium/${i}.cpp
#    python carto.py --header $i > ../plugins/belgium/${i}.h
done

for i in dublin; do
    python carto.py --cpp $i > ../plugins/ireland/${i}_p.h
#    python carto.py --class $i > ../plugins/ireland/${i}.cpp
#    python carto.py --header $i > ../plugins/ireland/${i}.h
done

for i in luxembourg; do
    python carto.py --cpp $i > ../plugins/luxembourg/${i}_p.h
#    python carto.py --class $i > ../plugins/luxembourg/${i}.cpp
#    python carto.py --header $i > ../plugins/luxembourg/${i}.h
done

for i in seville santander; do
    python carto.py --cpp $i > ../plugins/spain/${i}_p.h
#    python carto.py --class $i > ../plugins/spain/${i}.cpp
#    python carto.py --header $i > ../plugins/spain/${i}.h
done

for i in toyama; do
    python carto.py --cpp $i > ../plugins/japan/${i}_p.h
#    python carto.py --class $i > ../plugins/japan/${i}.cpp
#    python carto.py --header $i > ../plugins/japan/${i}.h
done
