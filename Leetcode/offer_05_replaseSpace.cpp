#include "common_header.hpp"

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        if (s.length() <= 0) {
            return s;
        }
        int originLen = s.length();
        int numberOfBlank = std::count(s.begin(), s.end(), ' ');
        int p2 = originLen + numberOfBlank * 2;
        int p1 = originLen;
        // 需要修改s的大小
        s.resize(p2);

        while (p1 != p2) {
            if (s[p1] != ' ') {
                s[p2--] = s[p1--];
            }
            else {
                s[p2--] = '0';
                s[p2--] = '2';
                s[p2--] = '%';
                p1--;
            }
        }
        return s;
    }
};