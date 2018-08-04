#include "List.h"
#include <stdlib.h>
#include <stdio.h>

List * createlist(){
    List * list=calloc(1, sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    return list;
}

Node  * createNode(int * data){
    Node * node=calloc(1, sizeof(Node));
    node->data=data;
    node->previous=NULL;
    node->next=NULL;
    return node;
}
int insertAtHead(List * list,int * data){
    Node * node =createNode(data);
    node->next=list->head;
    if(node->next!=NULL)
        node->next->previous=node;
    list->head=node;
    list->length++;
    if(list->length==1) {
        list->tail = node;
    }
    return 1;

}
int deleteAtPosition(List *list,int pos){
    Node * node=list->head;
    for(int j=0;j<pos;j++){
        node=node->next;
    }
    if(node->next!=NULL)
        node->next->previous=node->previous;
    if(node->previous!=NULL)
        node->previous->next=node->next;
    if(pos==0){
        list->head=node->next;
        if(list->length==1){
            list->tail=node->next;
        }
    }
    else if (pos=list->length-1){
        list->tail=node->previous;
    }
    list->length--;
}


int printList(List * list){
    for(Node * node=list->head;node!=NULL;node=node->next){
        printData(node->data);
        printf("\t");
    }
}
int printData(int * data){
    int *g=data;
    for(int r=0;r<3;r++,g++){
        printf("%d",*g);
    }

}

int movePointer(List * list,int move) {
    if (move)
        list->pointer = list->pointer->next;

    else
        list->pointer = list->pointer->previous;
    return 1;
}