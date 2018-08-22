//
// Created by Yotam Manne on 23/07/2018.
//


#ifndef SUDOKU_SOFTWARE_PROJECT_PARSER_H
#define SUDOKU_SOFTWARE_PROJECT_PARSER_H
#include "Game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Command{
    int type,numArgs,saveToList;
    int* intArgs;
    char* strArg;
} Command;

int getInput(char* command, int size);
int parseCommand(Game* game, char*command, Command* parsedCommand);
void initCommand(Command* c,int*a);

#endif
