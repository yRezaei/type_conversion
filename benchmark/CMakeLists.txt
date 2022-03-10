
add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark type_conversion Boost::headers benchmark::benchmark)