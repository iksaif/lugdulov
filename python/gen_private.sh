#!/bin/sh

echo "lyon"
python lyon.py --cpp $i > ../plugins/france/lyon_p.h

for i in paris cergypontoise creteil aixenprovence amiens besancon marseille mulhouse nancy nantes plainecommune rouen toulouse; do
    echo "$i"
    python carto.py --cpp $i > ../plugins/france/${i}_p.h
done

for i in bruxelles; do
    echo "$i"
    python carto.py --cpp $i > ../plugins/belgium/${i}_p.h
done

for i in dublin; do
    echo "$i"
    python carto.py --cpp $i > ../plugins/ireland/${i}_p.h
done

for i in luxembourg; do
    echo "$i"
    python carto.py --cpp $i > ../plugins/luxembourg/${i}_p.h
done

for i in seville santander; do
    echo "$i"
    python carto.py --cpp $i > ../plugins/spain/${i}_p.h
done

for i in toyama; do
    echo "$i"
    python carto.py --cpp $i > ../plugins/japan/${i}_p.h
done
