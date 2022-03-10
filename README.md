# Project
A header only templated functions to convertor basice types to/from std::string
The purpose of this project is to provide boost:lexical_cast like functionality, using C++ standard functions such as std::stoi, stof, stoul, std::to_string, etc.

# Requirment
* GTest required for testing
* Boost::format is required for benchmark
* Goodle benchmark required for performance mesaure
* I used conan to handle thirdparty libs used for test and benchmark. To install conan run the following command:
```
pip install conan
```
* You could also provide required packages include and lib directory instead of using conan package manager.

# How to build
Run the following comands in project folder
```
mkdir build && cd build
conan install ..
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build . --config Release 
```

# Run test
```
<project_folder>/build/test/test
```

# Run benchmark
```
<project_folder>/build/benchmark/benchmark
```

# Benchmark result
```
Run on (24 X 3792.88 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x12)
  L1 Instruction 32 KiB (x12)
  L2 Unified 512 KiB (x12)
  L3 Unified 16384 KiB (x1)
Load Average: 0.20, 0.13, 0.04
--------------------------------------------------------------------------
Benchmark                                Time             CPU   Iterations
--------------------------------------------------------------------------
BM_LexicalCast_int_to_string          53.3 ns         53.3 ns     12963755
BM_std_int_to_string                  32.1 ns         32.1 ns     21713748

BM_LexicalCast_double_to_string        510 ns          510 ns      1367575
BM_std_double_to_string                296 ns          296 ns      2378989

BM_LexicalCast_string_to_int          19.1 ns         19.1 ns     35271573
BM_std_string_to_int                  17.5 ns         17.5 ns     39949641

BM_LexicalCast_string_to_double        332 ns          332 ns      2109632
BM_std_string_to_double               74.3 ns         74.3 ns      9388198

BM_LexicalCast_string_to_bool        0.000 ns        0.000 ns   1000000000
BM_std_string_to_bool                0.000 ns        0.000 ns   1000000000

BM_LexicalCast_bool_to_string         30.8 ns         30.8 ns     22762000
BM_std_bool_to_string                 19.9 ns         19.9 ns     34944386
```
