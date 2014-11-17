//
// Ground.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:11:57 2014 
// Last Update Fri Nov 14 17:28:50 2014 
//

#include "catalogs/Ground.hh"

Ground::Ground()
{
}

Ground::Ground(unsigned int digTime, Hoopla::EItem digItem) :
  m_digTime(digTime),
  m_digItem(digItem)
{
}

Ground::~Ground()
{
}
