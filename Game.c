
#include "Game.h"

int mark_errors(Game* game, int arg){
    if(arg!=0 && arg!=1){
        printError(game,BINARY_RANGE_ERROR);
        return 0;
    }
    game->markError=arg;
    return 1;
}

int** set(Game* game,int x,int y,int value){
    int* listData=calloc(4, sizeof(int)); /* 0:x,1:y,2:from,3:to */
    if(!checkRange(game,x) || !checkRange(game,y) || !checkRange(game,value)){
        printError(game,VALUE_RANGE_ERROR);
        return NULL;
    }
    if(game->mode==1 && game->board[x][y].isFixed){
        printError(game,CELL_FIXED_ERROR);
        return NULL;
    }
    listData[0]=x,listData[1]=y,listData[2]=game->board[x][y].value,listData[3]=value;
   // addLast(game->list,listData);

    game->board[x][y].value=value;
    if(checkValid(game,x,y,value)) game->board[x][y].isValid=1;
    else game->board[x][y].isValid=0;

    return &listData;
}

int hint(Game* game, int x, int y){
    
}


int checkRange(Game* game,int a){
    if(a<0 || a>game->rows*game->columns) return 0;
    return 1;
}

int checkValid(Game* game, int x, int y, int value) {
    if(!value) return 1;
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

int edit(char * filePath){
    FILE * file;
    fopen(filePath,"r");
    if(file==NULL){
        printError(NULL,EDIT_IO_ERROR);
    }
    Game * game=readFromFile(file);
    if(game->mode==2){
        game->markError=1;
    }
    fclose(file);
}

/*change and then move list pointer */
int undo(Game * game) {

    /* need to complete: print board after changing the values and before printing the cells that changed */
    int i;
    int *move;
    if (!game->list->length || game->list->pointer == NULL) {
        printError(game,UNDO_ERROR);
        return 0;
    }
    for (i = 0; i < game->list->pointer->size; i++) {
        move = game->list->pointer->data[i];
        game->board[move[0]][move[1]].value = move[2];
        printf("Undo %d,%d: from ",move[0], move[1]);
        if (move[3])
            printf("%d to ", move[3]);
        else
            printf("_ to ");
        if (move[2])
            printf("%d\n", move[2]);
        else
            printf("_\n");
    }
    game->list->pointer = game->list->pointer->previous;
    return 1;
}

/*move list pointer and then change*/
    int redo(Game *game) {

    /* need to complete: print board after changing the values and before printing the cells that changed */
    char from;
        char to;
        int i;
        int *move;
        if (!game->list->length || game->list->pointer->next == NULL) {
            printError(game,REDO_ERROR);
            return 0;
        }
        game->list->pointer = game->list->pointer->next;
        for (i = 0; i < game->list->pointer->size; i++) {
            move = game->list->pointer->data[i];
            from = (move[2] == 0 ? '_' : move[2] + '0');
            to = (move[3] == 0 ? '_' : move[3] + '0');
            game->board[move[0]][move[1]].value = move[3];
            if(i==0) printBoard(game);
            printf("Redo %d,%d: from %c to %c\n", move[0], move[1], to, from);
        }
        return 1;
    }

    int save(Game *game, char *path) {
        FILE *file=fopen(path,"w");
        if (file == NULL) {
            printf("error");
            return 0;
        }
        if (game->mode == 2 && !checkError(game)) {
            printf("error");
            return 0;
        }
        if (game->mode == 1 && !validate(game)) {
            printf("error");
            return 0;
        }
        writeToFile(game,file);
        printf("Saved to:x\n");
        fclose(file);
        return 1;
    }
    int validate(Game *game) {
    }

    /* 0 if board is erroneous, 1 else*/
    int checkError(Game *game) {

    int i,j;
        for (i=0;i<game->columns*game->rows;i++){
            for(j=0;j<game->rows*game->columns;j++){
                if(game->board[i][j].isValid){
                    return 0;
                }
            }
        }
        return 1;

    }
    int reset(Game *game) {
        while (game->list->length != 0) {
            undo(game);
            deleteAtPosition(game->list, game->list->length - 1);
        }
        printf("Board reset\n");
    }

    Game *readFromFile(FILE *file) {
        int a, b, num, i, j;
        Cell **index;
        fscanf(file, "%d", &a);
        fscanf(file, "%d", &b);
        index = calloc(a * b, sizeof(Cell *));
        for (i = 0; i < a * b; i++) {
            index[i] = calloc(a * b, sizeof(Cell));
        }
        Game *game = calloc(1, sizeof(Game));
        game->columns = b;
        game->rows = a;
        game->board = index;
        for (i = 0; i < a * b; i++) {
            for (j = 0; j < a * b; j++) {
                fscanf(file, "%d", &num);
                game->board[i][j].value = num;
                if (getc(file) == '.')
                    game->board[i][j].isFixed = 1;
            }
        }
        return game;
    }

    int writeToFile(Game *game, FILE *file) {
        Cell **index;
        int i, j;
        fprintf(file, "%d ", game->rows);
        fprintf(file, "%d\n", game->columns);
        index = game->board;
        for (i = 0; i < game->rows * game->columns; i++) {
            for (j = 0; j < game->rows * game->columns; j++) {
                fprintf(file, "%d", index[i][j].value);
                if (index[i][j].isFixed == 1)
                    fprintf(file, ".");
                if (j == (game->rows * game->columns - 1))
                    fprintf(file, "\n");
                else
                    fprintf(file, "\t");

            }
        }
    }

    int** autofill(Game*game){
        int num_val[2]={0};
        int**cellsToFill=NULL;
        int i,j,first=1,count=0;
        if(!checkError(game)){
            printError(game,ERRONEOUS_BOARD_ERROR);
            return 0;
        }
        for(i=0;i<game->rows;i++){
            for(j=0;j<game->columns;j++){
                if(game->board[i][j].value){/* if cell is not empty */
                    countPossibleValues(game,num_val,i,j);
                    if(num_val[0]==1) {
                        if(first){
                            cellsToFill=(int**)calloc(++count, sizeof(int*));
                            if(cellsToFill==NULL) printError(game,MEMORY_ALLOC_ERROR);
                            cellsToFill[count-1]=(int*)calloc(4, sizeof(int)); /* 0:x,1:y,2:from,3:to */
                            if(cellsToFill[count-1]==NULL) printError(game,MEMORY_ALLOC_ERROR);
                            cellsToFill[count-1][0]=i;
                            cellsToFill[count-1][1]=j;
                            cellsToFill[count-1][2]=0;
                            cellsToFill[count-1][3]=num_val[1];
                            first=0;
                        }
                        else{
                            cellsToFill=(int**)realloc(cellsToFill,++count);
                            if(cellsToFill==NULL) printError(game,MEMORY_ALLOC_ERROR);
                            cellsToFill[count-1]=(int*)calloc(4, sizeof(int)); /* 0:x,1:y,2:from,3:to */
                            if(cellsToFill[count-1]==NULL) printError(game,MEMORY_ALLOC_ERROR);
                            cellsToFill[count-1][0]=i;
                            cellsToFill[count-1][1]=j;
                            cellsToFill[count-1][2]=0;
                            cellsToFill[count-1][3]=num_val[1];
                        }
                    }
                }
            }
        }
        /* complete:
         * add list node
         * if count == 0 don't add list node
         * delete list nodes after this command*/
        fillValues(game,cellsToFill,count);
        updateCellValidity(game);
        printBoard(game);
        return cellsToFill;
    }

    void countPossibleValues(Game*game,int*num_val,int x, int y){
        int i,first=1;
        num_val[0]=0;
        num_val[1]=0;
        for(i=1;i<=game->rows*game->columns;i++){
            if(checkValid(game,x,y,i)){
                if(first){
                    num_val[1]=i;
                    first=0;
                }
                num_val[0]++;
            }
        }
    }

    void fillValues(Game*game,int**values,int size){
        int i;
        for(i=0;i<size;i++){
            game->board[values[i][0]][values[i][1]].value=values[i][3];
            game->board[values[i][0]][values[i][1]].isPlayerMove=1;
            printf("Cell <%d,%d> set to %d\n",values[i][0],values[i][1],values[i][3]);
        }
    }

    void updateCellValidity(Game*game){
        int i,j;
        for(i=0;i<game->rows;i++){
            for(j=0;j<game->columns;j++){
                if(!checkValid(game,i,j,game->board[i][j].value)){
                    game->board[i][j].isValid=0;
                } else{
                    game->board[i][j].isValid=1;
                }
            }
        }
    }

    int**generate(Game*game,int x,int y){
        if(!checkRange(game,x) || !checkRange(game,y)){
            printError(game,VALUE_RANGE_ERROR);
            return 0;
        }
    }

    void clearBoard(Game*game){
        int i,j;
        for(i=0;i<game->rows;i++){
            for(j=0;j<game->columns;j++){
                game->board[i][j].value=0;
            }
        }
    }










