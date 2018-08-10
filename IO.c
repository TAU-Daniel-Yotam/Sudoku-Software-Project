
#include "IO.h"

Game *readFromFile(FILE * file) {
    int a, b, num,i;
    Cell **index;
    fscanf(file, "%d", &a);
    fscanf(file, "%d", &b);
    index=calloc(a*b, sizeof(Cell *));
    for(i=0;i<a*b;i++){
        index[i]=calloc(a*b, sizeof(Cell));
    }
    Game *game = calloc(1, sizeof(Game));
    game->column = b;
    game->row = a;
    game->board=index;
    for(i=0;i<a*b;i++){
        for (int j=0;j<a*b;j++){
            fscanf(file, "%d", &num);
            game->board[i][j] .value=num;
            if(getc(file)=='.')
                game->board[i][j].isFixed=1;
        }
    }
    return game;
}

int writeToFile(Game * game,FILE * file) {
    Cell **index;
    int i,j;
    fprintf(file, "%d ", game->rows);
    fprintf(file, "%d\n", game->columns);
    index = game->board;
    for (i = 0; i < game->rows * game->columns ;i++){
        for(j=0;j<game->rows*game->columns;j++){
            fprintf(file, "%d", index[i][j]);
            if (index[i][j].isFixed == 1)
                fprintf(file,".");
            if(j==(game->rows*game->rows-1))
                fprintf(file,"\n");
            else
                fprintf(file,"\t");

        }
    }

}








