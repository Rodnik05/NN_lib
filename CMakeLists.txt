cmake_minimum_required(VERSION 3.0.0)
project(NN_lib VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

link_directories(NeuronsAndLayers)
link_directories(Functions)

add_subdirectory(NeuronsAndLayers)
add_subdirectory(Functions)

enable_testing()
add_subdirectory(Tests)