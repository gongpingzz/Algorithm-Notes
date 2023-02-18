/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include "uthash-master/src/uthash.h"

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct hashTable* hashtable;

struct hashTable* find( int ikey) {
    struct hashTable *s;
    
    HASH_FIND_INT(hashtable, &ikey, s);
    return s;
}

void insert(int ikey, int ival) {
    struct hashTable *tmp = find(ikey);
    if (!tmp) {
        tmp = malloc(sizeof *tmp);
        tmp->key = ikey;
        tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    }
    else {
        tmp->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find( target - nums[i]);
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val;
            ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

void main(){
    int mums[4] = {2,7,11,15};
    int retSize;
    int* ret = twoSum(mums, 4, 9, &retSize);
    if (ret) {
        printf("return size %d, first index %d, second index %d\n", retSize, ret[0], ret[1]);
    }
    else {
        printf("return size %d\n", retSize);
    }
}