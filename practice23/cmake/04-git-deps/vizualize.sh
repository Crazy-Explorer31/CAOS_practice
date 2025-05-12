#1 /usr/bin/bash
set -x
cmake -S . -B build --graphviz=04-git-deps.dot
dot -Tpng -o 04-git-deps.png 04-git-deps.dot
