cmake_minimum_required(VERSION 3.2.2)

set(HUNTER_STATUS_DEBUG ON)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.29.tar.gz"
    SHA1 "797be99a8a4f4666766257563fad8aa3aa032da2"
)
project(Ark-Cpp-Client)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

if (MSVC)
	add_definitions(
		-D_CRT_SECURE_NO_WARNINGS
		-D_SCL_SECURE_NO_WARNINGS
		-DNOMINMAX
	)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif()

# clone submodules
execute_process(
	COMMAND git submodule update --init --recursive
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_subdirectory(src)
add_subdirectory(test)

