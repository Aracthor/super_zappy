//
// Production.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:56:58 2014 
// Last Update Thu Dec  4 09:57:42 2014 
//

#include <cstdlib>

Hoopla::EItem
Production::getItem() const
{
  return (m_item);
}

unsigned int
Production::getRandomNumber() const
{
  return (random() % (m_max - m_min + 1) + m_min);
}
