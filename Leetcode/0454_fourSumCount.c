#include "common_header.h"

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct hashTable* hashtable;

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size){
    int ikey = 0, ans = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            ikey = nums1[i] + nums2[j];
            struct hashTable *tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if (tmp == NULL) {
                tmp = malloc(sizeof *tmp);
                tmp->key = ikey;
                tmp->val = 1;
                HASH_ADD_INT(hashtable, key, tmp);
            }
            else {
                tmp->val += 1;
            }
        }
    }

    for (int k = 0; k < nums3Size; k++) {
        for (int l = 0; l < nums4Size; l++) {
            ikey = -nums3[k] - nums4[l];
            struct hashTable *tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if (tmp != NULL) {
                ans += tmp->val;
            }
        }
    }
    return ans;
}

void main(){
    int nums1[] = {1, 2};
    int nums2[] = {-2, -1};
    int nums3[] = {-1, 2};
    int nums4[] = {0, 2};
    int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
    int nums3Size = sizeof(nums3)/sizeof(nums3[0]);
    int nums4Size = sizeof(nums4)/sizeof(nums4[0]);

    int ret = fourSumCount(nums1, nums1Size, nums2, nums2Size, nums3, nums3Size, nums4, nums4Size);
    printf("ret is %d\n", ret);
}