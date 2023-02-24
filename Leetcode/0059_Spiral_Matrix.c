#include "common_header.h"



/**
 * Return an array of arrays of size *returnSize. （返回的一个 元素都是 大小为n的 数组的 数组；  返回个数组a，数组a的每一个元素都是一个数组b，且数组b大小为n(*returnSize) ）
 * The sizes of the arrays are returned as *returnColumnSizes array. （ arrays的每个array的大小以*returnColumnSizes数组的形式返回，*returnColumnSizes每个元素代表一个array的大小 ）
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int num = 1;
    int** matrix = malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(int) * n);
        memset(matrix[i], 0, sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    while (left <= right && top <= bottom) {
        for (int column = left; column <= right; column++) {
            matrix[top][column] = num;
            num++;
        }
        for (int row = top + 1; row <= bottom; row++) {
            matrix[row][right] = num;
            num++;
        }
        if (left < right && top < bottom) {
            for (int column = right - 1; column > left; column--) {
                matrix[bottom][column] = num;
                num++;
            }
            for (int row = bottom; row > top; row--) {
                matrix[row][left] = num;
                num++;
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return matrix;
}