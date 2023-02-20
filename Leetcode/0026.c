/*
    利用双指针,需要优化
*/ 
int removeDuplicates_1(int* nums, int numsSize){
    int i,j,k;
    i = 1;
    j = 1;

    while(j < numsSize){
        k = j - i;
        while(k && j < numsSize && nums[j] > nums[i - 1] ){
            nums[i] = nums[j];
            k--;
            i++;
        }

        //寻找下一个升序排列的重复元素
        if(nums[i] > nums[i - 1]){
            i++;
        }
        //j寻找下一个升序排列的不重复元素
        j++;        
    }
    return i;
}