#include "chess.h"

#include <array>

bool Chess::IsValidBoard(const std::vector<size_t> &queen_positions) {
    std::array<bool,9> seen_positions = {};
    // Check if any queens are on the same row
    for (auto& q_pos : queen_positions) {
        if (seen_positions[q_pos]) {
            return false;
        }
        seen_positions[q_pos] = true;
    }
    // Check if any queens are diagonal of each other
    for (size_t col1 = 0; col1 < queen_positions.size(); ++col1) {
        // Check the diagonal going up the board
        size_t up = queen_positions[col1];
        for (size_t col2 = col1 + 1; col2 < queen_positions.size() && --up > 0; ++col2) {
            if (up == queen_positions[col2]) {
                return false;
            }
        }
        // Check the diagonal going down the board
        size_t down = queen_positions[col1];
        for (size_t col2 = col1 + 1; col2 < queen_positions.size() && ++down <= queen_positions.size(); ++col2) {
            if (down == queen_positions[col2]) {
                return false;
            }
        }
    }
    return true;
}

size_t Chess::NumberOfMoves(const std::vector<size_t>& original_positions,
    const std::vector<size_t>& new_positions) {
    size_t moves = 0;
    for (std::size_t i = 0; i < new_positions.size(); ++i) {
        if (original_positions[i] != new_positions[i]) {
            moves++;
        }
    }
    return moves;
}

size_t Chess::BackTrackMinimumMoves(const std::vector<size_t>& original_queen_positions,
std::vector<size_t>& queen_positions, size_t min_moves) {
    if (queen_positions.size() == 8) {
        if (IsValidBoard(queen_positions)) {
            return std::min(min_moves, NumberOfMoves(original_queen_positions, queen_positions));
        }
        return min_moves;
    }
    queen_positions.push_back(0);
    for (size_t row = 1; row <= 8; ++row) {
        queen_positions.back() = row;
        if (IsValidBoard(queen_positions)) {
            min_moves = std::min(min_moves,
                                 BackTrackMinimumMoves(original_queen_positions, queen_positions, min_moves));
        }
    }
    queen_positions.pop_back();
    return min_moves;
}

size_t Chess::MinimumMoves(const std::vector<size_t>& queen_positions) {
    if (IsValidBoard(queen_positions)) {
        return 0;
    }

    std::vector<size_t> new_positions = {};
    return BackTrackMinimumMoves(queen_positions, new_positions, 8);
}