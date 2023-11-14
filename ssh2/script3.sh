#!/bin/bash

pid=$(pgrep -f "script1.sh")

kill $pid
echo "скрипт убит"
