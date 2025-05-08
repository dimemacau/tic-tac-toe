Tic-Tac-Toe (Terminal Edition)<br/>

A simple 2-player Tic-Tac-Toe game built in C++ for the terminal. It’s a clean, interactive project designed for learning and practicing modern C++ concepts like encapsulation, input validation, and control flow.<br/>

🎮 How to Play<br/>
	•	You’ll see a 3×3 grid labeled 1–9:<br/>

 1 | 2 | 3<br/>
 4 | 5 | 6<br/>
 7 | 8 | 9<br/>

Each player is either X or O, and takes turns choosing a cell by typing a number.<br/>
	•	The game detects wins across rows, columns, and diagonals.<br/>
	•	If all cells are filled with no winner, it ends in a tie.<br/>
	•	After each game, you’ll be asked whether you want to play again.<br/>

🧠 Features<br/>
	•	Easy-to-use single-cell input (1–9)<br/>
	•	Validates input format and prevents overwriting cells<br/>
	•	Displays turn-by-turn board updates<br/>
	•	Alternates starting player each game<br/>
	•	Pure terminal experience – no libraries beyond iostream/string<br/>

🛠 Build & Run<br/>

```
g++ ttt.cpp game.cpp -o tic-tac-toe
./tic-tac-toe

```
<br/>

Make sure you have a C++ compiler like g++.<br/>

📁 File Structure<br/>
	•	ttt.cpp – Main entry point<br/>
	•	game.hpp – Class interface for TicTacToe<br/>
	•	game.cpp – Logic for board drawing, move handling, win/tie detection, etc.<br/>

🧪 Educational Focus<br/>

This project reinforces:<br/>
	•	Reference parameters (int&)<br/>
	•	Value-to-grid math (index / 3, index % 3)<br/>
	•	Input loop patterns (while (true), cin.ignore, validation)<br/>
	•	constexpr (variables whose values are known at compile time rather than at runtime)<br/>
  • Encapsulation<br/>

📝 License<br/>

MIT or public domain – feel free to use, modify, or build on this.<br/>
