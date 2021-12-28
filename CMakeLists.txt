cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(ising)

add_executable(ising src/lattice.cpp src/ising.cpp src/scenarios.cpp src/main.cpp)
