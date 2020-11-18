
cmake_minimum_required(VERSION 3.2)

project(${PROJECT_NAME}_tests C CXX)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

# ------------------------------------------------------------------------------
# External Libraries
# ------------------------------------------------------------------------------

include(${CMAKE_SOURCE_DIR}/cmake/GTest.cmake)

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Link the directories to be included
# ------------------------------------------------------------------------------

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../src)
include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# ARK Test Source
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Connection

set(CONNECTION_TEST_SOURCE ${PROJECT_SOURCE_DIR}/connection/connection.cpp)

# ------------------------------------------------------------------------------
# Host

set(HOST_TEST_SOURCE ${PROJECT_SOURCE_DIR}/host/host.cpp)

# ------------------------------------------------------------------------------
# HTTP

set(HTTP_TEST_SOURCE ${PROJECT_SOURCE_DIR}/http/http.cpp)

# ------------------------------------------------------------------------------
# Paths

set(PATH_TEST_SOURCE ${PROJECT_SOURCE_DIR}/api/paths.cpp)

# ------------------------------------------------------------------------------
# API

set(API_TEST_SOURCE
    ${PROJECT_SOURCE_DIR}/api/blockchain.cpp
    ${PROJECT_SOURCE_DIR}/api/blocks.cpp
    ${PROJECT_SOURCE_DIR}/api/delegates.cpp
    ${PROJECT_SOURCE_DIR}/api/entities.cpp
    ${PROJECT_SOURCE_DIR}/api/locks.cpp
    ${PROJECT_SOURCE_DIR}/api/node.cpp
    ${PROJECT_SOURCE_DIR}/api/peers.cpp
    ${PROJECT_SOURCE_DIR}/api/rounds.cpp
    ${PROJECT_SOURCE_DIR}/api/transactions.cpp
    ${PROJECT_SOURCE_DIR}/api/votes.cpp
    ${PROJECT_SOURCE_DIR}/api/wallets.cpp)

# ------------------------------------------------------------------------------
# ARK C++ Client Library Source

set(ARK_TEST_SOURCE
    ${CONNECTION_TEST_SOURCE}
    ${HOST_TEST_SOURCE}
    ${HTTP_TEST_SOURCE}
    ${PATH_TEST_SOURCE}
    ${API_TEST_SOURCE})

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Link ARK C++ Client to the Test Libraries
# ------------------------------------------------------------------------------

find_library(${PROJECT_NAME} PUBLIC)

add_executable(${PROJECT_NAME} ${ARK_TEST_SOURCE})

target_link_libraries(${PROJECT_NAME} ark_cpp_client gtest gmock gmock_main)

add_test(NAME test COMMAND ${PROJECT_NAME})

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Coverage 2:2
# ------------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include("${CMAKE_SOURCE_DIR}/cmake/CodeCoverage.cmake")

    setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_NAME} coverage)

    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

# ------------------------------------------------------------------------------
