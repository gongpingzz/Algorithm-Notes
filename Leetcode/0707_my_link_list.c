#include "common_header.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    struct ListNode *head;
    int size;
} MyLinkedList;

struct ListNode *ListNodeCreat(int val) {
    struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList * obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->head = ListNodeCreat(0);
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1;
    }
    struct ListNode *cur = obj->head;
    for (int i = 0; i <= index; i++) {
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) {
        return;
    }
    index = MAX(0, index);
    obj->size++;
    struct ListNode *pred = obj->head;
    for (int i = 0; i < index; i++) {
        pred = pred->next;
    }
    struct ListNode *toAdd = ListNodeCreat(val);
    toAdd->next = pred->next;
    pred->next = toAdd;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return;
    }
    obj->size--;
    struct ListNode *pred = obj->head;
    for (int i = 0; i < index; i++) {
        pred = pred->next;
    }
    struct ListNode *p = pred->next;
    pred->next = pred->next->next;
    free(p);
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode *cur = NULL, *tmp = NULL;
    for (cur = obj->head; cur;) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj);
}


/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

void main() {
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 1);
    printLinkedList(obj);

    myLinkedListAddAtTail(obj, 3);
    printLinkedList(obj);

    myLinkedListAddAtIndex(obj, 1, 2);
    printLinkedList(obj);

    myLinkedListGet(obj, 1);

    myLinkedListDeleteAtIndex(obj, 1);
    printLinkedList(obj);

    myLinkedListGet(obj, 1);
}