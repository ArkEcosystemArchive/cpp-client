
cmake_minimum_required(VERSION 3.2)

project(ark_cpp_client_example)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

if (MSVC)
	add_definitions(
		-D_CRT_SECURE_NO_WARNINGS
		-D_SCL_SECURE_NO_WARNINGS
		-DNOMINMAX
	)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
 #set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

add_subdirectory(lib/cpp-client/src)

set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ark_cpp_client)
