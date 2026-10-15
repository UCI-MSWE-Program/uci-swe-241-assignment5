//
// Created by jeff on 10/15/26.
//

#ifndef UCI_SWE_241_ASSIGNMENT5_PERMUTATIONS_H
#define UCI_SWE_241_ASSIGNMENT5_PERMUTATIONS_H
#include <string>
#include <unordered_map>
#include <vector>


/**
 * Determines whether one string contains a permutation of another.
 *
 * `ContainsPermutation` answers whether some contiguous substring of
 * `str2` is a permutation of `str1`, e.g. ("ab", "eidbaooo") is true
 * because "ba" is a permutation of "ab".
 */
class Permutations {
public:
    Permutations() = default;

    /**
     * Returns true if `str2` contains a substring that is a permutation of
     * `str1`, and false otherwise.
     *
     * For each of the (n - m + 1) candidate start positions in `str2`,
     * `BackTrack` greedily consumes the longest contiguous prefix whose
     * characters are all unused characters of `str1`; it succeeds exactly
     * when a contiguous block consumes every character of `str1`, i.e. that
     * block is a permutation of `str1`.
     *
     * Time complexity: O(m * n), where m = str1.size() and n = str2.size();
     * each start position may scan up to m characters.
     * Space complexity: O(m) for the character-count map plus O(m) for the
     * `BackTrack` recursion depth.
     */
    [[nodiscard]] static bool ContainsPermutation(const std::string& str1,
        const std::string& str2);

private:
    /**
     * Consumes `str2[i]` if it still has unused occurrences left in
     * `character_counts`, then recurses on `str2[i + 1]`. Returns true once
     * `character_counts` is empty, meaning the consumed contiguous prefix of
     * `str2` is a permutation of `str1`; returns false when `str2[i]` has no
     * remaining occurrences or the string is exhausted.
     *
     * Time complexity: O(k) per call, where k is the number of characters
     * remaining in `character_counts` (at most m), since each recursion
     * level consumes one character.
     * Space complexity: O(k) for the recursion depth.
     */
    [[nodiscard]] static bool BackTrack(std::unordered_map<char, std::size_t>& character_counts,
    const std::string& str2, std::size_t i);

};


#endif //UCI_SWE_241_ASSIGNMENT5_PERMUTATIONS_H
