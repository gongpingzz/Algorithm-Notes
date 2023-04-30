#include "common_header.hpp"

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;\
        int midIndex = leftIndex;

        while (numbers[leftIndex] >= numbers[rightIndex]) {
            // 如果index1和index2指向相邻的两个数，
            // 则index1指向第一个递增子数组的最后一个数字，
            // index2指向第二个子数组的第一个数字，也就是数组中的最小数字
            if (rightIndex - leftIndex == 1) {
                midIndex = rightIndex;
                break;
            }

            // 如果下标为index1、index2和indexMid指向的三个数字相等，
            // 则只能顺序查找
            if(numbers[leftIndex] == numbers[midIndex] && numbers[midIndex] == numbers[rightIndex])
                return MinInOrder(numbers, leftIndex, rightIndex);

            midIndex = (leftIndex + rightIndex) / 2;
            if (numbers[midIndex] >= numbers[leftIndex]) {
                leftIndex = midIndex;
            }
            else if (numbers[midIndex] <= numbers[rightIndex]) {
                rightIndex = midIndex;
            }
        }
        return numbers[midIndex];
    }

    int MinInOrder(vector<int>& numbers, int index1, int index2)
    {
        int result = numbers[index1];
        for(int i = index1 + 1; i <= index2; ++i)
        {
            if(result > numbers[i])
                result = numbers[i];
        }
        return result;
    }

};