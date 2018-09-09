
#include "functions.h"
#include <iostream>
#include <string>

using namespace std;

//functions implementations here

//FINISHED IMPLEMENTING

void displayBoardWithGridPos() {

    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (isEven(i) && !isEven(j)) {
                cout << "|";
            } else if (!isEven(i) && !isEven(j)) {
                cout << "+";
            } else if (!isEven(i) && isEven(j)) {
                cout << "---";
            } else {
                cout << " " << count << " ";
                count++;
            }
        }
        cout << endl;
    }
    cout << endl;
}

//FINISHED IMPLEMENTING

bool isEven(int checkPos) {
    if (checkPos % 2 == 0) {
        return true;
    }
    return false;
}

//FINISHED IMPLEMENTING

bool gameOver(char alignGridSymb[][3], int alignGridPos[][3], char board[][3]) {
    if (aWin(alignGridSymb, alignGridPos) || boardFull(board)) {
        return true;
    }
    return false;
}

//FINISHED IMPLEMENTING

void initGrid(char grid[]) {
    for (int i = 0; i < 9; i++) {
        grid[i] = ' ';
    }
}

//FINISHED IMPLEMENTING

void initBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

//FINISHED IMPLEMENTING

void initDisplayBoard(char board[][3], string displayBoard[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (isEven(i) && !isEven(j)) {
                displayBoard[i][j] = "|";
            } else if (!isEven(i) && !isEven(j)) {
                displayBoard[i][j] = "+";
            } else if (!isEven(i) && isEven(j)) {
                displayBoard[i][j] = "---";
            } else {
                displayBoard[i][j] = ' ';
                //                displayBoard[i][j] = board[i/2][j/2];
            }
        }
    }
}

//FINISHED IMPLEMENTING

void userInput(char grid[], int& gridPos) {
    cout << "Enter the grid position of where you want to place your mark: ";
    cin >> gridPos;

    //checkAvailable
    while (!posAvailable(grid, gridPos)) {
        cout << "Not a valid position. Try again: ";
        cin >> gridPos;
    }
}

//FINISHED IMPLEMENTING

bool posAvailable(char grid[], int gridPos) {
    if (grid[gridPos] != ' ') {
        return false;
    } else if (gridPos < 0 || gridPos > 8) {
        return false;
    }
    return true;
}

//FINISHED IMPLEMENTING

void placeMark(char grid[], int placePos, char symbol, char board[][3]) {
    grid[placePos] = symbol;
    //with each grid update, update the board[][] also
    getBoardFromGrid(board, grid);
}

//FINISHED IMPLEMENTING

void getBoardFromGrid(char board[][3], char grid[]) {
    //when a grid gets updated, this fxn is called to simultaneously update the board as well
    board[0][0] = grid[0];
    board[0][1] = grid[1];
    board[0][2] = grid[2];
    board[1][0] = grid[3];
    board[1][1] = grid[4];
    board[1][2] = grid[5];
    board[2][0] = grid[6];
    board[2][1] = grid[7];
    board[2][2] = grid[8];
}

//FINISHED IMPLEMENTING

void updateDisplayBoard(char board[][3], string displayBoard[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (isEven(i) && !isEven(j)) {
                displayBoard[i][j] = "|";
            } else if (!isEven(i) && !isEven(j)) {
                displayBoard[i][j] = "+";
            } else if (!isEven(i) && isEven(j)) {
                displayBoard[i][j] = "---";
            } else {
                string buffer = "  ";
                displayBoard[i][j] = buffer.insert(1, 1, board[i / 2][j / 2]);
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << displayBoard[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//FINISHED IMPLEMENTING

void initAlignGridPos(int alignGridPos[][3]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            alignGridPos[i][j] = 0;
        }
    }
}

//FINISHED IMPLEMENTING

void initAlignGridSymb(char alignGridSymb[][3]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            alignGridSymb[i][j] = ' ';
        }
    }
}

//FINISHED IMPLEMENTING -- previously named createAlignments()

void createAlignGridPos(int alignGridPos[][3]) {
    int count = 0;
    for (int i = 1; i < 5; i++) {
        if (i % 2 == 0) {
            if (i == 2) {
                alignGridNum(alignGridPos, count, 2, i);
            } else {
                alignGridNum(alignGridPos, count, 0, i);
            }
        } else {
            for (int j = 0; j < 3; j++) {
                if (i == 1) {
                    alignGridNum(alignGridPos, count, j * 3, i);
                } else {
                    alignGridNum(alignGridPos, count, j, i);
                }
            }
        }
    }
}

//FINISHED IMPLEMENTING -- previously named alignGrid()

void alignGridNum(int alignGridPos[][3], int& c, int pos, int skip) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        alignGridPos[c][i] = pos;
        pos += skip;
    }
    c++;
}

//FINISHED IMPLEMENTING

