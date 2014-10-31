//
// RingMap.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 13:29:12 2014 
// Last Update Thu Oct 30 17:28:53 2014 
//

#include "abstractions/maths.hh"
#include "map/generators/RingMap.hh"

RingMap::RingMap(unsigned int longer, unsigned int larger) :
  HeightMap(longer, larger)
{
}

RingMap::~RingMap()
{
}


float
RingMap::calcHeight(unsigned int x, unsigned int y)
{
  float	height;
  float	longer;
  float	larger;
  float	distance;

  longer = (float)ABS(m_longer / 2 - x) / (float)m_longer * 2.0f;
  larger = (float)ABS(m_larger / 2 - y) / (float)m_larger * 2.0f;
  distance = sqrtf(longer * longer + larger * larger) * 200.0f;

  height = 100.0f - distance;
  if (height > 50.0f)
    height = 100.0f - (height + (height - 50.0f) * 2);

  return (height);
}
