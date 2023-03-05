/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getListLength(struct ListNode* head){
    int length = 0;
    while(head){
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    int length = getListLength(head);
    struct ListNode* cur = dummy;
    for(int i = 0; i < length - n; i++){
        cur = cur->next;
    }
    cur->next = cur->next->next;
    return dummy->next;
}

/**
    1. 函数调用会花费更多时间，利用函数传参赋值的性质，可以不用改变头节点
    2. 27行被删除的节点内存应当被释放
*/