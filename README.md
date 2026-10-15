# UCI SWE 241 Assignment 5

C++ solutions implemented from scratch for two tasks: checking whether
one string contains a permutation of another, and computing the minimum
number of moves to make eight chess queens non-attacking.

[TOC]

## Task 1: Permutation in string

Given two strings `s1` and `s2`, return `true` if `s2` contains a
permutation of `s1`, or `false` otherwise. In other words, return
`true` if one of `s1`'s permutations is the substring of `s2`.

### Task 1: Example 1

Input: `s1 = "ab"`, `s2 = "eidbaooo"`

Output: `true`

Explanation: `s2` contains one permutation of `s1` (`"ba"`).

### Task 1: Example 2

Input: `s1 = "ab"`, `s2 = "eidboaoo"`

Output: `false`

### Task 1: Sample test cases

Write sample test cases that validate the implementation, including:

1.  `s1 = "ab"`, `s2 = "eidbaooo"` returns `true`.
2.  `s1 = "ab"`, `s2 = "eidboaoo"` returns `false`.
3.  `s1` longer than `s2` returns `false`.

## Task 2: Eight queens minimum moves

An 8x8 chess board has 8 queens placed randomly, one per column, so no
two queens attack vertically. Some queens may attack horizontally or
diagonally. Move queens vertically only, changing their row positions
but not their columns, until no two queens attack each other. A move
moves a queen from `(R1, C)` to `(R2, C)` where `1 <= R1, R2 <= 8`
and `R1 != R2`. Find the minimum number of moves required.

Each input consists of a line containing 8 integers. All integers are
in the range `[1, 8]`. The i-th integer indicates the row position of
the queen in the i-th column.

### Task 2: Example 1

Input: `1 2 3 4 5 6 7 8`

Output: `7`

### Task 2: Example 2

Input: `1 1 1 1 1 1 1 1`

Output: `7`

### Task 2: Sample test cases

Write sample test cases that validate the implementation, including:

1.  `1 2 3 4 5 6 7 8` returns `7`.
2.  `1 1 1 1 1 1 1 1` returns `7`.
