
#include "MainAux.h"

void printDashes(int column,int row){
    for (int j=0;j<4*column*row+column+1;j++){
        printf("-");
        if(j==(4*column*row+column))
            printf("\n");
    }
}

void printBoard(Game * game) {
    int i, j;
    Cell index;
    for (i = 0; i < game->column * game->row; i++) {
        if (!(i % game->column))
            printDashes(game->column, game->row);
        for (j = 0; j < game->column * game->row; j++) {
            if (!(j % game->row))
                printf("|");
            index = game->board[i][j];
            if (index.isFixed) {
                printf(" %2d.", index.value);
            } else if (!index.isValid && game->markError)
                printf(" %2d*", index.value);
            else {

                if (index.value != 0) {
                    printf(" %2d ", index.value);
                } else {
                    printf("    ");

                }
            }
        }
        printf("|\n");
    }
    printDashes(game->column, game->row);
}

int arrComp(int*a1, int size1, int*a2, int size2){
    if(a1!=NULL && a2!=NULL){
        if (size1!=size2) return 0;
        for(int i=0;i<size1;i++){
            if(a1[i]!=a2[i]) return 0;
        }
        return 1;
    }
    else{
        return a1==a2;
    }
}

void printArray(void*a, int size) {
    int i;
    int*x = (int*)a;
    for (i = 0; i<size; i++) {
        printf("a[%d]=%d ", i, x[i]);
        fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
}

int initArray(int*a, int size, int initValue){
    int i;
    for(i=0;i<size;i++){
        a[i]=initValue;
    }
    return 0;
}