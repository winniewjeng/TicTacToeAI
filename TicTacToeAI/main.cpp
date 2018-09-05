
#include <iostream>
#include <string>

using namespace std;

//declaring function prototypes
bool playerWin(char[][3], char);
bool boardFull(char[][3]);
bool gameOver(char[][3]);

bool isEven(int);
void printBuffer(int);
void display(char[][3], string[][5]);
void initBoard(char[][3]);
void userInput(char[][3], int&, int&);
bool posAvailable(char[][3], int&, int&);
void hintPrompt();
void AIMove(char[][3], int&, int&);
void placeOnBoard(char[][3], int&, int&, char);

int main() {

    string displayBoard[5][5];
    char board[3][3];

    bool userTurn = true;
    int row;
    int col;
    int checkPos;
    char replay = 'y';

    while(replay == 'y' || replay == 'Y'){
        initBoard(board);

        while(!gameOver(board)){  
            if (userTurn){
                display(board, displayBoard);
                userInput(board, row, col);
                board[row][col] = 'X';
            }
            else{
                AIMove(board, row, col);
                printBuffer(100);
                cout << "(the AI moved to spot x, y)\n" << endl;
            }
            userTurn = !userTurn;
        }

        cout << "would you like to play again? 'y' for yes, 'n' for no >>> ";
        cin >> replay;
    }

    return 0;
}
        //Implement HINT:

        //prompt the user to input a location on the board. Keep prompting if the position is not available.
        //userInput(row, col);
        //check: Available()
        /*while (!posAvailable(board, row, col)) {
            //userInput(row, col);
        }*/

        //place down the mark

//declaring function implementations

bool isEven(int checkPos) {
    if (checkPos % 2 == 0) {
        return true;
    }
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
    string sideBuffer[5][6];
    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 6; j++){
            if(j < 1){
                sideBuffer[i][j] = "\t\t";
            }
            else{
                sideBuffer[i][j] = displayBoard[i][j-1];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << sideBuffer[i][j];
        }
        cout << endl;
    }
}

void userInput(char board[][3], int& row, int& col) {
    cout << "\nEnter the location where you want to place your mark.\n" << endl;
    cout << "\t\tRow: ";
    cin >> row;
    cout << "\t\tCol: ";
    cin >> col;
    if(!posAvailable(board, row, col)){
        cout << "that is not a valid location, try again." << endl;
        userInput(board, row, col);
    }
}

bool posAvailable(char board[][3], int& row, int& col) {
    if (board[row][col] != ' ') {
        return false;
    } else if (row < 0 || row > 2 || col < 0 || col > 2) {
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

bool gameOver(char board[][3]){
    if(playerWin(board, 'X')){
        cout << "X wins!";
        return true;
    }
    else if(playerWin(board, 'O')){
        cout << "O wins!";
        return true;
    }
    else if(boardFull(board)){
        cout << "tie!";
        return true;
    }
    else{
        return false;
    }
}

bool boardFull(char board[][3]){
    return false;
}

bool playerWin(char board[][3], char symbol){
    return false;
}

void printBuffer(int lines){
    for(int i = 0; i < lines; i++){
        cout << endl;
    }
}



