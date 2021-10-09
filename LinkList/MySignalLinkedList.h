typedef struct MyLinkedList_t{
    int val;
    struct MyLinkedList_t *next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate();
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);