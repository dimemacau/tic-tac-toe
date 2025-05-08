#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype> // for tolower()
#include <limits> // for max() which is the maximum value a streamsize can hold


#include "game.hpp"

using namespace std;

// Helper (free-function) that checks whether the input is valid and converts it to an int if so
int promptInput(string& input) {
    while(true) {
        // Read the next token (user input)
        cin >> input;
        // Validate that input is exactly one character between '1' and '3'
        if(input.size() != 1 || input[0] < '1' || input[0] > '9') {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid Input. Please enter a number from 1-9." << endl;
            // Invalid entry: clear rest of line and retry
            continue;
        }

        return input[0] - '0'; // Subtracting kEmptyCell_ (ASCII 48 -- means that kEmptyCell_ equals to int 48) converts any char to int
    }
}


TicTacToe::TicTacToe() {
    initializeGameState();
    currentPlayer_ = 'O';
} 

void TicTacToe::displayBoard() const { // Display the current state of the board
    
    cout << endl << currentPlayer_ << "'s turn:\n" << endl;
    // Display the board

    cout << " --- --- --- " << endl; 
    int cellNum = '1';
    // Loop through each row to display its contents
    for(int i = 0; i < kBoardSize_; ++i) {
        // Loop through each cell in the current row
        for (char j : board_[i]) {
            char cell = (j == kEmptyCell_) ? cellNum : j;
            cout << "| " << cell << " ";
            ++cellNum;
        }
        // Close rows
        cout << "|" << endl;
        // Vertical divider between rows
        cout << " --- --- --- " << endl;
    }
    cout << endl;
}

void TicTacToe::initializeGameState() {

    // Reset every cell in the board to empty
    for (int i = 0; i < kBoardSize_; ++i) {
        for (int j = 0; j < kBoardSize_; ++j) {
            board_[i][j] = kEmptyCell_;
        }
    }
}

void TicTacToe::getMove(int &row, int &column) {

    cout << "Player " << currentPlayer_ << "\'s turn:" << endl;

    bool validInput = false;

    string cellInputStr;
    int cellInputInt;

    while(!validInput) {
        cout << "Choose cell 1-9: ";
        cellInputInt = promptInput(cellInputStr);
        // Convert cell number (1-9) to 0-based row and column indices
        // Subtracting 1 gives us a 0-8 range. 
        // Integer division by 3 gives us the row index (0, 1, or 2). Since C++ truncates the decimal part when converting a double to int, 
        // this works perfectly for cell 1–9 mapping to 3 rows.
        // Modulo 3 gives the remainder, which maps to column index (0, 1, 2).
        // For example: cell 5 → (5 - 1) = 4 → row = 4 / 3 = 1, column = 4 % 3 = 1
        row = (cellInputInt - 1) / 3;
        column = (cellInputInt - 1) % 3;
        if(board_[row][column] == 'X' || board_[row][column] == 'O') {
            cout << "Cell is occupied!" << endl;
        } else {
            validInput = true;
        }
    }
}

void TicTacToe::setMove(int r, int c) {
    board_[r][c] = currentPlayer_;
}

void TicTacToe::togglePlayer() {
    if(currentPlayer_ == 'X') {
        currentPlayer_ = 'O';
    } else {
        currentPlayer_ = 'X';
    }
} 

bool TicTacToe::checkWin() const {

    int count = 0;

    // Check each row for three matching symbols
    for(int i = 0; i < kBoardSize_; ++i) {    
        for(char cell: board_[i]) {
            if(cell == currentPlayer_) count += 1;
        }
        if(count == 3) {
            return true;
        } else {
            count = 0; 
        }
    }

    // Check each column for three matching symbols
    for(int c = 0; c < kBoardSize_; ++c) {    
        for(int r = 0; r < 3; ++r) {
            if(board_[r][c] == currentPlayer_) count += 1;
        }
        if(count == 3) {
            return true;
        } else {
            count = 0; 
        }
    }


    // Check top-left to bottom-right diagonal
    for(int i = 0; i < kBoardSize_; ++i) {
        if(board_[i][i] == currentPlayer_) count += 1;
    }
    if(count == 3) {
        return true;
    } else {
        count = 0; 
    }

    // Check top-right to bottom-left diagonal
    for(int r = 0; r < kBoardSize_; ++r) {
        if(board_[r][2 - r] == currentPlayer_) count += 1;
    }
    if(count == 3) {
        return true;
    } else {
        count = 0; 
    }

    return false;
}

bool TicTacToe::checkTie() const {
    // Verify every board cell is filled (no empty cells)
    int tieCount = 0;
    for(int r = 0; r < kBoardSize_; ++r) {
        for(int c = 0; c < kBoardSize_; ++c) {
            if (board_[r][c] != kEmptyCell_) ++tieCount;
        }
    }
    if(tieCount == 9) {
        return true;
    }
    return false;
}

void TicTacToe::displayResults() const {
    if (checkTie()) {
        cout << "It's a tie!" << endl;
    } else {
        cout << currentPlayer_ << " has won!" << endl;
    }
}

bool TicTacToe::playAgain() {

    cout << "Play again? y/n" << endl;

    char input;

    while(true) {
        cin >> input;
        input = tolower(input);
        if(input == 'y' || input == 'n') {
            if(input == 'y') {return true;} else {return false;}
        } else {
            cout << "Please enter \'y\' or \'n\'" << endl;
        }
    }
    return false;
}

void TicTacToe::play() {
    bool playing = true;

    while(playing) {

      // Start a fresh round with a reset board and new starting player
      initializeGameState();
      bool finished = false;
      
      while(!finished) {
        // Show board and prompt move until the game ends
        displayBoard();

        int r, c;
        getMove(r, c);
        setMove(r, c);

        if(checkWin() || checkTie()) {
          finished = true;
          displayBoard();
          displayResults();
          if(!playAgain()) {
            finished = true;
            playing = false;
          } else {
            finished = true;
          }
        }
        togglePlayer();
      }
    }
    cout << "Thanks for playing!" << endl;
}