cmake_minimum_required(VERSION 3.0)
project(algos_pp)
set(CMAKE_CXX_STANDARD 11)
add_library(algos_pp
    account.cpp account.hpp
    quicksort.cpp quicksort.hpp)