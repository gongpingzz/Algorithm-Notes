#include "common_header.h"
/*  
    解法1：使用双指针，指针i从前往后寻找目标值val,指针j从后往前寻找非目标值
*/

int removeElement(int* nums, int numsSize, int val){
    int i,j;
    i = 0;
    j = numsSize - 1;
    if(numsSize <= 0){ // 测试用例有空数组，后面取索引会报错
        return 0;
    }
    while(i < j){
        if(nums[i] == val && nums[j] != val){
            nums[i] = nums[j];
            nums[j] = val;
            i++;
            j--;
            continue;
        }
        if(nums[i] != val){ //移动i
            i++;
        }
        if(nums[j] == val){ //移动j
            j--;
        }
    }
    if(nums[i] == val){
        return i;
    }
    else{
        return i+1;
    }
}

/* 解法2 */
int removeElement2(int* nums, int numsSize, int val){
    int slowIndex = 0; //慢指针
    int fastIndex = 0; //快指针

    if(numsSize <= 0){
        return 0;
    }
    //寻找非目标值，i从0开始，把数组nums当成一个新数组需要被赋值，
    //j从0开始寻找非目标值，依次拷贝到i处
    for(fastIndex = 0; fastIndex < numsSize; fastIndex++){
        if(nums[fastIndex] != val){
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }
    return slowIndex;
}

void main(){
    int nums[8] = {0,1,2,2,3,0,4,2};
    int length = sizeof(nums) / sizeof(nums[0]);
    int val = 2;
    int ret = removeElement2(nums, length, val);
    printf("return %d\n", ret);
}