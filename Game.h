

#ifndef SUDOKU_SOFTWARE_PROJECT_GAME_H
#include "list.h"

typedef struct Cell{
    int value;
    int isFixed;
    int isValid;
    int isPlayerMove;
}Cell;

/**
 * mode: 0=init, 1=solve, 2=edit
 */
typedef struct Game{
    int columns,rows; /*num of rows and columns in a single block*/
    Cell ** board;
    int mode;
    int markError;
    List * list;
}Game;



#define SUDOKU_SOFTWARE_PROJECT_GAME_H

#endif //SUDOKU_SOFTWARE_PROJECT_GAME_H
