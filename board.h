// Author Name: Amanda Zheng
// File name: board.h
// Date: 2019-01-17
// Purpose: Board takeTurn for players, and decide whether player is winner
// based on board state.

#ifndef BOARD_H
#define BOARD_H

#include "player.h"

class Board 
{
 public:
  Board();
  // constructor.

  void takeTurn(string playerName, int &location, int &ladders, int &chutes);
  // takes a turn for playerName, printing status message.
  // pre: location must be a valid and non-winner location, e.g. within [0,
  // WIN_SPACE) post: location contains new location for playerName
  //       ladders indicates number of encountered ladders
  //       chutes indicates number of encountered chutes

  bool winner(int location);
  // returns whether this is an winning location or not.

 private:
  int spin();
  // return number within [1, SPIN_MAX] after spin a dice.

  void handleSpin(string playerName, int &location);
  // handles movement for playerName by spin a dice.
  // pre: location must be a valid and non-winner location, e.g. within [0,
  // WIN_SPACE) post: location contains new location for playerName

  void handleLadderChutes(string playerName, int &location, int &ladders,
                          int &chutes);
  // handles movement for playerName by processing ladders and chutes(if any) at
  // location. pre: location must be a valid and non-winner location, e.g.
  // within [0, WIN_SPACE) post: location contains new location for playerName

 private:
  static const int WIN_SPACE = 100;
  // the winner location.

  static const int SPIN_MAX = 6;
  // the maximum spin number.

  int ladderChutes_[WIN_SPACE];
  // ladders and chutes configuration.
};
#endif
