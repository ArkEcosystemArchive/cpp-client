cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-tests)

add_subdirectory(lib/googletest)

include(CTest)
enable_testing()

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

include_directories(${PROJECT_SOURCE_DIR}/../src)
include_directories(${PROJECT_SOURCE_DIR}/../test)
include_directories(${PROJECT_SOURCE_DIR}/lib/ArduinoJson)
include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(TEST_CONNECTION_SRC
	${PROJECT_SOURCE_DIR}/connection/connection.cpp
)

set(TEST_HOST_SRC
	${PROJECT_SOURCE_DIR}/host/host.cpp
)

set(TEST_HTTP_SRC
	${PROJECT_SOURCE_DIR}/http/http.cpp
)

set(TEST_API_PATHS_SRC
	${PROJECT_SOURCE_DIR}/api/paths.cpp
)

set(TEST_API_SRC
	${PROJECT_SOURCE_DIR}/api/blockchain.cpp
	${PROJECT_SOURCE_DIR}/api/blocks.cpp
	${PROJECT_SOURCE_DIR}/api/delegates.cpp
	${PROJECT_SOURCE_DIR}/api/node.cpp
	${PROJECT_SOURCE_DIR}/api/peers.cpp
	${PROJECT_SOURCE_DIR}/api/transactions.cpp
	${PROJECT_SOURCE_DIR}/api/votes.cpp
	${PROJECT_SOURCE_DIR}/api/wallets.cpp
)

find_library(Ark-Cpp-Client-tests PUBLIC)

add_executable(Ark-Cpp-Client-tests
	${TEST_CONNECTION_SRC}
	${TEST_HOST_SRC}
	${TEST_HTTP_SRC}
	${TEST_API_PATHS_SRC}
	${TEST_API_SRC}
)

target_link_libraries(Ark-Cpp-Client-tests Ark-Cpp-Client-lib gtest gmock gmock_main)

add_test(NAME test COMMAND Ark-Cpp-Client-tests)

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
  include("${CMAKE_SOURCE_DIR}/cmake/CodeCoverage.cmake")

  setup_target_for_coverage(${PROJECT_NAME}_coverage Ark-Cpp-Client-tests coverage)

  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

