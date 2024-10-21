#!/usr/bin/bash
./01-exit-code
echo $?
./01-exit-code || echo "Failed"
