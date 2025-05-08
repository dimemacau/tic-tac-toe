// TicTacToe: manages state and gameplay for a terminal-based Tic-Tac-Toe game.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TicTacToe {
    public:
    // Constructor: initializes a new TicTacToe game object.
    TicTacToe();
    // Initializes the game state, setting up the board and starting player.
    void initializeGameState();
    // Displays the current state of the game board.
    void displayBoard() const;
    // Prompts and retrieves the current player's move input.
    void getMove(int &row, int &column);
    // Sets the move on the board for the current player at the specified location.
    void setMove(int r, int c);
    // Switches the current player from 'X' to 'O' or vice versa.
    void togglePlayer();
    // Checks if the current player has won the game.
    bool checkWin() const;
    // Displays the game results after a win or tie.
    void displayResults() const;
    // Asks the player if they want to play again, returning true if yes.
    bool playAgain();
    // Checks if the game board is full and no moves remain (tie condition).
    bool checkTie() const;

    // Starts and controls the main game loop.
    void play();
    
    private:
        // 3x3 board array: holds '0' for empty, 'X' or 'O' for moves.
        char board_[3][3];
        // Current player symbol: 'X' or 'O'.
        char currentPlayer_;
        // Board dimension (3 for a 3x3 grid). constexpr initializes and defines at compilation not at runtime (saves resources)
        static constexpr int kBoardSize_ = 3; 
        // Sentinel (empty) value for an empty cell.
        static constexpr char kEmptyCell_ = '0'; 
};