//
// Player.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:48:47 2014 
// Last Update Tue Nov  4 08:52:49 2014 
//

#include "data/Player.hh"

Player::Player(const char* name, const Class* refToClass) :
  Namable(name),
  m_class(refToClass)
{
}

Player::~Player()
{
}
