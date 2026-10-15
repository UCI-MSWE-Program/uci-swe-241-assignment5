cmake_minimum_required(VERSION 4.3)
project(uci_swe_241_assignment5)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(permutations_tests
        permutations_tests.cc
        permutations.cc
        permutations.h)

add_executable(chess_tests
        chess_tests.cc
        chess.cc
        chess.h)

enable_testing()
add_test(NAME permutations_tests COMMAND permutations_tests)
add_test(NAME chess_tests COMMAND chess_tests)
