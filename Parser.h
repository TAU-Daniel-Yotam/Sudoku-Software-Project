//
// Created by Yotam Manne on 23/07/2018.
//
#include "Game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef SUDOKU_SOFTWARE_PROJECT_PARSER_H
typedef struct Command{
    int type,numArgs,saveToList;
    int* intArgs;
    char* strArg;
} Command;


#define SUDOKU_SOFTWARE_PROJECT_PARSER_H

int getInput(char* command, int size);
int parseCommand(Game* game, char*command, Command* parsedCommand);
void initCommand(Command* c,int*a);

#endif //SUDOKU_SOFTWARE_PROJECT_PARSER_H
