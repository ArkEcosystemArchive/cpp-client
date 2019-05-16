cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-lib)

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
include_directories(${PROJECT_SOURCE_DIR})

# ------------------------------------------------------------------------------
# curl
# ------------------------------------------------------------------------------

set(BUILD_TESTING OFF)
set(HTTP_ONLY ON)
set(CMAKE_USE_LIBSSH2 OFF)

include_directories(${PROJECT_SOURCE_DIR}/lib/curl/include)

if (UNIX AND NOT APPLE)
  add_subdirectory(${PROJECT_SOURCE_DIR}/lib/curl)
	target_link_libraries(${PROJECT_NAME} PUBLIC libcurl)
else()
	target_link_libraries(${PROJECT_NAME} PUBLIC CURL)
endif()

# ------------------------------------------------------------------------------

target_include_directories(${PROJECT_NAME} PUBLIC
	${cpp_client_build_include_dirs}
)

if (MSVC)
	target_link_libraries(${PROJECT_NAME} PUBLIC crypt32)
endif()
