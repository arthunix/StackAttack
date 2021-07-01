# (C) 2021 Arthur Eugenio Silverio
# This CMake script is released under the Simplified BSD License (see LICENSE)

# Header file for non-native modules
include(FindPkgConfig)

# Set de minimum required version for compilation
cmake_minimum_required(VERSION 3.15)

# Set the project name and configurations
project(StackAttack)
set(CMAKE_CXX_STANDARD 11)  # set C++11 standard
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Set sependencies path for finding the allegro5 library
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(Allegro5 REQUIRED)

# Include in compilation path the library 
include_directories(${ALLEGRO_INCLUDE_DIR})
include_directories("${PROJECT_SOURCE_DIR}")

# Finally config the executable output and source code files and link the library files
add_executable(StackAttack StackAttack/StackAttack.cpp StackAttack/Block.h StackAttack/Column.h StackAttack/Hominho.h StackAttack/Space.h)
target_link_libraries(${PROJECT_NAME} ${ALLEGRO_LIBRARIES})