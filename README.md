# Project
A header only templated functions to convertor basice types to/from std::string
The purpose of this project is to provide boost:lexical_cast like functionality, using C++ standard functions such as std::stoi, stof, stoul, std::to_string, etc.

# Requirment
* GTest required for testing
* Boost::format is required for profiling
* Optionally you could install conan to get boost libs or simply provide the include path to boost::lexical_cast.hpp
* To install conan package manager simply install it by
```
pip install conan
```

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

# Run profiling
```
<project_folder>/build/profiling/profiling
```

# Benchmark result
```
Run on (24 X 3792.88 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x12)
  L1 Instruction 32 KiB (x12)
  L2 Unified 512 KiB (x12)
  L3 Unified 16384 KiB (x1)
Load Average: 0.08, 0.02, 0.01
----------------------------------------------------------------
Benchmark                      Time             CPU   Iterations
----------------------------------------------------------------
BM_Boost_Lexical_Cast        594 ns          594 ns      1151549
BM_standard_functions        362 ns          362 ns      1936437
```
