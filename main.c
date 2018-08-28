
#include "Game.h"
#include "Parser.h"
#include "gurobi_c.h"

int main(){
    int exit,eof,type;
    Game game;
    Command parsedCommand;
    char command[1024];
    game.mode=0;
    printf("Sudoku\n------\n");
    while (!exit){
        eof=getInput(command,1024);
        type=parseCommand(&game,command,&parsedCommand);
        if (type==-1){
            printError(&game,INVALID_COMMAND_ERROR);
            continue;
        }
        switch(type){
            case 1:
                solve(&game,parsedCommand.strArg);
                break;
            case 2:
                edit(parsedCommand.strArg,&game);
                break;
            case 3:
                mark_errors(&game,parsedCommand.intArgs[0]);
                break;
            case 4:
                printBoard(&game);
                break;
            case 5:
                set(&game,parsedCommand.intArgs[0],parsedCommand.intArgs[1],parsedCommand.intArgs[2]);
            case 15:
                exitGame(&game);
            default:
                break;






        }

        }




    /*
     * Game Flow here
     * */

    return 0;

}