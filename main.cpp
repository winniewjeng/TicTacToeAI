#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main() {

    bool userTurn = true;
    char mark = 'X';
    char board[3][3];
    char grid[9];
    int gridPos; //an int returned by userInput()
    string displayBoard[5][5];
    int alignGridPos[8][3]; //init once. Previously named q[][]
    char alignGridSymb[8][3]; //keep updating. Previously named w[][]
    int placePos; //AI places position here. Argument inside placeMark() for AI

    //initialize grid[9] to ' '
    initGrid(grid);
    initBoard(board);
    initDisplayBoard(board, displayBoard);
    initAlignGridSymb(alignGridSymb);
    initAlignGridPos(alignGridPos);
    createAlignGridPos(alignGridPos);

    //display gameBoard[][] with grid position #
    displayBoardWithGridPos();

    while (!gameOver(alignGridSymb, alignGridPos, board)) {

        if (userTurn) {
            mark = 'X';
            //user places the symbol on board
            userInput(grid, gridPos); //gridPos is passed by reference back to main()
            //update the grid (& board) with symbol 'X' at user's chosen gridPos
            placeMark(grid, gridPos, mark, board);
//            updateDisplayBoard(board, displayBoard);
        } else {
            cout << "AI's turn:" << endl;
            mark = 'O';
            //determine where to place mark: checkwin/block, center, check fork, place corner, place whatever left open
            //check hasTwo() for winning or blocking
            if (hasWin(alignGridSymb, alignGridPos, placePos)) {
                placeMark(grid, placePos, mark, board);
            } else if (hasBlock(alignGridSymb, alignGridPos, placePos)) {
                placeMark(grid, placePos, mark, board);
            } else if (hasCenter(grid, placePos)) {
                placeMark(grid, placePos, mark, board);
            } else if (hasFork(grid, placePos)) {
                placeMark(grid, placePos, mark, board);
            } else if (hasCorner(grid, placePos)) {
                placeMark(grid, placePos, mark, board);
            } else if (hasBlank(grid, placePos)) {
                placeMark(grid, placePos, mark, board);
            }
        }
        //create alignments of the possible winning combos x8
        createAlignGridSymb(board, alignGridSymb);
        //display the updated board
        updateDisplayBoard(board, displayBoard);
        //take turns
        userTurn = !userTurn;
    }

    return 0;

}




