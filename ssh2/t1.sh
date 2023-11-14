#!/bin/bash

num=5

output_file="proc_count.txt"

echo 0 > $output_file

for i in {1..5}
do
    sleep 5 &
done

wait
echo $num> $output_file

sleep 3600

