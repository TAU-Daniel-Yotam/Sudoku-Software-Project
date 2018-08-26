//
// Created by danielpeer on 25/08/2018.
//
#include "game.h"

#ifndef SUDOKU_SOFTWARE_PROJECT_GAMEAUX_H
int     readFromFile(Game * game, FILE * file);





int     checkBoard(Game * game);




void initGame(Game * game,int mode,int markError,int blockHeight,int blockWidth);
int readFromFile2(FILE *file,Game * game,int mode,int markError);
Cell ** createBoard(int blockHeight,int blockWidth);
void printDashes(int blockWidth,int blockHeight);
int checkRange(Game* game,int a);
int checkBlock(Game * game,int x,int y);
int freeMemory(void ** array,int size,int size2);
int checkRow(Game * game,int x);
int checkColumns(Game * game,int x);
int     checkEmpty(Game*game);
void createValuesArray(Game*game,int x,int y,int* values);
void createListDataGenerate(Game*game,int**listData);
int checkError(Game *game);
int writeToFile(Game *game, FILE *file);
int**copyBoard(Game*game);
void countPossibleValues(Game*game,int*num_val,int x, int y);
void fillValues(Game*game,int**values,int size);
void updateCellValidity(Game*game);
void freeGame(Game*game);
void freeBoard(Game*game);



int     checkInvalid(Game* game, int x, int y, int value);



int     checkEmpty(Game*game);
void    createValuesArray(Game*game,int x,int y,int* values);
void    createListDataGenerate(Game*game,int**listData);


void    exitGame(Game*game);
int     findError(Game * game);

#define SUDOKU_SOFTWARE_PROJECT_GAMEAUX_H

#endif //SUDOKU_SOFTWARE_PROJECT_GAMEAUX_H
