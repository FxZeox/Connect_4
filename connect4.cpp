#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROWS = 6;
const int COLS = 7;
char board[ROWS][COLS];
int player1Wins = 0, player2Wins = 0, draws = 0;

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
cout << "--Connect Four Game-- " <<endl; 
cout <<"  " <<endl;


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < COLS; i++) {
        cout << "--";
    }
    cout << "-" << endl;
    for (int i = 0; i < COLS; i++) {
        cout << " " << i + 1;
    }
    cout << endl;
}

void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux/macOS
#endif
}

bool toss() {
    srand(time(0)); 
    int tossResult = rand() % 2;
    if (tossResult == 0) {
        cout << "Player 1 wins the toss and goes first!" << endl;
        return true; // Player 1 goes first
    } else {
        cout << "Player 2 wins the toss and goes first!" << endl;
        return false; // Player 2 goes first
    }
}

bool playerTurn(int player, int col) {
    if (col < 0 || col >= COLS) {
        cout << "Invalid column. Please choose a valid column between 1 and " << COLS << endl;
        return false;
    }
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = (player == 1) ? 'A' : 'B';
            return true;
        }
    }
    cout << "Column is full. Please choose another column." << endl;
    return false;
}

bool winningCondition() {
    // Check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check vertical
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check diagonal (bottom-left to top-right)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

bool drawCondition() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    initializeBoard();
    bool currentPlayer = toss(); // true = player 1, false = player 2
    int column;
    bool gameOver = false;

    while (!gameOver) {
        clearScreen(); // Clear screen before displaying the board
        printBoard();
        cout << "Player " << (currentPlayer ? "1 (A)" : "2 (B)") << "'s turn. Choose a column (1-7): ";
        cin >> column;
        column--; // To convert to zero-indexed
        if (!playerTurn(currentPlayer ? 1 : 2, column)) {
            continue; // Invalid move, retry
        }

        if (winningCondition()) {
            clearScreen(); // Clear screen before displaying the board
            printBoard();
            cout << "Player " << (currentPlayer ? "1 (A)" : "2 (B)") << " wins!" << endl;
            if (currentPlayer) {
                player1Wins++;
            } else {
                player2Wins++;
            }
            gameOver = true;
        } else if (drawCondition()) {
            clearScreen(); // Clear screen before displaying the board
            printBoard();
            cout << "The game is a draw!" << endl;
            draws++;
            gameOver = true;
        }

        currentPlayer = !currentPlayer; // Switch turn
    }
}

void showScores() {
    cout << "Scores:" << endl;
    cout << "Player 1 (A) wins: " << player1Wins << endl;
    cout << "Player 2 (B) wins: " << player2Wins << endl;
    cout << "Draws: " << draws << endl;
}

void credits() {
    cout << "Connect Four Game created by: Usman Ahmad" << endl;
}

void instructions() {
    cout << "Instructions/Rules of Connect Four:" << endl;
    cout << "1. Players take turns to drop a disc into one of the seven columns." << endl;
    cout << "2. The first player to get four of their discs in a row (horizontally, vertically, or diagonally) wins." << endl;
    cout << "3. If the board is full and no player has four in a row, the game is a draw." << endl;
    cout << "4. Player 1 uses 'A' and Player 2 uses 'B'." << endl;
}

int main() {
    int choice;
    bool playing = true;

    while (playing) {
        cout << "\nConnect Four Game Menu" << endl;
        cout << "1. Play Game" << endl;
        cout << "2. View Scores" << endl;
        cout << "3. Instructions" << endl;
        cout << "4. Credits" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                showScores();
                break;
            case 3:
                instructions();
                break;
            case 4:
                credits();
                break;
            case 5:
                playing = false;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}

