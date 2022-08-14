cmake_minimum_required(VERSION 3.22)
project(30_3)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400)
FetchContent_MakeAvailable(cpr)

add_executable(30_3 main.cpp)
target_link_libraries(30_3 PRIVATE cpr::cpr)
