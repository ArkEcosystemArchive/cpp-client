
# OS Builds

### dependencies

**CMake:**
Use an installer package from the following link:
```https://www.cmake.org/download/```

or using
**Homebrew:**
`brew install cmake`

> note: all other dependencies will be automatically installed via CMake and Hunter Package Manager.

#

### make and build
**`cd` into `cpp-client/`**
then run the following commands:
`mkdir build && cd build`
`cmake .. && cmake --build .`

### run tests
`./test/Ark-Cpp-Client-tests`
