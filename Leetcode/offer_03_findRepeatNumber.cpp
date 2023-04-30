#include "common_header.hpp"

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 方法1：先排序，再遍历
        std::sort(nums.begin(), nums.end());
        int pre = -1;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] == pre) {
                std::cout << nums[i] << std::endl;
                return nums[i];
            }
            pre = nums[i];
        }
        return -1;
    }
    
    int findRepeatNumber2(vector<int>& nums) {
        // 方法2：使用hash
        std::unordered_set<int> us;
        for (auto v : nums) {
            if (us.find(v) != us.end())
            {
                std::cout << v << std::endl;
                return v;
            }
            us.insert(v);
        }
        return -1;
    }

    /** 每个数字交换两次都能找到自己的位置，n个数字，就是2n此，所以时间复杂度是O(n) */
    int findRepeatNumber3(vector<int>& nums) {
        // 因为长度为n, 数字为0~n-1, 所以不重复的情况下，数组下标与对应的数组元素的值应该相等
        // 下标    ：0 1 2 3 ... n-1
        // 对应的值 ：0 1 2 3 ... n-1
        for (auto i = 0; i < nums.size(); i++) {
            while (i != nums[i]) {
                if (nums[nums[i]] != nums[i]) {
                    std::swap(nums[i], nums[nums[i]]);
                }
                else {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};