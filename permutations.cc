#include "permutations.h"

#include <string>
#include <unordered_map>

bool Permutations::BackTrack(std::unordered_map<char, std::size_t>& character_counts,
                      const std::string& str2, const std::size_t i) {
    if (character_counts.empty()) {
        return true;
    }
    if (!character_counts.contains(str2[i])) {
        return false;
    }
    --character_counts[str2[i]];
    if (character_counts[str2[i]] == 0) {
        character_counts.erase(str2[i]);
    }
    if (BackTrack(character_counts, str2, i + 1)) {
        return true;
    }
    ++character_counts[str2[i]];
    return false;
}

bool Permutations::ContainsPermutation(const std::string& str1,
    const std::string& str2) {
    if (str1.size() > str2.size()) {
        return false;
    }
    std::unordered_map<char, std::size_t> character_counts = {};
    for (const char& c : str1) {
        ++character_counts[c];
    }
    for (std::size_t i = 0; i <= str2.length() - str1.length(); ++i) {
        if (BackTrack(character_counts, str2, i)) {
            return true;
        }
    }
    return false;
}