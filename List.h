#ifndef SUDOKU_SOFTWARE_PROJECT_LIST_H
typedef struct  Node {
    int * data;
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
Node * createNode(int * data);
List * createlist();
int printData(int * data);
int deleteAtPosition(List *list,int pos);
int insertAtHead(List * list,int * data);
int printList(List * list);
int movePointer(List * list,int move);

#endif //SUDOKU_SOFTWARE_PROJECT_LIST_H
