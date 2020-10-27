#include "array.h"
using namespace std;

/* 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素 */
vector<int> Solution::findDiagonalOrder(vector<vector<int>>& matrix) 
{
    if (matrix.size() <= 0)
    {
        return {};
    }
    // get the row and column of matrix
    int N = matrix.size(); //row
    int M = matrix[0].size();  //column
    vector<int> tmp; 
    vector<int> res; //返回结果的vector
    /* 外部循环遍历所有的对角线 */
    for (int d = 0; d < M + N - 1; d++) {
        /* 求对角线的第一个元素 */
        int r = d < M ? 0 : d - M + 1;
        int c = d < M ? d : M - 1;

        /* 遍历对角线 */
        while (d < N && c >= 0)
        {
            tmp.push_back(matrix[r][c]); 
            r++;
            c--;
        }
        /* 元素反转 */
        if (d % 2 == 0) 
        {   
            reverse(tmp.begin(), tmp.end());
        }
        /* 添加到输出 */
        for (vector<int>::iterator iter  = tmp.begin(); iter != tmp.end(); iter++)
        {
            res.push_back(*iter);
        }
        /* 临时vector清空 */
        tmp.clear();
    }
    return res;
}


/**
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
*/
string Solution::longestCommonPrefix(vector<string>& strs) {
    unsigned int size = strs.size();
    //vector为空
    if (strs.size() <= 0)
    {
        return "";
    }
    //求出vector中最短的字符串
    int len = strs[0].size();
    for (auto it = strs.begin(); it != strs.end(); it++) 
    {
        if ((*it).size() < len)
        {
            len = (*it).size();
        }
    }
    //求最长公共前缀
    string res = "";
    for (unsigned int i = 0; i < len; i++)
    {
        for (unsigned int j = 0; j < size-1; j++)
        {
            if(strs[j][i] != strs[j+1][i]) return res;
        }
        res.push_back(strs[0][i]);
    }
    return res;
}
