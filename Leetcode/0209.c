/* 我的解法1，超时了 */
int minSubArrayLen(int target, int* nums, int numsSize){
    /*
        设最小长度连续子数组为minLen，因为是连续的，这就像一个滑动窗口
        这个窗口最开始的长度又从左到右遍历数组元素所得。
        快指针fastIndex指向窗口的右边，slowIndex指向窗口的左边
        当发现满足条件 “数组中其和>=target” 的条件，则滑动窗口长度减小1，继续滑动寻找满足这个条件的窗口位置
        当窗口长度等于1，结束，或者滑出数组边界，返回此时的最小长度。结束
    */

#define SLOW_STEP 1
#define FAST_STEP 1

    int minLen = 0;
    int nextLen = 0;
    int slowIndex = 0;
    int fastIndex = 0;
    int totalLen = 0;

    while (slowIndex < numsSize && fastIndex - slowIndex < numsSize) {
        //求滑动窗口的元素和
        if (totalLen == 0) {
            for (int i = slowIndex; i <= fastIndex; i++) {
                totalLen = totalLen + nums[i]; 
            }
        }

        if (totalLen >= target) {
            if (minLen == 1) {
                return minLen;
            }
            else {
                minLen = fastIndex - slowIndex + 1;
                if (fastIndex < numsSize - 1) {
                    fastIndex++;
                    int tmp = slowIndex;
                    slowIndex = fastIndex + 1 - minLen + SLOW_STEP;
                    for (int i = slowIndex; i < slowIndex; i++) {
                        totalLen = totalLen - nums[i];
                    }
                    totalLen = totalLen + nums[fastIndex];
                }
                else {
                    slowIndex = fastIndex + 1 - minLen + SLOW_STEP;
                    totalLen = totalLen - nums[slowIndex - 1];
                }
                
            }
        }
        else {
            if (fastIndex < numsSize - 1) {
                fastIndex++;
            }
        }
    }
    return minLen;
}



/* 官方答案：滑动窗口 */
int minSubArrayLen2(int target, int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int ans = INT_MAX;
    int start = 0, end = 0;
    int sum = 0;
    while (end < numsSize) {
        sum += nums[end];
        while (sum >= target) {
            ans = fmin(ans, end - start + 1);
            sum -= nums[start];
            start++;
            if (ans == 1) return 1;
        }
        end++;
    }
    return ans == INT_MAX ? 0 : ans;
}