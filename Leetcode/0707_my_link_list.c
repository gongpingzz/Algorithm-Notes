#include "common_header.h"

typedef struct {
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* tmp = malloc(sizeof(MyLinkedList));
    if (tmp == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    memset(tmp, 0, sizeof(MyLinkedList));
    return tmp;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* curr = obj;
    while (index) {
        if (curr->next) {
            curr = curr->next;
        }
        else{
            return -1;
        }
        index--;
    }
    printf("func=myLinkedListGet: return %d\n", curr->val);
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* tmp = myLinkedListCreate();
    if (tmp == NULL) {
        printf("create new node failed\n");
        return;
    }
    tmp->next = obj->next;
    tmp->val = val;
    obj->next = tmp;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* tmp = obj;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    MyLinkedList* tmp2 = myLinkedListCreate();
    tmp2->val = val;
    tmp->next = tmp2;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* prev = NULL;
    MyLinkedList* curr = obj;
    while (index) {
        if (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        else {
            return;
        }
        index--;
    }
    MyLinkedList* tmp = myLinkedListCreate();
    tmp->val = val;
    tmp->next = curr;  
    prev->next =  tmp;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* prev = NULL;
    MyLinkedList* curr = obj;
    while (index) {
        if (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        else {
            return;
        }
        index--;
    }
    prev->next = curr->next;
    if (curr) {
        free(curr);
        curr = NULL;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* tmp = NULL;
    while (obj) {
        tmp = obj;
        free(tmp);
        obj = NULL;
        obj = obj->next;
    }
}

void printLinkedList(MyLinkedList* obj) {
    while (obj->next) {
        MyLinkedList* tmp = obj->next;
        printf("%d -> ", tmp->val);
        obj = obj->next;
    }
    printf("\n");
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