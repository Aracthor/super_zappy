//
// Random.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:44:03 2014 
// Last Update Sun Oct 12 08:28:08 2014 
//

#include <cstdlib>

#include "abstractions/Random.hh"

Random::Random(unsigned long seed) :
  m_seed(seed)
{
  srandom(seed);
}

Random::~Random()
{
}


unsigned int
Random::getNumber()
{
  return (random());
}
