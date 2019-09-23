# run desktop builds
cmake . -DCMAKE_BUILD_TYPE=Coverage -DBUILD_TESTING=OFF
cmake --build .

# disable build examples until breaking changes are committed so the example can pull them in
# build examples
#cd ./examples/cmake_example
#cmake .
#cmake --build .

# run Gtest
# cd ../../
./test/Ark-Cpp-Client-tests
