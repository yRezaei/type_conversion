cmake_minimum_required(VERSION 3.1)
project(type_conversion)
set(CMAKE_CXX_STANDARD 14)

find_package(Boost CONFIG REQUIRED headers)

add_executable(type_conversion main.cpp)

target_link_libraries( type_conversion Boost::headers)