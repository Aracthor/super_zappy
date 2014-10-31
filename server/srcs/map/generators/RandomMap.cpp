//
// RandomMap.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 17:14:09 2014 
// Last Update Mon Oct 27 13:37:20 2014 
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


float
RandomMap::calcHeight(unsigned int x, unsigned int y)
{
  (void)(x);
  (void)(y);
  return ((float)(random() % 10000 - 5000) / 100.0f);
}
