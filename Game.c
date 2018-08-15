//
// Created by Yotam Manne on 23/07/2018.
//

#include "Game.h"




int mark_errors(Game* game, int arg){
    if(arg!=0 && arg!=1){
        //error - arg must be 0 or 1
        return 0;
    }
    game->markError=arg;
    return 1;
}

int* set(Game* game,int x,int y,int value){
    int* listData=calloc(4, sizeof(int));
    if(!checkRange(game,x) || !checkRange(game,y) || !checkRange(game,value)){
        //error - not in range
        return NULL;
    }
    if(game->mode==1 && game->board[x][y].isFixed){
        //error - cell is fixed
        return NULL;
    }
    listData[0]=x,listData[1]=y,listData[2]=game->board[x][y].value,listData[3]=value;
   // addLast(game->list,listData);

    game->board[x][y].value=value;
    if(checkValid(game,x,y,value)) game->board[x][y].isValid=1;
    else game->board[x][y].isValid=0;

    return listData;
}

int hint(Game* game, int x, int y){
    
}


int checkRange(Game* game,int a){
    if(a<0 || a>game->rows*game->columns) return 0;
    return 1;
}

int checkValid(Game* game, int x, int y, int value) {
    if(!value) return 1;
    return checkBlock(game, x, y, value)*checkRowColumn(game, x, y, value);
}

int checkBlock(Game* game, int x, int y, int value) {
    int k, r, i=x, j=y;
    while (x%game->columns != 1)x--;
    while (y%game->rows != 1)y--;
    for (k = 0; k<game->rows; k++) {
        for (r = 0; r<game->columns; r++) {
            if (game->board[x][y].value == value && k!=j && r!=i)
                return 0;
            x++;
        }
        y++;
    }
    return 1;
}

int checkRowColumn(Game* game, int x, int y, int value) {
    int i;
    for(i=0;i<game->rows;i++){
        if(i!=y && game->board[x][i].value==value) return 0;
    }
    for(i=0;i<game->columns;i++){
        if(i!=x && game->board[i][y].value==value) return 0;
    }
    return 1;
}

int edit(char * filePath){
    FILE * file;
    fopen_s(&file,filePath,"r");
    if(file==NULL){
        abort();
    }
/*    Game * game=readFromFile(file);*/
   // game->markError=1;
    fclose(file);
}

/*change and then move list pointer */
int undo(Game * game) {
    int i;
    int *move;

    if (!game->list->length || game->list->pointer == NULL) {
        /*no moves to undo error*/
        return 0;
    }
    for (i = 0; i < game->list->pointer->size; i++) {
        move = game->list->pointer->data[i];
      game->board[move[0]][move[1]].value = move[2];
        printf("Undo %d,%d: from ",move[0], move[1]);
        if (move[3])
            printf("%d to ", move[3]);
        else
            printf("_ to ");
        if (move[2])
            printf("%d\n", move[2]);
        else
            printf("_\n");
    }
    game->list->pointer = game->list->pointer->previous;
    return 1;
}

/*move list pointer and then change*/
    int redo(Game *game) {
        char from;
        char to;
        int i;
        int *move;
        if (!game->list->length || game->list->pointer->next == NULL) {
            /*no moves to undo error*/
            return 0;
        }
        game->list->pointer = game->list->pointer->next;
        for (i = 0; i < game->list->pointer->size; i++) {
            move = game->list->pointer->data[i];
            from = (move[2] == 0 ? '_' : move[2] + '0');
            to = (move[3] == 0 ? '_' : move[3] + '0');
            game->board[move[0]][move[1]].value = move[3];
            printf("Redo %d,%d: from %c to %c\n", move[0], move[1], to, from);
        }
        return 1;
    }

    int save(Game *game, char *path) {
        FILE *file;
        fopen_s(&file, path, "w");
        if (file == NULL) {
            ",,";
        }
        if (game->mode == 1 && !checkError(game)) {
            printf("Error: board contains erroneous values\n");
        }
        if (game->mode == 1 && !validate(game))
            printf("Error: board validation failed\n");


        fclose(file);
    }
    int validate(Game *game) {
    }

    int checkError(Game *game) {
        Cell *cell;
        int sizeBoard = 0;
        for (cell = game->board[0];
             sizeBoard < game->columns * game->rows * game->columns * game->rows; sizeBoard++, cell++) {
            if (!cell->isValid) {
                return 0;
            }
        }
        return 1;

    }
    int reset(Game *game) {
        while (game->list->length != 0) {
            undo(game);
            deleteAtPosition(game->list, game->list->length - 1);
        }
        printf("Board reset\n");
    }
    Game *readFromFile(FILE *file) {
        int a, b, num, i, j;
        Cell **index;
        fscanf(file, "%d", &a);
        fscanf(file, "%d", &b);
        index = calloc(a * b, sizeof(Cell *));
        for (i = 0; i < a * b; i++) {
            index[i] = calloc(a * b, sizeof(Cell));
        }
        Game *game = calloc(1, sizeof(Game));
        game->columns = b;
        game->rows = a;
        game->board = index;
        for (i = 0; i < a * b; i++) {
            for (j = 0; j < a * b; j++) {
                fscanf(file, "%d", &num);
                game->board[i][j].value = num;
                if (getc(file) == '.')
                    game->board[i][j].isFixed = 1;
            }
        }
        return game;
    }

    int writeToFile(Game *game, FILE *file) {
        Cell **index;
        int i, j;
        fprintf(file, "%d ", game->rows);
        fprintf(file, "%d\n", game->columns);
        index = game->board;
        for (i = 0; i < game->rows * game->columns; i++) {
            for (j = 0; j < game->rows * game->columns; j++) {
                fprintf(file, "%d", index[i][j]);
                if (index[i][j].isFixed == 1)
                    fprintf(file, ".");
                if (j == (game->rows * game->columns - 1))
                    fprintf(file, "\n");
                else
                    fprintf(file, "\t");

            }
        }
    }










