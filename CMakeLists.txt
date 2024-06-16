cmake_minimum_required(VERSION 3.10)

# set the project name
project(SerializationTests)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the include directory
include_directories(include)

# add the tinyxml2 library
add_library(tinyxml2 STATIC include/tinyxml2.cpp)

# add the executable for BinTest
add_executable(BinTest test/BinTest.cpp)
target_link_libraries(BinTest PRIVATE tinyxml2)

# add the executable for XMLTest
add_executable(XMLTest test/XMLTest.cpp)
target_link_libraries(XMLTest PRIVATE tinyxml2)
