//
// AGenerator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 17:49:05 2014 
// Last Update Mon Oct 27 18:11:56 2014 
//

#include "map/Chunk.hh"
#include "map/generators/AGenerator.hh"

AGenerator::AGenerator()
{
}

AGenerator::AGenerator(unsigned int width, unsigned int height) :
  m_width(width * CHUNK_SIZE),
  m_height(height * CHUNK_SIZE),
  m_hooplasNumber(m_width * m_height)
{
}

AGenerator::~AGenerator()
{
}
