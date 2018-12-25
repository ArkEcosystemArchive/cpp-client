
cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-lib)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

set(PLATFORM_SRC 
	http/os/http.cpp
)

set(API_SRC 
	api/blocks/blocks.cpp
	api/delegates/delegates.cpp
	api/node/node.cpp
	api/peers/peers.cpp
	api/transactions/transactions.cpp
	api/votes/votes.cpp
	api/wallets/wallets.cpp
)

add_library(Ark-Cpp-Client-lib STATIC
	${PLATFORM_SRC}
	${API_SRC}
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
