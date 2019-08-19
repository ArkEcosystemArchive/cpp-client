#!/bin/bash

rm -dfr build
mkdir build
cd build

# Mimic submodule process by copying cpp-client src into the expected directory
# git doesn't like nested .gitmodule files
rm -dfr ../lib/cpp-client/
mkdir ../lib/cpp-client/
cp -R ../../../src ../lib/cpp-client/

cmake ..
cmake --build .
