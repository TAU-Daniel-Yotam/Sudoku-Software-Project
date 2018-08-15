#ifndef SUDOKU_SOFTWARE_PROJECT_LIST_H
typedef struct  Node {
    int ** data;
    int size;
    struct Node * next;
    struct Node * previous;
}Node ;


typedef struct List{
    Node * head;
    Node * tail;
    Node * pointer;
    int length;
} List;

#define SUDOKU_SOFTWARE_PROJECT_LIST_H
Node * createNode(int ** data,int size);
List * createlist();
int printData(int ** data,int size);
int deleteAtPosition(List *list,int pos);
int insertAtHead(List * list,int ** data);
int deleteAfterSet(List *list,Node * node);
int delete2(List  *list,Node * node);
int printList(List * list);
int movePointer(List * list,int move);
int deleteTail(List *list,Node * node);
int addLast(List * list,int ** data,int size);
#endif //SUDOKU_SOFTWARE_PROJECT_LIST_H

