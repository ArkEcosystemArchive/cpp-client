
cmake_minimum_required(VERSION 3.2)

project(ark_cpp_client C CXX)

# ------------------------------------------------------------------------------
# External Libraries
# ------------------------------------------------------------------------------

include(${CMAKE_INSTALL_PREFIX}/cmake/External.cmake)

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# ARK C++ Cliient Source
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# API

set(API_SRC
    api/blockchain/blockchain.cpp
    api/blocks/blocks.cpp
    api/delegates/delegates.cpp
    api/entities/entities.cpp
    api/locks/locks.cpp
    api/node/node.cpp
    api/peers/peers.cpp
    api/rounds/rounds.cpp
    api/transactions/transactions.cpp
    api/votes/votes.cpp
    api/wallets/wallets.cpp)

# ------------------------------------------------------------------------------
# Http

set(HTTP_SRC http/os/http_impl.cpp)

# ------------------------------------------------------------------------------
# ARK C++ Client Library Source

set(ARK_SOURCE ${API_SRC} ${HTTP_SRC})

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Add the Source Files to the Library
# ------------------------------------------------------------------------------

add_library(${PROJECT_NAME} STATIC ${ARK_SOURCE})

# ------------------------------------------------------------------------------

set(ARK_CPP_CLIENT_INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include/cpp-client)

include_directories(${ARK_CPP_CLIENT_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME} PUBLIC ${ARK_CPP_CLIENT_INCLUDE_DIRS})

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Link against CURL
# ------------------------------------------------------------------------------

target_link_libraries(${PROJECT_NAME} PUBLIC libcurl)

# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Windows: Link to `crypt32`
# ------------------------------------------------------------------------------

if (MSVC)
    target_link_libraries(${PROJECT_NAME} PUBLIC crypt32)
endif()

# ------------------------------------------------------------------------------
