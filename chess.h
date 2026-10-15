//
// Created by jeff on 10/15/26.
//

#ifndef UCI_SWE_241_ASSIGNMENT5_CHESS_H
#define UCI_SWE_241_ASSIGNMENT5_CHESS_H
#include <vector>


/**
 * Computes the minimum number of moves to make eight queens non-attacking.
 *
 * The board is an 8x8 grid with one queen per column, encoded as a vector
 * of eight row positions (each in [1, 8]) indexed by column. Queens may
 * move vertically only, i.e. change rows within their column. `MinimumMoves`
 * exhaustively searches all candidate arrangements, pruning partial
 * arrangements that already contain attacking queens, and returns the fewest
 * queens that must change rows to reach any non-attacking arrangement.
 */
class Chess {
public:
    Chess() = default;

    /**
     * Returns the minimum number of vertical moves required to transform
     * `queen_positions` (eight row values in [1, 8], one per column) into a
     * non-attacking arrangement, or 0 if the arrangement is already valid.
     *
     * Time complexity: O(8^9) worst case; the backtracking search tree has
     * at most 8^8 nodes and each node validates its (partial) board in
     * O(8), though pruning usually reduces the explored space substantially.
     * Space complexity: O(1); the recursion depth and candidate vector hold
     * at most eight queens.
     */
    [[nodiscard]] static size_t MinimumMoves(const std::vector<size_t>& queen_positions);


private:
    /**
     * Returns the number of columns whose queen row differs between
     * `original_positions` and `new_positions`.
     *
     * Time complexity: O(k), where k is the number of queens (8).
     * Space complexity: O(1).
     */
    [[nodiscard]] static size_t NumberOfMoves(const std::vector<size_t>& original_positions, const std::vector<size_t>& new_positions);

    /**
     * Returns true if no two queens attack each other: all queens occupy
     * distinct rows and no pair shares an upward or downward diagonal.
     *
     * Time complexity: O(k^2) worst case for k queens; each column scans at
     * most k - 1 diagonal steps in each direction. For the fixed eight-queen
     * board this is O(1).
     * Space complexity: O(1); the row-seen table is a fixed-size array.
     */
    [[nodiscard]] static bool IsValidBoard(const std::vector<size_t> &queen_positions);

    /**
     * Backtracking search that fills `queen_positions` column by column with
     * rows in [1, 8], pruning any partial arrangement that already contains
     * attacking queens, and returns the smallest move count among all valid
     * complete arrangements, bounded above by `min_moves`.
     *
     * Time complexity: O(8^9) worst case (see `MinimumMoves`).
     * Space complexity: O(1); at most eight recursive frames.
     */
    [[nodiscard]] static size_t BackTrackMinimumMoves(const std::vector<size_t>& original_queen_positions,
  std::vector<size_t>& queen_positions, size_t min_moves);
};


#endif //UCI_SWE_241_ASSIGNMENT5_CHESS_H
