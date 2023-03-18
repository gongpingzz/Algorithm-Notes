#include "common_header.h"

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct hashTable* hashtable;

bool canConstruct(char * ransomNote, char * magazine){
    // 把magazine放进哈希表
    for (int i = 0; i < strlen(magazine); i++) {
        struct hashTable *tmp;
        HASH_FIND_INT(hashtable, &magazine[i], tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof *tmp);
            tmp->key = magazine[i];
            tmp->val = 1;
            HASH_ADD_INT(hashtable, key, tmp);
        }
        else {
            tmp->val += 1;
        }
    }

    // 检查ransomNote
    for (int i = 0; i < strlen(ransomNote); i++) {
        struct hashTable *tmp;
        HASH_FIND_INT(hashtable, &ransomNote[i], tmp);
        if (tmp == NULL) {
            return false;
        }
        else {
            tmp->val -= 1;
            if ( tmp->val < 0 ) return false;
        }
    }
    return true;
}

void main(){
    char * ransomNote = "a";
    char * magazine = "b";
    bool ret = canConstruct(ransomNote, magazine);
    printf("ret is %d\n", ret);
}