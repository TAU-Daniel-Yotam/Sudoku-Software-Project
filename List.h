#ifndef SUDOKU_SOFTWARE_PROJECT_LIST_H
typedef struct  Node {
    int ** data;
    int dataElements;
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
Node * createNode(int ** data);
List * createlist();
int printData(int ** data);
int deleteAtPosition(List *list,Node * node);
int insertAtHead(List * list,int ** data);
int deleteAfterSet(List *list,Node * node);
int delete2(List  *list,Node * node);
int printList(List * list);
int movePointer(List * list,int move);
int addLast(List * list,int ** data);

#endif //SUDOKU_SOFTWARE_PROJECT_LIST_H

