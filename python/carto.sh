#!/bin/sh

for i in paris cergypontoise; do
    python carto.py --cpp $i > ../plugins/france/${i}_p.h
done
