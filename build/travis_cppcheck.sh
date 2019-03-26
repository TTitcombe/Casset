#!/bin/sh
# Script for compiling Casset in Travis
sudo apt install python3-pip python3-setuptools xutils-dev
sudo pip3 install conan
conan user
conan remote add zimmerk https://api.bintray.com/conan/zimmerk/conan
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
mkdir -p ~/.conan/profiles
cp travis/default ~/.conan/profiles/default
mkdir build
cd build
cmake -DENABLE_CPPCHECK=ON -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_BUILD_TYPE=Debug .. && make