//
// HeightMap.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 10:12:00 2014 
// Last Update Mon Oct 27 13:38:06 2014 
//

#include "abstractions/allocs.hh"
#include "map/generators/HeightMap.hh"

HeightMap::HeightMap(unsigned int longer, unsigned int larger) :
  m_size(longer * larger),
  m_longer(longer),
  m_larger(larger)
{
  MALLOC(m_heights, m_size, float);
}

HeightMap::~HeightMap()
{
  free(m_heights);
}


float
HeightMap::calcHeight(unsigned int x, unsigned int y)
{
  (void)(x);
  (void)(y);
  return (0.0f);
}


void
HeightMap::initHeights()
{
  unsigned int	x, y;

  for (x = 0; x < m_longer; ++x)
    for (y = 0; y < m_larger; ++y)
      m_heights[y * m_longer + x] = this->calcHeight(x, y);
}


void
HeightMap::copyHeights(Hoopla* hooplas) const
{
  unsigned int	i;

  for (i = 0; i < m_size; ++i)
    hooplas[i].height = m_heights[i];
}


HeightMap&
HeightMap::operator+=(const HeightMap& map)
{
  unsigned int	i;

  for (i = 0; i < m_size; ++i)
    m_heights[i] += map.m_heights[i];

  return *this;
}
