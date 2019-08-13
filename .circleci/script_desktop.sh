# run desktop builds
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Coverage -DBUILD_TESTING=OFF
cmake --build .

# build examples
cd ../examples/cmake_example
./build.sh

# run Gtest
# cd ../../
./test/Ark-Cpp-Client-tests
