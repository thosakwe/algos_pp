cmake_minimum_required(VERSION 3.0)
project(algos_pp)
set(CMAKE_CXX_STANDARD 11)
add_library(algos_pp
    account.cpp account.hpp
    quicksort.cpp quicksort.hpp)

link_libraries(algos_pp)
add_executable(dump_accounts dump_accounts.cpp)
add_executable(find_account find_account.cpp)
add_executable(sort_accounts sort_accounts.cpp)
