//
// WaterGenerator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 26 10:33:20 2014 
// Last Update Tue Oct 28 19:47:43 2014 
//

#include "map/Chunk.hh"
#include "map/generators/GroundGenerator.hh"
#include "map/generators/WaterGenerator.hh"

#include <cstdlib>

WaterGenerator::WaterGenerator(unsigned int width, unsigned int height) :
  AGenerator(width, height),
  RiverGenerator(width, height),
  LowLakeGenerator(width, height)
{
  m_width = width * CHUNK_SIZE;
  m_height = height * CHUNK_SIZE;
  m_hooplasNumber = m_width * m_height;
}

WaterGenerator::~WaterGenerator()
{
}


void
WaterGenerator::insertWater(Hoopla* hooplas)
{
  Position	pos;

  m_hooplas = hooplas;

  for (pos.x = 1; (unsigned int)pos.x < m_width - 1; ++pos.x)
    for (pos.y = 1; (unsigned int)pos.y < m_height - 1; ++pos.y)
      if (this->isPeak(this->getHoopla(pos)) &&
	  (random() % RIVER_CHANCES) == 0)
	this->createRiver(pos);
}

