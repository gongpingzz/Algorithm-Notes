/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    //找到负数与非负数的分界线
    int negative = -1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < 0) {
            negative = i;
        } else {
            break;
        }
    }

    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    int i = negative, j = negative + 1;
    while (i >= 0 || j < numsSize) {
        if (i < 0) { //全是正数
            ans[(*returnSize)++] = nums[j] * nums[j];
            ++j;
        } else if (j == numsSize) { //全是负数
            ans[(*returnSize)++] = nums[i] * nums[i];
            --i;
        } else if (nums[i] * nums[i] < nums[j] * nums[j]) {
            ans[(*returnSize)++] = nums[i] * nums[i];
            --i;
        } else {
            ans[(*returnSize)++] = nums[j] * nums[j];
            ++j;
        }
    }

    return ans;
}