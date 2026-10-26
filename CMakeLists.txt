cmake_minimum_required(VERSION 3.20)
project(AlgoGym CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/*.cpp)
list(FILTER SOURCES EXCLUDE REGEX "cmake-build-")

foreach(src ${SOURCES})
    file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${src})
    string(REPLACE "/" "_" name ${rel})
    string(REPLACE ".cpp" "" name ${name})
    add_executable(${name} ${src})
endforeach()