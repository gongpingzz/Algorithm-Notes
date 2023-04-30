#include "common_header.hpp"

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 找到需要遍历的真实二维数组大小
        int col = 0;
        int row = 0;
        // 异常检查
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        for (; col < matrix[0].size(); col++) {
            if (matrix[0][col] > target) {
                break;
            }
        }
        for (; row < matrix.size(); row++) {
            if (matrix[row][0] > target) {
                break;
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }

    bool findNumberIn2DArray2(vector<vector<int>>& matrix, int target) {
        // 每次选取右上角的位置的数字比较，若是
        // 1. 选取数字大于target: 剔除行
        // 2. 选取数字小于target: 剔除列
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0;
        int col = cols - 1;

        while (col >= 0 && row < rows) {
            if ( matrix[row][col] == target ) {
                return true;
            }
            else if (matrix[row][col] > target) {
                col--;
            }
            else {
                row++;
            }
        }
    }
};