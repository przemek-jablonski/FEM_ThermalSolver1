cmake_minimum_required(VERSION 3.3)
project(MesThermalSolver1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GlobalData.cpp GlobalData.h Node.cpp Node.h FiniteElement.cpp FiniteElement.h FEMGrid.cpp FEMGrid.h)
add_executable(MesThermalSolver1 ${SOURCE_FILES})