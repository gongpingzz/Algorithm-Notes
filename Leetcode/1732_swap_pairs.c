#include "common_header.h"

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* prev_group_first  = NULL;
    struct ListNode* prev_group_second = NULL;
    struct ListNode* curr_group_first  = NULL;
    struct ListNode* curr_group_second = NULL;
    struct ListNode* newHead = NULL;
    struct ListNode* tmp = NULL;

    if (!head)
        return NULL;

    if (!head->next)
        return head;

    while (head) {
        if (head->next){
            //记录下一次迭代位置，避免head改变导致找不到下次迭代位置
            tmp = head->next->next;
            //两个元素一组，求当前组第一第二元素
            curr_group_first = head;
            curr_group_second = head->next;
            //改变指向关系
            curr_group_second->next = curr_group_first;
            curr_group_first->next = NULL;
            if (prev_group_first)
                prev_group_first->next = curr_group_second;
            else
                newHead = curr_group_second; //记录新的头节点

            prev_group_first = curr_group_first;
            prev_group_second = curr_group_second;

            head = tmp;
        }
        else {
            //元素总数是单数且不为1的情况（1的情况前面已经特殊处理了）
            curr_group_first = head;
            //改变关系（prev_group_first一定不为空）
            prev_group_first->next = curr_group_first;
            break;
        }
    }
    return newHead;
}

void main() {
    struct ListNode *first = malloc(sizeof(struct ListNode));
    first->val = 1;
    struct ListNode *second = malloc(sizeof(struct ListNode));
    second->val = 2;
    struct ListNode *third = malloc(sizeof(struct ListNode));
    third->val = 3;
    struct ListNode *fourth = malloc(sizeof(struct ListNode));
    fourth->val = 4;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    struct ListNode *head = first;

    struct ListNode *ret = swapPairs(head);
    printSingleLinkedList(ret);
}
