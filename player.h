// Author Name: Amanda Zheng
// File name: player.h
// Date: 2019-01-17
// Purpose: Player tracks the metrics during one board game.

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player 
{
 public:
  Player();
  // constructor.

  string getName();
  // returns player's name.

  void setName(string name);
  // sets player's name.

  int getLocation();
  // returns player's location.

  void setLocation(int location);
  // sets player's location.
  // post: location_ will be set to location.

  int getEncounteredLadders();
  // returns the number of ladders player encountered.

  void incEncounteredLadders(int count);
  // increase the number of ladders player encountered by count.
  // post: encounteredLadders_ will be increased by count.

  int getEncounteredChutes();
  // returns the number of chutes player encountered.

  void incEncounteredChutes(int count);
  // increase the number of chutes player encountered by count.
  // post: encounteredChutes_ will be increased by count.

  void reset();

 private:
  string name_;
  // player's name.

  int location_;
  // player's current location.

  int encounteredLadders_;
  // number of ladders player encountered.

  int encounteredChutes_;
  // number of chutes player encountered.
};

#endif