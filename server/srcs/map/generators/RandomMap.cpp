//
// RandomMap.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 17:14:09 2014 
// Last Update Fri Oct 24 17:21:03 2014 
//

#include "map/generators/RandomMap.hh"

#include <cstdlib>

RandomMap::RandomMap(unsigned int longer, unsigned int larger) :
  HeightMap(longer, larger)
{
}

RandomMap::~RandomMap()
{
}


int
RandomMap::calcHeight(unsigned int x, unsigned int y)
{
  (void)(x);
  (void)(y);
  return (random() % 100 - 50);
}
