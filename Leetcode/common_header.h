#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printSingleLinkedList(struct ListNode *head){
    while(head){
        if (head->next)
            printf("%d -> ", head->val);
        else
            printf("%d -> NULL\n", head->val);
        head = head->next;
    }
}