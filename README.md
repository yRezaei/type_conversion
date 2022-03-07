# Project
A header only templated functions to convertor basice types to/from std::string
The purpose of this project is to provide boost:lexical_cast like functionality, using C++ standard functions such as std::stoi, stof, stoul, std::to_string, etc.

# Requirment
* Boost::format is required for test case
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
