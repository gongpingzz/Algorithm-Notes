/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fastPtr = head, *slowPtr = head;
    // 判空链表
    while (fastPtr != NULL){
        slowPtr = slowPtr->next;
        // 判一个节点的链表
        if (fastPtr->next == NULL) { 
            return NULL;
        }
        fastPtr = fastPtr->next->next;
        //先移动指针可以避免初始情况，快慢指针相等的情况
        if (fastPtr == slowPtr){
            struct ListNode *ptr = head;
            while(ptr != slowPtr){
                ptr = ptr->next;
                slowPtr = slowPtr->next;
            }
            return ptr;
        }
    }
    return NULL;
}