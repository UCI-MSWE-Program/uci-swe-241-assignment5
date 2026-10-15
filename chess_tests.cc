//
// Created by jeff on 10/16/26.
//

#include "chess.h"

#include <cassert>
#include <iostream>
#include <vector>

namespace {
// chess_tests.cc

void TestAlreadyValidBoard() {
  // A known valid 8-queens configuration.
  const std::vector<size_t> kValidBoard = {4, 2, 7, 3, 6, 8, 5, 1};
  assert(Chess::MinimumMoves(kValidBoard) == 0);
}

void TestSequentialBoard() {
  // The main diagonal configuration. Max matches with any valid board is 1.
  const std::vector<size_t> kBoard = {1, 2, 3, 4, 5, 6, 7, 8};
  assert(Chess::MinimumMoves(kBoard) == 7);
}

void TestAllSameRow() {
  // All queens on the first row. Max matches with any valid board is 1.
  const std::vector<size_t> kBoard = {1, 1, 1, 1, 1, 1, 1, 1};
  assert(Chess::MinimumMoves(kBoard) == 7);
}

void TestTwoMovesRequired() {
  // Started with valid {4, 2, 7, 3, 6, 8, 5, 1} and changed the first two
  // columns to 1. This means 6 queens are currently in a valid placement.
  const std::vector<size_t> kBoard = {1, 1, 7, 3, 6, 8, 5, 1};
  assert(Chess::MinimumMoves(kBoard) == 2);
}

void TestFourMovesRequired() {
  // Started with valid {4, 2, 7, 3, 6, 8, 5, 1} and changed the last five
  // columns to 1. Columns 0, 1, 2, and 7 (already row 1) can stay put, so
  // only the four middle columns need to move.
  const std::vector<size_t> kBoard = {4, 2, 7, 1, 1, 1, 1, 1};
  assert(Chess::MinimumMoves(kBoard) == 4);
}

}

int main() {
  TestAlreadyValidBoard();
  TestSequentialBoard();
  TestAllSameRow();
  TestTwoMovesRequired();
  TestFourMovesRequired();

  std::cout << "All chess tests passed successfully.\n";
  return 0;
}