#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList_t{
    int val;
    struct MyLinkedList_t *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* vhead = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    vhead->val = 0;
    vhead->next = NULL;
    return vhead;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(!obj->next) {
        printf("list is null\n");
        return -1;
    }
    int i = 0;
    MyLinkedList* cur = obj->next;
    for(; i < index; i++){
        if(cur->next) cur = cur->next;
        else return -1;
    }
    return cur->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* head = myLinkedListCreate();
    head->val = val;
    head->next = obj->next;
    obj->next = head;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* tail = myLinkedListCreate();
    tail->val = val;
    while(obj->next)
    {
        obj = obj->next;
    }
    obj->next = tail;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    //空链表或者索引小于等于0，插入头部
    if(!obj->next || index <= 0){
        myLinkedListAddAtHead(obj, val);
        return;
    }

    MyLinkedList* tmp = myLinkedListCreate();
    tmp->val = val;
    MyLinkedList* prev = obj;

    while(index && prev->next){
        prev = prev->next;
        index--;
    }
    if(index == 0 && prev->next){ //index less list len
        tmp->next = prev->next;
        prev->next = tmp;
    }
    else if(index == 0 && !prev->next){ //index equal list len
        prev->next = tmp;
    }
    else{ //index greater list len
        printf("index greater list len, the node will not be inserted.\n");
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(!obj->next) {
        printf("list is null\n");
        return;
    }
    MyLinkedList* prev = obj;
    MyLinkedList* next = prev->next; //待删除结点
    while(index && next->next)
    {
        prev = next;
        next = next->next;
        index--;
    }
    if(index == 0){
        prev->next = next->next;
    }
    else{
         printf("index greater list len,the index is valid.\n");
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    obj->next = NULL;
}

/********************************************************
 *                     help function
 *******************************************************/
/* print linked list */
void printSignalLinkedList(MyLinkedList* obj){
    if(!obj->next) {
        printf("%d -> NULL\n", obj->val);
        return;
    }
    while(obj->next)
    {
        printf("%d -> ", obj->val);
        obj = obj->next;
    }
    printf("%d -> ", obj->val);
    printf("NULL\n");
}


int main(int argc, char** argv){
    int tmp = 0;

    /* test
     * ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
     * [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]   
     */
    MyLinkedList* linkedList = myLinkedListCreate();

    myLinkedListAddAtHead(linkedList, 7);
    myLinkedListAddAtHead(linkedList, 2);
    myLinkedListAddAtHead(linkedList, 1);
    printSignalLinkedList(linkedList);

    myLinkedListAddAtIndex(linkedList, 3,0);
    printSignalLinkedList(linkedList);

    myLinkedListDeleteAtIndex(linkedList, 2);

    myLinkedListAddAtHead(linkedList, 6);

    myLinkedListAddAtTail(linkedList, 4);

    tmp = myLinkedListGet(linkedList, 4);
    printf("return val = %d\n", tmp);

    myLinkedListAddAtHead(linkedList, 4);

    myLinkedListAddAtIndex(linkedList, 5, 0);

    myLinkedListAddAtHead(linkedList, 6);
    printSignalLinkedList(linkedList);

    return 0;
}