

#ifndef SUDOKU_SOFTWARE_PROJECT_SOLVER_H
#define SUDOKU_SOFTWARE_PROJECT_SOLVER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gurobi_c.h"
#include "Game.h"

#define SUBDIM  3
#define DIM    (SUBDIM*SUBDIM)

int ILPSolve(Game* game);

#endif
