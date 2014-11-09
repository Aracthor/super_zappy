//
// Movements.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 05:33:54 2014 
// Last Update Sun Nov  9 08:37:25 2014 
//

const sf::Vector2u&
Movements::getMovement(unsigned int id) const
{
  return (m_movements[id]);
}

const sf::Vector2i&
Movements::getIMovement(unsigned int id) const
{
  return (m_imovements[id]);
}
