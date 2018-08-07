//
// Created by Yotam Manne on 06/08/2018.
//

#include "ParserTester.h"

void testParser(){

    Game g;
    g.column=3;
    g.row=3;
    g.mode=0;
    g.markError=0;
    g.board=NULL;
    g.list=NULL;

    Command c;
    int intArgs[3];
    char*strArg;
    c.intArgs=intArgs;
    c.strArg=strArg;
    c.saveToList=0;
    c.numArgs=-1;
    c.type=-1;

    int a[3]={-1,-1,-1};

    char command[256]="solve c:\\game1.txt";

    Command testSolve;
    testSolve.intArgs=NULL;
    testSolve.strArg="c:\\game1.txt";
    testSolve.saveToList=0;
    testSolve.numArgs=1;
    testSolve.type=1;

    parseCommand(&g,command,&c);
    if(!compareCommand(&c,&testSolve)) printf("test1 failed\n");
    g.mode=1;
    parseCommand(&g,command,&c);
    if(!compareCommand(&c,&testSolve)) printf("test2 failed\n");
    g.mode=2;
    parseCommand(&g,command,&c);
    if(!compareCommand(&c,&testSolve)) printf("test3 failed\n");

    char command1[256]="solve c:\\game1.txt sfgs 45";

    parseCommand(&g,command1,&c);
    if(!compareCommand(&c,&testSolve)) printf("test4 failed\n");

    char command2[256]="\n\t \n    solve  \n   c:\\game1.txt \n \t sfgs 45  \t \n";

    parseCommand(&g,command2,&c);
    if(!compareCommand(&c,&testSolve)) printf("test5 failed\n");

    char command3[256]="edit";
    Command testEdit;
    testEdit.intArgs=NULL;
    testEdit.strArg=NULL;
    testEdit.saveToList=0;
    testEdit.numArgs=1;
    testEdit.type=2;

    initCommand(&c,a);

    parseCommand(&g,command3,&c);
    if(!compareCommand(&c,&testEdit)) printf("test6 failed\n");

    initCommand(&c,a);

    char command4[256]="edit c:\\game1.txt";
    testEdit.strArg="c:\\game1.txt";
    parseCommand(&g,command4,&c);
    if(!compareCommand(&c,&testEdit)) printf("test6 failed\n");
    initCommand(&c,a);
    char command5[256]="\n\t \n    edit  \t \t   c:\\game1.txt \n \t sfgs 45  \t \n";
    parseCommand(&g,command5,&c);
    if(!compareCommand(&c,&testEdit)) printf("test7 failed\n");

    initCommand(&c,a);

    Command testMarkErrors;
    a[0]=1;a[1]=0;a[2]=0;
    testMarkErrors.type=3;
    testMarkErrors.saveToList=0;
    testMarkErrors.numArgs=1;
    testMarkErrors.intArgs=a;
    testMarkErrors.strArg=NULL;

    g.mode=1;
    char command6[256]="  \t  \n mark_errors";
    parseCommand(&g,command6,&c);
    if(!compareCommand(&c,&testMarkErrors)) printf("test8 failed\n");

    char command7[256]="  \t  \n print_board \t 5 xb";

    Command testPrintBoard;
    testPrintBoard.type=4;
    testPrintBoard.saveToList=0;
    testPrintBoard.numArgs=0;
    testPrintBoard.intArgs=NULL;
    testPrintBoard.strArg=NULL;

    parseCommand(&g,command7,&c);
    if(!compareCommand(&c,&testPrintBoard)) printf("test9 failed\n");
    g.mode=0;
    testPrintBoard.type=-1;
    parseCommand(&g,command7,&c);
    if(!compareCommand(&c,&testPrintBoard)) printf("test10 failed\n");

    g.mode=1;
    initCommand(&c,a);
    char command8[256]="set 1 2 3";
    a[0]=1;a[1]=2;a[2]=3;
    Command testSet;
    testSet.type=5;
    testSet.numArgs=3;
    testSet.intArgs=a;
    testSet.strArg=NULL;
    testSet.saveToList=1;

    parseCommand(&g,command8,&c);
    if(!compareCommand(&c,&testSet)) printf("test11 failed\n");

    char command9[256]="set \t\n 1    2 3";
    parseCommand(&g,command9,&c);
    if(!compareCommand(&c,&testSet)) printf("test12 failed\n");

    char command10[256]="set \t\n 1    sdg 3";
    testSet.type=-1;
    parseCommand(&g,command10,&c);
    if(!compareCommand(&c,&testSet)) printf("test13 failed\n");

    char command11[256]="set \t\n 1    2 3 4 sdgf";
    testSet.type=5;
    parseCommand(&g,command11,&c);
    if(!compareCommand(&c,&testSet)) printf("test14 failed\n");

    initCommand(&c,NULL);
    char command12[256]="set";
    testSet.type=-1;
    parseCommand(&g,command12,&c);
    if(!compareCommand(&c,&testSet)) printf("test15 failed\n");

    Command testValidate;
    testValidate.type=6;
    testValidate.numArgs=0;
    testValidate.intArgs=NULL;
    testValidate.strArg=NULL;
    testValidate.saveToList=0;

    initCommand(&c,NULL);
    char command13[256]="validate";
    parseCommand(&g,command13,&c);
    if(!compareCommand(&c,&testValidate)) printf("test16 failed\n");

    char command14[256]=" \t\n validate 4 c g";
    parseCommand(&g,command14,&c);
    if(!compareCommand(&c,&testValidate)) printf("test17 failed\n");

    a[0]=-1;a[1]=-1;a[2]=-1;
    int b[3]={1,2,-1};
    initCommand(&c,a);
    Command testGen;
    testGen.type=7;
    testGen.numArgs=2;
    testGen.intArgs=b;
    testGen.strArg=NULL;
    testGen.saveToList=1;
    g.mode=2;

    char command15[256]="generate 1 2";
    parseCommand(&g,command15,&c);
    if(!compareCommand(&c,&testGen)) printf("test18 failed\n");

    initCommand(&c,a);
    char command16[256]="generate 1 2 sg";
    parseCommand(&g,command16,&c);
    if(!compareCommand(&c,&testGen)) printf("test19 failed\n");

    initCommand(&c,a);
    char command17[256]="generate";
    testGen.type=-1;
    parseCommand(&g,command17,&c);
    if(!compareCommand(&c,&testGen)) printf("test20 failed\n");

    initCommand(&c,a);
    char command18[256]="generate 1 f";
    g.mode=2;
    testGen.type=-1;
    parseCommand(&g,command18,&c);
    if(!compareCommand(&c,&testGen)) printf("test21 failed\n");
}

int compareCommand(Command* c1, Command*c2){
    if(c1->type!=c2->type) return 0;
    if(c1->type==-1 && c2->type==-1) return 1;
    if(c1->numArgs!= c2->numArgs) return 0;
    if(c1->saveToList!=c2->saveToList)return 0;
    if(c1->strArg!=NULL && c2->strArg!=NULL){
        if(strcmp(c1->strArg,c2->strArg)) return 0;
    }
    else{
        if(c1->strArg!=c2->strArg) return 0;
    }
    if(!arrComp(c1->intArgs,3,c2->intArgs,3)) return 0;
    return 1;
}