void createAlignGridSymb(char board[][3], char alignGridSymb[][3]) {
    alignGridSymb[0][0] = board[0][0]; //0
    alignGridSymb[0][1] = board[0][1]; //1
    alignGridSymb[0][2] = board[0][2]; //2

    alignGridSymb[1][0] = board[1][0]; //3
    alignGridSymb[1][1] = board[1][1]; //4
    alignGridSymb[1][2] = board[1][2]; //5

    alignGridSymb[2][0] = board[2][0]; //6
    alignGridSymb[2][1] = board[2][1]; //7
    alignGridSymb[2][2] = board[2][2]; //8

    alignGridSymb[3][0] = board[0][2]; //2
    alignGridSymb[3][1] = board[1][1]; //4
    alignGridSymb[3][2] = board[2][0]; //6

    alignGridSymb[4][0] = board[0][0]; //0
    alignGridSymb[4][1] = board[1][0]; //3
    alignGridSymb[4][2] = board[2][0]; //6

    alignGridSymb[5][0] = board[0][1]; //1
    alignGridSymb[5][1] = board[1][1]; //4
    alignGridSymb[5][2] = board[2][1]; //7

    alignGridSymb[6][0] = board[0][2]; //2
    alignGridSymb[6][1] = board[1][2]; //5
    alignGridSymb[6][2] = board[2][2]; //8

    alignGridSymb[7][0] = board[0][0]; //0
    alignGridSymb[7][1] = board[1][1]; //4
    alignGridSymb[7][2] = board[2][2]; //8
}

//FINISHED IMPLEMENTING

bool hasWin(char alignGridSymb[][3], int alignGridPos[][3], int& placePos) {
    for (int i = 0; i < 8; i++) {
        int countO = 0;
        int countX = 0;
        for (int j = 0; j < 3; j++) {
            if (alignGridSymb[i][j] == 'X') {
                countX++;
            } else if (alignGridSymb[i][j] == 'O') {
                countO++;
            }
            //hasWin: winning has precedence over blocking 
            if (countO == 2 && countX == 0) {
                for (int k = 0; k < 3; k++) {
                    if (alignGridSymb[i][k] == ' ') {
                        placePos = alignGridPos[i][k];
                        return true;
                    }
                }
            }

        }

    }
    return false;
}

//FINISHED IMPLEMENTING

bool hasBlock(char alignGridSymb[][3], int alignGridPos[][3], int& placePos) {
    for (int i = 0; i < 8; i++) {
        int countO = 0;
        int countX = 0;
        for (int j = 0; j < 3; j++) {
            if (alignGridSymb[i][j] == 'X') {
                countX++;
            } else if (alignGridSymb[i][j] == 'O') {
                countO++;
            }//hasBlock
            if (countX == 2 && countO == 0) {
                for (int k = 0; k < 3; k++) {
                    if (alignGridSymb[i][k] == ' ') {
                        placePos = alignGridPos[i][k];
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//FINISHED IMPLEMENTING

bool hasCenter(char grid[], int& placePos) {
    if (grid[4] == ' ') {
        placePos = 4;
        return true;
    }
    return false;
}

//NOT YET FINISHED IMPLEMENTING -- generate a random position instead of hardcoding 5

bool hasFork(char grid[], int& placePos) {

    int countBlank = 0;

    for (int i = 0; i < 9; i++) {
        if (grid[i] == ' ') {
            countBlank++;
        }
    }
    if (countBlank == 6) {
        if ((grid[0] == grid[8] && grid[0] == 'X') || (grid[2] == grid[6] && grid[2] == 'X')) {
            placePos = 5; //could be either 1, 3, 5, or 7.
            return true;
        }
    }

    return false;
}

//NOT YET FINISHED IMPLEMENTING -- generate a random position instead of hardcoding 0, 2, 6, 8

bool hasCorner(char grid[], int& placePos) {
    if (grid[6] == ' ') {
        placePos = 6;
        return true;
    } else if (grid[8] == ' ') {
        placePos = 8;
        return true;
    } else if (grid[2] == ' ') {
        placePos = 2;
        return true;
    } else if (grid[0] == ' ') {
        placePos = 0;
        return true;
    }
    return false;
}

//FINISHED IMPLEMENTING

bool hasBlank(char grid[], int& placePos) {
    for (int i = 0; i < 9; i++) {
        if (grid[i] == ' ') {
            placePos = i;
            return true;
        }
    }
    return false;
}

//FINISHED IMPLEMENTING

bool boardFull(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    cout << "Tie!" << endl;
    return true;
}

//FINISHED IMPLEMENTING

bool aWin(char alignGridSymb[][3], int alignGridPos[][3]) {
    for (int i = 0; i < 8; i++) {
        int countO = 0;
        int countX = 0;
        for (int j = 0; j < 3; j++) {
            if (alignGridSymb[i][j] == 'X') {
                countX++;
            } else if (alignGridSymb[i][j] == 'O') {
                countO++;
            }
            //if a win is found, return true
            if (countO == 3) {
                cout << "AI wins!" << endl;
                return true;
            } else if (countX == 3) {
                cout << "Player wins!" << endl;
                return true;
            }
        }
    }
    return false;
}
