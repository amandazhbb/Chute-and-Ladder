// Author Name: Amanda Zheng
// File name: p1.cpp
// Date: 2019-01-17
// Purpose: drives the whole application.
// Input: number of players, and name for each player.
// Process: relies on Player and Board class to proceed.
// Output: it will output information for player's action and winner's metrics.

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include "board.h"
#include "player.h"

// Board board;
// Player player;
using namespace std;

void startGameLoop(Player *players, int numberOfPlayers, Board &board);
// start the main game loop, which picks a player to takeTurn first, and
// continue in round robin fashion.

bool playerTakeTurn(Player &player, Board &board);
// player take one turn.
// returns whether player is winner in this turn.

int main() {
  Board board = Board();
  Player *players;
  int numberOfPlayers;
  string playerName;
  char ans = 'y';

  srand(time(nullptr));
  cout << "Welcome to play Chutes & Ladders by @Fly By Night Games!"
       << "\n"
       << "Please enter number of players [2-6]:";
  cin >> numberOfPlayers;
  while (numberOfPlayers < 2 || numberOfPlayers > 6) {
    cout << "Hey thats invalid! Enter a valid number: ";
    cin >> numberOfPlayers;
  }

  players = new Player[numberOfPlayers];
  for (int i = 0; i < numberOfPlayers; ++i) {
    cout << "Please enter name of player " << i + 1 << ":";
    cin >> playerName;
    players[i].setName(playerName);
  }
  while (ans == 'y' || ans == 'Y') {
    startGameLoop(players, numberOfPlayers, board);
    for (int i = 0; i < numberOfPlayers; i++) {
      players[i].reset();
    }

    cout << "Would you like to play again? (Y/N)";
    cin >> ans;
  }
  cout << "Hope you enjoyed our game, Good bye!"
       << "\n";
}

void startGameLoop(Player *players, int numberOfPlayers, Board &board) {
  // randomly picks the first player.
  int nextPlayerIndex = rand() % numberOfPlayers;

  bool gameEnded = false;
  while (!gameEnded) {
    cout << "Press Enter to Continue! \n";
    cin.get();
    gameEnded = playerTakeTurn(players[nextPlayerIndex], board);

    // set the nextPlayer in round-robin fashion.
    nextPlayerIndex = (nextPlayerIndex + 1) % numberOfPlayers;
  }
}

bool playerTakeTurn(Player &player, Board &board) {
  string playerName = player.getName();
  int location = player.getLocation();
  int laddersCount = 0;
  int chutesCount = 0;

  board.takeTurn(playerName, location, laddersCount, chutesCount);
  player.setLocation(location);
  player.incEncounteredLadders(laddersCount);
  player.incEncounteredChutes(chutesCount);

  if (board.winner(location)) {
    cout << playerName
         << " is the winner, congratulations! You have encountered"
         << " ladders:" << player.getEncounteredLadders()
         << ", chutes:" << player.getEncounteredChutes() << "\n";
    return true;
  }
  return false;
}
