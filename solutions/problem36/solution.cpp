#include "solution.hpp"
#include <vector>
#include <set>

bool Solution::isValidSudoku(std::vector<std::vector<char>> &board)
{

    std::vector<std::set<char>> rowElement(9);    // 9 sets, one per Row
    std::vector<std::set<char>> columnElement(9); // 9 sets, one per Column
    std::vector<std::set<char>> subMatrix(9);     // 9 sets, one per subMatrix
    for (int i = 0; i < board.size(); i++)
    { // row i
        for (int j = 0; j < board[0].size(); j++)
        { // column j
            if (board[i][j] == '.')
            {
                continue;
            }
            // check on the rows
            if (rowElement[i].find(board[i][j]) == rowElement[i].end())
            {
                rowElement[i].insert(board[i][j]);
            }
            else
            {
                return false; // we found a duplicate on the row
            }

            // check on the columns
            if (columnElement[j].find(board[i][j]) ==
                columnElement[j].end())
            {
                columnElement[j].insert(board[i][j]);
            }
            else
            {
                return false; // we found a duplicate on the row
            }
            int k = i / 3;
            int l = j / 3;
            // Working on SubMatrix id: l+3k
            if (subMatrix[l + 3 * k].find(board[i][j]) ==
                subMatrix[l + 3 * k].end())
            {
                subMatrix[l + 3 * k].insert(board[i][j]);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
