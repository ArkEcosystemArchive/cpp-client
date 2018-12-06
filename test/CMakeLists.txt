cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-tests)

hunter_add_package(GTest)

find_package(GTest CONFIG REQUIRED)
find_package(GMock CONFIG REQUIRED)

include(CTest)
enable_testing()

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

include_directories(${PROJECT_SOURCE_DIR}/../src)
include_directories(${PROJECT_SOURCE_DIR}/../test)
include_directories(${PROJECT_SOURCE_DIR}/lib/ArduinoJson)
include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(TEST_API_SRC
	${PROJECT_SOURCE_DIR}/connection/connection.cpp
)

set(TEST_ONE_SRC
	${PROJECT_SOURCE_DIR}/api/one/one_accounts.cpp
	${PROJECT_SOURCE_DIR}/api/one/one_blocks.cpp
	${PROJECT_SOURCE_DIR}/api/one/one_delegates.cpp
	${PROJECT_SOURCE_DIR}/api/one/one_loader.cpp
	${PROJECT_SOURCE_DIR}/api/one/one_peers.cpp
	${PROJECT_SOURCE_DIR}/api/one/one_signatures.cpp
	${PROJECT_SOURCE_DIR}/api/one/one_transactions.cpp
)

set(TEST_TWO_SRC
	${PROJECT_SOURCE_DIR}/api/two/two_blocks.cpp
	${PROJECT_SOURCE_DIR}/api/two/two_delegates.cpp
	${PROJECT_SOURCE_DIR}/api/two/two_node.cpp
	${PROJECT_SOURCE_DIR}/api/two/two_peers.cpp
	${PROJECT_SOURCE_DIR}/api/two/two_transactions.cpp
	${PROJECT_SOURCE_DIR}/api/two/two_votes.cpp
	${PROJECT_SOURCE_DIR}/api/two/two_wallets.cpp
)

find_library(Ark-Cpp-Client-tests PUBLIC)

add_executable(Ark-Cpp-Client-tests
	${TEST_API_SRC}
	${TEST_ONE_SRC}
	${TEST_TWO_SRC}
)

target_link_libraries(Ark-Cpp-Client-tests Ark-Cpp-Client-lib GTest::gtest GMock::gmock GMock::main)

add_test(NAME test COMMAND Ark-Cpp-Client-tests)

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
  include("${CMAKE_SOURCE_DIR}/cmake/CodeCoverage.cmake")

  setup_target_for_coverage(${PROJECT_NAME}_coverage Ark-Cpp-Client-tests coverage)

  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
 endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

