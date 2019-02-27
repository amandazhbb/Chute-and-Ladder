// Author Name: Amanda Zheng
// File name: player.h
// Date: 2019-01-17
// Purpose: Implementation for Player described in player.h

#include "player.h"

#include <string>
#include <cctype>
using namespace std;

Player::Player() 
{
  location_ = 0;
  encounteredLadders_ = 0;
  encounteredChutes_ = 0;
}

void Player::setName(string name) 
{ 
    name_ = name; 
}

string Player::getName() 
{ 
    return name_; 
}

int Player::getLocation() 
{ 
    return location_; 
}

void Player::setLocation(int newLocation) 
{ 
    location_ = newLocation; 
}

int Player::getEncounteredLadders() 
{ 
    return encounteredLadders_; 
}

void Player::incEncounteredLadders(int count) 
{ 
    encounteredLadders_ += count; 
}

int Player::getEncounteredChutes() 
{ 
    return encounteredChutes_; 
}

void Player::incEncounteredChutes(int count) 
{ 
    encounteredChutes_ += count; 
}

void Player::reset()
{
    location_ = 0;

    encounteredLadders_ = 0;

    encounteredChutes_ = 0;
}
