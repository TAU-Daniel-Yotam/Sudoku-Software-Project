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
    char command18[256]="generate 1";
    g.mode=2;
    testGen.type=-1;
    parseCommand(&g,command18,&c);
    if(!compareCommand(&c,&testGen)) printf("test21 failed\n");

    g.mode=1;
    initCommand(&c,a);
    Command testUndoRedo;
    testUndoRedo.type=8;
    testUndoRedo.numArgs=0;
    testUndoRedo.intArgs=NULL;
    testUndoRedo.strArg=NULL;
    testUndoRedo.saveToList=0;

    char command19[256]="undo";
    parseCommand(&g,command19,&c);
    if(!compareCommand(&c,&testUndoRedo)) printf("test22 failed\n");

    initCommand(&c,a);
    testUndoRedo.type=9;
    char command20[256]="redo";
    parseCommand(&g,command20,&c);
    if(!compareCommand(&c,&testUndoRedo)) printf("test23 failed\n");

    initCommand(&c,a);
    char command21[256]=" \t \t  \n  redo 4 df s";
    parseCommand(&g,command21,&c);
    if(!compareCommand(&c,&testUndoRedo)) printf("test24 failed\n");

    initCommand(&c,a);
    testUndoRedo.type=8;
    char command22[256]=" \t \t  \n  undo 4 df s";
    parseCommand(&g,command22,&c);
    if(!compareCommand(&c,&testUndoRedo)) printf("test25 failed\n");

    g.mode=0;
    testUndoRedo.type=-1;
    initCommand(&c,a);
    char command23[256]="undo";
    parseCommand(&g,command23,&c);
    if(!compareCommand(&c,&testUndoRedo)) printf("test26 failed\n");

    testUndoRedo.type=-1;
    initCommand(&c,a);
    char command24[256]="redo";
    parseCommand(&g,command24,&c);
    if(!compareCommand(&c,&testUndoRedo)) printf("test27 failed\n");

    g.mode=1;
    Command testSave;
    testSave.type=10;
    testSave.intArgs=NULL;
    testSave.saveToList=0;
    testSave.strArg="c:\\game1.txt";
    testSave.numArgs=1;

    initCommand(&c,a);
    char command25[256]="save c:\\game1.txt";
    parseCommand(&g,command25,&c);
    if(!compareCommand(&c,&testSave)) printf("test28 failed\n");
    initCommand(&c,a);
    g.mode=1;

    initCommand(&c,a);
    char command26[256]="save c:\\game1.txt";
    parseCommand(&g,command26,&c);
    if(!compareCommand(&c,&testSave)) printf("test29 failed\n");
    initCommand(&c,a);
    g.mode=2;

    initCommand(&c,a);
    char command27[256]="save c:\\game1.txt";
    parseCommand(&g,command27,&c);
    if(!compareCommand(&c,&testSave)) printf("test30 failed\n");
    initCommand(&c,a);

    initCommand(&c,a);
    char command28[256]="save c:\\game1.txt sfgs 45";

    parseCommand(&g,command28,&c);
    if(!compareCommand(&c,&testSave)) printf("test31 failed\n");

    initCommand(&c,a);
    char command29[256]="\n\t \n    save  \n   c:\\game1.txt \n \t sfgs 45  \t \n";

    parseCommand(&g,command29,&c);
    if(!compareCommand(&c,&testSave)) printf("test32 failed\n");

    initCommand(&c,a);
    testSave.type=-1;
    char command30[256]="save";
    parseCommand(&g,command30,&c);
    if(!compareCommand(&c,&testSave)) printf("test33 failed\n");

    g.mode=0;
    initCommand(&c,a);
    parseCommand(&g,command27,&c);
    if(!compareCommand(&c,&testSave)) printf("test34 failed\n");

    g.mode=1;
    b[0]=1;b[1]=2;b[2]=-1;
    initCommand(&c,a);
    Command testHint;
    testHint.type=11;
    testHint.numArgs=2;
    testHint.intArgs=b;
    testHint.strArg=NULL;
    testHint.saveToList=0;

    char command31[256]="hint 1 2";
    parseCommand(&g,command31,&c);
    if(!compareCommand(&c,&testHint)) printf("test35 failed\n");

    initCommand(&c,a);
    char command32[256]="hint 1 2 sg";
    parseCommand(&g,command32,&c);
    if(!compareCommand(&c,&testHint)) printf("test36 failed\n");

    initCommand(&c,a);
    char command33[256]="hint";
    testHint.type=-1;
    parseCommand(&g,command33,&c);
    if(!compareCommand(&c,&testHint)) printf("test37 failed\n");

    initCommand(&c,a);
    char command34[256]="hint g";
    g.mode=0;
    testHint.type=-1;
    parseCommand(&g,command34,&c);
    if(!compareCommand(&c,&testHint)) printf("test38 failed\n");

    g.mode=1;
    initCommand(&c,a);
    Command testNumSol;
    testNumSol.type=12;
    testNumSol.numArgs=0;
    testNumSol.intArgs=NULL;
    testNumSol.strArg=NULL;
    testNumSol.saveToList=0;

    char command35[256]="num_solutions";
    parseCommand(&g,command35,&c);
    if(!compareCommand(&c,&testNumSol)) printf("test39 failed\n");

    initCommand(&c,a);
    char command36[256]=" \t \t  \n  num_solutions 4 df s";
    parseCommand(&g,command36,&c);
    if(!compareCommand(&c,&testNumSol)) printf("test41 failed\n");

    g.mode=0;
    testNumSol.type=-1;
    initCommand(&c,a);
    char command37[256]="num_solutions";
    parseCommand(&g,command37,&c);
    if(!compareCommand(&c,&testNumSol)) printf("test43 failed\n");


    g.mode=1;
    initCommand(&c,a);
    Command testAutofill;
    testAutofill.type=13;
    testAutofill.numArgs=0;
    testAutofill.intArgs=NULL;
    testAutofill.strArg=NULL;
    testAutofill.saveToList=1;

    char command38[256]="autofill";
    parseCommand(&g,command38,&c);
    if(!compareCommand(&c,&testAutofill)) printf("test39 failed\n");

    initCommand(&c,a);
    char command39[256]=" \t \t  \n  autofill 4 df s";
    parseCommand(&g,command39,&c);
    if(!compareCommand(&c,&testAutofill)) printf("test41 failed\n");

    g.mode=0;
    testAutofill.type=-1;
    initCommand(&c,a);
    char command40[256]="autofill";
    parseCommand(&g,command40,&c);
    if(!compareCommand(&c,&testAutofill)) printf("test43 failed\n");

    g.mode=2;
    initCommand(&c,a);
    Command testReset;
    testReset.type=14;
    testReset.numArgs=0;
    testReset.intArgs=NULL;
    testReset.strArg=NULL;
    testReset.saveToList=0;

    char command41[256]="reset";
    parseCommand(&g,command41,&c);
    if(!compareCommand(&c,&testReset)) printf("test44 failed\n");

    initCommand(&c,a);
    char command42[256]=" \t \t  \n  reset 4 df s";
    parseCommand(&g,command42,&c);
    if(!compareCommand(&c,&testReset)) printf("test45 failed\n");

    g.mode=0;
    testReset.type=-1;
    initCommand(&c,a);
    char command43[256]="reset";
    parseCommand(&g,command43,&c);
    if(!compareCommand(&c,&testReset)) printf("test46 failed\n");

    g.mode=2;
    initCommand(&c,a);
    Command testExit;
    testExit.type=15;
    testExit.numArgs=0;
    testExit.intArgs=NULL;
    testExit.strArg=NULL;
    testExit.saveToList=0;

    char command44[256]="exit";
    parseCommand(&g,command44,&c);
    if(!compareCommand(&c,&testExit)) printf("test44 failed\n");

    initCommand(&c,a);
    char command45[256]=" \t \t  \n  exit 4 df s";
    parseCommand(&g,command45,&c);
    if(!compareCommand(&c,&testExit)) printf("test45 failed\n");

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