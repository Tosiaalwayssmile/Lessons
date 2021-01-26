cmake_minimum_required(VERSION 2.8.9)
project(wyklad_program)
include_directories(include)
set(SOURCES src/main.cpp src/ex1Functions.cpp src/ex2Functions.cpp src/ex3Functions.cpp src/ex4Functions.cpp src/ex5Functions.cpp src/inputValidation.cpp 
include/ex1Functions.h include/ex2Functions.h include/ex3Functions.h include/ex4Functions.h include/ex5Functions.h include/inputValidation.h)
add_executable(program ${SOURCES})

# Locate GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
#add_executable(executeTests zadLista3Gtest.cpp)
#target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
