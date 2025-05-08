Tic-Tac-Toe (Terminal Edition)

A simple 2-player Tic-Tac-Toe game built in C++ for the terminal. It’s a clean, interactive project designed for learning and practicing modern C++ concepts like encapsulation, input validation, and control flow.

🎮 How to Play
	•	You’ll see a 3×3 grid labeled 1–9:

 1 | 2 | 3
 4 | 5 | 6
 7 | 8 | 9

Each player is either X or O, and takes turns choosing a cell by typing a number.
	•	The game detects wins across rows, columns, and diagonals.
	•	If all cells are filled with no winner, it ends in a tie.
	•	After each game, you’ll be asked whether you want to play again.

🧠 Features
	•	Easy-to-use single-cell input (1–9)
	•	Validates input format and prevents overwriting cells
	•	Displays turn-by-turn board updates
	•	Alternates starting player each game
	•	Pure terminal experience – no libraries beyond iostream/string

🛠 Build & Run

g++ ttt.cpp game.cpp -o tic-tac-toe
./tic-tac-toe

Make sure you have a C++ compiler like g++.

📁 File Structure
	•	ttt.cpp – Main entry point
	•	game.hpp – Class interface for TicTacToe
	•	game.cpp – Logic for board drawing, move handling, win/tie detection, etc.

🧪 Educational Focus

This project reinforces:
	•	Reference parameters (int&)
	•	Value-to-grid math (index / 3, index % 3)
	•	Input loop patterns (while (true), cin.ignore, validation)
	•	constexpr (variables whose values are known at compile time rather than at runtime)
  • Encapsulation

📝 License

MIT or public domain – feel free to use, modify, or build on this.
