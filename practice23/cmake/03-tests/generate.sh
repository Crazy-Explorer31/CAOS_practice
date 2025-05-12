#!/usr/bin/bash
set -x
#cmake -S . -B build -G "Unix Makefiles" -DANOTHER_FRAC=ON
cmake -S . -B build -G "Unix Makefiles"
#cmake -S . -B build -G "Ninja"

