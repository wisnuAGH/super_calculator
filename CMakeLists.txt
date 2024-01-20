cmake_minimum_required(VERSION 3.20)
project(super_calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(super_calculator main.cpp SuperCalculator.cpp SuperCalculator.h menu.cpp menu.h tests/CalculatorTest.cpp)
