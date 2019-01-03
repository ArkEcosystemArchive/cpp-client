
cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-lib)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

set(PLATFORM_SRC 
	http/os/http.cpp
)

set(API_ONE_SRC 
	api/one/accounts/one_accounts.cpp
	api/one/blocks/one_blocks.cpp
	api/one/delegates/one_delegates.cpp
	api/one/loader/one_loader.cpp
	api/one/peers/one_peers.cpp
	api/one/signatures/one_signatures.cpp
	api/one/transactions/one_transactions.cpp
)

set(API_TWO_SRC 
	api/two/blocks/two_blocks.cpp
	api/two/delegates/two_delegates.cpp
	api/two/node/two_node.cpp
	api/two/peers/two_peers.cpp
	api/two/transactions/two_transactions.cpp
	api/two/votes/two_votes.cpp
	api/two/wallets/two_wallets.cpp
)

add_library(Ark-Cpp-Client-lib STATIC
	${PLATFORM_SRC}
	${API_ONE_SRC}
	${API_TWO_SRC}
)

set(cpp_client_build_include_dirs
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include/cpp-client
)
include_directories(${cpp_client_build_include_dirs})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${cpp_client_build_include_dirs}
)

target_link_libraries(${PROJECT_NAME} PUBLIC CURL::libcurl)

if (MSVC)
	target_link_libraries(${PROJECT_NAME} PUBLIC crypt32)
endif()
