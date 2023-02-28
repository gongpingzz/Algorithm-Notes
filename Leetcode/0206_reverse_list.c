/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    //迭代法，重点是提前记录下一个节点
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

    // 递归法，重点是思路清晰
    // if (head == NULL || head->next == NULL) {
    //     return head;
    // }
    // struct ListNode* newHead = reverseList(head->next);
    // head->next->next = head;
    // head->next = NULL;
    // return newHead;
}