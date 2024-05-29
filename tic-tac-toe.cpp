//TIC - TAC - TOE GAME

#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

// Function to display the game board
void displayBoard() {
    cout<<"  |   |  \n";
    cout<<" "<<board[0][0]<<"| "<<board[0][1]<<" | "<<board[0][2]<<" \n";
    cout<<"__|___|__\n";
    cout<<"  |   |  \n";
    cout<<" "<<board[1][0]<<"| "<<board[1][1]<<" | "<<board[1][2]<<" \n";
    cout<<"__|___|__\n";
    cout<<"  |   |  \n";
    cout<<" "<<board[2][0]<<"| "<<board[2][1]<<" | "<<board[2][2]<<" \n";
    cout<<"  |   |  \n";
}

// Function to get player input
int getPlayerMove(char player) {
  int move;
  while (true) {
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;
    if (move >= 1 && move <= 9 && board[(move - 1) / 3][(move - 1) % 3] == ' ') {
      return move;
    } else {
      cout << "Invalid move. Try again." << endl;
    }
  }
}

// Function to check if a player has won
bool checkWin(char player) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

// Function to check for a draw
bool isDraw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  char currentPlayer = 'X';
  int move;

  while (true) {
    // Display board
    displayBoard();

    // Get player move
    move = getPlayerMove(currentPlayer);

    // Update board
    board[(move - 1) / 3][(move - 1) % 3] = currentPlayer;

    // Check for win
    if (checkWin(currentPlayer)) {
      displayBoard();
      cout << "Player " << currentPlayer << " wins!" << endl;
      break;
    }

    // Check for draw
    if (isDraw()) {
      displayBoard();
      cout << "It's a draw!" << endl;
      break;
    }

    // Switch player
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  // Play again prompt
  char choice;
  cout << "Play again? (y/n): ";
  cin >> choice;
  if (choice == 'y' || choice == 'Y') {
    // Reset board and play again
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        board[i][j] = ' ';
      }
    }
    currentPlayer = 'X';
    main();
  } else {
    cout << "Thanks for playing!" << endl;
  }

  return 0;
}