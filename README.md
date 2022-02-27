# Project
A set of function to convertor basice types
The driving is to have one to one or approximate verion of boost:lexical_cast in standard library

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