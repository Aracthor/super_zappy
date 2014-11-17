//
// Craft.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 11:01:17 2014 
// Last Update Fri Nov 14 12:04:05 2014 
//

#include "catalogs/Craft.hh"

#include <cstring>

Craft::Craft()
{
}

Craft::Craft(unsigned int time, unsigned int level) :
  m_time(time),
  m_level(level)
{
  memset(m_requires, 0, sizeof(m_requires));
}

Craft::~Craft()
{
}
