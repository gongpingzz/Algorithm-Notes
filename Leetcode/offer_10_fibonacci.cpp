#include "common_header.hpp"

using namespace std;

class Solution {
public:
    // 迭代
    int fib(int n) {
        const int MOD = 1000000007;
        int result[2] = {0, 1};
        
        if (n < 2) return result[n];
        
        long long fibN = 0;
        long long fibNMinusOne = 1;
        long long fibNMinusTwo = 0;
        for (int i = 2; i <= n; i++) {
            fibN = (fibNMinusOne + fibNMinusTwo) % MOD;
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        return fibN;
    }
    // 动态规划

    // 矩阵快速幂

};