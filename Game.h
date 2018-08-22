
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include "Exceptions.h"
#include "MainAux.h"

#ifndef SUDOKU_SOFTWARE_PROJECT_GAME_H
#define SUDOKU_SOFTWARE_PROJECT_GAME_H


/*#include "IO.h"*/
typedef struct Cell{
    int value;
    int isFixed;
    int isValid;
    int isPlayerMove;
}Cell;

/*
 * mode: 0=init, 1=solve, 2=edit
 */
typedef struct Game{
    int columns,rows; /*num of rows and columns in a single block*/
    Cell ** board;
    int mode;
    int markError;
    List * list;
}Game;


int reset(Game * game);
Game * readFromFile(FILE * file);
int undo(Game * game);
int  writeToFile(Game * game,FILE * file);
int checkError(Game *game);
int save(Game *game, char *path);
#endif
