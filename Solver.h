

#ifndef SUDOKU_SOFTWARE_PROJECT_SOLVER_H
#define SUDOKU_SOFTWARE_PROJECT_SOLVER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Exceptions.h"
#include "gurobi_c.h"

/*#define SUBDIM1  (game->rows)
#define SUBDIM2  (game->columns)
#define DIM    (SUBDIM1*SUBDIM2)*/

int ILPSolve(Game*game,int**board);

#endif
