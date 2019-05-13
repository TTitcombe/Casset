#!/bin/bash -ex

# A bash script to install conan and conan remotes on a linux Travis build

sudo pip3 install conan
conan user

# Add the remotes
conan remote add zimmerk https://api.bintray.com/conan/zimmerk/conan
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
conan remote add vthiery https://api.bintray.com/conan/vthiery/conan-packages
conan remote add cli11 https://api.bintray.com/conan/cliutils/CLI11

mkdir -p ~/.conan/profiles
cp travis/default ~/.conan/profiles/default

# Use the conanfile which doesn't contain Qt
rm conanfile.txt
cp travis/conanfile.txt conanfile.txt
