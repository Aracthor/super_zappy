//
// MountainMap.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 13:29:12 2014 
// Last Update Fri Oct 24 16:42:18 2014 
//

#include "abstractions/maths.hh"
#include "map/generators/MountainMap.hh"

MountainMap::MountainMap(unsigned int longer, unsigned int larger) :
  HeightMap(longer, larger)
{
}

MountainMap::~MountainMap()
{
}


#include <stdio.h>
int
MountainMap::calcHeight(unsigned int x, unsigned int y)
{
  int	height;
  float	longer;
  float	larger;
  float	distance;

  longer = (float)ABS(m_longer / 2 - x) / (float)m_longer * 2.0f;
  larger = (float)ABS(m_larger / 2 - y) / (float)m_larger * 2.0f;
  distance = sqrtf(longer * longer + larger * larger) * 200.0f;
  height = 100.0f - distance;

  return (height);
}
