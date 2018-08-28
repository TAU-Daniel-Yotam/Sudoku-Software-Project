

#include "Game.h"
#include "Parser.h"
#include "MainAux.h"
#include "gurobi_c.h"
#include "Exceptions.h"
#include "gameAux.h"

int main() {
    int exit, eof, type, erroneous, valid;
    Game game;
    game.mode = 0;
    Command parsedCommand;
    char command[1024];
    printf("Sudoku\n------\n");
    while (!exit) {
        eof = getInput(command, 1024);
        type = parseCommand(&game, command, &parsedCommand);
        if (type == -1) {
            printError(&game, INVALID_COMMAND_ERROR);
            continue;
        }
        if (erroneous && type != 8) {
            printError(&game, PUZZLE_SOLUTION_ERROR);
            continue;
        }
        switch (type) {
            case 1:
                solve(&game, parsedCommand.strArg[0]);
                break;
            case 2:
                edit(parsedCommand.strArg[0], &game);
                break;
            case 3:
                mark_errors(&game, parsedCommand.intArgs[0]);
                break;
            case 4:
                printBoard(&game);
                break;
            case 5:
                set(&game, parsedCommand.intArgs[0], parsedCommand.intArgs[1], parsedCommand.intArgs[2]);
                if (checkWinningGame(&game) && validate(&game)) {
                    printf("Puzzle solved successfully\n");
                    game.mode = 0;
                } else if (checkWinningGame(&game) && !validate(&game)) {
                    printError(&game, PUZZLE_SOLUTION_ERROR);
                    erroneous = 1;
                }
                break;
            case 6:
                valid = validate(&game);
                if (valid == 1)
                    printf("Validation passed board is solvable\n");
                else
                    printf("Validation failed: board is unsolvable\n");
                break;
            case 7:
                generate(&game, parsedCommand.intArgs[0], parsedCommand.intArgs[1]);
                break;
            case 8:
                if (erroneous == 1)
                    erroneous = 0;
                undo(&game);
                break;
            case 9:
                redo(&game);
                break;
            case 10:
                save(&game, parsedCommand.strArg[0]);
                break;
            case 11:
                hint(&game, parsedCommand.intArgs[0], parsedCommand.intArgs[1]);
                break;
            case 13:
                autofill(&game);
                break;
            case 14:
                reset(&game);
                break;
            case 15:
                exitGame(&game);
                exit = 1;
                break;
        }

    }
    return 0;


}