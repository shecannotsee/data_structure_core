#!/bin/bash
project="data_structure_core"
# Get pwd string
path=$(pwd)
# Get last 19 chars
suffix="${path: -19}"
# Check if it is "data_structure_core"
if [ "$suffix" = "$project" ]; then
    echo "ok"
else
    echo "Path error.Please ensure that the last few strings after using pwd are "$project
    exit 1  # stop
fi

echo "Check third_party exist?"
if [ -d "./third_party" ];
then
    echo "third_party."
else
    echo "Create third_party."
    mkdir third_party
fi

git clone --branch v1.12.x --depth 1 https://github.com/google/googletest.git ./third_party/googletest/

cd third_party
mv googletest googletest-src
# build
mkdir googletest
cd googletest
path=$(pwd)
cmake -DCMAKE_INSTALL_PREFIX=./ ../googletest-src
make -j8
make install
# Delete all, except for the lib and include directories
shopt -s extglob
rm -rf !(include|lib)
