//
// Created by jeff on 10/16/26.
//

#include "permutations.h"

#include <iostream>
#include <string>
#include <cassert>

namespace {

void TestS1LengthGreaterThanS2() {
  assert(Permutations::ContainsPermutation("abcd", "abc") == false);
}

void TestS1LengthEqualS2() {
  assert(Permutations::ContainsPermutation("abc", "bca") == true);
}

void TestS1Empty() {
  assert(Permutations::ContainsPermutation("", "abc") == true);
}

void TestS1AndS2Empty() {
  assert(Permutations::ContainsPermutation("", "") == true);
}

void TestCaseSensitivity() {
  assert(Permutations::ContainsPermutation("A", "a") == false);
}

void TestS2DoesNotContainPermutation() {
  assert(Permutations::ContainsPermutation("abc", "defghij") == false);
}

void TestS2ContainsCharsNonContiguous() {
  // s2 has 'a', 'b', 'c', but not contiguously.
  assert(Permutations::ContainsPermutation("abc", "a_b_c") == false);
}

void TestS2ContainsPermutationWithDuplicates() {
  assert(Permutations::ContainsPermutation("aab", "bbaa") == true);
}

void TestS2ContainsPermutationAtStart() {
  assert(Permutations::ContainsPermutation("abc", "cabdefg") == true);
}

void TestS2ContainsPermutationAtMiddle() {
  assert(Permutations::ContainsPermutation("abc", "defbcaghi") == true);
}

void TestS2ContainsPermutationAtEnd() {
  assert(Permutations::ContainsPermutation("abc", "defghbca") == true);
}

  void TestS2EmptyWhileS1Not() {
  assert(Permutations::ContainsPermutation("abc", "") == false);
}

  void TestIncorrectCharacterFrequencies() {
  // Contiguous block of same length, but mismatched counts.
  assert(Permutations::ContainsPermutation("aab", "abb") == false);
}

  void TestOverlappingPartialMatches() {
  // 'a' matches, next 'a' breaks the "ab" sequence but starts a new valid one.
  assert(Permutations::ContainsPermutation("ab", "aab") == true);
}

  void TestNonAlphabeticCharacters() {
  // Handles spaces, punctuation, and non-alpha ASCII.
  assert(Permutations::ContainsPermutation("a b!", "xyz!b a") == true);
}

}  // namespace

int main() {
  TestS1LengthGreaterThanS2();
  TestS1LengthEqualS2();
  TestS1Empty();
  TestS1AndS2Empty();
  TestCaseSensitivity();
  TestS2DoesNotContainPermutation();
  TestS2ContainsCharsNonContiguous();
  TestS2ContainsPermutationWithDuplicates();
  TestS2ContainsPermutationAtStart();
  TestS2ContainsPermutationAtMiddle();
  TestS2ContainsPermutationAtEnd();
  TestS2EmptyWhileS1Not();
  TestIncorrectCharacterFrequencies();
  TestOverlappingPartialMatches();
  TestNonAlphabeticCharacters();

  std::cout << "All permutation tests passed successfully.\n";
  return 0;
}