

#ifndef SUDOKU_SOFTWARE_PROJECT_GAME_H
#include "list.h"


#ifndef UNTITLED7_GAME_H

typedef struct Cell{
    int value;
    int isFixed;
    int isValid;
    int isPlayerMove;
}Cell;

typedef struct  Game{
    int row,line;
    Cell ** board;
    int mode;
    int markError;
    List * list;

}Game;
#define UNTITLED7_GAME_H

#endif //UNTITLED7_GAME_H

#define SUDOKU_SOFTWARE_PROJECT_GAME_H

#endif //SUDOKU_SOFTWARE_PROJECT_GAME_H
