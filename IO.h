#ifndef SUDOKU_SOFTWARE_PROJECT_IO_H

#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
Game * readFromFile(FILE * file);
int  writeToFile(Game * game,FILE * file);

#define SUDOKU_SOFTWARE_PROJECT_IO_H

#endif //SUDOKU_SOFTWARE_PROJECT_IO_H
