#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    /* 对角线遍历 */
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix);

    /* 最长公共前缀 */
    string longestCommonPrefix(vector<string>& strs);

    /* 最长回文子串 */
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    /* 实现strStr() */
    int* bulid_next(string p) {
        int len = p.size();
        int i = 0, j = -1;
        int* next = new int[len];
        next[0] = -1;
        while (i < len-1) {
            if (j < 0 || p[i] == p[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int m = haystack.size();
        int n = needle.size();
        /* 特判 */
        if (m <= 0 && n <= 0) return 0;
        if (m <= 0 && n > 0) return -1;
        if (m > 0 && n <= 0) return 0;
        int* next = bulid_next(needle);
        while (i < m && j < n) {
            if (j < 0 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }
        if (j != n) return -1;
        return i - j;
    }


};