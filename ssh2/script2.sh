#!/bin/bash

count=$(cat count.txt)
count=$((count-3))

echo $count > count.txt
