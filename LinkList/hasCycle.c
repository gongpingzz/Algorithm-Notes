#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MySignalLinkedList.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(MyLinkedList *head) {
    //是否有环可以使用快慢指针，快指针将追上慢指针
    //空链表
    if(!head)
        return false;
    //只有一个节点
    if(!head->next || !head->next->next)
        return false;
    MyLinkedList *fast = head->next->next;
    MyLinkedList *slow = head->next;
    while(fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}


int main(int argc, char** argv)
{
    //[-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5]
    MyLinkedList* linkedList = myLinkedListCreate();
    myLinkedListAddAtTail(linkedList, -21);
    myLinkedListAddAtTail(linkedList, 10);
    myLinkedListAddAtTail(linkedList, 17);
    myLinkedListAddAtTail(linkedList, 8);
    myLinkedListAddAtTail(linkedList, 4);
    myLinkedListAddAtTail(linkedList, 26);
    myLinkedListAddAtTail(linkedList, 5);
    myLinkedListAddAtTail(linkedList, 35);
    myLinkedListAddAtTail(linkedList, 33);
    myLinkedListAddAtTail(linkedList, -7);
    myLinkedListAddAtTail(linkedList, -16);
    myLinkedListAddAtTail(linkedList, 27);
    myLinkedListAddAtTail(linkedList, -12);
    myLinkedListAddAtTail(linkedList, 6);
    myLinkedListAddAtTail(linkedList, 29);
    myLinkedListAddAtTail(linkedList, -12);
    myLinkedListAddAtTail(linkedList, 5);
    myLinkedListAddAtTail(linkedList, 9);
    myLinkedListAddAtTail(linkedList, 20);
    myLinkedListAddAtTail(linkedList, 14);
    myLinkedListAddAtTail(linkedList, 14);
    myLinkedListAddAtTail(linkedList, 2);
    myLinkedListAddAtTail(linkedList, 13);
    myLinkedListAddAtTail(linkedList, -24);
    myLinkedListAddAtTail(linkedList, 21);
    myLinkedListAddAtTail(linkedList, 23);
    myLinkedListAddAtTail(linkedList, -21);
    myLinkedListAddAtTail(linkedList, 5);

    hasCycle(linkedList);

    return 0;
}