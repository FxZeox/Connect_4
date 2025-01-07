# Connect Four Game

A two-player Connect Four game implemented in C++.

## Description
This is a command-line version of the Connect Four game where two players take turns to drop their discs into a grid and the first player to connect four of their discs horizontally, vertically, or diagonally wins.

## Features
- Two-player mode (Player 1 and Player 2).
- Toss mechanism to decide who plays first.
- Option to view the scores after each game.
- Draw condition when the board is full with no winner.
- Instructions and credits available.

## Instructions
1. Players take turns to drop a disc into one of the seven columns.
2. The first player to get four of their discs in a row (horizontally, vertically, or diagonally) wins.
3. If the board is full and no player has four in a row, the game is a draw.
4. Player 1 uses 'A' and Player 2 uses 'B'.

## How to Play
1. Choose option 1 to start the game.
2. Choose a column to drop your disc.
3. The game will display the board after each turn.
4. The game ends when either one player wins or the board is full (draw).

## Installation
1. Clone the repository:  
     `git clone https://github.com/username/connect-four-game.git`
2. Compile the program using:  
      `g++ -o connect4 connect4.cpp`
3. Run the game:  
     `./connect4`

