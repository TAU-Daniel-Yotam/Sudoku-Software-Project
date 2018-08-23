
#include "MainAux.h"

void printDashes(int column,int row){
    int j;
    for ( j=0;j<4*column*row+column+1;j++){
        printf("-");
        if(j==(4*column*row+column))
            printf("\n");
    }
}

void printBoard(Game * game) {
    int i, j;
    Cell index;
    for (i = 0; i < game->columns * game->rows; i++) {
        if (!(i % game->columns))
            printDashes(game->columns, game->rows);
        for (j = 0; j < game->columns * game->rows; j++) {
            if (!(j % game->rows))
                printf("|");
            index = game->board[i][j];
            if (index.isFixed) {
                printf(" %2d.", index.value);
            } else if (!index.isValid && (game->markError||game->mode==2))
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
    printDashes(game->columns, game->rows);
}

int arrComp(int*a1, int size1, int*a2, int size2){
   int i;
    if(a1!=NULL && a2!=NULL){
        if (size1!=size2) return 0;
        for(i=0;i<size1;i++){
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

int**copyBoard(Game*game){
    int size,i,j;
    int**board;
    size=game->columns*game->rows;
    board=(int**)calloc((unsigned int)size,sizeof(int*));
    if(board==NULL){
        printError(game,MEMORY_ALLOC_ERROR);
        return NULL;
    }
    for(i=0;i<size;i++){
        board[i]=(int*)calloc((unsigned int)size, sizeof(int));
        if(board[i]==NULL){
            printError(game,MEMORY_ALLOC_ERROR);
            return NULL;
        }
        for(j=0;j<size;j++){
            board[i][j]=game->board[i][j].value;
        }
    }
    return board;
}