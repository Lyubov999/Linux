#!/bin/bash

count=0

for i in {1..5}; do
count=$((count+1))
sleep 2
done

wait

echo "$count">count.txt
sleep 3600

