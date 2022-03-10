cmake_minimum_required(VERSION 3.16)
project(type_conversion VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest CONFIG REQUIRED)
find_package(Boost CONFIG REQUIRED Boost::headers)
find_package(benchmark CONFIG REQUIRED)

add_subdirectory(type_conversion)
add_subdirectory(test)
add_subdirectory(benchmark)