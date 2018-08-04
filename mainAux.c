#include<stdio.h>
#include "Game.h"

void printdashes(int row,int line){
    for (int j=0;j<4*row*line+row+1;j++){
        printf("-");
        if(j==(4*row*line+row))
            printf("\n");
    }
}
void printBoard(Game * game) {
    int i, j;
    Cell index;
    for (i = 0; i < game->row * game->line; i++) {
        if (!(i % game->row))
            printdashes(game->row, game->line);
        for (j = 0; j < game->row * game->line; j++) {
            if (!(j % game->line))
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
    printdashes(game->row, game->line);
}

