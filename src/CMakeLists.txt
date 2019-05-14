
cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-lib)


include_directories(${PROJECT_SOURCE_DIR}/lib/curl/include)
include_directories(${PROJECT_SOURCE_DIR}/lib/curl/lib)
find_package(CURL CONFIG REQUIRED)

set(PLATFORM_SRC
	http/os/http.cpp
)

set(HOST_SRC
	host/host.cpp
)

set(API_PATHS_SRC
	api/paths.cpp
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
	${HOST_SRC}
	${API_PATHS_SRC}
	${API_SRC}
)

set(cpp_client_build_include_dirs
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/include/cpp-client
)

include_directories(${cpp_client_build_include_dirs})
include_directories(${PROJECT_SOURCE_DIR}/lib/)


target_include_directories( ${PROJECT_NAME} PUBLIC
	${cpp_client_build_include_dirs}
)

target_link_libraries(${PROJECT_NAME} PUBLIC curl)

if (MSVC)
	target_link_libraries(${PROJECT_NAME} PUBLIC crypt32)
endif()
