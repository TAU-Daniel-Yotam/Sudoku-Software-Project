#include "List.h"
#include <stdlib.h>
#include <stdio.h>

List * createlist(){
    List * list=calloc(1, sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    list->pointer=NULL;
    return list;
}

Node  * createNode(int ** data,int size){
    Node * node=calloc(1, sizeof(Node));
   node->size=size;
    node->data=data;
    node->previous=NULL;
    node->next=NULL;
    return node;
}
/*int insertAtHead(List * list,int * data){
    Node * node =createNode(data);
    node->next=list->head;
    if(node->next!=NULL)
'        node->next->previous=node;
    list->head=node;
    list->length++;
    if(list->length==1) {
        list->tail = node;
    }
    list->pointer=list->head;
    return 1;

}*/
int deleteAtPosition(List *list,int pos) {
    int j;
    Node *node = list->head;
    for (j = 0; j < pos; j++) {
        node = node->next;
    }
    if (node->next != NULL)
        node->next->previous = node->previous;
    if (node->previous != NULL)
        node->previous->next = node->next;
    if (pos == 0) {
        list->head = node->next;
        if (list->length == 1) {
            list->tail = node->next;
        }
    } else if (pos = list->length - 1) {
        list->tail = node->previous;
    }
    list->length--;
    return 1;
}


int deleteTail(List *list,Node * node){
    while(node->next!=NULL){
        Node * temp=node->next;
        node->next=node->next->next;
        if(node->next!=NULL){
            node->next->previous=node;
        }
        free(temp);
        list->length--;
    }
}

int printList(List * list){
    Node * node;
    for(node=list->head;node!=NULL;node=node->next){
        printData(node->data,node->size);
    }
    return 1;
}
int printData(int **data,int size){
    int r,g;
    for(r=0;r<size;r++) {
        for ( g=0; g < 4; g++) {
            printf("%d ", data[r][g]);
        }
    printf("\n");
    }
return 1;
}

int movePointer(List * list,int isRight) {
    if (isRight)
        list->pointer = list->pointer->next;

    else
        list->pointer = list->pointer->previous;
    return 1;
}

int addLast(List * list,int ** data,int size){
    if(list->pointer!=list->tail){
        deleteTail(list,list->pointer);
    }
    Node *  node=createNode(data,size);
    if(list->length==0)
        list->head=node;
    else{
        node->previous=list->pointer;
        list->pointer->next = node;}
        list->tail = node;
        list->pointer = node;
    list->length++;;
        return 1;

}
