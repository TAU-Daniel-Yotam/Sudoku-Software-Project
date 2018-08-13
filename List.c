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
    list->pointer=list->head;
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
    return 1;
}
int deleteAfterSet(List *list,Node * node){
    Node * temp=node->next;
    if(node->next!=NULL){
        node->next=node->next->next;
        if(node->next!=NULL)
            node->next->previous=node;
    }
    free(temp);
    list->length--;
}

int delete2(List *list,Node * node){
    while(node->next!=NULL){
        deleteAfterSet(list,node);
    }
}

int printList(List * list){
    for(Node * node=list->head;node!=NULL;node=node->next){
        printData(node->data);
        printf("\t");
    }
    return 1;
}
int printData(int * data){
    int *g=data;
    for(int r=0;r<4;r++,g++){
        printf("%d",*g);
    }
return 1;
}

int movePointer(List * list,int move) {
    if (move)
        list->pointer = list->pointer->next;

    else
        list->pointer = list->pointer->previous;
    return 1;
}

int addAtLast(List * list,int * data){
    if(list->pointer!=list->tail){
        delete2(list,list->pointer);
    }
    Node *  node=createNode(data);
    list->pointer->next=node;
    list->tail=node;
    list->tail=node;
    list->length++;
    return 1;
}
