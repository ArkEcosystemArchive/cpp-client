
# ------------------------------------------------------------------------------
# CURL
# ------------------------------------------------------------------------------

set(BUILD_TESTING OFF)
set(HTTP_ONLY ON)
set(CURL_STATICLIB YES)
set(CURL_STATIC_CRT ON)
option(CMAKE_USE_LIBSSH2 OFF)
option(BUILD_CURL_EXE OFF)

if (APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl/lib")
    set(OPENSSL_INCLUDE_DIR "/usr/local/opt/openssl/include")
endif()

# Set the configuration
configure_file(${CMAKE_INSTALL_PREFIX}/cmake/extern/CURL.txt.in
               ${EXTERNAL_LIBRARY_DIR}/curl/CMakeLists.txt)

# Execute Git Clone and run Cmake
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${EXTERNAL_LIBRARY_DIR}/curl)

if(result)
    message(FATAL_ERROR "cURL: CMake Failed: ${result}")
endif()

# Build the Cloned Repo
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${EXTERNAL_LIBRARY_DIR}/curl)

if(result)
    message(FATAL_ERROR "cURL: Build Failed: ${result}")
endif()

add_subdirectory("${EXTERNAL_LIBRARY_DIR}/curl/src"
                 "${EXTERNAL_LIBRARY_DIR}/curl/build"
                 EXCLUDE_FROM_ALL)

set(CURL_INCLUDE_DIR
    ${EXTERNAL_LIBRARY_DIR}/curl/src/include
    CACHE INTERNAL "cURL: Include Folder Path")

if (MSVC)
    set(CURL_LIBRARY ${EXTERNAL_LIBRARY_DIR}/curl/src/build/lib)
    find_package(CURL)
    include_directories(${CURL_INCLUDE_DIRS})
    link_directories(${CURL_LIBRARIES})
endif()

# ------------------------------------------------------------------------------
