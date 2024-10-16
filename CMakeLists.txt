
cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(AntAlgorithm VERSION 1.0)

# file(GLOB_RECURSE CLASSES_FILES classes/*.cpp)

# add_library(GraphClass STATIC ./libs/Graph/Graph.cpp ./libs/Graph/Graph.h)

add_executable(AntAlgorithm main.cpp)

# target_link_libraries(AntAlgorithm PUBLIC GraphClass)
