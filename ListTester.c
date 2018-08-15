#include "ListTester.h"
#include "List.h"
#include "stdlib.h"
#include "Game.h"


int ** data(){
    int i,j=0;
    int ** r=calloc(4, sizeof(int*));
        for(i;i<4;i++){
            r[i]=calloc(4, sizeof(int));
                for(j=0;j<4;j++){
                    r[i][j]=i+j;
                }

            }
            return r;
        }
int ** data1(){
    int s=0,f=0;
    int ** r=calloc(4, sizeof(int*));
    for(s;s<4;s++){
        r[s]=calloc(4, sizeof(int));
        for(f=0;f<4;f++){
            r[s][f]=12;
        }

    }
    return r;
}

        List* lista(int ** data,int **  data1){
    List * list=createlist();
    addLast(list,data,4);
    addLast(list,data1,4);
    addLast(list,data1,4);
    deleteAtPosition(list,1);
    printList(list);

    return list;
}
int un(List * list){
    int i;
    int* board;
    Game * game=calloc(1,sizeof(game));
    game->list=list;
    printf("hi");
    board=calloc(2,sizeof(int));
    printf("hi");
 /*   for (i=0;i<20;i++){
        board[i]=calloc(20,sizeof(Cell));
    }
    game->board=board;
    printf("hi");
    undo(game);
    printf("hi");
    list->pointer->data[0][3]=0;*/

    undo(game);
    printf("%d",game->board[0][1].value);
}

