/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct HashTable {
    struct ListNode* key;
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tmp = headA;
    struct HashTable *hashTable = NULL; 
    while(tmp != NULL){
        // 添加到hash表
        struct HashTable *tmp2 = NULL;
        HASH_FIND(hh, hashTable, &tmp, sizeof(struct HashTable *),tmp2);
        if (tmp2 == NULL) {
            tmp2 = malloc(sizeof(struct HashTable)); 
            tmp2->key = tmp;
            HASH_ADD(hh, hashTable, key, sizeof(struct HashTable *), tmp2);
        }
        tmp = tmp->next;
    }
    tmp = headB;
    while(tmp != NULL){
        struct HashTable *tmp2 = NULL;
        HASH_FIND(hh, hashTable, &tmp, sizeof(struct HashTable *),tmp2);
        if (tmp2 != NULL) {
            return tmp2->key;
        }
        tmp = tmp->next;
    }
    return NULL;
}