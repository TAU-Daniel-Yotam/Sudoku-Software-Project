
#ifndef SUDOKU_SOFTWARE_PROJECT_MAINAUX_H
#define SUDOKU_SOFTWARE_PROJECT_MAINAUX_H

#include<stdio.h>
#include "Game.h"

void printDashes(int blockWidth,int blockHeight)
void printBoard(Game* game);
void printArray(void*a, int size);
int arrComp(int*a1, int size1, int*a2, int size2);
int**copyBoard(Game*game);
int freeMemory(void ** array,int size,int size2);

#endif 
