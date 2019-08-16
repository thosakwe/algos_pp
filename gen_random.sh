#!/usr/bin/env bash
for i in `seq 1 10000 | sort -R`
do
  echo "$i;Random User $i;$i"
done
