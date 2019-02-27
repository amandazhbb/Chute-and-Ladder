// Author Name: Amanda Zheng
// File name: player.h
// Date: 2019-01-17
// Purpose: Implementation for Board described in board.h

#include "board.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

Board::Board() 
{
  for (int i = 0; i < WIN_SPACE; i++) {
    ladderChutes_[i] = 0;
  }

  // init ladders
  ladderChutes_[1] = 37;
  ladderChutes_[4] = 10;
  ladderChutes_[9] = 12;
  ladderChutes_[23] = 21;
  ladderChutes_[28] = 56;
  ladderChutes_[36] = 8;
  ladderChutes_[51] = 15;
  ladderChutes_[71] = 19;
  ladderChutes_[80] = 20;

  // init chutes
  ladderChutes_[98] = -20;
  ladderChutes_[95] = -20;
  ladderChutes_[93] = -20;
  ladderChutes_[87] = -63;
  ladderChutes_[64] = -4;
  ladderChutes_[62] = -43;
  ladderChutes_[56] = -3;
  ladderChutes_[49] = -38;
  ladderChutes_[48] = -22;
  ladderChutes_[16] = -10;
}

void Board::takeTurn(string playerName, int &location, int &ladders,
                     int &chutes) 
{
  handleSpin(playerName, location);
  handleLadderChutes(playerName, location, ladders, chutes);
}

bool Board::winner(int location) 
{
     return location == WIN_SPACE; 
}

void Board::handleSpin(string playerName, int &location) 
{
  int spinNum = spin();
  int newLocation = location + spinNum;
  if (newLocation > WIN_SPACE) {
    cout << playerName << "losed his/her round by spin of " << spinNum << "\n";
    return;
  }

  cout << playerName << " moved by spin of " << spinNum << ": " << location
       << "==>" << newLocation << "\n";
  location = newLocation;
}

void Board::handleLadderChutes(string playerName, int &location, int &ladders,
                               int &chutes) 
{
  if (location >= WIN_SPACE) {
    return;
  }

  int jumpDistance = ladderChutes_[location];
  int newLocation = location + jumpDistance;
  if (jumpDistance == 0) {
    return;
  } else if (jumpDistance > 0) {
    ladders += 1;
  } else {
    chutes += 1;
  }

  cout << playerName << " moved by ladder/chute: " << location << "==>"
       << newLocation << "\n";
  location = newLocation;

  // deal with cases when the ending of an ladder/chute is the beginning of
  // another ladder/chute.
  handleLadderChutes(playerName, location, ladders, chutes);
}

int Board::spin() 
{ 
    return (rand() % 6) + 1; 
}
