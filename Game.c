//
// Created by Yotam Manne on 23/07/2018.
//

#include "Game.h"

int mark_errors(Game* game, int arg){
    if(arg!=0 && arg!=1){
        //error - arg must be 0 or 1
        return 0;
    }
    game->markError=arg;
    return 1;
}

int set(Game* game,int x,int y,int value){
    if(!checkRange(game,x) || !checkRange(game,y) || !checkRange(game,value)){
        //error - not in range
        return 0;
    }
    if(game->mode==1 && game->board[x][y].isFixed){
        //error - cell is fixed
        return 0;
    }
    /*add code to remember previous value for undo */
    game->board[x][y].value=value;
    if(checkValid(game,x,y,value)) game->board[x][y].isValid=1;
    else game->board[x][y].isValid=0;

    /*add code to remove the list nodes beyond this move and add this move to the list*/

}

int hint(Game* game, int x, int y){
    
}


int checkRange(Game* game,int a){
    if(a<0 || a>game->rows*game->columns) return 0;
    return 1;
}

int checkValid(Game* game, int x, int y, int value) {
    return checkBlock(game, x, y, value)*checkRowColumn(game, x, y, value);
}

int checkBlock(Game* game, int x, int y, int value) {
    int k, r, i=x, j=y;
    while (x%game->columns != 1)x--;
    while (y%game->rows != 1)y--;
    for (k = 0; k<game->rows; k++) {
        for (r = 0; r<game->columns; r++) {
            if (game->board[x][y].value == value && k!=j && r!=i)
                return 0;
            x++;
        }
        y++;
    }
    return 1;
}

int checkRowColumn(Game* game, int x, int y, int value) {
    int i;
    for(i=0;i<game->rows;i++){
        if(i!=y && game->board[x][i].value==value) return 0;
    }
    for(i=0;i<game->columns;i++){
        if(i!=x && game->board[i][y].value==value) return 0;
    }
    return 1;
}