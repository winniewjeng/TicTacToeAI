
#include <iostream>
#include <string>

using namespace std;

//declaring function prototypes
bool win();
bool boardFull();
bool isEven(int);
void display(char[][3], string[][5]);
void initBoard(char[][3]);
void userInput(int&, int&);
bool posAvailable(char[][3], int&, int&);
void hintPrompt();
void AIMove(char[][3], int&, int&);
void placeOnBoard(char[][3], int&, int&, char);

int main() {

    char board[3][3];
    string displayBoard[5][5];
    bool usersTurn = true;
    int row;
    int col;
    int checkPos;

    //Initialize an empty 3x3 game board. All elements in board[][] = " " 
    initBoard(board);

    //Display the empty 5x5 game board with grids and everything
    display(board, displayBoard);

    //Keep playing the game until there's a win or board is full and ends with a tie
    while (!win() && !boardFull()) {

        //Implement HINT:

        //prompt the user to input a location on the board. Keep prompting if the position is not available.
        //userInput(row, col);
        //check: Available()
        /*while (!posAvailable(board, row, col)) {
            //userInput(row, col);
        }*/

        //place down the mark
        if (usersTurn) {
            userInput(row, col);
            
            while (!posAvailable(board, row, col)) {
                userInput(row, col);
            }
            
            board[row][col] = 'X';
        } else {
            //board[row][col] = 'O';
            AIMove(board, row, col);
        }
        display(board, displayBoard);

        //check: noWin()--go through the win, block, corner, takeEmpty algorithm

        //If no one wins, change user's turn.
        usersTurn = !usersTurn;
    }

    return 0;
}

//declaring function implementations

bool isEven(int checkPos) {
    if (checkPos % 2 == 0) {
        return true;
    }
    return false;
}

bool win(){
    return false;
}
//declaring function implementations

bool boardFull() {
    //if(){return true}
    cout << "Stubbber\n";
    return false;
}

void initBoard(char board [][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display(char board[][3], string displayBoard[][5]) {
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
}

void userInput(int& row, int& col) {
    cout << "Enter the location where you want to place your mark." << endl;
    cout << "Row: ";
    cin >> row;
    cout << "Col: ";
    cin >> col;
}

bool posAvailable(char board[][3], int& row, int& col) {
    if (board[row][col] != ' ') {
        cout << "This position is occupied. Enter a different position." << endl;
        return false;
    } else if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "This position is out-of-bound. Enter a different position." << endl;
        return false;
    }

    return true;
}

void hintPrompt() {
    char yesHint = ' ';
    cout << "Do you want a hint? Enter Y to get a hint. Otherwise, enter anything to move on.";
    cin >> yesHint;

    if (yesHint == 'Y' || yesHint == 'y') {
        //Imple Algo;
    }
}

void AIMove(char board[][3], int& row, int& col) {
    //tells if a position is found
    bool found = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (posAvailable(board, i, j) && !found) {
                row = i;
                col = j;
                found = true;
            }
        }
    }
    placeOnBoard(board, row, col, 'O');
}

void placeOnBoard(char board[][3], int& row, int& col, char symbol) {
    board[row][col] = symbol;
}