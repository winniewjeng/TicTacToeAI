#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
using namespace std;

//declaring function prototypes

void displayBoardWithGridPos();
bool isEven(int);
bool gameOver();//NOT YET IMPLEMENTED
void initGrid(char[]);
void initBoard(char[][3]);
void initDisplayBoard(char[][3], string[][5]); //board[3][3], displayBoard[5][5]
void userInput(char[], int&); //grid[9], &gridPos
bool posAvailable(char[], int); //grid[9], gridPos
void placeMark(char[], int, char, char[][3]); //grid[9], placePos, symbol, board[][3]
void getBoardFromGrid(char[][3], char[]); //board[3][3], grid[9]
void updateDisplayBoard(char[][3], string[][5]); //board[3][3]
void initAlignGridPos(int[][3]); //alignGridPos[8][3]
void initAlignGridSymb(char[][3]); //alignGridSymb[8][3]
void createAlignGridPos(int[][3]); //alignGridPos[8][3]
void alignGridNum(int[][3], int&, int, int); //int q[][], int &count, int pos, int skip
void createAlignGridSymb(char[][3], char[][3]); //board[3][3], alignGridSymb[8][3]
bool hasTwo(char[][3], int[][3], int&); //alignGridSymb[8[3], alignGridPos[8][3], placePos
bool hasWin(char[][3], int[][3], int&); //CERTAIN portion can be condensed. too similar to hasBlock
bool hasBlock(char[][3], int[][3], int&); //CERTAIN portion can be condensed. too similar to hasWin
bool hasCenter(char[], int&);
bool hasFork(char[], int&); //NOT YET FINISHED IMPLEMENTING
bool hasCorner(char[], int&); //NOT YET FINISHED IMPLEMENTING
//NOT YET IMPLEMENTED
bool hasBlank(char[], int&);




#endif /* FUNCTIONS_H */

