#!/usr/bin/bash
dd if=/dev/urandom bs=2 count=100000000 | od -An -i > random_numbers.txt
