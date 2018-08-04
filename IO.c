
#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
Game *readFromFile(FILE * file) {
    int a, b, num;
    Cell **index;
    fscanf_s(file, "%d", &a);
    fscanf_s(file, "%d", &b);
    index=calloc(a*b, sizeof(Cell *));
    for(int i=0;i<a*b;i++){
        index[i]=calloc(a*b, sizeof(Cell));
    }
    Game *game = calloc(1, sizeof(Game));
    game->row = b;
    game->line = a;
    game->board=index;
    for(int i=0;i<a*b;i++){
        for (int j=0;j<a*b;j++){
            fscanf_s(file, "%d", &num);
            game->board[i][j] .value=num;
            if(getc(file)=='.')
                game->board[i][j].isFixed=1;
        }
    }
    return game;
};
int writeToFile(Game * game,FILE * file) {
    Cell **index;
    fprintf(file, "%d ", game->line);
    fprintf(file, "%d\n", game->row);
    index = game->board;
    for (int i = 0; i < game->line * game->row ;i++){
        for(int j=0;j<game->line*game->row;j++){
            fprintf(file, "%d", index[i][j]);
            if (index[i][j].isFixed == 1)
                fprintf(file,".");
            if(j==(game->line*game->line-1))
                fprintf(file,"\n");
            else
                fprintf(file,"\t");

        }
    }

}








