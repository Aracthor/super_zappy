//
// Movements.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 05:36:47 2014 
// Last Update Sun Nov  9 08:31:44 2014 
//

#include "data/Player.hh"
#include "executors/Movements.hh"

Movements::Movements()
{
  m_movements[Player::right]	= sf::Vector2u( 1,  0);
  m_movements[Player::down]	= sf::Vector2u( 0,  1);
  m_movements[Player::left]	= sf::Vector2u(-1,  0);
  m_movements[Player::up]	= sf::Vector2u( 0, -1);
  m_imovements[Player::right]	= sf::Vector2i( 1,  0);
  m_imovements[Player::down]	= sf::Vector2i( 0,  1);
  m_imovements[Player::left]	= sf::Vector2i(-1,  0);
  m_imovements[Player::up]	= sf::Vector2i( 0, -1);
}

Movements::~Movements()
{
}
