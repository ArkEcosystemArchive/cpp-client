cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-tests)

hunter_add_package(GTest)

find_package(GTest CONFIG REQUIRED)

include(CTest)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

set(COVERAGE OFF CACHE BOOL "Coverage")

include_directories(${PROJECT_SOURCE_DIR}/../src)
include_directories(${PROJECT_SOURCE_DIR}/../test)
include_directories(${PROJECT_SOURCE_DIR}/include/ArduinoJson)
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

find_library(Ark-Cpp-Client-tests
	NAMES Ark-Cpp-Client-lib
	PATHS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)

add_executable(Ark-Cpp-Client-tests
	${TEST_API_SRC}
	${TEST_ONE_SRC}
	${TEST_TWO_SRC}
)

target_link_libraries(Ark-Cpp-Client-tests Ark-Cpp-Client-lib)

target_link_libraries(Ark-Cpp-Client-tests GTest::main) # GTest::gtest will be linked automatically
target_link_libraries(Ark-Cpp-Client-tests GTest::gtest)

if (COVERAGE)
	target_compile_options(tests PRIVATE --coverage)
	target_link_libraries(tests PRIVATE --coverage)
endif()

add_test(NAME test COMMAND Ark-Cpp-Client-tests)
