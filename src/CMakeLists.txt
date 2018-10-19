
cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-lib)

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
include_directories(${PROJECT_SOURCE_DIR})

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

set(PLATFORM_SRC 
	${PROJECT_SOURCE_DIR}/http/os/http.cpp
)

set(API_ONE_SRC 
	${PROJECT_SOURCE_DIR}/api/one/accounts/one_accounts.cpp
	${PROJECT_SOURCE_DIR}/api/one/blocks/one_blocks.cpp
	${PROJECT_SOURCE_DIR}/api/one/delegates/one_delegates.cpp
	${PROJECT_SOURCE_DIR}/api/one/loader/one_loader.cpp
	${PROJECT_SOURCE_DIR}/api/one/peers/one_peers.cpp
	${PROJECT_SOURCE_DIR}/api/one/signatures/one_signatures.cpp
	${PROJECT_SOURCE_DIR}/api/one/transactions/one_transactions.cpp
)

set(API_TWO_SRC 
	${PROJECT_SOURCE_DIR}/api/two/blocks/two_blocks.cpp
	${PROJECT_SOURCE_DIR}/api/two/delegates/two_delegates.cpp
	${PROJECT_SOURCE_DIR}/api/two/node/two_node.cpp
	${PROJECT_SOURCE_DIR}/api/two/peers/two_peers.cpp
	${PROJECT_SOURCE_DIR}/api/two/transactions/two_transactions.cpp
	${PROJECT_SOURCE_DIR}/api/two/votes/two_votes.cpp
	${PROJECT_SOURCE_DIR}/api/two/wallets/two_wallets.cpp
)

add_library(Ark-Cpp-Client-lib STATIC
	${PLATFORM_SRC}
	${API_ONE_SRC}
	${API_TWO_SRC}
)

target_link_libraries(Ark-Cpp-Client-lib
	PUBLIC
	CURL::libcurl
)

if (MSVC)
	target_link_libraries(Ark-Cpp-Client-lib PUBLIC crypt32)
endif()
