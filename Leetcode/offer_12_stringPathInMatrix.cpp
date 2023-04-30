#include "common_header.hpp"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || word.size() == 0)
            return false;
        if (board[0].size() == 0)
            return false;

        int rows = board.size();
        int cols = board[0].size();
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);

        int pathLength = 0;
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                if(hasPathCore(board, rows, cols, row, col, word,
                    pathLength, visited))
                {
                    return true;
                }
            }
        }
        delete[] visited;

        return false;
    }

    bool hasPathCore(vector<vector<char>>& board, int rows, int cols, int row,
        int col, string word, int& pathLength, bool* visited)
    {
        if(word[pathLength] == '\0')
            return true;

        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols
            && board[row][col] == word[pathLength]
            && !visited[row * cols + col])
        {
            ++pathLength;
            visited[row * cols + col] = true;

            hasPath = hasPathCore(board, rows, cols, row, col - 1,
                word, pathLength, visited)
                || hasPathCore(board, rows, cols, row - 1, col,
                    word, pathLength, visited)
                || hasPathCore(board, rows, cols, row, col + 1,
                    word, pathLength, visited)
                || hasPathCore(board, rows, cols, row + 1, col,
                    word, pathLength, visited);

            if(!hasPath)
            {
                --pathLength;
                visited[row * cols + col] = false;
            }
        }
        return hasPath;
    }

};