<<<<<<< HEAD
=======

>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584
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
<<<<<<< HEAD
void createAlignments();
void hasAlign(int, int&, char[][3], int&);
=======
>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584

int main() {

    string displayBoard[5][5];
    char board[3][3];
<<<<<<< HEAD
=======

>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584
    bool userTurn = true;
    int row;
    int col;
    int checkPos;
    char replay = 'y';
<<<<<<< HEAD
    int count = 0;

    while (replay == 'y' || replay == 'Y') {
        initBoard(board);

        while (!gameOver(board)) {
            if (userTurn) {
                display(board, displayBoard);
                userInput(board, row, col);
                board[row][col] = 'X';
            } else {
                AIMove(board, row, col);
                printBuffer(9000);
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
=======

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
>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584

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
<<<<<<< HEAD
=======
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
>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584
            }
        }
    }
    string sideBuffer[5][6];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
<<<<<<< HEAD
            if (j < 1) {
                sideBuffer[i][j] = "\t\t";
            } else {
                sideBuffer[i][j] = displayBoard[i][j - 1];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
=======
>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584
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
<<<<<<< HEAD
    if (!posAvailable(board, row, col)) {
=======
    if(!posAvailable(board, row, col)){
>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584
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

<<<<<<< HEAD
bool gameOver(char board[][3]) {
    if (playerWin(board, 'X')) {
        cout << "X wins!";
        return true;
    } else if (playerWin(board, 'O')) {
        cout << "O wins!";
        return true;
    } else if (boardFull(board)) {
        cout << "tie!";
        return true;
    } else {
=======
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
>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584
        return false;
    }
}

<<<<<<< HEAD
bool boardFull(char board[][3]) {
    return false;
}

bool playerWin(char board[][3], char symbol) {
    return false;
}

void printBuffer(int lines) {
    for (int i = 0; i < lines; i++) {
=======
bool boardFull(char board[][3]){
    return false;
}

bool playerWin(char board[][3], char symbol){
    return false;
}

void printBuffer(int lines){
    for(int i = 0; i < lines; i++){
>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584
        cout << endl;
    }
}

<<<<<<< HEAD
void hasAlign(int pos, int& skip, char alignments[][3], int& count) {
    for (int i = 0; i < 3; i++) {
        alignments[count][i] = pos;
        pos += skip;
    }
    count++;
}

//This function basically creates 8 alignments of the possible winning combinations from the game board
void createAlignments() {
    char alignments[8][3]; //an array that holds 8 alignments of the winning combo
    int count = 0; //...
    //i, aka "skip", is an essential variable in the 8 combos
    for (int i = 1; i < 5; i++) {
        if (i % 2 == 0) {
            if (i == 2) {
                hasAlign(2, i, alignments, count);
            } else {
                hasAlign(0, i, alignments, count);
            }
        } else {
            for (int j = 0; j < 3; j++) {
                if (i == 1) {
                    hasAlign((j*3), i, alignments, count);
                } else {
                    hasAlign(j, i, alignments, count);
                }
            }
        }
    }

}
=======


>>>>>>> 3888b9789d238cde7189cf4758e9129f9d979584
