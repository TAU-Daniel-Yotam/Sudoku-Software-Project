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
    int j,i;
    FILE * file=fopen("C:\\Users\\danielpeer\\Pictures\\w","r");
   Game * game=readFromFile(file);
   printf("%d",game->columns);
   for(j=0;j<4;j++){
       for(i=0;i<4;i++){
           printf("%d",game->board[i][j].value);
       }
   }




    }




